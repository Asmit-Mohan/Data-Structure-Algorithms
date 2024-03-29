/* Approach 1 [Recursive] */

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a % b);  
    }    
}

/* One Liner Recursive */

int gcd(int a, int b)
{
    return B==0?A:gcd(B,A%B);    
}

/* Approach 2 [Iterative] */

int gcd(int a, int b)
{
    int result = min(a,b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result--;
    }
    return result;
}
