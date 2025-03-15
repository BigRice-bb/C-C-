clear all
close all
clc
% 参数设置
fs = 20000;  % 采样频率 (Hz)
T = 1;       % 信号长度 (s)
t = 0:1/fs:T-1/fs;  % 时间轴

% 几何参数
z_s = 50;    % 声源深度 (m)
z_r = 200;   % 接收器深度 (m)
d = 5000;    % 水平距离 (m)
H = 300;     % 海深 (m)
c = 1500;    % 声速 (m/s)

% 计算路径长度
L_direct = sqrt(d^2 + (z_r - z_s)^2);            % 直达波
L_surface = sqrt(d^2 + (z_r + z_s)^2);           % 海面反射波
L_bottom = sqrt(d^2 + (2*H - z_r - z_s)^2);      % 海底反射波

% 计算时延
tau_direct = L_direct / c;
tau_surface = L_surface / c;
tau_bottom = L_bottom / c;
tau_sd = tau_surface - tau_direct;
tau_bd = tau_bottom - tau_direct;

% 生成宽带信号 (2-6 kHz)
f_l = 2000; f_h = 6000;  % 信号频带 (Hz)
signal = randn(1, length(t));  % 高斯白噪声，宽带信号
% 设计带通滤波器
Wn = [f_l f_h] / (fs / 2); 
bp_filter = fir1(50, Wn, 'bandpass');
signal = filter(bp_filter, 1, signal);

% 数字延时
N_s = round(tau_sd * fs);
N_b = round(tau_bd * fs);
N_max = max(N_s,N_b);
signal_direct = signal(N_max + 1:length(signal));
signal_surface = signal(N_max - N_s + 1:length(signal) - N_s);
signal_bottom = signal(N_max - N_b + 1:length(signal) - N_b);

% 合成接收信号
received_signal = signal_direct + signal_surface + signal_bottom;

% 自相关处理
correlation = xcorr(received_signal, signal_direct);
lags = (-length(received_signal)+1:length(received_signal)-1) / fs;


% 绘制相关函数
figure;
plot(lags, correlation);
hold on;
xline(tau_direct, 'r--', sprintf('直达波: %.6f s', tau_direct));
xline(tau_surface, 'g--', sprintf('海面反射波: %.6f s', tau_surface));
xline(tau_bottom, 'b--', sprintf('海底反射波: %.6f s', tau_bottom));
title('自相关函数及多途时延');
xlabel('时延 (s)');
ylabel('相关函数');
grid on;
legend;
hold off;
