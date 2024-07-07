#include <stdio.h>
#include "global.h"
#include "stack.h"
#include "queue.h"

void displayCustomersInfo(Queue *pq)
{
    int n = queueSize(pq);
    QueueEntry e1;
    while (n > 0)
    {
        serve(pq, &e1);
        printf("%d \t", e1);
        append(e1, pq);
        n--;
    }
}

void reverseCustomers(Queue *pq, Stack *ps)
{
    int n = queueSize(pq);
    QueueEntry e1;
    while (n > 0)
    {
        serve(pq, &e1);
        push(e1, ps);
        append(e1, pq);
        n--;
    }
}

void displayInMostRecent(Queue *pq, Stack *ps)
{
    reverseCustomers(pq, ps);
    int n = stackSize(ps);
    StackEntry e1;
    for (int i = 0; i < n; i++)
    {
        pop(&e1, ps);
        printf("%d \t", e1);
    }
    printf("\n");
}

int main()
{
    Queue q;
    createQueue(&q);

    int option = 0;
    while (option != -1)
    {
        printf("\n1: Add a New Customer.\n");
        printf("2: Serve a Customer.\n");
        printf("3: Display Customers Information.\n");
        printf("4: Display Customers in the most-recent Order.\n");
        printf("-1: Exit\n");

        printf("Choose an option: ");
        scanf("%d", &option);
        while (getchar() != '\n')
            ; // Clear input buffer //?????

        switch (option)
        {
        case 1:
        {
            // V1 : CUSTOMER DATA IS JUST AN ID
            Customer c1;
            printf("Please add a new customer data.\n");
            scanf("%d", &c1);
            append(c1, &q);
            break;
        }
        case 2:
        {
            // V1 : CUSTOMER DATA IS JUST AN ID
            if (!queueEmpty(&q))
            {
                Customer c1;
                serve(&q, &c1);
                printf("Serve the first Customer is  : %d .\n", c1);
            }
            else
                printf("NO CUSTOMERS FOUND!!\n");
            break;
        }
        case 3:
        {
            // V1 : CUSTOMER DATA IS JUST AN ID

            if (!queueEmpty(&q))
            {
                printf("Customers in our System  : ");
                displayCustomersInfo(&q);
            }
            else
                printf("NO CUSTOMERS FOUND!!\n");
            break;
        }
        case 4:
        {
            // V1 : CUSTOMER DATA IS JUST AN ID

            if (!queueEmpty(&q))
            {
                Stack s;
                createStack(&s);
                printf("Customers in Most-Recent Order : ");
                displayInMostRecent(&q, &s);
            }
            else
                printf("NO CUSTOMERS FOUND!!\n");
            break;
        }
        case -1:
        {
            printf("Exiting.......\n");
            break;
        }
        default : {
            printf("Please Enter valid option!\n");
        }

        }
    }
    return 0;
}