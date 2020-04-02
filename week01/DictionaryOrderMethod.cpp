//
// Created by convi on 2020/3/31.
//

#include "DictionaryOrderMethod.h"
#include <iostream>

std::vector<std::string> DictionaryOrderMethod::getPermutations(const int n) {
    mark.resize(n + 1);
    this->_permutation.resize(n);
    perm(n, 0, n);
    return this->_permutations;
}

std::string DictionaryOrderMethod::getNextPermutation(const std::string &p) {
    //1.从后向前找第一个下降的位置
    int bound = 0;
    for (int i = p.size() - 1; i > 0; --i) {
        if (p[i] > p[i - 1]) {
            bound = i;
            break;
        }
    }
    if(bound == 0)
        return std::string("");

    //2. 从bound开始找比p[bound-1]大且最靠右的元素
    int k = 0;
    for (auto i = bound; i < p.size(); ++i) {
        if (p[i] > p[bound - 1])
            k = i;
        else
            break;
    }

    //3. 交换p[bound-1], p[k]的值
    std::string s(p);
    std::swap(s[bound - 1], s[k]);

    //4. bound后面的元素按升序排列
    std::string s_tmp(s.rbegin(), s.rbegin() + s.size() - bound);
    s.replace(bound, s.size(), s_tmp);

    this->_permutation = s;
    return s;
}

std::string DictionaryOrderMethod::getNextPermutation() {
    return getNextPermutation(this->_permutation);
}

void DictionaryOrderMethod::perm(int N, int index, int n) {
    if (n == 0) {
        this->_permutations.push_back(this->_permutation);
        return;
    } else {
        for (int i = 1; i <= N; ++i) {
            if (!mark[i]) {
                mark[i] = true;
                this->_permutation[index] = '0' + i;
                perm(N, index + 1, n - 1);
                mark[i] = false;
            }
        }
    }
}
