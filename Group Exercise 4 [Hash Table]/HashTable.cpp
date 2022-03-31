#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string data;
    Node *prev;
    Node *next;
};

class LinkList
{
private:
    Node *head;
    Node *tail;

public:
    LinkList();
    ~LinkList();
    void push(string);
    void insertAfter(Node *, string);
    void append(string);
};

LinkList::LinkList()
{
    head->prev = nullptr;
    head->next = nullptr;
    tail->prev = nullptr;
    tail->next = nullptr;
}

LinkList::~LinkList() {}

void LinkList::push(string value)
{
    if (head == nullptr)
    {
        head->data = value;
        tail->data = value;
        return;
    }

    Node *newNode = new Node;

    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void LinkList::insertAfter(Node *prevNode, string value)
{
    if (prevNode == nullptr)
    {
        head->data = value;
        tail->data = value;
        return;
    }

    Node *newNode = new Node;

    newNode->data = value;
    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    prevNode->next = newNode;

    if (newNode->next != nullptr)
    {
        newNode->next->prev = newNode;
    }
}

void LinkList::append(string value)
{
    if (tail == nullptr)
    {
        head->data = value;
        tail->data = value;
        return;
    }

    Node *newNode = new Node;

    newNode->data = value;
    newNode->prev = tail;
    newNode->next = nullptr;
    tail->next = newNode;
    tail = newNode;
}