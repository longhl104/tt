int dem,tong = 1,so_uoc=1;
for( int i = 1; i*i<=n; i++)
    {
     tam=n; dem=0;
     while(tam% i ==0&&nguyento(i) ) {
           dem ++;
           tam/=i;
           }
     if(dem!=0){
           so_uoc*=dem+1;
           tong*=(pow(i,(dem+1)-1)/(i-1);
           }
     }
     printf("So uoc so la %d \n",so_uoc);
     printf("Tong uoc so la %d \n",tong);
