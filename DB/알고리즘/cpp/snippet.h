#include <bits/stdc++.h>
using namespace std;


//split
vector<string> split (string old, string sep) {
     vector<string> ret;
     string token;
     int pos;

     while ((pos = old.find(sep)) != string::npos) {
          token = old.substr(0, pos);
          ret.push_back(token);
          old.erase(0, pos + sep.length());
     }
     ret.push_back(old);      // 아직 한발 남았다

     return ret;
}


//순열
template <typename T>
vector<vector<string>> permutation(T *seq){ // [2, 3, 4]
    vector<vector<string>> ret;

    do{ 
        vector<string> A;
        
        for (char i: *seq)
          A.push_back( to_string(i) );

        ret.push_back(A);        

    } while ( next_permutation(begin(*seq), end(*seq)) );

    return ret;
}
/*    for (auto i: permutation(&s)){
        for (auto j: i)
            cout << (char)atoi(j.c_str()) << ' ';
        cout << '\n';
    }
*/


//"123456789101112131415"의 글자수 = natural(n)
//띄어쓰기 하나씩 포함 = natural(n)+n-1
int natural(int n) {
     return n+(n>9)*(n-9);
}