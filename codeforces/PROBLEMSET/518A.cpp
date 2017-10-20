#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define int long long

#undef int

int main(){
    #define int long long
    string s,t; cin >> s >> t;
    int now = 0;
    while(s[now] == t[now]) now++;
    if(s[now] + 1 < t[now]){
        s[now] = (char)(s[now] + 1);
        cout << s << endl;
        return 0;
    }
    else{
        for(int i=now+1;i<SZ(s);i++){
            if(s[i] != 'z'){
                s[i] = 'z';
                cout << s << endl;
                return 0;
            }
            else if(t[i] != 'a'){
                t[i] = 'a';
                cout << t << endl;
                return 0;
            }
        }
    }
    cout << "No such string" << endl;
    return 0;
}
