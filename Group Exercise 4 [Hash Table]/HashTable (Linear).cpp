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
    void printNode(const string&);
};

int convertASCII(const string&);
string getFirstName(const string&);

int main()
{
    HashTable* table = new HashTable(10);

    table->insertItem("Josh William", "384-182-4845");
    table->insertItem("Jennifer White", "394-596-3925");
    table->insertItem("Dave Smith", "912-395-3901");
    table->insertItem("Dave Smith", "234-463-5903");
    table->insertItem("Dave Smith", "748-484-8640");


    cout << "Before delete: " << endl;

    cout << table->searchItem("Josh William") << endl;
    cout << table->searchItem("Jennifer White") << endl;
    cout << table->searchItem("Dave Smith") << endl;

    table->deleteItem("Jennifer White");

    cout << endl;

    cout << "After delete: " << endl;

    cout << table->searchItem("Josh William") << endl;
    cout << table->searchItem("Jennifer White") << endl;
    cout << table->searchItem("Dave Smith") << endl;

    table->printNode("Dave Smith");
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

    while (index < this->tableSize)
    {
        if (table[index] == nullptr)
        {
            table[index] = new HashNode();
            table[index]->data = key;
            table[index]->phone = phone;
            return;
        }

        index++;
    }

    if (index == this->tableSize)
    {
        index = 0;

        while (index < temp)
        {
            if (table[index] == nullptr)
            {
                table[index] = new HashNode();
                table[index]->data = key;
                table[index]->phone = phone;
                return;
            }

            index++;
        }
    }
}

bool HashTable::searchItem(const string& key)
{
    int index = hashFunc(key);
    int temp = index;

    while (index < this->tableSize)
    {
        if (table[index] != nullptr && table[index]->data == key)
        {
            return true;
        }

        index++;
    }

    if (index == this->tableSize)
    {
        index = 0;

        while (index < temp)
        {
            if (table[index] != nullptr && table[index]->data == key)
            {
                return true;
            }

            index++;
        }
    }

    return false;
}

void HashTable::deleteItem(const string& key)
{
    int index = hashFunc(key);
    int temp = index;

    while (index < this->tableSize)
    {
        if (table[index]->data == key)
        {
            delete table[index];
            table[index] = nullptr;
            return;
        }

        index++;
    }

    if (index == this->tableSize)
    {
        index = 0;

        while (index < temp)
        {
            if (table[index]->data == key)
            {
                delete table[index];
                table[index] = nullptr;
                return;
            }

            index++;
        }
    }
}

void HashTable::printNode(const string& key)
{
    int index = hashFunc(key);
    int temp = index;

    while (index < this->tableSize)
    {
        if (table[index] != nullptr && table[index]->data == key)
        {
            cout << table[index]->data << ' ' << table[index]->phone << " ----> ";
        }

        index++;
    }

    if (index == this->tableSize)
    {
        index = 0;

        while (index < temp)
        {
            if (table[index] != nullptr && table[index]->data == key)
            {
                cout << table[index]->data << ' ' << table[index]->phone << " ----> ";
            }

            index++;
        }
    }

}