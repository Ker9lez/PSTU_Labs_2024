#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct DoublyNode
{
    char value;
    DoublyNode* next;
    DoublyNode* previous;
};

struct DoublyLinkedList
{
    DoublyNode* first = nullptr;
    DoublyNode* last = nullptr;

    // Добавление элемента в начало списка
    void addToFront(char val)
    {
        DoublyNode* newNode = new DoublyNode;
        newNode->value = val;
        newNode->next = first;
        newNode->previous = nullptr;

        if (first != nullptr)
        {
            first->previous = newNode;
        }
        first = newNode;
        if (last == nullptr)
        {
            last = newNode;
        }
    }

    // Добавление элемента в конец списка
    void addToBack(char val)
    {
        DoublyNode* newNode = new DoublyNode;
        newNode->next = nullptr;
        newNode->value = val;

        if (first != nullptr)
        {
            newNode->previous = last;
            last->next = newNode;
            last = newNode;
        }
        else
        {
            newNode->previous = nullptr;
            first = last = newNode;
        }
    }

    // Вывод списка
    void display()
    {
        DoublyNode* current = first;
        while (current)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Получение узла по индексу
    DoublyNode* getNodeByIndex(int index)
    {
        DoublyNode* current = first;
        int counter = 0;

        while (counter != index)
        {
            if (current == nullptr)
                return current;
            current = current->next;
            counter++;
        }
        return current;
    }

    // Перегрузка оператора []
    DoublyNode* operator[](int index)
    {
        return getNodeByIndex(index);
    }

    // Получение размера списка
    int getSize()
    {
        int size = 0;
        DoublyNode* current = first;
        while (current != nullptr)
        {
            size++;
            current = current->next;
        }
        return size;
    }

    // Вставка элемента по индексу
    void insertAt(int index, char val)
    {
        if (index == 0)
        {
            addToFront(val);
        }
        else if (index == getSize())
        {
            addToBack(val);
        }
        else
        {
            DoublyNode* newNode = new DoublyNode();
            newNode->value = val;

            DoublyNode* current = first;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }

            newNode->next = current->next;
            newNode->previous = current;
            current->next->previous = newNode;
            current->next = newNode;
        }
    }

    // Удаление последнего элемента
    void removeFromBack()
    {
        if (last == nullptr) return;

        DoublyNode* temp = last->previous;
        if (temp != nullptr)
            temp->next = nullptr;
        else
            first = nullptr;

        delete last;
        last = temp;
    }

    // Удаление первого элемента
    void removeFromFront()
    {
        if (first == nullptr) return;

        DoublyNode* temp = first->next;
        if (temp != nullptr)
            temp->previous = nullptr;
        else
            last = nullptr;

        delete first;
        first = temp;
    }

    // Удаление элемента по индексу
    void removeAt(int index)
    {
        DoublyNode* nodeToRemove = getNodeByIndex(index);
        if (nodeToRemove == nullptr)
            return;

        if (nodeToRemove->previous == nullptr)
        {
            removeFromFront();
            return;
        }

        if (nodeToRemove->next == nullptr)
        {
            removeFromBack();
            return;
        }

        DoublyNode* leftNode = nodeToRemove->previous;
        DoublyNode* rightNode = nodeToRemove->next;
        leftNode->next = rightNode;
        rightNode->previous = leftNode;

        delete nodeToRemove;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    DoublyLinkedList myList;
    int elementCount;
    char inputValue;

    cout << "Введите количество элементов в списке: ";
    cin >> elementCount;

    if (elementCount >= 0)
    {
        for (int i = 0; i < elementCount; i++)
        {
            cout << "Введите " << i + 1 << " элемент: ";
            cin >> inputValue;
            myList.addToBack(inputValue);
        }
        myList.display();
    }

    int insertIndex;
    cout << "Введите индекс добавляемого элемента: ";
    cin >> insertIndex;
    cout << "Введите значение добавляемого элемента: ";
    cin >> inputValue;
    myList.insertAt(insertIndex, inputValue);
    myList.display();

    int removeIndex;
    cout << "Введите индекс удаляемого элемента: ";
    cin >> removeIndex;
    myList.removeAt(removeIndex);
    myList.display();

    return 0;
}