#include <iostream>
using namespace std;
class stack
{
private:
    int capacity;
    int top;
    int *ptr;

public:
    stack(int);
    void push(int);
    bool isFull();
    bool isEmpty();
    int peek();
    int pop();
    void print();
    ~stack();
    void reverse();
    int getSize();
    stack& operator=(stack&);
    stack(stack&);
};
stack::stack(int cap)
{
    if (cap < 0)
        cap = -cap;
    if (cap == 0)
        cap = 5;
    capacity = cap;
    top = -1;
    ptr = new int[capacity];
}
void stack::push(int data)
{
    if (isFull())
    {
        cout<<endl<<"Stack Overflow";
    }
    else
    {
        ptr[++top] = data;
    }
}
int stack::peek()
{
    try
    {
        if(top==-1)
            throw 1;
        return ptr[top];
    }
    catch(int e)
    {
        cout<<"\nStack is Empty";
        return 0;
    }
}
int stack::pop()
{
    if(isEmpty())
      cout<<"\nStack Underflow";
    else
    {
        return ptr[top--];
    }
}
bool stack::isFull()
{
    return top==capacity-1;
}
bool stack::isEmpty()
{
    return top==-1;
}
void stack::print()
{
    if(isEmpty())
    {
        cout<<"\nStack Underflow";
    }
    else
    {
        int temp=top;
        while(temp!=-1)
        {
            cout<<ptr[temp--]<<" ";
        }
        cout<<endl;
    }
}
int stack::getSize()
{
    return top+1;
}
stack::~stack()
{
   delete []ptr;
}
void stack::reverse()
{
    if(!isEmpty())
    {
        int low=0,high=top,temp;
        while(low<high)
        {
            temp=ptr[low];
            ptr[low]=ptr[high];
            ptr[high]=temp;
            low++;
            high--;
        }
    }
}
stack& stack::operator=(stack &s)
{
    if(this!=&s)
    {
    capacity=s.capacity;
    top=s.top;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
    for(int i=0;i<=top;i++)
        ptr[i]=s.ptr[i];
    }
    return *this;
}
stack::stack(stack &s)
{
    capacity=s.capacity;
    top=s.top;
    ptr=new int[capacity];
    for(int i=0;i<=top;i++)
        ptr[i]=s.ptr[i];
}
void reverseStack(stack &s)
{
    stack *tempStack=new stack(s.getSize());
    while(!s.isEmpty())
    {
        tempStack->push(s.pop());
    }
    s=*tempStack;
}
void minValueTracking()
{
    stack s1(5);
    stack min(5);
    int x;
    for(int i=0;i<5;i++){
        cout<<"Enter a number: ";
        cin>>x;
        s1.push(x);
        if(min.isEmpty())
            min.push(x);
        else
        {
            if(x<min.peek())
                min.push(x);
            else
                min.push(min.peek());
        }
    }

    for(int i=0;i<5;i++)
    {
        cout<<"\nMinimum value in the stack is "<<min.peek();
        s1.pop();
        min.pop();
    }

}
int main()
{
    stack s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.print();
    s1.reverse();
    s1.print();
    minValueTracking();
    return 0;
}