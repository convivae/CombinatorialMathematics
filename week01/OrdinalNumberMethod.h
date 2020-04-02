//
// Created by convi on 2020/3/24.
// 序数法
//

#ifndef COMBINATORIALMATHEMATICS_ORDINALNUMBERMETHOD_H
#define COMBINATORIALMATHEMATICS_ORDINALNUMBERMETHOD_H

#include <utility>

#include "GeneratePermutation.h"

class OrdinalNumberMethod : public GeneratePermutation {
protected:
    std::string getNextPermutation() override;

public:
    std::vector<std::string> getPermutations(int n) override;

    std::string getNextPermutation(const std::string &p) override;

    // 给定全排列, 返回对应的 an-1 到 a1
    std::string getSequenceFromPermutation(const std::string &p);

    // 给定 an-1 到 a1, 返回对应的全排列
    std::string getPermutationFromSequence(const std::string &seq);

    // 从数字得到序数法相应的系数
    static std::string getAnToA1(int num);

    std::string getNextSequence(const std::string &seq);
};


#endif //COMBINATORIALMATHEMATICS_ORDINALNUMBERMETHOD_H
