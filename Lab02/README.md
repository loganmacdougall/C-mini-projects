# Introduction

This lab is your first introduction to C programming and will introduce
you to many of the basic concepts of C and low-level coding. By the end
of this lab, you will be expecting to understand the follow key points:

1.  Understanding C libraries.
2.  Understanding functions in C.
3.  Understanding arithmetic in C.
4.  Printing text to stdout in C.
5.  Reading text from stdin in C.
6.  Creating C Source files (.c) and Header files (.h).
7.  Compiling C code.

The proceeding labs will build and expand this knowledge into the realm
of low level computing, including memory management, data structures,
methods for approaching low-level computation, and a variety of other
subjects. As such, knowing these key principles will be important for
future programming and development.

In this lab you are expected to perform the basics of cloning your Lab 2
repository from the GitLab course group. A link to the course group can
be found
[<span style="color: blue">here</span>](https://git.cs.dal.ca/courses/2022-fall/csci-1120)
and your repository can be found in the Lab2 subgroup. See the Lab
Technical Document for more information on using git. You will notice
that your repository has a file in the **Lab2** directory named
**delete_this_file**. Due to the limitations of GitLab, we are not
able to push completely empty directories. Before you push your work to
your repository (which should be in the **Lab2** directory anyway), make
sure to first use the **git rm** command to remove the extra file. If
you do not, your pipeline will fail.

This lab is designed to be learned by breaking it into parts. Work on
each part below **in order** until you are comfortable with the
material. The "Check Your Understanding" sections will give you some
simple problems to implement. The answers to those problems can be found
in the Example Solutions document on Brightspace.

Part 1:
1.  What is a Programming Language?  
2.  Data Types, Keywords, and Language Features  
3.  C Libraries  
4.  Variables and the Main Function  
5.  Input and Output Streams  
6.  **Check Your Understanding - Part 1**

Part 2:
1.  Arithmetic
2.  Functions
3.  Working C Code Example
4.  **Check Your Understanding - Part 2**

Part 3:
1.  Header Files
2.  Compiling C Code
3.  Comparing Your Outputs to Expected Outputs

Part 4:
1.  Lab 2 Function Contracts

{- Do not try to do this lab in one sitting. Follow the parts above and work on a little bit each day. Daily practice is the key to victory. -}
# Table of Contents

[[_TOC_]]


# What is a Programming Language?

A programming language is a set of special commands designed to allow
you to interact with the operating system and hardware without needing
to speak the hardware’s language. As most of you probably know, the CPU
in your computer operates exclusively using **binary**, which is a a way
of representing numerical values using only 0’s and 1’s. Since the CPU
speaks in 0’s and 1’s and you do not, programming languages allow you to
write commands in a format *you* understand and then translate those
programs into the language *the CPU* understands. This allows both you
and the computer to interact in an efficient way.

In order for the translation between your instructions and the CPU’s
binary instructions to take place, programming languages need a piece of
software called a **compiler**. In this course, we will be working with
the C Programming Language, which uses a compiler on Timberlea called
**gcc**, or the **G**NU **C**ompiler **C**ollection. When you run
**gcc** on one of your program source files (as you did with the working
code example above), it takes your source code file and reads it
line-by-line, converting it into a series of binary instructions the CPU
is able to execute. When you run the program, the operating system loads
your program into memory and the CPU runs each binary instruction in
order. For every program you write, those are the steps you will follow: 1) write your code; 2) compile your code; 3) execute your code on the CPU.

While the process is more complex “under the hood", those steps are the
simplest view of the system to follow. In the following sections, we
will give you some examples to try, followed by some simple programming
problems to solve. If you are having trouble with the problems
presented, be sure to reach out to a TA for help!

## Writing and Running your First Program

We’re going to start with very simply writing your first program. You
won’t need to understand what’s happening here in detail, but over the
next few sections it will become more clear. Since you have already done
Lab 1, you should have an understanding of how to edit files using vim,
so we won’t be discussing how to use vim in this document. If you need
more practice, there is a section on vim in the technical document on
Brightspace.

To start, sign in to Timberlea via SSH and create a new directory for
storing code examples. You can make it anywhere you’d like, but name it
something you’ll remember. Once you’ve created that directory, navigate
into it and use vim to create a file named **hello.c**. Once you have
opened this file for editing, you can type the following code into the
editor, then save it and exit:

``` c
// The stdio.h library gives us access to printf.
#include <stdio.h>

// The main function is where every program starts executing.
int main(int argc, char** argv)
{
    // The printf function allows us to write text to the screen.
    printf("Hello World!\n");
    
    // Your main function should return 0 at the end.
    return 0;   
}
```

You have just written your first C program. Congratulations! Now that
you’ve written your program, it’s time to compile it so the computer
understands what we want it to do. It can’t read the code directly, but
if we convert it to binary then the CPU will be able to run our code and
achieve our desired outcome. To compile your program, we will use the
gcc command and provide your source file’s name as an argument. You can
run the following command to compile your code:

``` c
gcc hello.c
```

When you run this command, if it compiles successfully it will not
produce any output. If you’ve written the program as-shown, no errors
should occur. If you receive errors, make sure you’ve written things
correctly. If your problems persist, speak to a TA immediately. Do not
copy and paste any code from this document, as PDFs use fonts and
formatting incompatible with the Unix terminal, and this markdown file was copied from the PDF.

By default, if you do not tell the compiler to name your program
something different, it will compile your program into an executable
binary file called **a.out**. You should use the **ls** command to
ensure the **a.out** file exists after you run **gcc**.

To execute your program, Unix needs to know the path to the file in
question. You may recall from Lab 1 that **./** refers to the current
directory. In order to ensure Unix doesn’t try to look elsewhere for
your program, you will specifically tell it to run the **a.out** by
referring to it in this directory using the **./** path notation. If you
do not use **./**, Unix will likely produce an error. To run your
program, enter the following command into the command line:

``` c
./a.out
```

If your program runs correctly (and it should), you should see "Hello
World!" print to the screen on its own line and you’ve just
successfully run your first C program!

# Data Types, Keywords, and Language Features

Before moving onto coding and using specific features, we have to go
over some of the data types, keywords, and features of the C Programming
Language. Read through this section to get an understanding of how
different types of numbers are stored, reserved language keywords, and a
few other principles. You may need to refer back to this section
throughout this lab, so keep it bookmarked!

The C programming language has a variety of keywords which are reserved
and may only be used for their intended purpose. These reserved keywords
offer a collection of functionality and make up the key building blocks
of your C programs, some of which you will use very regularly, and some
you may never use at all. If you try to name a variable or function
after any of these keywords, the compiler will produce an error tell you
not to use data types or keywords as variable names or function
definitions.

## Data Types

The reserved words you are likely to use the most are related to **data
types**. Since C is **statically typed** (all data is assigned a type
when a program compiles and those types will never change), all of the
data types of variables and values are checked at compile time to ensure
the logic of your code will not fail. This means you will have to be
careful and specific when assigning variable types. However, C has some
methods of "breaking" the static typing rules, such as being able to
push data of one type into another type using pointers. You will see
more on pointers in later courses.

|| **Integer Types**                                                                                             ||
| ---      | ---                                                                               | ---              |
| **Type** | **Values**                                                                        | **Bits (Bytes)** |
| char     | A character, but can also be represented as an integer in \[-128, 127\].          |      8 (1)       |
| short    | An integer in the range \[−32,768, 32,767\].                                      |      16 (2)      |
| int      | An integer in the range \[−2,147,483,648, 2,147,483,647\]                         |      32 (4)      |
| long     | An integer in the range \[−9,223,372,036,854,775,808, 9,223,372,036,854,775,807\] |      64 (8)      |



|| **Floating Point (Real) Types**                                                                                                        ||  
| ---      | ---      | ---                                                                                                                |
| **Type** | **Values**                                                                                                 | **Bits (Bytes)** |
| float  | A real value in the range \[\-3.4028234664e+38, 3.4028234664e+38\].<br>The smallest fraction is +/\-1.1754943508e\-38.    | 32 (4) |
| double | A real value in the range \[\-1.7976931349e+308, 1.7976931349e+308\].<br>The smallest fraction is +/\-2.2250738585e\-308. | 64 (8) |



One of the problems with C (and other languages such as C++) is that
finding a compiler which adheres strictly and exclusively to the C
standard is fairly uncommon. Very often, compiler designers will add
extra features on top of the C standard rules to make coding easier.
These are called **compiler extensions**. The compiler we’re using in
this course is the GNU Compiler Collection (gcc), which compiles C code
by default. The value ranges seen in the tables above are are adherent
to the C standard, but not the minimum C standard, and apply
specifically to the GCC compiler and the underlying Unix system
configuration on our servers. As such, these values are guaranteed on
Timberlea, but not on any other Unix installation or compiler. If you
are writing code with a compiler other than the **gcc** compiler on
Timberlea, we will not help you debug that code (as a rule) and we don’t
promise any of the above values will be correct.

If you’re curious, you can find a list of the GNU compiler extensions
[<span style="color: blue">here</span>](https://gcc.gnu.org/onlinedocs/gcc/C-Extensions.html).

## Keywords

Outside of the data types, the remaining keywords are related to control
structures that give you the core functionality of the language. These
include conditional statements, loops, and some other functionality
related to memory. A table of the various keywords, and their usage, can
be found
[<span style="color: blue">here</span>](https://www.programiz.com/c-programming/list-all-keywords-c-language).
We will introduce many of these keywords in Lab 2 and 3, so don’t feel
that you have to know how to use them all immediately. Just be aware
that you cannot use these words for names of variables or functions.

## Comments

Like most languages, C has comments. Comments are a type of annotation
designed to make the code more meaningful to the reader. In all
solutions, comments will be used to explain most lines of code, or
blocks of code wherein multiple lines have a similar or compound
functionality.

In this class, we will generally expect your code to be commented
line-by-line, or block-by-block, especially if you’re doing something
out of the ordinary. See the final working example code at the end of
these instructions for a good example of proper commenting.

Note that the functions in the **example.c** in Section 10 do not have
function headers, but it can be useful (especially if using a
documentation generator such as Doxygen; not covered in this course, but
useful to check out) to provide function information before the function
in a series of informational comments or a comment block to help a
reader get an immediate understanding of the function’s design.

### Single Line

A single line comment is written using two forward slashes, **// Comment
Here**. It can appear anywhere on a line of code and anything *after it
on the same line* will be ignored by the compiler. There are many
different places where single line comments are used, and often people
will use single line comments for all of their commenting needs, saving
multi line comments for debugging purposes.


