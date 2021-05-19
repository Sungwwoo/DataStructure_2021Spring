#pragma once
#include <new>
#include <iostream>
#include "QueType.h"
template <class ItemType>
struct TreeNode;

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

template <class ItemType>
class TreeType{
public:
    TreeType();
    ~TreeType();
    TreeType(const TreeType<ItemType>& originalTree);
    void operator=(const TreeType<ItemType>& originalTree);
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    int LenghIs() const;
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType newItem);
    void DeleteItem(ItemType item);
    void ResetTree(OrderType order);
    void GetNextItem(ItemType& item, OrderType order, bool&);
    void PrintTree() const;

private:
    TreeNode<ItemType>* root;
    QueType<ItemType> preQue;
    QueType<ItemType> inQue;
    QueType<ItemType> postQue;
};

template <class ItemType>
struct TreeNode{
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

template <class ItemType>
int CountNodes(TreeNode<ItemType>* tree){
    if (tree == NULL)
        return 0;
    else
        return CountNode(tree->left) + CountNode(tree->right) + 1;
}

template <class ItemType>
TreeType<ItemType>::TreeType(){
    root = NULL;
}

template <class ItemType>
void Destroy(TreeNode<ItemType>*& tree){
    if (tree != NULL){
        // POST ORDER
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}

template <class ItemType>
TreeType<ItemType>::~TreeType(){
    Destroy(root);
}

template <class ItemType>
void CopyTree(TreeType<ItemType>*& copy, const TreeNode<ItemType>* original){
    if (original == NULL)
        copy = NULL;
    else{
        copy = new TreeNode<ItemType>;
        // PRE ORDER
        copy->info = original->info;
        CopyTree(copy->left, original->left);
        CopyTree(copy->right, original->right);
    }
}

template <class ItemType>
TreeType<ItemType>::TreeType(const TreeType<ItemType>& originalTree){
    CopyTree(root, originalTree.root);
}

template <class ItemType>
void TreeType<ItemType>::operator=(const TreeType<ItemType>& originalTree){
    if (&originalTree == this)
        return;
    Destroy(root);
    CopyTree(root, originalTree.root);
}

template <class ItemType>
void TreeType<ItemType>::MakeEmpty(){
    Destroy(root);
    root = NULL;
}

template <class ItemType>
bool TreeType<ItemType>::IsEmpty() const{
    return root == NULL;
}

template <class ItemType>
bool TreeType<ItemType>::IsFull() const{
    TreeNode<ItemType>* location;
    try{
        location = new TreeNode<ItemType>;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception){
        return true;
    }
}

template <class ItemType>
int TreeType<ItemType>::LenghIs() const{
    return CountNodes(root);
}

template <class ItemType>
void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found){
    if (tree == NULL)   // no item
        found = false;
    else if (item < tree->info)
        Retrieve(tree->left, item, found);
    else if (item > tree->info)
        Retrieve(tree->right, item, found);
    else{   // item found
        item = tree->info;
        found = true;
    }
}

template <class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found){
    Retrieve(item, found);
}

template <class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item){
    if (tree == NULL){
        tree = new TreeNode<ItemType>;
        tree->info = item;
        tree->right = NULL;
        tree->left = NULL;
    }
    else if (item < tree->info)
        Insert(tree->left, item);
    else
        Insert(tree->right, item);
}

template <class ItemType>
void TreeType<ItemType>::InsertItem(ItemType newItem){
    Insert(root, newItem);
}

template <class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data){
    while (tree->right != NULL)
        tree = tree->right;
    data = tree->info;
}

template <class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree){
    ItemType data;
    TreeNode<ItemType>* tempLoc;
    tempLoc = tree;
    // right child만 있으면 그대로 연결
    if (tree->left == NULL){
        tree = tree->right;
        delete tempLoc;
    }
    // left child만 있으면 그대로 연결
    else if (tree->right == NULL){
        tree = tree->left;
        delete tempLoc;
    }
    else{// child 두개이면 트리에서 가장 큰 값과 위치 바꾸고 바꾼 위치에서 다시 삭제 반복
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data);
    }
}

template <class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item){
    // 삭제할 item 찾음
    if (item < tree->info)
        Delete(tree->left, item);
    else if (item > tree->info)
        Delete(tree->right, item);
    // 찾으면 삭제
    else
        DeleteNode(tree);
}

template <class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item){
    Delete(root, item);
}

template <class ItemType>
void PreOrder(TreeNode<ItemType>* tree, QueType<ItemType>* preQue){
    if (tree != NULL){
        preQue.Enqueue(tree->info);
        PreOrder(tree->left, preQue);
        PreOrder(tree->right, preQue);
    }
}

template <class ItemType>
void InOrder(TreeNode<ItemType>* tree, QueType<ItemType>* inQue){
    if (tree != NULL){
        InOrder(tree->left, inQue);
        inQue.Enqueue(tree->info);
        InOrder(tree->right, inQue);
    }
}

template <class ItemType>
void PostOrder(TreeNode<ItemType>* tree, QueType<ItemType>* postQue){
    if (tree != NULL){
        PostOrder(tree->left, postQue);
        PostOrder(tree->left, postQue);
        postQue->Enqueue(tree->info);
    }
}

template <class ItemType>
void TreeType<ItemType>::ResetTree(OrderType order){
    switch (order){
    case PRE_ORDER: PreOrder(root, preQue);
        break;
    case IN_ORDER: InOrder(root, inQue);
        break;
    case POST_ORDER: PostOrder(root, postQue);
        break;
    }
}

template <class ItemType>
void TreeType<ItemType>::GetNextItem(ItemType& item, OrderType order, bool& finished){
    finished = false;
    switch (order){
    case PRE_ORDER: 
        preQue.Dequeue(item);
        if (preQue.IsEmpty())
            finished = true;
        break;
    case IN_ORDER: 
        inQue.Dequeue(item);
        if (inQue.IsEmpty())
            finished = true;
        break;
    case POST_ORDER: 
        postQue.Dequeue(item);
        if (postQue.IsEmpty())
            finished = true;
        break;
    }
}

template <class ItemType>
void Print(TreeNode<ItemType>* tree){
    // IN ORDER -> left subtree, 자기 자신, right subtree 순으로 접근
    if (tree != NULL){
        PrintTree(tree->left);
        std::cout << tree->info << " ";
        PrintTree(tree->right);
    }
}

template <class ItemType>
void TreeType<ItemType>::PrintTree() const{
    PrintTree(root);
    std::cout << std::endl;
}