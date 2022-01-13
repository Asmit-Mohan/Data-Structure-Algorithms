class Solution
{
public:
long long int nthFibonacci(long long int n)
{
long long int t[n+1] = {0};
t[0] = 0;
t[1] = 1;
for(int i = 2;i<=n;i++)
{
 t[i] = (t[i-1]+t[i-2])%1000000007;
}
return t[n];
}
};