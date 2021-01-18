#include <iostream>

struct node {
	int data = 0;
	node* next = nullptr;
};

struct queue {
	node* head;
	node* tail;
};

void constructor(queue& in) {
	in.head = nullptr;
	in.tail = nullptr;
}

void size(queue& in) {
	unsigned int cnt = 0;
	node* first = in.head;
	while (first != nullptr) {
		first = first->next;
		cnt++;
	}
	std::cout << "Size: " << cnt << std::endl;
}

void destructor(queue& in) {
	node* first = in.head;
	while (first != nullptr) {
		first = in.head->next;
		delete in.head;
		in.head = first;
	}
	std::cout << "Cleared!" << std::endl;
}

void push(queue& in, node& in2) {
	node* node_new = new node;
	node_new->data = in2.data;
	if (in.head == nullptr) in.head = node_new;
	else in.tail->next = node_new;
	in.tail = node_new;
}

node* pop(queue& in) {
	node* out = in.head;
	in.head = in.head->next;
	return out;
}

void print(const queue& in) {
	node* first = in.head;
	if (!in.head) {
		std::cout << "Stack is empty" << std::endl;
		return;
	}
	while (first != nullptr) {
		std::cout << first->data << std::endl;
		first = first->next;
	}
}

int main() {
	queue Queue;
	constructor(Queue);
	std::cout << "Welcome! Available commands list:" << std::endl;
	std::cout << "destruct - Clears the queue" << std::endl;
	std::cout << "size - Shows size of the queue" << std::endl;
	std::cout << "push - Pushes an element to the queue" << std::endl;
	std::cout << "pop - Pops an element from the queue" << std::endl;
	std::cout << "print - Prints all elements from the queue" << std::endl;
	std::cout << "exit - Exits the program" << std::endl;
	bool is_inwork = true;
	while (is_inwork) {
		std::string console_input;
		std::cin >> console_input;
		if (console_input == "destruct") destructor(Queue);
		else if (console_input == "size") size(Queue);
		else if (console_input == "push") {
			std::cout << "Enter an element: ";
			node node_new;
			std::cin >> node_new.data;
			push(Queue, node_new);
			std::cout << "Pushed!" << std::endl;
		}
		else if (console_input == "pop") {
			if (!Queue.head) std::cout << "Queue is empty" << std::endl;
			else {
				node* node_pop = pop(Queue);
				std::cout << "Popped: " << node_pop->data << std::endl;
				delete node_pop;
			}
		}
		else if (console_input == "print") print(Queue);
		else if (console_input == "exit") is_inwork = false;
		else std::cout << "Unknown command" << std::endl;
	}
	return 0;
}
