# Type Conversion in C


## What is Type Conversion?

Type conversion is changing a value from one data type to another.  
Examples: turning an `int` into a `float`, or a `char` into an `int`.

In C, conversions happen **automatically** (the compiler does it) or **manually** (you ask for it).

---

## Why Type Conversion Matters

- Different types store values differently (integers vs decimals).  
- When you mix types (like `int + float`) the compiler needs rules to decide how to compute a result.  
- Wrong assumptions about conversion cause bugs like incorrect division, wrong comparisons, loss of precision, or strange large numbers when signed values become unsigned.

---

## C Data Types

**Integer types** (store whole numbers):  
- `char` (often 1 byte)  
- `signed char`, `unsigned char`  
- `short` or `short int`  
- `unsigned short`  
- `int`  
- `unsigned int`  
- `long` or `long int`  
- `unsigned long`  
- `long long` or `long long int`  
- `unsigned long long`

**Floating-point types** (store decimals):  
- `float`  
- `double`  
- `long double`

**Note:** The exact size (number of bytes) depends on the system/implementation. For simplicity assume typical 32/64-bit platforms where `int` is 4 bytes.

---

## Two Kinds of Conversion

### 1. Implicit (automatic) conversion
Performed by the compiler when required (also called *type promotion*). Example: `int + double` → the `int` becomes `double` automatically.

### 2. Explicit conversion (casting)
You force the conversion with a cast: `(type)value` — example: `(int)3.9` gives `3` (fraction truncated).

---

## Conversion Hierarchy (including unsigned types)

A simple "size/rank" order that helps decide which type wins in mixed expressions. Put simply, **smaller types get converted to larger types**. This list includes unsigned integer types too (from lower to higher):

```
char / signed char / unsigned char
→ short / unsigned short
→ int / unsigned int
→ long / unsigned long
→ long long / unsigned long long
→ float
→ double
→ long double
```

Important: this is a simplified order. **Signed vs unsigned** complicates decisions — we'll explain the exact rules (below).

---

## Integer Promotions (detailed)

Before many operations, **small integer types** (`char`, `signed char`, `unsigned char`, `short`) are **promoted** to either `int` or `unsigned int`. This is called *integer promotion*.

Rules (simple version):
- If `int` can represent all values of the original type, promote to `int`.
- Otherwise promote to `unsigned int`.

Example: if `char` is 1 byte and `int` is 4 bytes, `char` will become `int` during arithmetic.

Why? It makes arithmetic faster and consistent on many machines.

---

## Usual Arithmetic Conversions (step-by-step)

When two operands in an expression have different types, C applies rules called **usual arithmetic conversions** to find a common type for the operation. Steps (simplified but accurate enough for beginners):

1. **If either operand is `long double` ⇒ convert the other to `long double`.**  
2. Else if either is `double` ⇒ convert the other to `double`.  
3. Else if either is `float` ⇒ convert the other to `float`.  
4. Else (both are integer types) ⇒ do integer promotions (small types become `int` or `unsigned int`). Then:
   - If both after promotion are same type ⇒ use that type.
   - If one is unsigned and the other is signed:
     - If the **unsigned type's rank ≥ signed type's rank** ⇒ convert signed operand to **unsigned** type of higher rank.
     - Else if the signed type can represent all values of the unsigned type (rare) ⇒ convert unsigned to signed.
     - Else convert both to unsigned version of the signed type with greater rank.

**Example (integer):** `unsigned int` and `long` → if `long` rank > `unsigned int` rank, and `long` is signed but can represent all `unsigned int` values? Usually no — result often becomes `unsigned long`. (These rules are fiddly — for most cases you can avoid surprises by keeping types consistent and using casts intentionally.)


## Rules Simplified
### Rule - 1: Small types are promoted to `int`  

- If you use char or short in an expression, C first converts them to int (this is called integer promotion).   
Example:
```c
char c = 10;
short s = 20;
int result = c + s;  // both converted to int before addition
```

### Rule - 2: If types are different, convert to the “higher” type

- C has a hierarchy (from lower → higher precision):
```c
char → short → int → unsigned int → long → unsigned long → long long → unsigned long long → float → double → long double
```

Example: 
```c
int a = 5;
double b = 2.5;
printf("%lf", a + b);  // a converted to double, result is double
```

### Rule - 3: Unsigned vs Signed → Unsigned wins (if same rank)

If you mix a signed and unsigned of the same size, the signed number is converted to unsigned.  
⚠️ This can cause unexpected results.  

Example: 
```c
int a = -5;
unsigned int b = 3;
printf("%u\n", a + b);  // result may look huge (because -5 becomes a big unsigned number)
```

### Rule - 4: Float + Double → Double

When `float` is used in an expression with `double`, `float` gets converted to `double`.

