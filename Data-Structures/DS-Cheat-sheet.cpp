/*

*DATA STRUCTURES AND ALGORITHMS CHEAT SHEET*

//////////////////////////////////////////////////////////////

**DATA STRUCTURES**

//////////////////////////////////////////////////////////////

1)ARRAYS
    
    DECLARATION:
    
        data_type array_name[array_size] = {elements}; || data_type array_name[] = {elements}; || data_type array_name[array_size] = {0};
    
    METHODS:

        - array_name[index]: Access element at specific index. 
        - sizeof(array_name) / sizeof(array_name[0]): Get the size of the array.
        - sort(array_name, array_name + array_size): Sort the array (requires #include <algorithm>).
        - reverse(array_name, array_name + array_size): Reverse the array (requires #include <algorithm>).
        - fill(array_name, array_name + array_size, value): Fill the array with a specific value (requires #include <algorithm>).
        - find(array_name, array_name + array_size, value): Find an element in the array (requires #include <algorithm>).
        - delete[] array_name: Deallocate memory for dynamic arrays.

    RANDOM BS:

        - The array name can be treated as a constant pointer that stored the memory address of the first element of the array.
        - Arrays are passed to functions using pointers, as the array name decays to a pointer to the first element. So, we also need to pass the size of the array to the function


2)LINKED LISTS

    DECLARATION:

        struct Node {
        
        // Data field - can be of 
        // any type and count
        int data;
        
        // Pointer to the next node
        struct Node* next;
        }

    RANDOM BS:

        - 3 types: Singly Linked List, Doubly Linked List, Circular Linked List

3)STACKS

    DECLARATION:

        stack<data_type> stack_name;

    METHODS:

        - push(element): Add an element to the top of the stack.
        - pop(): Remove and return the top element of the stack.
        - top(): Return the top element.
        - empty(): Check if the stack is empty.
        - size(): Return the number of elements in the stack.

4) QUEUE 

    DECLARATION:

        queue<data_type> queue_name;

    METHODS:
        - push(element): Add an element to the rear of the queue.
        - pop(): Remove and return the front element of the queue.
        - front(): Return the front element.
        - back(): Return the rear element.
        - empty(): Check if the queue is empty.
        - size(): Return the number of elements in the queue.
        - swap(queue_name): Swap the contents of two queues .
        - push_range(start_iterator, end_iterator): Add a range of elements to the rear of the queue.

5)Hash Tables / Maps

    DECLARATION:
        
        unordered_map<key_type, value_type> hash_table_name;
        map<key_type, value_type> ordered_map_name; //ordered version (slower performance O(log n))

    METHODS:

        - insert(key,data): Add an element to the map
        - at(key) || [key] : Access element by key
        - at(key) = new_value || [key] = new_value : Modify element by key
        - find(key): Find element by key => returns iterator to element or end() if not found
        - erase(key): Remove element by key
        - empty(): Check if the map is empty
        - size(): Return the number of elements in the map
        - clear(): Remove all elements from the map
        - contains(key): Check if the map contains a key (C++20 and later)
        - count(key): Returns 1 if key exists, 0 otherwise

6) Hash Sets / Sets 

    DECLARATION:
        
        unordered_set<value_type> hash_set_name;
        set<value_type> ordered_set_name; //ordered version (slower performance O(log n))

    METHODS:

        - insert(data): Add an element to the set
        - next(begin_iterator,elementIndex): Getting a specific element by index
        - find(data): Find element => returns iterator to element or end() if not found
        - erase(data): Remove element
        - empty(): Check if the set is empty
        - size(): Return the number of elements in the set
        - clear(): Remove all elements from the set
        - Traversing => for (const auto& element : set_name) { //access element }

7) Trees

8) Heaps

9) Graphs

*/