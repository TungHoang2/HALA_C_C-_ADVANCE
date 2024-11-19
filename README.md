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
**Định nghĩa:** Là 1 con trỏ mà khi đã được khởi tạo thì không thể thay đổi địa chỉ khác (trỏ đến 1 địa chỉ duy nhất) 

**Khai báo:** <data_type> *const <tên_biến> (int *const const_ptr)

**Tác dụng:**
* Bảo vệ địa chỉ cố định: Giúp đảm bảo rằng con trỏ luôn trỏ đến một biến nhất định trong suốt thời gian thực thi chương trình.
* Tránh lỗi vô tình thay đổi địa chỉ trong các chương trình phức tạp.
* Dùng trong lập trình hệ thống hoặc nhúng: Khi con trỏ cần trỏ đến một vùng bộ nhớ cố định, ví dụ: dùng con trỏ để làm việc với vùng nhớ GPIOA hoặc GPIOB, nhưng vẫn cần được phép sửa đổi dữ liệu tại đó.
* Tăng độ an toàn và dễ bảo trì: Các biến được truy cập bởi const pointer sẽ không bị trỏ nhầm tới địa chỉ khác, giúp dễ phát hiện và sửa lỗi.
  
**Ví dụ:**
``` C
#include <stdio.h>

int main(){
    int a = 5;
    int b = 6;
    int *const const_ptr = &a;

    printf("Gia tri cua a: %d\n",*const_ptr);   // Output: Gia tri cua a: 5
    *const_ptr = 4;                             // Có thể thay đổi qua pointer
    printf("Gia tri cua a: %d\n",*const_ptr);   // Output: Gia tri cua a: 5

    //const_ptr = &b;                           // Sai: không thể trỏ đến địa chỉ khác

}
```
### NULL Pointer
**Định nghĩa:** Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào và có địa chỉ mặc định là 0x00
Khi sử dụng xong phải gán là giá trị NULL tránh con trỏ sẽ trỏ vào các vị trí không mong muốn

**Khi nào sử dụng con trỏ NULL?**

* Khi khởi tạo con trỏ mà không gán giá trị thì nó sẽ trỏ đến 1 địa chỉ ngẫu nhiên (địa chỉ rác) và khi sử dụng vi xử lý có trường hợp sẽ trỏ đến vị trí mình đang sử dụng, thay đổi giá trị và gây ra lỗi.
* Đối với lập trình vi xử lý, khi khai báo con trỏ mà chưa sử dụng thì phải gán giá trị NULL để tránh bị lỗi.

### Pointer to pointer

**Định nghĩa:** Con trỏ trỏ đến con trỏ (Pointers to pointers) là một con trỏ chứa địa chỉ của một con trỏ khác

**Tác dụng:**
* Khi muốn thay đổi địa chỉ mà con trỏ đang trỏ tới. (**Giải thích:** Vì khi truyền một con trỏ vào hàm, hàm đó chỉ nhận được một bản sao của địa chỉ mà con trỏ đang trỏ tới. Nếu muốn hàm thay đổi địa chỉ mà con trỏ đang trỏ tới, cần truyền một pointer to pointer.)
* Sử dụng trong các hàm cấp phát bộ nhớ động hoặc truyền con trỏ qua hàm.
* Quản lý mảng con trỏ (**Ví dụ:** Quản lý mảng các chuỗi.)

**Ví dụ:**
``` C
#include <stdio.h>

int main(){
    int a =5;
    int *ptr = &a;  //  &ptp = 0x01 _ &ptr = 0xc1 _ a = 10
    int **ptp = &ptr;

    printf("%d",*(*ptp));
}
```
**Giải thích:** ptp có địa chỉ là 0x01, ptr có địa chỉ là 0xc1, giá trị bên trong địa chỉ 0xc1 = 10. *ptp sẽ là địa chỉ của ptr  vậy nên **ptp = *&ptr = 10

# Extern - Static - Register - Volatile

## Extern
**Khái niệm:**
Được sử dụng để khai báo một biến hoặc hàm được định nghĩa ở nơi khác (thường là ở một file khác) nhằm chia sẻ biến/hàm đó giữa nhiều file trong một chương trình lớn.. Giúp chương trình hiểu được biến hoặc hàm đã được định nghĩa và sẽ được sử dụng từ 1 vị trí khác, quản lý sự liên kết giữa các phần khác nhau của chương trình hoặc giữa các file nguồn.


**Ứng dụng:**

* Chia sẻ biến toàn cục giữa nhiều file: Trong các chương trình lớn, thường có nhiều file mã nguồn. Dùng extern để tránh khai báo nhiều lần cho cùng một biến toàn cục.
* Cải thiện quản lý mã nguồn: Các biến toàn cục chỉ cần được định nghĩa một lần và có thể truy cập từ nhiều file khác nhau mà không phải khởi tạo lại.
* Sử dụng trong thư viện hoặc các dự án lớn: extern giúp các dự án lớn tách riêng logic thành nhiều file và dễ dàng quản lý hơn.


