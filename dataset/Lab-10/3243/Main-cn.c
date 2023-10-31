/*
给定一个字符串 w，重新排列 w 的字母，以构建另一个字符串 s，使 s 在词法上大于 w。如果给定的输入没有更大的字符串，则打印 "No Answer"。如果有多个可能的答案，则找出词典上最小的一个并打印出来。词典顺序如下：
"a"<"b"，"aa"<"ab"，"ab"<"da"，"dac"<"dca"。

注意：字符串只包含小写字母。字符串的大小由用户指定，并使用动态内存分配。

输入格式：第一行包含字符串的大小，下一行包含字符串本身。
输出格式：从所有可能的词性较大的字符串中打印出词性最小的字符串。

输入样例： 
2
ab
输出样例：
ba 
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d\n", &n);
    char * s = (char *)malloc((n + 1) * sizeof(char));
    for(int i = 0; i < n; i++)
        scanf("%c", (s + i));
    *(s + n) = '\0';    
    int * a = (int *)calloc(n, sizeof(char));
    for(int i = 0; i < n; i++)
        *(a + i) = *(s + i) - 'a';
    int i = n - 1;
    while(i > 0 && *(a + i - 1) >= *(a + i))
        i--;
    if(i <= 0){
        printf("No Answer");
    }
    else{
        int l = n - 1;
        while(*(a + l) <= *(a + i - 1))
            l--;
        int tmp = *(a + i - 1);
        *(a + i - 1) = *(a + l);
        *(a + l) = tmp;
        l = n - 1;
        while(i < l){
            tmp = *(a + i);
            *(a + i) = *(a + l);
            *(a + l) = tmp;
            i++;
            l--;
        }
        for(i = 0; i < n; i++)
            *(s + i) = *(a + i) + 'a';
        printf("%s", s);    
    }
    return 0;
}