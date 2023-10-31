/*
Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for nontrivial code
- Indentation: align your code properly
- Function use and modular programming
- Do not include anything in the header other than what is already given in the template. --------------------------------------------------------------------------------------------------------------

如果一个矩阵的子矩阵是对称矩阵，我们就说这个矩阵是好矩阵。 如果矩阵不好，我们就说它的好度为 0。但是，如果矩阵好，我们就定义好度为给定矩阵的最大对称子矩阵的维数（即，如果最大的对称子矩阵是 n x n，那么好度就是 n）。例如

0 1 1 0
1 0 0 1
1 0 2 3

这个矩阵是好矩阵，因为 
1 0
0 1
是它的子矩阵，并且是对称的。

0 1 1
1 0 0
1 0 2
 也是给定矩阵的对称子矩阵。

由于给定矩阵的最大子矩阵的维数为 3，因此好度为 3。

你的任务
给定一个矩阵，打印其良率值和最大对称子矩阵左上角的位置。在上面给出的例子中，好度值为 3，对称子矩阵左上角的位置是 (1,1)，即第一行第一列。如果好度为 0，那么左上角的位置可以取为 (-1,-1)，因为它实际上没有定义。


假设所有数字都是整数。如果有两个或两个以上最大对称子矩阵的左上角位置分别为 (i1,j1) 和 (i2,j2)，则如果 (i1 < i2) 或 (i1 == i2 且 j1 < j2) 则输出 (i1,j1)，否则输出 (i2,j2)。

输入
m,n // 表示输入矩阵的行数和列数
随后是 m x n 矩阵，其中有 m 行（每行一行）和 n 列
例如

3 4
0 1 1 0
1 0 0 1
1 0 2 3

输出：
g i j // 如果 g 是您的善值且 (i,j) 是对称子矩阵左上角的位置。

例如，上述输入的答案将是

3 1 1
*/
#include <stdio.h>
int min(int a, int b)
{
    return (a<b) ? a : b;
}
int main()
{
    int m,n,i,j,k,l,ans_i=-1,ans_j=-1,flag;
    int max_goodness = 0,curr_goodness, max_gp;
    scanf("%d%d",&m,&n);
    
    int M[m][n];
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            //checking whether an symmetric sub matrix begin at (i,j)                                        i.e. at i+1th row and j+1th column
            curr_goodness = 0;
            flag = 0;
            max_gp = min(m-i,n-j);
            for(k=0;k<max_gp;k++)
            {
                for(l=k;l>=0;l--)
                {
                    if(l==0)
                    {
                       continue;
                        
                    }
                    else
                    {
                        if(M[i+k][j+k-l] != M[i+k-l][j+k])
                        {
                            curr_goodness = k;
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag == 1)
                    break;
            }
            
            if (k == max_gp)
                curr_goodness = max_gp;

            if(curr_goodness > max_goodness)
            {
                max_goodness = curr_goodness;
                ans_i = i+1;
                ans_j = j+1;
                // printf("%d %d %d\n",ans_i,ans_j,max_goodness );
            }
        }
    }
    printf("%d %d %d\n", max_goodness, ans_i,ans_j );
    
}