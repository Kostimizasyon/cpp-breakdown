#include "cheat-header.h"

template <typename T>
struct DataStructuresInCPP {

    //EMPLACE VS PUSH => push and emplace are basically the same except the fact that emplace does everything inline so its better most of the time
    // edgecase for push => if an object is already created THEN being inserted then push is better as emplace will try to keep inline

    //'[]' is DANGEROUS =>IT WONT DO BOUNDS CHECKING, if it is out of bounds it will do undefined behaviour
    //use .at(index)

    //ARRAY VS VECTOR => arrays are better for performance cuz stack but dynamic is also a really big deal
    void VectorsInCPP() {
        T value = 5;

        std::vector<T> vec = {};

        //Vectors are dynamic arrays for c++, they live on the heap
        
        std::vector<T> arr = {};

        //GENERATION OF VECTORS:

        std::vector<T> customGenVector(15); //basically std::array<int, 15> but slower as it lives on the heap instead of stack

        std::generate(customGenVector.begin(), customGenVector.end(), [&] (T i) {return i*i;}); //Generating a custom vector that will be ran through a function

        //requires #include <numeric>
        T numberToIncrementFrom = 1;
        std::iota(customGenVector.begin(), customGenVector.end(), numberToIncrementFrom); //It will inrement from this number till it reaches the end of the vector
    

        //Operations:

        //1)Insertion:

            arr.push_back(5); //:: Inserts an elemnt at the end of the vector very fast, O(1) => create the object then pass it this function
            arr.emplace_back(); //:: better push_back => do everything inline //returns a reference to the reference to inserted value

            //Takes a iterator to point to index
            arr.insert(arr.begin()+1,9); //:: Insert an element at a spesified position, slow => O(n)
            arr.emplace(arr.begin()+9, 1) //:: Insert at a spesified position but faster (inline) :: returns iterator to emplaced item

            std::fill(arr.begin(), arr.end(), value); //Fill the vector with the value
    
        //2)Access Elements:

            arr[1]; 
            //or , both O(1) BUT [] WONT DO BOUNDARY CHECKING
            arr.at(1);

            arr.front();
            arr.back();

            arr.data(); //Returns a raw pointer to the underlaying array.
        
        //3)Deleting Elements:

            arr.pop_back(); //remove the last value in the vector

            arr.erase(arr.begin()+1); //remove the element at a spesific index using an iterator

            arr.clear(); //clear vector

        //4)Other operations:

            arr.swap(vec); //Swap the contents of two vectors 

            arr.size(); //get the size of vector, returns int

            arr.empty(); //check if the vector is empty, returns bool

            arr.capacity(); //Returns the total memory currently alocated for the vector

            arr.resize(20); //Resize the vector

            arr.reserve(50); //Reserve memory space for the vector

            arr.shrink_to_fit(); //Frees up unuszed memory
        
        //5) Transforming Elements

            //transform(arr.begin(), arr.end(), [] (int a) { return a*5; }); //Applies the given function to all elements of the vector

            //std::replace(start,end,oldvalue,newvalue)
            //std::fill(start,end,value)

            std::unique(arr.begin(), arr.end()); //Removes consecutive duplicates

    }

    void ArraysInCPP() {
        int index = 0;
        //Static arrays, they live on the heap

        T arr[5] oldArray; //C style arrays DONT USE => code smell, decays to pointer no size or bounds checking
        std::array<T,5> coolArray; //knows its size, bounds checking

        //OPERATIONS

            //Value access:
            coolArray.at(index);
            coolArray[index];
            coolArray.front();
            coolArray.back();

            //Capacity:

            coolArray.empty(); //returns bool
            coolArray.size(); //ACTUALLY KNOWS ITS SIZE
            coolArray.max_size(); //returns max size

            //Operations:
            
                //std::fill(start,end,value)
                //std::swap(coolVec1, coolVec2) //swapp array elements
            
    }

    void LinkedListsInCPP() {   

        struct Node {
            T data;
            Node* next;
        };

        Node* n1 = new Node{10,nullptr};
        Node* n2 = new Node{20,nullptr};
        n1->next = n2; //Linking the nodes together

    }

    void MapsInCPP() {

        std::map<int, char> map_example = {{0,'4'}, {1,'5'}}; 
        //Stores key-value pairs in order based on their keys => since they need to sort they are slower
        //They use red-black trees to implement
        //Takes O(log n) time for inserting-accesing-deleting an element

        std::unordered_map<int, char> unordered_map_example = {{0, '4'}, {1, '5'}};
        //Stores key-value pairs WITHOUT order => faster
        //They use hash tables to implement
        //Takes O(1) time for inserting-accesing-deleting an element

        //ACCESING

        char charAt0 = map_example[0];
        charAt0 = map_example.at(0);

        //UPDATING

        map_example[0] = 'B'; //while using this to check such as if (map_example[0]) {} => this will actually add to the map if its not in it with a value of 1
        map_example.at(0) = 'C';

        //OPERATIONS

            //INSERT:
            map_example.insert({2, '6'}); // if there is already a 2 key in the map it just wont do this action
            //so you should use this instead
            map_example.insert_or_assign(2, '6');

            //SEARCHING 
            
            SearchFunction();
            
            //ITERATING

            for (auto it = map_example.begin(); it != map_example.end(); it++) {

                std::cout<< it->first << it->second;

            }
            
            //DELETING
            
            map_example.erase(0);
            //OR
            map_example.erase(map_example.begin());

            //OTHER OPERATIONS

            map_example.size();

            map_example.clear();

            map_example.count('5'); //Returns 0 or 1

        }

    void StacksInCPP() {
        int value = 0;
        //LIFO, we have 3 stack types in C++:
        std::stack<int, std::vector<int>> vecStack; //Implemented via vectors, fastest, cache friendly but has to realocate while growing sometimes
        std::stack<int, std::deque<int>> defaultStack; //Implemented via both LL and arrays, no realocate problem but slower than vectors //DEFAULT
        std::stack<int, std::list<int>> llStack; //literally no reason to use

        //Operations:

            defaultStack.push(value); //Add last element
            defaultStack.emplace(value); //Add last element
            defaultStack.pop(); //Remove last element
            int top = defaultStack.top(); //Returns last element
            bool isEmpty = defaultStack.empty();
            int size = defaultStack.size();

    }

    void QueueInCPP() {

        int value = 0;
        //FIFO, we have 2 queue types in C++:
        std::queue<int, std::deque<int>> defaultQueue; //Implemented via both LL and arrays, no realocate problem but slower than vectors //DEFAULT
        std::queue<int, std::list<int>> llQueue; //literally no reason to use

        //Operations:
            defaultQueue.push(value);    // add to BACK
            defaultQueue.emplace(value); // add to BACK in place
            defaultQueue.pop();          // remove from FRONT
            int front = defaultQueue.front(); // peek at FRONT
            int back = defaultQueue.back();   // peek at BACK
            defaultQueue.empty();
            defaultQueue.size();

    }

};  