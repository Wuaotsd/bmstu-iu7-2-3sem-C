#include "process.h"

int process(FILE *f)
{
    if (f == NULL)
        return ERR_PARAMS;
        
    float num, x_arif = 0, q = 0;
    float p_3;
    float n_3q = 0;
    int n = 0, rc;
    while ((rc = fscanf(f, "%f", &num)) == 1)
    {
        x_arif += num;
        n++; 
    }
    if (n < 2 || rc == 0)
        return INCORRECT_FILE;
    x_arif /= n;
    rewind(f);
    
    while (fscanf(f, "%f", &num) == 1)
        q += (num - x_arif) * (num - x_arif);
    q = sqrt(q / (n - 1));
    rewind(f);
    
    while (fscanf(f, "%f", &num) == 1)
        if ((x_arif - 3 * q) < num && num < (x_arif + 3 * q))
            n_3q ++;
            
    p_3 = n_3q / n;
    if (p_3 >= 0.997)
        return 1;
    return 0;
}