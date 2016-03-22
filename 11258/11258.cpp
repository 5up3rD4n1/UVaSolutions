#include <iostream>

#include <algorithm>
#include <ctype.h>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <bits/basic_string.h>


#define MAX_L 210
using namespace std;

long memo[MAX_L];
int n;
string num;

long DP(int i){

    if (i >= n) return 0;
    if (memo[i] != -1) return memo[i];
    long res = 0;
    long answ = 0;

    for (int j = 1; j + i <= n && j <= 10; j++){
        //cout<<i <<" i "<<j<< " j "<<n<<" n\n";
        answ = stol(num.substr(i, j));

        if(answ <= INT_MAX)
            res = max(res, answ + DP(i+j));
    }

    return memo[i] = res;

}
int main(){
    freopen("input", "r", stdin);

    int tc;
    cin>>tc;
    while(tc--){
        cin>>num;
        memset(memo, -1, sizeof memo);

        n = (int) num.size();
        cout<< DP(0)<<'\n';


    }
    return 0;
}