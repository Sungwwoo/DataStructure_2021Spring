#pragma once

template <class ItemType>
struct HeapType{
    void ReheapDown(int root, int bottom);  // Used by DeleteItem
    void ReheapUp(int root, int bottom);    // Used by InsertItem

    ItemType* elements; // Heap using array
    int numElements;
};

template <class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom){  // root부터 child에 더 큰 값이 있으면 바꾸면서 내려감
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;

    if (leftChild <= bottom){
        if (leftChild == bottom)    // root has single child
            maxChild = leftChild;
        else{
            if (elements[leftChild] <= elements[rightChild])    // maxChild를 두 child 중 큰 것으로 초기화
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }

        if (elements[root] < elements[maxChild]){               // subtree의 root가 maxChild보다 작으면 서로 바꾸고 바꾼 subtree 확인
            Swap(elements[root], elements[maxChild]);
            ReheapDown(maxChild, bottom);
        }
    }
}

template <class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom){    // bottom부터 root로 올라가면서 Heap으로 정렬
    int parent;

    if (bottom > root){  // tree is not empty
        parent = (bottom - 1) / 2;
        if (elements[parent] < elements[bottom]){
            Swap(elements[parent], elements[bottom]);
            ReheapUp(root, parent);
        }
    }
}