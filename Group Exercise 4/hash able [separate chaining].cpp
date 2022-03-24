// separate chaining Hash Table
#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class HashTable {
	private:
		static const int hashGroups = 10;
		std::list <pair<int, string>> table[hashGroups];	// create a list of pair (key, value)

	public:
		bool isEmpty();
		int hashFunction(int key);
		void insertItem(int key, string value);
		void removeItem(int key);
		void printTable();
		string searchTable(int key);
		
};

bool HashTable::isEmpty() {
	int sum{};
	for (int i{}; i < hashGroups; ++i) {
		sum += table[i].size();
	}

	if(!sum) {
		return true;
	}
	return false;
}

int HashTable::hashFunction(int key) {
	return key % hashGroups;
}

void HashTable::insertItem(int key, string value) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);		// declare begining intergrator --> beginning of the list
	bool keyExist = false;

	for (; bItr != end(cell); bItr++) {
		if (bItr -> first == key) {
			keyExist = true;
			bItr -> second = value;
			cout << "Key exists! Value replaced." << endl;
			break;
		}
	}

	if(!keyExist) {
		cell.emplace_back(key, value); 	// insert when the key doesn't exist
	}

	return;

}

void HashTable::removeItem(int key) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);		// declare begining intergrator --> beginning of the list
	bool keyExist = false;

	for (; bItr != end(cell); bItr++) {
		if (bItr -> first == key) {
			keyExist = true;
			bItr = cell.erase(bItr);
			cout << "Item removed." << endl;
			break;
		}
	}

	if (!keyExist) {
		cout << "Key not found! Pair not remove." << endl;
	}

	return;
}


void HashTable::printTable() {
	for (int i{}; i < hashGroups; ++i) {
		if (table[i].size() == 0)
			continue;
		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			cout << "Key: " << bItr -> first << ", Value: " << bItr -> second << endl;
		}
	}

	return;
}




// =============== MAIN FUNCTION
int main(void) {
	HashTable HT;

	if (HT.isEmpty()) {
		cout << "[INFO] Empty Hash Table " << endl;
	}
	else {
		cout << "Something wrong in declaration! Check again the Table!" << endl;
	}

	HT.insertItem(109, "LyLy");
	HT.insertItem(218, "Miu");
	HT.insertItem(91, "Tuna");
	HT.insertItem(14, "Tom");
	HT.insertItem(415, "Bob");
	HT.insertItem(76, "Sandy");
	HT.insertItem(117, "Kim");
	HT.insertItem(360, "Rob");
	HT.insertItem(871, "Rick");
	HT.insertItem(871, "Linda");

	HT.printTable();

	HT.removeItem(14);
	HT.removeItem(76);

	if (HT.isEmpty()) {
		cerr << "[ERROR] The Hash Table is empty" << endl;
	}

	//HT.printTable();

	return 0;
}