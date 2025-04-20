# 📖 Hướng dẫn về Union trong C

Tài liệu này cung cấp kiến thức cơ bản, ví dụ thực tế và giải thích rõ ràng về **union** trong lập trình C.

---

## 📚 Mục lục

- [Tổng quan](#tổng-quan)
- [Cách khai báo union](#cách-khai-báo-union)
- [Truy cập thành viên của union](#truy-cập-thành-viên-của-union)
- [Sự khác biệt giữa struct và union](#sự-khác-biệt-giữa-struct-và-union)
- [Ứng dụng của union](#ứng-dụng-của-union)
- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

---

## 🧠 Tổng quan

`Union` là dữ liệu đặc biệt trong ngôn ngữ C cho phép bạn dự trữ các kiểu dữ liệu khác nhau trong cùng 1 vùng nhớ. Bạn có thể định nghĩa Union với rất nhiều tham số, nhưng chỉ một thành phần chứa giá trị tại một thời điểm.

---

## ⚙️ Cách khai báo union

### Khai báo tường minh:
```c
union unionName {
    dataType member1;
    dataType member2;
    // Các thành viên khác
};
```
#### Ví dụ:
```C
union Hoclaptrinh {
    int i;
    float f;
    char chuoi[50];
};
```
### Khai báo không tường minh (sử dụng typedef):
```C
typedef union {
    dataType member1;
    dataType member2;
    // Các thành viên khác
} unionName;
```
#### Ví dụ:
```C
typedef union {
    int i;
    float f;
    char chuoi[50];
} Hoclaptrinh;
```
Khác với struct là về cách quản lý bộ nhớ, còn cách dùng thì giống nhau.

## 🔍 Truy cập thành viên của union
Các thành viên của `union` được truy cập bằng toán tử `.` (dấu chấm), tương tự như `struct`.
### Ví dụ:
```C
#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;

    data.i = 10;
    printf("data.i: %d\n", data.i);

    data.f = 220.5;
    printf("data.f: %.2f\n", data.f);

    // Lưu ý: Giá trị của `data.i` sẽ bị ghi đè bởi `data.f`
    return 0;
}
```
## 🔄 Sự khác biệt giữa struct và union
| **Đặc điểm**           | **struct**                          | **union**                          |
|-------------------------|--------------------------------------|-------------------------------------|
| **Bộ nhớ**             | Mỗi thành viên có vùng nhớ riêng    | Các thành viên chia sẻ cùng một vùng nhớ |
| **Kích thước**         | Tổng kích thước của tất cả thành viên | Kích thước của thành viên lớn nhất |
| **Truy cập đồng thời** | Các thành viên có thể được truy cập đồng thời | Chỉ một thành viên có thể được truy cập tại một thời điểm |
| **Ứng dụng**           | Lưu trữ dữ liệu phức tạp với các thành viên độc lập | Tiết kiệm bộ nhớ khi các thành viên không cần tồn tại đồng thời |