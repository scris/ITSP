/*

我们的一位名叫 A 的辅导员打字很差。他试着不看键盘就打字，结果犯了很多错误。例如，他有时会把 "hello "打成 "helli"，把 "chariman "打成 "chairman"，等等。 A 非常伤心，因为他无法快速撰写邮件和试卷等。 请你帮 A 写一个程序，告诉他输入的单词在词典中最接近的单词。

两个词串 s1 和 s2 的接近度计算如下：
1. 如果 length(s1) = length(s2)，则额外得到 1 个接近点。
2. 对于 s1[j] = s2[j]，每个 j 都会得到 2 个额外点。
3. 对于 s1[j] != s2[j]的每个 j，如果 s1[j] 存在于 s2 中，而 s2[j] 存在于 s1 中，则可获得 0.5 个附加点。如果 j >= length(s1)，但 j < length(s2)，则只需检查 s2[j] 是否存在于 s1 中，同样，如果 j < length(s1)，且 j >= length(s2)，也只需检查 s2[j] 是否存在于 s1 中。

例如，"hello"和 "helobo"之间的相似度为 7.0。接近度参数越小，字符串就越接近！)

输入 ： 
输入字典的大小 N。之后会有 N 行，每行都有一个数字，后面跟一个字符串。数字表示字符串的长度。这 N 行就是字典的内容。
接下来是字符串长度和字符串对，这些字符串对是要根据字典中的近似程度进行修正的单词。输入的词对应一直处理到出现-1为止。
 
输出：
打印字典中与每个长度、字符串对相对应的最接近的字符串。如果字典中存在多个与输入单词同样接近的单词，则输出较早添加到字典中的单词。

示例
输入 ： 
3
2 hi
3 hey
4 yoyo
2 hi
3 hiy
4 yoy
1 h
-1

输出 ：
hi 
hey
yoyo 
hi

注意 ： 
在字典中，"hi"和 "Hi"应视为不同的单词。作为练习，你可以让程序不区分大小写。有许多启发式方法可用于根据字典纠正错误的单词。为这个问题定义的近似度量就是其中之一。可能还有更好的启发式方法。

*/
#include <stdio.h>
#include <stdlib.h>

int get_len(char s[])
{
	int i = 0 ; 
	while(*(s + i) != '\0')
		i++;

	return i ; 
}

int exists(char *a , char ch){
	int i = 0 ; 
	while(a[i] != '\0')
	{
		if(a[i] == ch)
			return 1; 
		i++; 
	}

	return 0;
}

float get_closeless(char *a, char *b)
{
	float closeness = 0 ;
	int i , j;

	int a_len = get_len(a) , b_len = get_len(b); 

	if(a_len == b_len)
		closeness += 1; 

	for(i = 0 ; i < a_len || i < b_len ; i++)
		if(i < a_len && i < b_len)
		{	if(a[i] == b[i])
				closeness += 2;
			else {if (exists(b , a[i]) && exists(a , b[i]))
				closeness += 0.5;}	
		}
		else{
			if(i < a_len){
				if(exists(b, a[i]))
				{ 
					closeness += 0.5; 
				}
			}
			else if(exists(a, b[i])){
				closeness += 0.5;
			}

		}

	return closeness ; 
}

int get_closest_word(char *s, char **dict){
	int i = 0 ; 
	int max_closeness = - 1; 
	int max_closeness_index = -1;
	while(dict[i] != NULL ){
		if(get_closeless(s , dict[i]) > max_closeness){
			max_closeness = get_closeless(s, dict[i]) ; 
			max_closeness_index = i ; 
		}
		i++;
	} 
	return max_closeness_index ;
} 

int main(){
	int n, n_temp , e_len, i, j;
	char *error_word = NULL ;

	scanf("%d" , &n);

	char **dict = malloc((n + 1)*sizeof(int *));
	for (i=0 ; i<n ; i++){
			scanf("%d" , &n_temp);
            dict[i] = malloc((n_temp + 1)*sizeof(int));
            scanf("%s" , dict[i]);
        }
    dict[n] = NULL ;

    while(1){
    	scanf("%d" , &n_temp);
    	if(n_temp == - 1)
    		break;

    	free(error_word);
    	error_word = malloc((n_temp + 1)*sizeof(char));
    	scanf("%s", error_word);
    	printf("%s\n",dict[get_closest_word(error_word , dict)]);
    	
    }
    return 0;

}