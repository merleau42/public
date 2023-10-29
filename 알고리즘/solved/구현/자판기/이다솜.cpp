using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/1620

string NtoE[100004];
map<string, int> EtoN;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, Qn;
    cin >> n >> Qn;

    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        NtoE[i] = s;
        EtoN[s] = i;
    }

    for (int i=0; i<Qn; i++) {
        string Q;
        cin >> Q;
        int conv = atoi(Q.c_str());
        
        if ( conv==0 )
            cout << EtoN[Q];
        else
            cout << NtoE[conv];
        cout << '\n';
    }

    return 0;
}

/*
26 5
Bulbasaur
Ivysaur
Venusaur
Charmander
Charmeleon
Charizard
Squirtle
Wartortle
Blastoise
Caterpie
Metapod
Butterfree
Weedle
Kakuna
Beedrill
Pidgey
Pidgeotto
Pidgeot
Rattata
Raticate
Spearow
Fearow
Ekans
Arbok
Pikachu
Raichu
25
Raichu
3
Pidgey
Kakuna*/