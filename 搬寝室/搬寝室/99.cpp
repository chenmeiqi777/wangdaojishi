//
//  99.cpp
//  搬寝室
//
//  Created by chenmeiqi on 2019/4/28.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
#define INF 0xfffffff    // 预定义最大的int取值为无穷
int main(int argc, const char * argv[]) {
    int n,k;
    int w[2001];        // 保存每个物品重量
    int  dp[1001][2001];        // 保存每个状态
    while (cin>>n>>k) {
        w[0]=0;
        for (int i=1; i<=n; i++) {
            cin>>w[i];
        }
        sort(w+1, w+1+n);       // 使所有物品按照重量递增排序
        for (int i=0; i<=k; i++) {
            for (int j=0; j<=n; j++) {
                if (i==0) {       // 初始值
                    dp[i][j]=0;
                }
                else if(2*i>j){     // 配对数大于总数，设置为正无穷
                    dp[i][j]=INF;
                }
                
                else{       // 根据最后一个是否配对分为两种情况，取最小值
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j-2]+(w[j]-w[j-1])*(w[j]-w[j-1]));
                }
            }
        }
        cout<<dp[k][n]<<endl;
    }
    return 0;
}
