# Format Specifiers in C

In C programming, **format specifiers** are special symbols used in `printf()` and `scanf()` functions to specify the type of data being handled. They tell the compiler how to interpret the variable's memory during **input** or **output** operations.

Format specifiers are essential for working with different data types, numbers, strings, characters, and floating-point values. Using the wrong specifier can lead to unexpected behavior, garbage values, or program crashes.

---

## 1. Common Format Specifiers in C

| Data Type              | Format Specifier | Description                                       | Example                                                    |
| ---------------------- | ---------------- | ------------------------------------------------- | ---------------------------------------------------------- |
| `int`                  | `%d`             | Signed decimal integer                            | `int x = 10; printf("%d", x);`                             |
| `int`                  | `%i`             | Signed decimal integer (same as %d)               | `int x = 10; printf("%i", x);`                             |
| `unsigned int`         | `%u`             | Unsigned decimal integer                          | `unsigned int x = 300; printf("%u", x);`                   |
| `octal`                | `%o`             | Unsigned octal number                             | `int x = 10; printf("%o", x);` outputs `12`                |
| `hexadecimal`          | `%x`             | Unsigned hexadecimal (lowercase)                  | `int x = 255; printf("%x", x);` outputs `ff`               |
| `hexadecimal`          | `%X`             | Unsigned hexadecimal (uppercase)                  | `int x = 255; printf("%X", x);` outputs `FF`               |
| `char`                 | `%c`             | Single character                                  | `char ch = 'A'; printf("%c", ch);`                         |
| `string`               | `%s`             | String (null-terminated)                          | `char str[] = "Hello"; printf("%s", str);`                 |
| `float`                | `%f`             | Decimal floating-point                            | `float f = 3.14; printf("%f", f);` outputs `3.140000`      |
| `double`               | `%lf`            | Double floating-point                             | `double d = 3.1415; printf("%lf", d);`                     |
| `scientific notation`  | `%e`             | Float/double in scientific notation (lowercase e) | `printf("%e", 123.45);` outputs `1.234500e+02`             |
| `scientific notation`  | `%E`             | Float/double in scientific notation (uppercase E) | `printf("%E", 123.45);` outputs `1.234500E+02`             |
| `short int`            | `%hd`            | Signed short integer                              | `short s = 10; printf("%hd", s);`                          |
| `unsigned short`       | `%hu`            | Unsigned short integer                            | `unsigned short s = 10; printf("%hu", s);`                 |
| `long int`             | `%ld`            | Signed long integer                               | `long l = 1000000; printf("%ld", l);`                      |
| `unsigned long`        | `%lu`            | Unsigned long integer                             | `unsigned long l = 1000000; printf("%lu", l);`             |
| `long long int`        | `%lld`           | Signed long long integer                          | `long long ll = 10000000000; printf("%lld", ll);`          |
| `unsigned long long`   | `%llu`           | Unsigned long long integer                        | `unsigned long long ll = 10000000000; printf("%llu", ll);` |
| `pointer`              | `%p`             | Memory address                                    | `int x; printf("%p", &x);`                                 |
| `size_t`               | `%zu`            | For `sizeof()` results                            | `printf("%zu", sizeof(int));`                              |
| `hexadecimal floating` | `%a` / `%A`      | Float/double in hexadecimal format                | `printf("%a", 10.5);` outputs `0x1.500000p+3`              |

---

## 2. Using Format Specifiers for **Input** (`scanf()`)

The same format specifiers are used in `scanf()` but with a crucial difference: you must pass the **address of the variable** using `&` (except for strings).

### Examples:

```c
#include <stdio.h>

int main() {
    int a;
    float f;
    char c;
    char str[20];

    printf("Enter an integer: ");
    scanf("%d", &a);

    printf("Enter a float: ");
    scanf("%f", &f);

    printf("Enter a character: ");
    scanf(" %c", &c); // note the space before %c to skip whitespace

    printf("Enter a string: ");
    scanf("%s", str); // no & needed for strings

    printf("You entered: %d, %f, %c, %s\n", a, f, c, str);
    return 0;
}
```

