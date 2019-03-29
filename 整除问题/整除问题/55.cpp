//
//  55.cpp
//  整除问题
//
//  Created by chenmeiqi on 2019/3/28.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <array>
#include <cmath>
using namespace std;

array<int, 1001> getPrime(int x){
    array<int, 1001> prime_x={0};
    prime_x[0]=1;
    prime_x[1]=1;
    for (int i=2; i<=x; i++) {
        if (prime_x[i]==0) {
            int frequence=x/i;
            for (int j=i; j<=frequence; j++) {
                prime_x[i*j]=1;
            }
        }
    }
    return prime_x;
}

int main(int argc, const char * argv[]) {
    int n,a;
    array<int, 1001> prime={0};
    prime=getPrime(1000);              // 筛选出 0 ～ 1000 所有素数
    
    while(cin>>n>>a){
        int ans=123123123;         // ans 初始化为一个大整数，为取最小值做准备
        int temp_a=a;           // 临时变量 temp_a 保存 a 的值
        array<int, 1001> exponent_a={0};        // 保存 a 的素因数的指数
        array<int, 1001> exponent_n={0};        // 保存 n 的素因数的指数
      
        for(int i=2;i<=n;i++){
            int temp_n=n;                // 临时变量 temp_n 保存 n 的值
            if(prime[i]==0){
                while (temp_n) {
                    exponent_n[i]+=temp_n/i;
                    temp_n/=i;
                }
            }
        }
        
        for (int i=2; i<=a; i++) {
            if(prime[i]==0){
                while (a%i==0) {            // 找到 a 的素因数
                    exponent_a[i]++;        // 确定指数
                    a/=i;
                }
            }
        }
        

        for(int i=2;i<=temp_a;i++){
            if(exponent_a[i]!=0){           // 若该素数不能从 a 中分解到，即其对应幂指数为 0，则其不影响整除性
                if(exponent_n[i]/exponent_a[i]<=ans){
                    ans=exponent_n[i]/exponent_a[i];
                }
            }
        }
        
        cout << ans <<endl;
    }
    return 0;
}
