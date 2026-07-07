#include "apc.h"

// Division Function
void division(node *headL1, node *head_OPR2,node *tail_OPR2, node **headR, node **tailR)
{
    // Declaring the temp pointer.
    int sub_count=0;
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
    // Running loop untill l_temp become null.
    while(l_temp!=NULL)
    {
        // For taking each number int untill greater than operand2
        sub_count=0;
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
            sub_count++;
        }
        // Inserting Quotient(sub_count) in the list.
        insert_last(headR,tailR,sub_count);

        // Updating for operand1
        l_temp=l_temp->next;
        if(l_temp!=NULL)
        {
            insert_last(&head_OPR1,&tail_OPR1,l_temp->data);
            remove_pre_zeros(&head_OPR1);
        }
    }
    // Freeing the temp Pointer
    free(head_OPR1);
}

