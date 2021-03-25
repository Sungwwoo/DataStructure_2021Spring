#pragma once

const int MAX_ITEMS = 200;
class FullStack
// Exception class thrown by Push when stack is full.
{};

class DoubleStack{
private:
    int top_small;
    int top_big;
    int items[MAX_ITEMS];
public:
    DoubleStack();
    void Push(int item);
    void Print();
    bool IsFull() const;
};