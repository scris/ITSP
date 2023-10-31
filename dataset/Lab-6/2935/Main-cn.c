/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include
- Comments for non trivial code 
- Indentation: align your code properly 
- Function use and modular programming
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

将两个多项式相乘。

输入 ： 
第一行包含两个空格分隔的数字，n1 和 n2 - 分别是第一个和第二个多项式的度数。
第二行包含第一个多项式，即空格分隔的 (n1 + 1) 项。第 i 项是 x^(i-1) 的系数。x^n1 的系数将不为零。
第三行包含第二个多项式，即空间隔离的（n2 + 1）项。第 i 项是 x^(i-1) 的系数。x^n2 的系数将不为零。
每个系数都是 [-1000, 1000] 中的一个数字。

以类似格式输出第三个多项式。第一行是度数，下一行是系数。第 i 项应该是新多项式中 x^(i-1) 的系数。

限制条件 ： 
1 <= n1, n2 <= 15

Example:

Input:
2 2
3 1 -5
0 -2 4

(-5x^2 + x + 3)*(4x^2 - 2x) = -20x^4 + 14x^3 + 10x^2 - 6x + 0. So, output:
4
0 -6 10 14 -20
*/
#include<stdio.h>

int main (){
    int n1, n2, n;
    scanf ("%d %d", &n1, &n2);
    n = n1 + n2;
    printf ("%d\n", n);
    int p1[20], p2[20], p[40];
    for (int i=0;i<=n1;++i)scanf ("%d", &p1[i]);
    for (int i=0;i<=n2;++i)scanf ("%d", &p2[i]);
    
    for (int i=0;i<=n;++i)p[i] = 0;
    for (int i=0;i<=n1;++i){
        for (int j=0;j<=n2;++j){
            p[i+j]+=p1[i]*p2[j];
        }  
    }
    for (int i=0;i<=n;++i)printf ("%d ", p[i]);
    return 0;
}