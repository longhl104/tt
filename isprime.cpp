bool isprime(int n)
{
    int k,sqrtn;
    if(n==2||n==3)
        return true;
    if(n==1||n%2==0||n%3==0)
        return false;
    sqrtn=sqrt(n);
    k=-1;
    while(k<=sqrtn)
    {
        k+=6;
        if(n%k==0||n%(k+2)==0)
            break;
    }
    return(k>sqrtn);
}
