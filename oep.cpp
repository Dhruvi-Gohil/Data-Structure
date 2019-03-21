#include<stdio.h>
#include<malloc.h>	
#define SIZE 10
typedef struct list     //creating structure for linked list
{
      struct list *next;
      int val;  
}node;
struct stack     //creating structure for stack
{
      node* a[SIZE];
      int top;  
}s;
node* create(node *root)   //function for creating nodes
{
      int data;
      node *temp,*curr;
      root = NULL;
      printf("\n enter data:");
      scanf("%d",&data);
      while(data != 999)
      {
     temp = (node*)malloc(sizeof(node));
     temp->val = data;
     if(root == NULL)
     {
             temp->val = data;
             temp->next = NULL;
             root = temp;
             curr = temp;
     }
     else
     {
         temp->val = data;
         
         curr->next = temp;
         temp->next = NULL;
         curr = temp;
     }
      printf("\n enter data:");
      scanf("%d",&data);
      }
      return root;
     
}
void display_list(node *root)   //function to display linked list
{
     node *temp;
     temp = root;
     while(temp!=NULL)
     {
                   printf("%d ->",temp->val);
                   temp = temp->next;
     }
     
}
int isempty()       //to check whether stack is empty or not
{
      if(s.top == -1)
       
        return 1;
       else
           return 0;
       
}
int isfull()       //to check whether stack is full or not
{
     if(s.top == SIZE-1)
     
            return 1;
     else
         	 return 0;
}                       
void push(node *root)      //function to store values in stack
{
     if(isfull())
     {
      printf("\n stack is full you cnt enter values");
      }
     else
     {
      s.top++;
      s.a[s.top] = root;
     }
}
node* pop()
{
    node *temp;
    if(isempty())
    {
        printf("\n stack is empty you cnt delete values");
    }
    else
    {
        
        temp = s.a[s.top];
        s.top--;
        temp = temp->next;
        printf("\n the poped value = %d",temp->val);
    }
    return temp;
}
    

void display_stack()         //displaying final stack
{
     int i;
     printf("\nstored elements\n");
     for(i=s.top;i>=0;i--)
     {
        display_list(s.a[i]);
      printf("\n");
      }
}
void main()
{
    node *root[10];
    node *temp;
    s.top = -1;
    int i,n,del;
    printf("\n enter the size:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
   {
    printf("\n%d List\n",i+1);
	root[i] = create(root[i]);     //function call
     push(root[i]);             //pushing these nodes into stack
   }
   temp = pop();                  //calling pop function
  
   printf("\n displaying linked list");
   for(i=0;i<n;i++)
   {
       printf("\n");
       display_list(root[i]);
    }
   printf("\n displaying stack of linked list\n");  
   display_stack();
   
}
 


