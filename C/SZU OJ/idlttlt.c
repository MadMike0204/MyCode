int main()
{
	int T;
	scanf("%d\n",&T);
	while(T--){
        int m,n,i,j,sum,temp;

        scanf("%d",&m,&n);

        for(i=1;i<n;i++){
            temp=0;
            for(j=2;j<i;j++){
                if(i%j==0){
                    printf("NO");
                    temp++;
                }
            }
	}
	if(temp==0){
	    sum+=i;
	    printf("%d\n%d",i,sum);	
	}	
	}
	return 0;	
}