/*
* Copyright(c) 2019 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* This repo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation
*
* It is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int N, V;
    cin>>N>>V;
    
    int dp_k[V+1];
    int dp_k_1[V+1];
    for (int i=0; i<=V; i++) dp_k[i] = 0;
    
    for (int i=0; i<N; i++) {
        int v, w, s;
        cin>>v>>w>>s;
        
        //memcpy(dp_k_1, dp_k, V+1);
        memcpy(dp_k_1, dp_k, sizeof(dp_k));
        int window_size = min(V/v, s);
        int index[window_size];
        for (int j=0; j<v; j++) {
            
            int head = 0, tail = -1;
            for (int k=j; k<=V; k+=v) {
                if (tail>=head && k-index[head] > window_size * v)
                    head++;
                    
                if (tail >= head)
                    dp_k[k] = max(dp_k[k], dp_k_1[index[head]] + (k-index[head]) / v * w);
                    
                //while (tail>head && (dp_k_1[index[tail]] - (index[tail] - j) / v * w) <= (dp_k[k] - (k-j) / v *w))
                // 入队列的是上一时刻的数据 !
                while (tail>=head && (dp_k_1[index[tail]] - (index[tail] - j) / v * w) <= (dp_k_1[k] - (k-j) / v *w))
                    tail--;
                /*
                    head = 0, tail = 0 为初始值这里就有问题了
                    第一次循环数据放在了 tail = 1 的地方
                    而应该从head =0 处开始存放
                */
                tail++;
                index[tail] = k;
            }
        }
    }
    
    cout << dp_k[V];
    
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, V;
    cin>>N>>V;
    int d_k[V+1];
    int d_k_1[V+1];
    
    for (int i=0; i<=V; i++) d_k[i] = 0;
    
    for(int i=1;i<=N;i++)
    {
        int v,w,s;
        cin>>v>>w>>s;
        memcpy(d_k_1,d_k,sizeof(d_k));
        //滚动数组优化空间，g[]即f[i-1][];
        int window_size = min(V/v, s);
        int index[window_size];
        for(int j=0;j<v;j++)
        {
            //int hh=0,tt=-1;
            int head = 0, tail = -1;
            for(int k=j;k<=V;k+=v)
            {
                if(head<=tail && k-window_size*v>index[head])  
                //如果当前窗口的内容超过了s个;
                {
                    head++;
                }
                if(head<=tail) 
                {
                    d_k[k]=max(d_k[k],d_k_1[index[head]]+(k-index[head])/v*w); 
                    //max(f[i-1][k],f[i-1][能转移里最大]+个数*v[i]);
                }
                while(head<=tail && d_k_1[index[tail]]-(index[tail]-j)/v*w <= d_k_1[k]-(k-j)/v*w)
                {
                    tail--;
                }
                tail++;
                index[tail]=k;
            }
        }
    }
    cout<<d_k[V]<<endl;
}
*/

/*
	最终版
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int N, V;
    cin>>N>>V;
    
    int dp_k[V+1];
    int dp_k_1[V+1];
    for (int i=0; i<=V; i++) dp_k[i] = 0;
    
    for (int i=0; i<N; i++) {
        int v, w, s;
        cin>>v>>w>>s;
        
        memcpy(dp_k_1, dp_k, sizeof dp_k);
        
        int window_size = min(s, V/v);
        int index[window_size];
        for (int j=0; j<v; j++) {
            int head = 0, tail = -1;
            for (int k=j; k<=V; k+=v) {
                if (tail>=head && k-index[head]>window_size*v)
                    head++;
                    
                if (tail>=head)
                    dp_k[k] = max(dp_k[k], dp_k_1[index[head]] + (k-index[head])/v*w);
                    
                while (tail>=head && (dp_k_1[index[tail]] - (index[tail] - j) / v*w) <= (dp_k_1[k] - (k-j)/v*w))
                    tail--;
                    
                tail++;
                index[tail] = k;
            }
            
        }
    }
    
    cout << dp_k[V];
    
    return 0;
}