//
//  48.cpp
//  最小公倍数
//
//  Created by chenmeiqi on 2019/3/25.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;

int GCD(int a,int b){           // 求最大公约数
    int temp=0;
    while(b!=0){
        temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}

int main(int argc, const char * argv[]) {
    int a,b;
    int gcd;
    int lcm;
    while (cin>>a>>b) {
        gcd=GCD(a, b);
        lcm=a*b/gcd;
        cout<<lcm<<endl;
    }
    return 0;
}
