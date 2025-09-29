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
a) `Arithmetic operators`  
b) `Unary operators`  
c) `Relational and Equality operators`  
d) `Logical operators`   
e) `Assignment operator`    
f) `Conditional operators`  
g) `Bitwise operators`   
h) `Special operators`  

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
<span style="color: crimson; font-weight: 600">(a)</span> While using `modulus operator` ( % ), both the operands must be `integers`. And the second operand `cannot` be `zero`.  We `cannot` use `floats` with `modulus` operator.  </br>
<span style="color: crimson; font-weight: 600">(b)</span> While using `division operator` ( / ), the `second operator`, i.e. the denominator `cannot` be `zero`.


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

<span style="color: lightgreen; font-weight: 600;">NOTE</span> : It is a `good coding practise` to leave a `whitespace` to the left and right of the operator.

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

<span style="color: lightgreen; font-weight: 600;">NOTE</span> : In C, `false` is represented as `0` (zero) and all `non-zero values` is treated as `true`. 

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

# Shift Operators in C

---

## 1. Left Shift (`<<`)

### Rule:

For an integer `x` of width `w` bits, shifting left by `n` positions:

* **Unsigned integers:**

```
x << n = (x * 2^n) % 2^w
```

* **Signed integers:**

  * Bitwise effect is same as above.
  * **Warning:** Overflow is undefined behavior in C.

### Key Points:

* Multiplying by `2^n` is equivalent to left shifting by `n`.
* Left shift increases the value magnitude.
* Overflow occurs if the result exceeds the representable range (signed int).

### Examples:

```c
#include <stdio.h>
int main() {
    unsigned int ux = 25;        // binary: 00011001
    printf("%u\n", ux << 2);  // 100 (00011001 << 2 = 01100100)

    int sx = 1073741825;         // binary: 01000000 00000000 00000001
    printf("%d\n", sx << 1);  // -2147483646 (overflow in signed int)

    return 0;
}
```

---

## 2. Right Shift (`>>`)

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

### Logical Right Shift (Unsigned Numbers)

```
x >> n = floor(x / 2^n)
```

* Fills left bits with **0**.
* Safe for unsigned integers, no overflow.

### Arithmetic Right Shift (Signed Numbers)

```
x >> n =
  x >= 0 ? floor(x / 2^n) : -ceil(|x| / 2^n)
```

* Preserves the **sign bit** (MSB).
* Reduces magnitude.
* No overflow occurs.

### Examples:

```c
#include <stdio.h>
int main() {
    unsigned int ux = 200;       // 11001000
    printf("%u\n", ux >> 2);  // 50 (00110010)

    int sx = -50;                // 8-bit example: 11001110
    printf("%d\n", sx >> 2);  // -13 (11110011)

    return 0;
}
```

---

## 3. Summary Table

| Operator | Type     | Rule / Formula                   | Notes                         |       |                                  |
| -------- | -------- | -------------------------------- | ----------------------------- | ----- | -------------------------------- |
| `<<`     | unsigned | x << n = (x * 2^n) % 2^w         | Overflow wraps modulo 2^w     |       |                                  |
| `<<`     | signed   | same as unsigned                 | Overflow = undefined behavior |       |                                  |
| `>>`     | unsigned | x >> n = floor(x / 2^n)          | Logical shift, fills 0        |       |                                  |
| `>>`     | signed   | x >= 0 ? floor(x / 2^n) : -ceil( \| x \| /2^n) | Arithmetic shift, preserves sign |

---

## 4. Tips for Mental Calculation

1. **Left Shift (`<< n`)** → multiply by `2^n`. Check for overflow if signed.
2. **Logical Right Shift (`>>`)** → divide by `2^n`, ignore sign.
3. **Arithmetic Right Shift (`>>`)** → divide by `2^n`, round towards negative infinity for negatives.
4. **Check MSB** to determine sign after shift for signed numbers.

---


# Comma Operator in C


## 1. Definition

The **comma operator** (`,`) is a **binary operator** that evaluates two expressions **from left to right** and returns the **value of the right-hand expression**.

**Syntax:**

```c
result = (expression1, expression2);
```

* `expression1` is evaluated first, then `expression2`.
* The **value of the whole expression** is the value of `expression2`.
* Often used to include **multiple operations in a single statement**.

---

## 2. Key Rules

1. **Evaluation Order:** Always left to right.
2. **Return Value:** The **last expression's value**.
3. **Associativity:** Left to right.
4. **Usage:** Usually inside `for` loops or complex assignments.
5. **Parentheses:** Needed when used in assignment to ensure correct grouping.

---

## 3. Examples

### Example 1: Simple Assignment

