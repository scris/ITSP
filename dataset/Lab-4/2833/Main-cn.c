/*
输入一个自然数 N。您需要计算边长小于或等于 N 的整边三角形的数目。

Input:
4

Output:
Number of possible triangles is 13
*/
#include <stdio.h>
int main() {

	int N;
	int a, b, c , count = 0;

	scanf("%d",&N);

	for(a = 1 ; a <= N ; a++)
		for(b = 1 ; b <= a ; b++)
			for(c =1 ; c <= b ; c++)
				if ( a + b > c && b + c > a && c + a > b)
					count++;


	printf("Number of possible triangles is %d" , count);

	return 0;
}