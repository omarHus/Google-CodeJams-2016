#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 100


void flip(char *stack, int pancakes)
{
    int i;
    for(i=0;i<pancakes;i++)
    {
        if(*(stack+i) == '+')
        {
            *(stack+i) = '-';
        }
        else
        {
            *(stack+i) = '+';
        }

    }
}

int main()
{
    FILE *in;
    FILE *out;
    in = fopen("input.txt", "r");
    out = fopen("output2.txt", "w");

    int T = 0, i =0,j,k;

    fscanf(in, "%d", &T);

    for(i=0;i<T;i++)
    {
        int flip_total = 0, length =0;
        char *stack = 0;
        stack = (char *)malloc(sizeof(char)*STRING_LENGTH);
        fscanf(in, "%s", stack);
        length = strlen(stack);

        for(j=0;j<length;j++)
        {
            // if starts with +
            if(*(stack+j) == '+')
            {
                for(k=j+1;k<length;k++)
                {
                    if(*(stack+k) == '-')
                    {
                        flip(stack, k);
                        flip_total++;
                        break;
                    }
                }

            }
            else if (*(stack+j) == '-') // encounter 1st minus
            {
                if(length == 1)
                {
                    flip(stack, 1);
                    flip_total++;
                    break;
                }
                else
                {
                    if(length == j+1)
                    {
                        flip(stack, j+1);
                        flip_total++;
                        break;
                    }
                    // check for the next +
                    for(k=j+1;k<length;k++)
                    {
                        if(*(stack+k) == '+')
                        {
                            // flip -
                            flip(stack,k);
                            flip_total++;
                            break;
                        }
                        else if(length == (k+1))
                        {
                            flip(stack, length);
                            flip_total++;
                            break;
                        }
                    }
                }
            }
        }

        // output
        fprintf(out, "Case #%d: %d\n", i+1, flip_total);
        free(stack);
        stack = 0;
    }

    return 0;
}
