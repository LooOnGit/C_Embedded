# 💡 Hướng dẫn về Con trỏ trong C

Tài liệu này cung cấp kiến thức cơ bản, ví dụ thực tế và giải thích về **con trỏ** trong lập trình C.

---

## 📚 Mục lục

- [Tổng quan](#tổng-quan)
- [Khái niệm cơ bản về con trỏ](#khái-niệm-cơ-bản-về-con-trỏ)
- [Khai báo và sử dụng con trỏ](#khai-báo-và-sử-dụng-con-trỏ)
- [Ví dụ cơ bản](#ví-dụ-cơ-bản)
- [Con trỏ và mảng](#con-trỏ-và-mảng)
- [Con trỏ tới hàm](#con-trỏ-tới-hàm)
- [Lưu ý khi sử dụng con trỏ](#lưu-ý-khi-sử-dụng-con-trỏ)
- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

---

## 🧠 Tổng quan

Con trỏ là một biến trong C dùng để **lưu trữ địa chỉ của một biến khác**. Việc sử dụng con trỏ giúp tăng tính linh hoạt và hiệu suất của chương trình, đặc biệt khi làm việc với mảng, cấp phát bộ nhớ động, và khi cần truyền tham chiếu tới các hàm.

---

## 🏷️ Khái niệm cơ bản về con trỏ

- **Con trỏ** là một biến chứa địa chỉ của một biến khác.
- Con trỏ có thể trỏ đến bất kỳ loại dữ liệu nào, chẳng hạn như kiểu nguyên thủy (`int`, `float`, ...) hoặc kiểu cấu trúc (`struct`).
- Để khai báo con trỏ, chúng ta sử dụng dấu `*`.

---

## ⚙️ Khai báo và sử dụng con trỏ

### Cách khai báo con trỏ:

```c
int *ptr;  // Con trỏ trỏ đến kiểu int
