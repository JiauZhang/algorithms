#include <iostream>
#include <vector>

using namespace std;

struct Split {
    int v, w;
};

int main()
{
    int N, V;
    cin>>N>>V;

    int dp[V+1];
    for (int i=0; i<=V; i++) dp[i] = 0;

    vector<Split> splits;

    for (int i=0; i<N; i++) {
        int v, w, s;
        cin>>v>>w>>s;

        for (unsigned int k=1; k<=s; k = k<<1) {
        // for (; k<=s; k*=2) {
            s -= k;
            splits.push_back({k*v, k*w});
            // cout << k;
        }

        if (s>0) {
            splits.push_back({s*v, s*w});
        }
    }

    // for (int i=0; i<splits.size(); i++) {
    for (auto sp: splits) {
        int v, w;
        v = sp.v;
        w = sp.w;
        for (int j=V; j>=v; j--) {
            dp[j] = max(dp[j-v]+w, dp[j]);
        }
    }

    cout << dp[V];

    return 0;
}