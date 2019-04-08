#include <iostream>
#include <climits>
using namespace std;


// array[ix] has children at array[ix*2 + 1 ] and array[ix*2 + 2]
// node[child] has parent at array[(child -1)/2]\



void swap(int *x, int *y );



class MinHeap {
  int * harr; // pointer to array of elements in heap
  int capacity;
  int heap_size;

  public:
    MinHeap(int capacity);

    void MinHeapify(int);

    int parent(int i ) {return (i)/2; }

    int left(int i) {return (2*i); }

    int right(int i ){return (2*i + 1 ); }

    int extractMin(); // extract root which is minimum element

    void decreaseKey(int i, int new_val); // decrease key value of key at index i to new_Val;

    int getMin(){return harr[1];}

    void deleteKey(int i);

    void insertKey(int k);


};

MinHeap :: MinHeap(int cap){
  heap_size = 1;
  capacity = cap;
  harr = new int[cap + 1 ];
  harr[0] = INT_MIN;
}



void MinHeap :: insertKey(int k){
  if (heap_size == capacity){
    cout << "\nOverflow: Could not insertKey \n";
    return;
  }

  heap_size++;
  int i = heap_size -1;

  harr[i] = k;

  while(i != 1 && harr[parent(i)] > harr[i]){
    swap(&harr[i], &harr[parent(i)]);
    i = parent(i);
  }
}

void MinHeap :: decreaseKey(int i, int new_val){
  harr[i] = new_val;
  while(i != 1 && harr[parent(i)] > harr[i] ){
    swap(&harr[i], &harr[parent(i)]);
    i = parent(i);
  }
}



int MinHeap :: extractMin()
{
  if (heap_size <= 0)
    return INT_MAX;
  if (heap_size == 1)
  {
    heap_size --;
    return harr[1];
  }
  // store the minimum value, and removie it from the heap
  int root = harr[1];
  harr[1] = harr[heap_size -1];
  heap_size --;
  MinHeapify(1);
  return root;
}



// This function delets key at index i, It first reduced value to
// minus
// infinite, then calls extractMin()

void MinHeap :: deleteKey(int i){
  decreaseKey(i, INT_MIN);
  extractMin();
}

// A recursive method to heapify a subtree with the root at given
// This method assumes that teh subtrees are already heapified

void MinHeap :: MinHeapify(int i ){
  int l = left(i);
  int r = right(i);
  int smallest = i;

  if (l < heap_size && harr[l] < harr[i])
    smallest = r;
  if(r < heap_size && harr[r] < harr[smallest])
      smallest = r;
  if (smallest != i){
    swap(&harr[i], &harr[smallest]);
    MinHeapify(smallest);
  }
}


void swap(int*x, int*y){
  int temp = *x;
  *x = *y;
  *y = temp;
}





int main(){
  MinHeap h(11);
  h.insertKey(3);
  h.insertKey(2);
  h.deleteKey(1);
  h.insertKey(15);
  h.insertKey(5);
  h.insertKey(4);
  h.insertKey(45);

  cout << h.extractMin() << " ";
  cout << h.getMin() << " ";
    h.decreaseKey(2,1);
    cout << h.getMin() << endl;
    return 0;
}
