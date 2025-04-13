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
2. **Thêm file từ thư mục dự án**: 
   Sử dụng dấu ngoặc kép " " để thêm các file .h trong thư mục chứa project của bạn. Nếu không tìm thấy file trong thư mục dự án, bộ tiền xử lý sẽ tiếp tục tìm trong thư viện hệ thống.
   ```c
   #include "myheader.h"
   ```
   **Cách hoạt động**:
   Tất cả nội dung của file .h sẽ được chèn vào file .c tại vị trí của chỉ thị #include.
### Ví dụ 2:

Dưới đây là những gì ta có trong file `.c`:

```c
#include "file.h"

long myFunction(int x, double y) {
    /* Source code of function */
}

void otherFunction(long value) {
    /* Source code of function */
}
```
Và những gì có trong file .h:
```c
long myFunction(int x, double y);
void otherFunction(long value);
```
**Tiền xử lý**:
Khi sử dụng #include "file.h", bộ tiền xử lý sẽ chèn toàn bộ nội dung của file file.h vào file .c tại vị trí của chỉ thị #include. Kết quả sau khi tiền xử lý sẽ như sau:
```c
long myFunction(int x, double y);
void otherFunction(long value);

long myFunction(int x, double y) {
    /* Source code of function */
}

void otherFunction(long value) {
    /* Source code of function */
}
```
### Ví dụ 3: Sử dụng hàm `static`

#### Mô tả:
Hàm `static` trong C được sử dụng để giới hạn phạm vi sử dụng của hàm chỉ trong file `.c` nơi nó được định nghĩa. Điều này giúp tránh xung đột tên hàm khi làm việc với nhiều file trong một dự án.

#### Cách thực hiện:

1. **Tạo file `lib.h`**:
   ```c
   #include <stdio.h>
   void in_so();
   ```

2. **Tạo file `lib.c`**:
   ```c
   #include "lib.h"

   static void so(int num) {
       num = num + 1;
   }

   void in_so() {
       int num = 0;
       so(num);
       printf("Số sau khi tăng: %d\n", num);
   }
   ```

   - Hàm `static void so()` chỉ có thể được sử dụng trong file `lib.c`. Nó không thể được gọi từ các file khác.

3. **Tạo file `main.c`**:
   ```c
   #include "lib.h"

   int main() {
       in_so();
       return 0;
   }
   ```

#### Kết quả:
Khi chạy chương trình, bạn sẽ nhận được kết quả in ra từ hàm `in_so()`.

#### Lưu ý:
- Hàm `static` giúp bảo vệ các hàm nội bộ, tránh việc chúng bị sử dụng ngoài ý muốn từ các file khác.
- Đây là một cách tốt để tổ chức mã nguồn và giảm thiểu xung đột tên trong các dự án lớn.

