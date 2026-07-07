#include "apc.h"

// Subtraction Function
void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    // Declaring two pointer and borrow, sub
    int borrow=0,sub=0;
    node *temp1=tail1;
    node *temp2=tail2;
    int digit1=0,digit2=0;

    // Running loop untill 1st list empty
    while(temp1!=NULL)
    {
        // Storing each list each integer of list in digit1
        digit1=temp1->data;
        if(temp2!=NULL)
        {
            digit2=temp2->data;
        }
        else
        {
            // If 2nd list is empty store as zero.
            digit2=0;
        }
        // Checking borrow
        if(borrow==1)
        {
            digit1=digit1-1;
        }
        // checking digit1 is less than digit2 and update digit1 and borrow.
        if(digit1 < digit2)
        {
            borrow=1;
            digit1=digit1+10;
        }
        else
        {
            borrow=0;
        }
        // Subtracting the two digit.
        sub=digit1-digit2;
        insert_first(headR,tailR,sub);
        
        // updating temp2 pointer untill null.
        if(temp2!=NULL)
        {
            temp2=temp2->prev;
        }
        temp1=temp1->prev;
    }
}
