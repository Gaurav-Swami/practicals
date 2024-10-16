#include <iostream>
#include <conio.h>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int val)
  {
    data = val;
    next = nullptr;
  }
};

class Queue
{
public:
  Node *front, *rear, *temp;
  Queue()
  {
    front = rear = nullptr;
  }
  void enqueue()
  {
    int data;
    cout << "\nEnter the data for the node : ";
    cin >> data;
    Node *newNode = new Node(data);
    if (front == nullptr)
    {
      front = rear = newNode;
      rear->next = front;
    }
    else
    {
      rear->next = newNode;
      rear = rear->next;
      rear->next = front;
    }    
  }
  
  void dequeue(){
    if(front==nullptr){
      cout<<"\n Underflow";
    }
    else if (front == rear){
      temp = front;
      front = rear = nullptr;
      delete temp;
    }
    else{
      temp = front;
      front = front->next;
      rear->next = front;
      delete temp;
    }
  }
  void display()
  {
    if (front == nullptr)
    {
      cout << "The queue is empty\n";
    }
    else
    {
      temp = front;
      do
      {
        cout << temp->data << " ";
        temp = temp->next;
      } while (temp!=front );
    }
  }
};

int main()
{
  Queue q;
  while (1)
  {
    int choice;
    cout << "\n1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display\n";
    cout << "0. Exit\n";
    cout << "Enter your choice : ";
    cin>>choice;
    cout<<"\n";
    switch (choice)
    {
      case 0:
        return 0;
      case 1:
        q.enqueue();
        break;
      case 2:
        q.dequeue();
        break;
      case 3:
        q.display();
        break;
      default:
        break;
    }
  }
  getch();
  return 0;
}