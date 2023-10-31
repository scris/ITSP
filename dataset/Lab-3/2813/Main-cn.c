/*
编写一个 C 程序来计算两条直线的交点。所有数值均为浮点数。

INPUT: $a_1 \: b_1\: a_2\: b_2$ 给出了一条直线。它们指定了两条直线 $(\frac{X}{a_1} + \frac{Y}{b_1} \,=\, 1 )$ & $(\frac{X}{a_2} + \frac{Y}{b_2} \,=\, 1 )$ 。

输出： 如果没有交点，则打印 "INF"，否则打印交点，精确到小数点后 3 位。

Example 1: 输入: 1 1 1 0.5
输出: (1.000,0.000)

Example 2: 输入: 1 0 0 1
输出: (0.000,0.000)

Example 3: 输入: 1 0 1 0
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
	    a = ((b2-b1)/d)*a1*a2;
	    b = ((a1-a2)/d)*b1*b2; 
	    printf("(%.3f,%.3f)\n", a,b);
    
	}    
	
	return 0;
}