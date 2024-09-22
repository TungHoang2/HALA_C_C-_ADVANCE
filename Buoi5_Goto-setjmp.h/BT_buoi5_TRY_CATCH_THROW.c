#include <stdio.h>
#include <string.h>
#include <setjmp.h>

// Định nghĩa các macro TRY, CATCH, THROW
#define TRY if ((exception = setjmp(buf)) == 0)

#define CATCH(ErrorCodes) else if (exception == ErrorCodes)

#define THROW(ErrorCodes, input_error) \
    strcpy(error_message, input_error); \
    longjmp(buf, ErrorCodes); \


// Các biến để lưu giá trị
jmp_buf buf;

int exception;

char error_message[100];


// Định nghĩa các mã lỗi
enum ErrorCodes
{
    NO_ERROR,
    FILE_ERROR,
    NETWORK_ERROR,
    CALCULATION_ERROR
};

// Các hàm mô phỏng (readFile,networkOperation,...)
void readFile()
{
    printf("Doc file...\n");
    THROW(FILE_ERROR, "File is not available.");
}

void networkOperation()
{
    printf("Network checking...\n");
    THROW(NETWORK_ERROR, "Network isn't operating.");
}

void calculateData()
{
    printf("Data calculating...\n");
    THROW(CALCULATION_ERROR, "Calculating failed.");
}

int main()
{
    TRY
    {
        networkOperation();
        readFile();
        calculateData();
    }
    CATCH(FILE_ERROR)
    {
        printf("%s\n", error_message);
    }
    CATCH(NETWORK_ERROR)
    {
        printf("%s\n", error_message);
    }
    CATCH(CALCULATION_ERROR)
    {
        printf("%s\n", error_message);
    }
}