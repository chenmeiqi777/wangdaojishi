//
//  105.cpp
//  产生冠军
//
//  Created by chenmeiqi on 2019/5/5.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    string s1,s2;           // 保存两个选手名称
    map<string,int> player;         // 定义一个完成从string到int映射的map
    int idx;
    int inDegree[2000];         // n<1000 组
    int res;
    while (cin>>n) {
        player.clear();     // 对map中的映射关系清空
        idx=0;      // 下一个被映射的数字
        for (int i=0; i<2*n; i++) {     // n组胜负关系，至多存在n个队伍
            inDegree[i]=0;          // 初始化入度
        }
        res=0;                  // 共有y几个入度为0的结点
        if (n==0) {
            break;
        }
        int tmp_n=n;
        while (tmp_n--) {
            cin>>s1>>s2;
            int idxb;
            if (player.find(s1)==player.end()) {        // map中无对s1的映射
                player[s1]=idx;                     // 设定其映射为idx，并递增idx
                idx++;
            }
            if (player.find(s2)==player.end()) {        // map中无对s2的映射
                player[s2]=idx;
                inDegree[idx]++;                    // s2对应的映射的入度加1
                idx++;
            }
            else{                                  // map中有对s2的映射
                idxb=player[s2];                // 直接读出该映射
                inDegree[idxb]++;
            }
        }
        for (int i=0; i<n; i++) {
            if (inDegree[i]==0) {               // 统计入度为1的结点数量
                res++;
            }
        }
        if (res==1) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
