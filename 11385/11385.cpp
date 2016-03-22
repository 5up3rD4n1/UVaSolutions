#include <iostream>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <vector>
#include <stdio.h>
#include <limits.h>

using namespace std;
#define vl vector<long>
#define vlIt vector<long>::iterator

vl fibbo;

void fillfibbo(int number){
    fibbo.push_back(0);
    fibbo.push_back(1);
    fibbo.push_back(2);
    for(int i = 3; i< number; i++){
        fibbo.push_back(fibbo[i-2]+fibbo[i-1]);
    }
}


int main() {
    freopen("input", "r", stdin);
    fillfibbo(70);
    int cases;
    cin>>cases;
    while(cases--){
        vl numbers;
        int n;
        cin>>n;
        long number;
        while(n--){
            cin>>number;
            numbers.push_back(number);
        }
        string word = "";


        cin.clear();
        cin.ignore(INT_MAX,'\n');
        getline(cin, word);

        string clean = "";

        for(int i = 0; i < word.size(); i++){
            if(isupper(word[i])){
                clean += word[i];
            }
        }

        vlIt index;
        string answ = "";
        int count = 0;
        int i = 1;
        while(count < numbers.size() && i < 70){
            index = find (numbers.begin(), numbers.end(), fibbo[i]);
            if (index != numbers.end()){
                count++;
                int diff = (index - numbers.begin());
                answ += clean[diff];
            }else
                answ += ' ';
            i++;
        }

        cout<<answ<<'\n';



    }
    return 0;
}