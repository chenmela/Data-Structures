#ifndef HASH_H
#define HASH_H

#include<stdio.h>
#include<string>
#include<vector>
#include<tuple>
#include<iostream>
#include<cmath>

template <class T>
class HashMap {
	public:
		/* Custom exception for invalid HashMap size input */
		struct InvalidInputException : public std::exception {
			const char * what() const throw() {
				return "Hashmap size must be a non-negative integer.";
			}
		};
		
		/*
		 * Construct a HashMap with pre-allocated space
		 * for a user-defined number of objects.
		 * 
		 * Throws exception when size is invalid.
		 */
		HashMap(unsigned int size) {
			maxSize = size;
			currSize = 0;
			
			if (size < 0 || (std::isnan(size) || size % 1 != 0)) {
				throw InvalidInputException();
			}

			/* Create string, object of type T, and bool
			 * to reserve space for each tuple's contents.
			 */
			T tObj;
			std::string str;
		       	/* This variable indicates whether a certain
			 * index has been occupied before.
			 */	
			bool neverUsed;

			/* Reserve space for each tuple in the vector */
			for (int i = 0; i < (int) maxSize; i++) {
				vec.push_back(std::make_tuple(
					str, tObj, neverUsed));
			}
			/* Initialize every index to have never been
			 * occupied.
			 */
			for (int i = 0; i < (int) maxSize; i++) {
				std::get<2>(vec.at(i)) = true;
			}
		};

		/* Insert key-value pairs into the HashMap.
		 * This employs a quadratic probing tecnique for
		 * collision resolution.
		 * Returns a boolean indicating whether insertion 
		 * was successful.
		 */
		bool set(std::string key, T value) {
			unsigned int index = hasher(key);
			
			/* If hashed index is not occupied by another element,
			 * fill it */
			if (std::get<2>(vec.at(index)) == true) {
				std::get<0>(vec.at(index)) = key;
				std::get<1>(vec.at(index)) = value;
				/* Since index is now occupied, 
				 * set flag to false */
				std::get<2>(vec.at(index)) = false;
				currSize++;
				return true;
			}

			/* If hashed index is occupied, calculate how many
			 * times you must move to find an unoccupied index.
			 */
			int count = 0;
			for (int i = index; i < (int) maxSize; i++) {
				if (std::get<2>(vec.at(index)) == true) {
					break;
				}
				count++;
			}

			for (int i = 0; i < (int) index; i++) {
				if (std::get<2>(vec.at(index)) == true) {
					break;
				}
				count++;
			}
			/* Move the element to i^2, where i is the number
			 * of steps needed to get to an unoccupied index. */
			int newIndex = ((count * count) + index) % maxSize;
			if (std::get<2>(vec.at(newIndex))) {
				std::get<0>(vec.at(newIndex)) = key;
				std::get<1>(vec.at(newIndex)) = value;
				std::get<2>(vec.at(newIndex)) = false;
				currSize++;
					return true;		
			}
			return false;
		};

		/*
		 * Retrieves value corresponding to supplied key.
		 */
		T get(std::string key) {
			/* Get value if key matches on first try. */
			unsigned int index = hasher(key);
			if (std::get<0>(vec.at(index)) == key) {
				return std::get<1>(vec.at(index));
			}
			
			/* If key doesn't match on first try, look 
			 * at indexes i^2 away, possible locations
			 * if collision occurred.
			 */
			for (int i = 1; i < (int) maxSize; i++) {
				int step = i * i;
				int newIndex = (index + step) % maxSize;
				if (std::get<2>(vec.at(newIndex))) {
					return NULL;
				}
				if (std::get<0>(vec.at(newIndex)) == key) {
					return std::get<1>(vec.at(newIndex));
				}	
				index += (i * i);
				index %= maxSize;
			}
			return NULL;
		};
		
		/* 
		 * Removes from the HashMap the key value pair corresponding
		 * to the given key.
		 * Returns a boolean indicating whether the removal 
		 * was successful.
		 */
		bool remove(std::string key) {
			T value = get(key);
			unsigned int index = hasher(key);
			if (value != NULL) {
				for (int i = 0; i < (int) maxSize; i++) {
					int step = i * i;
					int newIndex = (step + index) % maxSize;
					if (std::get<1>(vec.at(newIndex)) == value) {
						std::get<0>(vec.at(newIndex)) = "";
						std::get<1>(vec.at(newIndex)) = NULL;
						currSize--;
						return true;
					}
					index += step;
					index %= maxSize;
				}
			}
			return false;
		};

		/* Returns the load factor of the HashMap, a measure
		 * of how full it is.
		 */
		float load() {
			return ((float) currSize / (float) maxSize);
		};

		/* Returns a boolean indicating whether the HashMap
		 * is empty.
		 */
		bool empty() {
			return (currSize <= 0);
		};

		/* Returns the maximum size of the HashMap */
		unsigned int size() {
			return maxSize;
		};

		/* Neatly prints each index and key value pair in
		 * the HashMap. 
		 */
		void printHash() {
			for (int i = 0; i < (int) maxSize; i++) {
			std::cout << "\tIndex: " << i << ", Key: " <<
				std::get<0>(vec.at(i)) << ", Value: " << 
				std::get<1>(vec.at(i)) << std::endl;
			}
		};

		/* Hash function mapping string keys to integer
		 * values representing indices in the HashMap.
		 */
		unsigned int hasher(std::string key) {
			std::hash<std::string> hasher;
			unsigned int result = hasher(key);
			if (result < 0) {
				result *= -1;
			}
			return result % maxSize;
		};

	private:
		std::vector<std::tuple<std::string, T, bool>> vec;
		unsigned int maxSize;
		unsigned int currSize;
};

#endif
