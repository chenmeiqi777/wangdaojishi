//
//  6.cpp
//  wdjs
//
//  Created by chenmeiqi on 2019/2/22.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//


// 思路：1.先算第一年到年底的天数（考虑闰平年），加上 2.年初到第二年的天数（365或366减第二年到年底的天数，视闰平年而定），再加 3.中间年的天数（考虑闰平年）

// 另一种思路是找一个基准点：把原区间问题统一到起点确定的区间问题上去。在该例中，我们不妨把问题统一到特定日期与一个原点时间(如 0000 年 1 月 1 日) 的天数差，当要求两个特定的日期之间的天数差时，我们只要将它们与原点日期 的天数差相减，便能得到这两个特定日期之间的天数差(必要时加绝对值)。这样做有一个巨大的好处——预处理。我们可以在程序真正开始处理输入数据之前，预处理出所有日期与原点日期之间的天数差并保存起来。当数据真正开始输入时，我们只需要用 O(1)的时间复杂度将保存的数据读出，稍加处理便能得 到答案。值得一提的是，预处理也是空间换时间的重要手段(保存预处理所得数 据所需的内存来换取实时处理所需要的时间消耗)。

// 知识点  https://blog.csdn.net/zsy162534/article/details/52100878
//        https://blog.csdn.net/xyisv/article/details/78702806
//        https://blog.csdn.net/michellehsiao/article/details/8067667
//        https://blog.csdn.net/rosefun96/article/details/71405269
//        https://blog.csdn.net/anycodes/article/details/41087785
//        https://blog.csdn.net/ezhou_liukai/article/details/13779091
//        https://blog.csdn.net/u010510020/article/details/73799996

#include <iostream>
#include <cmath>
using namespace std;
int month_days[12]={31,28,31,30,31,30,31,31,30,31,30,31};  // 12个月里各有多少天   用大括号初始化。。
// 字符串转int
int string_to_int(string str,int start,int end){
    int count=0;
    int j=end-start;
    for(int i=start;i<=end;i++){    // 0 1 2 3
        // 3 2 1 0
        count += pow(10,j)*(str[i] -'0');   // 字符转数字
        j--;
    }
    return count;
}

// 判断是否闰年
bool if_Leap(string year){
    int count=0;
    count=string_to_int(year,0,3);
    if(((count % 4)==0 && (count % 100)!=0)||(count%400==0))
        return true;
    else
        return false;
}

//算其余月天数
int other_month_days(int month){
    int other_days=0;
    for(int i =month;i<12;i++){
        other_days+=month_days[i];
    }
    return other_days;
}


// 算总天数
int number_days(string year){
    int days=0;
    int i=year[5]-'0';
    if(year[4]=='0'){
        days=month_days[i-1]-string_to_int(year, 6, 7)+1;    // 算当月天数
        days+=other_month_days(i);      //算其余月天数
    }
    if(year[4]=='1'){
        
        days=month_days[i+10-1]-string_to_int(year, 6,7)+1;
        days+=other_month_days(i+10);      //算其余月天数
    }
    return days;
}

//20110203 - 20120831
int main(void){
    string date1,date2;
    int date1_days,date2_days,days=0;
    int year1,year2=0;
    
    int days1=365;
    cin>>date1>>date2;
    year1=string_to_int(date1, 0, 3);
    year2=string_to_int(date2, 0, 3);
    
    if(if_Leap(date1.substr(0,3))){         // substr string 截取
        month_days[1]=29;
        days1=366;
    }
    // 算从 date1 到年底的天数
    date1_days=number_days(date1);
    
    // 算从年初到 date2 的天数
    if(if_Leap(date2.substr(0,3))) {
        month_days[1]=29;
        date2_days=366-number_days(date2);
    }
    else {
        month_days[1]=28;
        date2_days=365-number_days(date2);
    }
    if(year1==year2){
        days=date2_days-(days1-date1_days)+1;
    }
    else{       // year 比 year1 大
        days=date1_days+date2_days;
        for(int i=year1;i<year2-1;i++){
            if(if_Leap(to_string(i+1))){
                days+=366;
            }
            else days+=365;
        }
    }
    cout<<days<<endl;
    return 0;
}
