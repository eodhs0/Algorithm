/* Problem 70 */
class Solution {
public:
    int climbStairs(int n) {
        int a[10000] = {0};
        
        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        else if(n == 3)
            return 3;
        else
        {
            a[0] = 1;
            a[1] = 2;
            a[2] = 3;
            for(int i = 4; i <= n; i++)
            {
                a[i-1] = a[i-3] + a[i-2];
            }
            return a[n-1];
        }
    }
};