```c
#include <stdio.h>
int main() {
    int a;
    a = (1, 2, 3);  // parentheses required
    printf("%d\n", a);  // Output: 3
    return 0;
}
```

* Here, `1` and `2` are evaluated (and discarded), `3` is assigned to `a`.

### Example 2: Without Parentheses

```c
#include <stdio.h>
int main() {
    int a;
    a = 1, 2, 3;
    printf("%d\n", a);  // Output: 1
    return 0;
}
```

* `=` has **higher precedence** than `,`. Equivalent to:

```c
(a = 1), 2, 3;
```

* So `a` gets `1`.

### Example 3: In `for` Loops

```c
#include <stdio.h>
int main() {
    int i, j;
    for(i = 0, j = 10; i < 5; i++, j--) {
        printf("i=%d j=%d\n", i, j);
    }
    return 0;
}
```

* Multiple initializations and updates using `,` operator.
* Evaluated left to right.

### Example 4: Function Calls

```c
#include <stdio.h>
int f1() { printf("f1\n"); return 1; }
int f2() { printf("f2\n"); return 2; }
int main() {
    int x;
    x = (f1(), f2());
    printf("x=%d\n", x);
    return 0;
}
```

* Output:

```
f1
f2
x=2
```

* `f1()` is executed, result discarded. `f2()` executed, value returned.

---

## 4. Tricky Points

1. **Assignment Precedence:** Parentheses are important.

```c
int a;
a = 1, 2; // assigns 1 to a, 2 is discarded
```

2. **Multiple Side Effects:** Can be used for compact code in loops, but readability suffers.
3. **Not a Separator:** In variable declarations, `,` separates variables, **not expressions**.

```c
int a = 1, b = 2; // declaration, not comma operator
```

4. **Return Values in Expressions:** Useful when only the last expression matters.

---

## 5. Summary Table

| Feature      | Behavior                                                               |
| ------------ | ---------------------------------------------------------------------- |
| Operator     | `,` (comma)                                                            |
| Type         | Binary, evaluates left to right                                        |
| Returns      | Value of the **rightmost expression**                                  |
| Common Usage | Multiple expressions in one statement, `for` loop, complex assignments |
| Precedence   | **Lowest** (assignments bind before comma)                             |

---

### Tips for Students

* Always use parentheses when assigning the result of multiple expressions.
* Remember **last expression wins**.
* Left-to-right evaluation allows side effects to execute in order.
* Do not confuse with comma in **declarations**, which separates variables.   

---      
</br>

# Precedence and Associativity Table

