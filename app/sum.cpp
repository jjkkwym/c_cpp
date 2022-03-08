#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};

class Stduent
{
public:
    void get_info(void)
    {
        cout << "the name is " << this->name << endl;
        cout << "the age is "<< this->age << endl;
    }
private:
    int age = 18;
    char name[23] = "123";
};

int main()
{
    vector<int> nums = {1,2,1,2,4,2,1,2,1};
    Solution s1;
    int t = s1.pivotIndex(nums);
    cout << t << endl;
    Stduent Stduent1;
    Stduent1.get_info();
}

