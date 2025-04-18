C
# 📖 Hướng dẫn về Struct trong C

Tài liệu này cung cấp kiến thức cơ bản, ví dụ thực tế và giải thích rõ ràng về **struct (cấu trúc)** trong lập trình C.

---

## 📚 Mục lục

- [Tổng quan](#tổng-quan)
- [Cách khai báo struct](#cách-khai-báo-struct)
- [Truy cập thành viên của struct](#truy-cập-thành-viên-của-struct)
- [Sử dụng con trỏ với struct](#sử-dụng-con-trỏ-với-struct)
- [Struct lồng nhau](#struct-lồng-nhau)
- [Kích thước của Struct](#kích-thước-của-Struct)
- [Phân mảnh bộ nhớ](#Phân-mảnh-bộ-nhớ)
- [Cách khắc phục phân mảnh bộ nhớ](Cách-khắc-phục-phân-mảnh-bộ-nhớ)
- [Ứng dụng của struct](#ứng-dụng-của-struct)

---

## 🧠 Tổng quan

`struct` (cấu trúc) trong C là một kiểu dữ liệu do người dùng định nghĩa, cho phép nhóm nhiều biến có kiểu dữ liệu khác nhau lại với nhau. `struct` rất hữu ích khi bạn cần tổ chức dữ liệu phức tạp.

---

## ⚙️ Cách khai báo struct

### Khai báo tường minh
```c
struct structureName {
    dataType member1;
    dataType member2;
    // Các thành viên khác
};
```
#### Ví dụ:
```C
struct student {
    char ten[30];
    int tuoi;
    char sodienthoai[20];
    float lop;
};
```
**Khai báo biến struct**:
```C
struct student sv1;
struct student sv2;
// Hoặc khai báo mảng struct
struct student sv[10];
```


### Khai báo không tường minh (Sử dụng `typedef` với struct)

Khi sử dụng `typedef`, bạn có thể định nghĩa một tên mới cho kiểu `struct`, giúp việc khai báo biến trở nên ngắn gọn hơn.

```c
typedef struct {
    dataType member1;
    dataType member2;
    // Các thành viên khác
} structureName;
```
#### Ví dụ:
```C
typedef struct {
    char ten[30];
    int tuoi;
    char sodienthoai[20];
    float lop;
} student;
```
**Khai báo biến struct:**
```C
student sv1;
student sv2;
// Hoặc khai báo mảng struct
student sv[10];
```

## 🔍 Truy cập thành viên của struct
Các thành viên của struct được truy cập bằng toán tử . (dấu chấm).
### Ví dụ:
```C
#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

int main() {
    struct Student student1 = {"Tran Cong Hoa", 20, 8.5};

    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("Grade: %.2f\n", student1.grade);

    return 0;
}
```
## 📋 Sử dụng con trỏ với struct
Khi làm việc với con trỏ trỏ đến struct, bạn sử dụng toán tử -> để truy cập các thành viên.
### Ví dụ: 
```C
#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point p1 = {10, 20};
    struct Point *ptr = &p1;

    printf("x: %d, y: %d\n", ptr->x, ptr->y);

    return 0;
}
```

## 📊 Struct lồng nhau
`struct` có thể chứa các `struct` khác làm thành viên.
### Ví dụ:
```C
#include <stdio.h>

struct Address {
    char city[50];
    int zip;
};

struct Person {
    char name[50];
    struct Address address;
};

int main() {
    struct Person person = {"Tran Cong Hoa", {"Hanoi", 100000}};

    printf("Name: %s\n", person.name);
    printf("City: %s\n", person.address.city);
    printf("ZIP: %d\n", person.address.zip);

    return 0;
}
```
## 📏 Kích thước của Struct
Giả sử mình có struct như sau và câu hỏi đặt ra là kích thước của nó là bằng bao nhiêu?
**Câu trả lời:** Kích thước của struct là bội kích thước của phần tử có kích thước lớn nhất trong struct.
![alt text](image.png)
```c
struct ST {
    int Index;
    char Team;
};

// Phần tử lớn nhất là Index có kích thước 4 byte.
// -> Kích thước struct là bội của 4.

// Index nằm trong block 4 byte đầu tiên.
// Block này không còn byte trống, do con chip
// thường là 32 bit thì 4 byte là đủ rồi mà.

// Team có kích thước 1 byte phải nằm ở block tiếp theo.
// Block này là 4 byte thừa 3 byte.

// => Kích thước struct này là 8 byte.
```
## 🧩 Phân mảnh bộ nhớ (Memory Alignment)
### Data alignment là gì? Nó hoạt động như thế nào?
   Data alignment có nghĩa là khi data được load lên memory sẽ được CPU sắp xếp lại để tiện cho việc truy xuất tối ưu nhất có thể. Các bạn đều đã biết bộ nhớ máy tính là một dãy các ô nhớ liên tiếp nhau, mỗi ô nhớ có kích thước 1 byte. Tuy nhiên khi chương trình chạy, các vi xử lý hiện đại không truy cập từng ô nhớ một, mà một nhóm các ô nhớ gồm 2, 4 hoặc 8 bytes. Việc này nhằm mục đích tăng hiệu suất để đọc ghi của hệ thống.

**Để có thể làm được việc đó chúng ta cần hiểu 2 khái niệm sau:**
- **Data alignment**: sắp xếp data sao cho địa chỉ của các biến luôn là số chẵn và phù hợp với hệ thống.
- **Data padding**: để làm được việc alignment như ở trên chúng ta cần phải "padding" (đệm) thêm một số byte vào sau biến "char id" để khi đó biến"int age" có thể ở địa chỉ chẵn. Char có thể bắt đầu trên bất cứ byte địa chỉ nào, short-2 bytes chỉ bắt đầu bằng các bytes địa chỉ chẵn, int-4 bytes hoặc float-4 bytes bắt đầu tại các byte địa chỉ chia hết cho 4, long-8bytes hoặc double-8 bytes bắt đầu tại các byte địa chỉ chia hết cho 8. Không có sự khác biệt giữa các kiểu có dấu và không dấu.
![alt text](image-1.png)
Những gì bạn tính là 1+4+8 = 13 bytes, nhưng kết quả lại là 16, lạ phải không nào?
 Đầu tiên compiler sẽ tìm xem trong struct, thành viên nào có kích thước lớn nhất, sau đó sẽ cấp phát một block có kích thước lớn nhất, sau đó sẽ cấp phát một block có kích thước tương ứng với member lớn nhất, rồi điền các vùng nhớ của các members theo thứ tự khai báo trong struct, khi nào hết một block, sẽ cấp thêm block mới. Cụ thể với ví dụ trên:

 Compiler sẽ xác định member gpa kiểu double là thành viên có kích thước lớn nhất trong struct, kích thước là 8bytes.

 Sau đó, compiler sẽ đẩy 1 byte của **id** vào block. Lúc này còn 7 bytes trống, compiler sẽ xác định thành viên có kích thước bé tiếp theo rồi vào, ở đây sẽ là 4 bytes của **age**, compiler sẽ padding 3 bytes và đẩy age vào 4 bytes còn lại.
 	
 Vậy là hết block đầu tiên, còn lại thành viên gpa chưa được cấp bộ nhớ, do đó compiler sẽ cấp phát tiếp 2 block 8bytes rồi đẩy **gpa** vào 8 bytes đó.

**Ví dụ**: Tính kích thước của Struct
```C
struct A {
    int x;
    double z;
    short int y;
};

struct B {
    double z;
    int x;
    short int y;
};

struct C {
    double z;
    short int y;
    int x;
};
```
**Struct A**
![alt text](image-2.png)
- Kích thước của struct A là bội của 8 vì phần tử có kích thước lớn nhất là 8 byte và cấp từ trên xuống nên ta có:
- Phần tử x kiểu int 4 byte và vì là bội của 8 nên còn 4byte trống
- Phần tử z kiểu double 8 byte nên vừa đủ không có byte trống
- Phần tử y kiểu short int 2 byte nên dùng 2 byte và còn 6byte trống
- Tổng kích thước Struct A = 8+8+8 = 24 byte

**Struct B**
![alt text](image-3.png)
- Kích thước z kiểu double 8 byte thì như trên.
- Phần tử y short int kích thước 2 byte mà cấp đến 8 byte nên còn dư 6byte và x kiểu int 4 byte.
- Kích thước Struct C = 8+2+2+4 = 16 byte.

## 🛠️ Cách khắc phục phân mảnh bộ nhớ
`#pragma pack(n)`: Từ khóa này sẽ nói cho trình biên dịch biết rằng cần cấp phát cho các phần tử trong struct theo n bytes một.
![alt text](image-4.png)
- Ý nghĩa của parama pack là lúc này chỉ cấp phát 1 byte 1
Cách xem kích thước struct.
![alt text](image-5.png)

## 💡 Ứng dụng của struct
- Quản lý dữ liệu phức tạp như thông tin sinh viên, nhân viên, sản phẩm, v.v.
- Tổ chức dữ liệu trong lập trình nhúng và hệ thống.
- Làm việc với các cấu trúc dữ liệu như danh sách liên kết, cây, đồ thị.