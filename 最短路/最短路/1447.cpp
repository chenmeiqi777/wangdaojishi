//
//  1447.cpp
//  最短路
//
//  Created by chenmeiqi on 2019/4/9.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
#define N 100
#define M 1001          // 题目中 C<=1000,所以 1001 代表无穷
int weight[N][N];
int main(int argc, const char * argv[]) {
    int n,m;
    int a,b;
    while(cin>>n>>m){
        if(n==0 && m==0){
            break;
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                weight[i][j]=M;             // 初始化
            }
            weight[i][i]=0;         //  自己到自己的路径长度设为0
        }
        
        
        while(m--){                 // 读入已有路径
            cin>>a>>b;
            cin>>weight[a-1][b-1];
            weight[b-1][a-1]=weight[a-1][b-1];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if (weight[i][k]+weight[k][j]<weight[i][j]) {       // 经过 k 后获得了更短的路径，更新该值
                        weight[i][j]=weight[i][k]+weight[k][j];
                    }
                    
                }
            }
        }
        cout<<weight[0][n-1]<<endl;         // 第一个到最后一个结点的距离
    }
    return 0;
}
