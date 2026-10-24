
#pragma once

const int QUEUE_CAPACITY = 1000;

template <typename T>
class Queue {
private:
    T items[QUEUE_CAPACITY];
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue() {
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool enqueue(const T& value) {
        if (count == QUEUE_CAPACITY) {
            return false;
        }

        rearIndex = (rearIndex + 1) % QUEUE_CAPACITY;
        items[rearIndex] = value;
        count++;

        return true;
    }

    bool dequeue() {
        if (isEmpty()) {
            return false;
        }

        frontIndex = (frontIndex + 1) % QUEUE_CAPACITY;
        count--;

        return true;
    }

    bool peek(T& result) const {
        if (isEmpty()) {
            return false;
        }

        result = items[frontIndex];
        return true;
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }
};
