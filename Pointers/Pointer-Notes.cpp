/*
 * ========================================
 * POINTERS & REFERENCES
 * ========================================
*/

// POINTERS
// --------
// Store the address of variables or memory locations
// Incrementing a pointer => moving along memory addresses
//
// Syntax:
//   data_type* pointer_name;           // Declaration
//   pointer_name = &variable_name;     // Initialization
//   *pointer_name;                     // Dereferencing (access value)


// REFERENCES
// ----------
// An alias (another name) for an existing variable

// Can be used to pass into a function as a const to save memory
// Cant be null, and must be initialized at declaration. Once set, it cannot be changed to refer to another variable (unlike pointers).
//
// Syntax:
//   data_type& reference_name = variable_name;
//
// Note: Changes in the original variable affect the reference and vice versa.
//       Use references in function parameters to modify the original variable.


// POINTERS vs REFERENCES
// ----------------------
// Feature                Pointer                          Reference
// -------                -------                          ---------
// Definition             Stores memory address            Alias for existing variable
// Declaration            Uses *                           Uses &
// Initialization         Optional                         Must be at declaration
// Null Value             Can be NULL/nullptr              Cannot be null
// Reassignment           Can point to another variable    Cannot be reassigned
// Memory Address         Has its own address              Shares variable's address
// Dereferencing          Requires * operator              Not needed
// Usage                  Dynamic memory, arrays           Function parameters, overloading
// Safety                 Less safe (dangling pointers)    Safer option
