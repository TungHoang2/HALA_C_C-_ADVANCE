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
