/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include 
- Comments for non trivial code 
- Indentation: align your code properly
- Use of character constants instead of ASCII values ('a', 'b, ..., 'A', 'B', ..., '0', '1' etc instead of ASCII values like 65, 66, 48 etc.)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

输入点为圆心坐标 (x, y) 及其半径（例如 r）。输入另一点，例如 (x1，y1)。请编写一个程序，找出该点是在圆内、圆上还是圆外。假设 x、y、r、x1、y1 为浮点数据类型。

输入格式： x y r x1 y1（用一个空格分隔）。

Example:
Input:
3.2 4.3 2.3 4.3 5.6 	
Output:
Point is inside the Circle.

Input:
1.2 2.3 2.0 5.3 7.6
Output:
Point is outside the Circle.
*/
#include<stdio.h>
#include<math.h>

int main()
{
    float x, y, r, x1, y1, d;
    scanf("%f%f%f%f%f", &x,&y,&r,&x1,&y1);
    d = sqrtf(pow((x1-x), 2) + pow((y1 - y), 2));
    if(d < r)
        printf("Point is inside the Circle.");
    else if(d == r)
        printf("Point is on the Circle.");
    else
        printf("Point is outside the Circle.");
    return 0;
    
}