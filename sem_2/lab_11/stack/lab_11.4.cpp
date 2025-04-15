#include <iostream>
using namespace std;

struct StackNode {
    char value;
    StackNode* next;
};

struct CharStack {
    StackNode* top = nullptr;
    int elementCount = 0;

    // Добавление элемента в стек
    void push(char newValue) {
        StackNode* newNode = new StackNode;
        newNode->value = newValue;
        newNode->next = top;
        top = newNode;
        elementCount++;
    }

    // Удаление верхнего элемента
    void pop() {
        if (top != nullptr) {
            StackNode* temp = top;
            top = top->next;
            delete temp;
            elementCount--;
        }
    }

    // Вставка элемента перед указанным значением
    void insertBefore(char searchValue, char newValue) {
        StackNode* newNode = new StackNode;
        newNode->value = newValue;
        newNode->next = nullptr;

        if (top == nullptr) {
            cout << "Стек пуст, вставка невозможна." << endl;
            delete newNode;
            return;
        }

        if (top->value == searchValue) {
            newNode->next = top;
            top = newNode;
            elementCount++;
            return;
        }

        StackNode* current = top;
        while (current->next != nullptr && current->next->value != searchValue) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Значение " << searchValue << " не найдено в стеке." << endl;
            delete newNode;
        }
        else {
            newNode->next = current->next;
            current->next = newNode;
            elementCount++;
        }
    }

    // Удаление элемента по значению
    void removeByValue(char valueToRemove) {
        StackNode* current = top;
        StackNode* previous = nullptr;

        while (current != nullptr) {
            if (current->value == valueToRemove) {
                if (previous == nullptr) {
                    top = current->next;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                elementCount--;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Элемент со значением " << valueToRemove << " не найден." << endl;
    }

    // Вывод стека
    void display() {
        StackNode* current = top;
        cout << "Содержимое стека (сверху вниз): ";
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Очистка стека
    ~CharStack() {
        while (top != nullptr) {
            pop();
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    CharStack myStack;
    int numElements;
    char inputValue;

    cout << "Введите количество элементов для добавления в стек: ";
    cin >> numElements;

    for (int i = 1; i <= numElements; i++) {
        cout << "Введите элемент №" << i << ": ";
        cin >> inputValue;
        myStack.push(inputValue);
    }

    myStack.display();

    char searchValue, newValue;
    cout << "Введите значение, перед которым нужно вставить новый элемент: ";
    cin >> searchValue;
    cout << "Введите значение нового элемента: ";
    cin >> newValue;
    myStack.insertBefore(searchValue, newValue);
    myStack.display();

    char valueToRemove;
    cout << "Введите значение элемента для удаления: ";
    cin >> valueToRemove;
    myStack.removeByValue(valueToRemove);
    myStack.display();

    return 0;
}