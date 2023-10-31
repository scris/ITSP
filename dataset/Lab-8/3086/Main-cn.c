/*
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for nontrivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template. 
-----------------------------------------------------------------------------------------------------------

有一个 n*m 矩阵，其中只有 0 和 1。你需要找出矩阵中仅由 1 组成的最大正方形的大小。
假设矩阵为
01010101
00000000
00011100
00011100
00011100
在这种情况下，最大正方形的大小为 3 [正方形最左侧的顶点为 (2,3)]。

输入
两个整数：n 和 m。
这表示矩阵有 n 行和 m 列。
接下来会有 n 行，每行有 m 个整数。(表示矩阵的元素）。

输出：
表示最大正方形大小的整数。

提示：
创建另一个矩阵 sum[n][m]，复制原始矩阵的第一行和第一列（我们称这个矩阵为 input[n][m]），现在遍历 input[][]的所有其他元素。
如果 input[i][j]==0 则 sum[i][j]=0。
如果 input[i][j]==1 则 sum[i][j]=1+min(sum[i-1][j],sum[i][j-1],sum[i-1][j-1])；

创建 sum[][]后，该矩阵中的最大元素就是答案。

*/
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int dp[n][m],mat[n][m];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&mat[i][j]);
            if(i==0 || j==0)
            {
                dp[i][j]=mat[i][j];
            }
        }
    }
    int max=0;
    if ((m == 1) && (n == 1)) {
        printf("%d\n", mat[0][0]!=0);
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(mat[i][j]==0)continue;
            int m1;
            if(dp[i][j-1]<dp[i-1][j])
                m1=dp[i][j-1];
            else
                m1=dp[i-1][j];
            if(m1 > dp[i-1][j-1])
                m1=dp[i-1][j-1];
            m1++;
            dp[i][j]=m1;
            if(m1>max)max=m1;
          
        }
    }
    printf("%d\n",max);
    
    return 0;
}
