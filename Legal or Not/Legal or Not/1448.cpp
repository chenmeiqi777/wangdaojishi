//
//  1448.cpp
//  Legal or Not
//
//  Created by chenmeiqi on 2019/4/10.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#define N 100
int main(int argc, const char * argv[]) {
    int n,m;
    int a,b;
    vector<int> edge[N];
    while(cin>>n>>m){
        if(n==0){
            break;
        }
        for(size_t i = 0; i < N; i++)               // 清空邻接链表
        {
            edge[i].clear();
        }
        
        while(m--){
            cin>>a>>b;
            edge[b].push_back(a);               // 这里是保存每个点的入结点
        }
        int now=-1;
        for(int k = now+1; k < N; k++)
        {
            if(edge[k].size()==0){
                if(k==N-1){                 // 到了最后一个
                    cout<<"YES"<<endl;
                    break;
                }
                else{                       // 更新现在的入度为0的结点
                    now=k;
                }
            }
            else{                       // 还没到最后一个就找不到入度为0的结点了，说明存在环路
                cout<<"NO"<<endl;
                break;
            }
            for(int i = 0; i < N; i++)                      // 去掉当前入度为0的结点的所有边
            {
                for(int j = 0; j < edge[i].size(); j++)
                {
                    if(edge[i][j]==now){
                        edge[i].erase(edge[i].begin()+j);           // erase(index) 删除vector中某元素
                    }
                }
            }
        }
    }
    return 0;
}
