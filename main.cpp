#include <iostream>

struct node {
	int data = 0;
	node* next = nullptr;
};

struct list {
	node* head;
	node* tail;
};

void constructor(list& in) {
	in.head = nullptr;
	in.tail = nullptr;
}
void size_stack(list& in) {
	unsigned int cnt = 1;
	node* last = in.tail;
	while (last != in.head) {
		last = last->next;
		cnt++;
	}
	std::cout << "size: " << cnt << std::endl;
}

void size_queue(list& in) {
	unsigned int cnt = 1;
	node* first = in.head;
	while (first != in.tail) {
		first = first->next;
		cnt++;
	}
	std::cout << "size: " << cnt << std::endl;
}

void destructor_stack(list& in) {
	node* last = nullptr;
	while (in.tail != in.head) {
		last = in.tail->next;
		delete in.tail;
		in.tail = last;
	}
	constructor(in);
}

void destructor_queue(list& in) {
	node* first = nullptr;
	while (in.tail != in.head) {
		first = in.head->next;
		delete in.head;
		in.head = first;
	}
	constructor(in);
}

void push_stack(list& in, node& in2) {
	node* node_new = new node;
	node_new->data = in2.data;
	if (in.head == nullptr) in.head = node_new;
	else node_new->next = in.tail;
	in.tail = node_new;
}

void push_queue(list& in, node& in2) {
	node* node_new = new node;
	node_new->data = in2.data;
	if (in.head == nullptr) in.head = node_new;
	else in.tail->next = node_new;
	in.tail = node_new;
}

void pop_stack(list& in) {
	node* out = new node;
	if (!in.tail) {
		std::cout << "stack is empty" << std::endl;
		return;
	}
	node* last = in.tail;
	out->data = last->data;
	if (last == in.head) {
		destructor_stack(in);
	}
	else {
		in.tail = in.tail->next;
		delete last;
	}
	std::cout << "Popped: " << out->data << std::endl;
}

void pop_queue(list& in) {
	node* out = new node;
	if (!in.head) {
		std::cout << "stack is empty" << std::endl;
		return;
	}
	node* first = in.head;
	out->data = first->data;
	if (first == in.tail) {
		destructor_stack(in);
	}
	else {
		in.head = in.head->next;
		delete first;
	}
	std::cout << "Popped: " << out->data << std::endl;
}

void print_stack(const list& in) {
	node* last = in.tail;
	if (!in.head) {
		std::cout << "stack is empty" << std::endl;
		return;
	}
	while (last != in.head) {
		std::cout << last->data << std::endl;
		last = last->next;
	}
	std::cout << last->data << std::endl;
}

void print_queue(const list& in) {
	node* first = in.head;
	if (!in.head) {
		std::cout << "stack is empty" << std::endl;
		return;
	}
	while (first != in.tail) {
		std::cout << first->data << std::endl;
		first = first->next;
	}
	std::cout << first->data << std::endl;
}

int main() {
	list stack;
	constructor(stack);
	list queue;
	constructor(queue);
	std::cout << "Welcome! Available commands list:" << std::endl;
	std::cout << "destruct_stack - Clears the stack" << std::endl;
	std::cout << "destruct_queue - Clears the queue" << std::endl;
	std::cout << "size_stack - Shows size of the stack" << std::endl;
	std::cout << "size_queue - Shows size of the queue" << std::endl;
	std::cout << "push_stack - Pushes an element to the stack" << std::endl;
	std::cout << "push_queue - Pushes an element to the queue" << std::endl;
	std::cout << "pop_stack - Pops an element from the stack" << std::endl;
	std::cout << "pop_queue - Pops an element from the queue" << std::endl;
	std::cout << "print_stack - Prints all elements from the stack" << std::endl;
	std::cout << "print_queue - Prints all elements from the queue" << std::endl;
	std::cout << "exit - Exits the program" << std::endl;
	while (true) {
		std::string console_input;
		std::cin >> console_input;
		if (console_input == "destruct_stack") destructor_stack(stack);
		else if (console_input == "destruct_queue") destructor_queue(queue);
		else if (console_input == "size_stack") size_stack(stack);
		else if (console_input == "size_queue") size_queue(queue);
		else if (console_input == "push_stack") {
			std::cout << "Enter an element: ";
			node node_new;
			std::cin >> node_new.data;
			push_stack(stack, node_new);
			std::cout << "Pushed!" << std::endl;
		}
		else if (console_input == "push_queue") {
			std::cout << "Enter an element: ";
			node node_new;
			std::cin >> node_new.data;
			push_queue(queue, node_new);
			std::cout << "Pushed!" << std::endl;
		}
		else if (console_input == "pop_stack") pop_stack(stack);
		else if (console_input == "pop_queue") pop_queue(queue);
		else if (console_input == "print_stack") print_stack(stack);
		else if (console_input == "print_queue") print_queue(queue);
		else if (console_input == "exit") exit(0);
		else std::cout << "Unknown command" << std::endl;
	}
	return 0;
}