``` c
// This is a single line comment. I'm making a variable.
int var = 5;

int a = 16; // This is another comment. This comment has the "read twice" problem.
```

Often you will see comments appear after a line of code (as seen on line
4 above). This can have a negative effect on the reader, as the reader
will often read the code, then read the comment, then read the code
again to confirm what they’ve read. This means that every line could be
read twice and that can be tiresome for large codebases. We recommend
you always put a single line comment above the line you’re explaining.
That way the reader reads the comment, then the code. There’s no
repeating, which makes your code flow better.

### Multi Line

Multi line comments have a start and end pattern, **/\* Comment Here
\*/**. The start and end pattern can appear on different lines in your
code, as long as the start pattern appears before the end pattern. Multi
line comments can also stay on a single line if you want them to.


``` c
/* This is a multi line comment on a single line. I'm making a variable. */
int var = 5;

/* This is a multi line comment on multiple lines. 
   I'm making a variable. */
int a = 16; 
```

Using multi-line comments to “comment out" a piece of code by enclosing
it in the comment patterns is a typical way to temporarily remove code
from the compilation process so a specific piece of code can be executed
and tested. If you use single line comments exclusively throughout your
source files (and we recommend you do), you may find it easier to debug
your code with multi-line comments as you will never run into a
start/end pattern clash.


``` c
// Someday I may need to debug this, so I 
// never use multi line comments to avoid
// clashing the patterns.
int var = 5;
int a = 16 + var;
```

``` c
/* Commenting out the code was easy here.

// Someday I may need to debug this, so I 
// never use multi line comments to avoid
// clashing the patterns.
int var = 5;
int a = 16 + var;

*/
```

``` c
/* This is broken. I'm clashing with the comment I want to keep.

/* Someday I may need to debug this, so I 
 * never use multi line comments to avoid
 * clashing the patterns.
 */
int var = 5;
int a = 16 + var;

*/
```

## C Statements

Each program in C is a collection of computer directions referred to as
**statements**. A statement is a command defined by the C programming
language that, once compiled, will issue direct commands to the CPU to
perform some kind of work. There are many types of statements in C
(expression, selection, etc.), but expression statements are the primary
type we will look at in this lab. Expression statements, in general,
contain an optional expression and must end with a semicolon (;) so that
the compiler understands when the statement is completed. You will see
many examples of expression statements throughout this document, so you
will have many opportunities to see how they are used.

## Strings and Characters

Depending on your past programming knowledge (assuming you have any),
strings and characters may be considered the same thing in certain
languages. In C, this is not the case. A string is exclusively defined
as any text surrounded by double quotes. A character is defined
exclusively by a single character (or escape sequence) surrounded by
single quotes. While there are other ways to initialize characters and
strings, their quotation mark types are not interchangeable.


``` c
char a[] = "This is a string";
char c   = 'A';
```

For this lab, you will only need to know how to use strings in the scope
of **printf** and **scanf**, thus you will not need to know how to work
extensively with strings until Lab 3. They will not be covered in detail 
here.

# C Libraries

The C programming language allows the inclusion of built-in and external
code bases known as libraries. Libraries typically contain a collection
of related functions which can provide additional functionality beyond
the basic C language. Some benefits include the ability to read and
write to files, read from the standard input and output streams, access
to a greater range of math functions, and the ability to manipulate
strings. The libraries below are used very often and would be helpful
libraries to understand throughout this course.

For all of the libraries found below, a simple Google search will yield
many pages outlining their use and the functions they provide. You can
also use the **man** command on Timberlea to get a manual page for any
built-in C library or C function, such as **man math.h** (the C math
library) or **man strlen** (the C String library’s function to get the
length of a string).

## stdio.h

The stdio.h library (standard input/output library) contains functions
which allow you to interact with files and streams (read/write). Notable
functions in this library include printf and scanf for basic writing and
reading to the standard input/output streams, but also fputs and fgets
for allowing buffered writing and reading. This library also contains
functions for converting strings into other data types, such as sscanf.

## stdlib.h

The stdlib.h library (general purpose standard library) contains
functions for general purpose code control, including memory allocation,
direct conversions from strings to other data types (atox functions), a
very sub-par random number generator, the exit and system functions, and
integer math functions. This library will be required in many of the
future labs when dealing with manual memory allocation and pointers.

## math.h

The math.h library contains a variety of more complicated math
functions, such as trigonometric functions, and the floating point
versions of ceiling, floor, log, and power.

## string.h

The string.h library contains functions which allow you to compare and
manipulate strings, which include functions for string comparison,
finding the length of a string, and concatenating two strings together.

## time.h

The time.h library contains functions for managing clock time, dates,
and timers. If you need to time your code (which may happen in second
year), you may want to consider using this library.

# Variables and the Main Function

Your computer is very useful for computing a variety of things, but
without the ability to store any calculations in memory, the system
becomes very limited in its functionality. Therefore, being able to
store things in memory is a keystone feature for any programming
language and any computer system. In the C Programming Language, we
create variables to store data and access data. This data can be
assigned to a variable directly with a constant, storing the result of
an arithmetic calculation, or storing the result of a function call. In
this section we will discuss how to initialize variables, how to store
data in variables, and how to access that data again once we need it.

## The Main Function

Before we can talk about variables and how to use them, we first need to
discuss the **main** function. The main function is incredibly important
for your program to execute properly. When your program is compiled, the
compiler (gcc) is looking through your code for a function named main.
When it finds this function, it sets your program to begin execution
inside this function, which means it is the starting point of your
entire program.

When your program executes, it begins starting at the first line of your
main function’s body and proceeds until the end of the main function’s
body. When it reaches the end, the program will end. If your program
does not have a main function, the compiler will tell you that it
expects a main function, but you have not defined one. When writing your
code, make sure you don’t have any spelling errors, and for the sake of
organization, your main function should be the last function in your
source file. 

You may only have one main function during compilation, across any
number of files being compiled. If you have more than one main function,
the compiler will tell you that there is a duplicate main function and
the compilation process will stop. Check your files and makes sure you
only have one!

### Anatomy of a Starting Program

In the code snippet below, you will see the correct way to format a main
function when preparing a new source code file in this course. We will
discuss the components of functions in a later section, but for now use
this template to start every piece of code that you write until you have
a firm understanding of functions and libraries.

``` c
#include <stdio.h>

