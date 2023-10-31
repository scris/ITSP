/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for the non trivial part of the code 
- Indentation: align your code properly 
---------------------------------

请编写一个 C 语言程序，计算由 (a,b)、(a,0) 和 (0,b) 三点构成的三角形的面积。输出结果应为小数点后四位。具体格式如下 

输入格式：a b （在一行中给出）
输出格式：

Example:
输入： 1 1
输出： The area of (1.0000,1.0000), (1.0000,0) and (0,1.0000) is 0.5000.
*/
#include<stdio.h>

int main(){
	float a,b, a1,b1;
	float area;
	
	scanf("%f %f",&a,&b);
	
	a1=a, b1=b;
	if (a<0) a1=-a;
	if (b<0) b1=-b;
	
	area = 0.5*a1*b1;
	
	printf("The area of (%.4f,%.4f), (%.4f,0) and (0,%.4f) is %.4f.\n", a,b,a,b,area);

	return 0;
}