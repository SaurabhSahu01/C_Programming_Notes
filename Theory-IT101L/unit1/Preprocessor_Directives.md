# Preprocessor Directives

Upon completing this chapter, you will be able to:
- Describe **Macro Substitution**
- Describe **File Inclusion Directive**
- Determine how **Compiler Control Directives** are used
- Identify the **Preprocessor Directive** introduces as part of **ANSI* additions

## Introduction
C is a unique language in many aspects. One unique feature of the C language is the **preprocessors**.  
The C preprocessor provides several tools that are unavailable in other high-level languages. The programmer can use these tools to make his program easy to **read**, **modify**, **portable**, and **more efficient**.  
 `The preprocessor, as its name implies, is a program that processes the source code before it passes through the compiler.`  
 It operates under the control of what is known as `preprocessor command lines or directives`.  
 `Preprocessor directives are places in the source program before the main line.`  
 Before the source code passes through the compiler, it is examined by the `preprocessor` for any `preprocessor directives`. If there are any, appropriate actions(as per the directives) are taken and then the source program is handed over to the `compiler`.  
 </br>

 **Special syntax rules:**
 1.) They all begin with the symbol `#`.
 2.) Do NOT require semicolon(;) at the end.  

 </br>

 We have already used some preprocessor directive so far, for example, `#include`, and `#define`.

 **Table: Preprocessor Directives**  
 | Directive | Function                  |
|-----------|---------------------------|
| **#define**   | Defines a macro substitution |
| **#include** | Specifies the files to be included |
| **#if** | Tests a compile-time condition |
| **#endif** | Specifies the end of #if |
| **#else** | Specifies alternatives when #if test fails |
| **#ifdef** | Test for macro definition |
| **#ifndef** | Tests whether a macro is not defined |
| **#undef**    | Undefines a macro |  

These `directives` can be divided into `three` categories:   
1.) **Macro Substitution Directives**  
2.) **File Inclusion Directives**  
3.) **Compiler Control Directives** 

## Macro Substitution
`Macro substitution is a process where an identifier in a program is replaced by a predefined string composed of tokens.`  
- `#define`, known as `macro definition`, is used to perform the macro substitution.
- Syntax : `#define identifier string`
- The preprocessor replaces every occurence of the `identifier` in the source code by the `string` associated with the `identifier` in the `macro substitution`.
- There must not be any gap between `#` and `define`.
- The statement `#define identifier string` must not end with `semincolon(;)`.
- There must be at least one gap between `#define`, `identifier`, and the `string`.
- The `string` may be `any text`.
- The `identifier` must be a `valid C name`.  

There are different forms of `Macro Substitution`.  
1.) **Simple Macro Substitution**  
2.) **Argumented Macro Substitution**  
3.) **Nested Macro Substitution**

### Simple Macro Substitution
- Simple string replacement is commonly used to define constants.
- Notice that identifiers are written in `uppercase`. It is a convention used to distinguish `macro substitutions` from normal identifiers.   
- Below are some valid examples of `simple macro substitution`.

```c
#include<stdio.h>
#define M 5
#define PI 3.14159
#define SIZE sizeof(int)*4
#define TWO_PI 2.0*3.14159
#define A 12 + 32
#define D 32 - 12
#define A_BRACKETS (12 + 32)
#define D_BRACKETS (32 - 12)
#define TEST if(x > y)
#define AND
#define PRINT printf("PPS Theory\n");
#define EQUALS ==
#define OR ||
#define MOD %
#define INCREMENT ++
#define BLANK_LINE printf("\n");

int main(){
    int x = 10, y = 5;
    TEST AND PRINT // this will be translated into : if(x > y) printf("PPS Theory\n");
    return 0;
}
```

### Macros with Arguments
- The preprocessor permits us to define more complex and more useful form of replacements.
- Syntax : `#define  identifier(f1, f2, ...., fn)  string`
- Notice that there is no space between the `macro identifier` and the `left parentheses`.
- The identifiers f1, f2, ...., fn are the `formal macro arguments` that are analogous to the `formal arguments` in a `function definition`.
- There is a basic difference between the `simple macro substitution` and the `macro with arguments`. `Macro with arguments` is known as `macro call`, similar to the `function call`.
- When the macro is called, the preprocessor substitutes the string, replacing the formal parameters with the actual parameters.
- Let's understand with examples: 
```c
#include<stdio.h>
#define CUBE(x) (x*x*x)
#define CUBE2(x) ((x)*(x)*(x))

int main(){
    int side = 2;
    int a = 1, b = 1;
    int volume = CUBE(side); // The preprocessor will expand this to (side * side * side)
    volume = CUBE(a+b) // Expands to (a+b * a+b * a+b) -> Notice this will not produce accurate result
    volume = CUBE2(a+b) // Expands to ((a+b) * (a+b) * (a+b))
    return 0;
}
```

