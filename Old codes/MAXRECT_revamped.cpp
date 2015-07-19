#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
multiset<pair<int,int> >q[301];
int arr[301][301];
bool sr[301],sc[301];
int main(){
    int i,j,r,c;
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
            q[i].insert(make_pair(arr[i][j],j));
        }
    vector<int>::iterator it;
    multiset<pair<int,int> >::reverse_iterator mit;
    ll ans=0;
    //for(t=0;t<c;t++)
    int t=0;
    
        ll mans=0,pans=0;
        //memset(sr,0,sizeof(sr));
        //memset(sc,0,sizeof(sc));
        vector<int> selr,selc;
        //find appropriate set of rows for column t
        
        for(i=0;i<r;i++)
            if(arr[i][t]>0) {selr.push_back(i);sr[i]=1;}
            
        //select columns on basis of selr
        
        for(j=0;j<c;j++){
            mans=0;
            for(it=selr.begin();it!=selr.end();it++)
                mans+=arr[*it][j];
            if(mans>0){
                pans+=mans;
                selc.push_back(j);
                sc[j]=1;
            }
        }
        
        // add r,c pairs from unselected r's and c's
        ll temps=0;
        for(i=0;i<r;i++){
            if(sr[i]) continue;
            // sumup additions from selected cols
            for(it=selc.begin(),temps=0;it!=selc.end();it++) temps+=arr[i][*it];
            // test for every column
            for(mit=q[i].rbegin(),mans=temps;mit!=q[i].rend()&&mit->first>0;mit++){
                j=mit->second;
                for(it=selr.begin();it!=selr.end();it++)
                    mans+=arr[*it][j];
                mans+=mit->first;
                if(mans>0){
                    selr.push_back(i);
                    sr[i]=1;
                    selc.push_back(j);
                    sc[j]=1;
                    pans+=mans;
                    break;
                }
            }
        }
        
        // now see if some additional cols/rows can be added
        
         int go=2;
         while(go--){
         for(i=0;i<r;i++){
                if(sr[i]) continue;
                mans=0;
                for(it=selc.begin();it!=selc.end();it++)
                    mans+=arr[i][*it];
                if(mans>0){
                    pans+=mans;
                    selr.push_back(i);
                    sr[i]=1;
                }
            }
     
            for(j=0;j<c;j++){
                if(sc[j]) continue;
                mans=0;
                for(it=selr.begin();it!=selr.end();it++)
                mans+=arr[*it][j];
                if(mans>0){
                    pans+=mans;
                    selc.push_back(j);
                    sc[j]=1;
                }
            }
            }
            
            // now we hav best possible soln for column t
    sort(selr.begin(),selr.end());
    sort(selc.begin(),selc.end());
    printf("%d %d\n",selr.size(),selc.size());
    for(it=selr.begin();it!=selr.end();it++) printf("%d ",*it);
    putchar ('\n');
    for(it=selc.begin();it!=selc.end();it++) printf("%d ",*it);
    return 0;
}
