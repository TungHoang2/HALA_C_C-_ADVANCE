## 1.Con trỏ (Pointer)
### 1.1. Khái niệm
Con trỏ là 1 biến chứa địa chỉ bộ nhớ của 1 biến khác (biến, hàm,…)
### 1.2. Cách khai báo
<data_type> *<tên_biến>;

Có thể khai báo bằng 2 kiểu (Ưu tiên sử dụng kiểu 1 vì thuận tiện, dễ theo dõi):

Kiểu 1:
```
int x =10;
int *ptr = &x;
```
Kiểu 2:
```
int x=10;
int *ptr;
ptr =&x;
```
Chú ý: Trước khi truy cập hoặc sử dụng con trỏ, cần đảm bảo rằng nó đã được gán địa chỉ hợp lệ.
Ví dụ: 
Sai
int *ptr;
*ptr = 10; // Lỗi, vì ptr chưa được gán địa chỉ hợp lệ.
Đúng
int x = 10;
int *ptr = &x;  // ptr được gán địa chỉ của x



### 1.3. Kích thước con trỏ

Kích thước của con trỏ sẽ phụ thuộc vào kiến trúc máy tính và trình biên dịch bởi cơ bản con trỏ là địa chỉ bộ nhớ mà kích thước của địa chỉ thì giống nhau trong cùng 1 kiến trúc máy tính nên cho dù có khai báo kiểu dữ liệu int, char, double,…. thì kích thước của con trỏ cũng như nhau.

Compiler 64-bits thì con trỏ có kích thước 8 bytes.

Compiler 32-bits thì con trỏ có kích thước 4 bytes.

Compiler 8-bits thì con trỏ có kích thước 1 bytes.

### Ví dụ về pointer:
``` C
int swap_1(int a, int b){   
    int temp = a;
    a = b;
    b = temp;
}

int swap_2(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 5;    
    int b = 10;
    swap_2(&a,&b);
    printf("Gia tri cua a: %d\n",a);
    printf("Gia tri cua b: %d\n",b);
}
```
Giải thích:
Ở hàm main(), khi khai báo biến a và b thì khi đó giả sử a có địa chỉ là 0x01 – có giá trị là 5, b có địa chỉ là 0xd0 – có giá trị là 10

Đối với hàm swap_1, khi thực hiện biến a, b tuy cùng tên nhưng lại được cung cấp địa chỉ tạm thời giả sử là 0x02 và 0xf1 thì chỉ đổi giá trị ở 2 ô nhớ đó khi thực hiện xong hàm thì địa chỉ sẽ được thu hồi lại thế nên không ảnh hưởng đến 2 ô nhớ cần thay đổi.

Đối với hàm swap_2, thao tác trực tiếp với giá trị trên ô nhớ đó nên có thể thay đổi được

### 1.4. Các kiểu con trỏ
### 1.4.1. Void pointer
Dùng để trỏ đến bất kì địa chỉ nào mà không quan tâm kiểu dữ liệu của giá trị tại địa chỉ đó và có thể truy cập các kiểu dữ liệu khác bằng cách ép kiểu.
Khai báo: void *<tên_biến>;

Ví dụ:
```
#include <stdio.h>

int main(){
    void *ptr;

    int a =10;
    ptr = &a;
    printf("Gia tri cua a: %d\n", *(int*)ptr);

    double b = 5.6;
    ptr = &b;
    printf("Gia tri cua b: %f\n", *(double*)ptr);

    char c = 's';
    ptr = &c;
    printf("Gia tri cua c: %c\n", *(char*)ptr);
}
```
Tại sao phải ép kiểu?

Void pointer không có một kiểu dữ liệu cụ thể. Khi một con trỏ trỏ đến kiểu dữ liệu cụ thể như int, float, double, hoặc char, trình biên dịch cần biết chính xác kiểu dữ liệu mà nó trỏ đến để biết cách truy xuất và thao tác với dữ liệu đó.

### 1.4.2. Function pointer
Khai báo : <data_type> (*<tên_biến>) (<data_type_para1>, <data_type_para2>, …)

void (*ptr_func) (int, int)


