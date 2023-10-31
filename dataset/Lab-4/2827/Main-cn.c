/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include 
- Comments for non trivial code 
- Indentation: align your code properly
- Use of character constants instead of ASCII values ('a', 'b, ..., 'A', 'B', ..., '0', '1' etc instead of ASCII values like 65, 66, 48 etc.)
----------------------------------------------------------------------------------------------------------------------------------------------------------------

输入三个点 (x1，y1)、(x2，y2) 和 (x3，y3)。请编写一个程序，检查这三个点是否都落在一条直线上。

注意：假设 x1、y1、x2、y2、x3 和 y3 的数据类型为浮点数。

输入格式
x1 y1 x2 y2 x3 y3 用一个空格分隔。

Example:
Input:
1.0 0.0 2.0 0.0 3.0 0.0 	
Output:
All the points are on same line.

Input:
1.0 -2.0 5.2 3.0 0.0 5.0 	
Output:  
All the points are not on same line.
*/
#include<stdio.h>

int main()
{
    float x1, y1, x2, y2, x3, y3, slope, v;
    scanf("%f%f%f%f%f%f", &x1,&y1,&x2,&y2,&x3,&y3);
    if(x1 == x2)
    {
        if(x3 == x1)
            printf("All the points are on same line.");
        else
            printf("All the points are not on same line.");
    }
    else
    {
        slope = (y2 - y1)/(x2 - x1);
        v = (y3 - y1) - slope *(x3 - x1);
        if(v == 0)
            printf("All the points are on same line.");
        else
            printf("All the points are not on same line.");
    }            
    return 0;
    
}