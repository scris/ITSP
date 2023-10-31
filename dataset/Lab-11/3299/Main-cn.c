/*
-------------------------------------------- 
Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for non-trivial code 
- Indentation: align your code properly 
- Function use and modular programming 
- Do not include anything in the header other than what is already given in the template. 
- You are required to allocate memory Dynamically instead of static memory allocation otherwise you might get 0 
- TAs: Please ensure that the submission is doing quick sort and not any other sorting routine. ---------------------------------------------

Quicksort（升序）是一种分而治之的算法。Quicksort 首先将一个大数组分成两个较小的子数组：低元素和高元素。然后，Quicksort 可以对子数组进行递归排序。

具体步骤如下

1. 从数组中选取一个元素，称为枢轴(pivot)。

2. 2. 对数组重新排序，使所有值小于枢轴的元素都排在枢轴之前，而所有值大于枢轴的元素都排在枢轴之后（等值元素可以任选其一）。经过这样的分区后，中枢就处于最终位置了。这就是分割操作。

3. 对数值较小的元素子数组递归应用上述步骤，对数值较大的元素子数组单独应用上述步骤。

注意：递归的基本情况是大小为 0 或 1 的数组，它们从不需要排序。可以用函数 quicksort(A, lo, hi) 来表示对数组 A 的一个子数组 lo 至 hi（包含）进行排序的 quicksort。对整个数组排序的方法是调用 quicksort(A,1,length(A))。

下面的伪代码描述了该算法：
quicksort(A, lo, hi)
  #处理基本情况
  #对数组进行分区，并在两个分区上递归调用 quicksort

partition(A, lo, hi)
     # 选择一个枢轴元素（在本练习中，可以使用数组的第一个元素）
     #从数组的左右两边开始计数
      while True // 这里没有终止条件
        做
            right--
        当右边(right)的元素大于枢轴元素时
        执行
           left++
        当左侧(left)位置的元素小于枢轴元素时
        如果（此处插入条件）
            将 A[right] 与 A[left] 互换
        否则 
            返回right 
             # 如果完成分区后，右边是枢轴元素的位置，就会出现这种情况，这就是终止条件

输入 一个正整数 n，后面是一行包含 n 个正整数的空格。

输出 空格分隔的整数排序列表
*/
#include<stdio.h>
#include<stdlib.h>


int Partition(int* arr,int lo,int hi){
	int pivot = arr[lo];
    int i = lo;
    int j = hi;
    while(1){
    	while(arr[j]>pivot){
    		j--;
    	}
    	while(arr[i]<pivot){
    		i++;
    	}
    	if(i<j){
    		int temp = arr[i];
    		arr[i]=arr[j];
    		arr[j]=temp;
    		i++;
    		j--;
    	}
    	else{
    		return j;
    	}
    }
}

void QuickSort(int* arr,int lo, int hi){
	if(lo < hi){
		int p = Partition(arr,lo,hi);
		QuickSort(arr,lo,p);
		QuickSort(arr,p+1,hi);
	}
	return;
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

	QuickSort(arr,0,n-1);
	
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}