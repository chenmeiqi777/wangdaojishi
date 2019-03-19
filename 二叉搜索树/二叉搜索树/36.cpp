//
//  36.cpp
//  二叉搜索树（又：二叉排序树，二叉查找树，Binary Search Tree）
//
//  Created by chenmeiqi on 2019/3/18.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node{
    Node* lchild;
    Node* rchild;
    char data;
}Tree[10];

int idx;

Node* create(){
    Tree[idx].lchild=Tree[idx].rchild=NULL;
    return &Tree[idx++];
}

Node* Insert(Node* T,char c){           // 递归插入
    if(T==NULL){
        T=create();
        T->data=c;
        return T;
    }
    else{
        if(c>T->data){
            T->rchild=Insert(T->rchild, c);
        }
        else{
            T->lchild=Insert(T->lchild, c);
        }
    }
    return T;
}

Node* build(string s){              // 构造二叉排序树
    Node* T=NULL;
    for(int j=0;j<s.length();j++){
        T=Insert(T, s[j]);
    }
    return T;
}

string pre_s="";
string in_s="";

string PreOrder(Node * T){          // 前序遍历
    pre_s+=T->data;
    if(T->lchild!=NULL){
        PreOrder(T->lchild);
    }
    if(T->rchild!=NULL){
        PreOrder(T->rchild);
    }
    return pre_s;
}

string InOrder(Node * T){           // 中序遍历
    if(T->lchild!=NULL){
        InOrder(T->lchild);
    }
    in_s+=T->data;
    if(T->rchild!=NULL){
        InOrder(T->rchild);
    }
    return in_s;
}

int main(int argc, const char * argv[]) {
    int n;
    string seq;         // 待比较序列
    string comp;        // 比较序列
    
    cin>>n;
    cin>>seq;
    idx=0;
    
    build(seq);
    string seq_pre= PreOrder(&Tree[0]);         // 待比较序列的前序遍历
    string seq_in=InOrder(&Tree[0]);            // 待比较序列的中序遍历
    while(n--){
        for (int i=0; i<10; i++) {          // 清空数组（初始化）
            Tree[i].data='\0';
            Tree[i].lchild=Tree[i].rchild=NULL;
        }
        idx=0;                  // 序号归0
        pre_s=in_s="";          // 比较序列归零
        cin>>comp;
        build(comp);            // 构建比较序列的二叉排序树
        if(PreOrder(&Tree[0])==seq_pre&&InOrder(&Tree[0])==seq_in){         // 前序遍历、中序遍历相等
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
