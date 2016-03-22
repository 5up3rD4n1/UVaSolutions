#include <iostream>

#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>


using namespace std;

#define MAX_N 100010

string T,P; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P


void kmpPreprocess() { // call this before calling kmpSearch()
    int i = 0, j = -1; b[0] = -1; // starting values
    while (i < m) { // pre-process the pattern string P
        while (j >= 0 && P[i] != P[j]) j = b[j]; // if different, reset j using b
        i++; j++; // if same, advance both pointers
        b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
    }
}

int kmpSearch() { // this is similar as kmpPreprocess(), but on string T
    int i = 0, j = 0; // starting values
    int result = 0;
    while (i < n) { // search through string T
        while (j >= 0 && T[i] != P[j]) j = b[j]; // if different, reset j using b
        i++; j++; // if same, advance both pointers
        if (j == m) { // a match found when j == m
            result = i-j;
            j = b[j]; // prepare j for the next possible match
        }else
            result = i - j;
    }
    return result;
}





int main(){
    //freopen("input", "r", stdin);
    cin.tie(0);
    istream::sync_with_stdio(false);
    while(cin>>T){
        m = n = (int) T.size();
        P = "";

        int count = n;

        while(count--)
            P += T[count];

        kmpPreprocess();

        int index = kmpSearch();

        while(index--)
            T += T[index];

        cout<<T<<"\n";
    }
    return 0;
}