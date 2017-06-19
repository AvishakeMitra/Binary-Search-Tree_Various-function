#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node *left;
    struct node *right;
    
}Node;

Node* insert(Node *n,Node *t)
{
	if(!t)
	    return n;
	if(n->item < t->item)
	{
		if(!t->left)
		    t->left=n;
			
		insert(n,t->left);
	}
	else if(n->item > t->item)
	{
		if(!t->right)
			t->right=n;
			
		insert(n,t->right);
	}
	return t;
}

int inorder(Node *t)
{
    if(t!=NULL)
    {
    
        inorder(t->left);
        printf("%d ",t->item);
        inorder(t->right);
        
    }
}

int countLeaves(Node *t)
{
    if(!t) return 0;
    if(!t->left && !t->right) return 1;
    else return(countLeaves(t->left)+countLeaves(t->right));
}

int countNode(Node *t)
{
    if(!t) return 0;
    else return(1+countNode(t->left)+countNode(t->right));
}

int treeHeight(Node *t)
{   
    int l,r;
    if(!t)return 0;
    if(!t->left && !t->right)return 0;
    else 
    {
        l=treeHeight(t->left);
        r=treeHeight(t->right);
        return(1+(l>r?l:r));
    }
}

int fullNode(Node *t)
{
    if(!t) return 0;
    if(t->right && t->left)
    return (1+fullNode(t->left)+fullNode(t->right));
    else return 0;
}

int searchKey(Node *t,int key)
{	
	
    if(!t)return 0;
    if(t->item == key) return 1;
    if(key>t->item)
    return searchKey(t->right,key);
    else return searchKey(t->left,key);
    
}


int arr[100];
int inorder_sucessor(Node *t,int root_item)
{
    static int i=0;
    if(t!=NULL)
    {
         inorder_sucessor(t->left,root_item);
         arr[i++]=t->item;
         if(root_item==arr[i-2])
         return arr[i-1];
         inorder_sucessor(t->right,root_item);
         
    }
}

int min(Node *t)
{
    if(!t)return 0;
    if(t->left==NULL) return t->item;
    else
    return min(t->left);
}

int main(void) 
{
   	int n,i,x;
   	Node *new1=NULL;
	Node *tree=NULL; //Root node

	printf("Enter how many data you want to insert : ");
	scanf("%d",&n);
	printf("Enter data one by one : ");
	
	for(i=1;i<=n;i++)
	{
	    scanf("%d",&x);
	    new1=(Node*)calloc(1,sizeof(Node));
    	    new1->item=x;
    	    tree=insert(new1,tree);
	}
	printf("The INORDER TRAVERSAL OF THE TREE IS : ");
	inorder(tree);
	printf("\nNo of leaves in the tree : %d \n",countLeaves(tree));
	printf("No of nodes in the tree : %d \n",countNode(tree));
	printf("Height of the tree is : %d \n",treeHeight(tree));
   	printf("No of fullNode is the tree is : %d \n",fullNode(tree));
        if(searchKey(tree,35))
        	printf("Item found\n");
        else 
	    	printf("Item not found\n");
    printf("Min Node Value is the tree is : %d \n",min(tree));
    printf("The INORDER SUCESSOR of THE ROOT NODE IS : %d \n",inorder_sucessor(tree,tree->item));
  
  
}
