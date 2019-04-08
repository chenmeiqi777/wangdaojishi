//
//  1017.cpp
//  还是畅通工程
//
//  Created by chenmeiqi on 2019/4/8.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int Tree[100];
struct Edge
{
    int begin;      // 起始顶点
    int end;        // 终点
    int weight;     // 该边权值
    bool operator < (const Edge& a) const{      // 重载 < 运算符
        return weight<a.weight;
    };
};
int findRoot(int x){            // 找根结点
    int res=0;
    while(Tree[x]!=0){
        x=Tree[x];
    }
    res=x;
    return res;
}
int main(int argc, const char * argv[]) {
    int n,a,b,temp;
    while(cin>>n){
        for (int i=0; i<100; i++) {
            Tree[i]=0;                  // 初始化
        }
        if(n==0){
            break;
        }
        int res=0;
        int number=n*(n-1)/2;
        vector<Edge> edges;
        while(number--){
            Edge e;
            cin>>e.begin>>e.end>>e.weight;
            edges.push_back(e);
        }
        sort(edges.begin(),edges.end());            // 排序，以从权值小的边开始遍历
        int count=edges.size();
        for(int i=0;i<count;i++)
        {
            a=findRoot(edges[i].begin);
            b=findRoot(edges[i].end);
            temp=edges[i].begin;
            if(a!=b){
                Tree[a]=b;
                while(Tree[temp]!=0){               // 路径压缩优化
                    int t=Tree[temp];
                    Tree[temp]=b;
                    temp=t;
                }
                res+=edges[i].weight;               // 累加该边权值
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