int main(int argc, char** argv)
{
    // Your code should be written here.

    return 0;
}
```

Let’s go through this code template step-by-step so you understand
what’s happening:

On line 1, you will notice we use the **#include** command. In C, any
line starting with a # is referred to as a directive, and this
directive is one used to import an external code library. In this case,
it is trying to import **<stdio.h>**. When importing a built-in
library, such as stdio.h, we surround the library name with $`< >`$
to indicate the library is one provided by the compiler. In this case,
stdio.h is the Standard Input/Output C Library. It’s very likely you
will include this library inside any C source file which contains a main
function. Without this library, you cannot write to files and you cannot
print text to the screen, so any calculations being performed could not
be reported to the user in some way without this library. For the time
being, always import this in your C files.

On line 3, you will find the main function definition. This is where you
define the various components of the main function. For now, you don’t
need to know what this means right now, but it should be written this
way every time you write a main function.

On line 4 and 8, you will find curly braces $`\{ \}`$. When you
write any function, such as the main function, the code contained inside
your function’s body will be surrounded by curly braces. The curly
braces actually designate the code inside as a **code block**, which is
a way of sub-dividing your code to make it easier to read and use.

On line 7, you will find the return statement. Functions in C are
capable of returning a value. In the main function, the return statement
is returning a value of 0 to the operating system. When the program
ends, if the operating system receives a return value of 0, then it
knows the program exited successfully. If it receives any other value,
it knows the program exited with a failure state. Your main function
should always return 0 at the end. You’ll also notice this line ends
with a semicolon $`(;)`$. Every C statement (not code block) should end in
with a semicolon, and this is no exception.

On line 5, you will see where your code should be written. Line 5 in
this example will be the first line of code executed by the program, and
it will execute until it reaches the return statement at the end of the
main function’s code block. Any code you write should start here.

## Using Variables

Now that you have an understanding of how your main function should be
structured, we can talk about adding variables to your program.
Variables are a means of storing and accessing data so you can perform
calculations which persist until the end of the program is reached.
Using variables appropriately can allow you to perform arithmetic
calculations easily, which we will discuss later.


### Variable Naming Conventions

There are certain ways C will expect you to name variables, which much
be followed in order to not receive errors during compilation:

1.  A variable may not have the same name as a C keyword.
2.  A variable name may contain characters (uppercase and lowercase), integers, and/or underscores.
3.  A variable name may not start with a number.

Keep your variable names short, but descriptive. While we sometimes use
single letter variable names to provide examples, our solution code (and
your own code) should always have variable names which are descriptive
so we know where values come from and what they’re being used for.
There’s nothing worse than writing code that has six integers named a,
b, c, d, e, f, g and then we have to try to remember what each of them
represents across a variety of calculations.

### Declaring and Initializing Variables

To declare (create) a variable, you must know the type of data you want
to store and have a name for the data in question. Once you know those
things, the format of a variable in code is as follows:

``` c
dataType variableName;
dataType variableName = initialValue;
```

The first type of variable declaration involves C creating memory for
you to store the given data type in, which you can now always refer to
by the variable name. This is the most basic form of variable
declaration and is also the least safe. Because C wants to be as
efficient as possible when creating variables, you cannot guarantee the
starting value of this type of variable declaration. It could be
anything, depending on the situation. As such, the second style of
declaration is universally considered the standard way to declare a
variable.

The second style involves both declaring the variable and setting its
initial value in the same statement. In C, any time we want to perform a
**value assignment**, we use an equals sign $`(=)`$. Much like in common
mathematics, the variable on the left hand side of the equals sign will
be given the value on the right hand side of the equals sign. Here are
some variable declaration examples:

``` c
int badInt;
int value = 15;
char myChar = 'a';
double pi = 3.14;
long bigInt = 274877906944L;
```

The first declaration creates a variable named *badInt*, which is
capable of holding 32-bit integer values, either positive or negative.
It was not initialized with a starting value, which is a bad idea. Try
to avoid this as much as possible.

The second declaration creates a variable named *value*, which is
capable of holding 32-bit integer values, either positive or negative.
It was initialized with a starting value of 15. This is the best way to
initialize variables.

The third declaration creates a variable named *myChar*, which is
capable of holding 8-bit integer values, either positive or negative.
The char data type can also hold characters, which are single numbers,
letters, or symbols surrounded by single quotation marks. It has been
initialized to a character value of ‘a’. We will further discuss how
char types can be represented in Lab 3, but for now you can assume they
always hold a single character.

The fourth declaration creates a variable named *pi*, which is capable
of accurately holding very large real-valued numbers. It has been
initialized to hold 3.14. When initializing a double variable with a
numeric value (not a function call or math formula), remember to put a
lowercase l at the end of the value.

The fifth declaration creates a variable named *bigInt*, which is
capable of holding 64-bit integer values, either positive or negative.
It has been initialized to 274,877,906,944, a value which cannot fit
into an int data type. When initializing a long variable with a numeric
value (not a function call or math formula), remember to put a capital L
at the end of the value.

{- NOTE: -} When first starting out with C, if you need an integer type, use an
**int**. If you need to hold a number with decimal places, use a
**double**. If you need to hold a character, use a **char**. If you need
to hold a string, use a **char[]**.

### Variable Declaration Code Example

As an example of how you might declare variables in actual code, you can
view this code snippet. This code exists purely as an early example, and
we will build on it further as we continue on.

``` c
#include <stdio.h>
 
int main(int argc, char** argv)
{
    char c   = 'a';
    int  i   = 15;
    long l   = 15L;
    float f  = 3.14159;
    double d = 3.14159l;
    char s[] = "Whoa";

    return 0;
}
```

### Assigning Variables and Using Variables

Now that you’ve seen how to create variables, it’s time to see how we
can use them in your programs. The first thing we can do to a variable
at any time is assign it a new value. You can assign new values to
variables using the following format:

``` c
variableName = newValue;
```

Assigning a new value to a variable is much like initializing a variable
when it’s declared. The only difference is that once a variable has been
declared, **it stays the same data type forever**. This means you won’t
have to add the data type to the front of the assignment (as C already
knows its type); you can just assign it a new value by using the equals
sign.

When assigning values to variables, it’s possible to assign a variable’s
value to another variable (or even itself, if that’s what you’re into).
Variable names can be used the same way that constant numerical values
are, where if they appear on the right hand side of the equals sign,
their value is retrieved and used as the value in the variable
assignment. Here are some examples of different variable assignments
(using the same variables declared in the previous example):

``` c
value = 71;
myChar = 'x';
pi = 17.127l;
bigInt = 2000L;
badInt = value;
```

Compare these assignments to the previous example. Since all of their
new values match the variables’ original data types, they should be
updated to the new assigned values without issues.

The fifth assignment in this list contains a variable assignment equal
to another variable. In this case, because the *value* variable should
be holding 71 now, when you perform this assignment, *badInt* will be
assigned an integer value of 71.

### Variable Assignment Code Example

Below we can see how to approach assigning new values to existing
variables. Take a look through the list of variables and see if you can
figure out what their values will be by the end of the program. After
you learn about printing values to the screen in the next section, come
back and try to print the values of each variable on line 10 (after
initialization) and again on line 21 (after the variable values have
been changed).

``` c
#include <stdio.h>
 
int main(int argc, char** argv)
{
    char c   = 'a';
    int  i   = 15;
    long l   = 15L;
    float f  = 3.14159;
    double d = 3.14159l;
    
    c = 'x';
    i = 66;
    l = 281L;;
    f = 16.7;
    d = 28.1l;
    
    char t   = 'p';
    double m = d;
    
    c = t;
    
    return 0;
}
```

## Creating a String Variable

Creating a string variable requires a special formatting of your
variable name, but is still relatively simple. You may have noticed that
we declare strings using $`[`$ $`]`$ on the end of variable names. We
can do this in a few different formats, which we will explain here. For
our purposes in this last, there are two main ways to create a string:
either you can let C figure out how much "capacity" the string has, or
you can declare it yourself.

To create a string, you must declare it using one of the following
formats:

``` c
char str[]   = "This is a string.";
char str[50] = "This is a string.";
char str[50];
```

Format 1 lets C decide the maximum capacity of the string for you based
on the length of the string you’re assigning. In this case, "This is a
string." is 17 characters long, so the maximum capacity of the string
will be 17.

Format 2 lets you declare the maximum size of the string directly. The
number you put inside the square brackets $`([`$ $`])`$  will determine
what the maximum size is. In this case, we are telling C to make us a
string which holds up to 50 characters (although it will actually be 49
in practice; we cover this in Lab 3) and the initial string value should
be "This is a string.".

Format 3 declares a string the same was as format 2, except it does not
have an initial string value. For most purposes, this format creates a
string capable of holding up to 50 characters, but it will not be
assigned a value at declaration. In later parts of these instructions,
you may want to declare a string variable this way if you plan to use
**scanf** to read text into it from the user.

You can see an example of declaring a string in the Section 5.2.2 code
example.

# Input and Output Streams

In the C programming language, the **stdio.h** library provides a
variety of functions for interacting with files and streams, but in this
lab you will only be required to use simple input and output methods. In
future labs you will be expected to understand the stdio.h library much
more comprehensively.

## stdout and stdin

Every operating system controls data streams which the user is able to
interact with. When it comes to printing to the screen (or providing
output to systems outside of your program), the operating system
provides each program with a standard output (shortened to **stdout**)
stream. Whenever your program wants to send text data to the operating
system, it adds it to the stdout data stream. By default, data added to
this stream appears on the terminal screen as printed text. In this
course, the primary method of adding data to the stdout stream will be
with the **printf** function from the stdio.h library.

The operating system also provides your programs with a second stream
for accepting input from outside sources (other programs when using a
Unix pipeline, or user input from a keyboard), referred to as the
standard input (shortened to **stdin**) stream. While your program can
hold data in its stdin stream, it is only actually accessed by your
program when you specifically ask for it. In this course, the primary
method of accessing data from the stdin stream will be with the
**scanf** function from the stdio.h library.

## Printing to stdout

For this lab, you can print to the stdout stream using the **printf**
function, available by including the stdio.h library in your code. When
using printf to print to the screen, you will provide it with a
formatted string, which defines how the provided data will be displayed.
This string may contain any text, escape characters, or format
specifiers. If you include format specifiers, you will also need to
provide printf with a list of variables or values from which to extract
data to be displayed.

### Regular Printing

The default form of printf uses no variables and simply prints a string
to the terminal screen.

``` c
printf("This is a string on your screen!\n");
```

Notice the **\\n** added to the end of the string’s body. In most
programmning languages, you are not able to simply hit enter and
continue writing a string on the assumption that it will add the extra
line break to your text. The C compiler actually attempts to ignore as
much whitespace (spaces, tab spaces, line breaks, etc.) as possible when
compiling your code, which means that information will be lost when your
program compiles.

To get around this limitation, C offers the ability to add **escape
sequences** to your strings. Escape sequences explicitly tell the
compiler which kind of character to place in your string when the escape
sequence is encountered. In the case of the string above, the **\\n**
escape sequence is telling the compiler to add a line break (new line)
at the end of the string. Try writing a program which uses the printf
code above. Compile and run it as shown, then remove the **\\n** from
the string and run it again. You should see a difference in the way your
output is formatted in the terminal.

C is capable of recognizing a variety of escape sequences. The most
common escape characters you’ll likely to use are:

| **Sequence** | **Result**           |
| :----------: | :------------------- |
|     \\n      | New line             |
|     \\t      | Horizontal tab space |
|     \\\\     | Backslash            |
|     \\’      | Single quote         |
|     \\"      | Double quote         |

### Printing Variables and Data

In addition to the default format, printf can also use pattern matching
with codes called **format specifiers**. When constructing the formatted
string for printf, you can add format specifiers which will signify the
**type of data** you want to add to the string at the format specifier’s
location. A list of common format specifiers can be found here:

| **Specifier** | **Data Type**            |
| :-----------: | :----------------------- |
|      %c       | char                     |
|      %d       | decimal integer          |
|      %ld      | long (long int)          |
|      %f       | float (sometimes double) |
|      %lf      | double (long float)      |
|      %s       | string                   |

To use a format specifier in a printf statement, you construct your
fromatted string as normal, but place the format specifier (a percent
sign followed by the desired type signifier) where you expect your data
value to appear. You can have multiple format specifiers in a single
string. Once you have completed your string in the printf statement, you
must follow it with a comma separated list of variable names.

The printf statement will scan through your formatted string from left
to right. When it finds a valid format specifier, it will match it with
the next variable in the variable list you’ve given it. This means the
first format specifier it finds will be matched with the first variable,
the second format specifier will be matched with the second variable,
etc.

Whenever a format specifier is matched, the printf function looks at the
value inside the matched variable and inserts it in the string at the
format specifier’s location. This means a series of C statements which
looks like:

``` c
int A = 12;
int B = 23;
printf("I need %d pieces of cake and %d candles\n", A, B);
```

would print the following string to the screen:

``` c
I need 12 pieces of cake and 23 candles
```

### Data Type Printing Example

An example program for printig values of each of these types is
available below. You will learn more about variables in the next section
of the instructions. For now, this serves as an example of how different
types of data can be printed to the screen using printf.


``` c
#include <stdio.h>
 
