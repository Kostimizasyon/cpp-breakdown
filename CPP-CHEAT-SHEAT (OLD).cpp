#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
template <typename data_type>

//--- CPP CHEAT SHEET ---

    void LambdaExpression() {

        //The lambda expression lets us use functions inside functions in cpp with the following snytax:

        //1) Literally defining a function inside a function:


        //we say auto as the compiler will assign a special class to lambda expressions we cant type it ourselves
        // -> is optional even if you are returning a data type

        auto functionName = [] (data_type parameters) -> void { //function body };
            //functionbody
        };

        /*      [] (The Capture Clause Types)
        
        The capture clause has 4 types that will change the way we can use the variables in the lambda expression:

        [] => the expression can only use the variables passed as parameters
        
        [=] => the expression will capture everything by value (will make a copy), so we can use outside variables but we cant change the originals

        [&] => the expression will capture everything by reference, so we can use outside variables and change the originals 
        
        */

    }

    void Template() {
        
        //Templates helps us so that we can write a code that works for any data type without rewriting each type
        //We can use templates to: (They cannot be declared in a function they have to be global (includes main))
        
        //We can give them default parameters, also define multiple at once:

        #if 0

        template <typename T1,typename T2 = double,typename T3 = std::string> //If they dont specify think of T2 as a double

        //They can also take arguments that arent data types, consts etc => for example getting the minumum of a static array (needs length too)

        template <typename T,int length> int arrMin(T arr,int length) {

            //function body

        }

        #endif


        //1) Create Function Templates:
        #if 0

        template <typename T>
        data_type add(T a, T b) {
            return a + b;
        }

        //We actually can use lambda expressions to do the same thing without using templates

        auto add = [] (auto a, auto b) -> auto {
            return a + b;
        };

        #endif
       
        //2) Class Templates: (Usefull for when creating a class that is independent of data types such as linkedlists etc)

        #if 0

        template <typename T>
        class LinkedList {

            T x;
            T y;

        }

        #endif

        //3) Variable Templates: (C++14 and later)

        #if 0

        template <typename T> 
        constexpr T pi = T(3.1415926535897932385); //This will create a variable that can be used for any data type:

        cout << "Pi as float: " << pi<float>;
        coust << "Pi as double: "<< pi<double>;

        #endif



    }

    void Define() {

        //They have to be defined before the main function and at the core of the program
        // Define keyword is a preprocessor directive that allows us to create aacros,
        // meaning we tell the compiler to basically find and replace our macros with their corresponding values
        // DONT USE ;
        // we have 5 types of macros that we can define:

        #ifndef 0        

        // 1) Macro Constants

            #define PI 3.145678
        
        // 2) Chain Macros => linked macros basically int x = a;

            #define AREA PI
            #define PI 3.1475645

        // 3) Macros  => basically just functions 
        
            #define SQUARE(x) ((x) * (x)) 

        // 4) Macro Expressions:

            #define forLoop(len) for (int i =0;i<len;i++) 

        // 5) Multiline Macros

            #define FACT "Talha \
            is \
            gay"

        #endif

    }

    void PointersandReferencesInCpp() {

        // POINTERS
        // ----------
        // Doesnt have to be initilized,can be null (nullptr),can be reasigned,has its own spot in memory
        // ----------
        
        
        //Pointers store the address of variables or memory locations, they are straight up memory locations and depending on the data type they point to,
        //they can be incremented to move along the memory adresses (as something like a vector holds its elements in sequential memory locations)

        int variable_name = 5;
        
        int* pointer_name = nullptr; //Declaration (BEST PRACTICE IS TO NULIFY ON DECLARATION)
        pointer_name = &variable_name; //Initialization
        *pointer_name; //Dereferencing (accessing value, would be 5)

        std::cout << "Pointer: " << pointer_name << "\n";
        std::cout << "Pointer value: " << *pointer_name <<"\n";

        //we also use -> instead of . when dealing with pointers

        pointer_name = nullptr; //Nullifying the pointer (good practice to avoid dangling pointers) (NEVER USE NULL OR 0 ON A POINTER TO NULIFY)


        // REFERENCES
        // ----------
        // Has to be initilized on declaration, cannot be null, cannot be reasigned, shares the same memory adress as its reference.
        // ----------

        //An alias for an existing variable

        int original_variable = 10;

        int& reference_variable = original_variable; //Declaration and initialization,has to be initilized

        std::cout << "Reference value: " << reference_variable << "\n";

        reference_variable++; //Any change in the reference will affect the original value and vice versa
        std::cout << "Original variable after incrementing reference: " << original_variable << "\n";
        original_variable++;
        std::cout << "Reference variable after incrementing original: " << reference_variable << "\n";

                
        //FUNCTION PASSING

            #if 0
            
            // 1. Pass by Value (Makes a slow copy, original is untouched)
            void tryToChange(int x) { x = 99; } 

            // 2. Pass by Reference (Fast, modifies the original directly. Modern C++ favorite!)
            void changeWithRef(int& x) { x = 99; } 

            // 3. Pass by Pointer (Fast, modifies original, but requires null-checks and dereferencing)
            void changeWithPtr(int* x) { 
                if (x != nullptr) { // Always check for null!
                    *x = 99; 
                }
            }

            #endif

            //Memoery cheat
            //If we have a really big varaible to pass to a function we can use a const reference, which will make sure no copy is made to the original variable (no memory)
            //and that the original variable isnt modified
            #if 0
            std::vector<int> REALLYBIGVECTOR;

            int returnFirstValue(const int& REALLYBIGVECTOR) {
                return *REALLYBIGVECTOR.begin()
            }

            #endif
    }

    void Iterators() {

        //An iterator is an object that acts like a pointer that allows us to traverse and acsess elements of a container
        //They allow us to traverse the container without exposing internal structure

        std::vector<int> exampleVector = {1,2,3,4,5};
        std::vector<int>::iterator it = exampleVector.begin(); //This will create an iterator that points to the first element of the vector
        //auto it = exampleVector.begin(); //This will do the same thing but with less typing, the compiler will figure out the type of the iterator for us

        //Just like a pointer would, we can use iterators to access and modify the value they point to: (DEREFERENCING)
        std::cout << *it << "\n";
        *it = 100;
        std::cout << *it << "\n";

        //Once again just like pointers we can increment and decrement iterators to move through the memory:
        std::cout << "Incremented value: " << ++*it << "Decremented value:" << --*it << std::endl;

        //We can compare iterators that iterate through the same container.

        // -----        Methods that return iterators:      -------

        //Normal:
        exampleVector.begin(); //Returns an iterator to the first element
        exampleVector.end(); //Returns an iterator to the element after the last element (we use it to check if we reached the end or not)
        
        //Constants:
        exampleVector.cbegin(); //Returns a const iterator to the first element (cant change the value of the element)
        exampleVector.cend(); //Returns a const iterator to the element after the last element (cant change the value of the element)

        //Reverses (you get the jist its reverse ooooooooooooooo who would have thunk it):
        exampleVector.rbegin(); //Returns a reverse iterator to the first element
        exampleVector.rend(); //Returns a reverse iterator to the element after the last element 

        //Constant Reverses:
        exampleVector.crbegin(); //You get it by now
        exampleVector.crend();   //You get it by now

        // =====================================================
        //                  ITERATOR TYPES TABLE
        // =====================================================
        //
        // ┌─────────────────┬────────────┬─────────────┬────────────┬───────────┬─────────────────────────┐
        // │ Iterator Type   │ Read/Write │ Forward (++)│ Back (--)  │ Jump (+5) │ Example Container       |
        // ├─────────────────┼────────────┼─────────────┼────────────┼───────────┼─────────────────────────┤
        // │ Input / Output  │ One or the │     Yes     │     No     │     No    │ Streams (cin, cout)     │
        // │                 │    other   │             │            │           │                         │
        // ├─────────────────┼────────────┼─────────────┼────────────┼───────────┼─────────────────────────┤
        // │ Forward         │    Both    │     Yes     │     No     │     No    │ std::forward_list       │
        // ├─────────────────┼────────────┼─────────────┼────────────┼───────────┼─────────────────────────┤
        // │ Bidirectional   │    Both    │     Yes     │     Yes    │     No    │ std::map, std::set      │
        // ├─────────────────┼────────────┼─────────────┼────────────┼───────────┼─────────────────────────┤
        // │ Random Access   │    Both    │     Yes     │     Yes    │     Yes   │ std::deque              │
        // ├─────────────────┼────────────┼─────────────┼────────────┼───────────┼─────────────────────────┤
        // │ Contiguous      │    Both    │     Yes     │     Yes    │     Yes   │ std::vector, std::string│
        // └─────────────────┴────────────┴─────────────┴────────────┴───────────┴─────────────────────────┘
        
    }

    void EnumsInCPP() {

        //There are two ways to define enums old and one new:

        enum OldEnumExample {A,B,C = 5};

        enum class ModernEnumExample {D,E,F = 4};

        //Acsessing an enum value:

        ModernEnumExample EnumExample = ModernEnumExample::D;

        std::cout<< static_cast<int>(EnumExample); 
        //This value will be 0 because D is the first value in the enum and it starts counting from 0, E will be 1 and F will be 4 because we set it to 4    
        //If D was something else, for example 2 then we would start counting up from there and E would be 3, F wouldnt change as it is defined


        #if 0
        std::cout<< EnumExample; // Compiler Error as the enums are not defined to anything in the class definition
        #endif

        //                                               PROBLEMS OF THE OLD DEFINITION
        
        
        //First problem of the old definition:
        
       
        enum OldEnumFaulty {X,Y,Z}; //Because they dont act like containers, it will act like A,B,C are a taken namespace on the first defination and this will throw an error
        enum class ModernEnumStillWorking {D,E,F}; //Still works

        //Second problem of the old definition:

        //In the old definition, the values of the enum are implicitly converted to integers, so you can do something like this:
        
        int a = A; //This will work and a will be 0, but this can lead to bugs if you accidentally assign an enum value to an integer variable

    }

    void UsingKeyword() {

        //                                                       --USECASES--

        //1)Allows the developers to specify the use of a particular namespace
        
        using namespace std; //Tells the compiler => If you see something undefined, go into the std definitions and check if it exists there
        //This is a bad practice because if you try cout => it will go through the entire std namespace entirely,so the better practice is to only do the spesific ones you will use
        using std::string; 

        //2)Type Alliasing 

        using ListofString = std::vector<std::string>;
        ListofString stringVector = {"this","is","a","vector","of","strings"};

        //3)Class Inheritence => in OOP C++, if a base class has an overloaded function the child inheriting these,if it only overrides one function it will hide the other.
        
        class Base {
            public:
                void print(double);
                void print(int);
                Base() {}
        };

        class Child : public Base {

            public:
                using Base::print; //This will allow the child class to use the print function with double and int parameters without hiding one of them
                void print(int); //This will overload the int print in the parent

                using Base::Base; //This will allow the child class to use the constructor of the parent without typing it out 

                

        };

    }

    void RightAndLeftValues() {
    
       /*
       
        Left Values (Also know as Locators) => they are actually located in the memory so they can be pointed to and refernced to

        normal variables
       
       */
       int x = 5; //(l value);

       /*
       
       Right Values (Also know as Read-only)

       They are referenced via && instead of &

       They arent actually in the memory so they arent stored in anyway shape or form

       
       */
        int y = x+5; //(x+5 is an rvalue while y is an l value);
        int&& rValueReference = x+5; //(rvalue reference)

        //Some other things that will return an rvalue::

        auto RValueReturner = [&] () -> std::string {
            return "this is an rvalue"; //Thi)s will create an rvalue that will last in the memory long enough to be assigned to a value
        };

        #if 0
        std::move(/*parameters*/); //Will cast the parameter passed into an rvalue;
        #endif

        static_cast<int>(5); //Will cast the parameter into an rvalue;

    }

    void Structs() {

        //Basically just classes with 2 differences => Public by default, and inheritences are also public by default;
        //If your object doesnt have complex logic or need to protect its data, use a struct.

        struct Coords {
            //public: present at all times
            int X;
            int Y;
            int Z;

            Coords() {
                X = 1;
                Y = 2;
                Z = 3;
            }

            ~Coords() {
                std::cout<< "Destroyed coords" << "\n";
            }

        };

        //Its literally the same as classes:

        
    }   
    
    void ClassesInCPP() {

        //Classes are just classes but their syntax are a lil different
        //Also you need to publicise your inheritence

        //Syntaxes:

        //Constructor Syntax
        class ConstructorSyntax {
            private:
                std::string first;
                std::string last;
            public:
                ConstructorSyntax(std::string first,std::string last): first(first), last(last) {}

                ConstructorSyntax(std::string first,std::string last) {
                    this->first = first;
                    this->last = last;
                }

                virtual void print() { std::cout<< "This is Constructor call"<<std::endl; } //virtual is a good practice as it will get the compiler to yell at you if you change soemthing but you dont "need need" it  
        };


        //Super Syntax
        class SuperSyntax : public ConstructorSyntax {
           private:
                std::string a;
                std::string b;
            public:
                SuperSyntax(std::string first,std::string last,std::string a,std::string b): ConstructorSyntax(first,last), a(a), b(b) {}

        };

        //Ovverride Syntax
        class OverrideSyntax : public ConstructorSyntax {
            public:
                using ConstructorSyntax::ConstructorSyntax; 
                void print() override { std::cout<< "This is Override call"<<std::endl; };
        };


        //PolyMorphism Example
        auto polyMorphismExample = [] () -> void {

            // --- The Wrong Way (Object Slicing) ---
                std::vector<ConstructorSyntax> exampleVector = {};

                ConstructorSyntax a("first", "last");
                OverrideSyntax b("first", "last");

                exampleVector.push_back(a);
                exampleVector.push_back(b); // 'b' gets "sliced" into a base object here

                std::cout << "--- Wrong Way ---" << '\n';
                for (ConstructorSyntax c : exampleVector) {
                    c.print(); // Prints: 2 "This is Constructor call"
                }

                // --- The Correct Way (Pointers) ---
                std::vector<ConstructorSyntax*> exampleVector2 = {};

                // FIX: You must use the '&' operator to get the memory addresses of a and b!
                exampleVector2.push_back(&a);
                exampleVector2.push_back(&b);

                std::cout << "\n--- Correct Way ---" << '\n';
                for (auto* c : exampleVector2) { // 'auto*' makes it clear it's a pointer
                    c->print(); // Prints: 1 "Constructor call", 1 "Override call"
                }
        };

        /*                          General OOP stuff 
        
        static => tie something to the CLASS ITSELF 

            Encapsulation => the class protecting itself

            Abstraction => keeping the ugly side out => abtract classes

            Inheritance =>  Inheritence

            Polymorphism => Using a parent class to refer to a child Employee* e1 = &developer1; => employee has a work function put virtual at the start and it will check if the developer also has it defiend (POINTERS ARE IMPORTANT)
        
        */

    }

    void ConstexprKeyWord() {

        //Used to optimize values, lets the const expression be defined and computed on compile time instead of run time

        constexpr auto square = [=] (int x) -> int {
            return x * x;
        }; 

        //Functions should ONLY refer to global variables
        //These functions can only call other constexpr functions
        //The function shouldnt be void (duh)

        constexpr int preRunTimeValue = square(25);

    }

    void EndlKeyword() {

       // In C++, we have \n and std::endl for newlines.

                std::cout << "Fast newline\n";
                std::cout << "Slow newline" << std::endl;

                // Differences between \n and endl:
                // 1. '\n' just adds a newline character to the buffer.
                // 2. std::endl adds a newline character AND forces the buffer to flush immediately. => endl is literally std::cout<<"\n"<<std::flush();

                // Best Practice: Always default to '\n' unless you need immidiete output to console. 
                // Flushing the buffer is a very slow process. Let the OS handle it!

                // Example of where endl completely destroys performance:
                for (int i = 0; i < 100000; i++) {
                    // std::cout << "Test" << std::endl; // HORRIBLE! Asks the OS to draw 100,000 separate times.
                    std::cout << "Test\n";               // GREAT! Groups text together and draws in fast, large chunks.
                }

        //Buffer => CPU fast af, monitor and other parts are really slow in comparison so we use a truck (buffer) and load our outputs into the truck.
        //Flush => Send the truck to its destination.

        //So endl would send 100000 trucks while \n would load everything into one truck and only send that (A LOT MORE EFFICIENT MEMORY/RUNTIME WISE)

    }

    void NewKeyword() {

        //In coding we have two types of memory: stack and heap

        //Stacks have automatic lifetime
        int y = 10;

        //While heaps are manually managed in their lifetime
        int* x = new int; //Allocates memory in the heap for one int.
        //To remove them from the memory we use the delete keyword
        delete x;
        //Even when we delet them from the memory, they still point to a memory spot, we need to nullify them
        x = nullptr;

        //New is used best when:

        //You dont know how much memory you will need in advance
        //You want to create memory while program is running, based on input for example
        //You need to store large amounts of flexible data


    }

    void LinkedListsInCPP() {   

        struct Node {
            int data;
            Node* next;
        };

        Node* n1 = new Node{10,nullptr};
        Node* n2 = new Node{20,nullptr};
        n1->next = n2; //Linking the nodes together

    }

    void Vectors() {
        int value = 5;

        std::vector<int> vec = {};

        //Vectors are dynamic arrays for c++
        
        std::vector<int> arr = {};

        //Operations:

        //1)Insertion:

            arr.push_back(5); //:: Inserts an elemnt at the end of the vector very fast, O(1)

            //Takes a iterator to point to index
            arr.insert(arr.begin()+1,9); //:: Insert an element at a spesified position, slow => O(n)

            std::fill(arr.begin(), arr.end(), value); //Fill the vector with the value
    
        //2)Access Elements:

            arr[1]; 
            //or , both O(1)
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
        
        //5) Trans forming Elements

            transform(arr.begin(), arr.end(), [] (int a) { return a*5; }); //Applies the given function to all elements of the vector

            //std::replace(start,end,oldvalue,newvalue)
            //std::fill(start,end,value)

            std::unique(arr.begin(), arr.end()); //Removes consecutive duplicates

    }

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

    void Swap() {

        int value1,value2 = 0;

        //need #include <algoritm>

        //Swaps the values of two variables, supports almost ANY data type.

        std::swap(value1,value2);
        //Literally can work on anything arrays,classes,vectors...

    }

    void TypeModifiersInCPP() {

        //In c++ we have 4 type modifiers:
        
        //1 Signed: Indicates that the given type will use one bit to indicate its sign (+/-)
        // Can be applied to -> int,char and other modifiers (that isnt unsigned)

        signed int signed_int;     // -2147483648 to 2147483647
        signed char signed_char;   // -128 to 127


        //2 Unsigned: Instead of dedicating a bit to a sign, instead we use it to also display a number letting it display bigger numbers but cant be negative
        // Can be applied to -> int,char and other modifiers (that isnt signed)

        unsigned int unsigned_int;   // 0 to 4294967295 
        unsigned char unsigned_char; // 0 to 255

        //3 Short: Decreases the size of the data type in the memory by half, leading to less numbers but less memory
        // Can only be applied on ints

        short int short_int;        //  -32768 to 32767 
        std::cout << sizeof(short int) << "\n"; // 2 bytes instead of 4
        
        //4 Long: Increases the size of the data type in the memory by double, leading to less numbers but less memory
        // Can be applied to -> int,doubles and other modifiers (that isnt long long)

        long int long_int;          // -9223372036854775808 to 9223372036854775807
        std::cout << sizeof(long int) << "\n"; // 8 bytes instead of 4

        unsigned long int unsigned_long_int; // 0 to 18446744073709551615

        long double long_double;  //TOO HIGH
        std::cout << sizeof(long double ) << "\n"; // 16 bytes instead of 8
        
        //-------------------OVERFLOW----------------------

        //The act of overflow is about bits => 1111 lets say this is our limit for a number, if we were to add +1 => if we only have 4 bits to hold numbers it would be 0000
        //so our value would reset to 0;

        unsigned char a = 255;
        std::cout << a + 1 << "\n"; //This will print 0 because of overflow.

        //Now for signed cases since we preserve one bit for the sign, 0111 would be our max value, if we were to add +1 => 
        //overflow would cause the sign bit to flip and the number would become the negative max of our data type

        signed char b = 127;
        std::cout << b+1 << "\n";  //This will print -128 cuz of overflow 

    }

    void TypeConversionInCPP() {
        double x = 5.0;
            //Type conversions are the act of converting a data type to another data type such that it wont lose meaning

            //In c++ we have 2 types of type conversions:

            //1) Implicit Type Conversion (coercion) => Is the act of the compiler automatically, cases of coercion:
            
                //a)Hierarchy => when doing operations with two different types, the compiler will always pick the higher order one to convert the result to:
                //bool -> char -> short int -> int ->  unsigned int -> long -> unsigned -> long long -> float -> double -> long double

                int intiger1 = 1;
                double double1 = 2.0;

                auto result = intiger1 + double1; //the result will be a double

                //b)Pointer => (upcasting) 

                class Animal { public: void eat() {} };
                class Dog : public Animal { public: void bark() {} };

                Dog* myDog = new Dog();
                Animal* myAnimal = myDog; // Implicit conversion: Dog* to Animal*

                myAnimal->eat(); // Works fine
                // myAnimal->bark(); // Error: Animal class has no bark() method

                //c)Boolean Conversion

                if (intiger1) {}
                if (!nullptr) {}
 
            //2)Explicit Type Conversion => Also know as type casting, is type conversion by the developer themselves with code:

                //a)C Style Type Casting
                
                (int /* any data type */) x;//variable name

                //b)C++ Style Type Casting

                    //1)Static Cast:

                        //Standard compile type conversions
                        
                        static_cast<int>(x);

                    //2)Dynamic Cast:

                    //3)Const Cast:

                    //4)Reinterpet Cast:






    }
