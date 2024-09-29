# Phân biệt malloc(), calloc(), realloc()
## malloc():
<ul>
  <li>Được sử dụng để phân bố động 1 khối bộ nhớ có kích thước được chỉ định</li>
  <li>Kiểu trả về là void * và có thể ép kiểu về con trỏ bất kì </li>
  <li>Giá trị ban đầu của từng ô nhớ mặc định là garbage value</li>
  <li>Nếu không đủ không gian, việc phân bổ sẽ không thành công và trả về con trỏ NULL.</li>
  <li>Khi sử dụng phải khai báo thư viện stdlib.h</li>
</ul>

### Cú pháp:
ptr = (cast-type*) malloc(byte-size)

### Ví dụ:
ptr = (int*) malloc(100 * sizeof(int))

Vì kích thước của int là 4 byte, câu lệnh này sẽ phân bổ 400 byte bộ nhớ. Và con trỏ ptr giữ địa chỉ của byte đầu tiên trong bộ nhớ được phân bổ. 


## calloc():
<ul>
  <li>Được sử dụng để phân bổ động số lượng khối bộ nhớ được chỉ định của loại được chỉ định (data-type)</li>
  <li>Nếu không đủ không gian, việc phân bổ sẽ không thành công và trả về con trỏ NULL.</li>
  <li>Khi sử dụng phải khai báo thư viện stdlib.h</li>
  <li>Kiểu trả về là void * và có thể ép kiểu về con trỏ bất kì </li>
</ul>

### 2 điểm khác biệt so với malloc():
Khởi tạo mỗi khối với giá trị mặc định là 0
Có 2 tham số hoặc đối số khi so sánh với malloc()

### Cú pháp: 
ptr = (cast-type*)calloc(n, element-size);

n là số lượng phần tử và element-size là kích thước của mỗi phần tử.


### Ví dụ: 
ptr = (float*) calloc(25, sizeof(float));

Câu lệnh này phân bổ không gian liền kề trong bộ nhớ cho 25 phần tử, mỗi phần tử có kích thước bằng float.


## free():
Khi sử dụng xong các vùng nhớ sẽ không tự động thu hồi mà phải dùng free() để thu hồi bộ nhớ


## recalloc():
<ul>
  <li>Được sử dụng để phân bổ lại bộ nhớ đã được phân bổ trước đó. Nếu bộ nhớ được phân bổ trước đó của malloc hoặc calloc không đủ, thì sẽ sử dụng recalloc() để phân bổ lại bộ nhớ động </li>
  <li>Việc phân bổ lại sẽ duy trì giá trị của các bộ nhớ cũ và gán giá trị rác cho các vùng nhớ mới.</li>
</ul>



### Cú pháp:
ptr = realloc(ptr, newSize); 

trong đó ptr được phân bổ lại với kích thước mới 'newSize'.
