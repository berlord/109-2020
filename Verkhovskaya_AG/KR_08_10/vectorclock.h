//
//  vectorclock.h
//  vectorclock
//
//  Created by Nastya Verkhovskaya on 08.10.2020.
//  Copyright © 2020 Nastya Verkhovskaya. All rights reserved.
//

#include <iostream>


class VectorClock {
private:
    int n, k;
    int* v;
public:
    
    VectorClock(const int& n_, const int& k_);
    ~VectorClock();
    
    VectorClock() = delete;
    
    void update();
    
    void get(const VectorClock& other);
    
    bool operator<(const VectorClock& other) const;
    
    void print();
    
    VectorClock &operator=(const VectorClock& other) {
        n = other.n;
        k = other.k;
        v = new int[n];
        for (int i = 0; i < n; ++i) {
            v[i] = other.v[i];
        }
        return *this;
    }
};