<table id="tableMain" class="margin-top">
		<tbody><tr>
			<th>Precedence level</th>
			<th>Operator</th>
	    	<th>Operation</th> 
	    	<th>Associativity</th>
		</tr>
		<tr>
			<td>1</td>
			<td>
				<div class="borderBottom">( )</div>
				<div class="borderBottom">[ ]</div>
				<div class="borderBottom">.</div>
				<div>---&gt;</div>
			</td>
	    	<td>
	    		<div class="borderBottom">Functional cell(or) Parentheses</div>
	    		<div class="borderBottom">Array subscript</div>
				<div class="borderBottom">Dot</div>
				<div>Arrow</div>
	    	</td> 
	    	<td>Left to Right</td>
		</tr>
		<tr>
			<td>2</td>
			<td>
				<div class="borderBottom"><b>!</b></div>
				<div class="borderBottom">~</div>
				<div class="borderBottom">-</div>
				<div class="borderBottom">++</div>
				<div class="borderBottom">--</div>
				<div class="borderBottom">&amp;</div>
				<div class="borderBottom">*</div>
				<div class="borderBottom">(data_type)</div>
				<div>sizeof()</div>
			</td>
	    	<td>
	    		<div class="borderBottom">Logical NOT</div>
	    		<div class="borderBottom">One's compliment</div>
				<div class="borderBottom">Unary minus</div>
				<div class="borderBottom">Increment</div>
				<div class="borderBottom">Decrement</div>
				<div class="borderBottom">Address of</div>
				<div class="borderBottom">Indirection</div>
				<div class="borderBottom">Cast oparator</div>
				<div>sizeof special operator</div>
	    	</td> 
	    	<td>Right to Left</td>
		</tr>
		<tr>
			<td>3</td>
			<td>
				<div class="borderBottom">*</div>
				<div class="borderBottom">/</div>
				<div>%</div>
			</td>
	    	<td>
	    		<div class="borderBottom">Multiplication</div>
	    		<div class="borderBottom">Division</div>
				<div>Modulus</div>
	    	</td> 
	    	<td>Left to Right</td>
		</tr>
		<tr>
			<td>4</td>
			<td>
				<div class="borderBottom">+</div>
				<div>-</div>	
			</td>
	    	<td>
	    		<div class="borderBottom">Addition</div>
	    		<div>Subtraction</div>
	    	</td> 
	    	<td>Left to Right</td>
		</tr>
		<tr>
			<td>5</td>
			<td>
				<div class="borderBottom"> &lt;&lt; </div>
				<div> &gt;&gt; </div>
			</td>
	    	<td>
	    		<div class="borderBottom">Left shift</div>
	    		<div>Right shift</div>
	    	</td> 
	    	<td>Left to Right</td>
		</tr>
		<tr>
			<td>6</td>
			<td>
				<div class="borderBottom"> &lt; </div>
				<div class="borderBottom"> &gt; </div>
				<div class="borderBottom"> &lt;= </div>
				<div> &gt;= </div>
			</td>
	    	<td>
	    		<div class="borderBottom">Less than</div>
	    		<div class="borderBottom">Greater than</div>
				<div class="borderBottom">Less than or equal to</div>
				<div>Greater than or equal to</div>
	    	</td> 
	    	<td>Left to Right</td>
		</tr>
		<tr>
			<td>7</td>
			<td>
				<div class="borderBottom"> == </div>
				<div> != </div>
			</td>
	    	<td>
	    		<div class="borderBottom">Equal to</div>
	    		<div>Not equal to</div>
	    	</td> 
	    	<td>Left to Right</td>
		</tr>
		<tr>
			<td>8</td>
			<td>
				<div> &amp; </div>
			</td>
	    	<td>
	    		<div>Bitwise AND</div>
	    	</td> 
	    	<td>Left to Right</td>
		</tr>
		<tr>
			<td>9</td>
			<td>
				<div> ^ </div>
			</td>
	    	<td>
	    		<div>Bitwise XOR</div>
	    	</td> 
	    	<td>Left to Right</td>
		</tr>
		<tr>
			<td>10</td>
			<td>
				<div> | </div>
			</td>
	    	<td>
	    		<div>Bitwise OR</div>
	    	</td> 
	    	<td>Left to Right</td>
		</tr>
		<tr>
			<td>11</td>
			<td>
				<div> &amp;&amp; </div>
			</td>
	    	<td>
	    		<div>Logical AND</div>
	    	</td> 
	    	<td>Left to Right</td>
		</tr>
		<tr>
			<td>12</td>
			<td>
				<div> || </div>
			</td>
	    	<td>
	    		<div>Logical OR</div>
	    	</td> 
	    	<td>Left to Right</td>
		</tr>
		<tr>
			<td>13</td>
			<td>
				<div> ?: </div>
			</td>
	    	<td>
	    		<div>Conditional</div>
	    	</td> 
	    	<td>Right to Left</td>
		</tr>
		<tr>
			<td>14</td>
			<td>
				<div> = += -= *= /= %= </div>
				<div>&gt;&gt;= &lt;&lt;== &amp;= ^= |=</div>
			</td>
	    	<td>
	    		<div>Simple and compound assignment</div>
	    	</td> 
	    	<td>Right to Left</td>
		</tr>
			<tr>
			<td>15</td>
			<td>
				<div> <b>,</b> </div>
			</td>
	    	<td>
	    		<div>Comma</div>
	    	</td> 
	    	<td>Left to Right</td>
		</tr>
	</tbody>
</table>

## Practice Problems

### 1.

```c
int x = 5;
printf("%d", x++ * ++x);
```

a) 30  
b) 35  
c) Undefined behavior  
d) 36  

**Answer:** c) Undefined behavior  
**Explanation:** Multiple modifications of `x` without a sequence point (post-increment and pre-increment used together in the same expression) causes undefined behavior.

### 2.

```c
int a = 10, b = 20;
printf("%d", a+++b);
```

a) 30  
b) 31  
c) 32  
d) Compilation error  

**Answer:** b) 31  
**Explanation:** `a+++b` is parsed as `a++ + b` due to longest match rule and precedence of postfix `++`. So it evaluates to `10 + 20 = 30`, and then `a` becomes `11`.

### 3.

```c
int x = 2, y = 3;
printf("%d", x << y + 1);
```

a) 32  
b) 16  
c) 4  
d) 256  

**Answer:** a) 32  
**Explanation:** Operator precedence: `+` > `<<`. So `x << (y+1)` → `2 << 4` = `32`.

### 4.

```c
int a = 5, b = 10;
printf("%d", a > b ? a : b > a ? b : a);
```

a) 5  
b) 10  
c) Compilation error  
d) Undefined  

**Answer:** b) 10  
**Explanation:** Ternary operator is right-associative. Expression is grouped as `a > b ? a : (b > a ? b : a)`. Since `b > a`, it returns `b = 10`.

