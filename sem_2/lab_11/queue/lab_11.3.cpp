#include <iostream>
using namespace std;

struct QueueNode {
    char value;
    QueueNode* next;
};

struct CharQueue {
    int count;
    QueueNode* front;
    QueueNode* rear;

    void initialize(CharQueue& queue, char initialValue) {
        QueueNode* newNode = new QueueNode;
        newNode->value = initialValue;
        newNode->next = nullptr;
        queue.front = newNode;
        queue.rear = newNode;
        queue.count = 1;
    }

    void enqueue(CharQueue& queue, char newValue) {
        QueueNode* newNode = new QueueNode{ newValue, nullptr };
        queue.rear->next = newNode;
        queue.rear = newNode;
        queue.count++;
    }

    void dequeue(CharQueue& queue) {
        if (queue.front != nullptr) {
            QueueNode* temp = queue.front;
            queue.front = queue.front->next;
            delete temp;
            queue.count--;
        }
    }

    void removeValue(CharQueue& queue, char valueToRemove) {
        int initialCount = queue.count;
        for (int i = 1; i <= initialCount; i++) {
            if (queue.front->value == valueToRemove) {
                dequeue(queue);
            }
            else {
                enqueue(queue, queue.front->value);
                dequeue(queue);
            }
        }
    }

    void insertAtPosition(CharQueue& queue, int elementsToAdd, int position) {
        // Перемещаем элементы до позиции вставки
        for (int i = 1; i < position; i++) {
            enqueue(queue, queue.front->value);
            dequeue(queue);
        }

        // Добавляем новые элементы
        char inputValue;
        for (int i = 1; i <= elementsToAdd; i++) {
            cout << "Введите элемент для вставки: ";
            cin >> inputValue;
            enqueue(queue, inputValue);
        }

        // Перемещаем оставшиеся элементы
        int remainingElements = queue.count - position - elementsToAdd;
        for (int i = position; i <= remainingElements; i++) {
            enqueue(queue, queue.front->value);
            dequeue(queue);
        }
    }

    void createQueue(CharQueue& queue, int elementCount) {
        char inputValue;
        cout << "Введите элемент №1: ";
        cin >> inputValue;
        initialize(queue, inputValue);

        for (int i = 2; i <= elementCount; i++) {
            cout << "Введите элемент №" << i << ": ";
            cin >> inputValue;
            enqueue(queue, inputValue);
        }
    }

    void clearQueue(CharQueue& queue) {
        while (queue.front->next != nullptr) {
            dequeue(queue);
        }
        QueueNode* temp = queue.front;
        queue.front = nullptr;
        queue.count--;
        delete temp;
    }

    void displayQueue(const CharQueue& queue) {
        cout << "Начало очереди" << endl;
        QueueNode* current = queue.front;
        while (current != nullptr) {
            cout << current->value;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl << "Конец очереди" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    CharQueue queue;
    int elementCount;

    cout << "Введите количество элементов в очереди: ";
    cin >> elementCount;
    queue.createQueue(queue, elementCount);

    cout << endl;
    queue.displayQueue(queue);

    int insertPosition, elementsToAdd;
    cout << "Введите позицию для вставки: ";
    cin >> insertPosition;
    cout << "Введите количество элементов для добавления: ";
    cin >> elementsToAdd;

    queue.insertAtPosition(queue, elementsToAdd, insertPosition);
    queue.displayQueue(queue);

    char valueToRemove;
    cout << "Введите значение для удаления: ";
    cin >> valueToRemove;
    queue.removeValue(queue, valueToRemove);
    queue.displayQueue(queue);

    return 0;
}