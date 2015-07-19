#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAXS 1700000

int n,q;
int *T[MAXS/5],ar[100002],br[100002],block[MAXS],*offset,*ptr;
int *list[100],size,sizes[100];
int li,ri,qi,qj,qk,low,high,mid,sum,tmp;
/**
BEGIN
FAST I/O
**/
#define BUFSIZE 6000000
char inbuf[BUFSIZE],outbuf[BUFSIZE],c,*in,*out;
int nbuf[10],nbs,bi;
int neg,num;

void io_init(){
    fread(inbuf,1,BUFSIZE,stdin);
    in = inbuf;
    out = outbuf;
}

int ni(){
    c = *in++;neg = num = 0;
    while(!(c >= '0' && c <= '9' || c == '-') ) c = *in++;
    if(c == '-') neg = 1, c = *in++;
    while(c >= '0' && c <= '9'){
        num = (num << 3) + (num << 1) + c - '0';
        c = *in++;
    }
    return neg ? -num : num;
}

void oi(int num){
    if(num < 0) *out++ = '-' , num = -num;
    nbs = bi = 0;
    if(num == 0) nbuf[nbs++] = 0;
    while(num) nbuf[nbs++] = num%10 , num /= 10;
    bi = nbs - 1;
    while(bi >= 0) *out++ = nbuf[bi--] + '0';
    *out++ = '\n';
}

void io_end(){
    *out = '\0';
    assert(out  - outbuf <= BUFSIZE && out - outbuf >= 0);
    fwrite(outbuf,1,out - outbuf,stdout);
}
/**
END
FAST I/O
**/
int compare(void const *p1 , void const *p2){
    return *((int *)p1) - *((int *)p2);
}
void merge(int *final , int *left , int *right,int lsize,int rsize){
    li = ri = 0;
    while(li < lsize && ri < rsize){
        if(*left < *right) *final = *left , ++left, ++li;
        else *final = *right , ++right, ++ri;
        ++final;
    }
    while(li < lsize) *final = *left, ++left , ++final , ++li;
    while(ri < rsize) *final = *right, ++ right , ++final , ++ri;
}

void build(int node, int b,int e){
    if(b == e){
        T[node] = br+b;
        return ;
    }
    int mid = b + e >> 1;
    build(node<<1,b,mid);
    build(node<<1|1,mid+1,e);
    T[node] = ptr = offset;
    merge(ptr,T[node<<1],T[node<<1|1],mid-b+1,e-mid);
    offset += (e-b+1);
}
void query(int node,int b,int e){
    if(b >= qi && e <= qj){
        list[size] = T[node];
        sizes[size++] = e-b+1;
        return ;
    }
    int mid = b + e >> 1;
    if(qj <= mid) query(node<<1,b,mid);
    else if(qi > mid) query(node<<1|1,mid+1,e);
    else query(node<<1,b,mid) , query(node<<1|1,mid+1,e);
}
int total(int x){
    int low,mid,high,i;
    sum = 0;
    for(i=0;i<size;i++){
        low = 0, high = sizes[i]-1;
        ptr = list[i];
        while(low < high){
            mid = low + high >> 1;
            if(ptr[mid] <= x) low = mid + 1;
            else high = mid;
        }
        if(ptr[low] > x) sum += low, sum -= (low > 0 && ptr[low-1] == x);
        else if(ptr[low] < x) sum += low+1;
        else sum += low;
    }
    return sum;
}
int binary_search(){
    low = 0,high = n-1;
    while(low < high){
        mid = low + high >> 1;
        tmp = total(ar[mid]);
        if(tmp <= qk) low = mid + 1;
        else high = mid;
    }
    tmp = total(ar[low]);
    if(tmp <= qk) return low;
    return low-1;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    assert(sizeof(char) == 1);
    int i,j;
    io_init();
    n = ni() , q = ni();
    for(i=0;i<n;i++)  ar[i] = ni() , br[i] = ar[i];
    offset = block;
    build(1,0,n-1);
    qsort(ar,n,sizeof(int),compare);
    while(q--){
        qi = ni() , qj = ni() , qk = ni();
        qi--,qj--,qk--;
        size = 0;
        query(1,0,n-1);
        oi(ar[binary_search()]);
    }
    io_end();
    return 0;
}
