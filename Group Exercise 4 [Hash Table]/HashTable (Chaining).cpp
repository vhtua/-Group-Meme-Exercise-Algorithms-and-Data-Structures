#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Node
{
private:
    string data;
    string phone;
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
    void push(const string&, const string&);
    void insertAfter(Node*, const string&, const string&);
    void append(const string&, const string&);
    void delNode(Node*);
    void printList();
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
    void insertItem(const string&, const string&);
    void deleteItem(const string&);
    void printTable();
};

int convertASCII(const string&);
string getFirstName(const string&);

int main()
{
    HashTable* table = new HashTable(10);
    table->insertItem("Josh Devia", "454-596-0954");
    table->insertItem("Jennifer Williams", "495-596-1238");
    table->insertItem("Dave Smith", "845-292-5839");

    cout << "Before delete: " << endl;

    table->printTable();

    table->deleteItem("Jennifer Williams");

    cout << endl << "After delete: " << endl;

    table->printTable();

    cout << endl;

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

void DoublyLinkedList::push(const string& value, const string& phone)
{
    Node* node = new Node();

    if (head == nullptr)
    {
        head = node;
        tail = node;
        head->data = value;
        head->phone = phone;
        tail->data = value;
        tail->phone = phone;
        return;
    }

    node->data = value;
    node->phone = phone;
    node->prev = nullptr;
    node->next = head;
    head->prev = node;
    head = node;
}

void DoublyLinkedList::insertAfter(Node* prevNode, const string& value, const string& phone)
{
    Node* node = new Node();

    if (prevNode == nullptr)
    {
        head = node;
        tail = node;
        head->data = value;
        head->phone = phone;
        tail->data = value;
        tail->phone = phone;
        return;
    }

    node->data = value;
    node->phone = phone;
    node->prev = prevNode;
    node->next = prevNode->next;
    prevNode->next = node;

    if (node->next != nullptr)
    {
        node->next->prev = node;
    }
}

void DoublyLinkedList::append(const string& value, const string& phone)
{
    Node* node = new Node();

    if (tail == nullptr)
    {
        head = node;
        tail = node;
        head->data = value;
        head->phone = phone;
        tail->data = value;
        tail->phone = phone;
        return;
    }

    node->data = value;
    node->phone = phone;
    node->prev = tail;
    node->next = nullptr;
    tail->next = node;
    tail = node;
}

void DoublyLinkedList::delNode(Node* del)
{
    if (head == nullptr || del == nullptr) { return; }

    if (head == del) { head = del->next; }

    if (tail == del) { tail = del->prev; }

    if (del->next != nullptr) { del->next->prev = del->prev; }

    if (del->prev != nullptr) { del->prev->next = del->next; }

    delete del;
    del = nullptr;
}

Node* DoublyLinkedList::searchNode(const string& key)
{
    Node* temp = this->head;

    if (temp != nullptr)
    {
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return temp;
            }

            temp = temp->next;
        }
    }

    return nullptr;
}

void DoublyLinkedList::printList()
{
    while (head->prev != nullptr) { head = head->prev; }

    Node* temp = head;

    while (tail->next != nullptr) { tail = tail->next; }

    while (temp != tail)
    {
        cout << "Name: " << temp->data << ", phone: " << temp->phone << " ----> ";
        temp = temp->next;
    }

    cout << "Name: " << temp->data << ", phone number: " << temp->phone;
}

HashTable::HashTable(int size)
{
    this->bucket = size;
    table = new DoublyLinkedList * [bucket];
    for (int i = 0; i < bucket; i++)
    {
        table[i] = nullptr;
    }
}

int HashTable::hashFunc(const string& key)
{
    return convertASCII(getFirstName(key)) % this->bucket;
}

void HashTable::insertItem(const string& key, const string& phone)
{
    int index = hashFunc(key);

    if (table[index] == nullptr)
    {
        table[index] = new DoublyLinkedList();
    }

    table[index]->push(key, phone);
}

bool HashTable::searchItem(const string& key)
{
    int index = hashFunc(key);
    Node* resNode = nullptr;
    bool result = false;
    DoublyLinkedList* temp = table[index];

    if (temp != nullptr)
    {
        resNode = temp->searchNode(key);

        if (resNode != nullptr)
        {
            result = true;
        }

        else
        {
            result = false;
        }
    }

    return result;
}

void HashTable::deleteItem(const string& key)
{
    int index = hashFunc(key);
    DoublyLinkedList* temp = table[index];

    if (temp != nullptr)
    {
        Node* tempNode = temp->searchNode(key);
        temp->delNode(tempNode);

        if (temp->head == nullptr && temp->tail == nullptr)
        {
            delete temp;
            table[index] = nullptr;
        }
    }
}

void HashTable::printTable()
{
    for (int i = 0; i < this->bucket; i++)
    {
        if (table[i] != nullptr)
        {
            cout << i << ". ";
            table[i]->printList();
            cout << endl;
        }

        else
        {
            cout << i << ". NULL";
            cout << endl;
        }
    }
}