int main(int argc, char** argv)
{
    char c   = 'a';
    int  i   = 15;
    long l   = 15L;
    float f  = 3.14159;
    double d = 3.14159l;
    char s[] = "Whoa";

    printf("Char  : %c\n", c);
    printf("Int   : %d\n", d);
    printf("Long  : %ld\n", l);
    printf("Float : %f\n", f);
    printf("Double: %f or %lf\n", d, d);
    printf("String: %s\n", s);
 
    return 0;
}
```

## Reading from stdin

You can accept input from the user via stdin using the **scanf**
function, available by including the stdio.h library in your code. The
scanf function operates in a fashion similar to printf in the way that
it scans through the standard input stream, checking the text for
pattern matches. If it finds a pattern match based on the string you
provide it, it will store the values caught by that pattern in the
variables you provide it. The pattern string scanf uses is constructed
from text and format specifiers from the table above in order to filter
and accept input.

A simple program to read in a single integer and a string from the user
could be:

``` c
#include <stdio.h>

int main(int argc, char** argv)
{
    int var = 0;
    char a[50];

    scanf("%d %s", &var, &a);

    printf("%d\n", var);
    printf("%s\n", a);

    return 0;
}
```

Notice that the scanf and printf are very similar, with one key
difference being the addition of **&** symbols before the variable names
in the scanf variable list. The & symbol is meant to get the memory
address of a variable (referred to as the “Address-of" operator) and has
a variety of uses in C. Since this operator is related to pointers,
which we are not covering in this lab, we will return to it at a later
date (usually second year).

One thing to be aware of with scanf is that it is capable of causing a
**buffer overflow**. A buffer overflow can happen when an array or
string is not allocated enough memory (isn’t long enough) to accommodate
something you’re trying to store inside them. In the case of scanf, if
you create a string variable and try to use %s to store a string from
the user which is too big for your variable, you will end up with
**undefined behaviour**.

If you spend any period of time working with C, you will run into the
phrase “undefined behaviour" often. The C standard has expectations of
what you will do, but doesn’t cover every single possibility. In
situations where the specification does not tell us exactly what
*should* happen, programmers writing compilers will instead do *whatever
they think is most useful*: sometimes that means crashing the program,
sometimes that means giving the action “its best shot" at success,
sometimes it means letting your software do any number of crazy things
such as reading uninitialized memory. One thing that happens on one
system may not happen on another, so be very careful when dealing with
outcomes that are considered undefined!

In the case of scanf on Timberlea, it appears that it goes for the “the
best shot" form of undefined behaviour, where scanf will read the input
from the user and fill your string with as much content as possible
before stopping. This behaviour makes it similar to the **fgets**
function, which is a far safer way of dealing with user and file inputs.
We will talk more about that in the future. For now, try running the
following program and see what output you get if you try to enter more
than 10 characters to the input!

``` c
#include <stdio.h>

int main(int argc, char** argv)
{
    char a[10];

    scanf("%s", &a);

    printf("%s\n", a);

    return 0;
}
```

# Check Your Understanding (Part 1)

We’ve gone through a lot of material so far! Take a break, have a
snack, drink some water. When you come back, sign into Timberlea, and
try to answer the following questions before proceeding to the next
section. Each question should be a separate .c file, just to keep
yourself organized. Make sure you compile and execute your code so you
know that it functions correctly. Solutions for these questions are
available in the Example Solutions document on Brightspace.

1.  Create one integer. Store your current age in the integer. Print your age to the screen.
2.  Ask the user for their age and store it in a variable. Print it to the screen.
3.  We’re going to generate a cool username for the user using their age and their first initial. After asking the user for their age, create a char, then ask the user for their first initial. (Hint: The enter key is also a character, so you’ll have to use `" %c"` when reading in the user’s initial.) Their new username is their first initial, followed by their age. Print their new username to the screen.
4.  It turns out that username was taken. We need to put something more unique on the end. Create a string that can hold 50 characters. Ask the user for their favourite food and store it in the string. Their new, super unique and super cool username is their first initial, followed by their age, followed by their favourite food! Print the super unique and cool username to the screen.

# Arithmetic

Simply being able to assign values to variables and print them to the
screen doesn’t make for very useful programs. One of the main features
of most programming languages is the ability to perform arithmetic
calculations.

The basic arithmetic for C is similar to other languages, where you can
add, subtract, multiply, divide, as well as calculate the division
remainder with the modulus operator. We will go over the basics of
arithmetic here, along with some examples. At the end, you’ll have an
opportunity to try writing some code of your own.

## Performing Basic Calculations

Basic arithmetic in C is performed exactly the same as variable
assignment, except instead of assigning a single variable to a value on
the right side of the equals sign, you assign a variable the result of
an arithmetic formula. Formulas follow the standard rules of
order-of-operations and brackets $`()`$ can be used to force the
system to perform calculations in whatever order you’d like. Arithmetic
operations can be used to initialize a variable or assign it a new value
later. Consider the following basic operations:

``` c
int A = 5 + 4;
myVal = 7 - 3;
value = 14 * 6;
other = 16 / 4;
thing = 17 % 4;
```

These arithmetic operations are relatively straight-forward, but for
completeness sake you can find a list of the operations here:

| **Specifier** | **Data Type**             |
| :-----------: | :------------------------ |
|      \+       | Add (a + b)               |
|      \-       | Subtract (a - b)          |
|      \*       | Multiply (a \* b)         |
|       /       | Divide (a / b)            |
|       %       | Modulus/Remainder (a % b) |

Both numbers and variables can be used as operands in your arithmetic
calculations, and C will always attempt to perform calculations inside
brackets first. You can chain multiple operations together and C will
always try to perform the operations as follows:

1.  Perform any calculations in brackets first. You can put brackets inside brackets; it will start at the innermost brackets and work its way outwards again.
2.  Perform any division, multiplication, or modulus operators from left to right.
3.  Perform any addition or subtraction from left to right.

C differentiates between floating point (real value) arithmetic
operations and integer arithmetic operations. Integer operations are
much faster on the CPU (as a general rule, a floating point addition
takes about 4 times as long as an integer addition), and so it’s useful
for them to be separated. That means you need to pay attention to which
values you’re performing math operations on: if you try to add an
integer and a floating point value together, the CPU *must* use the
floating point arithmetic hardware. Make sure you try to avoid mixing
floating point and integer arithmetic whenever you can. Sometimes it’s
unavoidable, so don’t worry too much if you have to do it.

The operators above will calculate differently depending on the type of
data they’re working on. Any operation performed on an integer will
always return an integer. If an operation on an integer would result in
a fraction/decimal value, C will throw it away, which is the same effect
as rounding down. This means the integer calculation $`5 / 2 = 2`$, not
$`2.5`$ in C. If you perform the floating point calculation
$`5.0 / 2.0`$, you *will* get $`2.5`$. This is an important distinction
to make when you’re coding in C.

Finally, if you’ve never seen the remainder operation before, the $`a % b`$
operation performs the integer division $`a / b`$ and then returns the
remainder. That means $`5 / 2 = 2`$ and $`5 % 2 = 1`$.

Below you will see an example of several math operations. Try running
this code to see what the answers are, then perform the calculations
yourself on paper to confirm. Try changing the variable data types to
see what happens.

``` c
#include <stdio.h>

int main(int argc, char** argv)
{
    int a = 10;
    int b = 4;
    int c = 5;
    int d = 2;

    int m = a + b + 3 % 2;
    int n = d - c + 5 * d;
    int o = (a + b) / 2;
    int p = 1 + (d * (a + c) - (b * c));

    printf("%d %d %d %d\n", m, n, o, p);

    return 0;
}
```

## Increment and Decrement

C also allows you to increment and decrement a value by 1 by using the
**++** and **--** operators. These operators can be placed
before or after a variable in order for you to choose when the increment
or decrement happens. If the operator is before a variable (such as
**++i**), then the value of the variable will be increased or
decreased by 1 *before* the value of the variable is used by your
program.


``` c
// Create an integer variable i and set it to 4.
int i = 4;

// A postfix increment or decrement operation such as this one...
int a = --i;

// ...is equivalent to the following code.
i = i - 1;
int a = i;

// This means a = 3 and i = 3.
```

If the operator is after a variable (such as **i++**), then the
value of the variable will be used by your program before it is
incremented or decremented.  

``` c
// Create an integer variable i and set it to 4.
int i = 4;

