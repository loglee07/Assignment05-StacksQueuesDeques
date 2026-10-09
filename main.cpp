#include <iostream>
#include <string>

// array stack

class ArrayStack {
private:
    static const int CAPACITY = 10;
    int values[CAPACITY];
    int topIndex;

public:
    ArrayStack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == CAPACITY - 1;
    }

    bool push(int value) {
        if (isFull()) {
            return false;
        }

        topIndex++;
        values[topIndex] = value;
        return true;
    }

    bool pop(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        removedValue = values[topIndex];
        topIndex--;
        return true;
    }

    void print() {
        std::cout << "Top -> ";

        if (isEmpty()) {
            std::cout << "[empty] ";
        } else {
            for (int i = topIndex; i >= 0; i--) {
                std::cout << values[i] << ' ';
            }
        }

        std::cout << '\n';
    }
};

// linked stack

class LinkedStack {
private:
    struct Node {
        int value;
        Node* next;

        Node(int nodeValue) {
            value = nodeValue;
            next = nullptr;
        }
    };

    Node* topNode;

public:
    LinkedStack() {
        topNode = nullptr;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    bool pop(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        Node* oldTop = topNode;
        removedValue = oldTop->value;
        topNode = topNode->next;
        delete oldTop;
        return true;
    }

    void print() {
        std::cout << "Top -> ";

        if (isEmpty()) {
            std::cout << "[empty] ";
        } else {
            Node* current = topNode;

            while (current != nullptr) {
                std::cout << current->value << ' ';
                current = current->next;
            }
        }

        std::cout << '\n';
    }

    ~LinkedStack() {
        int removedValue;

        while (pop(removedValue)) {
        }
    }
};

// array queue

class ArrayQueue {
private:
    static const int CAPACITY = 10;
    int values[CAPACITY];
    int frontIndex;
    int rearIndex;
    int count;

public:
    ArrayQueue() {
        frontIndex = 0;
        rearIndex = 0;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == CAPACITY;
    }

    bool enqueue(int value) {
        if (isFull()) {
            return false;
        }

        values[rearIndex] = value;
        rearIndex = (rearIndex + 1) % CAPACITY;
        count++;
        return true;
    }

    bool dequeue(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        removedValue = values[frontIndex];
        frontIndex = (frontIndex + 1) % CAPACITY;
        count--;
        return true;
    }

    void print() {
        std::cout << "Front -> ";

        if (isEmpty()) {
            std::cout << "[empty] ";
        } else {
            for (int i = 0; i < count; i++) {
                int index = (frontIndex + i) % CAPACITY;
                std::cout << values[index] << ' ';
            }
        }

        std::cout << "<- Rear\n";
    }
};

// linked queue

class LinkedQueue {
private:
    struct Node {
        int value;
        Node* next;

        Node(int nodeValue) {
            value = nodeValue;
            next = nullptr;
        }
    };

    Node* frontNode;
    Node* rearNode;

public:
    LinkedQueue() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            frontNode = newNode;
            rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    bool dequeue(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        Node* oldFront = frontNode;
        removedValue = oldFront->value;
        frontNode = frontNode->next;

        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete oldFront;
        return true;
    }

    void print() {
        std::cout << "Front -> ";

        if (isEmpty()) {
            std::cout << "[empty] ";
        } else {
            Node* current = frontNode;

            while (current != nullptr) {
                std::cout << current->value << ' ';
                current = current->next;
            }
        }

        std::cout << "<- Rear\n";
    }

    ~LinkedQueue() {
        int removedValue;

        while (dequeue(removedValue)) {
        }
    }
};

// array deque

class ArrayDeque {
private:
    static const int CAPACITY = 10;
    int values[CAPACITY];
    int frontIndex;
    int count;

public:
    ArrayDeque() {
        frontIndex = 0;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == CAPACITY;
    }