**Lưu ý:**
* Chỉ sử dụng extern cho biến đã được định nghĩa: Nếu biến không được định nghĩa ở bất kỳ file nào, sẽ gặp lỗi trong quá trình liên kết (linker error).
* Chỉ sử dụng khi biến ở toàn cục (vì nếu khai báo cục bộ thì nó chỉ có phạm vi trong 1 hàm nên không có ý nghĩa)
* Vì có phạm vi toàn cục nên lưu ý tránh xung đột tên biến với các file khác.
* Chỉ được khai báo không được khởi tạo giá trị.
* Phải sử dụng liên kết file và dùng để thiết kế thư viện.

**Câu hỏi:**

**Khi nào dùng extern cho biến?**
Khi bạn muốn sử dụng một biến toàn cục (global) đã được định nghĩa ở một file khác mà không cần phải khai báo và khởi tạo lại.

**Tại sao không sử dụng include mà xài extern?**
Không sử dụng include bởi vì chỉ cần xài 1 số biến, hàm trong file đó chứ không cần tất cả nên xài include sẽ tốn bộ nhớ, xử lý lâu hơn, tác vụ chậm hơn.


## Static 
### Static local variable

**Ví dụ:**
``` C
#include <stdio.h>

void count(){
    static int a =10;  // giữ giá trị qua các lần gọi hàm
    a++;
    printf("a = %d\n", a);
}
int main(){
    count(); // a = 11
    count(); // a = 12
    count(); // a =13
}
```
**Giải thích:**
* Static cục bộ sẽ nằm ở phân vùng ds hoặc bss chứ không phải trong stack nên là biến sẽ tồn tại đến khi kết thúc chương trình thực thi chứ không phải kết thúc khối lệnh mà nó được khai báo.
* Nếu muốn thay đổi giá trị thì dùng con trỏ (trỏ đến địa chỉ của biến đó và thay đổi) hoặc thay đổi trực tiếp trong hàm.

**Ứng dụng:**
* Lưu trữ trạng thái giữa các lần gọi hàm: Sử dụng biến static để theo dõi trạng thái trạng thái giữa các lần gọi hàm mà không cần sử dụng biến toàn cục.
* Cải thiện hiệu suất: Biến static cục bộ không bị khởi tạo lại mỗi khi hàm được gọi, điều này giúp cải thiện hiệu suất trong một số trường hợp.

### Static global variable:
Khi sử dụng với global variables (biến toàn cục – khai báo ngoài hàm), nó sẽ hạn chế phạm vi của biến đó chỉ trong file nguồn hiện tại không cho cái file khác truy cập vào. Điều này giúp tránh xung đột tên biến giữa các file và tăng tính bảo mật.

## Register

* Chỉ sử dụng cho biến cục bộ, không sử dụng cho biến toàn cục 
* Bình thường sẽ chạy tuần tự 4 bước từ khai báo ở RAM sau đó đẩy sang lưu vào Register và đẩy sang ALU để tính toán số học và cuối cùng là trả về  Register sau đó về RAM
* Khi khai báo register thì sẽ rút ngắn quá trình chạy chỉ còn 2 bước giúp chương trình chạy nhanh hơn, tăng tốc độ truy cập

**Câu hỏi:**

**Biến được khai báo register khai báo toàn cục hay cục bộ?**
Biến register chỉ khai báo được cục bộ thôi và khai báo toàn cục sẽ bị lỗi (với 1 vài compiler) vì mục đích của register là tối ưu hóa các biến có tuổi thọ ngắn để tăng hiệu suất tính toán số học trong các hàm con, bên cạnh đó thì lượng thanh ghi trong CPU là hữu hạn và sử dụng ở toàn cục thì có thể bị ghi đè dữ liệu dẫn đến tính toán sai.

**Khi nào nên sử dụng register?**
* Biến được sử dụng rất thường xuyên: Đặc biệt là trong các vòng lặp, phép tính số học.
* Biến có kích thước nhỏ: Các biến kiểu nguyên (int, short) thường phù hợp hơn.
* Trình biên dịch hỗ trợ: Không phải tất cả các trình biên dịch đều hỗ trợ từ khóa register hoặc có thể bỏ qua gợi ý của bạn.


## Volatile
Từ khóa volatile được sử dụng để báo hiệu cho trình biên dịch rằng một biến có thể thay đổi ngẫu nhiên, ngoài sự kiểm soát của chương trình (nút nhấn,…). Việc này ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.

# Bitmask

Bitmask là một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái. Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ thể trong một từ (word).

**Ứng dụng:**
Bitmask thường được sử dụng để tối ưu bộ nhớ, thực hiện các phép toán logic trên 1 cụm bit, và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác nhau của 1 đối tượng

## Các thao tác thường dùng:

### AND (&) – Kiểm tra trạng thái bit

**Mô tả:** So sánh từng bit của hai số, nếu cả hai bit đều là 1 thì kết quả là 1, ngược lại là 0.

**Ứng dụng:** Thường dùng để kiểm tra xem một bit cụ thể có được bật hay không.

**Ví dụ:**
``` C
int checkBit(int num, int pos) {
    return (num & (1 << pos)) != 0;
}
```
**Ví dụ:** Kiểm tra bit thứ 1 của số 5 (00000101):
``` C
00000101 & 00000010 = 00000000 (Kết quả: 0)
```

