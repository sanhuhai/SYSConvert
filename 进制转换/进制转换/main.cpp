#include <iostream>
using namespace std;

typedef struct Stack {
	int* data;
	int base, top, length,MAXSIZE;
} *LStack , Stack;

class MyStack
{
public:
	MyStack();
	~MyStack();
	void initial();
	void push(int data);
	void pop();
	void getTop();
	void translation(int src,int dst);
	void print();
private:
	Stack sta;
	int MAXSIZE = 100 ,addSize = 10;
	int data;
};

MyStack::MyStack(){
}

MyStack::~MyStack(){
}

void MyStack::initial() {
	sta.data = new int[MAXSIZE];
	sta.base = sta.top = -1;
	sta.length = 0;
}

void MyStack::push(int data) {
	if (sta.top == sta.MAXSIZE - 1) {
		sta.MAXSIZE += addSize;
		sta.data =(int *) realloc(sta.data, sizeof(int) * (sta.MAXSIZE));
	}
	sta.data[++sta.top] = data;
	sta.length ++ ;
}

void MyStack::pop() {
	if (sta.top != sta.base) {
		data = sta.data[sta.top--];
		sta.length--;
	}
}

void MyStack::getTop() {
	if (sta.length) {
		data = sta.data[sta.top - 1];
	}
	else return;
}

void MyStack::translation(int src,int dst) {
	int temp = src;
	while (temp){
		push(temp % dst);
		temp /= dst;
	}
}

void MyStack::print() {
	while (sta.base!=sta.top) {
		pop();
		if (data >= 10) {
			char ch = 'A';
			ch = ch + data - 10;
			cout << ch ;
		}
		else cout << data;
	}
	putchar(10);
}

int main() {
	MyStack S;
	S.initial();
	int data, dst;
	cin >> data >> dst;
	S.translation(data, dst);
	S.print();
	return 0;
}