#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Node
{
private:
    string data;
    Node* next;
    Node* prev;

    friend class DoublyLinkedList;

public:
    Node() : next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;

    friend class HashTable;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() {}
    void push(const string&);
    void insertAfter(Node*, const string&);
    void append(const string&);
    void delNode(Node*);
    Node* searchNode(const string&);
    void printNode();
};

class HashTable
{
private:
    int bucket;
    DoublyLinkedList** table;

public:
    HashTable() {}
    HashTable(int);
    ~HashTable() {}
    int hashFunc(const string&);
    void insItem(const string&);
    void searchItem(const string&);
    void delItem(const string&);
};

int convertASCII(const string&);
string getFirstName(const string&);

int main()
{
    DoublyLinkedList* list = new DoublyLinkedList();
    list->push("Josh Winston");
    list->push("Dave Smith");
    list->push("Jennifer Rockyou");

    list->printNode();

    Node* result = list->searchNode("Dave");
    list->delNode(result);

    list->printNode();

    cout << endl;

    system("pause");
    return 0;
}

int convertASCII(const string& key)
{
    int result = 0;

    for (int i = 0; i < (int)key.length(); i++)
    {
        result += key[i];
    }

    return result;
}

string getFirstName(const string& name)
{
    size_t pos = name.find(' ');
    return name.substr(0, pos);
}

void DoublyLinkedList::push(const string& value)
{
    Node* node = new Node();

    if (head == nullptr)
    {
        head = node;
        tail = node;
        head->data = value;
        tail->data = value;
        return;
    }

    node->data = value;
    node->prev = nullptr;
    node->next = head;
    head->prev = node;
    head = node;
}

void DoublyLinkedList::insertAfter(Node* prevNode, const string& value)
{
    Node* node = new Node();

    if (prevNode == nullptr)
    {
        head = node;
        tail = node;
        head->data = value;
        tail->data = value;
        return;
    }

    node->data = value;
    node->prev = prevNode;
    node->next = prevNode->next;
    prevNode->next = node;

    if (node->next != nullptr)
    {
        node->next->prev = node;
    }
}

void DoublyLinkedList::append(const string& value)
{
    Node* node = new Node();

    if (tail == nullptr)
    {
        head = node;
        tail = node;
        head->data = value;
        tail->data = value;
        return;
    }

    node->data = value;
    node->prev = tail;
    node->next = nullptr;
    tail->next = node;
    tail = node;
}

void DoublyLinkedList::delNode(Node* del)
{
    if (head == nullptr || del == nullptr) { return; }

    if (head == del) { head = del->next; }

    if (del->next != nullptr) { del->next->prev = del->prev; }

    if (del->prev != nullptr) { del->prev->next = del->next; }

    delete del;
}

Node* DoublyLinkedList::searchNode(const string& key)
{
    Node* temp = head;

    while (temp->data != key && temp->next != nullptr) { temp = temp->next; }

    if (temp->data != key) { return nullptr; }

    return temp;
}

void DoublyLinkedList::printNode()
{
    while (head->prev != nullptr) { head = head->prev; }

    Node* temp = head;

    while (tail->next != nullptr) { tail = tail->next; }

    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << temp->data << endl;
}

HashTable::HashTable(int size)
{
    this->bucket = size;
    table = new DoublyLinkedList * [bucket];
    for (int i = 0; i < bucket; i++)
    {
        table[i] = new DoublyLinkedList();
    }
}

int HashTable::hashFunc(const string& key)
{
    return convertASCII(getFirstName(key)) % this->bucket;
}

void HashTable::insItem(const string& key)
{
    int index = hashFunc(key);
    table[index]->push(key);
}

void HashTable::searchItem(const string& key)
{
    int index = hashFunc(key);
    DoublyLinkedList* temp = table[index];

    if (temp != nullptr)
    {
        while (temp != nullptr)
        {
            temp->head
        }
    }
}

void HashTable::delItem(const string& key)
{
    int index = hashFunc(key);
    DoublyLinkedList* temp = table[index];

}