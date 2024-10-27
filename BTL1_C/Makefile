# Tên của chương trình
TARGET = BTL

# Thư mục chứa header và source file
HEADER_DIR = HEADER
SOURCE_DIR = SOURCE

# Các tệp nguồn và tệp object tương ứng
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)

# Trình biên dịch và các cờ
CC = gcc
CFLAGS = -g -Wall -Wextra -I$(HEADER_DIR)

# Quy tắc đầu tiên là quy tắc mặc định sẽ được thực thi
all: $(TARGET)

# Quy tắc để tạo ra tệp thực thi
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Quy tắc để biên dịch các tệp .c thành .o
$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Quy tắc làm sạch thư mục
clean:
	rm -f $(SOURCE_DIR)/*.o $(TARGET)

# Quy tắc để chạy chương trình
run: $(TARGET)
	./$(TARGET)

# Quy tắc giả
.PHONY: all clean run
