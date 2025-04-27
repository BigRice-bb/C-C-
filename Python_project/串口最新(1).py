'''

1. 串口连接方式
最初代码：仅支持连接一个串口，串口名称需手动指定，如 COM = 'COM1'。
最新代码：能够自动检测系统中可用的串口，并且可同时连接多个串口。若有可用串口，会自动获取并使用；若没有可用串口，会给出相应提示。
2. 类的初始化
最初代码：SerialServer 类的 __init__ 方法仅接收一个串口名称和波特率作为参数，仅初始化一个串口对象。
最新代码：SerialServer 类的 __init__ 方法接收一个串口名称列表和波特率作为参数，会遍历该列表，尝试打开每个串口并为其启动一个接收线程。
3. 日志显示
最初代码：只有一个接收日志框，用于显示所有接收到的消息，无法区分消息来自哪个串口。
最新代码：会根据可用串口的数量动态创建相应数量的接收日志框，每个日志框对应一个串口，可清晰区分不同串口接收到的消息。
4. 代码健壮性
最初代码：缺乏对串口可用性的检查，若指定的串口不存在或无法打开，可能会引发异常。
最新代码：在初始化串口时添加了异常处理，若无法打开某个串口，会打印错误信息，避免程序崩溃。
5. 代码灵活性
最初代码：代码结构相对固定，若要增加串口数量，需要手动修改代码。
最新代码：通过使用列表存储串口对象和日志框，代码具有更高的灵活性，可轻松适应不同数量的串口。
6. 功能扩展性
最初代码：难以扩展以支持更多串口或处理更多复杂的串口通信场景。
最新代码：由于采用了动态创建日志框和多线程处理每个串口的方式，更易于扩展以支持更多串口和复杂的通信逻辑。

'''

#available_ports = ['COM1','COM2']

# -*- coding: utf-8 -*-
import tkinter as tk
import threading
from datetime import datetime
import logging
import os
import serial
from serial.tools import list_ports


# ID号默认没有
myid = None

# 定义文件夹路径
log_name = 'log'

# 定义txt表格记录文件
receive_file_name = "sensor_data.txt"


def check_and_create(path, is_folder=False):
    """
    检查指定路径的文件夹或文件是否存在，不存在则创建
    :param path: 文件夹或文件的路径
    :param is_folder: 是否为文件夹，默认为 False 表示文件
    """
    if is_folder:
        if not os.path.exists(path):
            os.makedirs(path)
            print(f"已创建 {path} 文件夹。")
        else:
            print(f"{path} 文件夹已存在，跳过创建。")
    else:
        if not os.path.exists(path):
            with open(path, 'w') as file:
                pass
            print(f"已创建 {path} 文件。")
        else:
            print(f"{path} 文件已存在，跳过创建。")


# 判断log文件夹是否创建
check_and_create(log_name, True)
# 判断sensor_data.txt是否创建
check_and_create(receive_file_name, False)

