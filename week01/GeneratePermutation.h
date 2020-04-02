//
// Created by convi on 2020/3/24.
// 排列的生成算法
//

#ifndef COMBINATORIALMATHEMATICS_GENERATEPERMUTATION_H
#define COMBINATORIALMATHEMATICS_GENERATEPERMUTATION_H

#include <utility>
#include <vector>
#include <string>
#include <sstream>

class GeneratePermutation {

protected:
    std::string _sequence;  //a(n-1) to a(1)
    std::string _permutation;   //全排列
    std::vector<std::string> _permutations; //所有的全排列

    GeneratePermutation() {
        _permutation.clear();
        _sequence.clear();
        _permutations.clear();
    }

    virtual std::string getNextPermutation() = 0;

public:
    // 返回所有的全排列
    virtual std::vector<std::string> getPermutations(int n) = 0;

    // 返回下一个全排列
    virtual std::string getNextPermutation(const std::string &p) = 0;
};


#endif //COMBINATORIALMATHEMATICS_GENERATEPERMUTATION_H
