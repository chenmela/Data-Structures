HashMap: 
This is a C++ implementation of a fixed size hash map associating string keys with arbitraty data object references. This data structure was designed with optimal runtime and memory usage in mind.

Getting started:
To create a HashMap instance, use HashMap<T> hashMap = new HashMap<T>(size) or HashMap<T> hashMap(size), where size is the maximum number of elements the map will store and T is the templatized type of the values to be inserted.

Note that the type of the value must be a data object reference (i.e. a pointer to a primitive type or object). This was chosen in order to comply with the requirement that get() and delete() should return null - without using a library like boost, these functions must return a pointer type in order to also return null.

To call functions, use hashMap.get("apples"), hashMap.remove("apples"), and hashMap.load();

Note that the delete function is not called remove, as delete is a keyword in C++.

Testing:
I have included a test that reads input from a file, populates a hashmap, and demonstrates delete, get, and load functionality. To run, simply type make run at the command line. To verify the solution does not create memory leaks, run make checkmem, which calls valgrind in the Makefile.

Author: Melanie Chen
Last Updated: September 30, 2017
