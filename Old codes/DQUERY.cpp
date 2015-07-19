#include<cstdio>
#include<algorithm>
#include<map>
#include<assert.h>
#define INF 10000000
using namespace std;
int n,ar[1000006],next[1000006],*tree[5000006],*ptr,*offset,block[20000007],*list[100],size,sizes[100];

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

void merge(int *final , int *left , int *right,int lsize,int rsize){
    int li,ri;
    li = ri = 0;
    while(li < lsize && ri < rsize){
        if(*left < *right) *final = *left , ++left, ++li;
        else *final = *right , ++right, ++ri;
        ++final;
    }
    while(li < lsize) *final = *left, ++left , ++final , ++li;
    while(ri < rsize) *final = *right, ++ right , ++final , ++ri;
}

void build(int v,int tl,int tr){
    if(tl == tr){
        tree[v] = next + tl;
        return;
    }
    int mid = (tl + tr) >> 1;
    build(v<<1,tl,mid);
    build(v<<1|1,mid+1,tr);
    tree[v] = ptr = offset;
    merge(ptr,tree[v<<1],tree[v<<1|1],mid-tl+1,tr-mid);
    offset += tr - tl + 1;
} 

void query(int v,int tl,int tr,int qi,int qj) {
    if(tl >= qi && tr<= qj){ 
        list[size] = tree[v];
        sizes[size++] = tr - tl + 1;
        return;
    }
    int mid = (tl + tr) >> 1;
    if(qj<=mid) query(v<<1,tl,mid,qi,qj);
    else if(qi>mid) query(v<<1|1,mid+1,tr,qi,qj);
    else query(v<<1,tl,mid,qi,qj),query(v<<1|1,mid+1,tr,qi,qj);
}

int binarySearch(int *arr,int x,int size){
    int low = 0,high = size-1;
    int ans = 0;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(arr[mid] > x) {
            high = mid - 1;
            ans = size - mid;
        }
        else low = mid + 1;
    }
    return ans;
}

int total(int x){
    int low,mid,high,i;
    int sum = 0;
    for(i=0;i<size;i++){
        ptr = list[i];
        sum+=binarySearch(ptr,x,sizes[i]);
    }
    return sum;
}

int main(){
    io_init();
    //scanf("%d",&n);
    n = ni();
    for(int i = 0;i < n;i++){
        //scanf("%d",&ar[i]);
        ar[i] = ni();
    }    
    map<int,int> ma;
    for(int i = n-1; i >=0 ;i --){
        if(ma.count(ar[i])) {
            next[i] = ma[ar[i]];
            ma[ar[i]] = i;
        }
        else {
            next[i] = INF;
            ma[ar[i]] = i;
        }
    }
    //for(int i = 0;i < n;i++) printf("%d ",next[i]);
    offset = block;
    build(1,0,n-1); 
    int q;
    //scanf("%d",&q);
    q=ni();
    while(q--){
        int qi,qj;
        //scanf("%d%d",&qi,&qj);
        qi=ni(),qj=ni();
        qi--,qj--;
        size = 0;
        query(1,0,n-1,qi,qj);
        //printf("%d\n",total(qj));
        oi(total(qj));
    }
    io_end();
    return 0;
}