Example: 
```c
float f = 3.2f;
double d = 4.5;
printf("%lf", f + d);  // f converted to double
```

### Rule - 5: Long double dominates

If `long double` is present in an expression, everything else is converted to `long double`.


---

## Assignments and Function Calls

### Assignment
When assigning value of one type to a variable of another type, **conversion happens**. Example:
```c
int i = 257;
char c = i; // value may wrap/truncate depending on char size
```

### Function calls
- For normal functions with parameters of given types, the usual conversions apply when passing arguments.  
- For **variadic functions** (like `printf`), default promotions occur: `float` → `double`, `char`/`short` → `int` (this is why `printf("%lf", 2.5f)` works — the `float` became `double`).

---

## Common Pitfalls and Rules of Thumb

- **Integer division vs floating division:** `5/2` (both ints) → `2`; `5.0/2` or `5/2.0` → `2.5`. Cast one operand to `double` or `float` to get non-integer result.  
- **Signed vs unsigned comparisons can produce surprising results.** If a signed negative is converted to unsigned it becomes a large positive number.  
- **Truncation vs rounding:** casting float/double to int **truncates toward zero**, it does not round.  
- **Format specifiers in `printf`:** must match the argument type or behavior is undefined. Example: passing an `int` and using `%f` is undefined behaviour.  
- **Precision loss:** converting `double` → `float` or `int` may lose information.  
- **Overflow/wrap-around:** assigning big value into small integer type can wrap or overflow.

---

## How Casting Works `(type)expr`

Syntax: `(type) expression` — result is the expression converted to `type`. Examples:
```c
(int)3.9    // becomes 3
(float)5/2  // if written like this, cast applies to 5 and division may still be integer depending on parentheses
(double) (a) / b // recommended: cast one operand to get floating division
```

**Be explicit** and use parentheses: `(double)a / b` — safer and clearer.

---

## Examples with Explanations

### Example 1: Integer division vs cast
```c
int a = 5, b = 2;
double r1 = a / b;          // integer division occurs first ⇒ 2, then converted to 2.0
double r2 = (double)a / b;  // a promoted to double before division ⇒ 2.5
```

### Example 2: char arithmetic
```c
char c = 'A';   // numeric value 65
int x = c + 3;  // c promoted to int ⇒ 65 + 3 = 68
```
`printf("%d", x); // prints 68`

### Example 3: signed vs unsigned
```c
int s = -1;
unsigned int u = 1;
if (s > u) { ... } // s is converted to unsigned (big positive number) ⇒ often true (surprising)
```

---

## Tricky Questions (40) with Answers & Detailed Explanations

> These are ordered from simpler to harder. For each question: code, expected output, and explanation. Try running them on your compiler to see behavior; remember results involving signedness/overflow can be implementation dependent but the explanations show the standard behavior.

---

### Q1
```c
int a = 5;
float b = 2.0;
printf("%f\n", a / b);
```
**Output:** `2.500000`  
**Why:** `a` promoted to `float` → floating division.

---

### Q2
```c
float x = 5/2;
printf("%f\n", x);
```
**Output:** `2.000000`  
**Why:** `5/2` computed as integer division first (2), then converted to float.

---

### Q3
```c
float x = 5.0/2;
printf("%f\n", x);
```
**Output:** `2.500000`  
**Why:** `5.0` is `double` (in C literal), but `5.0/2` becomes `2.5` and assigning to `float` may convert but shows 2.5.

> Note: `5.0` is actually a `double` literal. If you want `float` literal, use `5.0f`.

---

### Q4
```c
int a = 7, b = 2;
printf("%d\n", a / b);
```
**Output:** `3`  
**Why:** Integer division truncates fractional part.

---

### Q5
```c
double d = 10/4;
printf("%lf\n", d);
```
**Output:** `2.000000`  
**Why:** `10/4` is integer division `2`, then stored in `d`.

---

### Q6
```c
int a = 5;
double b = 2;
printf("%lf\n", a / b);
```
**Output:** `2.500000`  
**Why:** `a` promoted to `double`, floating division yields 2.5.

---

### Q7
```c
char c = 'A';
printf("%d\n", c);
```
**Output:** `65` (on ASCII machines)  
**Why:** `printf` with `%d` prints numeric value of `char` after integer promotion.

---

### Q8
```c
char c = 130;
printf("%d\n", c);
```
**Output:** Implementation dependent (if `char` is signed and 1 byte, 130 wraps to -126).  
**Why:** `char` may be signed or unsigned. If signed 1-byte range -128..127 so 130 becomes -126.

---

### Q9
```c
unsigned int u = -1;
printf("%u\n", u);
```
**Output:** `4294967295` (on 32-bit `unsigned int`)  
**Why:** `-1` converted to `unsigned int` produces maximum value (wrap-around).