    bool pushFront(int value) {
        if (isFull()) {
            return false;
        }

        frontIndex =
            (frontIndex - 1 + CAPACITY) % CAPACITY;

        values[frontIndex] = value;
        count++;
        return true;
    }

    bool pushBack(int value) {
        if (isFull()) {
            return false;
        }

        int backIndex =
            (frontIndex + count) % CAPACITY;

        values[backIndex] = value;
        count++;
        return true;
    }

    bool popFront(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        removedValue = values[frontIndex];

        frontIndex =
            (frontIndex + 1) % CAPACITY;

        count--;
        return true;
    }

    bool popBack(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        int backIndex =
            (frontIndex + count - 1) % CAPACITY;

        removedValue = values[backIndex];
        count--;
        return true;
    }

    void print() {
        std::cout << "Front -> ";

        if (isEmpty()) {
            std::cout << "[empty] ";
        } else {
            for (int i = 0; i < count; i++) {
                int index =
                    (frontIndex + i) % CAPACITY;

                std::cout << values[index] << ' ';
            }
        }

        std::cout << "<- Back\n";
    }
};

// linked deque

class LinkedDeque {
private:
    struct Node {
        int value;
        Node* previous;
        Node* next;

        Node(int nodeValue) {
            value = nodeValue;
            previous = nullptr;
            next = nullptr;
        }
    };

    Node* frontNode;
    Node* backNode;

public:
    LinkedDeque() {
        frontNode = nullptr;
        backNode = nullptr;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }

    void pushFront(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            frontNode = newNode;
            backNode = newNode;
        } else {
            newNode->next = frontNode;
            frontNode->previous = newNode;
            frontNode = newNode;
        }
    }

    void pushBack(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            frontNode = newNode;
            backNode = newNode;
        } else {
            newNode->previous = backNode;
            backNode->next = newNode;
            backNode = newNode;
        }
    }

    bool popFront(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        Node* oldFront = frontNode;
        removedValue = oldFront->value;
        frontNode = frontNode->next;

        if (frontNode == nullptr) {
            backNode = nullptr;
        } else {
            frontNode->previous = nullptr;
        }

        delete oldFront;
        return true;
    }

    bool popBack(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        Node* oldBack = backNode;
        removedValue = oldBack->value;
        backNode = backNode->previous;

        if (backNode == nullptr) {
            frontNode = nullptr;
        } else {
            backNode->next = nullptr;
        }

        delete oldBack;
        return true;
    }

    void print() {
        std::cout << "Front -> ";

        if (isEmpty()) {
            std::cout << "[empty] ";
        } else {
            Node* current = frontNode;

            while (current != nullptr) {
                std::cout << current->value << ' ';
                current = current->next;
            }
        }

        std::cout << "<- Back\n";
    }

    ~LinkedDeque() {
        int removedValue;

        while (popFront(removedValue)) {
        }
    }
};

// test helpers

void showEmptyResult(
    const std::string& operation,
    bool success) {

    std::cout << operation << ": "
              << (success
                      ? "unexpected success"
                      : "empty handled correctly")
              << '\n';
}

// test functions
void testArrayStack() {
    std::cout << "\n===== ARRAY STACK =====\n";

    ArrayStack stack;
    int removedValue = 0;

    showEmptyResult(
        "1. Pop",
        stack.pop(removedValue));

    stack.push(10);              // 2
    stack.push(20);              // 3
    stack.push(30);              // 4
    stack.print();

    stack.pop(removedValue);     // 5
    std::cout << "5. Popped: "
              << removedValue << '\n';

    stack.push(40);              // 6
    stack.print();

    stack.pop(removedValue);     // 7
    stack.pop(removedValue);     // 8
    stack.pop(removedValue);     // 9

    showEmptyResult(
        "10. Pop",
        stack.pop(removedValue));

    stack.print();
}

