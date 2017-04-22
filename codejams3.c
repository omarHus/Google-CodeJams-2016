#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long binary_to_baseN(char *string, int length, int base)
{
    int i=0, bin = 0;
    long long out = 0;
    for(i=length-1;i>=0;i--)
    {
        bin = (*(string+i) - '0');
        long long power = (long long)pow(base, i);
        printf("power: %lld * bin: %d\n", power, bin);
        out = out + bin*power;
        printf("out: %lld\n", out);
    }
    return out;
}

long long isPrime(long long baseNum, int length)
{
    long long i=0;
    long long prime = 0;

    for(i=2;i<((long long)sqrt(baseNum)+1);i++)
    {
        if(baseNum % i == 0)
        {
            prime = i;
            break;
        }
    }
    return prime;
}

void binary_generator(unsigned int number, char *strings, int length)
{
    static int counter = 0;
    if(number != 0 && counter < (length))
    {
        if(number%2 == 0)
        {
            *(strings+counter) = '0';
        }
        else
        {
            *(strings+counter) =  '1';
        }
        counter++;
        binary_generator(number/2, strings, length);
    }
    else
        counter = 0;

}

int main(void)
{
    FILE *in;
    FILE *out;
    in = fopen("C-small-practice1.in", "r");
    if(in == NULL)
    {
        printf("Error opening file\n");
        return(-1);
    }
    out = fopen("outputF.txt", "w");

    int T = 0, J = 0, N = 0, i;
    fscanf(in, "%d", &T);
    fscanf(in, "%d %d", &N, &J);

    unsigned int n = pow(2,(N));
    char *strings;
    strings = (char *)malloc(sizeof(char)*(N-1));
    if(strings == NULL)
    {
        printf("Error Malloc!\n");
    }
    long long *factors = 0;
    factors = (long long*)malloc(sizeof(long long)*9);
    if(factors == NULL)
    {
        printf("Error Malloc!\n");
    }
    long long baseN = 0;
    unsigned int j = 0;
    int counter = 0;

    for(i=0;i<T;i++)
    {
        fprintf(out, "Case #%d: \n", i+1);
        // generate strings of length N
        for(j=2*n; j>n;--j)
        {
            if(counter<J)
            {
                binary_generator(j, strings, N);

                if((*(strings) == '1') && (*(strings+(N-1)) == '1'))
                {
                    int sentinel = 0;
                    for(int k=2;k<11; k++)
                    {
                        baseN = binary_to_baseN(strings, N, k);
                        long long prime = isPrime(baseN, k);

                        if(prime != 0)
                        {
                            printf("k = %d, baseN = %lld\n", k, baseN);
                            *(factors+(k-2)) = prime;
                            sentinel++;
                            if(sentinel == 9)
                            {
                                counter++;
                                for(int r =0; r<N;r++)
                                {
                                    fprintf(out,"%d", (int)(*(strings+r) -'0'));
                                }
                                fprintf(out," ");
                                for(int h=0;h<9;h++)
                                {
                                    fprintf(out, "%lld ", *(factors+h));
                                }
                                fprintf(out, "\n");
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            else
                break;
        }
    }
    fclose(in);
    fclose(out);
    free(strings);
    free(factors);
    factors = 0;
    strings = 0;

    return 0;
}
