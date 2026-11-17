class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == -2147483648 && dividend > -2147483648)
            return 0;

        if (dividend == divisor)
            return 1;

        if (divisor == -1 && dividend == -2147483648)
            return 2147483647;

        if (divisor == 1)
            return dividend;

        if (divisor == -1)
            return -dividend;

        int sig = 0;

        if (divisor < 0)
        {
            divisor = -divisor;
            sig--;
        }

        int q = 0;

        if (dividend < 0)
        {
            sig--;
            if (dividend == -2147483648)
            {
                q++;
                dividend += divisor;
            }
            dividend = -dividend;
        }

        while (dividend >= divisor)
        {
            dividend -= divisor;
            q++;
        }

        if (sig == -1)
        {
            return -q;
        }
        return q;
    }
};