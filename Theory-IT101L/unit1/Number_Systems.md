# 📘 Number Systems in C Programming

## 1. Introduction
In C programming, numbers can be represented in different number systems:  
* <span style="color: yellow">Decimal</span> (Base 10) → Digits: `0–9`
* <span style="color: yellow">Binary</span> (Base 2) → Digits: `0, 1`
* <span style="color: yellow">Octal</span> (Base 8) → Digits: `0–7`
* <span style="color: yellow">Hexadecimal</span> (Base 16) → Digits: `0–9`, `A–F`  
Computers internally work in `binary`, but programmers often use `decimal`, `octal`, and `hexadecimal` notations for readability and specific applications (like memory addresses, permissions, bit-masks, etc.).   

## 2. Representation of Numbers in C

| Number System | Prefix in C | Example     | Meaning                      |
| ------------- | ----------- | ----------- | ---------------------------- |
| **Decimal**   | none        | `124`       | Decimal 124                  |
| **Binary**    | `0b` / `0B` | `0b1111100` | Binary 1111100 = Decimal 124 |
| **Octal**     | `0`         | `0174`      | Octal 174 = Decimal 124      |
| **Hex**       | `0x` / `0X` | `0x7C`      | Hex 7C = Decimal 124         |

## 3. Printing Numbers in Different Systems
```c
#include <stdio.h>

int main() {
    int num = 124;

    printf("Decimal     : %d\n", num);
    printf("Octal       : %o\n", num);
    printf("Hexadecimal : %x\n", num); // lowercase
    printf("Hexadecimal : %X\n", num); // uppercase

    return 0;
}
```

Ouput : 
```bash
Decimal     : 124
Octal       : 174
Hexadecimal : 7c
Hexadecimal : 7C
```

<span style="color: orange; font-weight: 700">👉 Note</span>: C does not have a direct format specifier for binary. We write custom functions for binary output.

## 4. Reading Input in Different Number Systems

```c
#include <stdio.h>

int main() {
    int d, o, h;

    printf("Enter decimal: ");
    scanf("%d", &d);

    printf("Enter octal (prefix with 0): ");
    scanf("%o", &o);

    printf("Enter hexadecimal (prefix with 0x): ");
    scanf("%x", &h);

    printf("\nDecimal: %d\nOctal: %d\nHex: %d\n", d, o, h);
    return 0;
}
```
Input : 
```bash
Enter decimal: 12
Enter octal (prefix with 0): 012
Enter hexadecimal (prefix with 0x): 0x12
```

Ouput : 
```bash
Decimal: 12
Octal: 10
Hex: 18
```
<span style="color: orange">Note : </span> `%d` format specifier is used for decimal, `%o` for octal, and `%x`(lowercase) or `%X`(uppercase) for hexadecimal number.

## 5. Conversion Programs

### (a) Decimal → Binary
```c
// Question : Write a C program to print Binary equivalent of a Decimal number in the REVERSE Order
#include <stdio.h>
int main() {
    int num;
    printf("Enter number(decimal) to convert to binary: ");
    scanf("%d", &num);
    
    printf("Binary Equivalent in the Reverse Format: \n");
    // READ BASICS OF WHILE LOOP
    while(num > 0){
        printf("%d", num%2);
        num = num/2;
    }
    return 0;
}
```
Input : 
```bash
Enter number(decimal) to convert to binary: 12
```

Ouput : 
```bash
Binary Equivalent in the Reverse Format: 
0011
```

### (b) Binary → Decimal
```c
// Question : Write a C program to print Decimal equivalent of a Binary number

#include<stdio.h>
#include<math.h>

int main(){
    int num;
    printf("Enter the Binary Number(in decimal format, only 0s and 1s): ");
    scanf("%d", &num);

    // logic to convert binary to decimal
    int decimalEquivalent = 0;
    int base = 0;
    while(num > 0){
        int lastDigit = num%10;
        num = num/10;
        decimalEquivalent += pow(2, base) * lastDigit;
        base++;
    }
    printf("The Decimal equivalent is : %d\n", decimalEquivalent);
    return 0;
}
```
Input: 
```bash
Enter the Binary Number(in decimal format, only 0s and 1s): 1100
```
Output: 
```bash
The Decimal equivalent is : 12

```

### (c) Decimal ↔ Octal / Hex
C already provides `%o` and `%x` specifiers:

```c
#include<stdio.h>

int main(){
    int num = 124;
    printf("Octal: %o, Hex(lowercase): %x, Hex(uppercase): %X\n", num, num);
    return 0;
}
```
Output: 
```bash
Octal: 174, Hex(lowercase): 7c, Hex(uppercase): 7C

```

### (d) Octal ↔ Binary / Hex ↔ Binary
First convert to `Decimal`, then to `Binary`.

How to convert to `Decimal` from `Octal` and `Hex`? 
```c
// Run this program by yourself!
#include<stdio.h>

int main(){
    int octal, hex;
    scanf("%o%x", &octal, &hex);
    printf("Octal in decima: %d\n", octal);
    printf("Hex in decimal: %d\n", hex);
    return 0;
}
```
Now we have converted the `Octal` and `Hex` to `Decimal`. We have already seen how to convert `Decimal` to `Binary`.  
Thus, we can convert `Octal` and `Hex` to `Binary`.

