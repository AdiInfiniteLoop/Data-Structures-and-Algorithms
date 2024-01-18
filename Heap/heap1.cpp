#include<iostream>
using namespace std;
#define N 101

class heap{
  public:
    int val;
    int* arr_heap = new int[N];
    int size;

  heap(){
    int size = 1;

  }   

  ~heap(){
    delete[] arr_heap;
  }

  void insertInheap(int val){
    size++;
    int index = size;
    arr_heap[index] = val;
    while(index > 1){
      if(arr_heap[index] > arr_heap[index/2]){
        std::swap(arr_heap[index],arr_heap[index/2]);
        index = index/2;
      }
      else break;
    }
  }


  void deleteFromheap(){
    arr_heap[1] = arr_heap[size];
    size--;
    int index = 1;

  while(index < size){
      int largest  = index;
    int left = 2*index;
    int right = 2*index + 1;
    if(arr_heap[index] < arr_heap[left] && left < size && arr_heap[left] > arr_heap[right]){
      largest = left;
    }
    
    if(arr_heap[index] < arr_heap[right] && right < size && arr_heap[right] > arr_heap[left]){
      largest = right;
    }
    if(largest == index){
      break; 
    }
    else{
      std::swap(arr_heap[largest],arr_heap[index]);
      index = largest;
    }
  }
  }
};

int main(){

  heap *h = new heap();
  h->arr_heap[1]= 50;
  h->arr_heap[2]= 30;
  h->arr_heap[3]= 70;
  h->arr_heap[4]= 40;
  h->arr_heap[5]= 80; //h.size won't work as constructor is called only once.
  
  h->insertInheap(35);
  h->insertInheap(50);
  h->insertInheap(25);
  h->insertInheap(18);
  h->insertInheap(16);
  h->insertInheap(12);
  h->insertInheap(11);
  h->insertInheap(14);
  h->insertInheap(17);
  h->insertInheap(18);
  h->insertInheap(48);
  h->insertInheap(19);
  h->insertInheap(67);
  h->insertInheap(56);
  h->insertInheap(46);
  h->insertInheap(3);
  h->insertInheap(100);
  for(int i = 1;i <= h->size;++i){
    cout<<h->arr_heap[i]<<" ";
  }

  h->deleteFromheap();
  h->deleteFromheap();
  h->deleteFromheap();
  cout<<"\n";
  for(int i = 1;i <= h->size;++i){
    cout<<h->arr_heap[i]<<" ";
  }


}


