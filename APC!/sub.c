#include "APC_header.h"

/*Function to perform subtraction*/
Status sub(cal *head1, cal *tail1, cal *head2, cal *tail2, cal **head3, cal **tail3)
{
    int sub = 0;
    cal *temp1 = tail1;
    cal *temp2 = tail2; // Temporary variables pointing to the last nodes of the lists
    cal *temp3 = temp1;

    // Check for invalid input
    if (!head1 || !tail1 || !head2 || !tail2 || !head3 || !tail3)
    {
        fprintf(stderr, "Error: Invalid input to the subtraction function.\n");
        return failure;
    }

    while (temp1 != NULL || temp2 != NULL) // Run the loop until NULL
    {
        if (temp1->data >= temp2->data) // If the first number is greater or equal, directly subtract
        {
            sub = temp1->data - temp2->data;
        }
        else
        {
            temp3 = temp1->prev; // Take a temp pointer to traverse backwards
            while (temp3 != NULL) // Traverse until a non-zero digit is found
            {
                if (temp3->data > 0) // If any data is greater than 0
                {
                    temp3->data--; // Decrement it by one
                    break;
                }
                else if (temp3->data == 0 && temp3->prev != NULL) // If zero is found
                {
                    temp3->data = 9; // Set it to 9
                }
                temp3 = temp3->prev; // Move backwards
            }

            sub = (temp1->data + 10) - temp2->data; // Add borrow and subtract
        }

        // Add the result to the resultant list
        if (add_res(head3, tail3, sub) == failure)
        {
            fprintf(stderr, "Error: Failed to add result during subtraction.\n");
            return failure;
        }

        // Move backwards for both numbers
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }

    return success; // Return success after completion
}
