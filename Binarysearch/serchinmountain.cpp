#include <bits/stdc++.h>
using namespace std;
// infinity array
typedef long long ll;

int orderogniostic(vector<ll> arr, int target, int low, int high)
{
    bool isasc = arr[low] < arr[high];
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        
        }

        if (isasc)
        {
            if (arr[mid] > target)
            {

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (arr[mid] < target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int peakofthemountain(vector<ll> arr)
{
    ll low = 0;
    ll high = arr.size() - 1;
    while (low < high)
    {
        ll mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{

    vector<ll> arr = {1, 2, 3, 5, 6, 4, 3, 2};
    ll target;
    cin >> target;
    ll peak = peakofthemountain(arr);
    ll firstpart = orderogniostic(arr, target, 0, peak);
    ll lastpart = orderogniostic(arr, target, peak + 1, arr.size()-1);
    if (firstpart != -1)
    {
        cout << firstpart << endl;
    }
    else
    {
        cout << lastpart << endl;
    }

    return 0;
}