**Important notes for input:**

* Strings do not need `&` because the array name already acts as a pointer.
* For characters, if you have `scanf("%c", &c);`, a leftover newline character from previous input may be read, so use `" %c"` (with space) to ignore whitespace.
* For `long`, `long long`, `unsigned`, etc., use the corresponding format specifier (`%ld`, `%llu`, `%lu`).

---

## 3. Using Format Specifiers for **Output** (`printf()`)

The `printf()` function uses format specifiers to **print variables** in a readable form.

### Examples:

```c
#include <stdio.h>

int main() {
    int num = 255;
    float f = 3.14159;
    double d = 123.456789;
    char ch = 'A';
    char str[] = "Hello";

    printf("Decimal: %d\n", num);
    printf("Octal: %o\n", num);
    printf("Hexadecimal: %x\n", num);
    printf("Char: %c\n", ch);
    printf("String: %s\n", str);
    printf("Float: %f\n", f);
    printf("Double: %lf\n", d);
    printf("Scientific notation: %E\n", d);
    printf("Memory address: %p\n", &num);

    return 0;
}
```

**Sample Output:**

```
Decimal: 255
Octal: 377
Hexadecimal: ff
Char: A
String: Hello
Float: 3.141590
Double: 123.456789
Scientific notation: 1.234568E+02
Memory address: 0x7ffee6b8
```

---

## 4. Output Formatting in `printf()`

C provides advanced ways to **format output** for better readability. You can control **width, precision, alignment, and padding**.

### 4.1 Width and Alignment

```c
int x = 123;

printf("%5d\n", x);    // Width 5, right-aligned → "  123"
printf("%-5dEND\n", x); // Left-aligned → "123  END"
```

### 4.2 Floating-point Precision

```c
float f = 3.14159265;

printf("%.2f\n", f);  // 2 decimal places → 3.14
printf("%8.3f\n", f); // Width 8, 3 decimals → "   3.142"
```

### 4.3 Zero Padding

```c
int n = 42;
printf("%05d\n", n); // Output: 00042
```

### 4.4 Printing Strings with Width and Precision

```c
char str[] = "HelloWorld";

printf("%10s\n", str);   // Right-aligned, width 10 → "HelloWorld"
printf("%.5s\n", str);   // Print only first 5 chars → "Hello"
printf("%-10.5sEND\n", str); // Left-aligned, 5 chars → "Hello     END"
```

### 4.5 Using `*` for Dynamic Width and Precision

```c
int width = 8;
int prec = 3;
float pi = 3.1415926;

printf("%*.*f\n", width, prec, pi); // Width 8, 3 decimals → "   3.142"
```

---

## 5. Special Cases

### 5.1 Printing `sizeof()` Result

```c
printf("Size of int: %zu bytes\n", sizeof(int));
printf("Size of double: %zu bytes\n", sizeof(double));
```

* `%zu` is preferred for `size_t`.

### 5.2 Pointers

```c
int x = 10;
int *ptr = &x;

printf("Value: %d\n", *ptr);
printf("Address: %p\n", ptr);
```

### 5.3 Hexadecimal Floating-point (`%a` / `%A`)

```c
double d = 10.5;
printf("%a\n", d); // Outputs hexadecimal representation → 0x1.500000p+3
```

---

## 6. Summary of Output Formatting Options

| Symbol/Specifier | Meaning                                          |
| ---------------- | ------------------------------------------------ |
| `%width`         | Minimum width for output                         |
| `%-width`        | Left-align output                                |
| `%0width`        | 0s padding                                     |
| `%.precision`    | Decimal places for floats, max chars for strings |
| `%*.*f`          | Dynamic width and precision                      |
| `%+d`            | Show `+` sign for positive numbers               |
| `% d`            | Space for positive numbers                       |
| `%%`             | Print a literal `%`                              |

---

## 7. Best Practices

