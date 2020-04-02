//
// Created by convi on 2020/3/24.
//

#include "OrdinalNumberMethod.h"
#include "lib/CalLessNum.h"

std::vector<std::string> OrdinalNumberMethod::getPermutations(const int n) {
    std::string s(n - 1, '0');
    auto p = getPermutationFromSequence(s);
    while (!p.empty()) {
        this->_permutations.push_back(p);
        p = getNextPermutation();
    }
    return this->_permutations;
}

/**
 * 返回下一个全排列，若是最后一个返回空
 * @param seq
 * @return
 */
std::string OrdinalNumberMethod::getNextPermutation(const std::string &p) {
    auto seq = getSequenceFromPermutation(p);
    seq = getNextSequence(seq);
    this->_permutation = getPermutationFromSequence(seq);
    return this->_permutation;
}

/**
 * 返回下一个全排列，若是最后一个返回空
 * @return
 */
std::string OrdinalNumberMethod::getNextPermutation() {
    this->_permutation = getNextPermutation(this->_permutation);
    return this->_permutation;
}


/**
 * 给定全排列, 返回对应的 an-1 到 a1
 * @param seq
 * @return
 */
std::string OrdinalNumberMethod::getSequenceFromPermutation(const std::string &p) {
    int len = p.size();

    std::vector<int> vec_seq(len), vec_num(len);

    for (auto i = 0; i < len; i++) {
        vec_seq[i] = p[i] - '0';
    }

    auto cal = new CalLessNum();
    auto tmp = cal->countSmaller(vec_seq);

    for (int i = 0; i < len; i++) {
        vec_num[vec_seq[i] - 1] = tmp[i];
    }

    std::string ret;
    for (auto i = len - 1; i >= 1; --i) {
        ret.push_back(vec_num[i] + '0');
    }

    this->_sequence = ret;
    return ret;
}

/**
 * 给定 an-1 到 a1, 返回对应的全排列
 * @param num
 * @return
 */
std::string OrdinalNumberMethod::getPermutationFromSequence(const std::string &seq) {
    if (seq.empty())
        return seq;

    int len = seq.size() + 1; //共有 len 个数做全排列
    std::string s(len, '0');

    for (auto i = 0; i < len - 1; ++i) {
        auto c = seq.at(i) - '0';
        auto per_num = len - i;
        auto less_num = 0;
        for (auto j = len - 1; j >= 0; --j) {
            if (less_num == c && s[j] == '0') {
                s[j] = per_num + '0';
                break;
            }
            if (per_num > s[j] - '0')
                less_num++;
        }
    }

    for (auto i = 0; i < len; ++i) {
        if (s[i] == '0') {
            s[i] = '1';
            break;
        }
    }
    this->_permutation = s;
    return s;
}

std::string OrdinalNumberMethod::getAnToA1(int num) {
    std::stringstream ss;
    std::string str;

    int weight = 2;
    while (num / weight != 0) {
        auto r = num % weight;
        ss << r;
        num /= weight;
        weight++;
    }
    ss << num;
    ss >> str;
    return std::string(str.rbegin(), str.rend());
}

std::string OrdinalNumberMethod::getNextSequence(const std::string &seq) {
    std::string ret(seq);

    int len = seq.size();
    int carry = 1, coefficient = 1; // 进位，系数(0=<ak<=k,k=1,2,...n-1)
    for (int i = len - 1; i >= 0; --i) {
        if (seq[i] - '0' + carry > coefficient) {
            auto tmp1 = (seq[i] - '0' + carry) / (coefficient + 1);
            auto tmp2 = (seq[i] - '0' + carry) % (coefficient + 1);
            ret[i] = tmp2 + '0';
            carry = tmp1;
        } else {
            ret[i] += carry;
            carry = 0;
        }
        coefficient++;

        // 判断是否是最后一个
        if (seq[i] - '0' > len || (i == 0 && carry != 0)) {
            return std::string("");
        }
    }
    return ret;
}




