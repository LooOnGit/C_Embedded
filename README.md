# 📖 Hướng dẫn về Union trong C

Tài liệu này cung cấp kiến thức cơ bản, ví dụ thực tế và giải thích rõ ràng về **union** trong lập trình C.

---

## 📚 Mục lục

- [Tổng quan](#tổng-quan)
- [Cách khai báo union](#cách-khai-báo-union)
- [Truy cập thành viên của union](#truy-cập-thành-viên-của-union)
- [Sự khác biệt giữa struct và union](#sự-khác-biệt-giữa-struct-và-union)
- [Ứng dụng của union](#ứng-dụng-của-union)
- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

---

## 🧠 Tổng quan

`Union` là dữ liệu đặc biệt trong ngôn ngữ C cho phép bạn dự trữ các kiểu dữ liệu khác nhau trong cùng 1 vùng nhớ. Bạn có thể định nghĩa Union với rất nhiều tham số, nhưng chỉ một thành phần chứa giá trị tại một thời điểm.

---

## ⚙️ Cách khai báo union

### Khai báo tường minh:
```c
union unionName {
    dataType member1;
    dataType member2;
    // Các thành viên khác
};
```
#### Ví dụ:
```C
union Hoclaptrinh {
    int i;
    float f;
    char chuoi[50];
};
```
### Khai báo không tường minh (sử dụng typedef):
```C
typedef union {
    dataType member1;
    dataType member2;
    // Các thành viên khác
} unionName;
```
#### Ví dụ:
```C
typedef union {
    int i;
    float f;
    char chuoi[50];
} Hoclaptrinh;
```
Khác với struct là về cách quản lý bộ nhớ, còn cách dùng thì giống nhau.

## 🔍 Truy cập thành viên của union
Các thành viên của `union` được truy cập bằng toán tử `.` (dấu chấm), tương tự như `struct`.
### Ví dụ:
```C
#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;

    data.i = 10;
    printf("data.i: %d\n", data.i);

    data.f = 220.5;
    printf("data.f: %.2f\n", data.f);

    // Lưu ý: Giá trị của `data.i` sẽ bị ghi đè bởi `data.f`
    return 0;
}
```
## 🔄 Sự khác biệt giữa struct và union
| **Đặc điểm**           | **struct**                          | **union**                          |
|-------------------------|--------------------------------------|-------------------------------------|
| **Bộ nhớ**             | Mỗi thành viên có vùng nhớ riêng    | Các thành viên chia sẻ cùng một vùng nhớ |
| **Kích thước**         | Tổng kích thước của tất cả thành viên | Kích thước của thành viên lớn nhất |
| **Truy cập đồng thời** | Các thành viên có thể được truy cập đồng thời | Chỉ một thành viên có thể được truy cập tại một thời điểm |
| **Ứng dụng**           | Lưu trữ dữ liệu phức tạp với các thành viên độc lập | Tiết kiệm bộ nhớ khi các thành viên không cần tồn tại đồng thời |

![alt text](image.png)
### Ví dụ:
```C
#include <stdio.h>
#include <string.h>

typedef union gt {
    int x;
    float y;
    char c[30];
} gt_t;

int main() {
    gt_t a;
    a.x = 100;
    a.y = 3.14;
    strcpy(a.c, "Loo_D");

    printf("x là %d\n", a.x);
    printf("y là %.2f\n", a.y);
    printf("c là %s\n", a.c);

    return 0;
}
```
![alt text](image-1.png)

Union nó tìm ra phần tử có kích thước lớn nhất và nó chỉ cấp phát ô nhớ cho phần tử có kích thước lớn nhất.
    Ví dụ trên khai báo c gồm 30 phần tử nên 30 byte là lớn nhất nên chỉ cấp phát cho c.
    Khi vào hàm main hoạt động thì gán phần tử x bằng 100 thì lúc này nó ghi giá trị vào 30byte vừa cấp phát. Và tiếp theo nó gán y bằng 3.14 thì lúc này y ghi đè giá trị vào 30 byte thì lúc này x không còn ghi trong đó nữa nên sinh ra giá trị rác.
    Khi thực hiện lệnh strcpy copy "Loo_D" vào phần tử c thì lúc này nó lại ghi đè lên y là ghi vào 30byte đó nên y cũng mất. Vì thế khi in ra thì x và y không đúng.
Kết luận: Union vd trên có kích thước 30byte và các phần tử sử dụng chung 30 byte đó. Và union sinh ra để tiết kiệm ô nhớ vì tại 1 thời điểm chỉ sử dụng 1 phần tử được sử dụng và có giá trị hợp lệ.
### Ví dụ: 
```C
typedef struct {
    char ten[30];
    int _level;
} giangvien_info_t;

typedef struct {
    char ten[30];
    int _class;
} sinhvien_info_t;

typedef union {
    giangvien_info_t gv;
    sinhvien_info_t sv;
} info_t;

int main() {
    info_t info; // 34 bytes

    printf("Nhap ten giang vien: ");
    gets(info.gv.ten);
    printf("Ten gv: %s\n", info.gv.ten);

    printf("Nhap ten sinh vien: ");
    gets(info.sv.ten);
    printf("Ten sv: %s\n", info.sv.ten);

    return 0;
}
```