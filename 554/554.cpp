#include <iostream>
#include <vector>


using namespace std;

int main(){
    cin.tie(0);
    istream::sync_with_stdio(false);
    freopen("input", "r", stdin);
    string in, line;
    vector<string> dic;

    while(getline(cin,in), in[0]!='#')
        dic.push_back(in);

    getline(cin, line);
    int k = 0;
    for(string s: dic){
        for(int i=0; i < (line.size()-s.size()); i++){
            int cos;
            bool solution = true;
            for(int j = 0; j<s.size(); j++){
                int val = (27+(line[i+j] - 'A')-(s[j]-'A'))%27; //This is the solving formula
                if (j==0) cos = val;
                else if(cos != val){
                    solution = false;
                    break;
                }
            }
            if (solution){
                if(k == cos) break;
                k = cos;
            }
        }
    }

    for(int i=0; i<line.size(); i++){
        char c = line[i];
        int l = (c - 'A')-k;
        if (l < 0) l+=27;
        if (c == ' ') l = 26-k;

        if(l == 26)line[i]=' ';
        else line[i]=char(l+'A');
    }

    string b = line;


    /*
    int i, l, soFar = 0;
    string bef = "";

    for (i = 0; i < b.length(); i += l+1){
        for (l = 1; i+l < b.length() && b[i+l] != ' '; l++);

        if (soFar + l + bef.length() > 60){
            cout << '\n';
            bef = "";
            soFar = 0;
        }

        soFar += l + bef.length();
        cout << bef << b.substr(i, l);
        bef = " ";
    }

    cout << '\n';
       */

    //FORMAT OUTPUT


    return 0;
}
