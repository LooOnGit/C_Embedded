# 💡 Hướng dẫn về Con trỏ trong C

Tài liệu này cung cấp kiến thức cơ bản, ví dụ thực tế và giải thích về **con trỏ** trong lập trình C.

---

## 📚 Mục lục

- [Tổng quan](#tổng-quan)
- [Khái niệm cơ bản về con trỏ](#khái-niệm-cơ-bản-về-con-trỏ)
- [Khai báo và sử dụng con trỏ](#khai-báo-và-sử-dụng-con-trỏ)
- [Toán tử tăng giảm con trỏ](#Toán tử Tăng Giảm Con trỏ)
- [Con trỏ và mảng](#con-trỏ-và-mảng)
- [Con trỏ tới hàm](#con-trỏ-tới-hàm)
- [Lưu ý khi sử dụng con trỏ](#lưu-ý-khi-sử-dụng-con-trỏ)

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

- **Kiểu dữ liệu** có thể là: void, char, int, float, double,...
- Dấu * trước **tên biến** là ký hiệu báo cho trình biên dịch biết ta đang khai báo con trỏ.

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
- **&pt**: địa chỉ của con trỏ trên RAM
- **pt**: địa chỉ con trỏ trỏ đến trên RAM.
- ***pt**: giá trị tại vùng địa chỉ con trỏ trỏ đến trên RAM
---

## ➕ Toán tử Tăng Giảm Con trỏ

Giống như một biến thông thường, con trỏ cũng có toán tử tăng giảm, tuy nhiên khi sử dụng toán tử tăng/giảm trên biến con trỏ, nó sẽ nhảy sang phần tử liền kề chứ không phải tăng/giảm giá trị lên 1 đơn vị.

![alt text](image.png)

## 🧑‍💻 Con trỏ và mảng
Con trỏ và mảng có một mối quan hệ chặt chẽ trong C. Khi khai báo mảng, tên mảng chính là địa chỉ của phần tử đầu tiên trong mảng.
![alt text](image-1.png)

## 🧩 Con trỏ tới hàm

**Truyền địa chỉ biến**
Khi chúng ta truyền vào tham trị (truyền vào giá trị biến) chứ không phải truyền vào tham chiếu (truyền vào địa chỉ biến) thì mặc dù trong hàm đã thay đổi giá trị các biến nhưng sau khi kết thúc hàm giá trị biến vẫn chưa thể thay đổi được. Và chúng ta sẽ phải sửa lại bằng cách truyền vào tham chiếu chính là địa chỉ của biến thông qua con trỏ.

```c
#include <stdio.h>

void hoanVi_thamchie(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void hoanVi_thamtri(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10, b = 1000;
    printf("Truoc khi goi ham hoan vi: a = %d, b = %d \n", a, b);
    hoanVi_thamtri(a, b);
    printf("Sau khi goi ham hoan vi: a = %d, b = %d \n", a, b);
    hoanVi_thamchie(&a, &b);
    printf("Sau khi goi ham hoan vi: a = %d, b = %d \n", a, b);
    return 0;
}
```
**Truyền địa chỉ của mảng**
Chúng ta có thể sử dụng con trỏ để thay đổi giá trị các phần tử mảng. Địa chỉ của mảng cũng chính là địa chỉ phần tử đầu tiên của mảng.

**Ví dụ:**
```c
#include <stdio.h>
#include <string.h>

int mang[100] = {0};

void NhapMang(int *pt, int *n)
{
    printf("Nhap vao so phan tu mang: ");
    scanf("%d", n);
    printf("Nhap Mang\n");
    for (int i = 0; i < *n; i++)
    {
        printf("mang[%d] = ", i); // gán giá trị cho phần tử mảng thông qua con trỏ
        scanf("%d", pt); // trỏ con trỏ pt đến phần tử mảng tiếp theo
        pt = pt + 1;
    }
}

void InMang(int *pt, int n)
{
    printf("In Mang\n");
    for (int i = 0; i < n; i++)
    {
        printf("mang[%d] = %d\n", i, *pt);
        pt = pt + 1;
    }
}

int main()
{
    int phan_tu_mang;
    NhapMang(mang, &phan_tu_mang);
    InMang(mang, phan_tu_mang);
}
```

**Hàm trả về con trỏ**
Tương tự như trong C++, thì trong C cũng cho phép hàm trả về một con trỏ.

**Cú pháp**
```c
kieudulieu_tra_ve *ten_ham()
{
    // user code
}
```

**Ví dụ:**

```c
#include <stdio.h>

int *timSoLonNhat(int x, int y)
{
    if (x > y)
    {
        return &x; // trả về 1 địa chỉ
    }
    else
    {
        return &y; // trả về 1 địa chỉ
    }
}

int main()
{
    int *result;
    int a = 11;
    int b = 15;
    result = timSoLonNhat(a, b); // truyền vào giá trị của a và b
    printf("So lon nhat = %d \n", *result);
    return 0;
}
```

**Kết quả:**
Segmentation fault (core dumped)

## ⚠️ Lưu ý khi sử dụng con trỏ
- Không truy cập bộ nhớ không hợp lệ: Truy cập con trỏ không được gán giá trị hoặc trỏ đến bộ nhớ không hợp lệ sẽ gây lỗi.
- Giải phóng bộ nhớ: Nếu bạn sử dụng con trỏ để cấp phát bộ nhớ động (ví dụ với malloc()), hãy nhớ giải phóng bộ nhớ bằng free() khi không sử dụng nữa.
- Tránh sử dụng con trỏ null: Trước khi dereference một con trỏ, luôn kiểm tra xem nó có phải là null không.