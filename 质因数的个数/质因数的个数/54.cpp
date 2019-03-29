//
//  54.cpp
//  质因数的个数
//
//  Created by chenmeiqi on 2019/3/27.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n=0;
    int count;          // 幂指数个数
    static int a[100001]={0};             // 把大数组开在了 Data Segment 中
    a[0]=a[1]=1;
    while(cin>>n){
        for(int i=2;i<n;i++){           // 依次遍历2到1000000所有数字
            if(a[i]==0){
                int frequence=n/i;
                for(int j=i;j<=frequence;j++){           // 没有从 2 * i 开始，而是直接从 i * i 开始
                    a[i*j]=1;
                }
            }
        }
        count=0;
        for(int k=2;k<=n;k+=1){
            if(a[k]==0){
                while(n%k==0){
                    count++;
                    n=n/k;           // 从被测试数中将该素数分解出来
                }
            }
        }
        if(n!=1){       // 若测试完2到100000内所有素因数，n仍未被分解至1，则剩余的因数一定是一个大于100000素因数
            count++;
        }
        cout<<count<<endl;
        
    }
    return 0;
}
