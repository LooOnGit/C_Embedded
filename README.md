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