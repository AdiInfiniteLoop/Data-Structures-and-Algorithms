#include<iostream>
#include<queue>

class Queue{
    public:
        int *arr;
        int front;
        int rear;
        int size;
        Queue(int size){
            this->size = size;
            this->front = 0;
            this->rear = 0;
            arr = new int[size];
        }
        void push(int data){
            if(rear == size) std::cout<<"The queue has no space\n";
            else arr[rear++] = data;
        }
        void pop(){
            if(front == rear) std::cout<<"The queue is emprt\n";
            else{
                arr[front] = -1;
                front++;
                if(front == rear){
                    front = 0;
                    rear = 0;
                }
            }
        }
        int getsize(){
            if(front == rear) return 0;
            else {
                return rear - front;
            }
        }
        int getfront(){
            if(front == rear) return 69;
            else {
                return arr[front];
            }
        }
        bool empty(){
            if(front == rear) return true;
            else {
                return false;
            }
        }
};

int main(){
    Queue *q = new Queue(6);
    q->push(10);
    q->push(20);
    q->push(30);
    q->push(40);
    q->push(50);
    q->push(60);
    std::cout<<q->getfront()<<"\n";
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    std::cout<<q->getfront()<<"\n";
    std::cout<<q->getsize()<<std::endl;

    while(!q->empty()){
        std::cout<<q->getfront()<<" ";
        q->pop();
    }


}