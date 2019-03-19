//
//  22.cpp
//  今年暑假不AC
//
//  Created by chenmeiqi on 2019/3/5.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

// 第一个节目我们应该选什么?
// 选择开始时间最早的?
// 假如有电视节目 A[0,5]，B[1,2]，C[3,4]。显然，选择最先开始的节目并不一定能够得到最优解。
// 选择持续时间最短的?
// 假如电视节目是这样安排的 A[0,10]，B[11,20]，C[9,12]。显然，选择时间最短的节目也并不一定能够得到最优解。
// 那么选择结束时间最早的? 这在以上两组案例中优先选择结束时间最早的节目是可以得到最优解的。
// 那么它是否就真的是我们所需要的贪心策略?我们可以试着先来证明该命题:最优解中，第一个观看的节目一定是所有节目里结束时间最早的节目。因为按照优先选择结束时间最早的节目，我们所观看的第一个节目一定是所有节目里结束时间最早的。

#include <iostream>
using namespace std;

struct timeTable{
    int beginTime;
    int endTime;
    int lastTime;
    bool operator < (const timeTable& a) const{
        return endTime<a.endTime;
    }
}timeTable[100];

int main(int argc, const char * argv[]) {
    int n=0;
    while(cin>>n){
        if(n==0) break;
        int i=0;
        int n_count=n;
        int endtime=0;
        int program_count=0;
        while (n_count--) {
            cin>>timeTable[i].beginTime>>timeTable[i].endTime;
            timeTable[i].lastTime=timeTable[i].endTime-timeTable[i].beginTime;
            i++;
        }
        
        sort(timeTable, timeTable+n);// 按照结束时间升序排列
        
        for(int j=0;j<n;j++){
            if (timeTable[j].beginTime>=endtime) {  // 若当前时间小于等于该节目开始时间,那么收看该在剩余节目里结束时间最早的节目
                program_count++;
                endtime=timeTable[j].endTime;   // 当前时间变为该节目结束时间
            }
        }
        
        cout << program_count<<endl;
    }
    return 0;
}