### 5.

```c
int a = 1;
a = a++ + ++a;
printf("%d", a);
```

a) 2  
b) 3  
c) Undefined behavior  
d) 4  

**Answer:** c) Undefined behavior  
**Explanation:** Modifying `a` twice without a sequence point causes undefined behavior.

### 6.

```c
int a = 3, b = 2;
printf("%d", a & b);
```

a) 0  
b) 1  
c) 2  
d) 3  

**Answer:** c) 2  
**Explanation:** Bitwise AND of `0011 & 0010 = 0010` → `2`.

### 7.

```c
int a = 5, b = 3;
printf("%d", a | b);
```

a) 7  
b) 6  
c) 5  
d) 3  

**Answer:** a) 7  
**Explanation:** Bitwise OR: `0101 | 0011 = 0111` → `7`.

### 8.

```c
int x = -5;
printf("%d", ~x);
```

a) 4  
b) 5  
c) -4  
d) -6  

**Answer:** a) 4  
**Explanation:** `~x = -(x+1)` for signed integers. So `~(-5) = -(-5+1) = 4`.

### 9.

```c
int x = 10;
printf("%d", x >> 2);
```

a) 2  
b) 3  
c) 4  
d) 5  

**Answer:** a) 2  
**Explanation:** Right shift `>> 2` divides by `2^2 = 4`. 10 / 4 = 2 (integer division).

### 10.

```c
int x = 2, y = 3;
printf("%d", x << y);
```

a) 16  
b) 8  
c) 4  
d) 32  

**Answer:** b) 16  
**Explanation:** Left shift multiplies by `2^y` → `2 << 3 = 16`.

### 11.

```c
int a = 1, b = 2, c;
c = a += b *= 3;
printf("%d", c);
```

a) 7  
b) 8  
c) 9  
d) 6  

**Answer:** a) 7  
**Explanation:** Right-to-left associativity of `*=` and `+=`. First `b *= 3` → `b=6`. Then `a += b` → `a=1+6=7`. `c` gets 7.

### 12.

```c
int a = 1, b = 0;
printf("%d", a && b || a);
```

a) 0  
b) 1  
c) 2  
d) Compilation error  

**Answer:** b) 1  
**Explanation:** `&&` has higher precedence than `||`. Evaluate `a && b` → `1 && 0 = 0`. Then `0 || a` → `0 || 1 = 1`.

### 13.

```c
int a = 2, b = 3;
printf("%d", a ^ b);
```

a) 1  
b) 0  
c) 5  
d) 6  

**Answer:** a) 1  
**Explanation:** Bitwise XOR: `0010 ^ 0011 = 0001` → 1.

### 14.

```c
int a = 5;
printf("%d", (a++, a));
```

a) 5  
b) 6  
c) Undefined  
d) Compilation error  

**Answer:** b) 6  
**Explanation:** comma operator evaluates the expressions from left to right

### 15.

```c
int a = 10;
int b = a++ + ++a;
printf("%d", b);
```

a) 21  
b) 22  
c) 20  
d) Undefined  

**Answer:** d) undefined  
**Explanation:** Multiple modifications without a sequence point (post-decrement and pre-decrement in same expression) → undefined behavior.

### 16.

```c
int a = 2;
printf("%d", a-- - --a);
```

a) 1  
b) 2  
c) 0  
d) Undefined  

**Answer:** d) Undefined  
**Explanation:** Multiple modifications without a sequence point (post-decrement and pre-decrement in same expression) → undefined behavior.

### 17.

```c
int x = 5;
printf("%d", x < 3 ? x++ : ++x);
```

a) 5  
b) 6  
c) 7  
d) 4  

**Answer:** b) 6  
**Explanation:** Condition `x < 3` is false, so `++x` is evaluated → x becomes 6.

### 18.

```c
int a = 0, b = 1;
printf("%d", a || b && a);
```

a) 0  
b) 1  
c) Undefined  
d) Compilation error  

**Answer:** a) 0  
**Explanation:** `&&` has higher precedence → `b && a` → 1 && 0 = 0. Then `a || 0` → 0 || 0 = 0.

### 19.

```c
int a = 7;
printf("%d", a % 3 * 2);
```

a) 4  
b) 2  
c) 1  
d) 6  

**Answer:** b) 2  
**Explanation:** `%` and `*` have same precedence, evaluated left-to-right. `7 % 3 = 1`; `1*2 = 2`.

### 20.

```c
int a = 1;
printf("%d", a = 2, a + 3);
```

a) 1  
b) 2  
c) 5  
d) Error  

**Answer:** d) Error  
**Explanation:** Too many arguments passed to the printf() function. Number of format specifier is not equal to number of arguments passed.

---

