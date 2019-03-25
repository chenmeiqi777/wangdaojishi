//
//  50.cpp
//  素数判定
//
//  Created by chenmeiqi on 2019/3/25.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int n=0;
    while (cin>>n) {
        bool prime_flag=true;
        if(n<=0||n==1){
            cout<<"no"<<endl;
        }
        else{
            for(int i=2;i<=sqrt(n);i++){
                if (n%i==0) {
                    cout<<"no"<<endl;
                    prime_flag=false;
                    break;
                }
            }
            if (prime_flag==true) {
                cout<<"yes"<<endl;
            }
        }
    }
    
    return 0;
}
