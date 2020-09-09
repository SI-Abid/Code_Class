#include "stdio.h"
#define FOR(n)      for(int i=1; i<=n; i++)
#define pcase(x)    printf("Case #%d: ", x)
int main() 
{
  int t, n, k;
  scanf("%d", &t);
  FOR(t)
  {
    scanf("%d %d", &n, &k);
    int bin = (1<<n) - 1;
    pcase(i);
    puts(((bin & k)==bin)? "ON" : "OFF");
  }
  return 0;
}