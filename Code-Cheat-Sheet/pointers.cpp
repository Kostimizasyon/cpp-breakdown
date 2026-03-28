#include "cheat-header.h"

struct Pointers {

        void PointersandReferencesInCpp() {

        // POINTERS
        // ----------
        // Doesnt have to be initilized,can be null (nullptr),can be reasigned,has its own spot in memory
        // ----------
        
        
        //Pointers store the address of variables or memory locations, they are straight up memory locations and depending on the data type they point to,
        //they can be incremented to move along the memory adresses (as something like a vector holds its elements in sequential memory locations)

            //RAW POINTERS
            //
            //Raw pointers have to manage require the developer to manage their memory usage, and lifecylcle (basically never use them) (they DONT own the object they point to)

            int variable_name = 5;
            
            int* pointer_name = nullptr; //Declaration (BEST PRACTICE IS TO NULIFY ON DECLARATION)
            pointer_name = &variable_name; //Initialization
            *pointer_name; //Dereferencing (accessing value, would be 5)

            std::cout << "Pointer: " << pointer_name << "\n";
            std::cout << "Pointer value: " << *pointer_name <<"\n";

            //we also use -> instead of . when dealing with pointers

            pointer_name = nullptr; //Nullifying the pointer (good practice to avoid dangling pointers) (NEVER USE NULL OR 0 ON A POINTER TO NULIFY)

            //SMART POINTERS
            //

                //[Unique Pointers] (https://www.geeksforgeeks.org/cpp/unique_ptr-in-cpp/) (https://en.cppreference.com/w/cpp/memory/unique_ptr.html)
                //Unique pointers have ownership over themselves and can manage their own memory, and since they are unique they cannot be copied only moved to another
                //unique pointer using std::move
                #include <memory.h>
                int args = 5;

                std::unique_ptr<data_type> ptr = std::make_unique<data_type>(args);
                std::unique_ptr<data_type> a_ptr (new args);

                //[Shared Pointers] () (https://en.cppreference.com/w/cpp/memory/shared_ptr.html)
                // CODE SMELL MOST OF THE TIME => basically a unique pointer that can have multiple owners
                
                std::shared_ptr<data_type> ptr = std::make_shared<data_type>(args);
                std::shared_ptr<data_type> a_ptr (new args);

            //SMART POINTER ARGUMENTS:::

            ptr.swap(a_ptr); //swap the pointer
            ptr.get(); //return a raw pointer to the referenced object
            ptr.release();//release the ownership of the referenced object, return a raw pointer and becomes null
            ptr.reset(); //DELETE object, become null
            a_ptr = std::move(ptr); //transfer ownership, become null
    


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


};