#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 不可以用void创建创建变量--不能够分配内存空间
// 用处:
// 1,限定函数的返回值,函数声明必须加返回值类型
// 2,void * 万能指针 (空指针)--sizeof(void*)=8(64为电脑)
//   8字节可以存下任何数据类型的地址
//   可以不通过强制类型转换转成其他类型
void test01()
{
    printf("%d\n",sizeof(void*));//8字节--该电脑为64位处理器
}
int main()
{
    test01();
    system("pause");
    return 0;
}