#include <iostream>
#include <vector>
using namespace std;
//提交部分
class Solution
{
    public:
        vector<int> twoSum(vector<int> nums,int target)
        {
            vector<int> Answer = {0,0};
            int x = nums.size();
            for(int i=0;i<(x-1);i++)
            {
                for(int j=i+1;(j<x);j++)
                {
                    if(nums[i] + nums[j] == target)
                    {
                        Answer = {i,j};
                        break;
                    }
                }
            }
            return Answer;
        }
};
//
void test()
{
    vector<int> arr = {1,8,6,3,5,33,98,3123,566};
    int target = 664;
    Solution T;
    cout << T.twoSum(arr,target)[0] << T.twoSum(arr,target)[1];
}

int main(){

    test();

}