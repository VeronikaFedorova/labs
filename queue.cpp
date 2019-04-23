#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
  queue<int> queue;
  string operation;
  while(1)
  {
    cin >> operation;
    if(operation == "push")
    {
      int number;
      cin >> number;
      queue.push(number);  
      printf("ok\n");
    }
    else if(operation == "pop"){
      printf("%d\n", queue.front());
      queue.pop();      
    }
    else if(operation == "front"){
      printf("%d\n", queue.front());      
      
    }
    else if(operation == "size"){
      printf("%d\n", queue.size());      
    }
    else if(operation == "clear"){
        while(!queue.empty())
        {
          queue.pop();
        }
        printf("ok\n");
    }
    else{
      printf("bye\n");
      break;    }
  }
  return 0;
}

