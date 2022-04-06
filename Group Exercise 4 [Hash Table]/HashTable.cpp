#include <iostream>
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

int main()
{
    DoublyLinkedList* list = new DoublyLinkedList();
    list->push("Josh");
    list->push("Dave");
    list->push("Jennifer");

    list->printNode();

    Node* result = list->searchNode("Dave");
    list->delNode(result);

    list->printNode();

    system("pause");
    return 0;
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