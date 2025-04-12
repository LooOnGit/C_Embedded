C
# 📖 Hướng dẫn về String trong C

Tài liệu này cung cấp kiến thức cơ bản, ví dụ thực tế và giải thích rõ ràng về **string (chuỗi)** trong lập trình C.

---

## 📚 Mục lục

- [Tổng quan](#tổng-quan)
- [Cách khai báo chuỗi](#cách-khai-báo-chuỗi)
- [Các hàm xử lý chuỗi phổ biến](#các-hàm-xử-lý-chuỗi-phổ-biến)
- [Ví dụ minh họa](#ví-dụ-minh-họa)
- [Lưu ý khi sử dụng chuỗi](#lưu-ý-khi-sử-dụng-chuỗi)
- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

---

## 🧠 Tổng quan

Trong ngôn ngữ lập trình C, **string** (chuỗi) là một mảng các ký tự được kết thúc bằng ký tự null (`'\0'`). Chuỗi không phải là kiểu dữ liệu riêng biệt mà được biểu diễn dưới dạng mảng ký tự.

---

## ⚙️ Cách khai báo chuỗi

### 1. Khai báo và khởi tạo trực tiếp:
```c
char str[] = "Hello, World!";
```
- Chuỗi này tự động thêm ký tự '\0' ở cuối.

### 2. Khai báo mảng ký tự:
```c
char str[20] = "Hello";
```