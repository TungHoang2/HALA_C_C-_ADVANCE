#include <stdio.h>

int main() {
    int a = 10;
    const int *ptr = &a;  // Không được thay đổi giá trị qua con trỏ
    printf("%d\n",a);
    *ptr = 20;  // Lỗi: Không thể thay đổi giá trị
    printf("%d",a);
}
