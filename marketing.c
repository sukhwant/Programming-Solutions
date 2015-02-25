/*
	problem: http://community.topcoder.com/stat?c=problem_statement&pm=1524&rd=4472
	Graph - DFS
*/

#include<stdio.h>

#define G 1000
#define RED 2
#define BLUE 3
#define TRUE 1
#define FALSE 0

int graph[G][G],connectedCount = 0;
	
void printGraph(int size)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			printf("%d ",graph[i][j]);
		printf("\n");
	}
}

int changeColor(int color)
{
	if(color==RED)
		return BLUE;
	else if(color==BLUE)
		return RED;
}

int dfs(int size,int start)
{
	int stack[G],top=-1,current,color[G]={0},visited[G]={0},i;
	
	stack[++top]=start;
	color[start]=RED;
	visited[start]=TRUE;
	
	while(top>=0)
	{
		current = stack[top--];
		connectedCount++;
		
		// add neighbours.
		for(i=0;i<size;i++)
		{
			if(graph[current][i]==1 && visited[i] == FALSE)
			{
				// Mark as visited.
				visited[i]=TRUE;
				if(color[i]==color[current])
				{
					// Not Possible.
					return 0;
				}
				// Push to stack.
				stack[++top]=i;
				//Assign opposite color.
				color[i]=changeColor(color[current]);
			}
		}
	}
	// Possible.
	return 1;
}

int main(){

	int total_products,i,ans;
	
	scanf("%d",&total_products);
	for(i=0;i<total_products;i++)
	{
		int num_competitor,temp,j;
		scanf("%d",&num_competitor);
		
		for(j=0;j<num_competitor;j++)
		{
			scanf("%d",&temp);
			graph[i][temp]=1;
			graph[temp][i]=1;
		}
	}
	
	//printGraph(total_products);
	
	if(dfs(total_products,0))
	{
		ans=2;	
		ans =  ans << (total_products-connectedCount);
		printf("%d\n",ans);
	}
	else
	{
		printf("-1");
	}
	
	return 0;
}
