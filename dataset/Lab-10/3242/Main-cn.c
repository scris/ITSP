/*
行列式是方阵的一个非常重要的性质。有趣的是，它可以通过递归方式计算如下：
让我们定义 M(j,k) = 不包含第 j 行和第 k 列的 A 的子矩阵。我们可以如下计算 det(A)

det(A) = 任何一行或一列的总和 (((-1)^(j + k)) * det( M(j,k) ).
也就是说，在应用上述递推公式时，j 或 k 中的一个固定不变。

举例说明：对于 3x3 矩阵 A，我们可以在固定 j=1 和改变 k 的情况下使用上式：
det(A) = det(M(1,1)) - det(M(1,2)) + det(M(1,3)) 。

输入：
表示正方形矩阵大小的整数 n。
由 n 个整数组成的 n 行，每行表示矩阵的内容。

输出：
矩阵的行列式。

你需要编写一个 C 语言程序来计算矩阵的行列式。
*/
#include <stdio.h>
#include <stdlib.h>

/*
   Recursive definition of determinate using expansion by minors.
*/

int Determinant(int **a,int n)
{
   int i,j,j1,j2;
   int det = 0;
   int **m = NULL;

   if (n < 1) { /* Error */

   } else if (n == 1) { /* Shouldn't get used */
      det = *(*(a + 0) + 0);
   } else if (n == 2) {
      det = (**a) * *(*(a + 1) + 1) - **(a + 1) * *(*a + 1);
   } else {
      det = 0;
      for (j1=0;j1<n;j1++) {
         m = malloc((n-1)*sizeof(int *));
         for (i=0;i<n-1;i++)
            m[i] = malloc((n-1)*sizeof(int));
         for (i=1;i<n;i++) {
            j2 = 0;
            for (j=0;j<n;j++) {
               if (j == j1)
                  continue;
               m[i-1][j2] = *(*(a + i) + j);
               j2++;
            }
         }
         det += pow(-1,1+j1+1) * *(*a + j1) * Determinant(m,n-1);
         for (i=0;i<n-1;i++)
            free(m[i]);
         free(m);
      }
   }
   return(det);
}


int main(){

	int n ,i, j; 
	scanf("%d" , &n);

	int **m = malloc((n)*sizeof(int *));
	for (i=0 ; i<n ; i++)
            m[i] = malloc((n)*sizeof(int));

    // Scanning the matrix
    for (i=0;i<n;i++)
    	for (j = 0 ; j < n ; j++)
    		scanf("%d" , *(m + i ) +  j);

    printf("%d" , Determinant(m , n ));
    return 0;
}