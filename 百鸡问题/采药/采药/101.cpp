//
//  101.cpp
//  采药
//
//  Created by chenmeiqi on 2019/5/2.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
struct N{           // 保存物品信息结构体
    int t;      // 物品体积（采摘时间）
    int w;      // 物品价值
};
//int main(int argc, const char * argv[]) {
//    int T,M;
//    N herb[101];
//    int time;
//    int dp[101][1001];        // 记录状态数组，dp[i][j]表示前i个物品组成的总体积不大于j的最大价值和
//    while (cin>>T>>M) {
//        time=0;
//        for (int i=1; i<=M; i++) {        // 输入
//            cin>>herb[i].t>>herb[i].w;
//        }
//        for (int i=0; i<=M; i++) {            // 初始化状态
//            dp[0][i]=0;
//        }
//        for (int i=1; i<=M; i++) {        // 循环每一个物品
//            for (int j=T; j>=herb[i].t; j--) {        // 对T到herb[i].t的每个j，状态转移来源为dp[i-1][j]或dp[i-1][j-herb[i].t]+herb[w]，选择其中较大的值
//                dp[i][j]=max(dp[i-1][j-herb[i].t]+herb[i].w,dp[i-1][j]);
//            }
//            for (int j=herb[i].t-1; j>=0; j--) {      // 对herb[i].t-1到0的每个j，状态仅能来源于dp[i-1][j]，固直接赋值
//                dp[i][j]=dp[i-1][j];
//            }
//        }
//        cout<<dp[M][T]<<endl;
//    }
//    return 0;
//}
int main(int argc, const char * argv[]) {
    int T,M;
    N herb[101];
    int time;
    int dp[101];
    while (cin>>T>>M) {
        time=0;
        for (int i=1; i<=M; i++) {
            cin>>herb[i].t>>herb[i].w;
        }
        for (int i=0; i<=M; i++) {
            dp[i]=0;
        }
        for (int i=1; i<=M; i++) {
            for (int j=T; j>=herb[i].t; j--) {      // 必须倒序更新每个dp[j]的值，j小于herb[i].t的各dp[j]不更新，保持原值，即等价于dp[i][j]=dp[i-1][j]
                dp[j]=max(dp[j],dp[j-herb[i].t]+herb[i].w);     // dp[j]在原值和dp[j-list[i].w]+list[i].v中选取较大的那个
            }
        }
        cout<<dp[T]<<endl;
    }
    return 0;
}
