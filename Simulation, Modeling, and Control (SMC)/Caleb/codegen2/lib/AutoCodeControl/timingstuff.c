#include <stdio.h>

int wait_loop0 = 10000;
int wait_loop1 = 6000;

// for microprocessor without timer, if it has a timer refer to vendor documentation and use it instead.
void wait( int seconds )
{   // this function needs to be finetuned for the specific microprocessor
    int i, j, k;
    for(i = 0; i < seconds; i++)
    {
        for(j = 0; j < wait_loop0; j++)
        {
            for(k = 0; k < wait_loop1; k++)
            {   // waste function, volatile makes sure it is not being optimized out by compiler
                int volatile t = 120 * j * i + k;
                t = t + 5;
            }
        }
    }
}

int main( int argc, char **argv)
{
    int running = 300;
    for(int i = 0; i < 100; i++)
    {
        while( running )
        {   // do something
            --running;
            printf("Bye");
            wait( 2 );
            printf("hi");
        }
    }
    return 0; // OK
}