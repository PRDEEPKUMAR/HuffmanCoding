///Creating the Priority Queue(Min Heap freq Structure) using structure.
///This can be use as Auxiliary freq Structure for other Algorithms
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *left;
    struct Node *right;
    int freq;
    char ch;
};
typedef struct Node Node;
Node* createNode()
{
    Node* A=(Node*)malloc(sizeof(Node));
    A->left=NULL;
    A->right=NULL;
    return A;
}
void heapify(Node *A[],int i ,int n)
{
    Node *t=NULL;
    int l=2*i;
    int r=2*i+1;
    int lar=i;
    if(l<=n)
    {
    if(A[lar]->freq>A[l]->freq)
    {
       lar=l;
    }
    }
    if(r<=n)
    {
        if(A[lar]->freq>A[r]->freq)
    {
        lar=r;
    }
    }
    if(lar!=i)
    {
        t=A[lar];
        A[lar]=A[i];
        A[i]=t;
        heapify(A,lar,n);
    }
}
void Build_Max_Heap(Node *A[],int n)
{
     int i=0;
    for(i=n/2;i>0;i--)
    {
        heapify(A,i,n);
    }

}
Node* DeleteHeap(Node *A[],int *n)
{
    Node *temp;
    temp=A[1];
    A[1]=A[*n];
    (*n)--;
    if(*n!=0)
    heapify(A,1,*n);
    return temp;

}
void display(Node *A[],int n)
{
    int i;
    for(i=1;i<=n;i++)
        printf("\n%c--%d\n",A[i]->ch,A[i]->freq);
}
void insert_heap(Node *A[],int *n,Node *item)
{
     (*n)++;

    int i=*n;
    if(i>1)
    {
    while(item->freq<A[i/2]->freq&&i>1)
    {
        A[i]=A[i/2];
        i=i/2;
        if(i==1)
            break;
    }
    }

    A[i]=item;

}
void generateArray(Node *A[],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        A[i]=createNode();
    printf("Enter the character and frequency :-");
    scanf(" %c",&A[i]->ch);
    scanf("%d",&A[i]->freq);
    }
}
void HuffmanCoding(Node *A[],int *n,int size)
{
    int i;
    for(i=1;i<=size-1;i++)
    {
    Node *x=DeleteHeap(A,n);
    Node *y=DeleteHeap(A,n);
    Node *z=createNode();
    z->ch='+';

    z->freq=x->freq+y->freq;
    if(x->freq>y->freq)
    {
        z->right=x;
        z->left=y;
    }
    else
    {
        z->right=y;
        z->left=x;
    }
    insert_heap(A,n,z);
    }

}
void preOrder(Node *t)
{
    if(t==NULL)
        return ;
    printf("%c %d\t",t->ch,t->freq);
    preOrder(t->left);
    preOrder(t->right);
}
void inOrder(Node *t)
{
    if(t==NULL)
        return ;
    inOrder(t->left);
    printf("%c %d\t",t->ch,t->freq);
    inOrder(t->right);
}
void printCodes(int Arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d",Arr[i]);
}
void generateHuffmanCode(Node * root,int arr[],int i)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->right==NULL&&root->left==NULL)
    {
        printf("%c   :",root->ch);
        printCodes(arr,i);
        printf("\n");
    }
    if(root->left)
    {
        arr[i]=0;
    generateHuffmanCode(root->left,arr,i+1);
    }
    if(root->right)
    {
        arr[i]=1;
    generateHuffmanCode(root->right,arr,i+1);
    }
}

int main()
{
    int i,n;
    Node *A[100]={NULL};
    A[0]=NULL;
    Node *t1=NULL,*t2,*t3;
    int arr[100]={-1};
    printf("Enter the number of character :");
    scanf("%d",&n);
    int size=n;
    generateArray(A,n);
   Build_Max_Heap(A,n);
     display(A,n);
   HuffmanCoding(A,&n,size);

//    printf("\npreOrder :");
 //   preOrder(A[1]);
 //   printf("\nInOrder :");
  //  inOrder(A[1]);
  //  printf("\nHuffmanCode :\n");
    generateHuffmanCode(A[1],arr,0);
    return 0;
}
