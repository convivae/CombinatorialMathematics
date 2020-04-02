//
// Created by convi on 2020/3/31.
// 字典序法
//

#ifndef COMBINATORIALMATHEMATICS_DICTIONARYORDERMETHOD_H
#define COMBINATORIALMATHEMATICS_DICTIONARYORDERMETHOD_H

#include "GeneratePermutation.h"

class DictionaryOrderMethod : public GeneratePermutation {
private:
    std::vector<bool> mark;

    void perm(int N,int index, int n);

public:
    std::vector<std::string> getPermutations(int n) override;

    std::string getNextPermutation(const std::string &p) override;

protected:
    std::string getNextPermutation() override;
};


#endif //COMBINATORIALMATHEMATICS_DICTIONARYORDERMETHOD_H
