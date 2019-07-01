long long X(long long a,long long b)
{
    long long res=0;
    while(b>0){
    if((b%2)==1){
        res+=a;
        res%=md;}
    a*=2;
    a%=md;
    b/=2;}
    return res%md;
}
