/*
-------------------------------------------- 
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for non-trivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template. 
 - You are required to allocate memory Dynamically instead of static memory allocation otherwise you might get 0. 
 - Use of C Structures is mandatory. A suitable structure is already given to you, you may use it wherever required.
---------------------------------------------


抽象地说，图（Graph）是由非负整数标注的顶点和边组成的集合。如果我们只讨论顶点 i 和 j 之间是否存在边，而不讨论它的方向，那么这个图就叫做无向图。

在本题中，我们将给出无向图中的边。边是一对非负整数 (i，j)，表示顶点 i 通过一条边与顶点 j 相连。例如，(1,2) 表示顶点 1 和 2 通过一条边相互连接（同时，1,2 也是彼此的邻居）。

然后，您将得到一个顶点编号 n。您必须按照输入边的顺序，输出与 n 有边相连的顶点列表。

输入格式：
您将得到以下内容。

1. 第一行包含一个介于 1 和 1000 之间的整数 E。

2. 2. 接下来是 E 行，每行包含一对数字 i 和 j，其中 i 和 j 都是非负整数 n <= 34,000. 任何一条边都不会重复出现。

3. 最后一行包含一个非负整数 n <= 34,000。n 肯定是第 (2) 部分 E 行中列出的一个顶点。

输出格式：
您必须按照输入的顺序输出 n 有边的节点列表，每个顶点一行。

注意：您不能初始化一个巨大的矩阵（顶点数 * 顶点数），因为它无法保存在内存中。但您完全可以将顶点的相邻元素存储为一个链接列表，并在需要时动态增长。

例如
如果输入：
5
1 2
1 3 
2 4
2 5
5 1
1
那么将输出：
2
3
5

说明： 第 2 行表示顶点 1 和顶点 2 是邻居： 
第 2 行表示顶点 1 和顶点 2 是邻居。
第 3 行表示顶点 1 和顶点 3 是邻居。
第 6 行表示顶点 5 和顶点 1 是邻居。
因此，顶点 1 的邻居是 2、3、5。
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int vertex;
	struct node *next;
};

struct list_entry{
	struct node *head;
	struct node *tail;
};

struct list_entry list_entries[34000];

void init_list_entries()
{
	int i;
	for ( i=0 ; i<100 ; i++ ){
		list_entries[i].head = 
			list_entries[i].tail =
			NULL;
	}
}
struct node * make_node ( int data )
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp -> vertex = data;
	temp -> next = NULL;
	return temp;
}
void insert_at_end(int a, int b)
{
	struct node *node1;
	struct node *node2;

	node1 = make_node (a);
	if(list_entries[b].head == NULL){
		list_entries[b].head = node1;
		list_entries[b].tail = node1;
	}else{
		list_entries[b].tail->next = node1;
		list_entries[b].tail = node1;
	}

	node2 = make_node(b);
	if(list_entries[a].head == NULL){
		list_entries[a].head = node2;
		list_entries[a].tail = node2;
	}else{
		list_entries[a].tail->next = node2;
		list_entries[a].tail = node2;
	}
	return;
}
void print_adjacent_vertices_of(int n)
{
	struct node *current = list_entries[n].head;

	while(current != NULL){
		printf("%d\n",current->vertex);
		current = current->next;
	}
	return;
}
int main()
{
	int num_edges;
	int a;
	int b;
	int n;
	int i=0;

	scanf("%d", &num_edges);
	for ( i=0; i<num_edges ; i++) {
		scanf ( "%d", & a);
		scanf ( "%d", & b);
		insert_at_end(a,b);
	}

	scanf("%d",&n);
	print_adjacent_vertices_of(n);
}
