/*
-------------------------------------------- 
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for non-trivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template. 
 - You are required to allocate memory Dynamically instead of static memory allocation otherwise you might get 0. 
 - Use of C Structures is mandatory.
---------------------------------------------

您将得到两个集合，您需要打印这两个集合中的元素。
请注意 集合的元素是唯一的。

请使用数据结构来解决这个问题，以便指定集合的详细信息。这样的数据结构可以有两个字段，一个指定数组中元素的数量，另一个是指向整数数组的指针。你应该动态分配空间来存储集合中的元素。

输入格式：
第一行包含第一个集合中元素的数量。
第二行包含第一个集合的元素（空格分隔）。
第三行包含第二个集合的元素数。
第四行包含第二组元素（空格分隔）。

输出格式： 
在一行中打印两个集合结合处的元素（按排序）。

输入示例 1
4
1 2 3 4
5 
2 3 4 5 6

样本输出1：
1 2 3 4 5 6

注意：您可能需要引入一个排序例程来对集合中的元素进行排序。
*/
#include <stdio.h>
#include <stdlib.h>

struct Set{
	int size;
	int * elements;
};

void inputSet(struct Set * set, int size) {
	set->size = size;
	set->elements = (int *) malloc(sizeof(int)*size);
	int i=0;
	for(i=0;i<size;i++) {
		scanf("%d",set->elements+i);
	}
}

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

void printUnion(struct Set set1,struct  Set set2) {
	int * unionArray = (int *) malloc(sizeof(int)*(set1.size+set2.size));
	int i,j,ind;
	for(i=0,ind=0;i<set1.size;i++,ind++) {unionArray[ind]=set1.elements[i];}
	for(i=0;i<set2.size;i++) {
		for(j=0;j<set1.size;j++) {
			if(set2.elements[i]==set1.elements[j]) break;
		}
		if(j==set1.size) unionArray[ind++]=set2.elements[i];
	}
	qsort(unionArray,ind,sizeof(int),comp);
	for(i=0;i<ind;i++) {
		printf("%d ",unionArray[i]);
	}
	printf("\n");
}

int main() {
	int size;
	struct Set set1,set2;
	scanf("%d",&size);
	inputSet(&set1,size);
	scanf("%d",&size);
	inputSet(&set2,size);
	printUnion(set1,set2);
	return 0;
}