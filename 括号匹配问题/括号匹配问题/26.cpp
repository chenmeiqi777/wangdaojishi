//
//  26.cpp
//  括号匹配问题
//
//  Created by chenmeiqi on 2019/3/12.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

// 每一个右括号，必定是与在其之 前的所有未被匹配的左括号中最靠右的一个匹配
#include <iostream>
#include <stack>
using namespace std;

void method_1(string s){
    stack<char> S;
    char out[100]={0};
    int index_right[100],index_left[100];
    int j=0;
    int k=0;
    memset(index_right, -1, 100*sizeof(int));
    memset(index_left, -1, 100*sizeof(int));
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') {
            S.push(s[i]);
            index_left[j]=i;
            j++;
        }
        else if(s[i]==')'){
            if(S.empty()){      // 若堆栈为空，则表示在其之前不存在未被匹配的左括号，匹配失败。
                index_right[k]=i;
                k++;
            }
            // 先判断是否为空在top()！否则报指针错误
            else if(S.top()=='('){      // 堆栈非空，那么栈顶左括号即为与其匹配的左括号
                S.pop();
                index_left[j-1]=-1;
                j--;
            }
        }
    }
    cout<<"Method1:"<<endl;
    cout<<s<<endl;
    for(int t=0;t<s.length();t++){
        if(index_right[t]!=-1) out[index_right[t]]='?';
        if(index_left[t]!=-1) out[index_left[t]]='$';  // 不能写 else
    }
    for (int b=0; b<s.length(); b++) {
        if(out[b])cout<<out[b];             // '\0' 不占位
        else cout<<" ";
    }
    cout<<endl;
}

void method_2(string s){
    stack<int> S;
    char out[100]={0};
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') {
            S.push(i);          // 堆栈保存左括号在字符串中的序号
            out[i]=' ';
        }
        else if(s[i]==')'){
            if(S.empty()){
                out[i]='?';     // 右括号不匹配
            }
            else{               // 其实只考虑空与不空两种情况就行了
                S.pop();
                out[i]=' ';     // 左右括号b匹配
            }
        }
    }
    while (!S.empty()) {
        out[S.top()]='$';       // 左括号不匹配
        S.pop();
    }
    cout<<"Method2:"<<endl;
    cout<<s<<endl;

    for (int b=0; b<s.length(); b++) {
        if(out[b])cout<<out[b];
        else cout<<" ";
    }
    cout<<endl;
}
int main(int argc, const char * argv[]) {
    string s;
    cin>>s;
    method_1(s);        // 设置两个数组分别保存不匹配的左括号和右括号
    method_2(s);        // 直接保存在输出数组里
    return 0;
}
