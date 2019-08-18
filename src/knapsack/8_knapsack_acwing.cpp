/*
	状态转移方程：
    dp[j] = max(dp[j], dp[j-v[i]]+w[i], dp[j-2v[i]]+2w[i]...)
*/

#include <iostream>

using namespace std;

int main()
{
    int N, V;
    cin>>N>>V;
    
    int dp[V+1];
    for (int i=0; i<=V; i++) dp[i] = 0;
    
    for (int i=0; i<N; i++) {
        int s;
        cin>>s;
        
        int v[s], w[s];
        for (int i=0; i<s; i++) cin>>v[i]>>w[i];
        /*
			该循环错误之处在于数据读取层，本身没有错误
			因为枚举容量时，是对整个组进行的，而该数据读取
			方式一个组只使用了一次，然后把后续不该用到的组取了出来
			所以应该先把组数据取出，然后再进行容量枚举 ！
        for (int j=V; j>=0; j--) {
            for (int k=0; k<s; k++) {
                int v, w;
                cin>>v>>w;
                if (j>=v)
                    dp[j] = max(dp[j], dp[j-v]+w);
            }
        }
        */
        
        for (int j=V; j>=0; j--) {
            for (int k=0; k<s; k++) {
                if (j>=v[k])
                    dp[j] = max(dp[j], dp[j-v[k]]+w[k]);
            }
        }
    }
    
    cout << dp[V];
    
    return 0;
}