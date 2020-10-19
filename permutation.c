int next_permutation(int n, char **s)
{
    int i = n-1;
    while(i>0 && strcmp(s[i-1], s[i])>=0)
    { 
        i--;	
    }
    if (i<1) return 0;
    
    int j = n-1;
    while(strcmp(s[i-1], s[j])>=0) 
    {
        j--;
    }	

    char *temp = s[i-1];
    s[i-1] = s[j];
    s[j] = temp;
    
    for(j=n-1; i<j; i++,j--) 
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return 1;
}