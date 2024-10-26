# Quá trình biên dịch chương trình của Compiler

## Preprocessing (Tiền xử lý)

**Chức năng:**
* Xử lý các chỉ thị tiền xử lý (preprocessor directives) như #include, #define, và #ifdef.
* Kết quả của giai đoạn này là một mã nguồn đã được mở rộng (expanded source code), trong đó các file được #include đã được chèn vào, các macro đã được thay thế và các comment được loại bỏ.

**Kết quả:** File đầu ra thường là .i hoặc .ii (đối với C++).

**Ví dụ:**
``` C
#define PI 3.14
int main() {
    float x = PI;
    return 0;
}
```

Sau tiền xử lý: 
``` C
int main() {
    float x = 3.14;
    return 0;
}
```

## Compiler

**Chức năng:**

* Chuyển mã C đã qua tiền xử lý thành mã hợp ngữ (assembly code).
* Phân tích cú pháp và kiểm tra tính hợp lệ của mã nguồn:
Kiểm tra cú pháp (syntax) có đúng không,
 kiểm tra ý nghĩa của mã (ví dụ: kiểm tra kiểu dữ liệu và sự tương thích của chúng).
* Kết quả là một mã hợp ngữ.

**Kết quả:** File đầu ra thường là .s.

## Assembler

**Chức năng:**
* Chuyển mã hợp ngữ thành mã máy (machine code), dạng nhị phân mà CPU có thể hiểu được.
* Kết quả là một object file (file đối tượng), thường có phần mở rộng là .o hoặc .obj.

## Linker

**Chức năng:**
* Liên kết các object files với nhau và với các thư viện cần thiết (như thư viện chuẩn C libc).
* Kết quả là một file thực thi hoàn chỉnh (executable).
  
**Quá trình này:**
* Gán địa chỉ cho các hàm và biến.
* Xử lý các lệnh gọi hàm bên ngoài (external calls), ví dụ: các lệnh gọi printf được liên kết với thư viện chuẩn.

**Kết quả:** File đầu ra là một file thực thi (.exe)

# Macro
## Macro hằng số

**Chức năng:** Thay thế một hằng số hoặc đoạn mã đơn giản.

**Ví dụ:**
``` C
#include <stdio.h>
#define PI 3.14

int main() {
    printf("PI = %f\n", PI);
    return 0;
}
```
Khi xuất hiện PI trong chương trình, bộ tiền xử lý sẽ thay thế nó bằng 3.14 trước khi biên dịch.

## Macro dạng hàm

**Chức năng:** Hoạt động giống như một hàm, nhưng chỉ là thay thế văn bản trước khi biên dịch.

``` C
#include <stdio.h>
#define SQUARE(x) ((x) * (x))

int main() {
    int num = 5;
    printf("Square of %d is %d\n", num, SQUARE(num));
    return 0;
}
```

**Lưu ý:** Các macro dạng hàm không kiểm tra kiểu dữ liệu của tham số, vì chúng chỉ là thay thế văn bản.

## Macro có điều kiện (Condition Macro)

### #if – Kiểm tra điều kiện

**Chức năng:** Biên dịch đoạn mã nếu điều kiện sau #if là đúng.

**Ví dụ:**
``` C
#define VERSION 2

#if VERSION == 2
#include <stdio.h>
int main() {
    printf("Version 2\n");
    return 0;
}
#endif
```

### #ifdef

**Chức năng:** Biên dịch đoạn mã nếu macro đã được định nghĩa bằng #define.

**Ví dụ:**
``` C
#define DEBUG

#ifdef DEBUG
#include <stdio.h>
int main() {
    printf("Debug mode is on.\n");
    return 0;
}
#endif
```
### #ifndef 

**Chức năng:** Biên dịch đoạn mã nếu macro chưa được định nghĩa.

**Ví dụ:**
``` C
#ifndef RELEASE
#include <stdio.h>
int main() {
    printf("This is a debug build.\n");
    return 0;
}
#endif
```

### #else
**Chức năng:** Chỉ định đoạn mã thay thế nếu điều kiện #if, #ifdef, hoặc #ifndef không đúng.