Few more examples: 
```c
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(x) (((x) > 0) ? (x) : (-(x)))
```

### Nested Macro Substitutions
- We can also use one macro in the definition of another macro. That is, macro definitions may ne nested. 
- Examples: 
```c
#define M 5
#define N M+1
#define SQUARE(x) ((x) * (x))
#define CUBE(X) (SQUARE(x) * (x))
```
- The preprocessor expands each `#define` macro, until no more macros appear in the text.
- Example: 
```c
// Finding max of 3 numbers
#include<stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MAX_3(x, y, z) MAX(MAX((x) , (y)), (z))

int main(){
    int x = 1, y = 2, z = 3;
    int max = MAX(x, y, z);
    printf("Max = %d", max);
    return 0;
}
```

**Practice Problem**  
Write a C program that implements a macro named GREATER(x, y), which prints TRUE or FALSE depending whether x is greater than y or not.


## File Inclusion
An external file containing functions or macro definitions can be included as a part of the program so that we need not rewrite those functions or macro definitions. This is achieved by the preprocessor directive:  
`#include "filename"`  
where `filename` is the name of the file containing the required definitions or functions.  
At this point, the preprocessor inserts the entire contents of `filename` into the source code of the program.  
When the `filename` is included within the `double quotation` marks, then the search for the file is made first in the `current directory` and then in the `standard directories`.  
Alternatively this directive can take the form:  
`#include <filename>`  
without `double quotation` marks. In this case, the file is searched only in the standard directories.
- Nesting of files is allowed. That is, an included file can inlcude other files.
- A file cannot include itself.
- If an inlcuded file is not found, an `error` is reported and the compilation is terminated.  

Let us assume that we have created the following three files:  
1. syntax.c -> contains syntax definitions
2. stats.c -> contains statistical functions
3. test.c -> contains test functions  

We can make use of a definition of function contained in any of these files by including them in the program as: 
```c
#include <stdio.h>
#include "syntax.c"
#include "stats.c"
#include "test.c"
#define M 5
int main(){
    // code
    return 0;
}
```

- Demonstrate how to include other files in the current source code file.

## Compiler Control Directives
While developing large programs, you may face one or more of the following situations: 
1. You have included a file containing some macro definitions. It is ot known whether a particular macro ( say TEST ) has been defined in that header file. However, you want to be certain that `TEST` is defined(or not defined).
2. Suppose a customer has two different types of computers and you are required to write a program that will run on both the systems. You want to use the same program, although certain lines of code must be different for each system.
3. You are developing a program(say, for sales analysis) for selling in the open market. Some customers may insist on having certain additional features. However, you would like to have a single program that would satisfy both types of customers.
4. Suppose you are in the process of testing your program, which is rather a large one. You would like to have print calls inserted in certain places to display intermediate results and messages in order to trace the flow of execution and errors, if any. Such statements are called `debugging statements`. You want these statements to be a part of the program and to become 'active' only when you decide so.  

One solution to these problems is to develop different programs to suit the needs of different situtations. Another method is to develop a single, comprehensive program that includes all optional codes and then directs the compiler to skip over certain parts of source code when they are not required.  
Fortunately, the C preprocessor offers a feature known as `conditional compilation`, which can be used to `switch` on or off a particular line or group of lines in a program.  

**Situation 1**  
This situation refers to the conditiona definition of a macro. We want to ensure that the macro `TEST` is always defined, irrespective of whether it has been defined in the header file or not. This can be achieved as follows: 
```c
#include "define.h"
#ifndef TEST
#define TEST 1
#endif
```
- `define.h` is the header file that is supposed to contain the definition of `TEST` macro. 
- The directive `#ifndef TEST` searches for the definition of `TEST` in the header file and if not defined, then all the lines between the `#ifndef` and the corresponding `#endif` directive are left active in the program. 

Similar is the case when we want the macro `TEST` never to be defined.
```c
#ifdef TEST
#undef TEST
#endif
```
This ensures that even if the macro `TEST` is defined in the header file, it's definition will be removed. 

**Situation 2**  
```c
#include <stdio.h>

int main(){
    // code
    #ifdef WINDOWS
    {
        // code for windows system
    }
    #else {
        // code for non-windows system
    }
    #endif
    return 0;
}
```

**Situtation 3**  
This is similar to the above situation and therefore the control directives take the following form:
```c
#ifdef ABC
    // group-A lines
#else
    // group-B lines
#endif
```
Group-A lines are included if the customer ABC is defined. Otherwise, group-B lines are included.




