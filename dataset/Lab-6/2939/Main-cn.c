/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include
- Comments for non trivial code 
- Indentation: align your code properly
- Function use and modular programming
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

给定一个整数数组，打印最长升序（严格递增）子序列的长度。

例如，数组 A = [1, -2, 3, -5, 5]，最长的递增子序列是 [1, 3, 5]。因此，输出结果为
3

提示
让 A[0...n-1] 作为输入数组。再创建一个数组 MaxTill[0..n-1]。在这个数组中，MaxTill[i] 表示直到索引 i 的最长升序子序列的长度，这样 A[i] 是最长序列的一个元素。
因此，MaxTill[i] 可以写成
MaxTill[i] = max(
     max(1+MaxTill(j)) （当 j < i 且 A[j] < A[i]）
     1 （如果没有这样的 j）
)

最长递增子序列的长度将是 MaxTill[0...n-1] 中所有值的最大值。

输入说明： 
第一行包含数组的大小 N。
下一行包含 N 个空格分隔的整数，给出数组的内容。

输出格式：
输出最长递增子序列的长度。

变量限制
数组大小小于 20。
每个数组条目都是符合 int 数据类型的整数。

Example:
Input:
5
1 -2 3 -5 5

Output:
3
*/
#include <stdio.h>
#define MAX 20

int max(int a, int b){
	return a>b?a:b;
}

int main(){
	int n, i, j, max_val, ans=0;
	int A[MAX], MAXVAL[MAX];
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d",&A[i]);
	}
	MAXVAL[0] = 1;
	for(i=1; i<n; i++){
		max_val=1;
		for(j=0; j<i; j++){
			if(A[j]<A[i]){
				max_val = max(MAXVAL[j]+1, max_val);
			}
		}
		MAXVAL[i] = max_val;
	}
	for(i=0; i<n; i++){
		ans = max(ans, MAXVAL[i]);
	}
	printf("%d\n", ans);
	return 0;
}