# Struct-Union
## Struct
Struct là một kiểu dữ liệu do người dùng định nghĩa, cho phép gộp nhiều kiểu dữ liệu khác nhau thành 1 nhóm. Mỗi phần tử trong struct được gọi là member.

### Cú pháp:
```
struct <Struct_name> {
       dataType member1
       dataType member2
       …..
};
```
Ví dụ:
```
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
### Lưu ý:
<ul>
  <li>Truy cập thành viên: Để truy cập thành viên của 1 struct, sử dụng dấu chấm (.) cho biến thông thường và dấu mũi tên (->) khi truy cập qua con trỏ</li>
  <li>Khởi tạo struct: Có thể khởi tạo trực tiếp các thành viên của struct khi khai báo biến.</li>
</ul>

Ví dụ:
struct Person person2 = {"Alice", 25, 5.5};

<ul>
  <li>Nếu không khởi tạo giá trị, thì member có thể có giá trị không xác định (garbage value)</li>
  <li>Các địa chỉ của các member có thể không liền kề nhau do memory alignment, trình biên dịch sẽ thêm padding giữa các member</li>
</ul>

Ví dụ: 
```
struct A {
    char c;
    int i;
};
printf("%d\n", sizeof(struct A));  // Kích thước có thể lớn hơn 5 do padding
```

<ul>
  <li>Sử dụng typedef với struct: Việc sử dụng từ khóa typedef giúp bạn tránh phải viết từ khóa struct mỗi lần sử dụng.</li>
</ul>


Ví dụ:
```
typedef struct {
    int x, y;
} Point;

Point p;  // Không cần viết 'struct Point'
```

## Union
### Cú pháp:
```
union UnionName {
    dataType1 member1;
    dataType2 member2;
    …..
    // các thành viên khác
};
```
### Khác nhau giữa struct và union:

<ul>
  <li>Trong struct, mỗi thành viên có một vùng bộ nhớ riêng.</li>
  <li>Trong union, tất cả các thành viên chia sẻ chung một vùng bộ nhớ, nên kích thước của một union là kích thước của thành viên có kích thước lớn nhất.</li>
</ul>

### Lưu ý: 

<ul>
  <li>Các thành viên trong union đều chia sẻ chung một vùng bộ nhớ. Do đó, chỉ có một thành viên có thể lưu trữ giá trị hợp lệ tại bất kỳ thời điểm nào.</li>
  <li>Khi một thành viên mới được gán giá trị, dữ liệu của thành viên trước đó sẽ bị mất (bị ghi đè lên qua từng lần gán giá trị)</li>
  <li>Kích thước của union bằng với kích thước của thành viên lớn nhất trong union.</li>
</ul>

Ví dụ: 
```
union Data {
    int i;      // 4 byte
    float f;    // 4 byte
    char str[20];  // 20 byte
};
printf("%zu\n", sizeof(union Data));  // Kết quả là 20
```

<ul>
  <li>Sử dụng với typedef: Có thể sử dụng từ khóa typedef để tránh phải viết từ khóa union mỗi lần sử dụng, tương tự như với struct.</li>
</ul>


Ví dụ: 
```
typedef union {
    int i;
    float f;
    char str[20];
} Data;

Data data;
```

### Ứng dụng của struct và union:
```
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
### Giải thích:
Sử dụng uint8_t cho struct để không bị padding

Sử dụng union cho frame để có địa chỉ chứa receive_data và transmit_data

(char*) để ép thành mảng khi xài strcpy
