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
} data_frame;

int main()
{
    data_frame transmit_data, receive_data;
    strcpy((char *)transmit_data.data.id, "10");
    strcpy((char *)transmit_data.data.data, "1234");
    strcpy((char *)transmit_data.data.check_sum, "21");
    strcpy((char *)receive_data.frame, (char *)transmit_data.frame);
    return 0;
}
