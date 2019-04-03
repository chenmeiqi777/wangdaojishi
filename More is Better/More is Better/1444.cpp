
//
//  1444.cpp
//  More is Better
//
//  Created by chenmeiqi on 2019/4/3.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
#define N 10000001                  // 后面没有分号！！
int Tree[N];
int sum[N];
int findRoot(int x){
    int res;
    while (Tree[x]!=0) {
        x=Tree[x];
    }
    res=x;
    return res;
}


int cmp(int a,int b){
    return a>b;
}


int main(int argc, const char * argv[]) {
    int n;
    int temp_n;
    int boy_1,boy_2;
    int res;
    while (cin>>n) {
        temp_n=n;
        res=1;                      // 答案初始化，至少为1
        for (int i=1; i<N; i++) {
            Tree[i]=0;
            sum[i]=1;               // 初始时都是1
        }
        while (temp_n--) {
            cin>>boy_1>>boy_2;
            boy_1=findRoot(boy_1);
            boy_2=findRoot(boy_2);
            if(boy_1!=boy_2){
                Tree[boy_1]=boy_2;
                sum[boy_2]+=sum[boy_1];             //合并两集时,将成为子树的树的根结点上保存
            }
        }
        for(int i=1;i<N;i++){
            if(Tree[i]==0 && res<sum[i]){           // 统计最大值，这里用了判断减去不必要的比较。
                res=sum[i];
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
