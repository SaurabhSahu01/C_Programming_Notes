# Operators in C

Once introduced to variables and constants, we can begin to operate with them by using `operators`. What follows is a complete list of operators. At this point, it is likely not necessary to know all of them, but they are all listed here to also serve as reference.

=> An `operator` is a special symbol used to manipulate data.  
=> The data items that the operators work upon are called `operands`.

```c
x = 10;
```
In the above code snippet, `=` ( assignment operator ) is an operator, while `x` and `10` are the operands.

=> The operator that works on the singe operand is called `unary operator`.  
=> The operator that works on two operands is called `binary operator`.

In C language, we have many types of operators:  
a) <span style="color: yellow;">Arithmetic operators</span>  
b) <span style="color: yellow;">Unary operators</span>  
c) <span style="color: yellow;">Relational and Equality operators</span>  
d) <span style="color: yellow;">Logical operators</span>  
e) <span style="color: yellow;">Assignment operator</span>  
f) <span style="color: yellow;">Conditional operators</span>  
g) <span style="color: yellow;">Bitwise operators</span>  
h) <span style="color: yellow;">Special operators</span>

Let's learn about each types of the operators one by one.

## Arithmetic Operators
| Operator | Description                          |
|----------|--------------------------------------|
| `+`      | Used for addition                    |
| `-`      | Used for subtraction                 |
| `*`      | Used for multiplication              |
| `/`      | Used for division                    |
| `%`      | Remainder / Modulus operator         |


Format : operand1 `operator` operand2

=> Arithmetic operators are applied on `Numeric operands`. Thus the operands could be `integers`, `floats`, or `characters` ( since characters are internally represented by numeric codes - ASCII values).

<span style="color: crimson; font-weight: 800;">CAUTION</span>  
<span style="color: crimson; font-weight: 600">(a) While using `modulus operator` ( % ), both the operands must be `integers`. And the second operand `cannot` be `zero`.  We `cannot` use `floats` with `modulus` operator.  </br>
(b) While using `division operator` ( / ), the `second operator`, i.e. the denominator `cannot` be `zero`.</span>

<span style="color: lightgreen; font-weight: 600;">We will study `Arithmetic Operations` which involves different data types in the `Type Conversion` lecture</span>

## Practice Problems
```c
#include <stdio.h>
void main() {
	int i = -3;
	int k = i % 2;
	printf("%d\n", k);
}
```
`Ouput` : -1  
`Explanation` : In C, the result of % (modulus operator) always has the same sign as the dividend (the left operand).

```c
#include <stdio.h>
void main() {
	int i = 3;
	int k = i % -2;
	printf("%d\n", k);
}
```
`Output`: 1
`Explanation`: Now the sign of dividend is +ve, so the answer will be +ve only.

```c
#include <stdio.h>
int main() {
	int i = 3;
	int a = i / -2;
	int k = i % -2;
	printf("%d %d\n", a, k);
	return 0;
}
```
`Output`: -1 1  
`Explanation`: The logic for division and modulus is very simple. 
In the above example, we have to divide 3 by -2 => -3/2 = -1.5.  
But since, both the operands are int type, the result will be int type and the decimal digits are truncated. Therefore, the result will be -1.  
Now the quotient is -1,  
Remainder = dividend - divisor*quotient   
Remainder = 3 - (-2)*(-1) = 3-2 = 1.  

```c
#include <stdio.h>
void main() {
	int x = 5.3 % 2;
	printf("Value of x = %d", x);
}
```
`Output`: Compile time error  
`Explanation`: We have studied that the operands in the modulus operator ( % ), must be only of the integer type. But 5.3 is not an integer type value, it's a double type value.


## Relational and Equality Operators
`Relational` and `equality` operators are used to `test` or `compare` two `numeric values` or `numeric expressions`.

=> `Relational` and `Equality` operators, when applied on the operands, produce an `integer` value, which is either `0` or `1`.
=> `0` and `1` are often called as `Logical Values`.
=> The value `0` represents `false`, while `1` represents `true`.  

In C, there are four relational and two equality operators as given below:

| Operator | Description                               |
|----------|-------------------------------------------|
| `>`      | Checks for greater-than condition         |
| `>=`     | Checks for greater-than-or-equals condition |
| `<`      | Checks for less-than condition            |
| `<=`     | Checks for less-than-or-equals condition  |
| `==`     | Checks if two values are equal            |
| `!=`     | Checks if two values are unequal          |

