/*********************************************************************************************************
	Name : : Chandeesh K M
	Date : : 30/06/2026
	Description : : This code is the main code for implementation the Arbitrary Precision 
	Calculator (APC) to perform operations such as Addition, Subtraction, Multiplication,
	Division, Power and Modulo on very large integers that exceed the storage capacity of 
	int and long int. Instead of storing the entire number in a single variable, creating
	a doubly linked list and storing the integer from command line arguments and converting
	the string into integer in the doubly linked list and storing the operator. It store
	large numbers as input, converts them into linked lists, performs operation, and 
	displays the result. Based on the operation selected, the program calls the respective
	arithmetic function. In addition function the data is added from the last and store in 
	the result list using insert at first function with help of carry. In Subtraction function
	at first finding the biggest list and subtracting the data and store in the result list 
	using insert at first with help of borrow. In Multiplication function multiply the one 
	digit of list2 to all number of list1 and storing in a list using addition function. In
	Division function check the operand2 is 0 ,if yes return Zero division Error, if not find
	the biggest number in operand .If operand2 is biggest return 0 else perform division on
	operand1 using subtraction function and store the Quotient in result list. In Modulo 
	Function check the operand2 is 0, if yes return Zero division Error, else using the
	Subtraction function find the remainder and store in the result list. In Power Function
	checking the operand2 is zero if yes always return 1, else perform Power function using
	Multiplication and Subtraction Operation and store in the result list.

**********************************************************************************************************/
#include "apc.h"
int main(int argc, char *argv[])
{
	// Declaring list Pointers
	node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
	
    // Validation of the arguments.
    if(argc!=4)
    {
        printf("ERROR: Invalid Argument Counts\n");
		printf("Usage apc.out operand1 operator operand2\n");
        return FAILURE;
    }

	// checking if both operands are + or -.
	int flag_op1=0,flag_op2=0;
	flag_op1=symbolcheck(1,argv);
	flag_op2=symbolcheck(3,argv);

	if(argv[3][0]=='+')
    {
        flag_op2=0;
        argv[3][0]='0';
    }
    if(argv[3][0]=='-')
    {
        flag_op2=1;
        argv[3][0]='0';
    }
	
	// Validation of the arguments
	if(cla_validation(argc,argv)==FAILURE)
	{
		return FAILURE;
	}

    // Create lists of operand1 and remove pre zeros
	create_list(argv[1], &head1, &tail1);
	remove_pre_zeros(&head1);
	printf("OPERAND1 --> ");
	if(flag_op1)
	{
		printf("-");
	}
	print_list(head1);

	// storing the operator
	char oper = argv[2][0];
	printf("OPERATOR --> %c\n",oper);

	// create list for operand2 and remove pre zeros
	create_list(argv[3], &head2, &tail2);
	remove_pre_zeros(&head2);
	printf("OPERAND2 --> ");
	if(flag_op2)
	{
		printf("-");
	}
	print_list(head2);
	
	// Compare two list
	int check_max=compare_list(head1,head2);
	printf("\n\n  RESULT --> ");

	// Perform operation based on operator
    switch(oper)
    {
		// Addition 
		case '+':

				// checking both list are + and -.
				if((flag_op1==0 && flag_op2==0) || (flag_op1 && flag_op2))
				{
					// adding 2 list
					addition(tail1, tail2, &headR, &tailR);
					remove_pre_zeros(&headR);
					// printing minus if both list are negative
					if(flag_op1 && headR->data)
					{
						printf("-");
					}
				}
				// Checking either one is + and -.
				else if(flag_op1==0 && flag_op2==1)
				{
					// find the biggest list
					if(check_max==OPERAND2)
					{
						// Subtracting the biggest list to smallest list
						subtraction(tail2,tail1,&headR,&tailR);
						remove_pre_zeros(&headR);
						if(headR->data)
						{
							printf("-");
						}
					}
					else if(check_max==OPERAND1)
					{
						subtraction(tail1,tail2,&headR,&tailR);
					}
					// Both list are equal update 0.
					else
					{
						insert_first(&headR,&tailR,0);
					}
				}
				// Checking either one is - and +.
				else if(flag_op1==1 && flag_op2==0)
				{
					// Finding biggest list
					if(check_max==OPERAND2)
					{
						subtraction(tail2,tail1,&headR,&tailR);
					}
					else if(check_max==OPERAND1)
					{
						subtraction(tail1,tail2,&headR,&tailR);
						remove_pre_zeros(&headR);
						if(headR->data)
						{
							printf("-");
						}
					}
					// Both list are same. 
					else
					{
						insert_first(&headR,&tailR,0);
					}
				}
				break;
		
		case '-':
				// Subtraction Function
				// Both list are + or -.
				if((flag_op1==1 && flag_op2==0) || (flag_op1==0 && flag_op2==1))
				{
					// Performing addition 
					addition(tail1, tail2, &headR, &tailR);
					remove_pre_zeros(&headR);
					// if both list are negative.
					if(flag_op1 && headR->data)
					{
						printf("-");
					}
				}
				// Both list are +.
				else if(flag_op1==0 && flag_op2==0)
				{
					// Checking Biggest number and perform subtraction
					if(check_max==OPERAND2)
					{
						subtraction(tail2,tail1,&headR,&tailR);
						remove_pre_zeros(&headR);
						if(headR->data)
						{
							printf("-");
						}
					}
					else if(check_max==OPERAND1)
					{
						subtraction(tail1,tail2,&headR,&tailR);
					}
					// Both list are equal update 0.
					else
					{
						insert_first(&headR,&tailR,0);
					}
				}
				// Both list are -.
				else if(flag_op1==1 && flag_op2==1)
				{
					// Checking Biggest number and perform subtraction
					if(check_max==OPERAND2)
					{
						subtraction(tail2,tail1,&headR,&tailR);
					}
					else if(check_max==OPERAND1)
					{
						subtraction(tail1,tail2,&headR,&tailR);
						remove_pre_zeros(&headR);
						if(headR->data)
						{
							printf("-");
						}
					}
					// Both list are equal.
					else
					{
						insert_first(&headR,&tailR,0);
					}
				}
				break;
		// Multiplication operator as X , * , x.
		case 'x':
		case 'X':
		case '*':
				// Performing Multiplication
				multiplication(tail1,tail2,&headR,&tailR);
				if((flag_op1==1 && flag_op2==0) || (flag_op1==0 && flag_op2==1))
				{
					remove_pre_zeros(&headR);
					// for - number printing -.
					if(headR->data)
					{
						printf("-");
					}
				}
	    		break;
		
		case '/':
				// Checking operand2 is 0 print error.
				if((head2)->next==NULL && (head2)->data==0)
				{
					printf("\nRUNTIME ERROR: ZERO DIVISION ERROR\n");
					printf("Usage apc.out operand1 operator operand2\n");
					return 0;
				}
				// if operand2 is biggest update result 0.
				if(check_max==OPERAND2)
				{
					insert_first(&headR,&tailR,0);
					break;
				}
				// any operand is negative print -.
				else if(flag_op1 ^ flag_op2)
				{
					printf("-");
				}
				// both list are same update 0.
				if(check_max==SAME)
				{
					insert_first(&headR,&tailR,1);
					break;
				}
				// perform division 
				division(head1,head2,tail2,&headR,&tailR);
				break;

		case '%':
				// if operand2 is 0 print error
				if((head2)->next==NULL && (head2)->data==0)
				{
					printf("\nRUNTIME ERROR: ZERO DIVISION ERROR\n");
					printf("Usage apc.out operand1 operator operand2\n");
					return 0;
				}
				// both list are same update 0.
				if(check_max==SAME)
				{
					insert_first(&headR,&tailR,0);
					break;
				}
				// check if operand1 is -.
				else if(flag_op1==1)
				{
					printf("-");
				}
				// perform modulo 
				modulo(head1,head2,tail2,&headR,&tailR);
				break;
		case '^':
				// Power function
				// check if operand2 is 0.
				if(head2->next==NULL && head2->data==0)
				{
					insert_first(&headR,&tailR,1);
					break;
				}
				// check operand2 is -.
				else if(flag_op2==1)
				{
					// checking operand1 is 1.
					if(head1->next==NULL && head1->data==1)
					{
						// checking operand2 is odd/even.
						if(tail2->data%2!=0)
						{
							printf("-");
						}
						insert_first(&headR,&tailR,1);
						break;
					}
					// operand2 is not 1 update result 0.
					insert_first(&headR,&tailR,0);
					break;
				}
				// check operand1 is -.
				if(flag_op1==1)
				{
					// check operand1 is odd/even.
					if((tail2->data) % 2!=0)
					{
						printf("-");
					}
				}
				// Performing power 
				power(tail1,tail2,&headR,&tailR);
				break;
		default:
				// Invalid operator
	    		printf("Invalid operator\n");
				return FAILURE;
    }
	// checking result is null or not.
	if(headR!=NULL)
	{
		remove_pre_zeros(&headR);
		print_list(headR);
	}
	else
	{
		printf("ERROR\n");
	}
	
	return 0;
}

