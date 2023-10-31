/*
编写一个 C 程序来计算两条直线的交点。所有数值均为浮点数。

输入：$a_1\: b_1\: a_2\: b_2$ 是在一条直线上给出的。它们指定了两条直线 $(a_1 X + b_1 Y\,=\, 1 )$ & $(a_2 X + b_2 Y\,=\, 1 )$ 。

输出： 如果没有交点，则打印 "INF"，否则打印交点，精确到小数点后 3 位。

Example 1: 输入: 1 0 0 1
输出: (1.000,1.000)

Example 2: 输入: 1 0 1 0
输出: INF
*/
#include<stdio.h>

int main(){
	float a1,b1, a2,b2;
	float d,a,b;
	
	scanf("%f %f %f %f",&a1,&b1,&a2,&b2);
	
	d = a1*b2 - a2*b1;
	
	if (d==0) 
	    printf("INF\n");
	else {
	    a = (b2-b1)/d;
	    b = (a1-a2)/d; 
	    printf("(%.3f,%.3f)\n", a,b);
    
	}    
	
	return 0;
}