#include "cheat-header.h"

//--- CPP CHEAT SHEET ---
template <typename data_type>
struct GeneralLogic {

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

                        //

                    //3)Const Cast:

                    //4)Reinterpet Cast:

    }

    void AttributesInCPP() {

        //Attributes are used in c++ to enforce constraints on the code, give additional info to the compiler for optimizaation, supress or express certain warnings

        //1) NORETURN => Lets the compiler optimize better for void functions or generate better warnings

        [[noreturn]] void f() {}
        int a = f(); //Will give warning

        //2) DEPRACTED => makes the compiler throw a warning message saying that the releated thing is depracted
        //Can work on functions, namespaces, structs, classes, variables.

        [[deprecated("CAN OVERFLOW")]] void gets() {}

        //3) NODISCARD => makes the compiler throw a warning to the caller saying that this functions return should be utilized

        [[nodiscard]] int h() {return 0;}
        h(); //will give warning

        //4) MAYBE_UNUSED => supresses the compilers error about unused stuff

        [[maybe_unused]] const char a = 'b';

        // 5) FALLTHROUGH — intentional fall through switch cases
        switch(x) {
            case 1:
                [[fallthrough]];  // ✅ semicolon needed
            case 2:
                break;
        }

        // 6) LIKELY / UNLIKELY — branch prediction hint
        switch(x) {
            [[likely]] case 1:    // ✅ hint: this case is most common
                break;
            [[unlikely]] case 2:  // ✅ hint: this case is rare
                break;
        }

        // 7) NO_UNIQUE_ADDRESS — lets compiler reuse memory for empty members
        struct Empty {};
        struct Foo {
            [[no_unique_address]] Empty e;  // takes 0 bytes instead of 1
            int x;
        };
    }

};



