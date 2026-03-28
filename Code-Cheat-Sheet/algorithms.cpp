#include "cheat-header.h"

struct Algorithms {

        void SortFunctions() {

        char comparator = '>';
        std::vector<int> toSort = {1,9,2,3,5,42,9,6};
        int pivot = toSort.size() / 2;

        std::sort(toSort.begin(),toSort.end(),comparator); //O(nlogn) sorting algorithm, we can give a comparator to swap to sorting in reverse 

        std::stable_sort(toSort.begin(),toSort.end(),comparator); //same sort but stable

        std::nth_element(toSort.begin(),toSort.begin() + pivot,toSort.end()); //Partion function in quicksort;;

    }

    void SearchFunction() {

        int value = 5;

        std::vector<int> toSearch = {5,91,8,56,2,3};
        
        auto it = std::find(toSearch.begin(), toSearch.end(), value);  //This will search through the vector and look for the first occurance of our value
        //if it finds it, it will return an iterator to that index if not it will return v.end();

        //O(n)

        if (it != toSearch.end()) {
            std::cout << std::distance(toSearch.begin(), it) << "\n"; //This will print the index of the found element (2 in this case)
        }

        //find_if & find_if_not => find but instead of a value, it takes a predicate (a function that returns a boolean)

        auto it2 = find_if(toSearch.begin(), toSearch.end(), [](int x) { return x % 2 == 1; });

        if (it2 != toSearch.end()) {
            std::cout << std::distance(toSearch.begin(), it2) << "\n"; //This will print the index of the first odd element (0 in this case)
        }

        bool isPresent = std::binary_search(toSearch.begin(), toSearch.end(), value); //ONLY WORKS ON SORTED VECTORS
        //quickly seraches the vector to see if the file is present or not as a boolean
        
        //O(log(n))

        //--------------------------------------------------------------------------------------------------------------------------------------------------

        std::lower_bound(toSearch.begin(), toSearch.end(),value); //looks for the first occurence of a value lower than the value given, returns an iterator to it if not return end
        std::upper_bound(toSearch.begin(), toSearch.end(),value);

        int count = std::count(toSearch.begin(), toSearch.end(), value); //counts how many values are in the vector

    }

    void MaxElement() {
        std::vector<int> toFind = {1,2,3,4,5};
        char binaryComparator = '<';

        //Needs #include <algoritm>

        //Finds the maximum elemnt in a given range, returns an iterator to it if it doesnt find it returns iterator to last
        
        auto maxIt = std::max_element(toFind.begin(),toFind.end(),binaryComparator);
        
        std::cout << *maxIt << "\n"; //Prints the maximum element (5 in this case)
        
    }

};