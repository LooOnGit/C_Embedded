# 📖 Hướng dẫn về Mảng (Array) trong C

Tài liệu này cung cấp kiến thức cơ bản, ví dụ thực tế và giải thích rõ ràng về **mảng (array)** trong lập trình C.

---

## 📚 Mục lục

- [Tổng quan](#tổng-quan)
- [Cách khai báo mảng](#cách-khai-báo-mảng)
- [Truy cập phần tử trong mảng](#truy-cập-phần-tử-trong-mảng)
- [Mảng một chiều](#mảng-một-chiều)
- [Mảng hai chiều](#mảng-hai-chiều)
- [Lưu ý khi sử dụng mảng](#lưu-ý-khi-sử-dụng-mảng)
- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

---

## 🧠 Tổng quan

Mảng (array) là một tập hợp các phần tử có cùng kiểu dữ liệu, được lưu trữ liên tiếp trong bộ nhớ. Mỗi phần tử trong mảng có thể được truy cập thông qua chỉ số (index).

---

## ⚙️ Cách khai báo mảng

### Cú pháp:
```c
type array_name[size];
```
- `type`: Kiểu dữ liệu của các phần tử trong mảng (ví dụ: `int`, `float`, `char`).
- `array_name`: Tên của mảng.
- `size`: Số lượng phần tử trong mảng.

### Ví dụ:
```c
int numbers[5]; // Mảng chứa 5 số nguyên
char letters[10]; // Mảng chứa 10 ký tự
```
## 🔍 Truy cập phần tử trong mảng
Các phần tử trong mảng được truy cập thông qua chỉ số, bắt đầu từ `0`.

### Ví dụ:
```c
int numbers[5] = {1, 2, 3, 4, 5};
printf("%d\n", numbers[0]); // In ra phần tử đầu tiên: 1
numbers[2] = 10; // Gán giá trị 10 cho phần tử thứ 3
```
## 📋 Mảng một chiều
Mảng một chiều là mảng cơ bản nhất, lưu trữ các phần tử theo một hàng.
### Ví dụ:
```c
#include <stdio.h>

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("Phần tử thứ %d: %d\n", i, numbers[i]);
    }
    return 0;
}
```
📊 Mảng hai chiều
Mảng hai chiều là mảng chứa các phần tử được tổ chức theo dạng bảng (hàng và cột).
### Cú pháp:
```c
type array_name[rows][columns];
```
### Ví dụ:
```c
#include <stdio.h>

int main() {
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Phần tử tại [%d][%d]: %d\n", i, j, matrix[i][j]);
        }
    }
    return 0;
}
```