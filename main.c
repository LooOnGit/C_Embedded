#include <stdio.h>
#include <stdint.h>

// Định nghĩa union cho motor control
typedef union {
    struct {
        uint8_t start   :1;   // Bit 0: Bật/tắt động cơ
        uint8_t stop    :1;   // Bit 1: Dừng động cơ
        uint8_t reverse :1;   // Bit 2: Đảo chiều động cơ
        uint8_t fault   :1;   // Bit 3: Báo lỗi
        uint8_t reserved:4;   // Bit 4-7: Dự phòng
    } bits;
    uint8_t all;              // Truy cập toàn bộ 8 bits
} MotorControlReg;

MotorControlReg motorReg;

void printMotorStatus(void) {
    printf("Motor Status: start=%d, stop=%d, reverse=%d, fault=%d, raw=0x%02X\n",
           motorReg.bits.start,
           motorReg.bits.stop,
           motorReg.bits.reverse,
           motorReg.bits.fault,
           motorReg.all);
}

int main(void) {
    printf("=== Điều khiển động cơ ===\n");

    // Bật động cơ
    motorReg.bits.start = 1;
    // Không đảo chiều
    motorReg.bits.reverse = 0;
    // Dừng động cơ (không dừng)
    motorReg.bits.stop = 0;
    // Không báo lỗi
    motorReg.bits.fault = 0;

    printMotorStatus();

    // Ghi trực tiếp cả byte
    motorReg.all = 0x0F;  // 00001111b → start=1, stop=1, reverse=1, fault=1

    printMotorStatus();

    return 0;
}

