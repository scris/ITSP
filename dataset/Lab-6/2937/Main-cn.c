/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include
- Comments for non trivial code 
- Indentation: align your code properly 
- Function use and modular programming
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

给定两个非降序排序的数组，将它们合并为一个非降序数组。

输入说明： 
第一行包含第一个数组的大小 N1。
下一行包含 N1 个空格分隔的整数，给出第一个数组的内容。
下一行包含大小为 N2 的第二个数组。
下一行包含 N2 个空格分隔的整数，给出第二个数组的内容。

输出格式：
输出合并数组的元素（每个元素后都有换行符）。

变量限制：
数组大小小于 20。
每个数组条目都是符合 int 数据类型的整数。

示例：
Input 1:
5
1 2 5 9 16
3
3 5 21

Output 1:
1
2
3
5
5
9
16
21

Input 2:
2
1 2
3
12 31 45

Output 2:
1
2
12
31
45

*/
#include <stdio.h>
#define MAX 20

int main(){
	int N1, N2;
	int A1[MAX], A2[MAX], ANS[2*MAX];
	int A1_index=0, A2_index=0, index_sum=0;
	int i;
	// Read array 1
	scanf("%d",&N1);
	for(i=0; i<N1; i++){
		scanf("%d",&A1[i]);
	}
	// Read array 2
	scanf("%d",&N2);
	for(i=0; i<N2; i++){
		scanf("%d",&A2[i]);
	}
	while(index_sum<N1+N2){
		if (A1_index>=N1){					// Array A1 is completely merged
			ANS[index_sum] = A2[A2_index];
			A2_index++;
			index_sum++;
		}else if (A2_index>=N2){		    // Array A2 is completely merged
			ANS[index_sum] = A1[A1_index];
			A1_index++;
			index_sum++;
		}else{
			if (A1[A1_index] < A2[A2_index]){	// A1 contains smaller element
				ANS[index_sum] = A1[A1_index];
				A1_index++;
				index_sum++;
			}else{						// A2 contains smaller element
				ANS[index_sum] = A2[A2_index];
				A2_index++;
				index_sum++;
			}
		}
	}
	for(i=0; i<N1+N2; i++){
		printf("%d\n", ANS[i]);
	}
	return 0;
}