Ví dụ:
```
#include <stdio.h>

void sum(int a, int b){
    printf("Tong bang: %d",a+b);
}

void subtract(int a, int b){
    printf("Hieu bang: %d",a-b);
}

void multiple(int a, int b){
    printf("Tich bang: %d",a*b);
}

void divide(int a, int b){
    printf("Thuong bang: %f",a/b);
}

void cal(void (*ptr) (int,int), int a, int b){
    ptr(a,b);
}

int main(){
    // Cách 1
    void (*ptr) (int, int);
    int a=5,b=7;

    ptr = sum;
    ptr(a,b); // hoặc (*ptr) (a,b)

    // Cách 2 : dùng array
    void (*cal[])(int,int)={sum, subtract, multiple, divide};

    cal[0](a,b);
    cal[4](a,b);

    // Cách 3: dùng hàm con
    cal1(sum, a, b);
    cal1(subtract, a, b);
}
```
Chú ý: Địa chỉ của hàm có thể là <tên_hàm> hoặc &<tên_hàm>
	Có thể gọi hàm bằng cách ptr(a,b) hoặc (*ptr)(a,b)


### 1.4.3. Pointer to constant – con trỏ hằng
Định nghĩa: Một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.

Khai báo: <data_type> const *<tên_biến>; hoặc const <data_type> *<tên biến>;

          int const *ptr_const;  hoặc const int *ptr_const;

Ví dụ:
```
#include <stdio.h>

int main(){
    int a = 5;
    int b = 6;
    const int *ptr_const = &a;

    printf("Gia tri cua a: %d\n", *ptr_const);   // Output: Gia tri cua a: 5
    //*ptr_const = 4;                           // Sai: không thể thay đổi qua pointer
    a = 4;                                      // Đúng: chỉ có thể thay đổi trực tiếp qua biến
    printf("Gia tri cua a: %d\n",*ptr_const);   // Output: Gia tri cua a: 4

    ptr_const = &b;                             // Có thể trỏ đến địa chỉ khác
    printf("Gia tri cua b: %d",*ptr_const);     // Gia tri cua b: 6
}
```
Chú ý: Tại địa chỉ mà nó trỏ đến chỉ có thể đọc giá trị mà không thể thay đổi giá trị thông qua pointer

Có thể trỏ đến địa chỉ khác (khác so với Constant Pointer – hằng con trỏ)

### 1.4.4. Constant Pointer
Định nghĩa: Là 1 con trỏ mà khi đã được khởi tạo thì không thể thay đổi địa chỉ khác (trỏ đến 1 địa chỉ duy nhất)
Khai báo: <data_type> *const <tên_biến> (int *const const_ptr)

Ví dụ: 
```
#include <stdio.h>

int main(){
    int a = 5;
    int b = 6;
    int *const const_ptr = &a;

    printf("Gia tri cua a: %d\n",*const_ptr);   // Output: Gia tri cua a: 5
    *const_ptr = 4;                             // Có thể thay đổi qua pointer
    printf("Gia tri cua a: %d\n",*const_ptr);   // Output: Gia tri cua a: 4

    //const_ptr = &b;                           // Sai: không thể trỏ đến địa chỉ khác

}
```
### 1.4.5. NULL Pointer
Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào và có địa chỉ mặc định là 0x00
Khi sử dụng xong phải gán là giá trị NULL tránh con trỏ sẽ trỏ vào các vị trí không mong muốn

Khi nào sử dụng con trỏ NULL?

Khi khởi tạo con trỏ mà không gán giá trị thì nó sẽ trỏ đến 1 địa chỉ ngẫu nhiên (địa chỉ rác) và khi sử dụng vi xử lý có trường hợp sẽ trỏ đến vị trí mình đang sử dụng, thay đổi giá trị và gây ra lỗi.

Đối với lập trình vi xử lý, khi khai báo con trỏ mà chưa sử dụng thì phải gán giá trị NULL để tránh bị lỗi.

### 1.4.6. Pointer to pointer
Con trỏ trỏ đến con trỏ (Pointers to pointers) là một con trỏ chứa địa chỉ của một con trỏ khác
Ví dụ: 
```
#include <stdio.h>

int main(){
    int a =5;
    int *ptr = &a;  //  &ptp = 0x01 _ &ptr = 0xc1 _ a = 10
    int **ptp = &ptr;

    printf("%d",*(*ptp));
}
```
Giải thích: ptp có địa chỉ là 0x01, ptr có địa chỉ là 0xc1, giá trị bên trong địa chỉ 0xc1 = 10. *ptp sẽ là địa chỉ của ptr  vậy nên **ptp = *&ptr = 10