**Ví dụ:**
``` C
#define DEBUG

#ifdef DEBUG
    #include <stdio.h>
    int main() {
        printf("Debug mode\n");
        return 0;
    }
#else
    int main() {
        // Mã sản phẩm chính thức không in gì ra
        return 0;
    }
#endif
```

### #elif 
**Chức năng:** Tương tự như else if trong C, nó kiểm tra điều kiện khác nếu điều kiện trước đó không đúng.

**Ví dụ:**
``` C
#define VERSION 3

#if VERSION == 1
    #include <stdio.h>
    int main() {
        printf("Version 1\n");
        return 0;
    }
#elif VERSION == 2
    #include <stdio.h>
    int main() {
        printf("Version 2\n");
        return 0;
    }
#else
    #include <stdio.h>
    int main() {
        printf("Unknown version\n");
        return 0;
    }
#endif
```

### #define và #undef

**Chức năng:**
* #define dùng để định nghĩa macro.
* #undef dùng để hủy bỏ định nghĩa của macro.

**Ví dụ:**
``` C
#define FEATURE

#ifdef FEATURE
#include <stdio.h>
int main() {
    printf("Feature enabled\n");
    return 0;
}
#undef FEATURE
#else
int main() {
    return 0;
}
#endif
```

## Variadic Macro

**Chức năng:** Cho phép macro nhận số lượng đối số không cố định. Sử dụng dấu ... để biểu thị danh sách đối số mở rộng.

``` C
#include <stdio.h>

#define sum(...)                    \
do{                                 \
    int arr[] = {__VA_ARGS__, 0};   \
    int tong = 0;                   \
    int i = 0;                      \
    while (arr[i] != 0)             \
    {                               \
        tong += arr[i];             \
        i++;                        \
    }                               \
    printf("Tong = %d\n", tong);    \
} while (0)                         

int main()
{
    sum(1, 2);
    sum(1, 2, 3);
    sum(1, 3, 5, 7, 9, 11);
}
```

