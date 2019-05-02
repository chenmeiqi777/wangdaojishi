//
//  102.cpp
//  Piggy-Bank
//
//  Created by chenmeiqi on 2019/5/2.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
#define INF 0x7fffffff

struct N{           // 代表钱币结构体
    int w;
    int v;
}list[501];

int main(int argc, const char * argv[]) {
    int T,E,F,N;
    int dp[10001];
    cin>>T;
    while (T--) {
        cin>>E>>F;
        cin>>N;
        int s=F-E;
        for (int i=1; i<=N; i++) {
            cin>>list[i].v>>list[i].w;
        }
        dp[0]=0;
        for (int i=1; i<=s; i++) {      // 初始化与 0-1 bag 不同。（要求恰好装满）
            dp[i]=INF;
        }
        for (int i=1; i<=N; i++) {
            for (int j=list[i].w; j<=s; j++) {      // 顺序遍历
                if (dp[j-list[i].w]!=INF) {         // 若dp[j-list[i].w]不为无穷，就可以由o此状态转移而来
                    dp[j]=min(dp[j],dp[j-list[i].w]+list[i].v);     // 取最小值
                }
            }
        }
        if (dp[s]!=INF) {       // 存在一种方案使背包恰好装满。输出其最小值
             cout<<"The minimum amount of money in the piggy-bank is "<<dp[s]<<endl;
        }
        else{       // 不存在
            cout<<"This is impossible"<<endl;
        }
    }
    return 0;
}