Format : Operand1 `Operator` Operand2

<span style="color: lightgreen; font-weight: 600;">`Note`: It is a `good coding practise` to leave a `whitespace` to the left and right of the operator.</span> 

## Practice Problems
```c
#include 
void main() {
	int num1 = 7;
	float num2 = 5.5;
	char ch = 'w';
	printf("Result1 = %d\n", (num1 > 5));
	printf("Result2 = %d\n", ((num1 + num2) <= 10));
	printf("Result3 = %d\n", (ch == 119));
	printf("Result4 = %d\n", (ch != 'p'));
	printf("Result5 = %d\n", (ch >= 10 * (num1 + num2)));
}
```
`Output`:  
Result1 = 1  
Result2 = 0  
Result3 = 1  
Result4 = 1  
Result5 = 0  

`Explanantion`: Self explanatory

```c
#include <stdio.h>
void main() {
	int a = 10, b = 5, c = 5;
	int d;
	d = (a == (b + c));
	printf("%d", d);
}
```
`Output`: 1  
`Explanation`: In the expression `d = (a == (b+c))`, the right hand side expression evaluates to `true`, which is `1` in C. Therefore, `1` is stored in the variable `d`.

```c
#include <stdio.h>
void main() {
	int x = 10;
	printf("%d %d %d\n", x <= 10, x == 40, x >= 10);
}
```
`Output`: 1 0 1  
`Explanation`: Apply the relational operator logic ( very easy )

## Logical Operators
`Logical operators` are used to perform logical operations on the given expressions.  

An expression containing a logical operator returns either 0 (or) 1 depending on the evaluation of the expression to either false or true respectively.  

<span style="color: lightgreen; font-weight: 600;">Note: In C, `false` is represented as `0` (zero) and all `non-zero values` is treated as `true`.</span>  

| Operator | Description  | Meaning                                                                 |
|----------|--------------|-------------------------------------------------------------------------|
| `&&`     | Logical AND  | Returns true when both conditions are true, else returns false          |
| `\|\|`     | Logical OR   | Returns true if at least one of the conditions is true                  |
| `!`      | Logical NOT  | Returns true when the given expression is false, and false when it is true |

### Short-Circuiting in Logical Operators 
| Operator | Short-Circuit Behavior                                                                 |
|----------|----------------------------------------------------------------------------------------|
| `&&`     | If the left-hand side expression is **false**, the result is **false**. The right-hand side expression is **not evaluated**. |
| `\|\|`     | If the left-hand side expression is **true**, the result is **true**. The right-hand side expression is **not evaluated**.  |

### Examples on Short-Circuiting
```c
#include <stdio.h>
int main() {
    int a = 10, b = 0;
    
    // Short-circuit saves us here
    if (b != 0 && (a / b > 1)) {
        printf("Division possible\n");
    } else {
        printf("Division not allowed\n");
    }
    return 0;
}
```
`Output`: Division not allowed  
`Explanation`: a / b is never evaluated because b != 0 is false.

```c
#include <stdio.h>
int main() {
    int x = 5;
    
    if (x > 0 || (x / 0 == 1)) {
        printf("Condition is true\n");
    }
    return 0;
}
```
`Output`: Condition is true  
`Explanation`: The right-hand side (x / 0 == 1) is never executed, avoiding runtime error.

### Practice Problems
```c
#include 
void main() {
	int num1 = 7;
	float num2 = 5.5;
	char ch = 'w';
	printf("Result1 = %d\n", ((num1 >= 6) && (ch == 'w')));
	printf("Result2 = %d\n", ((num2 < 11) && (num1 > 100)));
	printf("Result3 = %d\n", ((ch != 'p') || ((num1 + num2) <= 10)));
	printf("Result4 = %d\n", !(num1 > (num2 +1)));
	printf("Result5 = %d\n", !(num1 <= 3));
}
```
`Output`:  
Result1 = 1  
Result2 = 0  
Result3 = 1  
Result4 = 0  
Result5 = 1  
`Explanation`: Self Explanatory

