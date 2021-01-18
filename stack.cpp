#include <iostream>

struct node {
	int data = 0;
	node* prev = nullptr;
};

struct stack {
	node* tail;
};

void constructor(stack& in) {
	in.tail = nullptr;
}
void size(stack& in) {
	unsigned int cnt = 0;
	node* last = in.tail;
	while (last != nullptr) {
		last = last->prev;
		cnt++;
	}
	std::cout << "Size: " << cnt << std::endl;
}

void destructor(stack& in) {
	node* last = in.tail;
	while (last != nullptr) {
		last = in.tail->prev;
		delete in.tail;
		in.tail = last;
	}
	std::cout << "Cleared!" << std::endl;
}

void push(stack& in, node& in2) {
	node* node_new = new node;
	node_new->data = in2.data;
	node_new->prev = in.tail;
	in.tail = node_new;
}

node* pop(stack& in) {
	node* out = in.tail;
	in.tail = in.tail->prev;
	return out;
}

void print(const stack& in) {
	node* last = in.tail;
	if (!in.tail) {
		std::cout << "Stack is empty" << std::endl;
		return;
	}
	while (last != nullptr) {
		std::cout << last->data << std::endl;
		last = last->prev;
	}
}

int main() {
	stack Stack;
	constructor(Stack);
	std::cout << "Welcome! Available commands list:" << std::endl;
	std::cout << "destruct - Clears the stack" << std::endl;
	std::cout << "size - Shows size of the stack" << std::endl;
	std::cout << "push - Pushes an element to the stack" << std::endl;
	std::cout << "pop - Pops an element from the stack" << std::endl;
	std::cout << "print - Prints all elements from the stack" << std::endl;
	std::cout << "exit - Exits the program" << std::endl;
	bool is_inwork = true;
	while (is_inwork) {
		std::string console_input;
		std::cin >> console_input;
		if (console_input == "destruct") destructor(Stack);
		else if (console_input == "size") size(Stack);
		else if (console_input == "push") {
			std::cout << "Enter an element: ";
			node node_new;
			std::cin >> node_new.data;
			push(Stack, node_new);
			std::cout << "Pushed!" << std::endl;
		}
		else if (console_input == "pop") {
			if (!Stack.tail) std::cout << "Stack is empty" << std::endl;
			else {
				node* node_pop = pop(Stack);
				std::cout << "Popped: " << node_pop->data << std::endl;
				delete node_pop;
			}
		}
		else if (console_input == "print") print(Stack);
		else if (console_input == "exit") is_inwork = false;
		else std::cout << "Unknown command" << std::endl;
	}
	return 0;
}
