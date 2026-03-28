#include "cheat-header.h"

template <typename data_type>
struct Keywords {

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

    void TemplateKeyword() {
        
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

    void DefineKeyword() {

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

        //TLDR: BASICALLY USELESS JUST USE "\n"

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

        //TLDR: BASICALLY DEPRECATED YOU WILL ALMOST ALWAYS USE unique_ptr

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

    void SwapKeyword() {

        int value1,value2 = 0;

        //need #include <algoritm>

        //Swaps the values of two variables, supports almost ANY data type.

        std::swap(value1,value2);
        //Literally can work on anything arrays,classes,vectors...

    }

    void optionalType() {
        bool found = false;
        int value = 0;
        //TLDR: Error handling without cryptic return values

        //Our problem, whenever a function/variable is tied to lets say something like an API call, there is a chance that it will fail / have an error and we wont get the value
        //we were expecting, it used to be solved like this:

        int fetchApi() { //or updating a value by reference with a bool function or even returning a pair with bool,int
            if (!found) return -1; //Imply error
            return value;
        }

        //But with optional we can fix this:

        std::optional<int> findPlayer() {
            if (!found) return nullopt;
            return index;
        }

        std::optional<int> player = findPlayer();

        //OPERATIONS //Optional is essentially a pointer
            
            //ACCESS
                std::cout << *player << player->member; //BAD PRACTICE, undefined if empty
                std::cout << player.value(); //GOOD PRACTICE, throw if empty
                std::cout << player.value_or(0); //fallback to 0 if empty
            //CHECK
                if (player) {}
                if (player.has_value()) {}
            
    }

    void expectedType() {

        bool found = false;
        int value = 0;
        //TLDR: Error handling with proper returns

        //Our problem: we have a function with a chance for an error ,for example a calculator program with user input, and we want to tell the user what is wrong, for this 
        //we use expected

        std::expected<int, std::string> divide(int a, int b) 
        {

            if (b == 0) return std::unexpected("Division by zero");
            return a / b;

        }
        //Expected has two parts => our first value that we expect to return, then a unexpected return value basically an error

        auto result = divide(9,8);

        //OPERATIONS //Expected is essentially a pointer
            
            //ACCESS
                std::cout << *result; //BAD PRACTICE, undefined if empty
                std::cout << result.value(); //GOOD PRACTICE, throw if empty return expected value
                std::cout << result.error(); //Return unexpected value
                std::cout << result.value_or(0); //fallback to 0 if empty
                std::cout << result.error_or("idk"); //fallback to idk if empty
            //CHECK
                if (result) {} else { std::cout << result.error(); }
                if (result.has_value()) {}

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

};