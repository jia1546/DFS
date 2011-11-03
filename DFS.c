#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *next;
};
typedef struct node node;

int time = 0;

void linkedList(node **array, int n, int p)
{
	int x, y, i;
	
	for(i=1; i<=n; i++)
	{
		array[i] = (node*)malloc(sizeof(node));
		array[i] -> num = i;
		array[i] -> next = NULL;
	}
	
	for(i=1; i<=p; i++)
	{
		scanf("%d%d", &x, &y);
		node *newNode = (node*)malloc(sizeof(node));
		newNode -> num = y;
		newNode -> next = array[x] -> next;
		array[x] -> next = newNode;
	}
	
	printf("the linked list representation of the graph is:\n");
	for(i=1; i<=n; i++)
	{
		printf("%d: ", i);
		node *tmp = array[i] -> next;
		while(tmp != NULL)
		{
			printf("%d ", tmp -> num);
			tmp = tmp -> next;
		}
		printf("\n");
	}
}

void DFS_init(int *color, int *PI, int *discover, int *finish, int n)
{
	int i;
	for(i=1; i<=n; i++)
	{
		color[i] = -1;	//-1 represents WHITE, 0 represents GRAY, 1 represents BLACK
		PI[i] = -1;
		discover[i] = -1;
		finish[i] = -1;
	}
}

void DFS(node **array, int u, int *color, int *PI, int *discover, int *finish)
{
	printf("run DFS on node %d\n", u);
	discover[u] = time = time + 1;
	color[u] = 0;
	
	node *tmp = array[u] -> next;
	while(tmp != NULL)
	{
		if(color[tmp->num] == -1)
		{
			PI[tmp->num] = u;
			DFS(array, tmp->num, color, PI, discover, finish);
		}
		tmp = tmp -> next;
	}
	color[u] = 1;
	finish[u] = time = time + 1;
}

int main()
{
	int n, p, i;
	int *color, *PI, *discover, *finish;
	node **array;
	scanf("%d%d", &n, &p);
	array = (node**)malloc(sizeof(node*) * (n+1));
	color = (int*)malloc(sizeof(int) * (n+1));
	PI = (int*)malloc(sizeof(int) * (n+1));
	discover = (int*)malloc(sizeof(int) * (n+1));
	finish = (int*)malloc(sizeof(int) * (n+1));
	
	linkedList(array, n, p);
	DFS_init(color, PI, discover, finish, n);
	
	printf("\nthe process of DFS:\n");
	for(i=1; i<=n; i++)
		if(color[i] == -1)
			DFS(array, i, color, PI, discover, finish);	
		
	printf("\nnode:\t\t");
	for(i=1; i<=n; i++)
		printf("%d\t", i);
	printf("\n");
	
	printf("color:\t\t");
	for(i=1; i<=n; i++)
		printf("%d\t",color[i]);
	printf("\n");
	
	printf("PI:\t\t");
	for(i=1; i<=n; i++)
		printf("%d\t",PI[i]);
	printf("\n");
	
	printf("discover time:\t");
	for(i=1; i<=n; i++)
		printf("%d\t",discover[i]);
	printf("\n");
	
	printf("finish time:\t");
	for(i=1; i<=n; i++)
		printf("%d\t",finish[i]);
	printf("\n");	
	return 0;
}
