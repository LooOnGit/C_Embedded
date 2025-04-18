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