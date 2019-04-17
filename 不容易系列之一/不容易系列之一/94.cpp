//
//  94.cpp
//  不容易系列之一
//
//  Created by chenmeiqi on 2019/4/17.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
int getKinds(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        return (n-1)*getKinds(n-1)+(n-1)*getKinds(n-2);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    while (cin>>n) {
        cout<<getKinds(n)<<endl;
    }
    return 0;
}
