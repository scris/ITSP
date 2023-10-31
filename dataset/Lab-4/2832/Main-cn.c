/*
输入三个整数，对应三角形的三条边。编写一个程序来确定三角形是锐角三角形、直角三角形还是钝角三角形。如果边的组合与有效三角形不符，则应打印 "无效三角形"。

Input:
3 5 4
Output:
Right Triangle
*/
#include <stdio.h>

int main() {

	int a ,b , c , t;
	scanf("%d%d%d" , &a , &b , &c); 

	if (a > c)  //swap a & c
	{	t = c;
		c = a;
		a = t;
	}

	if (b > c)  //swap b & c
	{
		t = c;
		c = b;
		b = t;
	}
	// now c is the longest side

	if ( a + b <= c || b + c <= a || a + c <= b)
		printf("Invalid Triangle");

	else if (c*c > a*a + b*b)
		printf("Obtuse Triangle");

	else if (c*c < a*a + b*b)
		printf("Acute Triangle");

	else
		printf("Right Triangle");

	
	return 0;
}