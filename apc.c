#include "apc.h"
// Function definitions

// Checking the Valid Operator
int symbolcheck(int i,char *argv[])
{
    int res=0;
    if(argv[i][0]=='+')
    {
        res=0;
        argv[i][0]='0';
    }
    if(argv[i][0]=='-')
    {
        res=1;
        argv[i][0]='0';
    }
    // Checking the symbol of both operands
    return res;
}

// Validating the arguments
int cla_validation(int argc, char *argv[])
{
    // Checking the Operand1 is valid
    for(int i=0;argv[1][i];i++)
    {
        if(operandcheck(argv[1][i])==FAILURE)
        {
            printf("Invalid Operand1\n");
            printf("Usage apc.out operand1 operator operand2\n");
            return FAILURE;
        }
    }
    // Checking the operator
    if(argv[2][1]!='\0')
    {
        printf("Invalid Operator\n");
        printf("Usage apc.out operand1 operator operand2\n");
        return FAILURE;
    }
    // Checking the operator
    if(operatorcheck(argv[2][0])==FAILURE)
    {
        printf("Invalid Operator\n");
        printf("Usage apc.out operand1 operator operand2\n");
        return FAILURE;
    }
    // Checking the Operand2 is valid
    for(int i=0;argv[3][i];i++)
    {
        if(operandcheck(argv[3][i])==FAILURE)
        {
            printf("Invalid Operand2\n");
            printf("Usage apc.out operand1 operator operand2\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}
// Function to check Operand between 0 to 9
int operandcheck(char digit)
{
    if(digit>='0' && digit<='9')
    {
        return SUCCESS;
    }
    return FAILURE;
}
// Function to check Operator is +,-,*(x,X),/,%,^
int operatorcheck(char opr)
{
    // Checking the valid operator
    switch(opr)
    {
        case '+': 

        case '-': 

        case 'x': 

        case '*': 

        case 'X': 

        case '/': 

        case '%': 

        case '^': return SUCCESS;
        
        default: return FAILURE;
    }
}
// Function to create the list and update the operands
void create_list(char *opr, node **head, node **tail)
{
    for(int i=0;opr[i];i++)
    {
        // convert each char to integer
        int digit=opr[i]-'0';
        int check=insert_last(head,tail,digit);
        if(check!=SUCCESS)
        {
            printf("ERROR in OPERAND Conversion\n");
            exit(1);
        }
    }
}
// Function to add integer in last
int insert_last(node **head, node **tail, int data)
{
    node *newnode=malloc(sizeof(node));
    if(newnode==NULL)
    {
        return FAILURE;
    }
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        *tail=newnode;
        return SUCCESS;
    }
    (*tail)->next=newnode;
    newnode->prev=*tail;
    *tail=newnode;
    return SUCCESS;
}
// Function to print the operand
void print_list(node *head)
{
    if(head==NULL)
    {
        printf("INFO: List is Empty\n");
        return;
    }
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
    printf("\n");
}
// Function to add integer in first
int insert_first(node **head, node **tail, int data)
{
    node *newnode=malloc(sizeof(node));
    if(newnode==NULL)
    {
        return FAILURE;
    }
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        *tail=newnode;
        return SUCCESS;
    }
    (*head)->prev=newnode;
    newnode->next=*head;
    *head=newnode;
    return SUCCESS;
}
// function Comparing the two list
int compare_list(node *head1, node *head2)
{
    int count1=list_len(head1);
    int count2=list_len(head2);
    // Checking Biggest list
    if(count1>count2)
    {
        return OPERAND1;
    }
    else if(count2>count1)
    {
        return OPERAND2;
    }
    // Checking biggest list by comparing each integer
    while(head1!=NULL)
    {
        int sum=head1->data - head2->data;            
        if(sum<0)
        {
            return OPERAND2;
        }
        else if(sum>0)
        {
            return OPERAND1;
        }
        head1=head1->next;
        head2=head2->next;       
    }
    // Both list are same 
    return SAME;
}
// Fuction to find length of the list
int list_len(node *head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}
// Function to remove the pre zeroes in the list
void remove_pre_zeros(node **head)
{
    if(*head==NULL)
    {
        printf("INFO: List is Empty\n");
        return;
    }
    while((*head)->data==0 && (*head)->next!=NULL)
    {
        *head=(*head)->next;
        free((*head)->prev);
        (*head)->prev=NULL;
    }
}
// Funcion to delete the full List
int delete_list(node **head, node **tail)
{
    if(*head==NULL || *tail==NULL)
    {
        return FAILURE;
    }
    if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
        *tail=NULL;
        return SUCCESS;
    }
    node *temp=*head;
    node *nextnode=NULL;
    while(temp!=NULL)
    {
        nextnode=temp->next;
        free(temp);
        temp=nextnode;
    }
    *head=NULL;
    *tail=NULL;
    return SUCCESS;
}