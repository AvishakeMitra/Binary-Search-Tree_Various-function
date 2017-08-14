#include<stdio.h>
#define N 4

int adj_matrix[100][100],src,dest;
int path_dist[1000][2];
int tpath;
int k=0;

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int arr[][2], int n)
{
	
   int i, j;
   int temp[2];
   for (i = 0; i < n-1; i++) {     
    
       for (j = 0; j < n-i-1; j++) 
           if (arr[j][1]>arr[j+1][1])
		   {
			   temp[0]=arr[j][0];
			   temp[1]=arr[j][1];
			   arr[j][0]=arr[j+1][0];
			   arr[j][1]=arr[j+1][1];
			   arr[j+1][0]=temp[0];
			   arr[j+1][1]=temp[1];
		   }

   }	   
}

void print(int *num)
{
	int i=1;
	tpath=0;
	int dist_n=0;
	int newSrc=src;
	//printf("%d ->",src);
	
	while(adj_matrix[newSrc][num[i]]==1)
	{
	//printf("%d ->",num[i]);
	
	tpath=num[i]+tpath*10;
	
	dist_n++;
	newSrc=num[i];
	i++;
	if(newSrc==dest)
		break;
	}
	
	if(newSrc==dest)
	{
		
//		printf("The Distance of this path is %d \n",dist_n);
		
	    path_dist[k][0]=tpath;
		path_dist[k][1]=dist_n;
		k=k+1;
	
	}
}
	
void permute(int *a, int l, int r)
{
   int i;
   if (l == r)
	   print(a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i));
       }
   }
}


int main()
{
    
    int num[N];
    int *ptr;
    int temp;
    int i,j,kth,q;
	
    
	for (i = 0 ; i < N ; i++)
		num[i]=i;
	
	printf("Please enter the Source nodes : ");
	scanf("%d", &src);
	
	printf("Please enter the Destination nodes : ");
	scanf("%d", &dest);
	
	printf("Please enter K : ");
	scanf("%d", &kth);
	
	
	printf("\nEnter the graph as matrices : \n");
    for (i = 0 ; i < N; i++)
	{
		for(j = 0 ; j < N; j++)
		{
			
			scanf("%d ", &adj_matrix[i][j]);
		}
	}
			
    temp=num[src];
	num[src]=num[0];
	num[0]=temp;
    int newSrc=src;
	
	permute(num,1,N-1);
   		
	sort(path_dist,k);
	
	for(i = 0;i < k; ++i)
	{
		printf("\n%d-->%d",path_dist[i][0],path_dist[i][1]);
	}
	q=0;
	for(i = 0;i < k; ++i)
	{
		
		if(path_dist[i][1]!=0)
		{
			//printf("\nPath is :%d%d\twith distance :%d",src,path_dist[i][0],path_dist[i][1]);
			if(q<path_dist[i][1])
				q++;
			if(q==kth){
				printf("\nThe %dth shortest path is : %d%d  ",kth,src,path_dist[i][0]);
				break;
			}
			
		}
		
	}
	
	
	return 0;
}

