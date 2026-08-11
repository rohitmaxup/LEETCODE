class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        int i = num.size() - 1;

        while (i >= 0 && k > 0) {
            num[i] += k % 10;
            k /= 10;

            if (num[i] >= 10) {
                num[i] -= 10;
                k++;
            }

            i--;
        }

        while (k > 0) {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }

        return num;
    }
};