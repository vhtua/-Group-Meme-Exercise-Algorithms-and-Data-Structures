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
    friend class HashTable;

public:
    Node() : next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;
    Node* searchNode(const string&);

    friend class HashTable;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() {}
    void push(const string&);
    void insertAfter(Node*, const string&);
    void append(const string&);
    void delNode(Node*);
    void printNode();
};

class HashTable
{
private:
    int bucket;
    DoublyLinkedList** table;
    int hashFunc(const string&);

public:
    HashTable() {}
    HashTable(int);
    ~HashTable() {}
    bool searchItem(const string&);
    void insItem(const string&);
    void delItem(const string&);
};

int convertASCII(const string&);
string getFirstName(const string&);

int main()
{
    HashTable* table = new HashTable(30);
    table->insItem("Josh Devia");
    table->insItem("Jennifer Williams");
    table->insItem("Dave Smith");

    cout << table->searchItem("Dave Smith") << endl;
    cout << table->searchItem("Dave Smith") << endl;

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
    del = nullptr;
}

Node* DoublyLinkedList::searchNode(const string& key)
{
    Node* temp = head;

    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            return temp;
        }

        temp = temp->next;
    }

    return nullptr;
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

bool HashTable::searchItem(const string& key)
{
    int index = hashFunc(key);
    Node* resNode = nullptr;
    bool result = false;
    DoublyLinkedList* temp = table[index];

    if (temp != nullptr && temp->head != nullptr)
    {
        resNode = temp->searchNode(key);
    }

    if (resNode != nullptr) { result = true; }
    else { result = false; }

    delete temp;
    delete resNode;
    temp = nullptr;
    resNode = nullptr;
    return result;
}

void HashTable::delItem(const string& key)
{
    int index = hashFunc(key);
    DoublyLinkedList* temp = table[index];
    Node* tempNode = temp->searchNode(key);
    temp->delNode(tempNode);
    delete temp;
    temp = nullptr;
}