// A prefix increment or decrement operation such as this one...
int a = i++;

// ...is equivalent to the following code.
int a = i;
i = i + 1;

// This means a = 4, and i = 5
```

You can use the increment/decrement operators anywhere in your code,
including in other arithmetic operations, such as:

``` c
// Create an integer variable i and set it to 4.
int i = 4;

// Add 
int a = 17 + i++;
int b = 17 + ++i;
int c = 17 + --i;
int d = 17 + i--;

// What are the values of a, b, c, and d?
```

Note that the two above code blocks won’t run, as they are an example
for illustrating a comparison only, however they should be easy to
implement and print the values of if you understand how to structure a
main function.

# Functions

Functions are a special type of code block which, at their most basic
level, allow you to break your code into smaller pieces, which improves
code readability, allows for streamlined code reuse, helps with code
debugging, and reduces the length of your code. The components of a
function declaration can be seen here:  

``` c
ReturnType FunctionName(ParameterList)
{
    FunctionBody
}
```

The individual components of the function are described here:

| **Component**  | **Explanation**                                                                                |
| :------------- | :--------------------------------------------------------------------------------------------- |
| Return Type    | The return type of a function can be any data type. This includes the list provided above, as well as a few others we have not yet introduced, such as structs. The return type may also be a type you have defined yourself. If the return type is void, the function returns nothing. If the return type is not void, there must be at least one return call made in the code body. All return statements in a single function must return the type defined by the return type.    |
| Function Name  | The function name can be anything you’d like, although you should try to make it descrptive enough that you remember what it’s doing when you are reading your code. Like variables, function names in C must meet the required naming conventions.                                 |
| Parameter List | The parameter list is a comma separated list of variable type and name declarations. They must be in the format **dataType variableName** and should follow the C variable naming conventions. These parameters define the type and order of input arguments which must be provided when calling the function elsewhere in your code. If you attempt to pass values of the wrong data type to a function, or you pass them out of order, your compiler will fail.  |
| Function Body  | The function body is a list of C statements which define the behaviour of your function. They are written like any other code, except if your return type is not void, you must include at least one return statement which returns a value of the correct type.                          |

Here we can see the **changeNumber** function definition from the
**example.c** code given in Section 10. The comments have been removed
to keep it concise. The function accepts a single integer argument named
**number**. The function then creates a new integer and performs a
series of arithmetic operations, while using the incoming integer as a
starting point. Once the arithmetic operations are complete, the
function returns the new integer to the calling code.  

``` c
int changeNumber(int number)
{
    int newNumber = number + 15;
    newNumber = newNumber * 12;
    newNumber = newNumber - 15;
    newNumber = newNumber / 5;
    newNumber = newNumber % 150;
    return newNumber;
}
```

Unlike some other languages, when you are writing functions in C, the
order in which they are defined in your code is important. C will
compile the functions in the order in which they are written. If a
function at the top of your source file calls a function at the bottom
of your source file, you will receive an **implicit declaration of
function** error, which will stop your code from compiling. In order to
prevent these, you should create **function prototypes** using forward
declarations. For information on how to do that, check the Header Files
section below.  

## Revisiting the Main Function

As a review, the main function is a special function used in C to define
the starting point of your programs. When you compile, your program, it
must contain a main function and (to follow good practice) it must
minimally be in the following form:  

``` c
int main(int argc, char** argv)
{
    return 0;
}
```

The anatomy of the main function is important, as it relates to the way
the operating system handles program execution. First, the main function
should always accept two parameters: the argument count (argc) and an
array of arguments (argv), in that order. When your program is executed,
it’s possible for a user to provide a list of arguments to your program,
similar to how Unix commands work. The operating system tokenizes the
entire command line execution, stores each token in an array, and then
passes that array into the program as **argv**. You’ll notice that the
data type of argv is **char\*\***, which (for now) can be interpreted
simply as a list of strings. The other argument the operating system
passes to your program is the number of elements in the argv array,
which is provided as an integer we’ve named **argc**. These will be
important in other labs, but for this lab they’re just worth having a
brief understanding of.

Second, the main function should always return an integer. After
execution, your operating system will wait for your program to finish.
Once the program has completed execution, the main function will return
an integer to the operating system, which is then referred to as an
**exit code**. Exit codes are a useful diagnostic tool for the operating
system, as it provides information about whether the program exited in a
success state, or a failure state. Program designers will often
designate their exit codes to be specific reasons for failure, listing
the possible codes in a table which you can reference to understand why
a program execution failed.


## Executing Functions

As it turns out, you’ve been executing functions already in this lab.
Both **printf** and **scanf** are functions, although they have variable
numbers of parameters. Executing your own functions can be performed in
a very similar fashion, but now we need to be sure we account for any
return values your functions might produce.

Consider the following program:

``` c
#include <stdio.h>

int square(int a)
{
    return a * a;
}

int main(int argc, char** argv)
{
    int first = 10;

    int second = square(first);
    int third  = square(5);

    printf("First : %d\n", first);
    printf("Second: %d\n", second);
    printf("Third : %d\n", third);

    return 0;
}
```

We have written a function named **square**, which accepts a single
**int** value and multiplies it by itself. It then returns the result of
that multiplication. The main function creates a **first** variable,
then calls the **square** function, passing the value of **first** into
it as an argument. When square finishes its calculation, the function
will end and 100 will be assigned to **second**. Next, we call
**square** again and pass it the value **5**. When **square** finishes
its calculation, the function will end and 25 will be assigned to
**third**. We then print the value of every variable we created. Try
compiling this code and running it on Timberlea to see the output. Try
adjusting the values of the variables in main and the calculations
performed by the function to see how it affects the output.

Now consider the way you may have written the program without functions:

``` c
#include <stdio.h>

int main(int argc, char** argv)
{
    int first = 10;

    int second = first * first;
    int third  = 5 * 5;

    printf("First : %d\n", first);
    printf("Second: %d\n", second);
    printf("Third : %d\n", third);

    return 0;
}
```

In this situation, writing a function may not have been as useful as you
first expect: the code is shorter overall and the logic has stayed the
same. But what if you wanted to change the functionality from squaring a
number (power of 2) to cubing a number (power of 3). In the original
square function, you could simply add another "\* a" to your arithmetic
and the function would do exactly what you want everywhere you’d call
it. In the rewritten code, without a square function, you now have to do
to every place you squared something and add another multiplication to
it.

This example only has two variables with calculations performed on them,
but what if there were 50? Having to change your code in 50 places
(without missing one or making a mistake!) sounds very tiresome. Using
functions to split your code into smaller pieces that are called
separately makes your code easier to read and easier to fix when
something has to be changed. You’re likely to make a good number of
coding errors over the course of the semester and writing your code in
functions will help you save time trying to fix those errors.


# Working C Code Example

To help you solidify your overall knowledge of C to this point, we’re
providing you with a working example of a relatively simple C program.
The program asks you, the user, for four integers. Once you provide it
those integers by typing them in and pressing Enter, it will print those
integers to the screen as confirmation that they were read in properly.
It runs a math formula on each integer (via a custom function) to change
its value, and then it prints those new values to the screen. Finally,
it changes each of the integers to a string, then attempts to print them
by converting them back into integers, showing some of C’s ability to
convert numbers into text and text into numbers.

Read through the following code, then try running it on Timberlea.
You’ll need to perform the steps of compiling and executing yourself.
See below for a sample output.

## example.c

``` c
// The stdio.h library gives us access to printf and scanf.
#include <stdio.h>

// The stdlib.h library gives us access to atoi.
#include <stdlib.h>

int changeNumber(int number)
{
    // Add 15 to the number.
    int newNumber = number + 15;

    // Multiply the number by 12.
    newNumber = newNumber * 12;
    
    // Subtract 15 from the number.
    newNumber = newNumber - 15;

    // Divide the number by 5. This acts as integer division!
    newNumber = newNumber / 5;

    // Find the remainder of the number divided by 150.
    newNumber = newNumber % 150;

    // Return the new number after calculations.
    return newNumber;
}

