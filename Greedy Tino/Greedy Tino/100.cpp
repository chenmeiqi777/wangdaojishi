//
//  100.cpp
//  Greedy Tino
//
//  Created by chenmeiqi on 2019/4/28.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
#define OFFSET 2000     // 因为柑橘重量差存在负数的情况，即第一堆比第二堆轻，所以在计算重量差对应的数组下标时应加上该偏移值，使每个重量差对应合法的数组下标
#define INF 0x7ffffff       // 无穷
int w[101];     // 保存柑橘数量
int dp[101][4001];      // 保存状态
int main(int argc, const char * argv[]) {
    int t,n;
    cin>>t;
    for (int s=1; s<=t; s++) {
        bool hasZero=false;     //统计是否存在重量为0的柑橘
        int count=1;        // 计数器，记录共有多少个重量非零的柑橘
        cin>>n;
        for (int i=1; i<=n; i++) {      // 输入n个柑橘重量
            cin>>w[count];
            if(w[count]==0){            // 若当前输入柑橘重量为0
                count--;        // 去除这个柑橘
                hasZero=true;       // 并记录：存在重量为0的柑橘
            }
            count++;
        }
        count--;            // 要-1
        n=count;
        for (int i=-2000; i<=2000; i++) {
            dp[0][i+OFFSET]=-INF;           // 初始化，不往两堆中加任何柑橘时，两堆重量差不为0的状态不存在
        }
        dp[0][0+OFFSET]=0;          //  不往两堆中加任何柑橘时，两堆最大总重量为0
        for (int i=1; i<=n;i++) {       // 遍历每个柑橘
            for (int j=-2000; j<=2000; j++) {       // 遍历每种可能的重量差
                int tmp1=-INF,tmp2=-INF;            // 分别记录当前柑橘放在第一堆获第二堆时转移得来的新值，若无法转移则为-INF
                if(j+w[i]<=2000 && dp[i-1][j+w[i]+OFFSET]!=-INF){       // 当状态可由第一堆转移而来时（放到第二堆）
                    tmp1=dp[i-1][j+w[i]+OFFSET]+w[i];           // 记录转移值
                }
                if(j-w[i]>=-2000 && dp[i-1][j-w[i]+OFFSET]!=-INF){      // 当状态可由第二堆转移而来时（放到第一堆）
                    tmp2=dp[i-1][j-w[i]+OFFSET]+w[i];
                }
                if(tmp1<tmp2){          // 取较大的那个，存到tmp1
                    tmp1=tmp2;
                }
                if(tmp1<dp[i-1][j+OFFSET]){     //将tmp1与当前柑橘不放入任何堆，即状态差不发生改变的原状态值比较，取较大的那个，存到tmp1
                    tmp1=dp[i-1][j+OFFSET];
                }
                dp[i][j+OFFSET]=tmp1;       // 当前状态值
            }
        }
        if (dp[n][0+OFFSET]==0) {           // 不存在任何非0的组合使两堆重量相等
            if(hasZero){
                cout<<"Case "<<s<<":"<<0<<endl;             // 存在重量为0的柑橘
            }
            else{
                cout<<"Case "<<s<<":"<<-1<<endl;        // 不存在
            }
        }
        else{
            cout<<"Case "<<s<<":"<<dp[n][0+OFFSET]/2<<endl;     // 直接输出
        }
    }
    return 0;
}
