// CPP program to illustrate 
// Implementation of push() function 
#include <iostream> 
#include <stack> 
using namespace std; 
 
stack<int> mystack; 
int min1 = 99999;
int get_min() {
  return min1;
}

void my_push(int data) {
  if(data > get_min())
    mystack.push(data);
  else {
    mystack.push(2*data - min1);
    min1 = data;
  }
  printf("%d Current min\n",min1);
}
int my_pop() {
  int data = mystack.top();
  mystack.pop();
  int pop_min;
  pop_min = data;
  if (data < get_min()) {
    pop_min = min1;
    min1 = 2*min1 - data;
  }
  return pop_min;
}

int main() 
{ 
    // Empty stack 
    my_push(1);
    my_push(5);
    my_push(2);
    my_push(0);
    my_push(4);
    my_pop();
    my_pop();
    my_pop();
    my_pop();
    return 0;  
    // Printing content of stack 
} 
