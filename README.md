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

`#include` cho phép thêm nội dung của một file khác vào file đang viết. Chúng ta đặc biệt sử dụng `#include` để thêm các file `.h` từ thư viện chuẩn (như `stdio.h`, `stdlib.h`, `string.h`, `math.h`) hoặc các file `.h` do bạn tự định nghĩa.

---

#### Cách sử dụng:

1. **Thêm file từ thư viện hệ thống**:
   Sử dụng dấu ngoặc nhọn `< >` để thêm các file `.h` có sẵn trong thư mục cài đặt IDE của bạn.
   ```c
   #include <stdlib.h>
   ```