**Note:** 
* Khi khai báo hàm nhiều dòng phải có kí tự '\' ở cuối dòng
* Bởi vì macro là copy toàn bộ source code nên phải dùng do while(0) để có thể gọi nhiều lần vì nếu không khi gọi hàm sum() nhiều lần thì sẽ sinh ra nhiều biến arr[] cùng tên trong main gây ra lỗi. Do while(0) giống như 1 hàm và biến trong nó là cục bộ
* '##' được dùng để nối chuỗi (ví dụ: abc##xyz --> abcxyz)

**Ví dụ:** 
``` C
#define MERGE(x,y) x##y
```

* Dấu # hỗ trợ chuyển 1 đoạn văn bản thành chuỗi (nếu không có # thì máy nó không hiểu được cmd là gì)
  
**Ví dụ:** 
``` C
#define CREATE_STRING(cmd) printf(#cmd)
``` 

# Thư viện STDARG

Thư viện <stdarg.h> cung cấp cơ chế để làm việc với các hàm nhận số lượng đối số không cố định.

**Các macro chính trong thư viện STDARG:**
* va_list: Là 1 kiểu dữ liệu dùng để khai báo danh sách các đối số biến đổi.
* va_start: Khởi tạo danh sách đối số.
* va_arg: Truy cập vào 1 đối số trong danh sách.
* va_end: Kết thúc việc truy cập danh sách đối số.

**Ví dụ:**
``` C
#include <stdio.h>
#include <stdarg.h> // Thư viện cho hàm biến đối số

// Hàm tính tổng của n số nguyên
int sum(int count, ...) {
    va_list args;       // Khai báo danh sách đối số
    va_start(args, count); // Khởi tạo danh sách với đối số đầu tiên là 'count'

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int); // Lấy từng đối số kiểu int
    }

    va_end(args); // Kết thúc việc truy cập danh sách đối số
    return total;
}

int main() {
    printf("Sum of 2, 3, 4: %d\n", sum(3, 2, 3, 4)); // Truyền 3 số nguyên
    printf("Sum of 5, 10, 15, 20: %d\n", sum(4, 5, 10, 15, 20)); // Truyền 4 số nguyên
    return 0;
}
```

**Giải thích:**
* va_list args;: Khai báo danh sách chứa các đối số.
* va_start(args, count);: Khởi tạo danh sách, bắt đầu từ đối số ngay sau count.
* va_arg(args, int);: Lấy từng đối số ra, trong ví dụ này là kiểu int.
* va_end(args);: Kết thúc danh sách đối số.

# Thư viện ASSERT

Thư viện <assert.h> trong C được sử dụng để hỗ trợ kiểm tra điều kiện tại thời gian chạy (runtime). Nó giúp phát hiện lỗi trong quá trình phát triển bằng cách dừng chương trình nếu một biểu thức logic không đúng, hỗ trợ việc debug.

* Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.
* Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.
* Có thể dùng #define NDEBUG để vô hiệu hóa assert

**Ví dụ 1:**
``` C
#include <stdio.h>
#include <assert.h>

int main() {
    int a = 10;
    int b = 0;

    // Kiểm tra b khác 0 để tránh chia cho 0
    assert(b != 0);

    printf("Result: %d\n", a / b); // Không bao giờ tới đây nếu b == 0
    return 0;
}
```

Khi b == 0, assert(b != 0) sẽ sai. Chương trình sẽ in thông báo lỗi và dừng ngay lập tức:

``` C
Assertion failed: b != 0, file example.c, line 9
```

Có thể in thông báo lỗi cụ thể để hiển thị trên terminal:

``` C
assert(b !=0 && "b phai khac 0");
```

**Ví dụ 2:**
``` C
#include <assert.h>

#define ASSERT_IN_RANGE(val, min, max) assert((val) >= (min) && (val) <= (max))

void setLevel(int level) {
    ASSERT_IN_RANGE(level, 1, 10);
    // Thiết lập cấp độ
}
```

# Pointer

## Khái niệm:
Pointer(con trỏ) là một biến lưu trữ địa chỉ của một biến khác. Thay vì lưu trữ dữ liệu trực tiếp, con trỏ lưu địa chỉ của vùng nhớ nơi dữ liệu được lưu. Điều này cho phép truy cập và thao tác với dữ liệu gián tiếp thông qua địa chỉ.
## Cách khai báo
<data_type> *<tên_biến>;

Có thể khai báo bằng 2 kiểu (Ưu tiên sử dụng kiểu 1 vì thuận tiện, dễ theo dõi):

Kiểu 1:
``` C
int x =10;
int *ptr = &x;
```
Kiểu 2:
``` C
int x=10;
int *ptr;
ptr =&x;
```
**Chú ý:** Trước khi truy cập hoặc sử dụng con trỏ, cần đảm bảo rằng nó đã được gán địa chỉ hợp lệ.

**Ví dụ:** 

Sai
int *ptr;
*ptr = 10; // Lỗi, vì ptr chưa được gán địa chỉ hợp lệ.

Đúng
int x = 10;
int *ptr = &x;  // ptr được gán địa chỉ của x

## Kích thước con trỏ

Kích thước của con trỏ sẽ phụ thuộc vào kiến trúc máy tính và trình biên dịch bởi cơ bản con trỏ là địa chỉ bộ nhớ mà kích thước của địa chỉ thì giống nhau trong cùng 1 kiến trúc máy tính nên cho dù có khai báo kiểu dữ liệu int, char, double,…. thì kích thước của con trỏ cũng như nhau.

* Compiler 64-bits thì con trỏ có kích thước 8 bytes.
* Compiler 32-bits thì con trỏ có kích thước 4 bytes.
* Compiler 8-bits thì con trỏ có kích thước 1 bytes.

## Ví dụ về pointer:
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
**Giải thích:**
* Ở hàm main(), khi khai báo biến a và b thì khi đó giả sử a có địa chỉ là 0x01 – có giá trị là 5, b có địa chỉ là 0xd0 – có giá trị là 10
* Đối với hàm swap_1, khi thực hiện biến a, b tuy cùng tên nhưng lại được cung cấp địa chỉ tạm thời giả sử là 0x02 và 0xf1 thì chỉ đổi giá trị ở 2 ô nhớ đó khi thực hiện xong hàm thì địa chỉ sẽ được thu hồi lại thế nên không ảnh hưởng đến 2 ô nhớ cần thay đổi.
* Đối với hàm swap_2, thao tác trực tiếp với giá trị trên ô nhớ đó nên có thể thay đổi được

## Các kiểu con trỏ
### Void pointer

**Khái niệm:**
* Void pointer là con trỏ không có kiểu cụ thể. Nó có thể trỏ tới bất kỳ loại dữ liệu nào.
* Tuy nhiên, trước khi truy xuất dữ liệu, phải ép kiểu về kiểu dữ liệu cụ thể.

**Ứng dụng:**
* Dùng trong các hàm có đối số kiểu dữ liệu không xác định.
* Quản lý bộ nhớ trong các chương trình sử dụng nhiều kiểu dữ liệu khác nhau.
* Dùng để trỏ đến bất kì địa chỉ nào mà không quan tâm kiểu dữ liệu của giá trị tại địa chỉ đó và có thể truy cập các kiểu dữ liệu khác bằng cách ép kiểu.

**Khai báo:** void *<tên_biến>;

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
**Tại sao phải ép kiểu?**

Void pointer không có một kiểu dữ liệu cụ thể. Khi một con trỏ trỏ đến kiểu dữ liệu cụ thể như int, float, double, hoặc char, trình biên dịch cần biết chính xác kiểu dữ liệu mà nó trỏ đến để biết cách truy xuất và thao tác với dữ liệu đó.

### Function pointer

**Khái niệm:**
Function pointer là con trỏ trỏ tới một hàm. Nó cho phép gọi hàm thông qua địa chỉ của hàm.


**Ứng dụng:**
* Dùng trong callback function và xử lý sự kiện.
* Dùng để truyền hàm như tham số cho các hàm khác.
* Sử dụng trong hệ thống menu hoặc các hàm xử lý động (ví dụ như hàm qsort() thì mình có thể truyền vào tham số là hàm compare()) .

**Khai báo:** <data_type> (*<tên_biến>) (<data_type_para1>, <data_type_para2>, …)
void (*ptr_func) (int, int)

**Ví dụ:**
``` C
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

    // Cách 2 : dùng trong array
    void (*cal[])(int,int)={sum, subtract, multiple, divide};

    cal[0](a,b);
    cal[4](a,b);

    // Cách 3: dùng hàm con
    cal1(sum, a, b);
    cal1(subtract, a, b);
}
```
**Chú ý:** 
* Địa chỉ của hàm có thể là <tên_hàm> hoặc &<tên_hàm>
* Có thể gọi hàm bằng cách ptr(a,b) hoặc (*ptr)(a,b)


### Pointer to constant (con trỏ hằng)
**Khái niệm:** Một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.

**Tác dụng:** 
Ngăn chặn việc sửa đổi dữ liệu hoặc thay đổi dữ liệu 1 cách vô tình. Khi sử dụng con trỏ hằng, không thể thay đổi giá trị của biến mà con trỏ trỏ tới. Điều này giúp tránh các lỗi vô tình thay đổi dữ liệu, đặc biệt khi làm việc với các biến quan trọng 
(ví dụ: Khi truyền mảng hoặc chuỗi vào hàm thông qua con trỏ, dùng con trỏ hằng để đảm bảo rằng hàm không thể sửa đổi nội dung dữ liệu.)


**Khai báo:** <data_type> const *<tên_biến>; hoặc const <data_type> *<tên biến>;

            int const *ptr_const;  hoặc const int *ptr_const;

**Ví dụ:**
``` C
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
**Chú ý:** 
* Tại địa chỉ mà nó trỏ đến chỉ có thể đọc giá trị mà không thể thay đổi giá trị thông qua pointer
* Có thể trỏ đến địa chỉ khác (khác so với Constant Pointer – hằng con trỏ)

### Constant Pointer
**Định nghĩa:** Là 1 con trỏ mà khi đã được khởi tạo thì không thể thay đổi địa chỉ khác (trỏ đến 1 địa chỉ duy nhất) và không thể thay đổi giá trị thông qua con trỏ
**Khai báo:** <data_type> *const <tên_biến> (int *const const_ptr)

Ví dụ: 
``` C
#include <stdio.h>

int main(){
    int a = 5;
    int b = 6;
    int *const const_ptr = &a;

    printf("Gia tri cua a: %d\n",*const_ptr);   // Output: Gia tri cua a: 5
    *const_ptr = 4;                             // Sai: Không thể thay đổi qua pointer
    printf("Gia tri cua a: %d\n",*const_ptr);   // Output: Gia tri cua a: 5

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
