#include <iostream>
#include <string.h>
#include <math.h>

using namespace std; 

class Node{
	public: 
	Node *prev; 
	Node *next; 
	int value; 
	// Contstructor 
	Node(int value){
		this->value = value; 
		prev = next = NULL; 
	}
};
class dlist{
	public:
		Node *head; 
		Node *tail; 
		dlist(){
			head = tail = NULL; 
		}
		~dlist(){
			destroy();
		}
		void push_back(int value){
			Node *node = new Node(value); 
			if(head == NULL){
				head = tail = node;
			}
			else {
				tail->next = node; 
				node->prev = tail; 
				tail = node; 
			}
		}
		void destroy(){
			Node *temp = head; 
			while(temp){
				Node *node = temp; 
				temp = temp->next; 
				delete node; 
			}
		}
};

class Stack {
	public: 
		 int maxsize; 
		 int count; 
		 dlist list; 
		 Stack(int size){
		 	count = 0; 
		 	maxsize = size; 
		 }
		 void push(int num){
		 	if(count < maxsize){
		 		list.push_back(num); 
		 		count++; 
			 }
		 }
		 int pop(){
		 	Node *tail = list.tail; 
		 	int toreturn = NULL;
		 	if(!tail){
		 		return toreturn; 
			 }
			 if (tail == list.head){
			 	toreturn = tail->value; 
			 	delete tail; 
			 	list.head = list.tail = NULL; 
			 	count--;
			 }
			 else {
			 	toreturn = tail->value; 
			 	Node *temp = list.tail->prev; 
			 	delete list.tail;
				 list.tail = temp; 
				 list.tail->next = NULL; 
				 count--;  
			 }
			 return toreturn; 
		 }
		 
		
};

 int evaluatePostfix(char * exp){
		 	Stack stack = Stack(strlen(exp)); 
		 	int sizeofexp = strlen(exp); 
		 	int i; 
		 	if(stack.maxsize == 0) return -1; 
		 	
		 	for(i = 0; exp[i]; i++){
		 		if(isdigit(exp[i]))
		 			stack.push(exp[i] - '0');
				else {
					int val1 = stack.pop(); 
					int val2 = stack.pop(); 
					switch(exp[i]) {
						case '+': stack.push(val1 + val2); 
						break; 
						case '-': stack.push(val2-val1); 
						break; 
						case '*': stack.push(val2 * val1); 
						break; 
						case '/': stack.push(val2/val1); 
						break; 
						case '^': stack.push(pow(val2, val1)); 
						break; 
					}
				} 
			 }
			 cout << "the size of the expression is: " << sizeofexp << endl; 
			 return stack.pop(); 
		 }
int main(){
	char exp[] = "43+5*" , exp1[] = "435*+" , exp2[] = "623+-382/+*2^3+" ; 
	cout << "Evaluating the postfix expression:  43+5*" << endl; 
	cout << "POST FIX EVALUATION: " << evaluatePostfix(exp) << endl; 
	      cout << "\n" ; 
	
	cout << "Evalutating the postfix Expression:  435*+" << endl ; 
    cout<<"postfix evaluation: "<< evaluatePostfix(exp1) << endl;
          cout << "\n" ; 
          
    cout << "Evalutating the postfix Expression:  623+-382/+*2^3+" << endl ; 
    cout<<"postfix evaluation: "<< evaluatePostfix(exp2) << endl;
    
	
}
