void sort_by_area(triangle* tr, int n) 
{
    // int a[n], temp;
    triangle t;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            float x=(tr[j].a+tr[j].b+tr[j].c)/2.0;
            float y=(tr[j+1].a+tr[j+1].b+tr[j+1].c)/2.0;
            if((x*(x-tr[j].a)*(x-tr[j].b)*(x-tr[j].c))>(y*(y-tr[j+1].a)*(y-tr[j+1].b)*(y-tr[j+1].c)))
            {
                
                t=tr[j];
                tr[j]=tr[j+1];
                tr[j+1]=t;
                
            }
        }
    }
}