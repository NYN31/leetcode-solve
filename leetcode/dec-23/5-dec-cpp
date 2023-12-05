class Solution
{
public:
    int numberOfMatches(int n)
    {
        int total_match = 0;
        while (n > 1)
        {
            int match = n / 2;
            total_match += match;
            n = match + (n % 2);
        }
        return total_match;
    }
};

// Alternative

class Solution
{
public:
    int numberOfMatches(int n)
    {
        return n - 1;
    }
};