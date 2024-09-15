#pragma once

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
class LinkedList {
private:
	Node<T>* head;
public:
	LinkedList();
	void insertAtBeginning(T newData);
	void insertAtEnd(T newData);
	void insertAtPosition(size_t index, T newData);
	void deleteFromBeginning();
	void deleteFromEnd();
	void deleteFromPosition(size_t index);
	void display() const;
};

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr) {};

template<typename T>
void LinkedList<T>::insertAtBeginning(T newData) {
	Node<T>* newNode = new Node<T>();
	newNode->data = newData;
	newNode->next = head;
	head = newNode;
}

template<typename T>
void LinkedList<T>::insertAtEnd(T newData) {
	Node<T>* newNode = new Node<T>();
	newNode->data = newData;
	newNode->next = nullptr;

	if (!head) {
		head = newNode;
		return;
	}
	Node<T>* temp = head;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = newNode;
}

template<typename T>
void LinkedList<T>::insertAtPosition(size_t index, T newData) {
	Node<T>* newNode = new Node<T>();
	newNode->data = newData;
	newNode->next = nullptr;

	if (index == 1) {
		insertAtBeginning(newData);
		return;
	}
	Node<T>* temp = head;
	for (size_t i = 0;i < index - 1 && temp;i++) {
		temp = temp->next;
	}
	if (!temp) {
		std::cout << "Out of range\n";
		delete newNode;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

template <typename T>
void LinkedList<T>::deleteFromBeginning() {
	if (!head) {
		std::cout << "List empty\n";
		return;
	}
	Node<T>* temp = head;
	head = head->next;
	delete temp;
}

template <typename T>
void LinkedList<T>::deleteFromPosition(size_t index) {
	if (index == 1) {
		deleteFromBeginning();
		return;
	}
	Node<T>* temp = head;
	for (size_t i = 1;i < index - 1 && temp;i++) {
		temp = temp->next;
	}
	if (!temp || !temp->next) {
		std::cout << "Out of range\n";
		return;
	}
	Node<T>* toDelete = temp->next;
	temp->next = temp->next->next;
	delete toDelete;
}

template <typename T>
void LinkedList<T>::deleteFromEnd() {
	if (!head) {
		std::cout << "List empty\n";
		return;
	}
	if (!head->next) {
		delete head;
		head = nullptr;
		return;
	}
	Node<T>* temp = head;
	while (temp->next->next) {
		temp = temp->next;
	}
	Node<T>* toDelete = temp->next;
	temp->next = temp->next->next;
	delete toDelete;
}

template <typename T>
void LinkedList<T>::display() const {
	if (!head) {
		std::cout << "List empty\n";
		return;
	}
	Node<T>* temp = head;
	while (temp->next) {
		std::cout << temp->data << " -> " << std::endl;
		temp = temp->next;
	}
	std::cout << temp->data << " -> " << std::endl;
	std::cout << "Null\n";
}