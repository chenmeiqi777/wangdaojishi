//
//  18.cpp
//  查找学生信息
//
//  Created by chenmeiqi on 2019/2/28.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class student{
public:
    int id;
    string name;
    string gender;
    int age;
    
    student(){
        id=00;
        name="";
        gender="";
        age=0;
    }
    student(int input_id,string input_name,string input_gender,int input_age){
        id=input_id;
        name=input_name;
        gender=input_gender;
        age=input_age;
    }
    // https://www.cnblogs.com/zpcdbky/p/5027481.html 好文
    bool operator <(const student &a) const{    // 重载运算符 < ，进行排序
        return id<a.id;
    }
    
    bool operator <(int a) const{           //  重载运算符 <（参数不同），比较vec[index]<key
        return id<a;
    }
    
    bool operator ==(int a) const{           // 重载运算符 == ，不然无法比较 vec[index]==key
        return id==a;
    }
};
vector<student>vec;

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
    int n,m=0;
    cin>>n;
    int n_count=n;
    int input_id;
    string input_name;
    string input_gender;
    int input_age;
    
    int key=0;
    int index=0;
    int low,high;
    
    while(n_count--){
        cin>>input_id>>input_name>>input_gender>>input_age;
        student stu(input_id,input_name,input_gender,input_age);
        vec.push_back(stu);
    }
    sort(vec.begin(), vec.end());       // 排序
    
    cin>>m;

    while (m--) {           // 二分查找
        cin>>key;
        low=0;
        high=n-1;
        while (low<=high) {
            index =ceil((low+high)/2);
            if(vec[index]==key) break;
            else if(vec[index]<key) low=index+1;
            else high=index-1;
            index=-1;
        }
        
        if(index==-1) cout<<"No answer!"<<endl;
        else cout <<vec[index].id<<' '<<vec[index].name<<' '<<vec[index].gender<<' '<<vec[index].age<<endl;
    }
    return 0;
}

