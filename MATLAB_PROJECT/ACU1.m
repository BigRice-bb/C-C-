% 参数设定
Fs = 1000;                % 采样频率 (Hz)
T = 1;                    % 信号持续时间 (秒)
f = 50;                   % 信号频率 (Hz)
t = 0:1/Fs:T-1/Fs;        % 时间向量

% 生成正弦波
y = sin(2*pi*f*t);        % 正弦波公式

% 绘制正弦波
figure;
plot(t, y);
xlabel('时间 (秒)');
ylabel('幅度');
title(['频率 = ', num2str(f), ' Hz 的正弦波']);
grid on; % 启用网格
