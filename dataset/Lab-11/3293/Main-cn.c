/*
--------------------------------------------
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for non-trivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template. 
 - You are required to allocate memory Dynamically instead of static memory allocation otherwise you might get 0 marks. 
---------------------------------------------

我们遇到的问题，是如何给世界各国上色，使相邻的国家涂上不同的颜色。

给定输入 C，国家用数字 {0,1...C-1} 表示。您还将得到一个尺寸为 CxC 的（二维矩阵或）图形 G，其中如果国家 i 与国家 j 相邻，则 G[i,j] 为 1，否则 G[i,j] 为 0。您的输出应该是一行，给出各个国家 {0,1,....,C-1} 所用的颜色，中间用空格隔开。

假定你总是有足够的颜色来按照所需的方式给所有国家涂色。

要给第 i 个国家涂色，请查看 G 的第 i 行，检查 0 到 i-1 中与 i 相邻的国家。

注意：一定要先给第 0 个国家涂上 1 色，然后根据需要递增颜色数。否则，您可能会得到一个不同的解决方案。

例如  输入（C 之后分别是 G 和 m）：

4
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
3

输出

1 2 3 2
*/
#include <stdio.h>
#include <stdlib.h>

void printSolution(int solution[],int C){
	for(int i=0;i<C;i++)
		printf("%d ",solution[i]);
}

int isSafe(int ver,int col,int solution[],int **graph){
	for(int i=0;i<ver;i++){
		if(graph[ver][i] && col==solution[i])
			return 0;
	}
	return 1;

}

int graphColoring(int ver,int** graph,int m , int solution[],int C){
	if(ver==C)
		return 1;
	for(int col=1;col<=m;col++){
			if(isSafe(ver,col,solution,graph)){
				solution[ver] = col;
				if(graphColoring(ver+1,graph,m,solution,C))
					return 1;
				else
					solution[ver] = 0;
			}
	}
	return 0;

}

int main(){
	int C;
	scanf("%d",&C);
	
	int **G = (int **)malloc(C * sizeof(int **));
	for(int i=0;i<C;i++){
		G[i] = (int*)malloc(C*sizeof(int*));
	}

	for(int i=0;i<C;i++){
		for(int j=0;j<C;j++){
			scanf("%d",&G[i][j]);
		}
	}

	int m;
	scanf("%d",&m);

    int solution[C];

    for(int i=0;i<C;i++)
    	solution[i]=0;
    graphColoring (0,G,m,solution,C);
   	printSolution(solution,C);

	return 0;
}