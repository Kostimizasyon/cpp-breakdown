/*

*DATA STRUCTURES AND ALGORITHMS CHEAT SHEET*
Algorithm => work with data :: Data Structure => store data
Inplace algorithm => no extra space used (memory wise like you dont create a new array or anything)
//////////////////////////////////////////////////////////////

Time complexity:: 

BİGGİE (

    ::Big O Notation (WORST CASE // LES THAN OR EQUAL TO) {

    O(1) => Constant Time => a[5] => We know where it is

    O(n) => Linear Time => Looping through an array

    O(log n) => Logarithmic Time => Binary Search (cut from half on a sorted array go till you find) (you need the sorting to be worth it)

    O(n**2) => Quadratic Time => Nested Loops - insertion sort

    O(n!) => Factorial Time (You are probably doing something wrong) => Permutations (ABC-BCA...)

    }

    ::Big Omega Notation (BEST CASE) {

        basically big O but for best case scenerios

    }

    ::Big Theta Notation (AVERAGE) {

        Used when best and wors case are the same;; => predictable

    }

)

LİL WAYNE (

::Lil O (LESS THAN) {

    Big o says that a function grows no faster than the other, while little o STRICTLY says that it grows SLOWER than the other.

    lim (F(n)/G(n)) = 0 (Where x goes to infinity)
}

::Lil Omega {

    Big omega says that a function grows no slower than the other, while little omega STRICTLY says that it grows FASTER than the other.

    lim (F(n)/G(n)) = infinity (Where x goes to infinity)

}

)
--------------------------------------------------------------------------------------------------------------------------------

Space Complexity::

Measure of memory used by and algorithm / data structure in terms of input size (n)

Everything is O(n) for data structures except for graphs

in-place => O(1)

--------------------------------------------------------------------------------------------------------------------------------

**DATA STRUCTURES**

//////////////////////////////////////////////////////////////

1)ARRAYS => int arr[5] = {};
    
    a) Static Array => size is fixed (declared at compile time)
    b) Dynamic Array => size can be changed (using pointers and dynamic memory allocation) => will double itself most of the time => BAD cuz it will copy old elements to new memory location and delete old one => use vector instead in C++

    They use memory mapping => sequential memory allocation => each element is next to each other in memory => each are 4 bytes apart (for int)
    
    PROS:
        - Fast access time (direct access using index)
        - Simple to implement
    CONS:
        - Fixed size (static arrays)
        - Insertion/deletion can be costly (elements need to be shifted)


    Big O:
        Access: O(1) (direct access using index)
        Deletion: O(n) (if deleting at specific position) / O(1) (if deleting at end, average case for dynamic array)
        Insertion: O(n) (if inserting at specific position) / O(1) (if inserting at end, average case for dynamic array)
        Traversal: O(n)



2)LINKED LISTS => Can be used in hash tables with same hashing index to store multiple values (chaining)

    Consists of nodes where each node contains data and a pointer to the next node.

    Deleting and inserting nodes will only update the related pointers, on the case of deletion it will change the pointer of the previous node 
    to the next node of the deleted one.

    PROS:
        - Dynamic size
        - Doesnt have to be sequential in memory
        - Efficient insertions/deletions (only pointers are changed)
    CONS:
        - Have to go through each node to find something (no direct access)
        - Extra memory for pointers
    
    Big O:
        Insertion: O(1) (if inserting at head) / O(n) (if inserting at tail or specific position)
        Deletion: O(1) (if deleting head) / O(n) (if deleting tail or specific position)
        Traversal: O(n)

3)STACKS => Last in first out (LIFO) (CALL STACK)

    The 2 key operations are push (add to top) and pop (remove from top)
    The stack only has a single pointer to the top of the stack, so you can only access the top element.
    Can be a array or a linked list implementation => since there are many ways to implement => abstract data type (ADT) => only care about the operations and not the implementation

    PROS:
        -Really fast
        -Memmory Efficient
    CONS:
        -Limited access (only top element)

    Big O:
        Push: O(1)
        Pop: O(1)
        Top/Peek: O(1)
        Traversal: O(n) (if needed)
        Size: O(1) => (it will keep track in the background)

4) QUEUE => First in first out (FIFO) => BUFFER

    The 2 key operations are enqueue (push) and dequeue (pop)
    The queue has 2 pointers, one for the front and one for the rear of the queue, so you can only access the front and rear elements.
    Can be a array or a linked list implementation => since there are many ways to implement => abstract data type (ADT) => only care about the operations and not the implementation

    PROS:
        -Really fast
        -Fair in processing (first come first serve)
    CONS:
        -Limited access (only front and rear element)

    Big O:
        Enqueue: O(1)
        Dequeue: O(1)
        Front/Peek: O(1)
        Traversal: O(n) (if needed)
        Size: O(1) => (it will keep track in the background)

5) HASH TABLE //MAYBE RESEARCH MORE 

    Practically a long array that will take a key and a value and store the value at an index determined by a hash function on the key.
    Keys can be anything as long as its hashable (string, int, float, custom objects with hash function defined)
    Collisions => when two values have the same key


    PROS:
        -GODLİKE SPEED
        -Efficient for large datasets

    CONS:
        -Extra memory usage (overhead)
        -No ordering, data is scrambled
        -Caching issues due to random access patterns 

    Big O:
        Insertion: O(1) average / O(n) worst case (if many collisions)
        Deletion: O(1) average / O(n) worst case (if many collisions)
        Search: O(1) average / O(n) worst case (if many collisions)

    RANDOM BS:
        - Load Factor => number of elements / number of buckets => when it exceeds a certain threshold (like 0.7) => rehashing (create a new larger array and reinsert all elements)
        - Collision Resolution Techniques => Chaining (linked lists at each index) / Open Addressing (find next available slot)

6) HASH SETS

    An array that stores only unique values, and the data will be hashed to determine the memory location to store the value. They are unordered because the memory is unordered

    PROS:
        - GODLİKE SPEED
        - Unique values only
        - Easy access for intersection, union, difference operations etc

    CONS:
        - Values have to be hashable => you can create your own hash function for custom objects to mitigate this
        - No random access to elements
        - Memory overhead
        - You cannot modify elements directly (have to remove and reinsert)

    Big O:
        Insertion: O(1) average / O(n) worst case (if many collisions)
        Deletion: O(1) average / O(n) worst case (if many collisions)
        Search: O(1) average / O(n) worst case (if many collisions)

7)TREES => File explorers, Databases

    Non linear data structure where nodes are organized in hierarchy.
    Top of the tree is the root node, rest are the leaf nodes, these can have multiple child nodes, but only one parent node (except for the root which has no parent).

    Subtree => a part of the main tree

    Size of a tree => number of nodes in the tree || depth of a node => number of edges from the node to the root || height of a node => the number of edges on the longest paht from the node to a leaf

    Balanced Tree => left and right heigths are basically the same => O(log n) for search, insertion, deletion
    Unbalanced(skewed) Tree => left and right heights are different => O(n) for search, insertion

    Traversing a tree: 

        *//*

    Tree Types:

        Binary Tree => each node has at most 2 children {
            Binary Search Tree => left child's value is less than the parent node, right child's value is greater
        }

        Trenary Tree => each node has at most 3 children

        N-ary Tree => each node has at most n children

    PROS:
        -Hierarchical data representation
        -Efficient for searching, insertion, deletion (if balanced)
        -Dynamic memory, ordered data structure

    CONS:
        -No random indexing
        -Memory overhead for pointers => every node needs a pointer to its children and possibly its parent
        -Complex
        -Like linked listes they are scattered in memory => caching issues

    Big O:
        Insertion: O(log n) average (if balanced) / O(n) worst case (if unbalanced)
        Deletion: O(log n) average (if balanced) / O(n) worst case (if unbalanced)
        Search: O(log n) average (if balanced) / O(n) worst case (if unbalanced)

8)HEAPS => used for heapsort and priority queues

    format it as an array

    Binary heaps /// nearly complete binary trees (every place is complete with 2 children except the lowest part of the tree [which is filled to a point starting from the left])

    Heap addition => add to the end of the tree and then compare with parent and swap if necessary (heapify up)
    Heap deletion => remove the root node and replace it with the last node, then compare with children and swap with the larger (for max heap) or smaller (for min heap) child if necessary (heapify down)

    Types:
    
        Max Heap => parent node is greater than or equal to its children => used for heapsort
        Min Heap => parent node is less than or equal to its children => used for priority queues

    PROS:
        -Efficient for finding min/max (O(1))
        -Since its basically an array its memmory efficient and has a good cache performance
        -A heap cannot become unbalanced or skewed
    
    CONS:
        -Poor search
        -Limited utility (only good for min/max and priority queues)
        -Expensive updates

    Big O:
        Min/Max: O(1)
        Insertion: O(log n)
        Delete Top: O(log n)
        Search: O(n) (since its not sorted, you have to go through each element)
        Heapify: O(n)        
    
9)GRAPHS

    A collection of nodes (vertexes) and edges (connection between them) 

    Connections => adjencency

    TYPES:

        Weighted Graph => edges have values (like distance, cost, etc)
    
        Directed Graph => edges CAN BE traversed both ways (two edges) => 
        Undirected Graph => edges have to be traversed both ways => facebook friends

    WAYS TO DISPLAY:

        Adjencency matrix => 2d array if (row a colum b = 1, then there is an edge between a and b) => O(1) to check edges but O(n^2) space complexity
        Adjencency list => linked lists for each vertex that stores its neighbors => O(n) time, O(n+e) space complexity (e = number of edges)
        
    TRAVERSE:
        
        *//*

    PROS:
        -Really flexable can do almost anything you want with it
        -Excellent for representing relationships and connections
    CONS:
        -Can be complex to implement and understand
        -Kinda memory heavy (especially with adjacency matrix)
        -Can have performance issues with large graphs (especially with adjacency matrix)
    
    Big O:
        Adjacency Matrix:
            Add Edge: O(1)
            Add Vertex: O(n^2) 
            Remove Edge: O(1)
            Check Edge: O(1)
            Space Complexity: O(n^2)

        Adjacency List:
            Add Edge: O(1)
            Add Vertex: O(1)
            Remove Edge: O(n
            Check Edge: O(n)
            Space Complexity: O(n + e) (where e is the number of edges)

--------------------------------------------------------------------------------------------------------------------------------

**ALGORITHMS**

//////////////////////////////////////////////////////////////

//SEARCHING ALGORITHMS//

A) Linear Search  => go through each element and check if its the target => O(n) time complexity , O(1) space complexity (no additional memory needed)

B) Sentinal Linear Search => same as linear search but you also put the target value at the end so you dont have to check if you are at the end every time 
=> O(n) time complexity , O(1) space complexity (no additional memory needed)

C) Binary Search => ONLY WORKS ON SORTED ARRAYS => Check middle element if its not equal to target, check if less or more then chop the list accordingly 
keep going until you find the target => O(log(n)) time compexity,O(1) space complexity (iterative) / O(log(n)) space complexity (recursive)

D) Ternary Search => ONLY WORKS ON SORTED ARRAYS => More advanced BS => check for 2 middle points, divide array to 3 parts => O(log3(n)) time complexity, 
O(1) space complexity (iterative) / O(log3(n)) space complexity (recursive)

E) Jump Search => ONLY WORKS ON SORTED ARRAYS => define a jump size (usually sqrt(n)) => jump through the array like arr[0],arr[jump],arr[2jump]... 
untill you find an element greater than your target => it means the target is between the last two jumps => do a linear search between the jumps =>
O(sqrt(n)) time complexity, O(1) space complexity (no additional memory needed)

//////////////////////////////////////////////////////////////

//SORTING ALGORITHMS//

// Stable Sort => if two elements are equal they will maintain their original order in the sorted array //

(LITERAL HELL ON EARTH O(n**2))

A) Bubble Sort  => loop through the list and compare each element with the next order and swap them according to the sort rule 
=> repeat until no swaps are needed => O(n**2) time complexity, O(1) space complexity (no additional memory needed)

B) Selection Sort(unstable) => loop through the list and find smallest elemnt put it in the first position, then find the next smallest compare to first element 
if its smaller swap them, if not compare to second element and so on => O(n**2) time complexity, O(1) space complexity (no additional memory needed)

C) Insertion Sort =>  Split list into two (theoratically), then assume that the list is sorted starting from the 2nd element => compare it to the first one
swap if needed => repeat for 3 going backwards as in you check 1 2 for 3 => O(n**2) TC, O(1) SC
/////////////////////////////////////

(Great Ones O(n log n))

A) Merge Sort (recursive) => Splits the array into halves until you have arrays of size 1 => uses the merge() method (which expectes two sorted arrays) to merge the 
arrays back together in the correct order

CON: O(n) space complexity

B) Quick Sort (recursive,unstable) => Uses the partition function, which picks a pivot element in the array and sorts it according to that pivot point 
(less on left, greater on right) => and then the partion function passes an "partioning index (index of pivot )" to the quickSort() function, 
which splits the array into two subarrays then recursively calls itself untill the array is sorted 

PRO: Actually faster in real life as its caching is EXTREMELY effective

CON: O(log n) space complexity (average case) / O(n) space complexity (worst case when the smallest or largest element is always chosen as the pivot)
CON: O(n**2) time complexity (worst case when the smallest or largest element is always chosen as the pivot)

C) Heap Sort (unstable) => First step, turn array into a max heap => Swap the root value with the last element in the list => Will heapify down the root to maintain max heap 
=> repeat until the heap is empty

PRO: O(1) space complexity (in-place)

CON: In real world it is slower than quicksort due to more complex memory access patterns and less efficient caching
///////////////////

ODD ONES

a) Bucket/Counting Sort => Distribute each element into their related bucket => and then get every element out of the bucket left to right => O(n+k) time complexity (where k is the number of buckets) , O(n+k) space complexity (where k is the number of buckets)

A) Radix Sort (,not comparison based,recursive) => find the largest number in the array and find its number of digits (make sure every number has the same digits) => that is the amount of recursions 
=>  now we will start with the LSD and do a bucket sort on those digits => repeat for every digit => REALLY FAST for large numbers
    
PRO: O(n * k) time complexity (where k is the number of digits in the largest number) , O(n + k) space complexity (where k is the number of digits in the largest number)

CON: On lower numbers it can be slower due to the fixed cost of iterating over buckets (on 16 base n < 10000 it is slower than quicksort)

//////////////////////////////////////////////////////////////

LUCK IS A SKILL ONES:

A) BogoSort (GODLIKE) => Rely on your luck. Best Case => O(n)

B) Quantum BogoSort (LITERALLY UNFAIR) => Rely on your quantum luck, look through every multiverse where your array sorting results => elimante every universe where it isnt sorted
Best Case => O(n)


//////////////////////////////////////////////////////////////

// BITWISE OPERATIONS //

// ~X => NOT X ;; ^ => XOR

int a = 5; // 0101  int b = 3; // 0011 
a | b => (                     
  
    0 | 0 => 0
    1 | 0 => 1
    0 | 1 => 1
    1 | 1 => 1 
    
    result => 0111 => 7
)

">>" => right shift ;; 5 = 101 =>  101 >> == LSB gets scrapped and a 0 gets added to the left => 010 => 2 (DİVİSİON BY 2)
"<<" => left shift  ;; 5 = 101 => 101 << == MSB gets scrapped and a 0 gets added to the right => 110 => 6 (MULTİPLİCATİON BY 2)


::APPLICATIONS OF BITWISE OPERATIONS::

1) Optimization in embedded systems
2) XOR can be used for checking for file corruption
3) They are used for encryption and compression for data
4) Used in networking, packets are numerous bits
5) Image enchancing and getting parts of a microscopic image

//////////////////////////////////////////////////////////////

// BITWISE CHEATS //

x & 1 => check if x is even or odd (if 0 => even, if 1 => odd)

x >> 1 => divide x by 2
x << 1 => multiply x by 2

ch | '' -> lowercase
ch | "-" -> uppercase


*/