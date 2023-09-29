#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "utils.h"
#include "queue.h"

int main()
{
    set_terminal_flags();
    hide_cursor();

    Queue *q_x = queue_new(10);
    Queue *q_y = queue_new(10);

    clear_screen();
    for (int x = 5; x < 11; x++)
    {
        queue_push(q_x, x);
        queue_push(q_y, 10);
        gotoXY(x, 10);
        printf("#\n");
    }

    int x = 10;
    int y = 10;
    while (1)
    {
        gotoXY(queue_pop(q_x), queue_pop(q_y));
        printf(" \n");

        x++;
        queue_push(q_x, x);
        queue_push(q_y, y);
        gotoXY(x, y);
        printf("#\n");
        usleep(200000);
    }

    printf("\e[2J");
    for (int i = 0; i < 10; i++)
    {
        gotoXY(20+i, 10);
        printf("#\n");
        usleep(200000);
        char c = getc(stdin);
        if (c != EOF)
        {
            gotoXY(i, 0);
            printf("%c\n", c);
        }
    }

    return 0;
}
