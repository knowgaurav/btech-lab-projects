/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {4, 2, 2, 3, 3, 3};

    int L = 0, R = 0, ans = 0;

    // while(R < nums.size()){
    //     if(nums[R] != nums[L]){
    //         L = R;
    //     }else{
    //         ans = max(ans, R-L+1);
    //     }

    //     R++;
    // }

    // int count = 0;

    // for(int i=0; i<nums.size(); i++){
    //     if(i==0) count++;
    //     else if(nums[i] != nums[i-1]){
    //         count = 1;
    //     }else{
    //         count++;
    //         ans = max(ans, count);
    //     }
    // }

    // cout << ans << endl;

    // Sliding Window of Fixed size
    vector<int> sameKElements = {2, 3, 2, 1, 2, 1};

    int k = 2, n = sameKElements.size();
    bool flag = false;

    for (int l = 0; l < sameKElements.size(); l++)
    {
        for (int r = l + 1; r < min(l + k, n); r++)
        {
            if (sameKElements[l] == sameKElements[r])
            {
                flag = true;
                break;
            }
        }
    }

    if (flag)
        cout << "Same K Elements are present" << endl;
    else
        cout << "Not present" << endl;

    return 0;
}
