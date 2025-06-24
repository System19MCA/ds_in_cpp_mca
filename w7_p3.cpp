#include<iostream>
using namespace std;

class Queue{
    int* queue;
    int size, idx;
public:
    Queue(int size=10){
        queue = new int[size];
        this->size = size;
        this->idx = 0;
    }

    bool isEmpty(){
        return this->idx == 0;
    }
    bool isFull(){
        return this->idx == this->size;
    }

    void enqueue(int data){
        if(!isFull()){
            queue[idx++] = data;
        }
    }
    int dequeue(){
        if(!isEmpty()){
            return queue[--idx];
        }
        throw exception();
    }

    friend ostream& operator<<(ostream& os, Queue& q){
        for(int i =0; i < q.size; i++){
            os<<q.queue[i]<<", ";
        }
        return os;
    }
};



int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<q<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q<<endl;

    return 0;
}