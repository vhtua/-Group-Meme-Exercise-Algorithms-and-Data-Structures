#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <list>

using namespace std;

// ============= Prototype function ================


// Doubly linked list declaration
struct hash_node {			
	string key;
	string val;

	hash_node *next;
	hash_node *prev;
};

// Hash Table declaration
class HashMap {
	private:
		const int tablesize = 100;
		//const int linked_list_size;
	protected:
	public:
		//std::list <pair<string, string>> linked_list_data;
		hash_node **hashtable;
		hash_node **top;

		// Default Methods
		HashMap() {						// constructor
				hashtable = new hash_node*[tablesize];
				top = new hash_node*[tablesize];

				for (int i{}; i < tablesize; ++i) {
					hashtable[i] = NULL;
					top[i] = NULL;
				}
		}

		~HashMap() { delete[] hashtable; }			// destructor

		// Additional Methods
		string getFirstname(string fullname);
		string getLastname(string fullname);
		unsigned int convert_ASCII(string first_name);
		
		unsigned int HashFunc(string key);
		void Search(string key);
		void Insert(string key, string value);
		void Delete(string key);
		void showBuckets();
		void menu();
};

// ========================= FUNCTION DEFINITION =================================
string HashMap::getFirstname(string fullname) {
	//std::string s = "Tuna CSE2020";
    std::string delimiter = " ";

    size_t pos = 0;
    std::string token;
    while ((pos = fullname.find(delimiter)) != std::string::npos) {
        token = fullname.substr(0, pos);
        //std::cout << token << std::endl;
        fullname.erase(0, pos + delimiter.length());
    }
    string first_name = token;
    //cout << first_name;
    return first_name;
}


string HashMap::getLastname(string fullname) {
	//std::string s = "Tuna CSE";
	std::string delimiter = " ";

	size_t pos = 0;
	std::string token;
	while ((pos = fullname.find(delimiter)) != std::string::npos) {
   		token = fullname.substr(0, pos);
    	fullname.erase(0, pos + delimiter.length());
	}
	string last_name = fullname;
	std::cout << last_name;

	return last_name;
}


unsigned int HashMap::convert_ASCII(string first_name) {
	unsigned int p = 53;
	unsigned int result = 0;
	for (int i = 0; i < (int)first_name.size() - 1; ++i) {
		result += first_name[i] * pow(p, i);
	}

	// cout << fixed << (int)result;

	return result;
}


unsigned int HashMap::HashFunc(string key) {		
	// get the last name of the key and then convert it into an integer
	// string hasing https://cp-algorithms.com/string/string-hashing.html
	
	// cout << convert_ASCII(getFirstname(key)) % tablesize; --> debug
	return convert_ASCII(getFirstname(key)) % tablesize;
}


void HashMap::Search(string key) {
	int hash_val = HashFunc(key);
	bool flag = false;
	hash_node* entry = hashtable[hash_val];

	if (entry != NULL) {
		while (entry != NULL) {
			if (entry -> key == key) {
				//cout << "!!! Found key " << entry -> key << endl;
				//cout << "!!! Found value " << entry -> val << endl;
				flag = true;
			}

			if (flag) {
				cout << "\n [!] Element found at key " << key << " is: "<< entry -> val << endl;
				break;
			}

			entry = entry -> next;
		}
	}

	if (!flag)
		cout << "\n [!] No Element found at key " << key << endl;

}

void HashMap::Insert(string key, string value) {
        int hash_val = HashFunc(key);
        //cout << "Inserted " << hash_val << "!!! \n";
        hash_node* entry = hashtable[hash_val];
  
        if (entry == NULL || key == entry -> key) {
            entry = new hash_node;
            entry->val = value;
            entry->key = key;
            entry->next = NULL;
            entry->prev = NULL;
            hashtable[hash_val] = entry;
            top[hash_val] = entry;
        }
  
        else {
            while (entry != NULL)
                entry = entry->next;
  
            entry = new hash_node;
            entry->val = value;
            entry->key = key;
            entry->next = NULL;
            entry->prev = top[hash_val];
            top[hash_val]->next = entry;
            top[hash_val] = entry;
        }
        cout << "\n [!] Value " << value << " was successfully Inserted at key " << key << endl;
    }

