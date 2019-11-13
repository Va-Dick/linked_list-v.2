#pragma once
#include <utility>


//Single Link List Structuretemplate <typename T>
template <typename T>
class LinkedList {
private:
	struct Node {
		T value;
		Node* next = nullptr;
	};

	//Class Iterator for iterating over values
	struct Iterator {
	public:
		Iterator(Node*& it_) { it = it_; }
		Iterator operator++(int) {
			it = it->next;
			return it;
		}
		Iterator operator++() {
			it = it->next;
			return it;
		}
		T& operator*() {
			return it->value;
		}
		const T& operator*()const {
			return it->value;
		}
		bool operator!=(const Iterator& right) {
			return (it != right.it ? 1 : 0);
		}
	private:
		Node* it;
	};

	Node* head = nullptr;
public:
	//Default constructor
	LinkedList() {}

	//Uncopyable class
	LinkedList(const LinkedList<T>& list) = delete;
	void operator = (const LinkedList<T>& list) = delete;
	LinkedList(LinkedList<T>&& list);
	void operator = (LinkedList<T>&& list);

	//Function to add an item to the top of the list
	void push_front(const T& value);
	void push_front(T&& value);

	//Remove the first item from the list
	void pop_front();

	//Function reverse
	void reverse();

	//Function reverse using tail recursion
	void recursion(Node*& current, Node*& previous);
	void recursion_reverse();

	//Additional methods and overloads
	T& operator[](const std::size_t& position);
	const T& operator[](const std::size_t& position)const;
	const std::size_t& size()const;
	auto begin();
	auto end();
	const auto begin()const;
	const auto end()const;

	/* Additional functions for getting a pointer
	* to the heading of a singly linked list
	*/
	Node* get_head() { return head; }
	const Node* get_head() const { return head; }
	~LinkedList();
};

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& list) {
	head = list.head;
	list.head = nullptr;
}

template <typename T>
void LinkedList<T>::operator = (LinkedList<T>&& list) {
	head = list.head;
	list.head = nullptr;
}

template <typename T>
void LinkedList<T>::push_front(const T& value) {
	Node* new_value = new Node;
	new_value->next = head;
	new_value->value = value;
	head = new_value;
}

template <typename T>
void LinkedList<T>::push_front(T&& value) {
	Node* new_value = new Node;
	new_value->next = head;
	new_value->value = std::move(value);
	head = new_value;
}

template <typename T>
void LinkedList<T>::pop_front() {
	if (head == nullptr) {
		return;
	}
	Node* next_value = head->next;
	head->next = nullptr;
	delete head;
	head = next_value;
}

template<typename T>
void LinkedList<T>::reverse() {
	Node* next;
	Node* current = head;
	Node* previous = nullptr;
	while (current != nullptr) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head = previous;
}

template <typename T>
void LinkedList<T>::recursion(Node*& current, Node*& previous) {
	if (current == nullptr) {
		return;
	}
	Node* next = current->next;
	current->next = previous;
	previous = current;
	current = next;
	recursion(current, previous);
}

template <typename T>
void LinkedList<T>::recursion_reverse() {
	Node* current = head;
	Node* previous = nullptr;
	recursion(current, previous);
	head = previous;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	while (head != nullptr) {
		pop_front();
	}
}

template <typename T>
T& LinkedList<T>::operator[](const std::size_t& position) {
	Node* return_value = head;
	for (std::size_t i = 0; i < position; ++i) {
		if (return_value == nullptr) {
			throw std::out_of_range("Out of the range of container");
		}
		return_value = return_value->next;
	}
	return return_value->value;
}


template <typename T>
const T& LinkedList<T>::operator[](const std::size_t& position)const {
	Node* return_value = head;
	for (std::size_t i = 0; i < position; ++i) {
		if (return_value == nullptr) {
			throw std::out_of_range("Out of the range of container");
		}
		return_value = return_value->next;
	}
	return return_value->value;
}


template <typename T>
const std::size_t& LinkedList<T>::size()const {
	std::size_t size_ = 0;
	Node* iteration_value = head;
	while (iteration_value != nullptr) {
		++size_;
		iteration_value = iteration_value->next;
	}
	return size_;
}


template <typename T>
auto LinkedList<T>::begin() {
	Iterator begin_(head);
	return begin_;
}

template <typename T>
auto LinkedList<T>::end() {
	Node* iteration_value = head;
	while (iteration_value != nullptr) {
		iteration_value = iteration_value->next;
	}
	Iterator end_(iteration_value);
	return end_;
}

template <typename T>
const auto LinkedList<T>::begin()const {
	Iterator begin_(head);
	return begin_;
}

template <typename T>
const auto LinkedList<T>::end()const {
	Node* iteration_value = head;
	while (iteration_value != nullptr) {
		iteration_value = iteration_value->next;
	}
	Iterator end_(iteration_value);
	return end_;
}