## 6. Memory Units (Binary Multiples)
| Unit   | Value        |
|--------|-------------|
| 1 Byte | 8 bits      |
| 1 KB   | 1024 Bytes  |
| 1 MB   | 1024 KB     |
| 1 GB   | 1024 MB     |
| 1 TB   | 1024 GB     |
| 1 PB   | 1024 TB     |

## 7. Reading Articles
A) [Unsigned and Signed Numbers Representation in Binary Number System](https://www.geeksforgeeks.org/digital-logic/basics-of-signed-binary-numbers-of-ranges-of-different-datatypes/)

## 8. MCQs (Multiple Choice Questions)
<span style="color: yellow">Q1. What is the octal equivalent of decimal 65?  
a) 101  
b) 1010  
c) 1011  
d) 1012  
👉 Answer: a) 101

<span style="color: yellow">Q2. Which prefix is used for hexadecimal numbers in C?</span>  
a) 0  
b) 0x   
c) #    
d) &    
👉 Answer: b) 0x

<span style="color: yellow">Q3. What is the binary equivalent of 0xA?</span>   
a) 1111     
b) 1001     
c) 1010     
d) 1100     
👉 Answer: c) 1010

<span style="color: yellow">Q4. What is the decimal value of the binary number 10101?</span>    
a) 20   
b) 21   
c) 22   
d) 23   
👉 Answer: b) 21

<span style="color: yellow">Q5. What does the constant 012 represent in C?</span>  
a) Decimal 12   
b) Hexadecimal 12   
c) Octal 12 (Decimal 10)    
d) Binary 12    
👉 Answer: c) Octal 12 (Decimal 10)

<span style="color: yellow">Q6. Which of the following `was` an invalid constant in C?</span>  
a) 0b1101   
b) 014  
c) 0xF  
d) 25   
👉 Answer: a) 0b1101 (Binary prefix not supported in `old C standards`, but works in `C23 / GCC extension`)

<span style="color: yellow">Q7. What is the decimal equivalent of 0x1F?</span> 
a) 15   
b) 16   
c) 31   
d) 32   
👉 Answer: c) 31

<span style="color: yellow">Q8. If char c = 65;, what will printf("%c", c); print?</span>  
a) 65   
b) A    
c) Error    
d) Depends on compiler  
👉 Answer: b) A

<span style="color: yellow">Q9. What will printf("%d", 010); print?</span>     
a) 10   
b) 8    
c) Error        
d) 16   
👉 Answer: b) 8 (because 010 is octal)

<span style="color: yellow">Q10. What will `printf("%d", 0x10);` print?</span>   
a) 10   
b) 16   
c) Error    
d) 32   
👉 Answer: b) 16

<span style="color: yellow">Q11. What is the decimal equivalent of binary `11111111` (8-bit, unsigned)?</span>   
a) 127  
b) 128  
c) 255  
d) –1   
👉 Answer: c) 255

<span style="color: yellow">Q13. What does 0xFF equal in decimal?</span>   
a) 255  
b) 256  
c) 127  
d) 11111111     
👉 Answer: a) 255

<span style="color: yellow">Q14. Which of the following is the octal representation of decimal 124?</span>     
a) 0174     
b) 174      
c) 0x7C     
d) 124      
👉 Answer: a) 0174

<span style="color: yellow">Q15. What is the output of `printf("%x", 255);`?</span>      
a) 255      
b) FF       
c) 0xFF     
d) ffffffff     
👉 Answer: b) FF

<span style="color: yellow">Q16. What is the binary equivalent of decimal –6 in 8-bit 2’s complement?</span>   
a) 11111010     
b) 00000110     
c) 11100110     
d) 10000110     
👉 Answer: a) 11111010

<span style="color: yellow">Q17. Which of these correctly represents decimal 124 in different number systems?</span>   
a) Binary: 0b1111100, Octal: 0174, Hex: 0x7C    
b) Binary: 0b1111100, Octal: 174, Hex: 7C   
c) Binary: 1111100, Octal: 0b174, Hex: 124  
d) None of the above    
👉 Answer: a) Binary: 0b1111100, Octal: 0174, Hex: 0x7C

<span style="color: yellow">Q18. What will be the output of:</span>
```c
printf("%o", 65);
```
a) 65   
b) 101  
c) 0x41     
d) 41   
👉 Answer: b) 101 (Octal representation of 65)

<span style="color: yellow">Q19. What will be the ouput of:</span>
```c
printf("%d", 0b11);
```
A) 11   
B) 10   
C) 3    
D) 6    
👉 Answer: C) 3, 11 is the binary representation of 3(decimal)

<span style="color: yellow">Q20. What will be the ouput of:</span>
```c
printf("%x", 0b11110);
```
A) 1e        
B) 30   
C) 11    
D) 32    
👉 Answer: A) 1e, 1e is the hexadecimal representation of 30(decimal), 11110 in binary