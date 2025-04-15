#include <iostream>
using namespace std;

struct ListNode
{
    char value;
    ListNode* nextNode;

    void initialize(char val)
    {
        value = val;
        nextNode = nullptr;
    }
};

struct LinkedList
{
    ListNode* firstNode = nullptr;
    ListNode* lastNode = nullptr;

    // Добавление элемента в конец списка
    void append(char val)
    {
        ListNode* newNode = new ListNode;
        newNode->initialize(val);
        if (firstNode == nullptr) firstNode = newNode;
        if (lastNode != nullptr) lastNode->nextNode = newNode;
        lastNode = newNode;
    }

    // Добавление элемента в начало списка
    void prepend(char val)
    {
        ListNode* newNode = new ListNode;
        newNode->initialize(val);
        newNode->nextNode = firstNode;
        firstNode = newNode;
        if (lastNode == nullptr) lastNode = newNode;
    }

    // Вставка элемента после указанной позиции
    void insertAt(int position, char val)
    {
        if (position < 0) return;
        if (position == 0)
        {
            prepend(val);
            return;
        }

        ListNode* newNode = new ListNode;
        newNode->initialize(val);

        ListNode* current = firstNode;
        for (int i = 0; i < position - 1 && current != nullptr; i++)
        {
            current = current->nextNode;
        }

        if (current == nullptr) return;

        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;

        if (current == lastNode) lastNode = newNode;
    }

    // Удаление первого элемента
    void removeFirst()
    {
        if (firstNode == nullptr) return;

        if (firstNode == lastNode)
        {
            delete firstNode;
            firstNode = lastNode = nullptr;
            return;
        }

        ListNode* temp = firstNode;
        firstNode = temp->nextNode;
        delete temp;
    }

    // Удаление последнего элемента
    void removeLast()
    {
        if (lastNode == nullptr) return;

        if (firstNode == lastNode)
        {
            delete lastNode;
            firstNode = lastNode = nullptr;
            return;
        }

        ListNode* current = firstNode;
        while (current->nextNode != lastNode)
        {
            current = current->nextNode;
        }

        current->nextNode = nullptr;
        delete lastNode;
        lastNode = current;
    }

    // Получение элемента по индексу
    ListNode* getNode(int position)
    {
        if (position < 0) return nullptr;

        ListNode* current = firstNode;
        int counter = 0;

        while (current != nullptr && counter < position)
        {
            current = current->nextNode;
            counter++;
        }

        return (counter == position) ? current : nullptr;
    }

    // Удаление элемента по индексу
    void removeAt(int position, char val)
    {
        if (position < 0) return;

        if (position == 0)
        {
            prepend(val);
            return;
        }

        ListNode* prevNode = getNode(position - 1);
        if (prevNode == nullptr || prevNode->nextNode == nullptr) return;

        ListNode* nodeToDelete = prevNode->nextNode;
        prevNode->nextNode = nodeToDelete->nextNode;

        if (nodeToDelete == lastNode)
        {
            lastNode = prevNode;
        }

        delete nodeToDelete;
    }

    // Вывод списка
    void printList()
    {
        for (ListNode* current = firstNode; current != nullptr; current = current->nextNode)
        {
            cout << current->value << ' ';
        }
        cout << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    LinkedList myList;
    char inputChar;
    int elementsCount;

    cout << "Введите количество элементов в списке: ";
    cin >> elementsCount;

    for (int i = 0; i < elementsCount; i++)
    {
        cout << "Введите " << i + 1 << " элемент: ";
        cin >> inputChar;
        myList.append(inputChar);
    }

    cout << "\nСозданный список: ";
    myList.printList();

    int insertPosition;
    char newValue;

    cout << "\nВведите позицию для вставки нового элемента: ";
    cin >> insertPosition;
    cout << "Введите значение нового элемента: ";
    cin >> newValue;

    myList.insertAt(insertPosition, newValue);
    cout << "Список после вставки: ";
    myList.printList();

    int deletePosition;
    char dummyValue; // Не используется, но требуется для вызова removeAt

    cout << "\nВведите позицию элемента для удаления: ";
    cin >> deletePosition;
    cout << "Введите любое значение (не используется): ";
    cin >> dummyValue;

    myList.removeAt(deletePosition, dummyValue);
    cout << "Список после удаления: ";
    myList.printList();

    return 0;
}