#include <iostream>
using namespace std;

int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int (*arrayPtr)[4] ; // 数组指针，指向包含 4 个 int 类型元素的数组

    arrayPtr = arr; // 数组名是数组的首地址，所以可以直接赋值
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arrayPtr[i][j] << " "; // 输出数组元素
        }
        cout << endl;
    }

    return 0;
}