// Q1. Stack is a Last-In-First-Out data structure. Write a Stack class. It implements stack using
// Dynamically allocated array. Stack size should be passed in parameterized constructor. If size is not
// given, allocate stack of size 5.
// Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print().
#include<iostream>
 using namespace std;
 class stack{
   private:
   int sz;
   int top;
   int *ptr;

   public:

  //  stack(int size = 5)
  //   {
  //       this->sz = size;
  //       ptr = new int[sz];
  //   }
     stack(){
      top = -1;
       sz = 5;
    }
     stack(int s){
      top = -1;
       sz = s;
       ptr = new int[sz];
     }
     void push(int ele){
       if(!isFull()){
         top++;
         ptr[top] = ele;
        }
        else {
          cout<<"stack overflow"<<endl;
        }
     }
    void pop(){
      if(!isEmpty()){
          top--;
        }
        else{
           cout<<"stack is underflow"<<endl;
        }
        
     }
     int peek(){
          return ptr[top];
     }
     bool isEmpty(){
         return top == -1;
     }
     
     bool isFull(){
        return (top == sz-1);
     }
     void print(){
          for(int i = top; i>= 0; i--){
            cout<<ptr[i]<<" ";
          }
          cout<<endl;
     }
     ~stack(){
      delete[] ptr;
      ptr = NULL;
     }
 };
 int main(){
   
     stack v;
     cout<<"enter stack size "<<endl;
     int n;
     cin>>n;
     stack d(n);

    

     

     int ch;
     do{
      cout<<"0 exit "<<endl;
      cout<<"1 push"<<endl;
      cout<<"2 pop"<<endl;
      cout<<"3 peek"<<endl;
      cout<<"4 print stack"<<endl;
      cout<<"enter a choice"<<endl;
     
      cin>>ch;
      switch(ch)
      {
        case 0:
         break;
         case 1:
          cout<<"enter stack value"<<endl;
          int k;
          cin>>k;
          d.push(k);
          break;
         case 2:
            d.pop();
          break;
         case 3:
          cout<<"peek value === " <<d.peek()<<endl;
          break;
          case 4:
          d.print();
          break;
          default:
           break;
        }
      }while(ch != 0);
      


    return 0;
 }
