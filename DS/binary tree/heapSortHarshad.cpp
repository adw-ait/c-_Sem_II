#include<iostream>
using namespace std;

class heapSort {
  public:
    int s;
  void swap(int & b, int & c) {
    int t = b;
    b = c;
    c = t;
  }
  void maxHeapify(int a[], int size, int i) {
    int largest = i;
    int leftChild = (2 * i) + 1;
    int rightChild = (2 * i) + 2;
    while (leftChild < size && a[leftChild] > a[largest]) {
      largest = leftChild;
    }
    while (rightChild < size && a[rightChild] > a[largest]) {
      largest = rightChild;
    }
    if (largest != i) {
      swap(a[largest], a[i]);
      maxHeapify(a, size, largest);
    }
  }
  void minHeapify(int a[], int size, int i) {
    int parent = (i - 1) / 2;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    while (left > size && a[left] < a[parent]) {
      parent = left;
    }
    while (right > size && a[right] < a[parent]) {
      parent = right;
    }
    if (parent != i) {
      swap(a[parent], a[i]);
      maxHeapify(a, size, parent);
    }
  }
  void minheap(int a[], int s, int i) {
    int parent = i;
    int l = (i * 2) + 1;
    int r = (i * 2) + 2;

    if (l < s && a[l] < a[parent]) {
      parent = l;
    }

    if (r < s && a[r] < a[parent]) {
      parent = r;
    }
    if (parent != i) {
      swap(a[i], a[parent]);
      minheap(a, s, parent);
    }
  }
  void heapsort(int a[], int size) {
    s = size;
    for (int i = (s / 2) - 1; i >= 0; i--) {
      maxHeapify(a, s, i);
    }
    for (int i = s - 1; i >= 1; i--) {
      swap(a[1], a[i]);
      maxHeapify(a, s, 1);
    }
    display(a, s);
  }
  void display(int a[], int s) {
    cout << "\nElements in array : ";
    for (int i = 0; i < s; i++) {
      cout << a[i] << "\t";
    }
  }
};
int main() {
  heapSort hs;
  int size, a[100];
  cout << "\nEnter the size : ";
  cin >> size;
  cout << "\nEnter the elements : ";
  for (int i = 0; i < size; i++) {
    cin >> a[i];
  }
  int choice;
  do {
    cout << "\n 1.Maxheap and display \n 2.Minheap and display \n 3.Apply heap sort and display \n 4.Exit \n";
    cout << "\nEnter your choice : ";
    cin >> choice;
    switch (choice) {
    case 1:
      for (int i = (size / 2) - 1; i >= 0; i--) {
        hs.maxHeapify(a, size, i);
      }
      hs.display(a, size);
      break;
    case 2:
      for (int i = (size / 2) - 1; i >= 0; i--) {
        hs.minheap(a, size, i);
      }
      hs.display(a, size);
      break;

    case 3:
      hs.heapsort(a, size);
      break;
    case 4:
      cout << "\n Exited";
      break;
    default:
      cout << "Invalid choice bruh ..";
      break;
    }
  } while (choice != 4);
}