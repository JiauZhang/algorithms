#include <iostream>

using namespace std;

int main()
{
    int N, V;
    cin>>N>>V;

    int dp[V+1];
    for (int i=0; i<=V; i++) dp[i] = 0;

    for (int i=0; i<N; i++) {
        int v, w, s;
        cin>>v>>w>>s;

        for (int j=V; j>0; j--) {
            for (int k=1; k<=s && k*v<=j; k++) {
                dp[j] = max(dp[j-k*v]+k*w, dp[j]);
            }
        }
    }

    cout << dp[V];

    return 0;
}