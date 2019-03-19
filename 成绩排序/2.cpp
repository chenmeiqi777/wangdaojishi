//
//  main.cpp
//  wdjs
//
//  Created by chenmeiqi on 2019/2/22.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>       // 引入vector
using namespace std;
class student{
private:
    string name;
    int age,score;
public:
    student(){
        name=' ';
        age=0;
        score=0;
    }
    student(string input_name,int input_age,int input_score){       //构造函数重载
        name=input_name;
        age=input_age;
        score=input_score;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    int getScore(){
        return score;
    }
    
    // 重构 < 运算符
    bool operator <(const student &a ) const{     // 加const是因为：①我们不希望在这个函数中对用来进行赋值的“原版”做任何修改。
    // ②加上const，对于const的和非const的实参，函数就能接受；如果不加，就只能接受非const的实参。
    // 用引用是因为：这样可以避免在函数调用时对实参的一次拷贝，提高了效率。

        if(score!=a.score) return score<a.score;
        else if(name.compare(a.name)!=0) return name<a.name;
        else if(age!=a.age)return age<a.age;
        else
            return false;
    }
};
vector<student> Vec_stu;

bool cmp(student a,student b){      // 比较函数
    if(a.getScore()<b.getScore())
        return true;
    else if(a.getName()<b.getName())
        return true;
    else if(a.getScore()<b.getScore())
        return true;
    else
        return false;
}

int main(int argc, const char * argv[]) {
    int n,number;  // 学生人数
    string input_name;
    int input_age,input_score;
    cin>>n;
    number = n;
    while(n--){
        cin>>input_name>>input_age>>input_score;
        student stu(input_name,input_age,input_score);
        Vec_stu.push_back(stu);     // 插入vector
    }
    // sort(Vec_stu.begin(), Vec_stu.end(), cmp);   // 使用比较函数
    sort(Vec_stu.begin(), Vec_stu.end());      // 重构运算符
    for (int i=0; i<number; i++) {
        cout<<Vec_stu[i].getName()<<' '<< Vec_stu[i].getAge()<<' '<<Vec_stu[i].getScore()<<endl;
    }
    return 0;
}
