//
//  35.cpp
//  二叉排序树
//
//  Created by chenmeiqi on 2019/3/18.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

/*
二叉排序树是一棵特殊的二叉树，它是一棵二叉树但同时满足如下条件:对于树上任意一个结点，
其上的数值必大于等于其左子树上任意结点数值，必小于等于其右子树上任意结点的数值。
若对二叉排序树进行中序遍历，那么其遍历结果必然是 一个递增序列，这也是二叉排序树名字的来由，
通过建立二叉排序树就能对原无 序序列进行排序，并实现动态维护。
 */

#include <iostream>
using namespace std;

struct Node{
    Node *leftChild;
    Node *rightChild;
    int data;
}Tree[100];

int idx;
Node* create(){
    Tree[idx].leftChild=Tree[idx].rightChild=NULL;
    return &Tree[idx++];
}

void PreSort(Node* node){  // 前序遍历
    cout<<node->data<<" ";
    if(node->leftChild!=NULL) PreSort(node->leftChild);
    if(node->rightChild!=NULL) PreSort(node->rightChild);
}

void InSort(Node * node){   // 中序遍历
    if(node->leftChild!=NULL)InSort(node->leftChild);
    cout<<node->data<<" ";
    if(node->rightChild!=NULL)InSort(node->rightChild);
}

void PostSort(Node * node){   // 后序遍历
    if(node->leftChild!=NULL)PostSort(node->leftChild);
    if(node->rightChild!=NULL)PostSort(node->rightChild);
     cout<<node->data<<" ";
}

int main(int argc, const char * argv[]) {
    int n;  // 整数个数

    cin>>n;
    idx=0;
    int n_count=n;          // 保存 n 的c值
    int index=0;
    while (n_count--) {
        Node* node=create();
        cin>>node->data;
        Node* parent=&Tree[0];
        if(index!=0){
            int n_count1=n;             // 每次循环比较前初始化！！
            while(n_count1--){
                Node* temp;
                if(parent!=NULL&&node->data<parent->data) {        // 新加结点值比当前结点值小
                    temp=parent;                                    // 用一个临时指针保存当前结点值
                    parent=parent->leftChild;                       // 当前结点更换为其左孩子
                }
                else if(parent!=NULL&&node->data>parent->data) {
                   temp=parent;
                   parent=parent->rightChild;
                }
                if(parent==NULL){                           // 更换后为空（说明其没有左孩子或没有右孩子）
                    if(temp->data>node->data){             // 更换前的值大于新加结点值
                        temp->leftChild=node;               // 新加结点变为左孩子
                        break;
                    }
                   else{
                        temp->rightChild=node;
                        break;
                    }
                }
            }
        }
        index++;
    }
 
    PreSort(&Tree[0]);
    cout<<endl;
    InSort(&Tree[0]);
    cout<<endl;
    PostSort(&Tree[0]);
    cout<<endl;
    return 0;
}
