#include <iostream>
#include "week01/OrdinalNumberMethod.h"
#include "week01/DictionaryOrderMethod.h"
#include "week01/TranspositionMethod.h"

int main() {
    // 序数法
//    auto test01 = OrdinalNumberMethod();
//    auto ans = test01.getAnToA1(4000);
//    std::cout << ans << std::endl;
//
//    auto as = test01.getPermutationFromSequence("2020");
//    std::cout << as << std::endl;
//
//    std::cout << test01.getSequenceFromPermutation("35124") << std::endl;
//
//    auto s = test01.getNextSequence("00000");
//    while (!s.empty()) {
//        std::cout << s << std::endl;
//        s = test01.getNextSequence(s);
//    }

    //字典序法
//    auto test02 = new DictionaryOrderMethod();
//    auto seq = test02->getPermutations(5);
//    for (auto i : seq)
//        std::cout << i << std::endl;
//
//    std::string s("12345");
//    while (!s.empty()){
//        std::cout << s << std::endl;
//        s = test02->getNextPermutation(s);
//    }

    // 换位法
    auto test03 = new TranspositionMethod();

//    for(auto i : test03->getPermutations(4))
//        std::cout << i << std::endl;
//    for(auto i : test03->getPermutations(5))
//        std::cout << i << std::endl;
//    for(auto i : test03->getPermutations(4))
//        std::cout << i << std::endl;

    auto s_3 = std::string("123");
    while (!s_3.empty()){
        std::cout << s_3 << std::endl;
        s_3 = test03->getNextPermutation(s_3);
    }
}
