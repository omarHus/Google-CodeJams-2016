#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in;
    FILE *out;
    in = fopen("input4.txt", "r");
    out = fopen("output.txt", "w");

    int T_cases = 0, i = 0;
    fscanf(in, "%d", &T_cases);

    for(i=1;i<=T_cases;i++)
    {
        int K = 0, C = 0, S = 0;
        fscanf(in, "%d %d %d", &K, &C, &S);
        if( (C+S) <= K)
        {
            fprintf(out, "Case #%d: IMPOSSIBLE\n", i);
        }
        else
        {
            if(K==1)
            {
                fprintf(out, "Case #%d: 1\n", i);
            }
            else
            {
                if (K % 2== 0)
                {
                    if(S>1)
                        fprintf(out, "Case #%d: %d %d\n", i, K, 2*K);
                    else
                        fprintf(out, "Case #%d: %d\n", i, K);
                }
                else
                {
                    if(S>1)
                        fprintf(out, "Case #%d: %d %d\n", i, K-1, C*(K-1));
                    else
                        fprintf(out, "Case #%d: %d\n", i, K-1);
                }

            }
        }
    }
    fclose(in);
    fclose(out);

    return 0;
}
