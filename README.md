# 💡 Hướng dẫn Cấp phát Động trong C

Tài liệu này cung cấp kiến thức cơ bản và ví dụ thực tế về **dynamic memory allocation** (cấp phát động) trong ngôn ngữ lập trình C.

## 📚 Nội dung

- [Tổng quan](#tổng-quan)
- [So sánh với cấp phát tĩnh](#So-sánh-cấp-phát-tĩnh)
- [Các hàm cấp phát động](#các-hàm-cấp-phát-động)
- [Ví dụ cơ bản](#ví-dụ-cơ-bản)
- [Giải phóng bộ nhớ](#giải-phóng-bộ-nhớ)
- [Lưu ý khi sử dụng](#lưu-ý-khi-sử-dụng)

---

## 🧠 Tổng quan

Cấp phát động là quá trình **cấp phát bộ nhớ trong thời gian chạy (runtime)**, cho phép chương trình sử dụng bộ nhớ linh hoạt hơn.

## ⚖️ So sánh với cấp phát tĩnh
| Cấp phát bộ nhớ tĩnh| Cấp phát bộ nhớ động|
|---------------------|---------------------|
|Bộ nhớ được cấp phát trước khi chạy  chương trình (trong qúa trình biên dịch)| Bộ nhớ được cấp phát trong quá trình chạy chương trình.|
|Không thể cấp phát hạy phân bổ lại bộ nhớ trong khii chạy chương trình| Cho phép quản lý, phân bố hay giải phóng bộ nhớ trong khi chạy chương trình|
|Vùng nhớ được cấp phát và tồn tại cho đến khi kết thúc chương trình| Chỉ cấp phát vùng nhớ khi cần sử dụng tới|
|Chương trình chạy nhanh hơn so với cấp phát động| Chương trình chạy chậm hơn so với cấp phát tĩnh|
|Tốn nhiểu không gian bộ nhớ hơn | Tiết kiệm được không gian bộ nhớ sử dụng|


## 🛠️ Các hàm cấp phát động

| Hàm     | Chức năng                              |
|---------|----------------------------------------|
| `malloc()` | Cấp phát bộ nhớ chưa khởi tạo       |
| `calloc()` | Cấp phát bộ nhớ và khởi tạo về 0     |
| `realloc()`| Thay đổi kích thước vùng nhớ đã cấp |
| `free()`   | Giải phóng bộ nhớ đã cấp phát       |

---

### 📌 Hàm `malloc`
Hàm `malloc` cấp phát một khối bộ nhớ có kích thước `size` (tính bằng byte). Bộ nhớ này không được khởi tạo giá trị và có thể chứa các giá trị ngẫu nhiên.

```c
void* malloc(size_t size);
int *ptr = (int*) malloc(10 * sizeof(int));  // Cấp phát bộ nhớ cho mảng 10 phần tử kiểu int
```

📌 Hàm calloc
Hàm calloc tương tự như malloc, nhưng ngoài việc cấp phát bộ nhớ, nó còn khởi tạo tất cả các ô nhớ đã cấp phát về giá trị 0. bộ nhớ cấp phát ra bằng num*size.

```c
void* calloc(size_t num, size_t size);
int *ptr = (int*) calloc(10, sizeof(int));  // Cấp phát bộ nhớ cho mảng 10 phần tử kiểu int và khởi tạo về 0
```

📌 Hàm free
Hàm free được sử dụng để giải phóng bộ nhớ đã được cấp phát động trước đó. Sau khi gọi free, con trỏ ptr không còn trỏ tới vùng bộ nhớ hợp lệ nữa, vì vậy cần phải đảm bảo không sử dụng lại con trỏ đó mà không cấp phát lại bộ nhớ.

```c
free(ptr); //ptr là con trỏ
ptr = NULL; // Đặt con trỏ về NULL để tránh truy cập vùng bộ nhớ không hợp lệ
```

## 📌 Ví dụ 1

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *ten;
    int tuoi;
} sv_info_t;

int main() {
    sv_info_t sv1;
    sv1.ten = calloc(30, sizeof(char));  // cấp phát bộ nhớ

    printf("Nhap ten: ");
    fgets(sv1.ten, 30, stdin);

    // Xóa ký tự newline nếu có
    sv1.ten[strcspn(sv1.ten, "\n")] = '\0';

    printf("Nhap tuoi: ");
    scanf("%d", &sv1.tuoi);

    printf("Ten: %s\n", sv1.ten);
    printf("Tuoi: %d\n", sv1.tuoi);

    free(sv1.ten);  // giải phóng bộ nhớ đã cấp phát

    return 0;
}

```
## 📌 Ví dụ 2
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void in(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("arr[%d] = %d\n", i+1, arr[i]);
    }
}

int *them(int *arr, int *n){
    int a;
    printf("Nhap phan tu can them: ");
    scanf("%d", &a);
    int *arr_2 = (int*)calloc(*n+1, sizeof(int));
    memcpy(arr_2, arr, (*n)*sizeof(int));
    arr_2[*n] = a;
    free(arr);
    (*n)++;
    return arr_2;
}

int *xoa(int *arr,int *n,int index){
    for (int i = index; i < *n; i++)
    {
        arr[i] = arr[i+1];
    }
    (*n)--;
    int *arr_2 = calloc(*n, sizeof(int));
    memcpy(arr_2, arr, (*n)*sizeof(int));
    free(arr);
    return arr_2;
}

int main() {
    int n = 10;
    int *arr = (int*)calloc(10, sizeof(int));
    for(int i = 0; i < 10; i++){
        printf("arr[%d] = ", i+1);
        scanf("%d", arr+i);
    }
    in(arr, 10);
    arr = them(arr, &n);
    in(arr, n);
    arr = xoa(arr, &n, 2);
    in(arr, n);
    return 0;
}

```
*arr chỉ là 1 con trỏ đang trở đến vùng nhớ, bởi vậy nên khi free trong them thì chỉ giải phóng đi vùng nhớ thôi chứ không ảnh hưởng đến con trỏ.

---

## 📌 Ví dụ về lỗi hay gặp của cấp phát bộ nhớ động
```c
#include <stdio.h>
#include <stdint.h>

void capphatbonho(int *pt)
{
    pt = calloc(10, sizeof(int));
}

void main()
{
    int *pt;
    capphatbonho(pt);
    pt[0] = 1;
    printf("%d", pt[0]);
}
```
Khi bạn gọi hàm capphatbonho(pt), bạn chỉ truyền một con trỏ pt vào hàm, nhưng khi thay đổi giá trị của pt bên trong hàm, giá trị đó không được phản ánh ra bên ngoài vì con trỏ này được truyền theo kiểu giá trị (pass-by-value). Điều này có nghĩa là việc cấp phát bộ nhớ trong hàm không ảnh hưởng đến con trỏ pt trong hàm main.

Sửa
```c
#include <stdio.h>

int* capphatbonho(void)
{
    int *pt = calloc(10, sizeof(int));
    if (pt == NULL) {
        printf("Lỗi: Không thể cấp phát bộ nhớ!\n");
        exit(1);
    }
    return pt;
}

int main()
{
    int *pt;
    pt = capphatbonho();
    pt[0] = 1;
    printf("%d\n", pt[0]);
    free(pt); // Giải phóng bộ nhớ
    return 0;
}
```

## 📌 Ghi nhớ
- Đã là con trỏ thì luôn luôn trỏ đến 1 vùng nhớ, sau đó hãy tác động vào nó.
- Chạy xong cấp phát động phải free để giải phóng bộ nhớ
---


