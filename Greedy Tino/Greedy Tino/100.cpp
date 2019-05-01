//
//  100.cpp
//  Greedy Tino
//
//  Created by chenmeiqi on 2019/4/28.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
#define OFFSET 2000
#define INF 0x7ffffff
int w[101];
int dp[101][4001];
int main(int argc, const char * argv[]) {
    int t,n;
    cin>>t;
    for (int s=1; s<=t; s++) {
        bool hasZero=false;
        int count=1;
        cin>>n;
        for (int i=1; i<=n; i++) {
            cin>>w[count];
            if(w[count]==0){
                count--;
                hasZero=true;
            }
            count++;
        }
        count--;
        n=count;
        for (int i=-2000; i<=2000; i++) {
            dp[0][i+OFFSET]=-INF;
        }
        dp[0][0+OFFSET]=0;
        for (int i=1; i<=n;i++) {
            for (int j=-2000; j<=2000; j++) {
                int tmp1=-INF,tmp2=-INF;
                if(j+w[i]<=2000 && dp[i-1][j+w[i]+OFFSET]!=-INF){
                    tmp1=dp[i-1][j+w[i]+OFFSET]+w[i];
                }
                if(j-w[i]>=-2000 && dp[i-1][j-w[i]+OFFSET]!=-INF){
                    tmp2=dp[i-1][j-w[i]+OFFSET]+w[i];
                }
                if(tmp1<tmp2){
                    tmp1=tmp2;
                }
                if(tmp1<dp[i-1][j+OFFSET]){
                    tmp1=dp[i-1][j+OFFSET];
                }
                dp[i][j+OFFSET]=tmp1;
            }
        }
        if (dp[n][0+OFFSET]==0) {
            if(hasZero){
                cout<<"Case "<<s<<":"<<0<<endl;
            }
            else{
                cout<<"Case "<<s<<":"<<-1<<endl;
            }
        }
        else{
            cout<<"Case "<<s<<":"<<dp[n][0+OFFSET]/2<<endl;
        }
    }
    return 0;
}
