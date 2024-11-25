#include "APC_header.h"

extern int neg_flag;

Status division(cal *head1, cal *tail1, cal *head2, cal *tail2, cal **head3, cal **tail3)
{
    if (!head1 || !tail1 || !head2 || !tail2 || !head3 || !tail3)
    {
        fprintf(stderr, "Error: Invalid input to the division function.\n");
        return failure;
    }

    int stop_flag = 0;
    int count = 0, result = 0;
    cal *temp;

    while (stop_flag != 1)
    {
        if (result % 2 == 0) // If result value is even
        {
            count++;
            if (sub(head1, tail1, head2, tail2, head3, tail3) == failure)
            {
                fprintf(stderr, "Error: Subtraction failed during division.\n");
                return failure;
            }
            temp = *head3;
        }
        else
        {
            count++;
            if (sub(*head3, *tail3, head2, tail2, &head1, &tail1) == failure) // Perform subtraction and swap the lists
            {
                fprintf(stderr, "Error: Subtraction failed during division.\n");
                return failure;
            }
            temp = head1;
        }

        stop_flag = check_node(&temp, &head2); // Check if the result is greater than the denominator
        if (stop_flag == 1)
        {
            break; // Stop the process
        }
        else
        {
            if (result % 2 == 0)
                free_node(&head1, &tail1); // Based on result value, free the nodes
            else
                free_node(head3, tail3);
            result++;
        }
    }

    // Print the result
    printf("Result is: ");
    if (neg_flag)
        printf("-");
    printf("%d\n", count);

    return success;

}
/*Function to check the bigger node*/
int check_node(cal** head1,cal** head2)
{
	cal* temp1 = *head1;
	cal* temp2 = *head2;
	while(temp1)
	{
		if(temp1->data > temp2->data)			//if first list data is greater than second list data return 0
			return 0;
		else if(temp1->data < temp2->data)		//if it is vice versa result 1
			return 1;
		temp1 = temp1->next;
		temp2 = temp2->next;						//traverse till end of list
	}
	return 0;										//if equal return 0
}