# 💡 Phân vùng Bộ nhớ trong C

Tài liệu này cung cấp kiến thức cơ bản, ví dụ minh họa và giải thích rõ ràng về **phân vùng bộ nhớ (memory segmentation)** trong ngôn ngữ lập trình C.

---

## 📚 Mục lục

- [Tổng quan](#tổng-quan)
- [Các vùng bộ nhớ chính](#các-vùng-bộ-nhớ-chính)
- [Chi tiết từng phân vùng](#chi-tiết-từng-phân-vùng)
- [Ví dụ minh họa](#ví-dụ-minh-họa)
- [Ứng dụng và tối ưu](#ứng-dụng-và-tối-ưu)
- [Lưu ý khi lập trình](#lưu-ý-khi-lập-trình)
- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

---

## 🧠 Tổng quan

Khi một chương trình C được biên dịch và chạy, bộ nhớ được chia thành nhiều **vùng (segment)** khác nhau. Việc phân vùng bộ nhớ giúp hệ điều hành và chương trình quản lý tài nguyên hiệu quả hơn, đảm bảo an toàn và ổn định.

---

## 🧩 Các vùng bộ nhớ chính

Bộ nhớ trong chương trình C thường được chia thành các vùng sau:

1. **Text Segment (Code Segment)** – Chứa mã máy của chương trình.
2. **Data Segment (initialized data segment)** – Chứa biến toàn cục, biến static được khởi tạo.
3. **BSS Segment (uninitialized data segment)** – Chứa biến toàn cục, biến static chưa được khởi tạo.
4. **Heap  (free srote segment)** – Dành cho cấp phát bộ nhớ động (malloc, calloc, realloc).
5. **Stack (Stack segment)** – Dùng cho biến cục bộ, lời gọi hàm, địa chỉ trả về,…
![alt text](image.png)
---

## 🔍 Chi tiết từng phân vùng

### 📄 Text Segment
- Chứa mã nguồn đã được biên dịch.
- Thường là vùng **read-only**.
- Ví dụ: nội dung của các hàm `main()`, `printf()`, v.v.

### 🧾 Data Segment
- Biến toàn cục/static có giá trị khởi tạo.

**Ví dụ:**
```c
  int global_var = 10;
  static int count = 0;
```
### ❓ BSS Segment
- Biến toàn cục/static chưa khởi tạo.
- Được khởi tạo mặc định là 0.

**Ví dụ:**
```c
int x;
static int y;
```
### 📦 Heap
- Dùng cho cấp phát động: malloc, calloc,…
- Quản lý thủ công (cần free() sau khi dùng).

**Ví dụ:**
```c
int *arr = (int *)malloc(10 * sizeof(int));
```

### 🌀 Stack 
- Dành cho biến cục bộ, lời gọi hàm.
- Quản lý theo cơ chế LIFO (Last In, First Out).
- Tự động thu hồi sau khi thoát khỏi khối lệnh.