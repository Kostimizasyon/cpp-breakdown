#include "cheat-header.h"

struct OOPInCPP {
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

        //Its literally the same as classes: use when you dont need OOP practices

        
    }   
    
    void ClassesInCPP() {

        //Classes are just classes but their syntax are a lil different
        //Also you need to publicise your inheritence as they are private by default

        //Syntaxes:

        //Constructor Syntax
        class ConstructorSyntax {
            private:
                std::string first;
                std::string last;
            public:
                ConstructorSyntax(const std::string first,const std::string last): first(first), last(last) {}

                ConstructorSyntax(const std::string first,const std::string last) {
                    this->first = first;
                    this->last = last;
                }

                virtual ~ConstructorSyntax() {
                     //destruction, we NEED virtual so we can tell our children to handle their own data aswell
                    std::cout << "Class deleted!";

                }

                virtual void print() { std::cout<< "This is Constructor call"<<std::endl; }; //virtual is a good practice as it will get the compiler to yell at you if you change soemthing but you dont "need need" it  
        };

        //Super Syntax
        class SuperSyntax : public ConstructorSyntax {
           private:
                std::string a;
                std::string b;
            public:
                SuperSyntax(std::string first,std::string last,std::string a,std::string b) : ConstructorSyntax(first,last), a(a), b(b) {}

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

    void ExplicitKeyword() {

        //In c++ our compiler is allow to do exactly ONE implicit type conversion to resolve the parameters for a function on compile time, so an example like:
        
        class String {
            public:
                String(int n); //reserving memory for our string
                String(const char *p); 
        };

        //Now since the language is fucking stupid
        String myStr = 'x'; // WONT WORK -> it will cast our char into a int and use it to allocate memory
        //To avoid this we use EXPLICIT


        class String {
            public:
                explicit String(int n); // ONLY ACCEPTS INTS
                String(const char *p);
        };   

        String mySt = 3.14; //Caviat, now this WONT work as it will try double -> int -> string 2 conversions ERROR

    }

};