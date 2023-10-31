/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include
- Comments for non trivial code 
- Indentation: align your code properly 
- Function use and modular programming
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

给定两个整数数组（比方说 A1 和 A2），检查 A2 是否是 A1 的连续子数组。如果 A2 中的所有元素都以相同的顺序连续出现在 A1 中，那么 A2 就是一个连续的子数组。

例如 [12,42,67] 是 [1,62,12,42,67,96] 的连续子数组。
而 [1,23,21] 和 [12,42,96] 不是 [1,62,12,42,67,96] 的连续子数组。

输入说明： 
第一行包含第一个数组的大小 N1。
下一行包含 N1 个空格分隔的整数，表示第一个数组的内容。
下一行包含第二个数组的大小 N2。
下一行包含 N2 个空格分隔的整数，给出第二个数组的内容。

输出格式：
输出必须是 "YES"或 "NO"（后换一行）。

变量限制：
数组大小小于 20。
每个数组条目都是符合 int 数据类型的整数。

Example:
Input:
4
34 13 42 14
2
13 42
Output:
YES

Input
3
1 2 18
2
2 12
Output:
NO
*/
#include <stdio.h>
#define MAX 20

int main(){
	int A1[MAX], n1, A2[MAX], n2;
	int i, j, present;
	// Read array 1
	scanf("%d",&n1);
	for(i=0; i<n1; i++){
		scanf("%d",&A1[i]);
	}
	// Read array 2
	scanf("%d",&n2);
	for(i=0; i<n2; i++){
		scanf("%d",&A2[i]);
	}
	for(i=0; i<n1-n2; i++){
		present=1;
		for(j=0; j<n2; j++){
			if(A1[i+j] != A2[j]){
				present=0;
			}
		}
		if (present==1){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}