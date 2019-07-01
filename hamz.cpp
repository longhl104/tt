int l,r;
    z[0]=0;
    for(int i=1,l=0,r=0;i<n;++i)
    {
        z[i]=min(z[i-l],max(0,r-i+1));
        while(s[z[i]]==s[i+z[i]])
            ++z[i],l=i,r=i+z[i]-1;
    }
