//
// Created by convi on 2020/4/2.
// 换位法
//

#ifndef COMBINATORIALMATHEMATICS_TRANSPOSITIONMETHOD_H
#define COMBINATORIALMATHEMATICS_TRANSPOSITIONMETHOD_H

#include "GeneratePermutation.h"
#include <vector>

class TranspositionMethod : public GeneratePermutation {
private:
    int sum_count;  //总数
    std::vector<int> A, D, E;

    void perm(std::vector<int> &A, std::vector<int> &D, std::vector<int> &E, int n);

    void init(int n);

public:

    std::vector<std::string> getPermutations(int n) override;

    std::string getNextPermutation(const std::string &p) override;

protected:
    std::string getNextPermutation() override;
};


#endif //COMBINATORIALMATHEMATICS_TRANSPOSITIONMETHOD_H
