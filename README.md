# 💡 Hướng dẫn về Con trỏ cấp 2 trong C

Tài liệu này cung cấp kiến thức cơ bản, ví dụ thực tế và giải thích rõ ràng về **con trỏ cấp 2 (double pointer)** trong lập trình C.

---

## 📚 Mục lục

- [Tổng quan](#tổng-quan)
- [Con trỏ cấp 2 là gì?](#con-trỏ-cấp-2-là-gì)
- [Cách khai báo và sử dụng](#cách-khai-báo-và-sử-dụng)
- [Ví dụ cơ bản](#ví-dụ-cơ-bản)
- [Con trỏ cấp 2 trong cấp phát động](#Con trỏ cấp 2 trong cấp phát động)
- [Ứng dụng của con trỏ cấp 2](#ứng-dụng-của-con-trỏ-cấp-2)
- [Lưu ý khi sử dụng](#lưu-ý-khi-sử-dụng)
- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

---

## 🧠 Tổng quan

Con trỏ cấp 2 là **con trỏ trỏ đến một con trỏ khác**. Nó giúp chúng ta thao tác sâu hơn với bộ nhớ, thay đổi địa chỉ con trỏ trong hàm, quản lý mảng 2 chiều, và nhiều tình huống nâng cao khác trong lập trình C.

---

## 🏷️ Con trỏ cấp 2 là gì?

- Con trỏ cấp 2 là một biến lưu **địa chỉ của một con trỏ khác**.
- Ký hiệu: `**`, ví dụ: `int **pptr;`
- Có thể được hiểu như:  
  `**pptr` → giá trị của biến gốc  
  `*pptr` → con trỏ cấp 1  
  `pptr` → con trỏ cấp 2

---

## ⚙️ Cách khai báo và sử dụng

### Khai báo:

```c
int a = 5;
int *p = &a;       // con trỏ cấp 1
int **pp = &p;     // con trỏ cấp 2
```
## 🔍 Ví dụ cơ bản
![alt text](image.png)
![alt text](image-1.png)

Con trỏ cấp 1 lưu trữ địa chỉ của một biến còn con trỏ cấp 2 lưu trữ địa chỉ của 1 con trỏ.

## ⚙️ Con trỏ cấp 2 cấp phát động
### Ví dụ 1:
```c
#include <stdio.h>

void capphat(int **ptt, int n)
{
    int **p = (int **)ptt;
    *p = calloc(n, sizeof(int));
}

int main()
{
    int *pt = NULL;
    capphat(&pt, 10);
    pt[0] = 100;
    printf("%d", pt[0]);
    return 0;
}
```
### Ví dụ 2:
```c
#include <stdio.h>
#define KICHTHUOC 3
const int KICHCO = 4;

void xuatmang(int *pt, int sophantu)
{
    for (int i = 0; i < sophantu; i++)
    {
        printf("%d ", pt[i]);
    }
}

int main()
{
    int pt1[5] = {1, 2, 3, 4, 5};
    int pt2[5] = {11, 12, 13, 14, 15};
    int pt3[5] = {21, 22, 23, 24, 25};

    int *contro[KICHTHUOC];
    contro[0] = pt1;
    contro[1] = pt2;
    contro[2] = pt3;

    char *hotensv[] = {
        "Tran Hung Cuong",
        "Ho Ngoc Ha",
        "Nguyen Son Tung",
        "Dam Vinh Hung",
    };

    for (int i = 0; i < KICHCO; i++)
    {
        printf("gia tri cua hotensv[%d] = %s\n", i, hotensv[i]);
    }

    // contro[0][0] = 111; // thay doi gia tri
    xuatmang(contro[0], 5);

    return 0;
}
```
- Tác dụng thứ nhất là thay đổi địa chỉ của con trỏ 1 chiều.
- Tác dụng thứ 2 cấp phát động 1 mảng con trỏ.
