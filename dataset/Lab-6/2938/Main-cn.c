/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include
- Comments for non trivial code 
- Indentation: align your code properly 
- Function use and modular programming
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

给定一个整数数组和一个整数 k，打印每 k 个连续元素的和。

例如，数组 A = [1, 2, 3, 4, 5]，k = 3，输出将是
6
9
12

输入说明： 
第一行包含数组的大小 N。
下一行包含 N 个空格分隔的整数，表示数组的内容。
下一行包含 k。

输出格式：
输出 k 个总和（每个总和后都有换行符）。

变量限制：
数组大小小于 20。
每个数组条目都是符合 int 数据类型的整数。

Example:
Input:
4
34 13 42 14
2
Output:
47
55
56

Input
4
11 2 18 2
2
Output:
13
20
20

*/
#include <stdio.h>
#define MAX 20

int read_array(int arr[]){
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	return n;
}

int main(){
	int A[MAX], n, k;
	n = read_array(A);
	scanf("%d",&k);
	for(int i=0; i<=n-k; i++){
		int sum=0;
		for(int j=0; j<k; j++){
			sum += A[j+i];
		}
		printf("%d\n", sum);
	}
	return 0;
}