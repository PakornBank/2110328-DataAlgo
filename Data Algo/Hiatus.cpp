#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
 
    int n,m;
    cin >> n >> m;
    int v[n];
    for(int i =0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v[i] = (a*100 + b);
    }
    sort(v,v+n);
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        int num = a*100 + b;
        int pos = lower_bound(v,v+n,num) - v;
        if(pos == 0 && v[pos] > num){
            printf("-1 -1 ");
            continue;
        }
        if(v[pos] == num){
            printf("0 0 ");
            continue;
        }
        printf("%d %d ",v[pos-1]/100,v[pos-1]%100);

    }


}


