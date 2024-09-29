# Stack:
<ul>
  <li>Tuân theo nguyên tắc LIFO(Last In First Out)</li>
  <li>Có 3 thao tác cơ bản: Push, Pop, Top</li>
  <li>Top = size -1 --> Full</li>
  <li>Top = -1 --> Empty</li>
  <li>Ứng dụng khi sử dụng ngắt trong lập trình vi xử lý: Lưu địa chỉ (pc) vào stack sau đó chuyển qua làm ngắt và quay lại stack đó lấy địa chỉ và tiếp tục thực hiện chương trình</li>
</ul>


# Queue:
Tuân theo nguyên tắc FIFO (First In First Out).

Có 4 thao tác cơ bản:
<ul>
  <li>Enqueue: Thêm phần tử vào cuối hàng đợi</li>
  <li>Dequeue: Lấy phần tử từ đầu hàng đợi</li>
  <li>Front: Lấy giá trị của phần tử đứng đầu hàng</li>
  <li>Rear:  Lấy giá trị của phần tử đứng cuối hàng</li>
</ul>

### Các điểm cần nhớ:
<ul>
  <li>Khi mới khởi tạo thì: Front = rear = -1 (queue trống)</li>
  <li>Enqueue --> rear++</li>
  <li>Dequeue --> front++</li>
  <li>Max_front = max_rear = size -1</li>
  <li>Queue.rear = queue.size – 1 --> full</li>
  <li>Queue.front = queue.rear = -1 --> empty</li>
  <li>Queue.front  == -1 || queue.front > queue.rear --> empty</li>
</ul>

### Linear Queue
Khi front = rear mới thêm phần tử vào được (nhược điểm)
### Circular queue
Khắc phục nhược điểm của Linear queue. Khi dequeue thì rear = 1 (nhảy về đầu hàng đợi) và có thể thêm phần tử bất kì khi nào chứ không cần dequeue hết toàn bộ như linear queue
