#include<iostream>
#include<queue>
#include<deque>


// class Queue{
//     public:
//         int *arr;
//         int front;
//         int rear;
//         int size;
//         Queue(int size){
//             this->size = size;
//             this->front = 0;
//             this->rear = 0;
//             arr = new int[size];
//         }
//         void push(int data){
//             if(rear == size) std::cout<<"The queue has no space\n";
//             else arr[rear++] = data;
//         }
//         void pop(){
//             if(front == rear) std::cout<<"The queue is emprt\n";
//             else{
//                 arr[front] = -1;
//                 front++;
//                 if(front == rear){
//                     front = 0;
//                     rear = 0;
//                 }
//             }
//         }
//         int getsize(){
//             if(front == rear) return 0;
//             else {
//                 return rear - front;
//             }
//         }
//         int getfront(){
//             if(front == rear) return 69;
//             else {
//                 return arr[front];
//             }
//         }
//         bool empty(){
//             if(front == rear) return true;
//             else {
//                 return false;
//             }
//         }
// };
// class Circular_Queue{
//     public:
//         int size;
//         int front;
//         int rear;
//         int *arr;
//         Circular_Queue(int size){
//             this->size = size;
//             this->front = -1;
//             this->rear = -1;
//             arr = new int[size];
//         }
//     void push(int data){
//         //check whether queue is empty or not
//         if(front == 0 && rear == size - 1 || front - rear == 1) printf("Not empty\n");
//         //single and first element
//         else if((front == rear) == -1){
//             front = 0;
//             rear = 0;
//             arr[rear] = data;
//         }
//         //establishing the circular nature
//         else if (rear == size - 1 && front != 0) {
//             rear = 0; arr[rear] = data; //front != 0 means 0th index is empty
//         }
//         //normal flow
//         else    arr[++rear] = data;

//     }

//     void pop(){
//         //empty or full && front == -1
//         if(rear == -1 ) printf("Empty Queue\n");
//         //single element
//         else if((front == rear))    arr[front] =-1,front = -1,rear = -1;//go back to previous pos of front and rear
//         //circular flow
//         else if(front == size -1) front = 0;
//         else front++;
//     }

// };

class DEQue{
    public:
        int size;
        int front;
        int rear;
        int* arr;
    DEQue(int size){
        this->size = size;
        this->front = -1;
        this->rear = -1;
        arr = new int[size];
    }
    void push_rear(int data){
        //check whether queue is empty or not
        if(front == 0 && rear == size - 1 || front - rear == 1){
             printf("Not empty\n"); return;
        }
        //single and first element
        else if((front == rear) == -1){
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        //circular nature
        else if(rear == size - 1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }
        else{
            arr[++rear] = data;
        }
    }
    void push_front(int data){
        //check whether queue is empty or not
        if(front == 0 && rear == size - 1 || front - rear == 1){
            printf("Not empty\n"); return;
        }
        //single and first element
        else if((front == rear) == -1){
            front = 0;
            rear = 0;
            arr[front] = data;
        }
        //circular nature
        else if(rear != size - 1 && front == 0){
            front = size - 1;
            arr[front] = data;
        }
        else{
            arr[--front] = data;
        }
    }
    void pop_front(){
        if((front == rear) == -1) {
            std::cout<<"Empty Queue\n";
            return;
        }
        else if(front == 0 && rear == 0){
            arr[front] = -1;
            front = rear = -1;
        }
        else if(front == size - 1) {
            arr[front] = -1;
            front = 0;
        }
        else{
            front++;
        }
    }

    void pop_rear(){
        if((front == rear) == -1) {
            std::cout<<"Empty Queue\n";
            return;
        }
        //single element
        else if(front == 0 && rear == 0){
            arr[front] = -1;
            front = rear = -1;
        }
        //CIrcular nature/flow
        else if(rear == 0){
            arr[rear] = -1;
            rear = size- 1;
        }
        //normalflow
        else{
            rear--;
        }
    }
};
int main(){
    // Queue *q = new Queue(6);
    // q->push(10);
    // q->push(20);
    // q->push(30);
    // q->push(40);
    // q->push(50);
    // q->push(60);
    // std::cout<<q->getfront()<<"\n";
    // q->pop();
    // q->pop();
    // q->pop();
    // q->pop();
    // q->pop();
    // q->pop();
    // std::cout<<q->getfront()<<"\n";
    // std::cout<<q->getsize()<<std::endl;

    // while(!q->empty()){
    //     std::cout<<q->getfront()<<" ";
    //     q->pop();
    // }
    // Circular_Queue* cq = new Circular_Queue(2);

std::deque<int> dq;
dq.push_front(10);
//10
dq.push_back(20);
//10 20
dq.push_front(30);
//30 10 20
dq.push_back(40);
//30 10 20 40
dq.push_front(50);
//50 30 10 20 40

dq.pop_back();
//50 30 10 20
dq.pop_front();
//30 10 20
dq.pop_back();
//30 10
dq.pop_front();
//10
}