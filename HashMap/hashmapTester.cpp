#include "HashMap.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

int main() {
	std::cerr << "\n\tTest #1: Create a hash map" << std::endl;
	
	HashMap<std::string*> hashMap(10);
	assert(hashMap.size() == 10);
    	
	std::string username;
	std::string password;
	
	std::ifstream textFile("passwords.txt");
	
	std::cerr << "\n\tTest #2: Populate hash map with key value pairs" << std::endl;

	while (textFile >> username >> password) {
        	if (username != "end"){
            		hashMap.set(username, &password);
        	}
    	}
    	hashMap.printHash();
 
	std::cerr << "\n\tTest #3: Try, but fail, to access value not in hash map" << std::endl;

	std::string* invalidPassword = hashMap.get("hello");
    	assert(invalidPassword == NULL);

	std::cerr << "\n\tTest #4: Make sure all values are accessible from their keys" << std::endl;
   	textFile.clear();
    	textFile.seekg(0, std::ios::beg);
    	textFile >> username;
    	while (username != "end"){
        	textFile >> password;
		std::string* hashedPassword = hashMap.get(username);
		if (username != "value") {
			assert(password == *hashedPassword);
		}
        	textFile >> username;
    	}

	std::cerr << "\n\tTest #5: Access the load factor" << std::endl;
	std::cout << "\tLoad factor: " << hashMap.load() << std::endl;
	
	std::cerr << "\n\tTest #6: Make sure removing elements works" << std::endl;
    	textFile.clear();
    	textFile.seekg(0, std::ios::beg);
    	while (!hashMap.empty()){
        	textFile >> username >> password;
		std::string* hashedPassword = hashMap.get(username);
		if (hashedPassword != NULL) {
			if(password == *hashedPassword){
				hashMap.remove(username);
				assert(hashMap.size() == 10);
				assert(hashMap.get(username) == NULL);
			}
		}
    	}

    	textFile.close();
    	return 0;
}
