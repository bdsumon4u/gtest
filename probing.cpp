#include <bits/stdc++.h>

using namespace std;

// 1 5 77 12 5 45 35 2 12 32

class Probing {
public:
    int N, M;
    int *arr;

    Probing(int N) {
        this->N = N;
        this->M = this->isPrime(N) ? N : this->nextPrime(N);
        this->arr = new int[this->M];
        fill_n(this->arr, this->M, -1);
    }

    // Function that returns true if n
    // is prime else returns false
    bool isPrime(int n)
    {
        // Corner cases
        if (n <= 1)  return false;
        if (n <= 3)  return true;

        // This is checked so that we can skip
        // middle five numbers in below loop
        if (n%2 == 0 || n%3 == 0) return false;

        for (int i=5; i*i<=n; i=i+6)
            if (n%i == 0 || n%(i+2) == 0)
                return false;

        return true;
    }

    // Function to return the smallest
    // prime number greater than N
    int nextPrime(int N)
    {
        // Base case
        if (N <= 1)
            return 2;

        int prime = N;
        bool found = false;

        // Loop continuously until isPrime returns
        // true for a number greater than n
        while (!found) {
            prime++;

            if (isPrime(prime))
                found = true;
        }

        return prime;
    }

    virtual int _hash(int num) {
        return num % M;
    }

    virtual int _prob(int pos) {

    }

    int insert(int num) {
        int pos = this->_hash(num);
        arr[this->_prob(pos)] = num;
    }

    bool search(int num) {
        int pos = _hash(num);
    }

    void print() {
        for (int i = 0; i < M; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Linear: public Probing
{
public:
    Linear(int N): Probing(N) {

    }

    int _prob(int pos) {
        for (int i = 0; i < this->M; i++) {
            if (this->arr[pos] == -1) break;
            pos = this->_hash(pos + 1);
        }
        return pos;
    }
};

class PlusThree: public Probing {
public:
    PlusThree(int N): Probing(N) {

    }

    int _prob(int pos) {
        for (int i = 0; i < this->M; i++) {
            if (this->arr[pos] == -1) break;
            pos = this->_hash(pos + 3);
        }
        return pos;
    }
};

class QuadProb: public Probing {
public:
    QuadProb(int N): Probing(N) {

    }

    int _prob(int pos) {
        for (int i = 1; true; i+=2) {
            if (this->arr[pos] == -1) break;
            pos = this->_hash(pos + i);
        }
        return pos;
    }
};

int main() {
    int x;
    Linear *linear = new Linear(10);
    PlusThree *pThree = new PlusThree(10);
    QuadProb *qProb = new QuadProb(10);
    for (int i = 0; i < 10; ++i) {
        cin >> x;
        qProb->insert(x);
    }
    qProb->print();
}
