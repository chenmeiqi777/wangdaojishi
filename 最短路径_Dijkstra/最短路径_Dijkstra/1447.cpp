//
//  1447.cpp
//  最短路径_Dijkstra
//
//  Created by chenmeiqi on 2019/4/9.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#define M 1001
struct E{
    int next;           // 直接相邻的结点
    int c;              // 该边的权值
};
vector<E> edge[101];        // 邻接链表
bool mark[101];     // 标记，当mask[j]为true时表示结点j的最短路径长度已经得到，该结点已经加入集合K
int Dis[101]; // 距离向量，当mask[i]为true时，表示已得到最短路径长度；否则，表示所有从结点1出发，经过已知的最短路径达到集合K中的某结点，再经过一条边到达结点i的路径中最短的距离
int main(int argc, const char * argv[]) {
    int n,m;
    while(cin>>n>>m){
        if(n==0&&m==0){
            break;
        }
        for(int i=1;i<=n;i++){
            edge[i].clear();            // 初始化邻接链表
        }
        while(m--){
            int a,b,c;
            cin>>a>>b>>c;
            E tmp;
            tmp.c=c;
            tmp.next=b;
            edge[a].push_back(tmp);
            tmp.next=a;
            edge[b].push_back(tmp);     //将邻接信息加入邻接链表，由于原图为无向图，故每条边信息都要添加到其两个顶点的单链表中
        }
        for(int i=1;i<=n;i++){
            Dis[i]=M;          // 所有距离为1001，即不可达
            mark[i]=false;      // 所有结点不属于集合K
        }
        Dis[1]=0;           // 得到最近的点为结点1，长度为0
        mark[1]=true;       // 将结点1加入集合K
        int newP=1;         // 集合K中新加入的点为结点1
        for(int i=1;i<n;i++){
            for(int j=0;j<edge[newP].size();j++){
                int t=edge[newP][j].next;
                int c=edge[newP][j].c;
                if(mark[t]==false){
                    if(Dis[newP]+c<Dis[t]){
                        Dis[t]=Dis[newP]+c;
                    }
                }
            }
            int min=M;
            for(int j=1;j<=n;j++){
                if(mark[j]==false && Dis[j]<min){
                    min=Dis[j];
                    newP=j;
                }
            }
            mark[newP]=true;
        }
        cout<<Dis[n]<<endl;
    }
    return 0;
}
