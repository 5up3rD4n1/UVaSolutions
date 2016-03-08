#include <iostream>
#include <algorithm>

using namespace std;

vector<long long> factdic(long long x, int size){
    vector<long long> res;
    for(int i = 1; x!=0; i++){
        res.insert(res.begin(), x%i);
        x /= i;
    }

    size -= res.size();
    while(size--){
        res.insert(res.begin(), 0);
    }

    return res;
}


int main(){

    string str;
    int cases;
    cin>>cases;
    while(cases--){
        long long n;
        cin>>str;
        cin>>n;
        sort(str.begin(), str.end());
        vector<long long> dic = factdic(n, str.size());
        string answ = "";
        for(int i = 0; i < dic.size(); i++){
            answ+=(str[dic[i]]);
            str.erase(str.begin()+dic[i]);
        }

        cout<<answ<<'\n';
    }

    return 0;
}