int main(int argc, char** argv)
{
    // Create four integer variables.
    int one, two, three, four;

    // Alert the user that they have to enter some numbers.
    printf("Enter four integers: ");

    // Retrieve four integers separated by spaces from stdin.
    scanf("%d %d %d %d", &one, &two, &three, &four);
    
    // Print the four integers to the screen.
    printf("Numbers Received   : %d %d %d %d\n", one, two, three, four);

    // Update each number using the changeNumber function.
    one   = changeNumber(one);
    two   = changeNumber(two);
    three = changeNumber(three);
    four  = changeNumber(four);

    // Print the updated numbers to the screen.
    printf("Updated Numbers    : %d %d %d %d\n", one, two, three, four);

    // Create four string variables, each of length 10.
    char s1[10], s2[10], s3[10], s4[10];

    // Convert the four integers to strings, stored in our string variables.
    printf("Converting integers to strings...");
    sprintf(s1, "%d", one);
    sprintf(s2, "%d", two);
    sprintf(s3, "%d", three);
    sprintf(s4, "%d", four);
    printf(" Done.\n");
    
    // Print the integers from various sources, including a original integer,
    // a string, and two strings converted back to integers.
    printf("Testing AtoI Output: %d %s %d %d\n", atoi(s1), s2, atoi(s3), four);

    // Explicit successful exit code 0.
    return 0;   
}
```

## Output

``` c
Enter four integers: 1 2 3 4
Numbers Received   : 1 2 3 4
Updated Numbers    : 35 37 40 42
Converting integers to strings... Done.
Testing AtoI Output: 35 37 40 42
```

# Check Your Understanding (Part 2)

You got through two more sections! Congratulations! Take another
break, have another snack, drink even more water. When you come back,
sign into Timberlea, and try to answer the following questions before
proceeding to the next section. Each question should be a separate .c
file, just to keep yourself organized. Make sure you compile and execute
your code so you know that it functions correctly. Solutions for these
questions are available in the Example Solutions document on Brighstpace.

1.  Write a main function where you create a double which starts at 1.0. Double it it five times. Each time you double the value, print it to the screen.

2.  Write a program which creates two float variables. The first float variable should store the calculation $`1.0/6.0 + 1.0/6.0`$, which should equal 0.333333 repeating. The second variable should store the calculation $`0.1 + 0.2`$, which should equal 0.3. Compile and run your code to see if you get the right answer. Because floating point precision is not high, you may find you get strange answers if you print those values to 15 decimal places using the `"\%.15f"` format specifier to print them.

3.  Write a function that takes two integers as parameters, adds them together, and returns their sum as an integer. Call your function from the main function and print the result to ensure that it works.

4.  Write a function which accepts an int, a double, and a char, then prints them to the screen. The function doesn't have to return anything. Call your function from the main function to ensure that it works.

5.  Write two functions: <br>`void printMe(int a)`<br>`void mathMe(int a)` <br> The printMe function accepts a single integer and prints it to the screen. The mathMe function accepts a single integer and adds 15 to it, then calls the printMe function by passing the new integer value into it. Call mathMe from the main function with an integer of your choice to ensure it works.

# Header Files

Header files are a means of organizing your code so that both you and
the compiler are capable of better managing function definitions,
macros, and preprocessor definitions. Header files come in two forms and
are imported in different ways.

The first form is the built-in header type we call **libraries**.
Built-in libraries are provided by the C compiler and/or the operating
system and can be imported into your program using the following
command:  

``` c
#include <library.h>
```

The second form of header is the user-created header, which you can
write yourself. A header file written by you should always end with the
**.h** file extension and can include any forward declarations and
macros you desire. To import a user-generated header into your program,
you can use the following command:  

``` c
#include "myHeader.h"
```

Notice that the user-generated header is included in double quotation
marks, not within angle brackets. When you surround your header file
name with double quotes, the C compiler will look for the header files
in the current working directory. If you want to include other
directories for your compiler to look for header files, you will need to
compile using the **-l** option and include file paths to the headers.

## Writing a Header File

Header files are written in a similar fashion to C source files, but
with some changes. Headers should never contain any function bodies or
code statements. Any function declarations in the header file should be
forward declarations only. Preprocessor definitions can be included, and
define guards should be used.

The primary purpose for creating header files is to provide forward
declarations to C source files so that the compiler knows what to
expect, and from where. When C compiles code, it will compile the files
in the order that they are listed in the compiler command, and they will
compile code in order in your files. When a C compiler finds
**#include** statements, it will read those headers and store any
information inside before proceeding through the source while that
imported them.

Under normal circumstances, functions in C are compiled in the order in
which they are found. Sometimes you will create a situation in your code
where functions can have **circular references**, which means that
functionA can call functionB, but functionB can also call functionA. In
this situation, it’s impossible for your code to compile normally. To
alleviate this problem, we can create **forward function declarations**.
A forward declaration is provided to the C compiler before any functions
are implemented (given a function body) which tell the compiler what to
expect in the future.

Consider the following example:  

``` c
int functionA(int a)
{
    if(a <= 0)
        return 5;
    
    return functionC(a-1);
}

int functionB(int b)
{
    return functionA(b-1);
}

int functionC(int c)
{
    return functionB(c-1);
}

int main(int argc, char** argv)
{
    functionA(10);
    return 0;
}
```

In this example, we have a main function which calls functionA with a
value of 10 as the only parameter. If the value coming into functionA is
ever 0 or less, it will return 5 and the cycle of execution will end.
Otherwise A will call C, C will call B, B will call A, and this
execution path will continue forever with the integer argument
decreasing by 1 on every function call.

The problem with this execution is that there is a circular dependency
in the function calls: A needs C to compile, C needs B to compile, and B
needs A to compile. Since there’s no order where we can make each
function appear before each of the other functions, we will need to
create some forward declarations. While it is not strictly *necessary*
to create a forward declaration for every function, it’s good practice
for clarity, so in this course you will forward declare all functions.


``` c
int functionA(int);
int functionB(int);
int functionC(int);

int functionA(int a)
{
    if(a <= 0)
        return 5;
    
    return functionC(a-1);
}

int functionB(int b)
{
    return functionA(b-1);
}

int functionC(int c)
{
    return functionB(c-1);
}

int main(int argc, char** argv)
{
    functionA(10);
    return 0;
}
```

As you can see above, creating a forward declaration is as simple as
declaring the function without a body before any other functions are
implemented. They are represented as a return value, the function name,
and a parameter list in the form of a signature (which is just the list
of types, in order, but which do not require any variable names). Each
forward declaration ends with a semi-colon, as with any C statement.
When the C compiler sees a forward declaration, it will keep a note of
it as it proceeds, so that if it sees your code trying to call that
function, it will remember that you promised it would be implemented
somewhere in the compilation process. If you write a forward declaration
and then never implement (provide a function body for) the function
later, the C linker will fail.

Forward declarations as above are great, but if you have a lot of
functions it will quickly take up a lot of space in your C source files.
This is where you should create a Header file and store your forward
declarations there instead. Let’s take a look at an example of how to do
so here.  

``` c
// functions.h
#ifndef __FUNCTION_HEADER
#define __FUNCTION_HEADER

int functionA(int);
int functionB(int);
int functionC(int);

#endif
```

``` c
// main.c
#include "functions.h"

int functionA(int a)
{
    if(a <= 0)
        return 5;
    
    return functionC(a-1);
}

int functionB(int b)
{
    return functionA(b-1);
}

int functionC(int c)
{
    return functionB(c-1);
}

