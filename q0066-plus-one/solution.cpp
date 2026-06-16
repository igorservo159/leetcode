#include <vector>

using namespace std;

class Solution {
public:
    inline vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (auto it = digits.end() - 1; it >= digits.begin(); --it) {
            if (*it + carry == 10) {
                *it = 0;
                continue;
            }

            ++(*it);
            carry = 0;
            break;
        }

        if (carry) digits.insert(digits.begin(), carry);

        // vector<int> result;
        // result.push_back(1);

        // if (digits[0] == 0) {
        //     for (auto i : digits) {
        //         result.push_back(i);
        //     }

        //     return result;
        // }

        return digits;
    }
};
