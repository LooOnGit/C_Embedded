# 💡 Hướng dẫn về Storage Class Specifiers trong C/C++

Tài liệu này cung cấp kiến thức cơ bản, ví dụ thực tế và giải thích rõ ràng về **Storage Class Specifiers** trong lập trình C/C++.

---

## 📚 Mục lục

- [Tổng quan](#tổng-quan)
- [Storage Class Specifiers là gì?](#storage-class-specifiers-là-gì)
- [Các loại Storage Class Specifiers](#các-loại-storage-class-specifiers)
  - [auto](#auto)
  - [register](#register)
  - [static](#static)
  - [extern](#extern)
- [Ứng dụng của Storage Class Specifiers](#ứng-dụng-của-storage-class-specifiers)
- [Lưu ý khi sử dụng](#lưu-ý-khi-sử-dụng)
- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

---

## 🧠 Tổng quan

Trong C và C++, Storage Class Specifiers (chỉ định lớp lưu trữ) được sử dụng để xác định **thời gian sống**, **phạm vi truy cập** và **vị trí trong bộ nhớ** của các biến và hàm. Việc hiểu rõ về các specifiers này giúp tối ưu hóa việc quản lý bộ nhớ và kiểm soát phạm vi của các biến.

---

## 🏷️ Storage Class Specifiers là gì?

Storage Class Specifiers là các từ khóa dùng để xác định tính chất của các biến hoặc hàm. Các specifiers này ảnh hưởng đến **phạm vi (scope)**, **liên kết (linkage)**, và **thời gian sống (lifetime)** của các biến. Các specifiers chính gồm:

- **auto**
- **register**
- **static**
- **extern**

---

## ⚙️ Các loại Storage Class Specifiers
![alt text](image.png)
### auto

- **Phạm vi**: Biến cục bộ.
- **Liên kết**: Không có liên kết.
- **Thời gian sống**: Biến chỉ tồn tại trong khối mà nó được khai báo.
- **Mặc định**: Các biến cục bộ sẽ tự động có kiểu `auto` nếu không được khai báo rõ ràng.

### Nếu biến cục bộ tự động là auto thì tại sao sinh ra auto để làm gì?
Mặc dù auto không cần thiết trong thực tế code C, nó vẫn hữu ích cho những người viết trình biên dịch vì:

Giúp đơn giản hóa cấu trúc cú pháp ngôn ngữ (grammar): mọi biến đều có thể có một storage class specifier (ví dụ: auto, register, static, extern), nên người viết compiler chỉ cần xử lý một quy tắc cú pháp duy nhất cho tất cả khai báo biến.

Từ khóa auto tồn tại như một phần của thiết kế ngôn ngữ thống nhất và hình thức.

#### Ví dụ:
```c
void example() {
    auto int num = 10; // 'num' là biến cục bộ
    printf("%d\n", num);
}
