#include "apc.h"

// Modulo Function
void modulo(node *headL1, node *head_OPR2,node *tail_OPR2, node **headR, node **tailR)
{
    // Declare temp pointer
    node *head_OPR1=NULL,*tail_OPR1=NULL;
    node *l_temp=headL1,*head_SR=NULL,*tail_SR=NULL;

    // Adding  the 1st digit of the 1st list.
    insert_last(&head_OPR1,&tail_OPR1,l_temp->data);

    // Updating the list untill temp pointer greater than operand2
    while(compare_list(head_OPR1,head_OPR2)==OPERAND2 && l_temp)
    {
        // Updating the temp pointer as operand1
        l_temp=l_temp->next;
        if(l_temp!=NULL)
        {
            insert_last(&head_OPR1,&tail_OPR1,l_temp->data);
        }
        // Removing the Pre zero in list.
        remove_pre_zeros(&head_OPR1);
    }
    while(l_temp!=NULL)
    {
        // For taking each number int untill greater than operand2
        while(compare_list(head_OPR1,head_OPR2)==OPERAND1 || compare_list(head_OPR1,head_OPR2)==SAME)
        {
            // performing subtraction
            subtraction(tail_OPR1,tail_OPR2,&head_SR,&tail_SR);
            delete_list(&head_OPR1,&tail_OPR1);
            
            // Removing pre zeros And updating pointer
            remove_pre_zeros(&head_SR);
            head_OPR1=head_SR;
            tail_OPR1=tail_SR;

            head_SR=NULL;
            tail_SR=NULL;
        }
        // Updating for operand1
        l_temp=l_temp->next;
        if(l_temp!=NULL)
        {
            insert_last(&head_OPR1,&tail_OPR1,l_temp->data);
            remove_pre_zeros(&head_OPR1);
        }
    }
    // Running the loop to Update the remainder to result head and tail.
    while(head_OPR1!=NULL)
    {
        insert_last(headR,tailR,head_OPR1->data);
        head_OPR1=head_OPR1->next;
    }
    // Freeing the Temp pointer
    free(head_OPR1);
}