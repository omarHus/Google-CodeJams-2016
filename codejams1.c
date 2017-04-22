#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int *array, int cols)
{
    int out = 0;
    for(int i=0;i<cols;i++)
    {
        out = out + *(array+i);
    }
    return out;
}


int main()
{
    FILE *fp;
    FILE *out;

    fp = fopen("A-large.in", "r");
    if (fp==NULL)
    {
        printf("Error opening file");
        return(-1);
    }
    out = fopen("counting_sheep_out2.txt", "w");
    if(out == NULL)
    {
        printf("Error opening file");
        return(-1);
    }

    int T =0;
    // scan for number of test cases
    fscanf(fp, "%d", &T);
    int i= 0;
    char *N = 0;
    N = (char *)malloc(sizeof(char)*10);
    if(N == NULL)
    {
        printf("Error malloc!");
        return (-1);
    }


    for(i = 0; i<T; i++)
    {
        int array[10]={-1,0,0,0,0,0,0,0,0,0};
        int multiplier = 1;
        // scan for each individual starting case
        fscanf(fp, "%s", N);
        int number = atoi(N);
        int digit = 1, j = 1;

        while (sum(array, 10) < 45 && number != 0)
        {
            multiplier = j*number;
            j++;
            int divider = multiplier;

            while(divider>0)
            {
                digit = divider%10;
                if (array[digit]==digit)
                {
                    divider =divider/10;
                }
                else
                {
                    array[digit]=digit;
                    divider=divider/10;
                }
            }
        }

        // print the cases
        if (number == 0)
        {
            fprintf(out, "Case #%d: INSOMNIA\n", i+1);
        }
        else
        {
            fprintf(out, "Case #%d: %d\n", i+1, multiplier);
        }
    }
    free(N);
    N=0;
    return 0;
}
