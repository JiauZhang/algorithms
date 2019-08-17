#include <iostream>

using namespace std;

int main()
{
    int N, V;
    cin>>N>>V;
    
    int dp[V+1];
    for (int i=0; i<=N; i++) dp[i] = 0;
    
    for (int i=0; i<N; i++) {
        int v, w, s;
        cin>>v>>w>>s;
        
        int index[s];
        int head=0, tail=0;
        for (int j=0; j<v; j++) {
            for (int k=j; k<=V; k+=v) {
                if ((tail>head) && (k-index[head] >= s*v))
                    head++;
                
                if (head>tail)
                    dp[k] = max(dp[k], dp[index[head]]+(k%v)*w);
                
                while (tail>head && dp[tail]<=dp[k]-k*w)
                    tail--;
                tail++;
                index[tail] = k;
            }
        }
    }
    
    cout << dp[V];
    
    return 0;
}