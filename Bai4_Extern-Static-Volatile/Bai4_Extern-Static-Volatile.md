# Bài 4: Extern_Static_Volatile
## 1.1.Extern
Khái niệm:

Được sử dụng để thông báo 1 biến hoặc 1 hàm đã được khai báo ở 1 nơi nào đó trong chương trình hoặc 1 file nguồn khác. Giúp chương trình hiểu được biến hoặc hàm đã được định nghĩa và sẽ được sử dụng từ 1 vị trí khác, quản lý sự liên kết giữa các phần khác nhau của chương trình hoặc giữa các file nguồn.

Các lưu ý:
<ul>
  <li>Chỉ sử dụng khi biến ở toàn cục</li> 
  <li>Chỉ được khai báo không được gán giá trị</li>
  <li>Giúp chia sẻ những biến, hàm, … giữa các file khác nhau</li>
  <li>Phải sử dụng liên kết file và dùng để thiết kế thư viện</li>
  <li>Không sử dụng include bởi vì chỉ cần xài 1 số biến, hàm trong file đó chứ không cần tất cả nên xài include sẽ tốn bộ nhớ, xử lý lâu hơn, tác vụ chậm hơn</li>
</ul>


## 1.2.Static 
### 1.2.1.Static local variable
Ví dụ:
```
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
Giải thích: 
<ul>
  <li>Khi sử dụng từ khóa static thì biến trong hàm sẽ được cấp phát 1 địa chỉ và xài xuyên suốt cả chương trình, không bị thu hồi khi kết thúc hàm và tất nhiên vì nó là cục bộ nên sẽ chỉ có sử dụng trong phạm vi hàm</li>
  <li>Nếu muốn thay đổi giá trị thì dùng con trỏ (trỏ đến địa chỉ của biến đó và thay đổi) </li>
</ul>

Ứng dụng:

Lưu trữ trạng thái giữa các lần gọi hàm: Sử dụng biến static để theo dõi trạng thái trạng thái giữa các lần gọi hàm mà không cần sử dụng biến toàn cục.

### 1.2.2.Static global variable:
Khi sử dụng với global variables (biến toàn cục – khai báo ngoài hàm), nó sẽ hạn chế phạm vi của biến đó chỉ trong file nguồn hiện tại không cho cái file khác truy cập vào

## 1.3.Register
Chỉ sử dụng cho biến cục bộ, không sử dụng cho biến toàn cục


 
Bình thường sẽ chạy tuần tự 4 bước từ khai báo ở RAM sau đó đẩy sang lưu vào Register và đẩy sang ALU để tính toán số học và cuối cùng là trả về  Register sau đó về RAM

Khi khai báo register thì sẽ rút ngắn quá trình chạy chỉ còn 2 bước giúp chương trình chạy nhanh hơn, tăng tốc độ truy cập

## 1.4.Volatile
Từ khóa volatile được sử dụng để báo hiệu cho trình biên dịch rằng một biến có thể thay đổi ngẫu nhiên, ngoài sự kiểm soát của chương trình (nút nhấn,…). Việc này ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.

