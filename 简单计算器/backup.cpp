//
//  backup.cpp
//  简单计算器
//
//  Created by chenmeiqi on 2019/3/14.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;


int main(int argc, const char * argv[]) {
    char s[220]={0};
    while(cin.getline(s, 220)){
        if(s[0]=='0') break;
        stack<char> S;
        float result=0;
        float temp_result[200]={0};
        int j=0;
        float temp_1=0;
        float temp_2=0;
        int count=1;
        
        int len=0;
        for(;len<220;len++){
            if(s[len]=='\0')break;
        }
        for(int i=0;i<len;i++){
            if(s[i]=='*'){
                temp_1=temp_result[j-1];        // 不是S.top(),因为S里存的还是一个个字符，不是合在一起的整数
                S.pop();
                if(s[i+1]==' ')temp_2=s[i+2]-'0';   // 有空格就是后面两位
                else temp_2=s[i+1]-'0';                  // 没空格就是后面一位
                for(int k=i+1;k<len;k++){
                    if(s[i+1]==' '){
                        if(isdigit(s[k+2]) == 0)break;
                        else{
                            temp_2=temp_2*10+s[k+2]-'0';
                            count+=2;           // 每次跳两个字符
                            k++;
                        }
                    }
                    else{
                        if(isdigit(s[k+1]) == 0)break;
                        else{
                            temp_2=temp_2*10+s[k+1]-'0';
                            count++;
                        }
                    }
                }                temp_result[j-1]=temp_1*temp_2;
                i+=count;
            }
            else if(s[i]=='/'){
                temp_1=temp_result[j-1];
                S.pop();
                if(s[i+1]==' ')temp_2=s[i+2]-'0';   // 有空格就是后面两位
                else temp_2=s[i+1]-'0';                  // 没空格就是后面一位
                for(int k=i+1;k<len;k++){
                    if(s[i+1]==' '){
                        if(isdigit(s[k+2]) == 0)break;
                        else{
                            temp_2=temp_2*10+s[k+2]-'0';
                            count+=2;           // 每次跳两个字符
                            k++;
                        }
                    }
                    else{
                        if(isdigit(s[k+1]) == 0)break;
                        else{
                            temp_2=temp_2*10+s[k+1]-'0';
                            count++;
                        }
                    }
                }
                temp_result[j-1]=temp_1/temp_2;
                i+=count;               // 合并了几位数字，i要往后移，不再读取这些数字
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
        cout << setprecision(2) << result<<endl;
    }
    return 0;
}