```c
#include <stdio.h>
void main() {
	int a = 10, b = 5, c = 3;
	b = !a;
	c = !!a;
	printf("%d %d", b, c);
}
```
`Output`: 0 1  
`Explanation`: `a` is 10 initially. Performing `NOT` operation results in `false`, bcz `10` is considered `true`. Now again performing `NOT` on `false` evaluates `1`, which is considered `true`.

```c
#include<stdio.h>
void main() { 
	int i = 10; 
	i = ((!(i > 14)) || (i < 8)); 
	printf("i = %d", i); 
}
```
`Output`: i = 1
`Explanation`: `(i > 14)` evaluates to `0`, which is `false`. Now, `!(i>14)` is `true`, i.e. `1`. Applying the concept of `short-circuiting`, the second expression will never be executed. Thus `i` gets the value of `1`.

# Unary Operators in C

In C, **unary operators** operate on a **single operand**. There are four main unary operators:

| Operator | Description                                |
|----------|--------------------------------------------|
| `+`      | Unary Plus – indicates a positive value    |
| `-`      | Unary Minus – indicates a negative value   |
| `++`     | Increment operator – increases value by 1  |
| `--`     | Decrement operator – decreases value by 1  |

---

## Syntax

- For `+` and `-`: `operatorOperand`
- For `++` and `--`: `operatorOperand // Prefix form`, `operandOperator // Postfix form`  

**Coding convention**: No space should be provided between a unary operator and the operand.  
Example: `-a`, `++i` (✅ Correct)  
Example: `- a`, `++ i` (❌ Not recommended)

Note : We can further classify the increment and decrement operator :  
	1.) post-increment operator  
	2.) post-decrement operator  
	3.) pre-increment operator  
	4.) pre-increment operator  

## Pre-increment & Post-increment
```c
int x = 10;
x++; // post-increment
```
In the above example, we are using the post-increment operator with the variable `x`.

```c
int x = 10;
++x; // pre-increment
```
In the above example, we are using pre-increment operator with the variable `x`.

> Both the operators are incrementing the value of `x` by 1. But, there exists a subtle difference between these two operators.  
`x++` and `++x` can be understood `x = x+1`;

> The major difference between the post-increment and the pre-decrement operator is the `time of updation`.
In the pre-increment, the value of `x` is incremented first and then the expression involving variable `x` is evaluated. But in the post-increment operation, the expression involving the variable `x` is evaluated first and then the value of the variable `x` is incremented.  
Let's understand this by the example, given below.

```c
int x = 10;
int y = x++;
printf("value of x = %d\n", x);
printf("value of y = %d\n", y);
```
Output:  
`value of x = 11`  
`value of y = 10`

**Explanation**: We used the post-increment operator with the variable `x`. In line 2, the expression involving the variable `x` is evaluated first. So, the original value of `x`, that is 10, assigned to the variable `y`. And then the value of `x` is incremented by 1.

Now consider the below example to understand how the pre-increment operator works.

```c
int x = 10;
int y = ++x;
printf("value of x = %d", x);
printf("value of y = %d", y);
```
Output:  
`value of x = 11`  
`value of y = 11`

**Explanation**: You can clearly see here, that the value of `x` is first incremented and then assigned to the variable `y`.

> The same logic works for `pre-decrement` and `post-decrement` operators.

## Practice Problems
```c
#include <stdio.h>
int main() {
	int i = 2, x, y;
	x = 2 * ++i;
	y = 2 * i++;
	printf("%d %d\n", x, y);
	return 0;
}
```
**Output**:  
`6 6`

**Explanation**: In the expression `x = 2 * ++i`, the value of `i` is first incremented, and then the above expression is evaluated using the incremented value of `i`.  
But, in the expression, `y = 2 * i++`, the value of `i` is not incremented first, so the last updated value of `i` is used in this expression.

```c
#include <stdio.h>
void main() {
	int a = 10, b;
	b = a++ + ++a;
	printf("%d %d\n", a, b);
}
```
**Output**:  
`12 22`

**Explanation**: This is very interesting problem. The initial value of `a` is 10. Now look at the expression `b = a++ + ++a`, we are using pre-increment and post-increment operators in the same expression. Now we know that, pre-increment operator will immediately increment the value of `x` by 1, now it's 11. Post-increment operator will increment the value of `x` after the expression has been evaluated. So, the expression will be evaluated using the value of `x` as 11. So, 11 + 11 (22) will be stored in the variable `b`.

