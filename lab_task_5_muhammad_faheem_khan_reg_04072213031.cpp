#include<iostream>
struct node {
	int data;
	node *addr;
};
int count;
class stack {

	
public:
	node *TOP;
	stack() {
		TOP== nullptr;
		
	}
	~stack() {
		int n = count;
		for (int i = 0;i < n;i++) {
			pop();
		}
		
			
	}
	stack(const stack& rhs) {
		this->TOP = new node;
		this->TOP->addr = rhs.TOP->addr;
		this->TOP->data = rhs.TOP->data;
	}
	stack& operator=(const stack& rhs) {
	
		this->TOP->addr = rhs.TOP->addr;
		this->TOP->data = rhs.TOP->data;
		return *this;
	}
	//stack operator
	void push(const int & v) {
		if (TOP == nullptr) {
			TOP = new node();
			TOP->data = v;
			TOP->addr = nullptr;
		}
		else {
			node* temp;
			 temp=TOP;
			 TOP = new node();
			 TOP->addr = temp;
			 TOP->data = v;
		}
		count++;
	}
	void pop() {
		node* tmp;
		tmp = TOP;
		TOP = tmp->addr;
		delete tmp;
		count--;
		
	}
	int size()const {
		return count;
	}
	node* top()const {
		return TOP;
	}
	bool empty() {
		if (TOP == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	bool full() {
		node* temp = new node();
		if (temp == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
};
int main() {
	
		stack s;
		
		s.push(10);
		s.push(15);
		s.push(20);
		stack s2(s);//copy constructor called
		std::cout << s2.TOP->data << std::endl;
			s.pop();
			std::cout << s.TOP->data << std::endl;
			s.pop();
			std::cout << s.TOP->data << std::endl;
			s.pop();
		
		
		
	
	std::cout << count << std::endl;
	//std::cout << s.top() << std::endl;
	//std::cout << s.TOP << std::endl;
	int y = s.empty();
	//std::cout << y <<std:: endl;
	int z = s.full();
	//std::cout << z << std::endl;


}