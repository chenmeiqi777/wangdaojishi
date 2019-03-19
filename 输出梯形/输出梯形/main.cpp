//
//  14.cpp
//  输出梯形
//
//  Created by chenmeiqi on 2019/2/25.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    using namespace std;
    int h,bottomEdge=0;
    cin>>h;
    bottomEdge=h+2*(h-1);
    for(int i=1;i<=h;i++){
        for (int j=(bottomEdge-(h+2*(i-1)));j--;j>0) {
             cout<<" ";
        }
        for (int k=(h+2*(i-1));k--;k>0) {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
