C
# 📖 Hướng dẫn về Struct trong C

Tài liệu này cung cấp kiến thức cơ bản, ví dụ thực tế và giải thích rõ ràng về **struct (cấu trúc)** trong lập trình C.

---

## 📚 Mục lục

- [Tổng quan](#tổng-quan)
- [Cách khai báo struct](#cách-khai-báo-struct)
- [Truy cập thành viên của struct](#truy-cập-thành-viên-của-struct)
- [Sử dụng con trỏ với struct](#sử-dụng-con-trỏ-với-struct)
- [Struct lồng nhau](#struct-lồng-nhau)
- [Ứng dụng của struct](#ứng-dụng-của-struct)
- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

---

## 🧠 Tổng quan

`struct` (cấu trúc) trong C là một kiểu dữ liệu do người dùng định nghĩa, cho phép nhóm nhiều biến có kiểu dữ liệu khác nhau lại với nhau. `struct` rất hữu ích khi bạn cần tổ chức dữ liệu phức tạp.

---

## ⚙️ Cách khai báo struct

### Khai báo tường minh
```c
struct structureName {
    dataType member1;
    dataType member2;
    // Các thành viên khác
};
```
#### Ví dụ:
```C
struct student {
    char ten[30];
    int tuoi;
    char sodienthoai[20];
    float lop;
};
```
**Khai báo biến struct**:
```C
struct student sv1;
struct student sv2;
// Hoặc khai báo mảng struct
struct student sv[10];
```


### Khai báo không tường minh (Sử dụng `typedef` với struct)

Khi sử dụng `typedef`, bạn có thể định nghĩa một tên mới cho kiểu `struct`, giúp việc khai báo biến trở nên ngắn gọn hơn.

```c
typedef struct {
    dataType member1;
    dataType member2;
    // Các thành viên khác
} structureName;
```
#### Ví dụ:
```C
typedef struct {
    char ten[30];
    int tuoi;
    char sodienthoai[20];
    float lop;
} student;
```
**Khai báo biến struct:**
```C
student sv1;
student sv2;
// Hoặc khai báo mảng struct
student sv[10];
```

## 🔍 Truy cập thành viên của struct
Các thành viên của struct được truy cập bằng toán tử . (dấu chấm).
### Ví dụ:
```C
#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

int main() {
    struct Student student1 = {"Tran Cong Hoa", 20, 8.5};

    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("Grade: %.2f\n", student1.grade);

    return 0;
}
```
## 📋 Sử dụng con trỏ với struct
Khi làm việc với con trỏ trỏ đến struct, bạn sử dụng toán tử -> để truy cập các thành viên.
### Ví dụ: 
```C
#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point p1 = {10, 20};
    struct Point *ptr = &p1;

    printf("x: %d, y: %d\n", ptr->x, ptr->y);

    return 0;
}
```