void testLinkedStack() {
    std::cout << "\n===== LINKED STACK =====\n";

    LinkedStack stack;
    int removedValue = 0;

    showEmptyResult(
        "1. Pop",
        stack.pop(removedValue));

    stack.push(100);             // 2
    stack.push(200);             // 3
    stack.push(300);             // 4
    stack.print();

    stack.pop(removedValue);     // 5
    std::cout << "5. Popped: "
              << removedValue << '\n';

    stack.push(400);             // 6
    stack.print();

    stack.pop(removedValue);     // 7
    stack.pop(removedValue);     // 8
    stack.pop(removedValue);     // 9

    showEmptyResult(
        "10. Pop",
        stack.pop(removedValue));

    stack.print();
}

void testArrayQueue() {
    std::cout << "\n===== ARRAY QUEUE =====\n";

    ArrayQueue queue;
    int removedValue = 0;

    showEmptyResult(
        "1. Dequeue",
        queue.dequeue(removedValue));

    queue.enqueue(10);               // 2
    queue.enqueue(20);               // 3
    queue.enqueue(30);               // 4
    queue.print();

    queue.dequeue(removedValue);     // 5
    std::cout << "5. Dequeued: "
              << removedValue << '\n';

    queue.enqueue(40);               // 6
    queue.print();

    queue.dequeue(removedValue);     // 7
    queue.dequeue(removedValue);     // 8
    queue.dequeue(removedValue);     // 9

    showEmptyResult(
        "10. Dequeue",
        queue.dequeue(removedValue));

    queue.print();
}

void testLinkedQueue() {
    std::cout << "\n===== LINKED QUEUE =====\n";

    LinkedQueue queue;
    int removedValue = 0;

    showEmptyResult(
        "1. Dequeue",
        queue.dequeue(removedValue));

    queue.enqueue(100);              // 2
    queue.enqueue(200);              // 3
    queue.enqueue(300);              // 4
    queue.print();

    queue.dequeue(removedValue);     // 5
    std::cout << "5. Dequeued: "
              << removedValue << '\n';

    queue.enqueue(400);              // 6
    queue.print();

    queue.dequeue(removedValue);     // 7
    queue.dequeue(removedValue);     // 8
    queue.dequeue(removedValue);     // 9

    showEmptyResult(
        "10. Dequeue",
        queue.dequeue(removedValue));

    queue.print();
}

void testArrayDeque() {
    std::cout << "\n===== ARRAY DEQUE =====\n";

    ArrayDeque deque;
    int removedValue = 0;

    showEmptyResult(
        "1. Pop front",
        deque.popFront(removedValue));

    deque.pushBack(10);               // 2
    deque.pushFront(5);               // 3
    deque.pushBack(20);               // 4
    deque.print();

    deque.popFront(removedValue);      // 5
    std::cout << "5. Popped front: "
              << removedValue << '\n';

    deque.pushFront(1);                // 6
    deque.print();

    deque.popBack(removedValue);       // 7
    deque.popFront(removedValue);      // 8
    deque.popBack(removedValue);       // 9

    showEmptyResult(
        "10. Pop back",
        deque.popBack(removedValue));

    deque.print();
}

void testLinkedDeque() {
    std::cout << "\n===== LINKED DEQUE =====\n";

    LinkedDeque deque;
    int removedValue = 0;

    showEmptyResult(
        "1. Pop front",
        deque.popFront(removedValue));

    deque.pushBack(100);               // 2
    deque.pushFront(50);               // 3
    deque.pushBack(200);               // 4
    deque.print();

    deque.popFront(removedValue);      // 5
    std::cout << "5. Popped front: "
              << removedValue << '\n';

    deque.pushFront(10);               // 6
    deque.print();

    deque.popBack(removedValue);       // 7
    deque.popFront(removedValue);      // 8
    deque.popBack(removedValue);       // 9

    showEmptyResult(
        "10. Pop back",
        deque.popBack(removedValue));

    deque.print();
}

int main() {
    testArrayStack();
    testLinkedStack();
    testArrayQueue();
    testLinkedQueue();
    testArrayDeque();
    testLinkedDeque();

    return 0;
}