```c
#include <stdio.h>
int main() {
	int i = 2;
	i = 3 + 3 * i++;
	printf("%d", i);
	return 0;
}
```
**Output**:  
`9`

**Explanation**: Self explanatory

## Assignment Operator
In C, `=` is the assignment operator. It is the most common and important operator in any programming language.  
It is used to assign a value to a variable. It is used as follows:  
`LHS = RHS; (or) L-value = R-value;`

The `LHS` has to be a `variable` and the `RHS` can be a `value`, `variable`, or an `expression`.

The `L-value` represents the `address` of a `variable` and `R-value` represents the `value` of the `variable` or the `expression`.

**Example**:
```c
int x, y, z;
x = 10;		// variable x is assigned a value 10
y = 20;		// variable y is assigned a value 20
z = x + y;	// variable z is assigned the result of the expression x + y
```

> The compiler verifies the compatibility of types on either side of assignment operator.

> Note : It is a good coding practice to leave a white-space on either sides of the operator to increase the readability.

### Compound Assignment Operators
| Operator | Meaning                | Example               | Equivalent To | Explanation                     |               |                     |
| -------- | ---------------------- | --------------------- | ------------- | ------------------------------- | ------------- | ------------------- |
| `+=`     | Add and assign         | `a += b;`             | `a = a + b;`  | Adds `b` to `a`                 |               |                     |
| `-=`     | Subtract and assign    | `a -= b;`             | `a = a - b;`  | Subtracts `b` from `a`          |               |                     |
| `*=`     | Multiply and assign    | `a *= b;`             | `a = a * b;`  | Multiplies `a` by `b`           |               |                     |
| `/=`     | Divide and assign      | `a /= b;`             | `a = a / b;`  | Divides `a` by `b`              |               |                     |
| `%=`     | Modulus and assign     | `a %= b;`             | `a = a % b;`  | Stores remainder of `a / b`     |               |                     |
| `&=`     | Bitwise AND and assign | `a &= b;`             | `a = a & b;`  | Performs bitwise AND            |               |                     |
`\|=`                         | Bitwise OR and assign | `a            \|= b;`                           | `a = a \| b;` | Performs bitwise OR |
| `^=`     | Bitwise XOR and assign | `a ^= b;`             | `a = a ^ b;`  | Performs bitwise XOR            |               |                     |
| `<<=`    | Left shift and assign  | `a <<= b;`            | `a = a << b;` | Shifts bits of `a` left by `b`  |               |                     |
| `>>=`    | Right shift and assign | `a >>= b;`            | `a = a >> b;` | Shifts bits of `a` right by `b` |               |                     |


**Example**:
```c
int x = 3, y = 4, z = 0;
z += x; // is same as writing z = z + x;
z -= y; // is same as writing z = z - y;
```

**Practice Problems**
```c
#include <stdio.h>
void main() {
	int a = 2, b = 3;
	a = b = 10; // Note this line
	printf("%d %d\n", a, b);
}
```

**Output**: `10 10`
**Explanation**: In the expression `a = b = 10;`, the value `10` is first assigned to the variable `b`, and then the value of variable `b` is assigned to the variable `a`.  
We will get to this example, when we will learn about the `Precedence and Associativity` of the operators.

```c
#include <stdio.h>
void main() {
	int a = 2, b = 3, c = 4;
	a = 7 + (b = 8 + (c = 2)) - 4;
	printf("%d %d %d\n", a, b, c);
}
```
**Output**: `13 10 2`  
**Explanation**: Self explanatory


## Ternary Operator
C language provides an operator to evaluate conditions. It is called a `conditional operator` `(?:)` or a ternary operator.

The syntax for using a `ternary operator` is:
`condition ? expression1 : expression2`

The condition above in the syntax is the logical condition, which must evaluated to 1(true), or 0(false). Based on the true or false value of the codition, expression1 or expression2 is evaluated.

If condition is `true`, then the first expression, `expression1` is evaluated. If the codition is `false`, then the second expression `expression2` is evaluated. 

**Example**
```c
#include 
void main() {
	int age = 12 , eligibility = 18;
	(age < eligibility) ? printf("Not eligible for voting\n") : printf("Eligible for voting\n");
}
```
**Output**: `Not eligible for voting`  
**Explanation**: The conditional expression`(age < eligibility>)` turns out to be true, so the first expression `printf("Not eligible for votind\n")` is evaluated. 

