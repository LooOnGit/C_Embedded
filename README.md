# 📖 Hướng dẫn về Tiền xử lý (Preprocessor) trong C

Tài liệu này cung cấp kiến thức cơ bản, ví dụ thực tế và giải thích rõ ràng về **tiền xử lý (preprocessor)** trong lập trình C.

---

## 📚 Mục lục

- [Tổng quan](#tổng-quan)
- [Các nhóm chỉ thị tiền xử lý](#các-nhóm-chỉ-thị-tiền-xử-lý)
  - [1. Chỉ thị bao hàm tệp (`#include`)](#1-chỉ-thị-bao-hàm-tệp-include)
  - [2. Chỉ thị định nghĩa cho tên (`#define`)](#2-chỉ-thị-định-nghĩa-cho-tên-define)
  - [3. Chỉ thị biên dịch có điều kiện (`#if`, `#else`, `#elif`, `#endif`, ...)](#3-chỉ-thị-biên-dịch-có-điều-kiện-if-else-elif-endif-)
- [Ví dụ minh họa](#ví-dụ-minh-họa)
- [Lưu ý khi sử dụng tiền xử lý](#lưu-ý-khi-sử-dụng-tiền-xử-lý)
- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

---

## 🧠 Tổng quan

Tiền xử lý (Preprocessor) trong C là một bước thực hiện trước khi biên dịch mã nguồn. Tất cả các chỉ thị tiền xử lý đều bắt đầu với ký tự `#`. Các chỉ thị này không phải là lệnh C/C++ nên không cần dấu `;` khi kết thúc.

---

## 🔧 Các nhóm chỉ thị tiền xử lý

### 1. Chỉ thị bao hàm tệp (`#include`)

Dùng để chèn nội dung của một tệp tiêu đề (header file) vào mã nguồn.

**Cú pháp**:
```c
#include <tên_tệp>   // Tìm tệp trong thư mục hệ thống
#include "tên_tệp"   // Tìm tệp trong thư mục hiện tại