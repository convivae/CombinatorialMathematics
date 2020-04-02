//
// Created by convi on 2020/4/2.
//

#include <iostream>
#include "TranspositionMethod.h"

void TranspositionMethod::perm(std::vector<int> &A, std::vector<int> &D, std::vector<int> &E, int n) {
    if ((int) this->_permutations.size() == this->sum_count)
        return;

    std::string s;
    for (int i = 1; i <= n; i++) {
        s.push_back(A[i] + '0');
    }
    this->_permutations.emplace_back(s);

    int q = 0, k = n;
    while (k > 1) {
        D[k] += E[k];
        int p = D[k];
        if (p == k) {
            E[k] = -1;
        } else if (p == 0) {
            E[k] = 1;
            q++;
        } else {
            p += q;
            int r = A[p];
            A[p] = A[p + 1];
            A[p + 1] = r;
            perm(A, D, E, n);
        }
        --k;
    }
}

std::vector<std::string> TranspositionMethod::getPermutations(int n) {
    init(n);
    perm(A, D, E, n);
    return this->_permutations;
}

std::string TranspositionMethod::getNextPermutation(const std::string &p) {
    if (this->_permutations.empty())
        getPermutations(p.size());
    for (int i = 0; i < (int)this->_permutations.size() - 1; i++) {
        if (this->_permutations[i] == p) {
            return this->_permutations[i + 1];
        }
    }
    return std::string("");
}

std::string TranspositionMethod::getNextPermutation() {
    return std::__cxx11::string();
}

void TranspositionMethod::init(int n) {
    A.resize(n + 1);
    D.resize(n + 1);
    E.resize(n + 1);
    this->_permutations.clear();
    this->_permutation.clear();

    for (int i = 1; i <= n; i++) {
        A[i] = i;   // 存储结果
        D[i] = i;   // 中间过程
        E[i] = -1;  // 初始的方向全部向左
    }

    // 计算一下总次数
    int sum = 1;
    for (int i = 2; i <= n; i++) {
        sum *= i;
    }
    this->sum_count = sum;
}



