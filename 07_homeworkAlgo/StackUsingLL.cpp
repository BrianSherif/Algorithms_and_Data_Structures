#include <stdexcept>
#include <cstdlib>
#include <iostream>

using namespace std;
#define MAX 100

/*Please note that code may seem similar to online resource
I used the following resource to find and understand the code
https://proprogramming.org/c-program-to-implement-stack-using-linked-list/*/

template <class T> class Stack{
private:
	struct SNode{
		T data;
		SNode *next;
	};
	//I am confused by the need for a Current_Size
	SNode *top;
	int size;
public:
	Stack();
	void push(T el);
	T pop();
	bool isEmpty();
	T top_el(Stack *);
};

template <class T> Stack<T>::Stack(){
	this->size = -1;
	this->top = NULL;
}

template <class T> bool Stack<T>::isEmpty(){
	return size == -1;
}

template <class T> void Stack<T>::push(T el){
	if(size < MAX){                      //check for overflow
		SNode *new_stack = new SNode();
		new_stack->data = move(el);
		new_stack->next = NULL;

		if(this->top == NULL){
			this->top = new_stack;
		}else{
			new_stack->next = this->top;
			this->top = new_stack;
		}
		this->size += 1;
	}else{
		cerr << "Stack overflow" << endl;
	}
}

template <class T> T Stack<T>::pop(){
	try{
		if(isEmpty()){
			throw out_of_range("Stack underflow"); //check for stack underflow
		}
	}catch(out_of_range& err){
		cerr << err.what() << endl;
		exit(EXIT_FAILURE);
	}
	T x = top->data;
	SNode *remove_node = top;
	top = top->next;
	size--;
	delete remove_node;
	return x;
}


int main(){
	//Stack using Chars
	char First = 'a';
	char Second = 'b';
	char Third = 'c';
	Stack <char> a_stack;

	cout << "\nStack of chars" << endl;

	a_stack.push(First);
	a_stack.push(Second);
	a_stack.push(Third);

	while(a_stack.isEmpty() == 0){
		char x;
		x = a_stack.pop();
		cout << x << endl;
	}

	//stack using intergers
	int one = 1;
	int two = 2;
	int three = 3;
	Stack <int> b_stack;

	cout << "Stack of ints" << endl;
	b_stack.push(one);
	b_stack.push(two);
	b_stack.push(three);

	while(b_stack.isEmpty() == 0){
		int y;
		y = b_stack.pop();
		cout << y << endl;
	}

	//stack using floats
	float a = 1.0;
	float b = 2.0;
	float c = 3.0;
	Stack <float> c_stack;

	cout << "Stack of floats" << endl;

	c_stack.push(a);
	c_stack.push(b);
	c_stack.push(c);

	while(c_stack.isEmpty() == 0){
		float z;
		z = c_stack.pop();
		cout << z << endl;
	}
	return 0;
}
