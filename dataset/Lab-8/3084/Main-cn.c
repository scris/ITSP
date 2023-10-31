/*
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for nontrivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template. 
-----------------------------------------------------------------------------------------------------------

如果棋盘中的一个皇后被放在同一行/同一列/同一条对角线上，它就可以攻击另一个皇后。给定棋盘上的王后数量及其位置（行，列），找出这是否是一个安全的排列。如果没有王后可以攻击另一个王后，那么这个布局就是安全的。如果是安全布局，则打印 "是"；如果至少有一个皇后可以攻击另一个皇后，则打印 "否"。

限制条件
棋盘大小为 8x8。

输入
整数 N，表示棋盘上的皇后数量。
输入：一个整数 N，表示棋盘上的皇后数量；其后有 N 行，每行有两个整数 R 和 C，分别表示行数和列数。
它们的索引从 0 开始。

输出：
YES（如果是安全排列）
NO（如果不是安全排列）
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int mat[8][8];
    int r,c,n;
    memset(mat,0,sizeof(mat));
    scanf("%d",&n);
    int row[8],col[8],diag1[16],diag2[16];
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    memset(diag1,0,sizeof(diag1));
    memset(diag2,0,sizeof(diag2));
    int found=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&r,&c);
        mat[r][c]=1;
        if(row[r]==1)found=1;
        else row[r]=1;
        if(col[c]==1)found=1;
        else col[c]=1;
        if(diag1[r+c]==1)found=1;
        else diag1[r+c]=1;
        if(diag2[8+r-c]==1)found=1;
        else diag2[8+r-c]=1;
    }
    if(found==1)
        printf("no\n");
    else
        printf("yes\n");
        
    return 0;
}