### OR (|) – Bật (Set) bit

**Mô tả:** So sánh từng bit, nếu ít nhất một trong hai bit là 1 thì kết quả là 1, ngược lại là 0.

**Ứng dụng:** Thường dùng để bật (set) một bit cụ thể.

**Ví dụ:**
``` C
int setBit(int num, int pos) {
    return num | (1 << pos);
}
```

**Ví dụ:** Bật bit thứ 1 của số 5 (00000101):
``` C
00000101 | 00000010 = 00000111 (Kết quả: 7)
```

### AND và NOT - Tắt (Clear) bit

**Mô tả:** Để tắt một bit, dùng AND với NOT của bit cần tắt.

**Ứng dụng:** Xóa bỏ trạng thái của một bit cụ thể.

**Ví dụ:**
``` C
void disableFeature(uint8_t *features, uint8_t feature) {
    *features &= ~feature;
}
```

### XOR (^) – Đảo (Toggle) bit

**Mô tả:** So sánh từng bit, nếu hai bit khác nhau thì kết quả là 1, nếu giống nhau thì là 0.

**Ứng dụng:** Thường dùng để đảo ngược giá trị của một bit (1 thành 0 hoặc 0 thành 1).

**Ví dụ:**
``` C
int toggleBit(int num, int pos) {
    return num ^ (1 << pos);
}
```

**Ví dụ:** Đảo bit thứ 2 của số 5 (00000101)
``` C
00000101 ^ 00000100 = 00000001 (Kết quả: 1)
```

### NOT (~) – Đảo ngược tất cả bit

**Mô tả:** Chuyển tất cả bit 0 thành 1 và ngược lại.

**Ứng dụng:** Thường dùng để đảo ngược trạng thái của một số nhị phân hoàn toàn.

**Ví dụ:**
``` C
#include <stdio.h>

int main() {
    int num = 5;  // 00000101
    printf("NOT ~%d = %d\n", num, ~num);  // Đảo bit
    return 0;
}
```

### Dịch trái (<<) – Nhân với 2

**Mô tả:** Dịch các bit sang trái, các bit trống bên phải được lấp bằng 0.

**Ứng dụng:** Dùng để nhân số với 2 mũ n lần dịch.

**Ví dụ:** Dịch trái số 3 (00000011) 1 lần

``` C
00000011 << 1 = 00000110 (Kết quả: 6)
```

### Dịch phải (>>) – Chia cho 2

**Mô tả:** Dịch các bit sang phải, các bit trống bên trái có thể được lấp bằng 0 hoặc 1 tùy vào kiểu số.

**Ứng dụng:** Dùng để chia số cho 2 mũ n lần dịch.

**Ví dụ:** Dịch phải số 6 (00000110) 1 lần

``` C
00000110 >> 1 = 00000011 (Kết quả: 3)
```

**Ví dụ tổng hợp:**
``` C
#include <stdio.h>

#define READ    (1 << 0)  // 0001
#define WRITE   (1 << 1)  // 0010
#define EXECUTE (1 << 2)  // 0100

void updatePermissions(int *permissions, int action, int add) {
    if (add) {
        *permissions |= action;  // Bật quyền
    } else {
        *permissions &= ~action;  // Tắt quyền
    }
}

int main() {
    int permissions = READ;  // Khởi tạo với quyền đọc (0001)
    
    updatePermissions(&permissions, WRITE, 1);  // Thêm quyền ghi
    printf("Permissions: %d\n", permissions);  // Kết quả: 3 (0011)
    
    updatePermissions(&permissions, READ, 0);  // Xóa quyền đọc
    printf("Permissions: %d\n", permissions);  // Kết quả: 2 (0010)

    return 0;
}
```

### Bit Field

**Khai báo:**

``` C
struct {
    <type> member_name : width;
} <struct_name>;
```

* type: Kiểu dữ liệu của trường bit (thường là uint8_t, int, unsigned int).
* member_name: Tên của trường bit. 
* width: Số bit mà trường bit chiếm.

**Ví dụ:**
``` C
typedef struct {
    uint8_t LED1: 1;   
    uint8_t LED2: 1;
    uint8_t LED3: 1;
    uint8_t LED4: 1;
    uint8_t LED5: 1;
    uint8_t LED6: 1;
    uint8_t LED7: 1;
    uint8_t LED8: 1;
} LEDStatus;
```
**Giải thích:** Struct LEDStatus có kích thước 1 byte khi sử dụng bit field. Nếu không sử dụng là 8 bytes


**Ví dụ:**

``` C
struct flags {
    unsigned int is_active : 1;
    unsigned int is_completed : 1;
    unsigned int error_code : 3;
};
```
**Ưu điểm:**

* Tiết kiệm bộ nhớ.
* Tăng tốc độ: Trong một số trường hợp, truy cập trực tiếp vào các bit có thể nhanh hơn so với truy cập vào các byte.
* Dễ đọc: bit field có thể làm cho mã dễ đọc hơn, đặc biệt là khi đang làm việc với các cấu trúc dữ liệu nhị phân.

# Struct - Union
## Struct

