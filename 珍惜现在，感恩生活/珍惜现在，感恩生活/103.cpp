//
//  103.cpp
//  珍惜现在，感恩生活
//
//  Created by chenmeiqi on 2019/5/4.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;

struct N{       // 大米
    int v;      // 价格
    int w;      // 重量
}list[2001];   // 100*20

int main(int argc, const char * argv[]) {
    int C;
    int n,m;
    int count;
    int  dp[101];
    cin>>C;
    while (C--) {
        count=0;            // 拆分后物品总数
        cin>>n>>m;
        for (int i=1; i<=m; i++) {      // 输入
            int v,w,k;
            cin>>v>>w>>k;
            int c=1;
            while (k-c>0) {         // 对输入的数字k，拆分成1，2，4...k-2^c-1
                k-=c;
                list[++count].v=v*c;            // 拆分后的大米重量和价格均为组成该物品的大米的重量价格和
                list[count].w=w*c;
                c*=2;
            }
            list[++count].v=v*k;
            list[count].w=w*k;
        }
        for (int i=1; i<=n; i++) {      // 初始值
            dp[i]=0;
        }
        for(int i=1;i<=count;i++){          // 对拆分后的所有物品进行0-1背包
            for (int j=n; j>=list[i].v; j--) {
                dp[j]=max(dp[j], dp[j-list[i].v]+list[i].w);
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
