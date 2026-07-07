#include "apc.h"

// Power Function
void power(node *tail1, node *tail2, node **headR, node **tailR)
{
    // Declaring temp pointers
    node *temphead1=NULL,*temptail1=NULL;
    node *temphead2=NULL,*temptail2=NULL;
    node *subhead=NULL,*subtail=NULL;
    node *subreshead=NULL,*subrestail=NULL;

    // Storing the
    node *mulhead=NULL,*multail=NULL;

    // Updating the two list as 1
    insert_first(&subhead,&subtail,1);
    insert_first(headR,tailR,1);

    // Updating the Operand1 to temphead1 list
    while(tail1!=NULL)
    {
        insert_first(&temphead1,&temptail1,tail1->data);
        tail1=tail1->prev;
    }

    // Updating the Operand2 to temphead2 list
    while(tail2!=NULL)
    {
        insert_first(&temphead2,&temptail2,tail2->data);
        tail2=tail2->prev;
    }

    // Running the loop untill Null
    while(!(temphead2->next==NULL && temphead2->data==0))
    {
        // Multiply the tailr and temptail1
        multiplication(*tailR,temptail1,&mulhead,&multail);

        // Delete the headr list
        delete_list(headR,tailR);

        // Updating the pointer
        *headR = mulhead;
        *tailR = multail;

        mulhead = NULL;
        multail = NULL;

        // Subtracting the temptail2 by subtail and storing in the temptail2
        subtraction(temptail2, subtail, &subreshead, &subrestail);
        delete_list(&temphead2, &temptail2);

        // Updating the
        temphead2 = subreshead;
        temptail2 = subrestail;

        subreshead = NULL;
        subrestail = NULL;

        // Removing the pre zeros in list
        remove_pre_zeros(&temphead2);
    }

    // Deleting the temp pointers
    delete_list(&temphead1, &temptail1);
    delete_list(&temphead2, &temptail2);
    delete_list(&subhead, &subtail);
}