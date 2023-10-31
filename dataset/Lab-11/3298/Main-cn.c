/*
--------------------------------------------
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for non-trivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template. 
 - You are required to allocate memory Dynamically instead of static memory allocation otherwise you might get 0 
 - TAs: Please ensure that the submission is using the recursive idea behind Merge Sort.
---------------------------------------------
反转计数

由元素 a1、a2、... , an 组成的列表中的反转是指一对元素 {ai,aj} ，其中 ai > aj 且 i < j。要计算元素列表中的反转总数，可以修改标准的合并排序算法。从本质上讲，在 MergeSort 的递归定义中，计算每一半的反转数，并计算*交叉反转*的数量，即 {ai, aj}，使得 ai>aj 且 ai 位于前一半，aj 位于后一半。

请注意，您必须保持 MergeSort 的排序例程*原样*，并添加一些额外的处理步骤来计算反转数。

在本题中，请实现计算反转数并打印排序列表的算法。下面的伪代码描述了该算法：
sort-and-count(L)
  #处理列表 L 的基本情况
     #将 L 分成 A、B（几乎相等的部分）
     #*递归*计算 rA 和 rB，它们分别是 A 和 B 中的反转数
     #get r，即交叉逆转的次数，并使用排序后的列表 A 和 B 从合并例程中得到合并后的列表 L
     #return rL = rA+rB+r, L

merge-and-count(A,B)
  #merge sort 的标准合并例程
  #当 B 中的一个元素在 A 中剩余的 x 个元素之前被推入返回列表时，A 和 B 中的 "交叉转换 "计数增加 x 
  #返回计数和（A 和 B 的合并列表）

输入：一个正整数 n，后面是一行包含 n 个正整数的空格。

输出：列表中的反转数，下一行是排序后的列表（用空格分隔的元素）。
*/
#include<stdio.h>
#include<stdlib.h>

int MergeAndCount(int* arr, int lo, int hi){
	
	int* temp;
	temp = (int*) malloc((hi-lo+1)*sizeof(int));

	int mid=(lo+hi)/2;
	int i=lo;
	int j=mid+1;
	int k=0;

	int count = 0;

	while(i<=mid && j<=hi){
		if(arr[i]>arr[j]){
			temp[k++]=arr[j++];
			count+= (mid-i+1);
		}
		else{
			temp[k++] = arr[i++];
		}
	}

	while(i<=mid){
		temp[k++]=arr[i++];
	}
	while(j<=hi){
		temp[k++]=arr[j++];
	}

	for(i=0;i<=(hi-lo);i++){
		arr[i+lo]=temp[i];
	}

	free(temp);
	return count;
}



int SortAndCount(int* arr, int lo, int hi){
	int mid=(hi+lo)/2;
	if(hi>lo){
		int count1 = SortAndCount(arr, lo,mid);
		int count2 = SortAndCount(arr,mid+1,hi);
		int count3 = MergeAndCount(arr,lo,hi);
		return (count1+count2+count3);
	}
	else{
		return 0;
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

	int count = SortAndCount(arr,0,n-1);
	
	printf("%d\n",count);
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}