#include <stdio.h>

void function() {
    static int static_variable = 0;  // 静态局部变量
    static_variable++;
    printf("静态局部变量的值: %d\n", static_variable);
}

int main() {
    function();  // 第一次调用
    function();  // 第二次调用
    return 0;
}