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
Nhưng biến con trỏ không lưu giá trị bình thường, nó là biến trỏ tới 1 địa chỉ khác, tức mang giá trị là 1 địa chỉ trong RAM.

---

## 🏷️ Khái niệm cơ bản về con trỏ

- **Con trỏ** là một biến chứa địa chỉ của một biến khác.
- Con trỏ có thể trỏ đến bất kỳ loại dữ liệu nào, chẳng hạn như kiểu nguyên thủy (`int`, `float`, ...) hoặc kiểu cấu trúc (`struct`).
- Để khai báo con trỏ, chúng ta sử dụng dấu `*`.

---

## ⚙️ Khai báo và sử dụng con trỏ

### Cách khai báo con trỏ:

**<kiểu dữ liệu>** * **<tên biến>**

Trong đó:

**Kiểu dữ liệu** có thể là: void, char, int, float, double,...
Dấu * trước **tên biến** là ký hiệu báo cho trình biên dịch biết ta đang khai báo con trỏ.

**Ví dụ 1:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int x = 77;
    int *pt = &x;
    printf("Gia tri cua x = %d \n", *pt);
    printf("Dia chi cua x la %x hoac %x \n", &x, pt);
    printf("Dia chi cua con tro pt la %0x \n", &pt);
    return 0;
}
```
**Ví dụ 1:**
```c
#include <stdio.h>

int main() {
    int x = 1000;
    int *pt;        
    pt = &x;

    // In ra địa chỉ của con trỏ pt
    printf("&pt = %p \n", (void*)&pt);  // &pt: Địa chỉ của con trỏ pt

    // In ra địa chỉ mà con trỏ pt trỏ đến (địa chỉ của x)
    printf("pt = %p \n", (void*)pt);    // pt: Địa chỉ mà pt trỏ đến (địa chỉ của x)

    // In ra giá trị tại địa chỉ mà con trỏ pt trỏ đến (giá trị của x)
    printf("*pt = %d \n", *pt);        // *pt: Giá trị tại địa chỉ mà pt trỏ đến (giá trị của x)

    return 0;
}
```
**&pt**: địa chỉ của con trỏ (được RAM cấp)
**pt**: địa chỉ con trỏ trỏ đến (được RAM cấp)
***pt**: giá trị tại vùng địa chỉ con trỏ trỏ đến (được RAM cấp)

