#include "apc.h"

// Multiplication function
void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    // Declaring pointer to assign for operand1 and operand2
    // Declaring varibale for storing carry and multiply result
    int count=0,flag=1,mul,carry=0;
    node *temp1=tail1;
    node *temp2=tail2;

    // Declaring temp pointer for storing result
    node *head=NULL;
    node *tail=NULL;

    // Declaring temp pointer for storing Addition result
    node *headAR=NULL;
    node *tailAR=NULL;

    // Running untill list 2 is empty.
    while(temp2!=NULL)
    {
        head=NULL;
        tail=NULL;
        temp1=tail1;
        carry=0;
        // Storing 0 in result list for addition
        for(int i=0;i<count;i++)
        {
            insert_first(&head,&tail,0);
        }
        // Running the loop until temp1 is Null
        while(temp1!=NULL)
        {
            // Storing the Mulitply value.
            mul=carry+(temp1->data * temp2->data);
            if(flag)
            {
                // when flag is 1 storing result in headR,tailR
                insert_first(headR,tailR,mul%10);
            }
            else
            {
                // When flag is 0 storing result in temp head,tail
                insert_first(&head,&tail,mul%10);
            }
            carry=mul/10;
            temp1=temp1->prev;
        }
        // Adding the carry at last
        if(carry)
        {
            if(flag)
            {
                insert_first(headR,tailR,carry);
            }
            else
            {
                insert_first(&head,&tail,carry);
            }
        }
        if(flag==0)
        {
            // Adding the present and previous result
            addition(tail,*tailR,&headAR,&tailAR);

            // Deleting the temp list
            delete_list(&head,&tail);
            delete_list(headR,tailR);

            // Updating the pointer 
            *headR=headAR;
            *tailR=tailAR;

            head=NULL;
            tail=NULL;

            headAR=NULL;
            tailAR=NULL;
        }
        // Update the flag and increment the count 
        flag=0;
        temp2=temp2->prev;
        count++;
    }
}

