#include<stdio.h>
#define IDENTITY 0
long long t[250000][19];
long f(long a,long b)
{
    if(a>b) return a;
    else return b;    
}
void set(int x, int v) {
  t[x][0] = a[x] = v;
  for (int y = 1; y <= n; y++) {
    int xx = x-(x&((1<<y)-1));
    t[xx][y] = f(t[xx][y-1], t[xx+(1<<(y-1))][y-1]);
  }
}

int get(int i, int j) {
  int res = IDENTITY, h = 0; j++;
  while (i+(1<<h) <= j) {
    while ((i&((1<<(h+1))-1)) == 0 && i+(1<<(h+1)) <= j) h++;
    res = f(res, t[i][h]);
    i += (1<<h);
  }
  while (i < j) {
    while (i+(1<<h) > j) h--;
    res = f(res, t[i][h]);
    i += (1<<h);
  }
  return res;
}
int main()
{
    long N,k,l=0;
    scanf("%ld",&N);
    while(N--)
    {
        scanf("%d",&k);
        if(k==1)
        {
            scanf("%ld",&k);
            set(l,k);
            l++;    
        }    
        else if(l<3) puts("No ratings yet");
        else
            printf("%ld\n",get(0,l/3));
    }    
    return 0;
}
