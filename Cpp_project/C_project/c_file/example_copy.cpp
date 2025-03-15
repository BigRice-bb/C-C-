//实现文件的拷贝
//对一个文件读,对另一个文件写,就ok
//打开两个文件-一个读,一个写
//fread  fwrite  判断读出和写入是否相同
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include"string.h"

void fp_copy(char *src,char*dst)
{
    //打开需要读写的文件
    FILE* sfp=fopen(src,"r");//源文件
    if(!sfp)
    {
        perror("src file open error:");
        return;
    }
    FILE* dfp=fopen(dst,"w");//目的文件
    if(!dfp)
    {
        perror("dst file open error:");
        return;
    }
    char buf[256];//数据缓存,char大小为1byte,方便计算
    int ret;//返回值接收
    while(1)
    {
        ret=fread(buf,1,sizeof(buf),sfp);//读256个数据
        if(ret==0)
        {
            break;
        }
        fwrite(buf,1,ret,dfp);//将256个数据写入dst
        memset(buf,0,256);//清空数组
    }
    fclose(sfp);
    fclose(dfp);
}

//传入三个参数  程序名 源argc[0]  目的argc[1]
int main(int agrc,char **argv)
{
    fp_copy(argv[1],argv[2]);
    return EXIT_SUCCESS;
}