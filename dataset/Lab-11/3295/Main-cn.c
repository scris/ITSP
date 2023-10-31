/*
--------------------------------------------
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for non-trivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template. 
 - You are required to allocate memory Dynamically instead of static memory allocation otherwise you might get 0 
 - TAs: Please ensure that the submission is doing Comb Sort and not any other sorting routine.
---------------------------------------------

本题向你介绍对 n 个正整数（按非递减顺序）进行排序的新算法。

在冒泡排序中，当比较任何两个元素时，它们之间的间隙（在数组中彼此的距离）总是 1。

梳状排序的基本思想是消除乌龟，即靠近列表末尾的小数值，因为在冒泡排序中，这些数值会大大减慢排序速度。兔子，即列表开头附近的大数值，在冒泡排序中不会造成问题。

换句话说，进行实际交换的内循环会被修改，使被交换元素之间的间隙（在外循环的每次迭代中）以收缩因子的步长递减，即 [ n/shrink , n/shrink^2, n/shrink^3, ...., 1 ]。与气泡排序不同，在气泡排序中，间隙是恒定的，即 1。

开始时，间隙是被排序列表的长度除以收缩因子（一般为 1.3，见下文），然后以该值作为间隙对列表进行排序（如果需要，四舍五入为整数）。然后再次将间隙除以收缩因子，再以这个新的间隙对列表进行排序，整个过程重复进行，直到间隙为 1。此时，梳理排序继续使用 1 的间隙，直到列表完全排序完毕。因此，排序的最后阶段等同于冒泡排序，但此时大多数海龟都已处理完毕，因此冒泡排序会更有效率。

下面的伪代码描述了该算法：

1. 选择 gap = n/shrink。

2a. 如果gap*严格*大于 1，则对列表进行一次传递，在传递过程中，比较第 i 个元素和第 (i+gap)-th 个元素，如果 arr[i] > arr[i+gap]，则交换这些元素。从 i=0 开始，直到 i+gap>=n 为止，对所有 i 进行上述操作。

2b. 如果gap等于 1，则对整个列表进行一次传递（与 2a 中的交换相同），由于gap==1，所以 i+gap 与 i+1 相同，即在整个传递过程中比较相邻的元素。如果没有交换，则退出并返回排序后的列表。

3. 将gap除以shrink factor来减小间隙，然后再次执行步骤 2。如果间隙小于 1，则设置间隙等于 1 并再次执行步骤 2。

(请注意，当gap==1 时，基本上是对整个列表进行冒泡排序！因此，在该子程序结束时，列表必定会被排序。不过，这种排序算法的美妙之处在于，它比一般的冒泡排序要快得多！)

注意：本作业的shrink factor为 1.3。

输入：一个正整数 n，后面是一行包含 n 个正整数的空格。
 
输出：空格分隔的整数排序列表。
*/
#include<stdio.h>
#include<stdlib.h>

void CombSort(int* arr, int n){
    int gap = n;
   	float shrink = 1.3;
   	
   	int swapped = 1;
    while(gap>=1 && swapped==1){
        gap = (int) ((float)gap)/shrink;
        if(gap<1)	gap=1;
        
        
        int i=0;
        if(gap==1)
        	swapped=0;

        while((i+gap)<n){
        	if(arr[i]>arr[i+gap]){
        		int temp = arr[i];
        		arr[i]=arr[i+gap];
        		arr[i+gap]=temp;
        		if(gap==1)
        			swapped=1;
        	}
        	i++;
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

	CombSort(arr,n);
	
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}