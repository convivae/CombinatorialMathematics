//
// Created by convi on 2020/3/29.
//

#ifndef COMBINATORIALMATHEMATICS_CALLESSNUM_H
#define COMBINATORIALMATHEMATICS_CALLESSNUM_H

#include <algorithm>
#include <vector>
#include <cstring>

class CalLessNum {
private:
    int n;
    std::vector<int> arr;

    /**
     * x&(-x)，当x为0时结果为0；
     * x为奇数时，结果为1；
     * x为偶数时，结果为x中2的最大次方的因子。
     * @param x
     * @return
     */
    static int lowbit(int x) {
        return x & (-x);
    }

    void update(int pos, int delta) {
        while (pos <= n) {
            arr[pos] += delta;
            pos += lowbit(pos);
        }
    }

    int getSum(int pos) {
        int ret = 0;
        while (pos) {
            ret += arr[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }

public:
    std::vector<int> countSmaller(std::vector<int> &nums) {
        int len = nums.size();
        std::vector<int> ret(len);
        if (len == 0) {
            return ret;
        }
        int minn = 0x3f3f3f3f, maxx = -0x3f3f3f3f;
        for (int i = 0; i < len; ++i) {
            maxx = std::max(maxx, nums[i]);
            minn = std::min(minn, nums[i]);
        }
        n = maxx - minn + 2;
        arr.resize(n);

        for (int i = len - 1; i >= 0; --i) {
            ret[i] = getSum(nums[i] - minn);
            update(nums[i] - minn + 1, 1);
        }
        return ret;
    }
};


#endif //COMBINATORIALMATHEMATICS_CALLESSNUM_H
