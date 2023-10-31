/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include 
- Comments for non trivial code 
- Indentation: align your code properly 
- Use of character constants instead of ASCII values ('a', 'b, ..., 'A', 'B', ..., '0', '1' etc instead of ASCII values like 65, 66, 48 etc.)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------

编写一个 C 程序，以确定输入字符是大写字母、小写字母还是数字。请勿使用任何库函数，如 isupper()、islower()，否则将不得分。大写字母输出“Capital Letter”，小写字母输出“Small Letter”，数字输出“Digit”。

Example: 
Input: 
A 
Output: 
Capital Letter 

Input: 
5 
Output: 
Digit 

Input: 
c 
Output: 
Small Letter
*/
#include<stdio.h>

int main()
{
    char c;
    scanf("%c", &c);
    if('a' <= c && c <= 'z')
        printf("Small Letter");
    else if('A' <= c && c <= 'Z')
        printf("Capital Letter");
    else if('0' <= c && c <= '9')
        printf("Digit");
    return 0;
}