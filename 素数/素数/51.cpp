//
//  51.cpp
//  素数
//
//  Created by chenmeiqi on 2019/3/26.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include<iostream>
#include<cmath>
using namespace std;

int main(void){
    int n=0;
    int a[1000001]={0};             // 0~1000000 个数
    a[0]=a[1]=1;
    while(cin>>n){
        bool prime_flag=false;
        for(int i=2;i<n;i++){           // 依次遍历2到1000000所有数字
            if(a[i]==0){
                int frequence=n/i;
                for(int j=i;j<=frequence;j++){           // 没有从 2 * i 开始，而是直接从 i * i 开始
                    a[i*j]=1;
                }
            }
        }
        int count=0;
        for(int k=1;k<n;k+=10){
            if(a[k]==0){
                if(count!=0){       // 除了第一个数，其他前面均输出空格，满足题目中 “素数之间用空格隔开，最后一个素数后没有空格” 的要求
                    cout<<" ";
                }
                cout<<k;
                prime_flag=true;
                count++;
            }
        }
        if(prime_flag==false){          // 没有一个素数，输出-1
            cout<<"-1";
        }
        cout<<endl;
        
    }
    return 0;
}
