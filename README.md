### Singly linked list v.2

This version of the design project for the Linux operating system.

Features:

Uncopyable class:
- LinkedList(const LinkedList<T>& list) = delete;
- void operator = (const LinkedList<T>& list) = delete;
- LinkedList(LinkedList<T>&& list);
- void operator = (LinkedList<T>&& list);

The function of adding an item to the top of the list:
- void push_front(const T& value);
- void push_front(T&& value);

Function of removing the first item from the list:
- void pop_front();

Reverse functions:
- void reverse();
- void recursion(Node*& current, Node*& previous);
- void recursion_reverse();

Additional functions:
- Node* get_head() { return head; }
- const Node* get_head() const { return head; }
- ~LinkedList();

Iterative functions:
- T& operator[](const std::size_t& position);
- const T& operator[](const std::size_t& position)const;
- const std::size_t& size()const;
- auto begin();
- auto end();
- const auto begin()const;
- const auto end()const;

Googletests libraries "https://github.com/google/googletest" are required to start the project

After downloading, you need to create a build folder inside to build it. Then you need to enter the created folder through the command line and enter the following commands in turn:

	> cmake ..
	> make
	> sudo make install

After which, you need to start the project:

	>cd /directory/....
	>cmake CMakeLists.txt
