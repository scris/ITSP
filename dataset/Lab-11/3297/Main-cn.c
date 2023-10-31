/*
--------------------------------------------
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for non-trivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template. 
 - You are required to allocate memory Dynamically instead of static memory allocation otherwise you might get 0 
 - TAs: Please ensure that the submission is doing Insertion Sort and not any other sorting routine.
---------------------------------------------

插入排序（升序）是一种迭代方式，每次迭代消耗一个输入元素，并生成一个已排序的输出列表。每次迭代，插入排序都会从输入数据中移除一个元素，找到它在排序列表中的位置，然后将其插入。如此反复，直到没有输入元素为止。

排序通常是就地进行的，方法是向上迭代数组，使排序后的列表不断增长。在每个数组位置，它都会将该位置的值与排序列表中最大的值（恰好在它旁边，在上一个被检查的数组位置）进行核对。如果数值较大，则将该元素留在原位，然后移动到下一个位置。如果较小，则在排序列表中找到正确的位置，将所有较大的值向上移动一个空格，然后插入到正确的位置。

下面给出的伪代码描述了该算法：

1. 对于所有元素 arr[i]（0 < i < n），如果 arr[i] 小于 arr[i-1]，则转到步骤 2，否则对下一个 i 继续执行步骤 1。

2. 查找元素 arr[j]，使得 j 是满足 arr[j] > arr[i] 的最低索引。(将 arr[i] 置于列表的第 j 位，并将 j+1 至 i-1 的每个元素向右移动一位。

输入：一个正整数 n，后面是一行包含 n 个正整数的空格。
输出：空格分隔的整数排序列表。
*/
#include<stdio.h>
#include<stdlib.h>

void InsertionSort(int* arr, int n){
    int i;
    for(i=1;i<n;i++){
        if(arr[i]>=arr[i-1])
            continue;
    	int j;
    	for(j=0;j<i;j++){
    		if(arr[j]>arr[i]){
    			int k=j;
    			int prev=arr[k];
    			arr[k]=arr[i];
    			for(k=j+1;k<=i;k++){
    				int curr=arr[k];
    				arr[k]=prev;
    				prev=curr;
    			}
    			break;
    		}
    	}
    }
}

int main(){
	int n;
	scanf("%d",&n);
	int* arr;
	arr = (int*) malloc(n*sizeof(int));
	
	int i;

	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	InsertionSort(arr,n);
	
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}