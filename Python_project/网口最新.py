# -*- coding: utf-8 -*-
import tkinter as tk
import socket
import threading
from datetime import datetime
import logging
import os


#ID号默认没有
myid = None

# 默认主机和端口
default_host1 = '127.0.0.1'  # "127.0.0.1"  # "192.168.1.2";"192.168.1.2"
default_port1 = 6009

#备用主机和端口
default_host2 = '127.0.0.1'  # "127.0.0.1"  # "192.168.1.2";"192.168.1.2"
default_port2 = 6007

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

#判断log文件夹是否创建
check_and_create(log_name,True)
#判断sensor_data.txt是否创建
check_and_create(receive_file_name,False)

#定义本次时间戳下的.log
now = datetime.now()
log_file = "./log/" + now.strftime("%Y-%m-%d-%H-%M-%S")+"_server" + ".log"
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


def clear_recv_text():
    """
    清屏接收框

    """
    receive_log_text.delete("1.0", tk.END)


class UDPServer:
    def __init__(self, host, port):
        self.myid = None
        self.start_flag = False
        self.host = host
        self.port = port
        # 创建 UDP 套接字
        self.udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        # 绑定地址和端口
        self.udp_socket.bind((self.host, self.port))
        # 启动接收消息的线程
        receive_thread = threading.Thread(target=self.receive_message)
        receive_thread.daemon = True
        receive_thread.start()



    def receive_message(self):


        while True:
            try:
                # 接收客户端消息
                data_udp, client_address = self.udp_socket.recvfrom(1024 * 1024)
                message = data_udp.decode('utf-8')
                print(f"Received from {client_address}: {message}")
                display_info(receive_log_text, message)
                # 可以在这里添加对消息的处理逻辑

                "等待声通机启动"
                if not self.start_flag:
                    if len(message)>=8:
                        if message[0]=='$' and message[-1] == '#':
                            myid = int(message[5]+message[6])
                            self.myid = myid
                            self.start_flag = True
                            response = "ID"+str(self.myid)+":Successfully started"
                            self.udp_socket.sendto(response.encode(), client_address)
                            display_info(send_log_text, response)
                        else:continue
                    else:continue


                flag = True

                if myid == 19:

                    "识别指令"
                    data_rev = message[1:-1]
                    # data_rev = hex_to_string(data_rev)

                    "收到032209XXX1指令"
                    if data_rev== '032209XXX1':

                        "这部分是指令前六位的处理"
                        response_ = message[1:5]+'09'

                        "返回数据123456"
                        data_send = '123456'

                        "发送数据"
                        self.send_formatted_response(response_,client_address,data_send)
                        continue

                        "主动切换：中心节点的总控发起切换"
                        "或被动切换：水面节点要切换"
                    elif data_rev == '031819':

                        "总控先给中心2发送$032019#"

                        response_ = '032019'
                        address_standby = (default_host2,default_port2)
                        data_send = ''
                        self.send_formatted_response(response_, address_standby, data_send)
                        continue

                        "若收到$0320191#（说明唤醒中心2成功，中心2成为现用）"
                    elif data_rev == '0320191':

                        "再给中心1发送$032119#使其成为备用" \
                        "中心1收到$032119#之后要加flag，回复$0321191#。"

                        response_ = '$032119'
                        address_standby = (default_host1, default_port1)
                        data_send = ''
                        self.send_formatted_response(response_, address_standby, data_send)
                        continue







                    "这一部分同理19号节点，还没修改，需要得到具体指令转换任务"
                    "这一部分同理19号节点，还没修改，需要得到具体指令转换任务"
                    "这一部分同理19号节点，还没修改，需要得到具体指令转换任务"
                elif myid == 11:
                    if flag:
                        for i in range(3):
                            response = '$01621931313131313131313131313131313131313131313131313131313131313131313131313131313131313131313131313131313131313131313131313131313131#'
                            self.udp_socket.sendto(response.encode(), client_address)
                            display_info(send_log_text, response)
                        continue
                elif myid == 12:
                    if flag:
                        for i in range(3):
                            response = '$016219313231323132313231323132313231323132313231323132313231323132313231323132313231323132#'
                            self.udp_socket.sendto(response.encode(), client_address)
                            display_info(send_log_text, response)
                        continue
                elif myid == 13:
                    if flag:
                        for i in range(3):
                            response = '$016219313331333133313331333133313331333133313331333133313331333133313331333133313331333133313331333133313331333133#'
                            self.udp_socket.sendto(response.encode(), client_address)
                            display_info(send_log_text, response)
                        continue
                elif myid == 14:
                    if flag:
                        for i in range(3):
                            response = '$016219313431343134313431343134313431343134313431343134313431343134313431343134313431343134313431343134313431343134313431343134#'
                            self.udp_socket.sendto(response.encode(), client_address)
                            display_info(send_log_text, response)
                        continue

                else:
                    response = "Message received"
                    self.udp_socket.sendto(response.encode(), client_address)
                    display_info(send_log_text, response)

            except Exception as e:
                print(f"Error receiving message: {e}")

    def send_formatted_response(self, response_,address, data):
        """
        如果超过380字节，则分批发送
        :param response_:即指令前六位
        :param address: ：接收方地址
        :param data: 数据载体

        """
        start_part = "$"+response_
        end_part = "#"
        node_id = "nodeID"
        send_times_prefix = "SendTimes"
        payload_prefix = "PayLoad"


        # 去除 $ 和 # 后的实际数据
        hex_data = string_to_hex(data)
        hex_node_id = string_to_hex(node_id)
        hex_send_times_prefix = string_to_hex(send_times_prefix)
        hex_payload_prefix = string_to_hex(payload_prefix)
        hex_myid = string_to_hex(str(self.myid))

        chunk_size = 330#由于nodeID19SendTimes01PayLoad这部分占了50字节，所以只能发330字节
        chunk_num = 1
        if len(hex_data)==0:
            "切换设备走这里"
            formatted_chunk = f"{start_part}{end_part}"
            self.udp_socket.sendto(formatted_chunk.encode(), address)
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
                self.udp_socket.sendto(formatted_chunk.encode(), address)
                display_info(send_log_text, formatted_chunk)
                chunk_num += 1



if __name__ == "__main__":

    '师兄，这里的网口地址要修改，因为我是在本地测试的'
    server = UDPServer('127.0.0.1', 12345)

    # 创建窗口
    window = tk.Tk()
    window.title("UDP Server")

    # 日志框grid
    frame_display = tk.Frame(window)

    # 发送日志文本框
    message_label_3 = tk.Label(frame_display, text="send log")
    message_label_3.grid(row=0, column=0, sticky="w")
    clear_button_2 = tk.Button(frame_display, text="clear log", command=clear_send_text)
    clear_button_2.grid(row=0, column=1, stick="e")
    send_log_text = tk.Text(frame_display, height=8, width=90, wrap=tk.WORD)
    send_log_text.grid(row=1, columnspan=2)

    # 接收日志文本框
    message_label_4 = tk.Label(frame_display, text="recv log")
    message_label_4.grid(row=2, column=0, sticky="w")
    clear_button_3 = tk.Button(frame_display, text="clear recv log", command=clear_recv_text)
    clear_button_3.grid(row=2, column=1, stick="e")
    receive_log_text = tk.Text(frame_display, height=8, width=90, wrap=tk.WORD)
    receive_log_text.grid(row=3, columnspan=2)

    # 显示文本框位置
    frame_display.grid(row=2, column=2)

    # 运行窗口
    window.mainloop()

    try:
        while True:
            pass
    except KeyboardInterrupt:
        print("Server shutting down...")
