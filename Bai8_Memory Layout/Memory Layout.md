# Memory Layout
## Text-segment
<ul>
  <li>Hằng số và con trỏ kiểu char</li>
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