---

### Q10
```c
int x = 1000;
char c = (char)x;
printf("%d\n", c);
```
**Output:** Implementation dependent; on typical 8-bit `char`: `1000 % 256 = 232` interpreted as signed => `-24`  
**Why:** Value truncated to fit in `char`, may appear negative if `char` is signed.

---

### Q11
```c
float a = 0.1f;
if (a == 0.1) printf("Equal\n");
else printf("Not Equal\n");
```
**Output:** `Not Equal`  
**Why:** `0.1` in code is a `double`. `a` is `float`. `0.1f` cannot represent 0.1 exactly; double literal has different bits. Comparing float (promoted to double) vs double mismatches.

---

### Q12
```c
int a = 3;
float b = 3.0f;
if (a == b) printf("Equal\n");
else printf("Not Equal\n");
```
**Output:** `Equal`  
**Why:** `a` promoted to float and compares equal to `3.0f`.

---

### Q13
```c
int a = -1;
unsigned int u = 1;
if (a > u) printf("a>u\n");
else printf("a<=u\n");
```
**Output:** `a>u` (surprising)  
**Why:** `a` converted to `unsigned int` resulting in a very large number (e.g., `0xFFFFFFFF`) which is greater than 1.

---

### Q14
```c
int a = 5, b = 2;
printf("%lf\n", (double)(a/b));
```
**Output:** `2.000000`  
**Why:** `a/b` is integer division ⇒ 2. Then cast to double gives 2.0.

---

### Q15
```c
int a = 5, b = 2;
printf("%lf\n", (double)a/b);
```
**Output:** `2.500000`  
**Why:** `a` converted to double before division ⇒ floating division.

---

### Q16
```c
char a = 10, b = 20;
char c = a + b;
printf("%d\n", c);
```
**Output:** `30`  
**Why:** `a` and `b` promoted to `int` for the operation; result fits into `char`, then assigned to `c`.

---

### Q17
```c
int i = 1;
float f = 1.0f;
if (i == f) printf("Equal\n");
```
**Output:** `Equal`  
**Why:** `i` promoted to float, equals 1.0.

---

### Q18
```c
double d = 3.9;
int i = (int) d;
printf("%d\n", i);
```
**Output:** `3`  
**Why:** conversion truncates toward zero.

---

### Q19
```c
float f = -3.7f;
int i = (int) f;
printf("%d\n", i);
```
**Output:** `-3`  
**Why:** truncation toward zero. -3.7 ⇒ -3.

---

### Q20
```c
int a = 2147483647; // INT_MAX (32-bit)
int b = a + 1;
printf("%d\n", b);
```
**Output:** Undefined behavior in signed overflow; on many systems wraps to -2147483648 but do not rely on it.  
**Why:** Signed integer overflow is undefined in C.

---

### Q21
```c
unsigned int u = 0;
u = u - 1;
printf("%u\n", u);
```
**Output:** `4294967295` (on 32-bit)  
**Why:** Unsigned wrap-around defined by C (modulo 2^N arithmetic).

---

### Q22
```c
int i = -3;
int r = i % 2;
printf("%d\n", r);
```
**Output:** `-1` (C99 semantics: remainder sign follows numerator)  
**Why:** -3 % 2 ⇒ -1.

---

### Q23
```c
unsigned int u = 2;
int i = -3;
unsigned int r = u + i;
printf("%u\n", r);
```
**Output:** `4294967295` (on 32-bit) or large number  
**Why:** `i` promoted to unsigned producing big positive value; addition wraps modulo.

---

### Q24
```c
int x = 16777217; // > 2^24
float f = x;
printf("%.0f\n", f);
```
**Output:** `16777216`  
**Why:** `float` has 24 bits of precision (mantissa) — cannot represent 16777217, rounds to nearest representable which is 16777216.

---

### Q25
```c
double d = 1.0/10;
printf("%.20lf\n", d);
```
**Output:** shows many digits, e.g. `0.10000000000000000555`  
**Why:** Binary floating point cannot represent 0.1 exactly — small rounding error visible at many digits.

---

### Q26
```c
short s = 32767;
short t = 1;
short r = s + t;
printf("%d\n", r);
```
**Output:** Implementation dependent: typical `-32768` if overflow wraps, but behavior is undefined for signed overflow.  
**Why:** Signed overflow undefined; arithmetic promotes to `int` first then result assigned back to short.

---

### Q27 (Ternary operator type result)
```c
int i = 5;
double d = 4.5;
printf("%lf\n", (i > 3) ? i : d);
```
**Output:** `5.000000`  
**Why:** Second operand `i` is promoted to `double`, result is double.

---

