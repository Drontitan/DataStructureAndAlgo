#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int splitarray(vector<ll> &nums, ll m)
{
    ll start = 0;
    ll end = 0;
    for (ll i = 0; i < nums.size(); i++)
    {
        start = max(start, nums[i]);
        end += nums[i];
    }

    // binary search
    while (start < end)
    {
        // try for the middle as the potential ans
        ll mid = start + (end - start) / 2;

        // calcaulte in how many pieces you can divide this max sum
        int sum = 0;
        ll pieces = 1;
        for (auto num : nums)
        {
            if (sum + mid)
            {
                // means you can not add these in to these sub array so make the new once
                // say you add these new subarray then sum =num
                sum = num;
                pieces++;
            }
            else
            {
                sum += num;
            }
        }
        if (pieces > m)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    
    return end; // here the start will be equal to the end
}

int main()
{

    return 0;
}