**Khái niệm:**
* Struct là một kiểu dữ liệu do người dùng định nghĩa, cho phép gộp nhiều kiểu dữ liệu khác nhau thành 1 nhóm. Mỗi phần tử trong struct được gọi là member.
* Kích thước của struct bao gồm kích thước của các member cộng với padding.

**Cú pháp:**
``` C
struct <Struct_name> {
       dataType member1
       dataType member2
       …..
};
```

**Ví dụ 1:**
``` C
#include <stdio.h>

// Định nghĩa một struct có tên là Person
struct Person {
    char name[50];
    int age;
    float height;
};

int main() {
    // Tạo biến kiểu struct Person
    struct Person person1;
    struct Person person2 = {"Alice", 25, 5.5};

    // Gán giá trị cho các thành viên của struct
    strcpy(person1.name, "John");
    person1.age = 30;
    person1.height = 5.9;

    // In ra các giá trị của thành viên struct
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Height: %.1f\n", person1.height);

    return 0;
}
```

**Ví dụ 2:**

``` C
struct A {
    char c;
    int i;
};
printf("%d\n", sizeof(struct A));  // Kích thước lớn hơn 5 do padding
```

**Lưu ý:**
* Truy cập thành viên: Để truy cập thành viên của 1 struct, sử dụng dấu chấm (.) cho biến thông thường và dấu mũi tên (->) khi truy cập qua con trỏ
* Khởi tạo struct: Có thể khởi tạo trực tiếp các thành viên của struct khi khai báo biến.
* Nếu không khởi tạo giá trị, thì member có thể có giá trị không xác định (garbage value)
* Các địa chỉ của các member có thể không liền kề nhau do memory alignment, trình biên dịch sẽ thêm padding giữa các member

**Ví dụ 3:**
``` C
typedef struct {
    int x, y;
} Point;

Point p;  // Không cần viết 'struct Point'
```

Sử dụng typedef với struct: Việc sử dụng từ khóa typedef giúp bạn tránh phải viết từ khóa struct mỗi lần sử dụng.

## Union

**Khái niệm:**
Union cho phép lưu trữ nhiều thành viên (members) có các kiểu dữ liệu khác nhau tại cùng một vị trí trong bộ nhớ. Tuy nhiên, tại một thời điểm chỉ có một thành viên của union có thể chứa giá trị.

**Cú pháp:**
``` C
union UnionName {
    dataType1 member1;
    dataType2 member2;
    …..
    // các thành viên khác
};
```

**Ví dụ:**
``` C
union Data {
    int i;      // 4 byte
    float f;    // 4 byte
    char str[20];  // 20 byte
};
printf("%zu\n", sizeof(union Data));  // Kết quả là 20
```

**Khác nhau giữa struct và union:**
* Trong struct, mỗi thành viên có một vùng bộ nhớ riêng.
* Trong union, tất cả các thành viên chia sẻ chung một vùng bộ nhớ, nên kích thước của một union là kích thước của thành viên có kích thước lớn nhất.

**Lưu ý:** 

Chia sẻ bộ nhớ:
* Các thành viên trong union đều chia sẻ chung một vùng bộ nhớ. Do đó, chỉ có một thành viên có thể lưu trữ giá trị hợp lệ tại bất kỳ thời điểm nào.
* Khi một thành viên mới được gán giá trị, dữ liệu của thành viên trước đó sẽ bị mất (bị ghi đè lên qua từng lần gán giá trị)

Kích thước của union:
* Kích thước của union bằng với kích thước của thành viên lớn nhất trong union.

**Ví dụ:** 
``` C
typedef union {
    int i;
    float f;
    char str[20];
} Data;

Data data;
```
**Sử dụng với typedef:**
Có thể sử dụng từ khóa typedef để tránh phải viết từ khóa union mỗi lần sử dụng, tương tự như với struct.

**Ví dụ về struct và union:**

``` C
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union 
{
    struct 
    {
        uint8_t id[2];
        uint8_t data[4];
        uint8_t check_sum[2];
    } data;
    uint8_t frame[8];
}data_frame;

int main() {
    data_frame transmit_data, receive_data;
    strcpy((char*)transmit_data.data.id,"10");
    strcpy((char*)transmit_data.data.id,"1234");
    strcpy((char*)transmit_data.data.id,"21");
    strcpy((char*)receive_data.frame,(char*)transmit_data.frame);
    return 0;
}
```

**Giải thích:**
* Sử dụng uint8_t cho struct để không bị padding 
* Sử dụng union cho frame để có địa chỉ chứa receive_data và transmit_data
* (char*) để đổi kiểu dữ liệu và con trỏ để trỏ vào địa chỉ cụ thể


# Memory Layout
## Text-segment
<ul>
  <li>Biến constant global và chuỗi mà con trỏ kiểu char trỏ đến</li>
  <li>Read-only</li>
  <li>Chứa mã máy để thực thi chương trình</li>
</ul>

## Initialized data – DS(Data-segment)
<ul>
  <li>Chứa các biến toàn cục được khởi tạo giá trị khác 0</li>
  <li>Chứa các biến static (global + local) được khởi tạo với giá trị khác 0</li>
  <li>Ngoại trừ biến hằng số và con trỏ kiểu char (trường hợp đặc biệt nằm ở text-segment)</li>
  <li>Có thể đọc và thay đổi giá trị của biến (read – write)</li>
  <li>Biến được thu hồi sau khi kết thúc chương trình</li>
