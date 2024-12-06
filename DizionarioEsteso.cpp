#include <iostream>
template <typename T>
class Dizionario {
private:
    static const int MAX_VAL = 100; 
    struct Dizio {
        std::string key;
        T valore;
        bool occupato = false;
    };

    Dizio table[MAX_VAL];

    int hashFunction(const std::string& key) const {
        int hash = 0;
        for (char ch: key) {
            hash = (hash * 31 + ch) % MAX_VAL; // hash
        }
        return hash % MAX_VAL;
    }

public:
  
    void inserisci(const std::string& key, const T& valore) {
        int index = hashFunction(key);

        if (table[index].occupato && table[index].key != key) {
            index = findSlot(index);
        }

        table[index].key = key;
        table[index].valore = valore;
        table[index].occupato = true;
    }

    void cancella(const std::string key) {
	 int index = hashFunction(key);
		 if (table[index].occupato == true && table[index].key ==key) {
 				table[index].occupato = false; // pos libera
 				std::cout << "Chiave " << key << " cancellata.\n";
 				} else {
 						std::cout << "Chiave " << key << " non trovata.\n";
				 		}
 }

    
    T recupera(const std::string& key) const {
        int index = hashFunction(key);

        if (table[index].occupato && table[index].key != key) {
            while (table[index].occupato && table[index].key != key) {
                index = (index + 1) % MAX_VAL;
                if (table[index].occupato) {
                    throw std::runtime_error("Key not found!");
                }
            }
        }

        if (table[index].occupato) {
            return table[index].valore;
        } else {
            throw std::runtime_error("Key not found!");
        }
    }

   bool appartiene(const std::string key) const {
 		int index = hashFunction(key);
			 if (table[index].occupato == truw && table[index].key ==key) {
				 return true; 
 				}
 				else
 					return false; 
 }  
  
    void stampa() const {
        for (int i = 0; i < MAX_VAL; ++i) {
            if (table[i].occupato) {
                std::cout << "Index " << i << ": " << table[i].key << " => " << table[i].valore << "\n";
            }
        }
    }
}

