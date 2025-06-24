// Write a program to demonstrate the use of multiple stacks?
#include <iostream>
using namespace std;

class MultStk{
    int *st;
    int size, left, right;

    public:
    MultStk(int size=10){
        this->size = size;
        this->st = new int[size];
        this->left = 0;
        this->right = this->size-1;
    }

    bool isFull(){
        return left > right;
    }
    bool isEmpty1(){
        return left == 0;
    }

    bool isEmpty2(){
        return right == size-1;
    }
    void push1(int d){
        if(!isFull()){
            st[left++] = d;
        }else cout<<"\n############ Stack 1 Full ############"<<endl;
    }
    void push2(int d){
        if(!isFull()){
            st[right--] = d;
        }else cout<<"\n############ Stack 2 Full ############"<<endl;
  }
    int pop1(){
        if(isEmpty1()) {
            cout<<"\n############ Empty Stack 1 ############"<<endl;
            return -1;
        }
        return st[--left];
    }
    int pop2(){
        if(isEmpty2()) {
            cout<<"\n############ Empty Stack 2 ############"<<endl;
            return -1;
        }
        return st[++right];
    }

    friend ostream& operator<<(ostream& os, MultStk& obj){
        for(int i = 0; i < obj.size; i++){
            os<<obj.st[i]<<", ";
        }
        os<<"\nleft: "<<obj.left<<", right: "<<obj.right;
        return os;
    }
};

int main(){

    MultStk s;
    while(true){
        int choice = 0;              
        cout<<"1. push_1\t2. push_2\n3. pop_1\t4. pop_2\n5. display_all\t0. exit"<<endl;
        cout<<"Enter: ";
        cin>>choice;

        if(choice == 1){
            cout<<"Enter number: ";
            int x;
            cin>>x;
            s.push1(x);
        }else if(choice == 2){
            cout<<"Enter number: ";
            int x;
            cin>>x;
            s.push2(x);
        }else if(choice == 3){
            cout<<"Poped: "<<s.pop1()<<endl;
        }else if(choice == 4){
            cout<<"Poped: "<<s.pop2()<<endl;
        }else if(choice == 5){
            cout<<s<<endl;
        }else if(choice == 0) break;
    }
    return 0;
}