### Q28 (Pointer conversion caution)
```c
int a = 10;
void *p = &a;
int *ip = p; // warning without cast in C++
```
**Output:** (Compiles in C but `int *ip = p;` may give warning in C++; better: `int *ip = (int*)p;`)  
**Why:** `void*` can hold any object pointer in C; converting to another pointer type should be done carefully.

---

### Q29 (printf and default promotions)
```c
float f = 2.5f;
printf("%f\n", f);
```
**Output:** `2.500000`  
**Why:** `float` is promoted to `double` when passed to `printf` (variadic function default promotion).

---

### Q30 (Bitwise and signedness)
```c
int x = -1;
unsigned int y = 1;
unsigned int z = x & y;
printf("%u\n", z);
```
**Output:** `1` (but `x` converted to unsigned yields all bits 1, & 1 → 1)  
**Why:** `x` is converted to unsigned before bitwise operation.

---

### Q31 (Comparisons with mixed types)
```c
long l = 0;
unsigned int u = 1u;
if (l < u) printf("l<u\n"); else printf("l>=u\n");
```
**Output:** depends on sizes — dangerous to mix signed long and unsigned int.  
**Why:** One operand is unsigned; conversions follow usual arithmetic conversions — avoid mixing.

---

### Q32 (Signedness of plain `char`)
```c
char c = 200; // on platforms where char is signed
printf("%d\n", c);
```
**Output:** negative number (e.g., -56)  
**Why:** `char` signed representation wraps if value out of range.

---

### Q33 (Shift operations)
```c
int i = 1;
int r = i << 31;
printf("%d\n", r);
```
**Output:** undefined behavior if shifting into sign bit for signed types; avoid shifting into sign bit of signed types.  
**Why:** Left shifting into sign bit for signed int may be undefined.

---

### Q34 (Large double to int)
```c
double d = 1e20;
int i = (int)d;
printf("%d\n", i);
```
**Output:** Implementation-defined or undefined if value not representable; likely large value or INT_MAX.  
**Why:** Converting out-of-range floating to integer is undefined in C.

---

### Q35 (Order of conversions)
```c
unsigned int u = 4000000000u; // ~4e9
long long x = -1LL;
long long r = x + u;
printf("%lld\n", r);
```
**Output:** depends — mixing signed and unsigned may convert signed to unsigned leading to big positive result.  
**Why:** integer promotion and usual arithmetic conversions apply.

---

### Q36 (Compound assignment)
```c
short s = 1;
s += 100000;
printf("%d\n", s);
```
**Output:** value depends on implementation; `s +=` performs the operation in int then assigns back, conversion/truncation may happen.  
**Why:** Compound assignment uses the usual arithmetic conversions internally then converts result to left operand type.

---

### Q37 (printf mismatch UB)
```c
int a = 10;
printf("%f\n", a);
```
**Output:** Undefined Behavior; likely garbage or crash.  
**Why:** `%f` expects `double` but receiving `int`.

---

### Q38 (Rounding vs truncation)
```c
double d = 2.9999;
int i = (int)d;
printf("%d\n", i);
```
**Output:** `2`  
**Why:** Casting truncates toward zero.

---

### Q39 (Float literal assignment)
```c
float f = 0.123456789f;
printf("%.9f\n", f);
```
**Output:** shows limited precision (about 6-9 significant digits depending on float).  
**Why:** `float` holds ~7 decimal digits precision.

---

### Q40 (Careful with mixed increments)
```c
unsigned int u = 0;
int i = -1;
if (i < u) printf("i < u\n"); else printf("i >= u\n");
```
**Output:** `i >= u` (usually)  
**Why:** `i` converted to unsigned yields very large number > 0.

---

## Summary & Best Practices

- **Prefer consistent types.** Use `int` for integers unless you need specific width (use `int32_t` etc.). Use `double` for floating point if precision matters.  
- **When in doubt, cast explicitly** and document why you cast. `(double)a / b` is clearer than relying on implicit conversions.  
- **Avoid mixing signed and unsigned** types in comparisons/arithmetic. Use signed or unsigned consistently.  
- **Watch `printf` format specifiers** to match argument types.  
- **Remember integer division** truncates; use floating operands if you want fractions.  
- **Truncation is not rounding.** Casting float/double to int throws away fractional part (toward zero).  
- **Be careful with overflow** (signed overflow is undefined; unsigned overflow is defined modulo 2^N).  

---

## Extra exercises (do these on your machine)

1. Print outputs of these and explain:  
   - `printf("%d\n", (int)3.9999);`  
   - `printf("%f\n", (float)1/2);`  
   - `printf("%d\n", (unsigned int)-10);`  
2. Modify code to avoid surprising signed/unsigned comparison.  
3. Show how to force floating division in `int/int` scenario with casting.

---

