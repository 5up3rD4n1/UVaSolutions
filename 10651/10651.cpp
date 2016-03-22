#include <iostream>

#include <algorithm>


using namespace std;
string line;

int bitcount(int mask){
    int res = 0;
    for(int i = 0 ; i<12; i++)
        if(mask&1<<i) res++;

    return res;
}

int DP(int mask){
    int result = 0;
    for(int i = 0; i < 12; i++){

        if(i-1 >= 0 && i+1 < 12){
            if( !(mask & 1<<i-1) && (mask&1<<i) && (mask&1<<i+1)){
                int newmask = 0;
                newmask = mask^(1<<i-1);
                newmask &= ~(1 << i);
                newmask &= ~(1 << i+1);
                result = max(result, 1 + DP(newmask));
            }
        }

        if(i+2 < 12){
            if(!(mask & 1<<i+2) && mask&1<<i && mask&1<<i+1){
                int newmask = 0;
                newmask = mask^(1<<i+2);
                newmask &= ~(1 << i);
                newmask &= ~(1 << i+1);
                result = max(result, 1 + DP(newmask));
            }
        }
    }

    return result;

}

int main(){
    freopen("input", "r", stdin);
    cin.tie(0);
    istream::sync_with_stdio(false);
    int tc;
    cin>>tc;
    while(tc--){
        cin>>line;
        int bitmask = 0;
        for(int i = 0; i < 12; i++){
            bitmask |= (line[i] == '-')? 0<<i:1<<i;
        }
        int res = bitcount(bitmask) - DP(bitmask);
        cout<<res<<'\n';
    }
    return 0;
}