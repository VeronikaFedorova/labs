#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
  stack<int> stack;
  string operation;
  while(1)
  {
    cin >> operation;
    if(operation == "push")
    {
      int number;
      cin >> number;
      stack.push(number);  
      printf("ok\n");
    }
    else if(operation == "pop"){
      printf("%d\n", stack.top());
      stack.pop();      
    }
    else if(operation == "back"){
      printf("%d\n", stack.top());      
      
    }
    else if(operation == "size"){
      printf("%d\n", stack.size());      
    }
    else if(operation == "clear"){
        while(!stack.empty())
        {
          stack.pop();
        }
        printf("ok\n");
    }
    else{
      printf("bye\n");
      break;    }
  }
  return 0;
}
