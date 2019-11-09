### Singly linked list v.2
Features:

Uncopyable class
- LinkedList(const LinkedList<T>& list) = delete;
- void operator = (const LinkedList<T>& list) = delete;
- LinkedList(LinkedList<T>&& list);
- void operator = (LinkedList<T>&& list);

The function of adding an item to the top of the list
- void push_front(const T& value);
- void push_front(T&& value);

Function of removing the first item from the list
- void pop_front();

Reverse functions
- void reverse();
- void recursion(Node*& current, Node*& previous);
- void recursion_reverse();

Additional functions
- Node* get_head() { return head; }
- const Node* get_head() const { return head; }
- ~LinkedList();


To run the program, you need to go to this directory and execute the Cmake function

    >cd /directory/....
    >cmake CMakeLists.txt
