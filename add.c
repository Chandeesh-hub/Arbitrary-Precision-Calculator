#include "apc.h" 

// Addition Function 
void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    // Declaring sum and carry
    int sum=0,carry=0;
    // Declaring two pointer
    node *temp1=tail1;
    node *temp2=tail2;

    // Running loop untill both list empty
    while(temp1!=NULL || temp2!=NULL)
    {
        // Updating sum
        sum=carry;
        if(temp1!=NULL)
        {
            sum=sum+temp1->data;
            temp1=temp1->prev;
        }
        if(temp2!=NULL)
        {
            sum=sum+temp2->data;
            temp2=temp2->prev;
        }
        // Adding both number and store in the result list.
        // updating carry.
        carry=sum/10;
        insert_first(headR,tailR,sum%10);
    }
    // Adding carry at last
    if(carry)
    {
        insert_first(headR,tailR,carry);
    }
}
