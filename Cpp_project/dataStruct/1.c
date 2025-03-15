#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 定义顺序表结构体
typedef struct {
    int data[MAX_SIZE];
    int length;
} SeqList;

// 初始化顺序表
void initList(SeqList *list) {
    list->length = 0;
}

// 向顺序表中插入元素
void insertElement(SeqList *list, int value) {
    if (list->length < MAX_SIZE) {
        list->data[list->length++] = value;
    } else {
        printf("顺序表已满，无法插入元素！\n");
    }
}

// 删除顺序表中值在 x 和 y 之间的所有元素
void deleteElementsBetween(SeqList *list, int x, int y) {
    int k = 0;  // 用于记录新的顺序表长度
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] < x || list->data[i] > y) {
            list->data[k] = list->data[i];
            k++;
        }
    }
    list->length = k;  // 更新顺序表的长度
}

// 打印顺序表
void printList(SeqList *list) {
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    SeqList list;
    initList(&list);

    // 插入一些测试元素
    insertElement(&list, 1);
    insertElement(&list, 3);
    insertElement(&list, 5);
    insertElement(&list, 7);
    insertElement(&list, 9);
    insertElement(&list, 2);
    insertElement(&list, 4);
    insertElement(&list, 6);
    insertElement(&list, 8);

    printf("原始顺序表: ");
    printList(&list);

    int x = 3, y = 6;
    deleteElementsBetween(&list, x, y);

    printf("删除值在 %d 和 %d 之间的元素后: ", x, y);
    printList(&list);

    return 0;
}