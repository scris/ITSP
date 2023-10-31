/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice.
These include
- Comments: for the non trivial part of the code
- Indentation: align your code properly
---------------------------------

编写一个 C 程序，输出输入浮点数的符号。输入 $a$，输出他是正数、零还是负数。

输入格式：a
输出格式：input is zero 或 a is positive 或 a is negative，使用 4 位小数

Example 1: On input -12,
OUTPUT: -12.0000 is negative

Example 2: On input 0,
OUTPUT: input is zero

Example 3: On input 1,
OUTPUT: 1.0000 is positive

*/
#include <stdio.h>

int main() {
  float a;

  scanf("%f", &a);

  if (a < 0)
    printf("%.4f is negative", a);
  if (a == 0)
    printf("input is zero");
  if (a > 0)
    printf("%.4f is positive", a);

  return 0;
}