1. Always use the **correct specifier** for the data type to avoid undefined behavior.
2. Use **width and precision** for better-aligned tables and reports.
3. Use `%zu` for `sizeof()` and `%p` for pointers.
4. For `scanf()`, remember `&` for all variables except arrays.
5. Use formatting with strings to prevent buffer overflow in input (`%19s` for array of size 20).

---

### Example: Complete Input & Output Program

```c
#include <stdio.h>

int main() {
    int i;
    float f;
    double d;
    char ch;
    char str[20];

    printf("Enter int, float, double, char, string:\n");
    scanf("%d %f %lf %c %s", &i, &f, &d, &ch, str);

    printf("\n---Formatted Output---\n");
    printf("Integer: %5d\n", i);
    printf("Float: %8.2f\n", f);
    printf("Double: %10.4lf\n", d);
    printf("Char: %c\n", ch);
    printf("String: %-10.5sEND\n", str);

    return 0;
}
```

**Sample Input:**

```
123 3.14159 123.456789 A HelloWorld
```

**Sample Output:**

```
---Formatted Output---
Integer:   123
Float:     3.14
Double:  123.4568
Char: A
String: Hello     END
```

---

# Tricky MCQs on Format Specifiers in C

This document contains 15 tricky multiple-choice questions (MCQs) specifically focused on **Format Specifiers in C**. Each question comes with detailed explanations to help understand subtle behaviors.

---

## 1. Which format specifier should be used to print the result of `sizeof(int)`?

```c
printf("?");
```

**Options:**  
A) `%d`  
B) `%u`  
C) `%zu`  
D) `%ld`  

**Answer:** C) `%zu`  
**Explanation:** `sizeof` returns `size_t`, which requires `%zu`. Using `%d` or `%u` may cause incorrect output on 64-bit systems.

---

## 2. What is the output of the following?

```c
int x = -5;
printf("%u", x);
```

**Options:**  
A) -5  
B) 4294967291  
C) 5  
D) Undefined  

**Answer:** B) 4294967291  
**Explanation:** `%u` treats `x` as unsigned. The 32-bit representation of -5 as unsigned is `4294967291`.

---

## 3. Output of:

```c
char ch = 65;
printf("%c", ch);
```

**Options:**  
A) 65  
B) A  
C) a  
D) Error  

**Answer:** B) A  
**Explanation:** `%c` prints the character corresponding to ASCII value 65, which is 'A'.

---

## 4. Output of:

```c
float f = 3.14159;
printf("%.2f", f);
```

**Options:**  
A) 3.1  
B) 3.14  
C) 3.142  
D) 3.14159  

**Answer:** B) 3.14  
**Explanation:** `%.2f` rounds the float to 2 decimal places.

---

## 5. Output of:

```c
char str[] = "HelloWorld";
printf("%.5s", str);
```

**Options:**  
A) HelloWorld  
B) Hello  
C) World  
D) He  

**Answer:** B) Hello
**Explanation:** `%.5s` prints only the first 5 characters of the string.

---

## 6. Output of:

```c
int x = 255;
printf("%x %X", x, x);
```

**Options:**  
A) ff FF  
B) FF ff  
C) 255 255  
D) 0xff 0XFF  

**Answer:** A) ff FF  
**Explanation:** `%x` prints lowercase hexadecimal, `%X` prints uppercase hexadecimal.

---

## 7. Which format specifier prints a `long long int`?

**Options:**  
A) `%ld`  
B) `%lld`  
C) `%lu`  
D) `%d`  

**Answer:** B) `%lld`  
**Explanation:** `%lld` is used for `long long int`. `%ld` is for `long int`.

---

## 8. Output of:

```c
int a = 10;
printf("%5d", a);
```

**Options:**  
A) 10  
B) &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;10  
C) 10  
D) Error

**Answer:** B)   10
**Explanation:** `%5d` prints the number right-aligned in a width of 5 characters, padding with spaces.

---

## 9. Output of:

