#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)x.size())

int main() {
#define int long long
    string _T; getline(cin, _T);
    int T = stoi(_T);
    while(T--) {
        string line; getline(cin, line);
        stringstream ss(line);
        vector<int> ai;
        int x; while(ss >> x) ai.push_back(x);
        int up = ai.back(), down = 1;
        for(int i = SZ(ai) - 2; i >= 0; i--) {
            swap(up, down);
            up += ai[i] * down;
            int G = __gcd(up, down);
            up /= G;
            down /= G;
        }
        cout << up << " " << down << endl;
    }
    return 0;
}