</ul>

## Uninitialized data – bss
<ul>
  <li>Chứa các biến toàn cục và cục bộ chưa được khởi tạo hoặc khởi tạo với giá trị 0 </li>
  <li>Có thể đọc và ghi (read-write)</li>
  <li>Tất cả biến sẽ được thu hồi sau khi kết thúc chương trình</li>
</ul>


## Stack 
<ul>
  <li>Chức các biến cục bộ, tham số truyền vào (ngoại trừ biến static cục bộ được lưu vào ds hoặc bss)</li>
  <li>Biến const cục bộ sẽ được lưu vào phân vùng stack</li>
  <li>Read-write</li>
  <li>Sau khi kết thúc hàm sẽ thu hồi vùng nhớ</li>
  <li>Hoạt động theo cơ chế LIFO (Last In First Out)</li>
</ul>

## Heap 
<ul>
  <li>Được sử dụng để cấp phát bộ nhớ động. Các biến được cấp phát không có kích thước nhất định và có thể thay đổi trong quá trình thực thi chương trình </li>
  <li>Sử dụng các hàm malloc(), calloc(), realloc(), free()</li>
</ul>

## Phân biệt malloc(), calloc(), realloc()
### malloc():
<ul>
  <li>Được sử dụng để phân bố động 1 khối bộ nhớ có kích thước được chỉ định</li>
  <li>Kiểu trả về là void * và có thể ép kiểu về con trỏ bất kì </li>
  <li>Giá trị ban đầu của từng ô nhớ mặc định là garbage value</li>
  <li>Nếu không đủ không gian, việc phân bổ sẽ không thành công và trả về con trỏ NULL.</li>
  <li>Khi sử dụng phải khai báo thư viện stdlib.h</li>
</ul>

**Cú pháp:**
``` C
ptr = (cast-type*) malloc(byte-size)
```

**Ví dụ:**
``` C
ptr = (int*) malloc(100 * sizeof(int))
```

Vì kích thước của int là 4 byte, câu lệnh này sẽ phân bổ 400 byte bộ nhớ. Và con trỏ ptr giữ địa chỉ của byte đầu tiên trong bộ nhớ được phân bổ. 

### calloc():
<ul>
  <li>Được sử dụng để phân bổ động số lượng khối bộ nhớ được chỉ định của loại được chỉ định (data-type)</li>
  <li>Nếu không đủ không gian, việc phân bổ sẽ không thành công và trả về con trỏ NULL.</li>
  <li>Khi sử dụng phải khai báo thư viện stdlib.h</li>
  <li>Kiểu trả về là void * và có thể ép kiểu về con trỏ bất kì </li>
</ul>

**Cú pháp:**
``` C
ptr = (cast-type*)calloc(n, element-size);
```

n là số lượng phần tử và element-size là kích thước của mỗi phần tử.

**Ví dụ:**
``` C
ptr = (float*) calloc(25, sizeof(float));
```

Câu lệnh này phân bổ không gian liền kề trong bộ nhớ cho 25 phần tử, mỗi phần tử có kích thước bằng float.

### 2 điểm khác biệt so với malloc():
* Khởi tạo mỗi khối với giá trị mặc định là 0
* Có 2 tham số hoặc đối số khi so sánh với malloc()

## free():
Khi sử dụng xong các vùng nhớ sẽ không tự động thu hồi mà phải dùng free() để thu hồi bộ nhớ

## realloc():
<ul>
  <li>Được sử dụng để phân bổ lại bộ nhớ đã được phân bổ trước đó. Nếu bộ nhớ được phân bổ trước đó của malloc hoặc calloc không đủ, thì sẽ sử dụng recalloc() để phân bổ lại bộ nhớ động </li>
  <li>Việc phân bổ lại sẽ duy trì giá trị của các bộ nhớ cũ và gán giá trị rác cho các vùng nhớ mới.</li>
    <li>Có thể sử dụng realloc thay free() để thu hồi vùng nhớ.</li>
</ul>

**Cú pháp:**
``` C
ptr = realloc(ptr, newSize); 
```

trong đó ptr được phân bổ lại với kích thước mới 'newSize'.


## Phân biệt giữa stack và heap:
### Stack: 
<ul>
  <li>Truy cập nhanh: Do cấu trúc đơn giản nên việc truy cập dữ liệu rất nhanh</li>
  <li>Quản lý tự động: Hệ điều hành tự động cấp phát và giải phóng bộ nhớ trên stack khi hàm được gọi và kết thúc</li>
  <li>Kích thước hạn chế: Stack có kích thước cố định, nếu gọi quá nhiều hàm đệ quy hoặc khai báo quá nhiều biến cục bộ có thể dẫn đến tràn stack (stack overflow)</li>
  <li>Lưu các biến cục bộ, tham số, địa chỉ trả về</li>
</ul>


