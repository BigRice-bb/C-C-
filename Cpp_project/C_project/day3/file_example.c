#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//获取文件行数
int getfile_len(FILE* fp)
{
    int i=0;
    char str[128];
    while (fgets(str,128,fp))
    {
        i++;
    }
    return i;    
}
//将每行放入堆区
void putdata_heap(FILE*fp,char**parray)
{
    //创建临时的缓存,用于搬运
    char str[128];
    int n;//每行的大小,用于开辟数组
    int i=0;
    while(fgets(str,128,fp))
    {
        //fgets(str,128,fp);
        n=strlen(str)+1;//不包含\0的
        parray[i]=(char*)malloc(n);
        strcpy(parray[i],str);
        i++;
        memset(str,0,128);
    }
}
//打印字符串
void show_str(char**parray,int len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%s",parray[i]);
    }
}
//释放内存
void heap_free(char** parray,int len)
{
    for (size_t i = 0; i < len; i++)
    {
        if(parray[i]!=NULL)
        {
            free(parray[i]);
            parray[i]=NULL;
        }
    }
    if(parray!=NULL)
    {
        free(parray);
        parray=NULL;
    }
}
void test01()
{
    //第一步打开文件
    FILE*fp=fopen("test.txt","r");
    if(!fp)
    {
        perror("open error...");
    }
    int len=getfile_len(fp);
    printf("文件行数为--%d\n",len);
    //将文件指针移动到文件头部--或者关闭重新打开也可以
    rewind(fp);
    //二级指针,用于存放每行的首地址
    char** parray=(char**)malloc(sizeof(char*)*len);
    //放数据到堆区空间
    putdata_heap(fp,parray);
    //打印字符串
    show_str(parray, len);
    //释放内存
    heap_free(parray,len);
    //关闭文件
    fclose(fp);
}
int main()
{
    test01();
    system("pause");
    return 0;
}