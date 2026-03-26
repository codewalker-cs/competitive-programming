/*
 * Problem: Friendly Numbers
 * Platform: Codeforces
 *
 * Intuition:
 * We are given the equation:
 *      y - d(y) = x
 * where d(y) is the sum of digits of y.
 *
 * Rearranging:
 *      y = x + d(y)
 *
 * This means y is slightly larger than x, and the difference is equal
 * to the digit sum of y.
 *
 * Instead of iterating over all possible y, we iterate over possible
 * digit sums (i), and construct:
 *      y = x + i
 *
 * Then we simply check if:
 *      digit_sum(y) == i
 *
 * If true, then:
 *      y - d(y) = x  → valid "friendly number"
 *
 * Since maximum digit sum for y ≤ 1e9 is small (~81), we safely check
 * for i in range [1, 100].
 *
 * Time Complexity:
 *      O(t * 100 * digits) ≈ O(t)
 *
 * Space Complexity:
 *      O(1)
 */

#include <iostream>
using namespace std;

bool checksumd(long long y,int i)
{
    int sum=0;
    long long temp=y;
    while(temp!=0)
    {
        sum+=temp%10;
        temp/=10;
    }
    if(sum==i)
    {
        return true;
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        long long x;
        int count=0;
        cin>>x;
        for(int i=1;i<101;i++)
        {
            long long y=x+i;
            if(checksumd(y,i))
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
}
