#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class HashNode
{
private:
    string data;
    string phone;

    friend class HashTable;

public:
    HashNode() {}
    ~HashNode() {}
};

class HashTable
{
private:
    int tableSize;
    HashNode** table;

    int hashFunc(const string&);

public:
    HashTable() {}
    HashTable(const int&);
    ~HashTable() {}
    void insertItem(const string&, const string&);
    bool searchItem(const string&);
    void deleteItem(const string&);
    void printTable();
};

int convertASCII(const string&);
string getFirstName(const string&);

int main()
{
    HashTable* table = new HashTable(10);

    table->insertItem("Josh William", "384-182-4845");
    table->insertItem("Jennifer White", "394-596-3925");
    table->insertItem("Dave Smith", "912-395-3901");
    table->insertItem("Dave White", "234-463-5903");
    table->insertItem("Dave Jackson", "748-484-8640");
    table->insertItem("Jennifer Collins", "394-596-3925");

    table->deleteItem("Dave Jackson");
    table->deleteItem("Dave White");
    table->deleteItem("Dave Smith");
    table->deleteItem("Jennifer Collins");

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

HashTable::HashTable(const int& size)
{
    this->tableSize = size;
    this->table = new HashNode * [tableSize];

    for (int i = 0; i < tableSize; i++)
    {
        table[i] = nullptr;
    }
}

int HashTable::hashFunc(const string& key)
{
    return convertASCII(getFirstName(key)) % this->tableSize;
}

void HashTable::insertItem(const string& key, const string& phone)
{
    int index = hashFunc(key);
    int temp = index;

    while (temp < this->tableSize)
    {
        if (table[temp] == nullptr)
        {
            table[temp] = new HashNode();
            table[temp]->data = key;
            table[temp]->phone = phone;
            return;
        }

        temp++;
    }


    if (temp == this->tableSize)
    {
        temp = 0;

        while (temp < index)
        {
            if (table[temp] == nullptr)
            {
                table[temp] = new HashNode();
                table[temp]->data = key;
                table[temp]->phone = phone;
                return;
            }

            temp++;
        }
    }
}

bool HashTable::searchItem(const string& key)
{
    int index = hashFunc(key);
    int temp = index;

    while (temp < this->tableSize)
    {
        if (table[temp] != nullptr && table[temp]->data == key)
        {
            return true;
        }

        temp++;
    }

    if (temp == this->tableSize)
    {
        temp = 0;

        while (temp < index)
        {
            if (table[temp] != nullptr && table[temp]->data == key)
            {
                return true;
            }

            temp++;
        }
    }

    return false;
}

void HashTable::deleteItem(const string& key)
{
    int index = hashFunc(key);
    int temp = index;

    while (temp < this->tableSize)
    {
        if (table[temp] != nullptr && table[temp]->data == key)
        {
            delete table[temp];
            table[temp] = nullptr;
            return;
        }

        temp++;
    }

    temp = 0;

    while (temp < index)
    {
        if (table[temp] != nullptr && table[temp]->data == key)
        {
            delete table[temp];
            table[temp] = nullptr;
            return;
        }

        temp++;
    }
}

void HashTable::printTable()
{
    for (int i = 0; i < this->tableSize; i++)
    {
        cout << i << ". ";

        if (table[i] != nullptr)
        {
            cout << table[i]->data << " " << table[i]->phone << endl;
        }

        else
        {
            cout << "NULL" << endl;
        }
    }
}