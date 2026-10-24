
#pragma once

const int STACK_CAPACITY = 1000;

template <typename T>
class Stack {
private:
    T items[STACK_CAPACITY];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool push(const T& value) {
        if (topIndex == STACK_CAPACITY - 1) {
            return false;
        }

        topIndex++;
        items[topIndex] = value;

        return true;
    }

    bool pop() {
        if (isEmpty()) {
            return false;
        }

        topIndex--;
        return true;
    }

    bool peek(T& result) const {
        if (isEmpty()) {
            return false;
        }

        result = items[topIndex];
        return true;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    int size() const {
        return topIndex + 1;
    }
};
