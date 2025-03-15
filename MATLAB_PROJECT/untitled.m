% 参数设定
Fs = 20000;                % 采样频率 20 kHz
T = 1;                     % 信号长度 1秒
t = 0:1/Fs:T-1/Fs;         % 时间向量
f = 3000;                  % 频率 3 kHz（一个示例频率，在信号频带范围内）
signal = cos(2*pi*f*t);    % 生成一个3 kHz的信号（宽带信号的一部分）

% 计算理论时延
t_direct = 3.34;           % 直达波时延 (秒)
t_surface = 4.14;          % 海面反射波时延 (秒)
t_bottom = 4.23;           % 海底反射波时延 (秒)

% 创建不同的信号：直达波、海面反射波、海底反射波
direct_signal = cos(2*pi*f*(t - t_direct));  % 直达波
surface_signal = cos(2*pi*f*(t - t_surface));% 海面反射波
bottom_signal = cos(2*pi*f*(t - t_bottom));  % 海底反射波

% 合成宽带多途信号
total_signal = signal + surface_signal + bottom_signal;

% 计算自相关函数
[acor, lag] = xcorr(total_signal, 'unbiased');  % 自相关计算

% 转换时延为秒
lag_seconds = lag / Fs;

% 绘制自相关函数
figure;
plot(lag_seconds, acor);
xlabel('时延 (秒)');
ylabel('自相关');
title('水下宽带多途信号的自相关函数');
grid on;

% 计算自相关函数的峰值位置
[~, peak_idx] = max(acor);  % 获取最大值位置
detected_delay = lag_seconds(peak_idx);  % 对应的时延值

% 在图中标出理论时延值和检测到的时延值
hold on;
plot([t_direct, t_direct], ylim, 'r--', 'LineWidth', 1.5); % 直达波理论时延
plot([t_surface, t_surface], ylim, 'g--', 'LineWidth', 1.5); % 海面反射波理论时延
plot([t_bottom, t_bottom], ylim, 'b--', 'LineWidth', 1.5);  % 海底反射波理论时延

% 标注时延
text(t_direct + 0.01, max(acor)*0.8, sprintf('理论直达波时延: %.2f s', t_direct), 'Color', 'r');
text(t_surface + 0.01, max(acor)*0.7, sprintf('理论海面反射波时延: %.2f s', t_surface), 'Color', 'g');
text(t_bottom + 0.01, max(acor)*0.6, sprintf('理论海底反射波时延: %.2f s', t_bottom), 'Color', 'b');

% 标注检测到的时延
text(detected_delay + 0.01, max(acor)*0.5, sprintf('检测到的时延: %.2f s', detected_delay), 'Color', 'k');
hold off;