### Heap:
<ul>
  <li>Truy cập chậm hơn, dễ bị rò rỉ bộ nhớ </li>
  <li>Quản lý thủ công: Được quản lý bởi lập trình viên, dữ liệu trong Heap sẽ không bị hủy khi kết thúc chương trình, vậy nên phải tự giải phóng bộ nhớ bằng hàm free().</li>
  <li>Kich thước lớn: Heap thường có kích thước lớn hơn Stack, cho phép cấp phát vùng nhớ lớn hơn</li>
  <li>Linh hoạt: Có thể cấp phát hoặc thu hồi vùng nhớ theo yêu cầu của chương trình</li>
  <li>Lưu các đối tượng động, mảng lớn, cấu trúc dữ liệu phức tạp.</li>
</ul>

# C++
## Class

**Khái niệm:** Trong C++, class (lớp) là một cấu trúc dữ liệu giúp tạo ra các đối tượng (objects) với các thuộc tính (properties) và phương thức (methods).

**Lưu ý:** 
* Các properties mặc định sẽ là private. Nếu muốn truy cập từ bên ngoài thì phải khai báo public.
* Constructor là một method sẽ được tự động gọi khi khởi tạo object. Constructor sẽ có tên trùng với tên của class.
* Destructor là một method sẽ được tự động gọi khi object được giải phóng. Destructor sẽ có tên trùng với tên của class và thêm ký tự ~ ở phía trước tên.

**Ví dụ:**

``` C++
#include <iostream>

using namespace std;

class BankAccount{
    private:
    int AccountNumber;
    string AccountHolder;
    int balance;

    public:
    BankAccount(int AccNum, string AccHol, int initalBalance =0) 
        : AccountNumber(AccNum), AccountHolder(AccHol), balance(initalBalance) {}

    void deposit(int num){
        if(num >= 0){
            balance += num;
            cout << "Gui thanh cong: " << num << "VND" << endl;
        }else{
            cout << "So tien khong hop le" << endl;
        }
    }

    void withdraw(int num){
        if(num < 0 || num > balance){
            cout << "So tien khong hop le hoac vuot qua so du" << endl; 
        }else{
            balance -= num;
            cout << "Rut thanh cong: " << num << "VND" << endl;
        }
    }

    void displayBalance(){
        cout << "So tien con lai trong tai khoan: " << balance << "VND" << endl;
    }
};

int main(){
    BankAccount myAccount(123,"Tung", 50000);

    myAccount.deposit(100000);
    myAccount.displayBalance();

    myAccount.withdraw(2000000);
    myAccount.displayBalance();
}
```

## OOP
### Encapsulation

**Khái niệm:** tính đóng gói đề cập đến việc ẩn các properties bên trong của một đối tượng và chỉ cung cấp những methods cần thiết để tương tác với đối tượng đó. 

**Mục tiêu:** bảo vệ dữ liệu và tránh việc truy cập hoặc sửa đổi trực tiếp các thuộc tính (properties) của đối tượng từ bên ngoài lớp.

**Đóng gói thực hiện qua hai phần chính:**
* Ẩn dữ liệu (Data Hiding): Các thuộc tính của lớp thường được khai báo là private hoặc protected để không cho phép truy cập trực tiếp từ bên ngoài.
* Cung cấp giao diện (Interface): Các phương thức public được cung cấp để cho phép người dùng tương tác với đối tượng mà không cần biết chi tiết nội bộ của nó.

**Ứng dụng:**
* Bảo vệ dữ liệu: Bằng cách ẩn các thuộc tính khỏi truy cập trực tiếp từ bên ngoài, có thể bảo vệ dữ liệu khỏi những thay đổi không mong muốn hoặc lỗi lập trình.
* Giúp kiểm tra các điều kiện khi khởi tạo bằng các methods mà khởi tạo trực tiếp ở main không làm được.

``` C++
#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand; // Thương hiệu xe (private)
    int speed;   // Tốc độ xe (private)
    
public:
    // Constructor
    Car(string m, int s) : brand(m), speed(s) {}

    // Phương thức getter để lấy thông tin về thương hiệu
    string getBrand() const {
        return brand;
    }

    // Phương thức setter để thay đổi tốc độ
    void setSpeed(int s) {
        if(s >= 0 && s <= 300) { // Kiểm tra tốc độ hợp lệ
            speed = s;
        } else {
            cout << "Tốc độ không hợp lệ!" << endl;
        }
    }

    // Phương thức getter để lấy tốc độ
    int getSpeed() const {
        return speed;
    }

    // Phương thức tăng tốc
    void accelerate(int increment) {
        if (speed + increment <= 300) {
            speed += increment;
        } else {
            speed = 300; // Tốc độ tối đa là 300 km/h
        }
    }

    // Phương thức giảm tốc
    void brake(int decrement) {
        if (speed - decrement >= 0) {
            speed -= decrement;
        } else {
            speed = 0; // Tốc độ không thể nhỏ hơn 0
        }
    }
};

int main() {
    // Tạo đối tượng Car với thương hiệu "Toyota" và tốc độ ban đầu là 50 km/h
    Car myCar("Toyota", 50);

    // Lấy thông tin về thương hiệu và tốc độ xe
    cout << "Thương hiệu xe: " << myCar.getBrand() << endl;
    cout << "Tốc độ ban đầu: " << myCar.getSpeed() << " km/h" << endl;

    // Tăng tốc xe
    myCar.accelerate(20);
    cout << "Tốc độ sau khi tăng tốc: " << myCar.getSpeed() << " km/h" << endl;

    // Giảm tốc xe
    myCar.brake(30);
    cout << "Tốc độ sau khi giảm tốc: " << myCar.getSpeed() << " km/h" << endl;

    // Cố gắng set tốc độ vượt quá giới hạn
    myCar.setSpeed(350); // Tốc độ không hợp lệ

    return 0;
}
```

