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

                        //

                    //3)Const Cast:

                    //4)Reinterpet Cast:

    }

};



