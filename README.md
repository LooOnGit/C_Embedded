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

### Cú pháp:
```c
struct StructName {
    data_type member1;
    data_type member2;
    // Các thành viên khác
};