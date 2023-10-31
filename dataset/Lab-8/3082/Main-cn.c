/*
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for nontrivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template. 
-----------------------------------------------------------------------------------------------------------

给定矩阵 M[n][m]，找出总和最大的一行。如果有多行具有最大和，则按升序打印所有行。行的索引从 0 开始。

限制条件
n 和 m 在 1 到 100 之间。

输入 
第一行包含两个整数 n 和 m，表示矩阵的维数。
接下来是 n 行，每行有 m 个整数。每行表示矩阵的一行，第 j 行中的第 i 个值表示 matrix[i][j] 的值。

输出：
一行，行号按升序排列，中间用空格隔开。
*/
#include <stdio.h>
#include <limits.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int mat[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    int ct=0;
    int row[n];
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<m;j++)
        {
            sum+=mat[i][j];
        }
        if(sum > max)
        {
            max=sum;
            row[0]=i;ct=1;
        }
        else if(sum==max)
        {
            row[ct]=i;ct++;
        }
    }
    for(int i=0;i<ct;i++)
    {
        printf("%d ",row[i]);
    }
    printf("\n");
}