**Question**: Write a program to print the largest number among the two numbers using the `ternary operator`.
**Answer**:
```c
#include<stdio.h>

int main(){
	int num1, num2; // declaration of variables
	scanf("%d%d", &num1, &mum2); // taking input
	int largest = (num1 > num2) ? num1 : num2; // using ternary operator
	printf("The largest value is : %d", largest);
	return 0;
}
```

**Practice Questions**
```c
#include <stdio.h>
void main() {
	int b = 15, c = 5, d = 8, e = 8, result;
	result = b > c ? c > d ? 12 : d > e ? 13 : 14 : 15;
	printf("%d\n", result);
}
```
**Output**: `14`  
In the above program, the expression `result = b > c ? c > d ? 12 : d > e ? 13 : 14 : 15;` can be re-written as `result = (b > c) ? ((c > d ? 12 : d > e) ? 13 : 14 ): 15;`.  
Now, the readability has been increased and we can easily evaluate the nested ternary operators.   

```c
#include <stdio.h>
int main() {
	int k, num = 100;
	k = (num > 50 ? (num <= 10 ? 100 : 200): 500);
	printf("%d %d\n", num, k);
	return 0;
}
```
**Output**: `100 200`
**Explanation**: Self Explanatory


## Bitwise Operators

| Operator | Name        | Meaning                             | Example (a=5, b=3) | Binary Work    | Result                          |
| -------- | ----------- | ----------------------------------- | ------------------ | -------------- | ------------------------------- |
| `&`      | Bitwise AND | 1 if both bits are 1                | `a & b`            | `0101 & 0011`  | `0001 (1)`                      |
| `\|`     | Bitwise OR  | 1 if at least one bit is 1          | `a \| b`           | `0101 \| 0011` | `0111 (7)`                      |
| `^`      | Bitwise XOR | 1 if bits are different             | `a ^ b`            | `0101 ^ 0011`  | `0110 (6)`                      |
| `~`      | Bitwise NOT | Inverts each bit                    | `~a`               | `~0101`        | `…1010` (2’s complement = `-6`) |
| `<<`     | Left Shift  | Shifts bits left, fills 0s on right | `a << 1`           | `0101 << 1`    | `1010 (10)`                     |
| `>>`     | Right Shift | Shifts bits right                   | `a >> 1`           | `0101 >> 1`    | `0010 (2)`                      |

**Example**:
```c
#include <stdio.h>
int main() {
    int a = 5, b = 3;

    printf("a & b = %d\n", a & b);   // 1
    printf("a | b = %d\n", a | b);   // 7
    printf("a ^ b = %d\n", a ^ b);   // 6
    printf("~a = %d\n", ~a);         // -6 (2's complement)
    printf("a << 1 = %d\n", a << 1); // 10
    printf("a >> 1 = %d\n", a >> 1); // 2

    return 0;
}
```

### ✅ Key Points for Students:
1.) `~` (NOT) works differently on signed integers → because of 2’s complement representation.  
2.) `<<` and `>>` shift bits, but `>>` can behave differently on signed numbers (arithmetic vs logical shift).

```c
a = 5 →  0000 0101 (binary, 8 bits shown for simplicity)
~a   →  1111 1010
```
In the above example, `1111 1010` is not just `250`, since the leftmost bit (MSB) is `1`, it's treated as negative number in 2's complement. So `~5 = -6`

**Note**: `~n = -(n+1)`

> `Left shift` works normallly, but there is a catch with the `right shift operator`.

There are two kinds of `right shifts` in computer systems:  
**(A) Logical Right Shift**
- Fills 0 in the leftmost bits.
- Used for unsigned numbers.  
Example with `unsigned int a = 5;`
```c
a = 5 → 0000 0101
a >> 1 → 0000 0010 = 2
```

**(B) Arithmetic Right Shift**
- Fills the leftmost bit with the sign bit (to preserve the number’s sign).
- Used for signed numbers.
Example with `int a = -5;`
```c
a = -5 → 1111 1011 (2’s complement, 8 bits)
a >> 1 → 1111 1101 = -3   (sign bit kept as 1)
```







