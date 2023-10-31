/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include
- Comments for non trivial code 
- Indentation: align your code properly 
- Function use and modular programming
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

给定一个整数数组，检测其中是否包含重复元素。

输入说明： 
第一行包含数组的大小 N。
下一行包含 N 个空格分隔的整数，给出数组的内容。

输出格式：
输出 "是 "或 "否"（后跟换行符）。

变量限制：
数组大小小于 50。
每个数组条目都是符合 int 数据类型的整数。

Example:
Input:
4
34 13 42 13

Output:
YES

Input
4
11 2 18 22

Output:
NO

*/
#include <stdio.h>
#define MAX 50

int main(){
	int A[MAX], n;
	int i, j;
	int duplicate=0;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
	for(i=0; i<n; i++){
		for(j=0; j<i; j++){
			if (A[i] == A[j]){
				duplicate = 1;
			}
		}
	}
	if (duplicate == 1){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}