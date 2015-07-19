#include<math.h>
double pi=4.0*atan(1.0);
#define invtan(test) ((test)<0)?(atan(test)+pi):atan(test)
int main(){
    int t,v0,k1,k2;
    scanf("%d",&t);
    //printf("\t%lf\n",pi);
    long double g=10.0;
    while(t--){
        scanf("%d%d%d",&v0,&k1,&k2);
        double res=v0*v0/g;
        double th2,th;
        if(k1==0) th2=2*(pi/180)*90;
        else if (k2==0) th2=2*(pi/180)*45;
        else {double arg=-4.0*k1/k2;th2=invtan(arg);}
        th=.5*th2;
        printf("%.3lf ",th);
        res*=(k1*sin(th2)+k2*sin(th)*sin(th)/2);
        printf("%.3lf\n",res);
        //double test;
        //scanf("%lf",&test);
        //printf("%lf\n",test<0?atan(test)+pi:atan(test));
    }
    return 0;
}
