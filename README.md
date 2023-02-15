# DS_Programs

A data structure is not only used for organizing the data. It is also used for processing, retrieving, and storing data. There are different basic and advanced types of data structures that are used in almost every program or software system that has been developed. So we must have good knowledge about data structures. 


![DS_Classification](https://user-images.githubusercontent.com/96066261/219001712-e978b525-6d57-435d-9b01-dc252bc56567.jpg)


# 1. Linear data structure
Data structure in which data elements are arranged sequentially or linearly, where each element is attached to its previous and next adjacent elements, is called a linear data structure. Examples of linear data structures are array, stack, queue, linked list, etc.

## Characteristics

1. It is a type of data structure where data is stored and managed in a linear sequence. 
2. Data elements in the sequence are linked to one after the other.
3. Implementation of the linear structure of data in a computer’s memory is easy as the data is organized sequentially.
4. Array, queue. Stack, linked list, etc. are examples of this type of structure.
5. The data elements stored in the data structure have only one relationship.
6. Traversal of the data elements can be carried out in a single run as the data elements are stored in a single level.
7. There is poor utilization of the computer memory if a structure storing data linearly is implemented.
8. With the increase in the size of the data structure, the time complexity of the structure increases.


These structures can therefore be summarized as a type of data structure where the elements are stored sequentially and follow the order where:

Only one first element is present which has one next element.

Only one last element is present which has one previous element.

All the other elements in the data structure have a previous and a next element

# 2. Static data structure 
Data structures that are of a fixed size are called static data structures. Memory is allocated at the compiler time for static data structures and user cannot change their size after being compiled but, we can change the data which is stored in them.

The fixed size provides many benefits as well as a lot of drawbacks to static data structures. With the fixed memory allocation there is no need to worry about the overflow and underflow while inserting or deleting the element in/from the static data structures but it consumes a lot of memory and is not space-efficient.

Arrays are the best example of static data structures as they are of a fixed size and we can modify their data later.

As the memory is provided at the compile time for static data structures all the memory allocated is contiguous so there is no need to worry about the memory address of all the elements, user only needs to store the address of the first element and other element’s location can be easily found.

## Characteristics

There are many features of static data structures.

1. For static data structures, static memory is allocated at the compile time by the compiler which is stored in the stack memory of the program.
2. Memory allocated to the static data structures deallocates when they go out of scope or the program ends.
3. As we have discussed above, continuous memory is allocated to the static data structures, which means there is no need to store the structural information of data structure or explicit data variable to store the information of memory location.

# 3. Dynamic data structure 
Data structures that are of the dynamic size are called dynamic data structures. Memory is allocated at the run time for dynamic data structure and the size of the dynamic data structures varies at the run-time of the code. Also, both the size and the elements stored in the dynamic data structure can be changed at the run time of the code.

The dynamic size provides many benefits as well as a lot of drawbacks of dynamic data structures. With the dynamic memory allocation, there is no memory loss occurs and we can allocate space equal to the required number of elements. Users must have to check and carefully insert or delete data in/from the dynamic data structure to be safe from overflow and underflow conditions.

Linked lists and trees are common examples of dynamic data structures and a list of examples for dynamic data structures is never-ending.

As the memory allocated at the run time for the dynamic data structures makes allocated memory non-contiguous which decreases the performance of dynamic data structures because we have to create another variable to store the address of their allocated memory.

## Characteristics
There are many features of dynamic data structures.

1. For dynamic data structures, dynamic memory is allocated at the rum time which is stored in the heap memory of the program.
2. Memory allocated to the dynamic data structures doesn’t deallocate when they go out of scope which may cause the memory leak problem.
3. Memory of Dynamic data structure only gets deallocated when the program ends or the user deallocates it manually by using the free() function in C, delete() function in C++, etc.
4. Memory allocated to the dynamic data structures is not contiguous, which means users have to store the structural information of data structure or explicit data variable to store the information of each memory location.

# 4. Non-linear data structure
A Non-Linear Data Structure is one in which its elements are not connected in a linear fashion, as suggested by its name itself. In such a data structure elements might be connected in a hierarchical manner like a tree or graph, or it may be non hierarchical like in a LinkedList. Non-linear data structures have a more complex implementation, than their linear counterparts.

# About Repo
This repository will contain Data Structure Algorithms with an easy approach to make it understandable for the viewers.
Some of the algos may contain the use of STL and some of them will not contain STL so as to make it more easily understandable.
