//
//  95.cpp
//  拦截导弹
//
//  Created by chenmeiqi on 2019/4/17.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){      // 从高到低排
    return a>b;
}
int main(int argc, const char * argv[]) {
    int k;
    int a[26];
    int max;
    while (cin>>k) {
        int res[26]={0};                    // 初始化，便于排序
        for (int i=0; i<k; i++) {
            cin>>a[i];
        }
        res[0]=1;               //  初始化0位置的最长子序列为1
        for (int i=1; i<k; i++) {
            res[i]=1;
            max=1;
            for (int j=i-1; j>=0; j--) {
                if (a[i]<=a[j] && res[j]+1>max) {      // “不高于”
                    res[i]=res[j]+1;
                    max=res[i];
                }
            }
        }
        sort(res, res+26,cmp);          // 排序
        cout<<res[0]<<endl;
    }
    return 0;
}
