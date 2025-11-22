#include <iostream>
using namespace std;

class Heap {
    void heapify(int a[], int n, int i) { 
        int l = 2*i + 1 , r = 2*i + 2 , big = i ; 
        if(l < n && a[l] > a[big]) big = l ; 
        if(r < n && a[r] > a[big]) big = r ; 
        if(big != i) { 
            swap(a[i] , a[big]); 
            heapify(a , n , big); 
        } 
    }

public:
    void sortInc(int a[], int n) { 
        for(int i=n/2 -1; i>=0; i--) heapify(a , n , i); 
        for(int i=n-1; i>0; i--) { 
            swap(a[0] , a[i]); 
            heapify(a , i , 0); 
        } 
    }

    void sortDec(int a[], int n) { 
        for(int i=n/2 -1; i>=0; i--) heapify(a , n , i); 
        for(int i=n-1; i>0; i--) { 
            swap(a[0] , a[i]); 
            heapify(a , i , 0); 
        } 
        // reverse array 
        for(int i=0; i<n/2; i++) swap(a[i] , a[n-i-1]); 
    }
};

int main() { 
    int a[] = { 4 , 10 , 3 , 5 , 1 }; 
    int n = 5 ; 
    Heap h ; 
    
    cout << "Increasing Order: "; 
    h.sortInc(a , n); 
    for(int i=0; i<n; i++) cout << a[i] << " "; 
    cout << endl; 
    
    int b[] = { 4 , 10 , 3 , 5 , 1 }; 
    cout << "Decreasing Order: "; 
    h.sortDec(b , n); 
    for(int i=0; i<n; i++) cout << b[i] << " "; 
    cout << endl; 
}