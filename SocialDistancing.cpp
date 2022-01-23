#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool f(vector<pair<long long,long long>> in,long long d,long long N){
    long long curAns=1;
    long long curPos=in[0].first;
    long long counter=0;
    while(counter<in.size()){
        if(curPos+d<=in[counter].second){
            curAns++;
            curPos=max(curPos+d,in[counter].first);
            //curPos+=d;
        }else{
            counter++;
            continue;
        }
        if(curAns==N){
            return true;
        }
    }
    return false;
}


long long lastTrue(long long lo, long long hi,vector<pair<long long,long long>> in,long long N) {
    // if none of the values in the range work, return lo - 1
    lo--;
    while (lo < hi) {
        // find the middle of the current range (rounding up)
        long long mid = lo + (hi - lo + 1) / 2;
        if (f(in,mid,N)) {
            // if mid works, then all numbers smaller than mid also work
            lo = mid;
        } else {
            // if mid does not work, greater values would not work either
            hi = mid - 1;
        }
    }
    return lo;
}


int main() {
  freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    long long N,M;
    cin>>N>>M;
    vector<pair<long long,long long>> in;
    for(long long i=0;i<M;i++){
        long long a,b;
        cin>>a>>b;
        in.push_back({a,b});
    }
    sort(in.begin(),in.end());
    cout<<lastTrue(1,1000000000000000000,in,N);
    return 1;
}
