#include <iostream>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <vector>
#include <stdio.h>
#include <limits.h>

using namespace std;

int main(){
    freopen("input", "r", stdin);

    int a,f,n;

    cin>>n;

    while(n--){
        getchar();
        string answ = "";
        cin>>a>>f;
        for(int i = 1; i < a+1; i++){
            int temp = i;
            while(temp--)
                answ += '0' + i;
            answ += '\n';
        }
        for(int i = a-1; i > 0; --i){
            int temp = i;
            while(temp--)
                answ += '0' + i;
            answ += '\n';
        }

        while(f--){
            cout<<answ;
            if(!(n==0 && f==0))cout<<'\n';
        }
    }
    return 0;
}