### Inheritance
**Khái niệm:** Tính kế thừa ( Inheritance) là khả năng sử dụng lại các property và method của một class trong một class khác

**Ứng dụng:** Tính kế thừa giúp tái sử dụng mã nguồn, giảm sự trùng lặp và tạo ra cấu trúc lớp có thể mở rộng, dễ dàng bảo trì.


**Có 3 kiểu kế thừa:** public, private và protected. Những property và method được kế thừa từ class cha sẽ có quyền truy cập của class con tương ứng với kiểu kế thừa.
1. Public: method, property bên trong và object bên ngoài đều truy cập được
2. Protected:
* Thuộc tính protected không thể bị truy cập trực tiếp từ bên ngoài, giúp đảm bảo dữ liệu nội bộ của đối tượng không bị thay đổi ngoài ý muốn (giống private)
* Các class con có thể kế thừa được
3. Private:
* Object, class kế thừa không thể truy cập được
* Nội bộ class


**Lưu ý:**
* Chỉ kế thừa được property và method ở phạm vi public hoặc protected
* Kế thừa public: Nếu kế thừa public thì sẽ copy giữ nguyên phạm vi của property hoặc method 
* Kế thừa protected: Chuyển toàn bộ phạm vi về protected (Những property hay method nằm ở phạm vi private không thể kế thừa)
* Kế thừa private: Chuyển tất cả về private

**Ví dụ:**

``` C++
class Animal {
public:
    void eat() {
        cout << "Eating food" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking" << endl;
    }
};

int main() {
    Dog dog;
    dog.eat(); // Kế thừa từ Animal
    dog.bark(); // Đặc trưng của Dog
}
```
**Ví dụ:** Kế thừa và ghi đè chức năng của lớp cha

``` C++
class Animal {
public:
    void sound() {
        cout << "Some generic animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() { 
        cout << "Barking" << endl; // Ghi đè phương thức sound()
    }
};

int main() {
    Dog dog;
    dog.sound(); // Output: "Barking"
}
```

### Abstraction
**Khái niệm:** Tính trừu tượng trong OOP là việc che giấu chi tiết triển khai và chỉ cung cấp giao diện cần thiết cho người dùng. Tính trừu tượng đề cập đến việc ẩn đi các chi tiết cụ thể của một đối tượng và chỉ hiển thị những gì cần thiết để sử dụng đối tượng đó.

**Công dụng:** Tính trừu tượng giúp giảm phức tạp, tăng khả năng mở rộng, và dễ bảo trì.

**Ví dụ:** Lớp trừu tượng Animal với phương thức thuần ảo sound() buộc các lớp con như Dog hoặc Cat phải triển khai chi tiết cách phát âm thanh.

``` C++
#include <iostream>

using namespace std;

class Animal {
public:
    virtual void sound() =0 ;
};

class Dog : public Animal {
public:
    void sound() override { 
        cout << "Gau Gau" << endl; // Ghi đè phương thức sound()
    }
};

class Cat: public Animal {
    public:
    void sound() override{
        cout << "Meo meo" << endl; // Ghi đè phương thức sound()
    } 
};

int main() {
    Dog dog;
    dog.sound(); 

    Cat cat;
    cat.sound();
}
```

### Polymorphism

**Khái niệm:** Tính đa hình trong C++ là khả năng sử dụng cùng một giao diện nhưng hành vi khác nhau tùy vào đối tượng thực tế.

**Có 2 loại đa hình:**
1. Compile-time:
* Function Overloading : Khi có nhiều hàm có cùng tên nhưng tham số khác nhau

**Ví dụ:**
``` C++
#include <iostream>

using namespace std;

class calculate_Sum
{
public:
    void sum(int a, int b)
    {
        cout << "Tong = " << a + b << endl;
    }

    void sum(int a, int b, double c)
    {
        cout << "Tong = " << a + b + c << endl;
    }

    void sum(double a, double b)
    {
        cout << "Tong = " << a + b << endl;
    }
};

int main()
{
    calculate_Sum s1;
    s1.sum(1, 2);
    s1.sum(4, 5, 5.6);
    s1.sum(4.5, 1, 5);
}
```
* Operator Overloading: Cung cấp cho các toán tử một ý nghĩa đặc biệt cho một kiểu dữ liệu (Ví dụ như có kiểu phân số nhưng C++ không có sẵn các phép toán +,-,x,: thì khi đó sử dụng operator overloading)
``` C++
#include <iostream>

using namespace std;

class PhanSo
{
    private: 
    double tuSo;
    double mauSo;
    
    public:
    PhanSo(double t = 0, double m = 1) : tuSo(t), mauSo(m){}

    PhanSo operator + (PhanSo &other){
        PhanSo ketqua;
        ketqua.tuSo = this->tuSo * other.mauSo + this->mauSo * other.tuSo;
        ketqua.mauSo = this->mauSo * other.mauSo; 
        return ketqua;
    }

    void display(){
        cout << "Tu so: " << this->tuSo << endl;
        cout << "Mau so: " << this->mauSo << endl;
    }
};

int main()
{
    PhanSo p1(1,10);
    PhanSo p2(6,5);

    PhanSo result;
    result = p1 + p2;
    result.display();
}
```
2. Run -time:
* Virtual Functions