void HashMap::Delete(string key) {
        int hash_val = HashFunc(key);
        hash_node* entry = hashtable[hash_val];
        if (entry -> key != key || entry == NULL) {
            cout << "\n [x] Couldn't find any element at this key " << key << endl;
        }

  
        while (entry != NULL) {
            if (entry->next == NULL) {
                if (entry->prev == NULL) {
                    hashtable[hash_val] = NULL;
                    top[hash_val] = NULL;
                    delete entry;
                    break;
                }

                else {
                    top[hash_val] = entry->prev;
                    top[hash_val]->next = NULL;
                    delete entry;
                    entry = top[hash_val];
                }
            }
            entry = entry->next;
        }
        cout << "\n [!] Element was successfully removed at the key " << key << endl;
}


void HashMap::showBuckets() {
	//int hash_val = HashFunc(key);
	//bool flag = false;
	cout << "Show Buckets" << endl;
	hash_node* entry = hashtable[0];

	for (int i = 0; i < tablesize; ++i) {
		
		if (entry != NULL) {
			cout << i;
			while (entry != NULL) {	
				cout << " <---> " << entry -> key << ": " << entry -> val << " ";
				entry = entry -> next;
				//cout << " --- " << entry -> key << ": " << entry -> val << " ";
			}
			cout << endl;
		}
		else {
			cout << i << ". " << "NULL" << endl;
		}
		entry = hashtable[i];
	}

	

	/*
	if (!flag)
		cout << "\n [!] No Element found at key " << key << endl;
	*/
}


void HashMap::menu() {
	int choice{};
	string key, val;

	cout << "================== HASH TABLE ================== " << endl;
	while (choice != 4) {
		cout << "Select the number corresponding to your action below: (1 ~ 4)" << "\n";
		cout << "(1). Insert a key and value to the hash table" << endl;
		cout << "(2). Search a value using the key" << endl;
		cout << "(3). Delete a value using the key" << "\n";
		cout << "(4). Exit" << "\n\n";
		cout << "[?] Your option is: ";
		cin >> choice;
		if (choice == 1) {
			cout << "[!] Inserting" << endl;
			cout << " |__ Enter the key (full name): ";
			std::getline(std::cin >> std::ws, key);
			//coutcout << key;
			fflush(stdin);

			cout << " |__ Enter the value (telephone number): ";
			std::getline(std::cin >> std::ws, val);
			fflush(stdin);

			Insert(key, val);
			cout << "=============================================== ";
			cout << endl;
		}
		else if (choice == 2) {
			cout << "[!] Searching" << endl;
			cout << " |__ Enter the key (full name): ";
			std::getline(std::cin >> std::ws, key);
			fflush(stdin);

			Search(key);
			cout << "=============================================== ";
			cout << endl;
		}
		else if (choice == 3) {
			cout << "[!] Deleting" << endl;
			cout << " |__ Enter the key (full name): ";
			std::getline(std::cin >> std::ws, key);
			fflush(stdin);

			//cout << key << endl;
			Delete(key);
			cout << "=============================================== ";
			cout << endl;
		}

		else if (choice == 4) {
			cout << " |__ Good bye!";
			break;
		}

			
	}
	
	//while ()
}

// ===================== Main function ======================
int main(void) {
	HashMap hash;

	//hash.menu();
	
	hash.Insert("John Smith", "521-1234");
	hash.Insert("John Smith", "521-1235");

	hash.Insert("John Maguire ", "521-8976");
	hash.Insert("Luna Smith", "521-3166");
	hash.Insert("William Boi", "711-8176");
	hash.Insert("William Shakespear", "721-8436");

	hash.showBuckets();

	hash.Search("John Smith");		
	hash.Search("Lisa Smith");
	hash.Search("Luna Smith");

	

	hash.Delete("Luna Smith");
	hash.Delete("Harry Luna");




	/*
    hash.Insert("John Smith", "521-1234");
    hash.Insert("Lisa Smith", "521-8976");
    hash.Insert("Sandra Dee", "521-9655");
	

    hash.Search("John Smith");
    hash.Search("Lisa Smith");
   // hash.Delete("John Smith");
   // hash.remove("John Smith");
   	
   	cout << "\n==================================\n\n";
   	hash.Insert("Lisa Smith", "521-8976");
    hash.Search("Lisa Smith");
	*/
	//hash.Insert("John Smith", "521-1234");
	//hash.Delete("John Smith");
	//hash.Delete("John dh");
	return 0;
}



	