int main(int argc, char** argv)
{
    functionA(10);
    return 0;
}
```

Starting with the main.c file, we can see that we’ve removed the forward
declarations and added **#include "functions.h"**. This preprocessor
directive will tell the C compiler to scan the function.h file and any
lines it sees will be added directly to this C source file before
continuing. This means it will always compile the header in the place
you’ve added the include directive.

The functions.h file is more interesting. It contains the three forward
declarations as normal, but we’ve also included what’s called a
**header, define, or include guard**. A header guard uses preprocessor
directives to prevent importing the same code too many times, either
explicitly or implicitly, on a per-source file basis. The **#ifndef**
directive says that if the following definition exists (in this case a
definition named **__FUNCTION_HEADER**, but in practice should be a
unique label of your choice for each header file), then we will not scan
any of the code in the if block.

If the definition does not yet exist, then we define it and scan the
forward declarations. In practice, this means that each source file
should only get one copy of the forward declarations added during the
compilation process, and they should always be added as soon as they are
needed by the first include directive. Since C is more than happy to
repeatedly add the same code over and over if you don’t pay attention to
things such as nested include directives, the header guard should at
least help you avoid some unneeded errors.

# Compiling C Code

For the remainder of this course you will be working on writing C
programs, with your primary compiler being **gcc** on the Timberlea
server. This section will provide you with information on how the GNU
Compiler Collection works so you can make the best use of the
programming language throughout this semester.

## Compiling Basics

The most basic form of compilation you can perform with gcc is to simply
provide it a C source file. If you provide a file ending with a .c
extension, it will compile it in C mode.


``` 
gcc file.c
```

In most beginner circumstances, your code will compile fine if you run
it this way. By default, version 10 of gcc will use a custom GNU17
standard to compile your code. To ensure explicit compatibility (because
gcc changes its default standard occasionally in new versions), we will
compile your code with the C18 standard in these labs. If you want to
simulate that in your own testing, you will have to tell gcc to use that
standard specifically. To do so, you can use the **--std**
command:  

``` 
gcc --std=c18 file.c
```

This will force your code to compile to the C18 standard and, by
default, will produce an executable file named **a.out**. In order for
you to execute your program, your **a.out** file will need user
executable permissions. It should also have those by default, but if it
does not you can use **chmod** to set the permissions to whatever you’d
like. If you’d like your compiled code executable to have a nicer name,
you can use the **-o** option with gcc to have it name the executable
something different:

``` 
gcc --std=c18 file.c -o execute_me
```

Instead of a.out, this will produce an executable called
**execute_me**. To run any of your compiled programs, you can tell Unix
to run them directly with **./execute_me**, **./a.out**, or by
attaching **./** to whichever name you’ve given the executable file.

## Steps of Compilation

In general, there are only a few major steps in compiling your code: the
**preprocessor**, the **compiler**, the **assembler**, and the
**linker**. These steps are taken in the order shown here, controlled
completely by your compiler software. Note that we often refer to the
entire process as compilation, and the program which makes it happen a
compiler. Don’t get this confused with the compilation step!

Be aware that the C compiler makes a single pass through your code,
unlike other some other programming languages. This limitation is the
reason why we need header files and forward function declarations in
order to let the C compiler know about things it should expect to see.

{- NOTE: -} It is not necessary for you to perform these steps when compiling your
code. They are included here for informational purposes. It’s useful to
know the steps your compiler is taking to turn your code into
machine-executable binary.

### Preprocessor

The preprocessing section of the C compiler looks for any preprocessor
directives (which start with a #) and enforce them. During this process
it will keep track of any function declarations or data types that are
necessary for the compiling step. If it detects any incorrect ordering
of variables, data types, or functions, it will cause an error here.

If you want to stop the compilation process and have GCC provide you the
preprocessor file (assuming it was successfully created), you can
execute gcc with the **-E** option.

``` 
gcc --std=c18 -E file.c
```

Note that this command will likely just print the preprocessor output to
your screen. If you want to be able to sort through it manually, I would
suggest piping the output into the **less** program. Alternatively, you
can use file redirection to save it in a file, or use the **-o** option
to have it save to a specific filename.

### Compiler

The compiler section of the compilation process views the preprocessor
outputs and converts your program to assembly code. Sometimes you will
see the compiler and the assembler represented as just the compiler
(thus making this a three stage process), but it’s worth differentiating
them here. If you would like to see the assembly code generated by the
compiler, you can use the **-S** option.

``` 
gcc --std=c18 -S file.c
```

This will automatically generate a **file.s** assembly code file that
you can view.

### Assembler

The assembler section of the compilation process converts the assembly
code generated by the compiler into a binary object file. Note that if
you provide multiple source files in your compiler command, it will
generate an object file for each one separately before pushing them to
the linker. The binary object file contains all of the machine code
specifically designed to run on your compiled operating system. Since
assembly can differ by system, your machine code may not necessarily run
on another machine.

If you want to generate a binary object file without linking it, you can
use the **-c** option on your compiler.

``` 
gcc --std=c18 -c file.c
```

This will automatically generate a **file.o** object file. Since it is
in binary, it will be impossible to read with regular text editors. In
the labs, all of our test files will be accompanied by a .o object file
containing a main method and forward declarations based on the coding
contracts provided.

## Compiling with Libraries

Some libraries require you to tell the compiler to load them during
compilation time. For example, the math.h library requires gcc to be
executed with the **-lm** (or **-lmath**) option on the end of your gcc
command. If you are having trouble compiling with some built in
libraries, check online or the library’s **man** page to determine if
you need to enable additional options on your compiler.

## Compiling Lab Object Files

In the lab section of this course, you will be given the option to test
your code with a variety of our test object files. **Do not confuse
these with objects from object-oriented languages**, such as Java or
Python. C object files contain pre-compiled binary code which you can
compile with your own programs and are easily identified by their **.o**
extension. Our test objects will be provided to you in the
**CI/objects/** directory of your repository.

Each object file will be compiled on Timberlea and will contain a main
method with a selection of test cases for the functions you have to
write. It will have been compiled with a header file dictating forward
function declarations which match the relevant coding contracts. In
order for you to test your functions with our object files, you must
select the correct object file (as per the contract instructions) and
compile it together with your code using the following gcc command:

``` 
gcc --std=c18 contract.c contractM.o
```

Note that the names of the files will be slightly different, but the
process is the same. This should compile and generate the **./a.out**
file as normal. As mentioned in this section, you can feel free to use
the **-o** option to have the compiler rename your executable. This same
test file will be used in the pipeline for each of your submissions, but
the option is available for you to test offline using this method.

The object files provided by us contain everything your program will
need to properly execute if compiled the same as the above example.
Because they already know which functions to expect from your code, not
providing every required function in a contract will produce errors
letting you know that a function was promised, but never implemented. If
you try to compile your code along with one of the provided object files
and you get those errors, make sure you check that you have provided
function implementations (actual coded logic) for each required function
and ensure your **.c** file is being compiled properly with the **.o**
file.

# Comparing Your Outputs to Expected Outputs

In this lab (and beyond) we will provide you with expected output files,
which are used in the pipeline to determine if your program’s output
matches the correct output. This is done in a single Unix if statement,
where we use the diff command and wc command to decide whether or not
your output is valid.

The **diff** command tells you the difference between two files. If two
files are exactly the same, the diff command produces no output.
Otherwise it lists which lines are different in each file. Check the
**man** page for diff, or the internet, for more information. It’s a
very well-documented command.

The **wc** command outputs word, line, and character counts across a
series of files or text input. We specifically use the **-c** option so
that it will return a single value, which is the number of characters
(bytes) in the input. Again, the **man** page and internet documentation
for wc is extensive.

The testing section of the pipeline script performs a **diff** on your
output file and the expected output file. It then takes the output from
diff and pipes it into **wc -c**, which returns the number of characters
in the diff’s output. If that number is greater than 0, then that means
it found at least one line in your output that doesn’t match the
expected output. You can run the same commands via the terminal, and you
are provided the expected files in the **CI/** directory of your
repository. If your pipeline fails on that check, we suggest viewing the
diff output of your output files to see where you’re going wrong.

If **diff** does not give you enough information about your outputs, the
**cmp** program can tell you the first byte where two files are
different. Since each character is a byte, it will let you know the
first character that’s incorrect. This should help you track down any
issues in your print statements so you can make sure the outputs
match.

**If you are having pipeline failures, but it appears that your output
values are correct, double check your use of whitespace and new lines by
using diff. It could save you a lot of headaches and disappointment!**

# Lab 2 Function Contracts

In this lab you will be responsible for fulfilling three lab contracts:
the **Coins** contract, the **Power Rule** contract, and the
**Triangle** contract. Each contract is designed to test you on some of
the things you’ve learned throughout the instruction portion of this
lab.  

All contracts must be completed exactly as the requirements are laid
out. Be very careful to thoroughly read the contract instructions before
proceeding.  

All contracts are designed to be submitted without a main function, but
that does not mean you cannot write a main function in order to test
your code yourself while you’re writing your programs. It may be more
convenient for you to write a C source file with a main function by
itself and take advantage of the compiler’s ability to link files
together by accepting multiple source files as inputs. When you push
your code to Gitlab, you don’t need to <kbd>git add</kbd> any of your extra
main function source files.  

For those of you who are concerned, when deciding which naming
conventions you want to use in your code, favour consistency in style,
not dedication to a style that doesn’t work.  

The contracts in this document are worth the following points values, 
for a total of 10.

| Contract  | Points |
| ------    | ------ |
| Coins     | 2      |
| Power     | 3      |
| Triangle  | 5      |
| **Total** | 10     |

## Coins

### Problem

You are given a number of pennies between 0 and 10000 (inclusive). How
much money do we have if we convert the pennies to higher denominations,
such that we have as many dollars as possible, followed by as many
quarters as possible, then as many dimes as possible? How many pennies
are left over?

### Preconditions

You must provide a function which meets the requirements in the table
below. You you may include other functions as long as the requested
function executes correctly. Do not include a main function in your
source or header files.

| **Requirement**  | **Conditions**                                                                         |
| :--------------- | :------------------------------------------------------------------------------------- |
| Function         | void calculateCoins(int)                                                               |
| Input Parameters | Your function should accept a single integer, which represents some number of pennies. The integer provided is guaranteed to be in the range \[0, 10000\].|
| Return Value     | Your function should not return a value.                                               |
| Files Required   | coins.c, coins.h                                                                       |

### Postconditions

Your function must output to the standard output stream. The output must
print the number of coins of each type in descending order by largest
denomination. Your output must be terminated with a new line character.

### Restrictions

You should not use any C statements or structures not introduced in this
lab, which includes (but is not limited to) conditional statements and
loops.

**Important Note:** The current pipeline scripts do not test if you
are meeting the restrictions, but any practicum marking scripts will.
If a practicum tells you not to use a code feature and the marking
script catches you, that will yield a 0 on that question.

### File Requirements

This contract requires you to provide a C source file named `coins.c`
and a C header file named `coins.h`. Your header file should contain
your forward declarations. Your source file must not contain a main
function, or it will fail during testing.  

Your source and header files should be placed in the `Lab2/coins/`
directory in your GitLab repository.

### Testing

To test your code, you can compile your source file with the
`coinsM.o` object file found in `CI/objects/coins/`. It can then be
executed as normal. The `coinsM.o` file contains a main function, so you
do not need to provide one.

### Sample Inputs and Outputs

| **Input**            | **Output**                                            |
| :------------------- | :---------------------------------------------------- |
| calculateCoins(1)    | 0 dollars, 0 quarters, 0 dimes, 0 nickels, 1 pennies  |
| calculateCoins(1999) | 19 dollars, 3 quarters, 2 dimes, 0 nickels, 4 pennies |
| calculateCoins(2000) | 20 dollars, 0 quarters, 0 dimes, 0 nickels, 0 pennies |
| calculateCoins(1850) | 18 dollars, 2 quarters, 0 dimes, 0 nickels, 0 pennies |

## Power Rule

### Problem

Given a polynomial, use the power rule to find the first derivative.

### Preconditions

You must provide a series of functions which meet the requirements in
the table below. You you may include other functions as long as the
requested functions execute correctly. Do not include a main function in
your source or header files.  

Each of your functions represents a polynomial of the degree included in
its name. For example, **powerRule2** represents a power rule being
applied to a polynomial of degree 2, which means its term with the
largest exponent is 2. If you are not sure what the power rule is, a
quick Google search will give you the formula.

| **Requirement**  | **Conditions**                                                                      |
| :--------------- | :---------------------------------------------------------------------------------- |
| Functions        | void powerRule1(int, int) <br> void powerRule2(int, int, int) <br> void powerRule3(int, int, int, int) <br>  void powerRule4(int, int, int, int, int) |
| Input Parameters | You are given a series of positive integers which represent the coefficients of the terms of the function’s related polynomial, from highest degree term to the lowest. For example, powerRule2’s related polynomial would be of the form: <br><br>$`(ax^2 + bx^1 + cx^0)`$ <br><br>  which means we would call the function as **powerRule2(a, b, c)**. |
| Return Value     | Your function should not return a value.                                            |
| Files Required   | `power.c`, `power.h`                                                                    |

### Postconditions

Your function must output to the standard output stream. The output must
print each derivative term, separated by plus signs (+) and the output
must be terminated with a new line character. Each plus sign should have
a single space on either side. You must use the hat character (^) to
signify an exponent, but you should not print an exponent unless it is
greater than 1. If you have a term with a zero exponent, you should only
print the coefficient.

### Restrictions

You may not use any C statements or structures not introduced in this
lab, which includes (but is not limited to) conditional statements and
loops.  

**Important Note:** The current pipeline scripts do not test if you
are meeting the restrictions, but any practicum marking scripts will.
If a practicum tells you not to use a code feature and the marking
script catches you, that will yield a 0 on that question.

### File Requirements

This contract requires you to provide a C source file named `power.c`
and a C header file named `power.h`. Your header file should contain
your forward declarations. Your source file must not contain a main
function, or it will fail during testing.  

Your source and header files should be placed in the `Lab2/power/`
directory in your GitLab repository.

### Testing

To test your code, you can compile your source file with the
`powerM.o` object file found in `CI/objects/power/`. It can then be
executed as normal.

### Sample Inputs and Outputs

| **Input**                  | **Output**             |
| :------------------------- | :--------------------- |
| powerRule4(4, 3, 10, 4, 5) | 16x^3 + 9x^2 + 20x + 4 |
| powerRule4(1, 12, 1, 2, 2) | 4x^3 + 36x^2 + 2x + 2  |
| powerRule2(1, 2, 3)        | 2x + 2                 |

## Triangles

![image](CI/docs/triangle_good.png)

### Problem

Given a right triangle, the length of two of its sides, and the interior
angles in radians, find the length of the missing side. Input will
always be given in the order of (opposite, adjacent, hypotenuse, x, y),
with the missing side omitted. In this challenge, you will be writing
functions to find the missing side length using both the Pythagorean
theorem and by using trigonometry. Then, print the dimensions of all
three sides, and both angles. The block of dimensions should start and
end with a new line.

### Preconditions

You must provide a series of functions which meet the requirements in
the table below. You you may include other functions as long as the
requested functions execute correctly. Do not include a main function in
your source or header files.

:exclamation: :boom: $`\textcolor{red}{\text{In this contract, are you are only able to use a single printf statement (or equivalent) in any of your files.}}`$ 
$`\textcolor{red}{\text{It is important you follow this restriction. If you do not follow this restriction (or a similar restriction on a practicum), you will receive a grade of 0 for this contract.}}`$

Each function asks you to find the opposite, adjacent, or hypotenuse
using either the Pythagorean theorem (Pyth) or trigonometry (Trig).
These functions will be checked to ensure proper math functions are
used. Math functions can be found in the `math.h` library.

| **Requirement**  | **Conditions**                                                                          |
| :--------------- | :-------------------------------------------------------------------------------------- |
| Functions        | double findOppositePyth(double, double, double, double) <br>double findAdjacentPyth(double, double, double, double) <br>double findHypotenusePyth(double, double, double, double) <br>double findOppositeTrig(double, double, double, double) <br>double findAdjacentTrig(double, double, double, double) <br>double findHypotenuseTrig(double, double, double, double)                               |
| Input Parameters | You are given a series of positive double floating point values which represent the sides and angles of a right triangle. The values correspond to the triangle diagram provided above, such that the values will always be in the order (a, b, c, x, y). The only difference between inputs on the various functions is that the side in the name will be missing, thus only providing you four values. Those four values still remain in the same order, so, for example, if you are calling *findOppositePyth*, the function arguments you receive will be (b, c, x, y), as the opposite side (a) needs to be calculated.|
| Return Value     | Your function should return a double floating point value representing the length of the missing side of the triangle. |
| Files Required   | `triangle.c`, `triangle.h`                                                                  |

### Postconditions

Your function must output to the standard output stream, but it may only
do so once per function call. The output consists of seven lines: a
blank line, a line containing the value of the opposite side, a line
containing the value of the adjacent side, a line containing the value
of the hypotenuse, a line containing the value of the x angle, a line
containing the value of the y angle, and another blank line. Each line
with a value must include the name of the value and an equals sign (=).
When printing your double values to the screen, you should print them to
two decimal places. **This is not necessarily the same as rounding!**
Make sure you research floating point format specifiers with **printf**
and how to limit the number of decimal places printed.

### Restrictions

You may not use any C statements or structures not introduced in this
lab, which includes (but is not limited to) conditional statements and
loops.

**Important Note:** The current pipeline scripts do not test if you
are meeting the restrictions, but any practicum marking scripts will.
If a practicum tells you not to use a code feature and the marking
script catches you, that will yield a 0 on that question.

### File Requirements

This contract requires you to provide a C source file named
`triangle.c` and a C header file named `triangle.h`. Your header
file should contain your forward declarations. Your source file must not
contain a main function, or it will fail during testing.  

Your source and header files should be placed in the `Lab2/triangle/`
directory in your GitLab repository.

### Testing

To test your code, you can compile your source file with the
`triangleM.o` object file found in `CI/objects/triangle/`. It can
then be executed as normal. Note that because we’re using floating point
values, it’s possible that your values may vary slightly after several
decimal places are considered. By reducing the calculated values to two
decimal places, we limit the error and have never had a correct
submission fail the pipeline. However, it’s possible that we could run
into some kind of error with a valid calculation. If you have problems
with your calculations failing because of a slight error at two decimal
places, let us know right away and we can work out a solution.

### Sample Inputs and Outputs

| **Input**                                                          | **Output**          |
| :----------------------------------------------------------------- | :------------------ |
| findOppositePyth( 62, 86.9770084563, 0.7772682612, 0.7935280656 )  | <br>opposite = 61.00 <br>adjacent = 62.00 <br> hypotenuse = 86.98 <br> x = 0.78 <br> y = 0.79<br> <br>       |
| findAdjacentPyth( 97, 129.6341004520, 0.8454352154, 0.7253611114 ) |<br>opposite = 97.00<br>adjacent = 86.00<br>hypotenuse = 129.63<br>x = 0.85<br>y = 0.73<br> <br>       |
| findHypotenusePyth( 77, 78, 0.7789466400, 0.7918496868 )           |<br>opposite = 77.00<br>adjacent = 78.00<br>hypotenuse = 109.60<br>x = 0.78<br>y = 0.79<br> <br>       |
| findOppositeTrig( 9, 53.7587202229, 1.4025895549, 0.1682067719 )   |<br>opposite = 53.00<br>adjacent = 9.00<br>hypotenuse = 53.76<br>x = 1.40<br>y = 0.17<br> <br>   |
| findAdjacentTrig( 33, 60.7453701939, 0.5743048302, 0.9964914966 )  |<br>opposite = 33.00<br>adjacent = 51.00<br>hypotenuse = 60.75<br>x = 0.57<br>y = 1.00<br> <br>       |
| findHypotenuseTrig( 78, 71, 0.8323435117, 0.7384528151 )           |<br>opposite = 78.00<br>adjacent = 71.00<br>hypotenuse = 105.48<br>x = 0.83<br>y = 0.74<br> <br>       |


# Submission

## Required Files

When submitting this lab, you must submit your C source and header files
only. Each file must be contained in the directory listed in the
structure requirement diagram below. These files include:

1.  `coins.c`
2.  `coins.h`
3.  `power.c`
4.  `power.h`
5.  `triangle.c`
6.  `triangle.h`

As with all labs, submitting anything other than what is required in
this section will cause the testing scripts to fail on structure checks.

## Submission Procedure and Expectations

Your code will be submitted to your Lab 2 GitLab repository using the
same method as outlined in the Lab Technical Document. Refer to that
document if you do not remember how to submit files via the GitLab
service. A link to your repository can be found in the `Lab2` subgroup
of the CSCI 2122 GitLab group
[<span style="color: blue">here</span>](https://git.cs.dal.ca/courses/2023-winter/csci-2122).  

As mentioned in the Lab Technical Document, we will provide you with a
CI/CD script file which will help you test your submissions. The `.yml`
file containing the CI/CD test script logic, and any other necessary
script files, are available in your repository at all times. You are
free to view any of the script files to help you understand how our
testing scripts will function. We make extensive use of relative path
structures for testing purposes, which is why strict adherence to
directory structure and file contents is such a necessity. Also remember
to check your pipeline job outputs on the GitLab web interface for your
repository to see where your jobs might be failing.  

Remember to follow the instruction guidelines as exactly as possible.
Sometimes the pipeline scripts will not test every detail of your
submission. **Do not rely on us to perfectly test your code.** 
The CI/CD pipeline is a great tool for helping you debug
major parts of your submissions, but you are still expected to follow
all rules as they have been laid out.  

## Submission Structure

In order for a submission to be considered valid, and thus testable,
your git repository must contain directories and files in the following
structure:

```
Lab2/
 ┣ coins/
 ┃  ┣ coins.c
 ┃  ┗ coins.h
 ┣ power/
 ┃  ┣ power.c
 ┃  ┗ power.h
 ┗ triangle/
    ┣ triangle.c
    ┗ triangle.h
```


As with all labs, accuracy is incredibly important. When submitting any
code for labs in this class, you *must* adhere to the directory
structure and naming requirements in the above diagram. Failure to do so
will cause the testing scripts to fail.  

Remember to remove `Lab2/delete_this_file` from your repository
using <kbd>git rm</kbd> to avoid any pipeline failures.

## Marks

This lab is marked out of 10 points. All of the marks in this lab are
based on the successful execution of each contract. Any marking pipeline
failures of a given contract will result in a mark of 0 for that
contract. Successful completion of the various contracts will award
points based on the following table:

| Contract  | Points |
| ------    | ------ |
| Coins     | 2      |
| Power     | 3      |
| Triangle  | 5      |
| **Total** | 10     |