**Ví dụ:** hàm makeSound() gọi phương thức sound() của cả Dog và Cat, nhưng Dog kêu "Gâu gâu", còn Cat kêu "Meo meo". Nhờ virtual functions, chương trình tự chọn đúng hành vi tại runtime. Tính đa hình giúp code linh hoạt và dễ mở rộng.

``` C++
#include <iostream>

using namespace std;

class Animal {
public:
    virtual void sound() =0 ;
};

class Dog : public Animal {
public:
    void sound() override { 
        cout << "Gau Gau" << endl; // Ghi đè phương thức sound()
    }
};

class Cat: public Animal {
    public:
    void sound() override{
        cout << "Meo meo" << endl; // Ghi đè phương thức sound()
    } 
};

int main() {
    Dog dog;
    dog.sound(); 

    Cat cat;
    cat.sound();
}
```

**Lưu ý:**

* 1 class có ít nhất 1 pure virtual function gọi là 1 class trừu tượng sẽ không thể khai báo 1 object bình thường vì method chưa có tính năng gì. Nhưng gọi thông qua con trỏ thì bình thường vì bản chất là trỏ đến 1 object khác và method bên trong có nội dung đầy đủ
* Từ khóa override để phân biệt giữa đa hình và kế thừa (khi có override thì biết đó là đa hình) và nhìn vào là biết đang ghi đè 1 hàm ảo
* Method bình thường --> ghi đè --> tính kế thừa
* Method ảo (virtual) --> ghi đè --> tính đa hình (run-time)


## Template
### Function Template
**Khái niệm:** Cho phép định nghĩa một hàm tổng quát, có thể hoạt động với nhiều kiểu dữ liệu khác nhau.

**Công dụng:**
* Tránh lặp lại mã khi cần viết các hàm giống nhau cho các kiểu dữ liệu khác nhau.
* Thích hợp cho các thao tác chung như tính toán, so sánh, hoặc xử lý dữ liệu.

**Trường hợp sử dụng:**
* Các hàm thực hiện logic giống nhau nhưng cho các kiểu dữ liệu khác nhau:
1. Tính tổng, tìm giá trị lớn nhất/nhỏ nhất.
2. So sánh hai đối tượng.

**Cú pháp cơ bản:**
``` C++
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

**Ví dụ:**
``` C++
#include <iostream>

using namespace std;

template <typename T>
auto add(T a, T b){
    return a + b;
}


int main(){
    cout << add(3.4,4.5) << endl;

    cout << add(3,5) << endl;
}
```

## Class template
**Khái niệm:** Cho phép định nghĩa một lớp tổng quát, có thể làm việc với nhiều kiểu dữ liệu.

**Công dụng:** khi thiết kế các cấu trúc dữ liệu hoặc lớp có thể hoạt động với bất kỳ kiểu dữ liệu nào.

**Ví dụ:**
``` C++
#include <iostream>

using namespace std;

template <typename T>
class MyClass{
    private:
    T data;

    public:

    MyClass(T value) : data(value){}

    void display(){
        cout << "Giá trị: " << data << endl;
    }
};


int main(){
    MyClass<int> obj1(3);
    obj1.display();

    MyClass<string> obj2("Hello");
    obj2.display();

    return 0;
}
```

## Variadic template
**Khái niệm:** Loại template cho phép làm việc với số lượng tham số không xác định.

**Công dụng:** Xử lý danh sách tham số động hoặc các kiểu dữ liệu hỗn hợp.

**Ví dụ:**
```  C++
#include <iostream>

using namespace std;

// Class tổng quát sử dụng Variadic Template
template<typename... Args>
class MyClass;

// Định nghĩa class khi không có đối số
template<>
class MyClass<>{
    public:
        void display() {
            cout << "No arguments" << endl;
        }
};

// Định nghĩa class khi có ít nhất một đối số
template<typename T, typename... Args> 
class MyClass<T, Args...> : public MyClass<Args...>{
    private:
        T first_;

    public:
        MyClass(T first, Args... args): first_(first),  MyClass<Args...>(args...){} // T first_ = first, Args1 args1_ = args1, Args2 args2_ = args2,...

        void display(){
            cout << first_ << " ";
            MyClass<Args...>::display(); // Gọi hàm display của lớp cơ sở
        }   

};

int main() 
{
    MyClass<int, double, char> obj(1, 2.5, 'A');
    obj.display();  // Kết quả: 1 2.5 A

    MyClass obj1;
    obj1.display();
    return 0;
}
```
