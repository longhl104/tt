void eratosthene(int n)
{
    maxn=1000001;
    int j;
    bool prime[maxn];
    memset(prime,false,sizeof(prime));
    for(int i=2;i<=sqrt(n);++i)
        if(!prime[i])
        {
            j=i*i;
            while(j<=n)
            {
                prime[j]=true;
                j+=i;
            }
        }
}
