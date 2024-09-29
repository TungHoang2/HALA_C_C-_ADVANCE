# Phân biệt giữa stack và heap:
## Stack: 
<ul>
  <li>Truy cập nhanh: Do cấu trúc đơn giản nên việc truy cập dữ liệu rất nhanh</li>
  <li>Quản lý tự động: Hệ điều hành tự động cấp phát và giải phóng bộ nhớ trên stack khi hàm được gọi và kết thúc</li>
  <li>Kích thước hạn chế: Stack có kích thước cố định, nếu gọi quá nhiều hàm đệ quy hoặc khai báo quá nhiều biến cục bộ có thể dẫn đến tràn stack (stack overflow)</li>
  <li>Lưu các biến cục bộ, tham số, địa chỉ trả về</li>
</ul>


## Heap:
<ul>
  <li>Truy cập chậm hơn, dễ bị rò rỉ bộ nhớ </li>
  <li>Quản lý thủ công: Được quản lý bởi lập trình viên, dữ liệu trong Heap sẽ không bị hủy khi kết thúc chương trình, vậy nên phải tự giải phóng bộ nhớ bằng hàm free().</li>
  <li>Kich thước lớn: Heap thường có kích thước lớn hơn Stack, cho phép cấp phát vùng nhớ lớn hơn</li>
  <li>Linh hoạt: Có thể cấp phát hoặc thu hồi vùng nhớ theo yêu cầu của chương trình</li>
  <li>Lưu các đối tượng động, mảng lớn, cấu trúc dữ liệu phức tạp.</li>
</ul>





