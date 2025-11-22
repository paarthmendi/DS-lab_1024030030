#include <iostream>
#include <vector>
using namespace std;

class PQueue {
    vector<int> h;

    void up(int i) { 
        while(i > 0 && h[(i-1)/2] < h[i]) { 
            swap(h[i] , h[(i-1)/2]); 
            i = (i-1)/2; 
        } 
    }

    void down(int i) { 
        int n = h.size(); 
        int l = 2*i + 1 , r = 2*i + 2 , big = i; 
        if(l < n && h[l] > h[big]) big = l; 
        if(r < n && h[r] > h[big]) big = r; 
        if(big != i) { 
            swap(h[i] , h[big]); 
            down(big); 
        } 
    }

public:
    void push(int x) { 
        h.push_back(x); 
        up(h.size() - 1); 
    }

    void pop() { 
        if(h.empty()) return; 
        h[0] = h.back(); 
        h.pop_back(); 
        down(0); 
    }

    int top() { 
        return h.empty() ? -1 : h[0]; 
    }

    bool empty() { 
        return h.empty(); 
    }

    void show() { 
        for(int x : h) cout << x << " "; 
        cout << endl; 
    }
};

int main() { 
    PQueue pq; 
    pq.push(10); 
    pq.push(30); 
    pq.push(20); 
    pq.push(5); 
    pq.push(40); 
    
    cout << "Priority Queue: "; 
    pq.show(); 
    
    cout << "Elements popped in priority order: "; 
    while(!pq.empty()) { 
        cout << pq.top() << " "; 
        pq.pop(); 
    } 
    cout << endl; 
}