# 定义本次时间戳下的.log
now = datetime.now()
log_file = "./log/" + now.strftime("%Y-%m-%d-%H-%M-%S") + "_server" + ".log"
print(log_file)
logging.basicConfig(filename=log_file, level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')


def string_to_hex(s):
    """
    字符转十六进制
    :param s: 字符串
    :return hex_string:十六进制的字符串
    """
    # 初始化十六进制字符串
    hex_string = ''

    # 遍历字符串中的每个字符
    for char in s:
        # 如果字符是负号，先转换为十六进制
        if char == '-':
            hex_string += '0x2d'
        else:
            # 将字符编码为字节串，然后转换为十六进制
            byte_string = char.encode('utf-8')
            hex_byte = byte_string.hex()
            hex_string += hex_byte

    # 去除前缀 '0x'
    hex_string = hex_string.replace('0x', '')
    # print("s:", s)
    # print("hex_string:", hex_string)
    return hex_string


def hex_to_string(hex_str):
    """
    十六进制转字符
    :param hex_str: 十六进制
    :return original_string:字符串
    """
    # 将十六进制字符串解码为字节串
    byte_string = bytes.fromhex(hex_str)
    # 将字节串解码为原始字符串，这里假设原始字符串是UTF-8编码
    original_string = byte_string.decode('utf-8')
    return original_string


def display_info(log_text, message):
    """
    可视化框架显示收发的信息
    :param log_text: 显示的位置
    :param message: 显示的信息

    """
    logging.info(message)
    log_text.insert(tk.END, message)
    log_text.insert(tk.END, '\n')  # 在每条消息后面添加换行符
    log_text.see(tk.END)


def clear_send_text():
    """
    清屏发送框
    """
    send_log_text.delete("1.0", tk.END)


def clear_recv_text(log_text):
    """
    清屏接收框

    """
    log_text.delete("1.0", tk.END)


class SerialServer:
    def __init__(self, ports, baudrate=9600):
        self.ports = ports
        self.myid = None
        self.start_flag = False
        self.baudrate = baudrate
        self.serial_ports = []
        self.receive_log_texts = []
        for port in ports:
            try:
                serial_port = serial.Serial(port, self.baudrate)
                self.serial_ports.append(serial_port)
                receive_thread = threading.Thread(target=self.receive_message, args=(serial_port,))
                receive_thread.daemon = True
                receive_thread.start()
            except serial.SerialException as e:
                print(f"无法打开串口 {port}: {e}")

    def get_other_port(self, known_port):
        '''
        如果串口有两个，接收到串口known_port的数据，如果要对串口other_port做操作，则需要调用other_port的线程
        由于事前并不知道用哪个串口，所以已知其中一个，则调用另外一个
        :param known_port:
        :return: other_port
        '''
        for port in self.ports:
            if port != known_port.port:
                for other_port in self.serial_ports:
                    if other_port.port == port:
                        return other_port
        return None

    def receive_message(self, serial_port):
        index = self.serial_ports.index(serial_port)
        while True:
            try:
                if serial_port.in_waiting > 0:
                    # 接收串口数据
                    data_udp = serial_port.readline().decode('utf-8').rstrip()
                    message = data_udp
                    print(f"Received from {serial_port.port}: {message}")
                    display_info(self.receive_log_texts[index], message)
                    # 可以在这里添加对消息的处理逻辑

                    "等待声通机启动"
                    if not self.start_flag:
                        if len(message) >= 8:
                            if message[0] == '$' and message[-1] == '#':
                                myid = int(message[5] + message[6])
                                self.myid = myid
                                self.start_flag = True
                                response = "ID" + str(self.myid) + ":Successfully started"
                                self.send_message(serial_port, response)
                                display_info(send_log_text, response)
                            else:
                                continue
                        else:
                            continue

                    flag = True

                    if self.myid == 19:

                        "识别指令"
                        data_rev = message[1:-1]
                        # data_rev = hex_to_string(data_rev)

                        "假设收到032209XXX1指令"
                        if data_rev == '032209XXX1':

                            "这部分是指令前六位的处理"

                            response_ = message[1:5] + '09'

                            "返回数据123456"
                            data_send = '123456'

                            "发送数据"
                            self.send_formatted_response(serial_port, response_, data_send)
                            continue

                            "主动切换：中心节点的总控发起切换"
                            "或被动切换：水面节点要切换"
                        elif data_rev == '031819':

                            "总控先给中心2发送$032019#"

                            response_ = '032019'
                            data_send = ''
                            other_port = self.get_other_port(serial_port)
                            self.send_formatted_response(other_port, response_, data_send)
                            continue

                            "若收到$0320191#（说明唤醒中心2成功，中心2成为现用）"
                        elif data_rev == '0320191':

                            "再给中心1发送$032119#使其成为备用" \
                            "中心1收到$032119#之后要加flag，回复$0321191#。"

                            response_ = '$032119'
                            data_send = ''
                            other_port = self.get_other_port(serial_port)
                            self.send_formatted_response(other_port, response_, data_send)
                            continue

                        else:
                            continue
                        "这一部分同理19号节点，还没修改，需要得到具体指令转换任务"
                        "这一部分同理19号节点，还没修改，需要得到具体指令转换任务"
                        "这一部分同理19号节点，还没修改，需要得到具体指令转换任务"
                    elif myid == 11:
                        if flag:
                            for i in range(3):
                                response = '$0162193131313131313131313131313131313131313131313131313131313131313131313131313131313131313131313131313131313131313131313131#'
                                self.send_message(serial_port, response)
                                display_info(send_log_text, response)
                            continue
                    elif myid == 12:
                        if flag:
                            for i in range(3):
                                response = '$0162193132313231323132313231323132313231323132313231323132313231323132313231323132313231323132#'
                                self.send_message(serial_port, response)
                                display_info(send_log_text, response)
                            continue
                    elif myid == 13:
                        if flag:
                            for i in range(3):
                                response = '$016219313331333133313331333133313331333133313331333133313331333133313331333133313331333133313331333133313331333133#'
                                self.send_message(serial_port, response)
                                display_info(send_log_text, response)
                            continue
                    elif myid == 14:
                        if flag:
                            for i in range(3):
                                response = '$016219313431343134313431343134313431343134313431343134313431343134313431343134313431343134313431343134313431343134#'
                                self.send_message(serial_port, response)
                                display_info(send_log_text, response)
                            continue

                    else:
                        response = "Message received"
                        self.send_message(serial_port, response)
                        display_info(send_log_text, response)

                else:
                    continue

            except Exception as e:
                print(f"Error receiving message from {serial_port.port}: {e}")

    def send_message(self, serial_port, message):
        """
        发送消息到指定串口
        """
        serial_port.write((message + '\n').encode('utf-8'))

    def send_formatted_response(self, serial_port, response_, data):
        """
        如果超过380字节，则分批发送
        :param serial_port: 要发送数据的串口
        :param response_:即指令前六位
        :param data: 数据载体

        """
        start_part = "$" + response_
        end_part = "#"
        node_id = "nodeID"
        send_times_prefix = "SendTimes"
        payload_prefix = "PayLoad"

        # Base_len = len(node_id)+len(send_times_prefix)+len(payload_prefix)+len(str(myid))+1

        # 去除 $ 和 # 后的实际数据
        hex_data = string_to_hex(data)
        hex_node_id = string_to_hex(node_id)
        hex_send_times_prefix = string_to_hex(send_times_prefix)
        hex_payload_prefix = string_to_hex(payload_prefix)
        hex_myid = string_to_hex(str(self.myid))

        chunk_size = 330  # 由于nodeID19SendTimes01PayLoad这部分占了50字节，所以只能发330字节
        chunk_num = 1
        if len(hex_data) == 0:
            "切换设备走这里"
            formatted_chunk = f"{start_part}{end_part}"
            self.send_message(serial_port, formatted_chunk)
            display_info(send_log_text, formatted_chunk)

        else:
            for i in range(0, len(hex_data), chunk_size):
                print(chunk_num)
                chunk_num_hex = string_to_hex(str(chunk_num))
                chunk = hex_data[i:i + chunk_size]
                if self.myid == 19:
                    formatted_chunk = f"{start_part}{chunk}{end_part}"
                else:
                    formatted_chunk = f"{start_part}{hex_node_id}{hex_myid}{hex_send_times_prefix}{chunk_num_hex}{hex_payload_prefix}{chunk}{end_part}"
                print(len(formatted_chunk))
                # print(hex_to_string(formatted_chunk[7:57]))
                self.send_message(serial_port, formatted_chunk)
                display_info(send_log_text, formatted_chunk)
                chunk_num += 1


if __name__ == "__main__":
    # 获取系统中所有可用的串口
    available_ports = [port.device for port in list_ports.comports()]
    if len(available_ports) < 1:
        print("系统中没有可用的串口，请检查硬件连接。")
    elif len(available_ports) > 2:
        print("系统中可用串口超过两个，仅使用前两个。")
        available_ports = available_ports[:2]


    # available_ports = ['COM1', 'COM2']


    baudrate = 9600
    server = SerialServer(ports=available_ports, baudrate=baudrate)

    # 创建窗口
    window = tk.Tk()
    window.title("Serial Server")

    # 日志框grid
    frame_display = tk.Frame(window)

    # 发送日志文本框
    message_label_3 = tk.Label(frame_display, text="send log")
    message_label_3.grid(row=0, column=0, sticky="w")
    clear_button_2 = tk.Button(frame_display, text="clear log", command=clear_send_text)
    clear_button_2.grid(row=0, column=1, stick="e")
    send_log_text = tk.Text(frame_display, height=8, width=90, wrap=tk.WORD)
    send_log_text.grid(row=1, columnspan=2)

    # 根据可用串口数量创建接收日志文本框
    for i, port in enumerate(available_ports):
        frame_recv = tk.Frame(frame_display)
        message_label_4 = tk.Label(frame_recv, text=f"recv log from {port}")
        message_label_4.grid(row=0, column=0, sticky="w")

        def create_clear_command(index):
            return lambda: clear_recv_text(server.receive_log_texts[index])

        clear_button_3 = tk.Button(frame_recv, text="clear recv log", command=create_clear_command(i))
        clear_button_3.grid(row=0, column=1, stick="e")
        receive_log_text = tk.Text(frame_recv, height=8, width=90, wrap=tk.WORD)
        receive_log_text.grid(row=1, columnspan=2)
        server.receive_log_texts.append(receive_log_text)
        frame_recv.grid(row=2 + i * 2, column=0, columnspan=2)

    # 显示文本框位置
    frame_display.grid(row=2, column=2)

    # 运行窗口
    window.mainloop()

    try:
        while True:
            pass
    except KeyboardInterrupt:
        print("Server shutting down...")
