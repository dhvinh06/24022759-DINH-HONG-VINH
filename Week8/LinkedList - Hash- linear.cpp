#include <iostream>
#include <vector>
#include <string>
#include <functional>

class LinearProbingHashST {
public:
    int M;
    std::vector<int> data;
    std::vector<bool> occupied;

    int hash(int val) {
        return (std::hash<int>{}(val)) % M;
    }

public:
    LinearProbingHashST(int M = 30001) : M(M) {
        data.resize(M, 0);
        occupied.resize(M, false);
    }

    bool contains(int val) {
        for (int i = hash(val); occupied[i]; i = (i + 1) % M) {
            if (data[i] == val) {
                return true;
            }
        }
        return false;
    }

    void add(int val) {
        int i;
        for (i = hash(val); occupied[i]; i = (i + 1) % M) {
            if (data[i] == val) {
                return;
            }
        }

        data[i] = val;
        occupied[i] = true;
    }

    void remove(int val) {
        int i = hash(val);
        while (occupied[i]) {
            if (data[i] == val) {
                break;
            }
            i = (i + 1) % M;
        }
        if (!occupied[i]) return;

        occupied[i] = false;

        i = (i + 1) % M;
        while (occupied[i]) {
            int valToRehash = data[i];
            occupied[i] = false;
            add(valToRehash);
            i = (i + 1) % M;
        }
    }
};
