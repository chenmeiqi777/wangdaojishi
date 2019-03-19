//
//  17.cpp
//  找x
//
//  Created by chenmeiqi on 2019/2/28.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int b_search(int low,int high,vector<int>a,int key){
    int index=0;
    while (low<=high) {
        index =ceil((low+high)/2);
        if(a[index]==key) return index;
        else if(a[index]<key) low=index+1;
        else high=index-1;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int n,i=0;
    int key=0;
    vector<int>a;
    cin>>n;
    int b=n;
    while(b--){
        cin>>i;
        a.push_back(i);
    }
    cin>>key;
    sort(a.begin(), a.end());
    
    // 二分查找
    int index=b_search(0, n-1, a, key);
    
    cout << index<<endl;
    return 0;
}
