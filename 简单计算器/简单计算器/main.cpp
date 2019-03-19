//
//  main.cpp
//  简单计算器
//
//  Created by chenmeiqi on 2019/3/13.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//


#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

// 去掉空格
string remove_space(char s[]){
    string x="";
    for(int i=0;i<220;i++){
        if(s[i]=='\0') break;       // 到尾部就结束
        else if(s[i]!=' ') x+=s[i];     // 加上非空格字符
    }
    return x;
}
// 思路： * 和 / 直接提出来运算（前一个数和后一个数），+、-和数字先入栈，然后逐步计算。
// 可读性略差，扩展性不高。
void method_1 (){
    char c[220]={0};
    string s;
    while(cin.getline(c, 220)){     // 读取一行字符串！！getline将丢弃换行符，而get()将换行符保留在输入序列里。
                                                    //所以，在使用cin.get()输入多行数据时，中间可以使用get()消除换行符。
        if(c[0]=='0') break;
        stack<char> S;
        float result=0;
        float temp_result[200]={0};
        int j=0;
        float temp_1=0;
        float temp_2=0;
        int count=1;
        
        s=remove_space(c);
        
        // 求字符串数组长度
        //        int len=0;
        //        for(;len<220;len++){
        //            if(s[len]=='\0')break;
        //        }
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                temp_1=temp_result[j-1];        // 不是S.top(),因为S里存的还是一个个字符，不是合在一起的整数
                S.pop();
                temp_2=s[i+1]-'0';
                for(int k=i+1;k<s.length();k++){        // 将char转成第二个数，考虑‘99’=99
                    if(isdigit(s[k+1]) == 0)break;      // 遇到非数字就停止
                    else{
                        temp_2=temp_2*10+s[k+1]-'0';
                        count++;
                    }
                }
                temp_result[j-1]=temp_1*temp_2;
                i+=count;                        // 合并了几位数字，i要往后移，不再读取这些数字
            }
            else if(s[i]=='/'){
                temp_1=temp_result[j-1];
                S.pop();
                temp_2=s[i+1]-'0';
                for(int k=i+1;k<s.length();k++){
                    if(isdigit(s[k+1]) == 0)break;
                    else{
                        temp_2=temp_2*10+s[k+1]-'0';
                        count++;
                    }
                }
                temp_result[j-1]=temp_1/temp_2;
                i+=count;
            }
            else if(s[i]=='+' || s[i]=='-'){
                S.push(s[i]);           // 直接入栈
            }
            else if(isdigit(s[i])){
                if(i>0 && isdigit(s[i-1]) != 0){         // isdigit判断其上一个是否是数字，
                    // 若是数字或返回非0数（i>0 判断防止越界）
                    temp_result[j-1]=temp_result[j-1]*10+s[i]-'0';      // 更改上一个位置的数
                    S.pop();            // 合并一个就弹出一个
                }
                else{
                    temp_result[j]=s[i]-'0';
                    j++;
                }
                S.push(s[i]);
            }
        }
        j-=1;
        result=temp_result[j];
        while(!S.empty()){
            if(isdigit(S.top())!=0)S.pop();        // 如果栈顶是数字，就先把数字弹出来
            else if(S.top()=='+'){
                S.pop();                        // 弹出 ‘+’
                result+=temp_result[j-1];       // 上两个数相加
                temp_result[j-1]=result;
                if(j>0) j--;
            }
            else if(S.top()=='-'){
                S.pop();                             // 弹出 ‘-’
                result=temp_result[j-1]-result;     // 倒数第二个数减去倒数第一个数
                temp_result[j-1]=result;
                if(j>0) j--;
            }
        }
        // 保留两位小数
        cout<<setiosflags(ios::fixed);              // setprecision(n)和fixed合用可以控制小数点后有几位。
        cout<<setprecision(2);                      // setprecision(n)是控制保留几位 有效数字 的，
                                                    // 不是小数，不会补上0
        cout <<result<<endl;
    }

}

int main(int argc, const char * argv[]) {
    //method_1();
    char a = '0';
    int ia = (int)a;
    int x = ia - 48;
    cout<<x<<endl;
    return 0;
}
