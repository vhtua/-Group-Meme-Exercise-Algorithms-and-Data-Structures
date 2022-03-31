#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

// ============= Prototype function ================
string getLastname(string fullname);
int convert_ASCII(string last_name);

// Doubly linked list declaration
struct hash_node {			
	std::string key;
	std::string val;

	hash_node *next;
	hash_node *prev;
};

// Hash Table declaration
class HashMap {
	private:
		const int tablesize = 100;

	public:
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

		~HashMap() {
			delete[] hashtable;			// destructor
		}

		// Additional Methods
		int HashFunc(string key);
		void Search(string key);
		void Insert(string key, string value);


};


int HashMap::HashFunc(string key) {		
	// get the last name of the key and then convert it into an integer
	// string hasing https://cp-algorithms.com/string/string-hashing.html
	return convert_ASCII(getLastname(key)) % tablesize;
}


void HashMap::Search(string key) {
	int hash_val = HashFunc(key);
	bool flag = false;
	hash_node* entry = hashtable[hash_val];

	if (entry != NULL) {
		while (entry != NULL) {
			if (entry -> key == key) {
				flag = true;
			}

			if (flag) {
				cout << "Element found at key: " << key << ": ";
				cout << entry -> val;
			}

			entry = entry -> next;
		}
	}

	if (!flag)
		cout << "No Element found at key " << key << endl;

}

void HashMap::Insert(string key, string value) {
        int hash_val = HashFunc(key);
        hash_node* entry = hashtable[hash_val];
  
        if (entry == NULL) {
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
        cout << "Value " << value << " was successfully Inserted at key " << key << endl;
    }



// ===================== Main function ======================
int main(void) {
	HashMap hash;
    hash.Insert("John Smith", "521-1234");
    hash.Search("John Smith");
   // hash.remove("John Smith");
   	
   	cout << "\n==================================\n\n";
   	hash.Insert("Lisa Smith", "521-8976");
    hash.Search("Lisa Smith");

	return 0;
}


// ========================= FUNCTION DEFINITION =================================
string getLastname(string fullname) {
	std::string s = "scott tiger";
	std::string delimiter = " ";

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
   		token = s.substr(0, pos);
    	s.erase(0, pos + delimiter.length());
	}
	string last_name = s;
	//std::cout << last_name;

	return last_name;
}


int convert_ASCII(string last_name) {
	double p = 53;
	double result = 0;
	for (int i = 0; i < (int)last_name.size() - 1; ++i) {
		result += last_name[i] * pow(p, i);
	}

	//cout << fixed << (int)result;

	return (int)result;
}
	
