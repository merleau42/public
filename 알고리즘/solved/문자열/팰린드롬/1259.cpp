#include <bits/stdc++.h>
using namespace std;

int main(){
    while (true){
        bool okay=true;
        string s;
        cin >> s;
        
        if (s.compare("0")==0)
            break;

        for (int i=0; i<s.length()/2; i++) {
            if (s.at(i) != s.at(s.length()-1-i)){
                okay=false;
                break;
            }
        }

        if(okay)
            cout << "yes\n";

        else
            cout << "no\n";
    }



    return 0;
}