```c
int a = 42;
printf("%05d", a);
```

**Options:**  
A) 42  
B) 0042  
C) 00042  
D) 42  

**Answer:** C) 00042  
**Explanation:** `%05d` pads the number with zeros to make width 5.

---

## 10. Output of:

```c
double d = 123.456;
printf("%e", d);
```

**Options:**  
A) 123.456  
B) 1.234560e+02  
C) 123  
D) 1.23456E+02  

**Answer:** B) 1.234560e+02  
**Explanation:** `%e` prints in scientific notation with lowercase 'e' and default 6 decimals.

---

## 11. Which specifier is used to print a pointer address?

**Options:**  
A) `%d`  
B) `%p`  
C) `%u`  
D) `%x`  

**Answer:** B) `%p`  
**Explanation:** `%p` prints the memory address of a pointer in an implementation-defined format.

---

## 12. Output of:

```c
int x = 123;
printf("%-5dEND", x);
```

**Options:**  
A) &nbsp;&nbsp;&nbsp;123END   
B) 123&nbsp;&nbsp;&nbsp;END  
C) 123END  
D) Error

**Answer:** B) 123  END  
**Explanation:** `%-5d` left-aligns `123` in a width of 5, padding with spaces, followed by `END`.

---

## 13. Output of:

```c
int x = 10;
printf("%*d", 5, x);
```

**Options:**  
A) 10  
B) &nbsp;&nbsp;&nbsp;10  
C) 0010  
D) 00010  

**Answer:** B) &nbsp;&nbsp;&nbsp;10  
**Explanation:** `*` allows dynamic width. Here width is 5, so output is right-aligned with spaces.

---

## 14. Output of:

```c
float f = 10.5;
printf("%a", f);
```

**Options:**  
A) 10.5  
B) 0x1.500000p+3  
C) 0xa.8p+0  
D) Error  

**Answer:** B) 0x1.500000p+3  
**Explanation:** `%a` prints floating-point numbers in hexadecimal notation.

---

## 15. Output of:

```c
int n = 8;
printf("%d", n & (n-1));
```

**Options:**  
A) 0  
B) 1  
C) 7  
D) 8  

**Answer:** A) 0  
**Explanation:** `n & (n-1)` clears the least significant set bit. 8 in binary is 1000; 1000 & 0111 = 0.

---

## 16. Which format specifier is correct for `double` in `scanf()`?

**Options:**  
A) `%f`  
B) `%lf`  
C) `%d`  
D) `%lF`  

**Answer:** B) `%lf`  
**Explanation:** `scanf()` requires `%lf` for reading a double, while `%f` works for `float`.

---

## 17. Output of:

```c
char str[10];
scanf("%9s", str);
```

**Options:**  
A) Reads unlimited characters  
B) Reads maximum 9 characters  
C) Reads only 1 character  
D) Error  

**Answer:** B) Reads maximum 9 characters  
**Explanation:** Limiting width prevents buffer overflow; the 10th char is reserved for '�'.

---

## 18. Output of:

```c
int x = 5;
printf("%%d", x);
```

**Options:**  
A) 5  
B) %d  
C) 0d  
D) Error  

**Answer:** B) %d  
**Explanation:** `%%` prints a literal `%`, so output is `%d`.

---

## 19. Output of:

```c
int x = 123;
printf("%5.2d", x);
```

**Options:**  
A) 123  
B) 00123  
C) &nbsp;&nbsp;123  
D) Error

**Answer:** D) Error  
**Explanation:** Precision `.2` is invalid for integers. C standard allows `.precision` only for floats/strings.

---

## 20. Output of:

```c
int x = 10;
printf("%+d", x);
```

**Options:**  
A) 10  
B) +10  
C) -10  
D) Error  

**Answer:** B) +10  
**Explanation:** `%+d` prints a `+` sign for positive numbers.

---

This set of MCQs helps in understanding subtle behaviors and edge cases of **format specifiers in C**, useful for exams and interviews.


