//
//  1008.cpp
//  最短路径问题
//
//  Created by chenmeiqi on 2019/4/9.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#define N 1001
struct E{
    int next;
    int distance;
    int cost;
};
vector<E> edge[N];      // 邻接链表
int Dis[N];
int cost[N];
bool mark[N];
int main(int argc, const char * argv[]) {
    int n,m;
    int a,b,d,p;
    int s,t;            // 起点，终点
    while(cin>>n>>m){
        if(n==0 && m==0){
            break;
        }
        for(int i=1;i<=n;i++){      // 初始化
            edge[i].clear();
            Dis[i]=-1;
            cost[i]=0;
            mark[i]=false;
        }
        while(m--){             // 录入z已知信息
            cin>>a>>b>>d>>p;
            E e;
            e.next=b;
            e.distance=d;
            e.cost=p;
            edge[a].push_back(e);
            e.next=a;
            edge[b].push_back(e);
        }
        cin>>s>>t;
        Dis[s]=0;
        cost[s]=0;
        mark[s]=true;
        int newP=s;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < edge[newP].size(); j++)
            {
                int t=edge[newP][j].next;
                int d=edge[newP][j].distance;
                int c=edge[newP][j].cost;
                if(mark[t]==false){
                    if(Dis[t]==-1 || Dis[newP]+d<Dis[t] ||(Dis[newP]+d==Dis[t] && cost[newP]+c < cost[t])){     // 当距离更近或距离相等但花费更少时更新信息
                            Dis[t]=Dis[newP]+d;
                            cost[t]=cost[newP]+c;
                    }
                }
            }
            int min=123123123;
            for(int k=1;k<=n;k++){                  // 找到下一个最近点
                if(mark[k]==false && Dis[k]!=-1){
                    if(Dis[k]<min){
                        min=Dis[k];
                        newP=k;
                    }
                }
            }
            mark[newP]=true;
        }
        cout<<Dis[t]<<" "<<cost[t]<<endl;
    }
    return 0;
}
