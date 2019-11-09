#pragma once
#include <utility>

//Структура односвязного списка
template <typename T>
class LinkedList {
private:
	struct Node {
		T value;
		Node* next = nullptr;
	};
	Node* head = nullptr;
public:
	//Конструктор по умолчанию
	LinkedList() {}

	//Некопируемый класс
	LinkedList(const LinkedList<T>& list) = delete;
	void operator = (const LinkedList<T>& list) = delete;
	LinkedList(LinkedList<T>&& list);
	void operator = (LinkedList<T>&& list);

	//Функция добавления элемента в начало списка
	void push_front(const T& value);
	void push_front(T&& value);

	//Удаления первого элемента из списка
	void pop_front();

	//Функция реверс (переставляет начало на конец списка)
	void reverse();

	//Функция реверс с использованием хвостовой рекурсии
	void recursion(Node*& current, Node*& previous);
	void recursion_reverse();

	/*Дополнительные функции для получения указателя
	 * на заголовок односвязного списка
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

//Функция добавления элемента в начало списка
template <typename T>
void LinkedList<T>::push_front(const T& value) {
	Node* new_value = new Node;
	new_value->next = head;
	new_value->value = value;
	head = new_value;
}

//Функция добавления элемента в начало списка
template <typename T>
void LinkedList<T>::push_front(T&& value) {
	Node* new_value = new Node;
	new_value->next = head;
	new_value->value = std::move(value);
	head = new_value;
}

//Удаления первого элемента из списка
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

//Функция реверс (переставляет начало на конец списка)
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

//Функция реверс с использованием хвостовой рекурсии
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

//Деструктор (освобождает память и удаляет все элементы списка)
template <typename T>
LinkedList<T>::~LinkedList() {
	while (head != nullptr) {
		pop_front();
	}
}