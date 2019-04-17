//
//  93.cpp
//  N阶楼梯上楼问题
//
//  Created by chenmeiqi on 2019/4/17.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
// 递归解法
int getKind(int n){
    if(n==1) return 1;
    else if(n==2) return 2;
    else {
        return getKind(n-1)+getKind(n-2);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    long long res[90];          // res数组保存数列的每一个值，由于数值过大，我们需要使用long long类型
    while (cin>>n) {
//        cout<<getKind(n)<<endl;           // 递归解法
        res[1]=1;
        res[2]=2;
        for (int i=3; i<=n; i++) {
            res[i]=res[i-1]+res[i-2];
        }
        cout<<res[n]<<endl;
    }
    return 0;
}
