#include<stdio.h>
#include<string.h>
int main(){
   int N,i,j,k,z,m,n,x,y,p,l,t,s,sum1,sum2,sum;
    char str[20];
    scanf("%d",&N);
    int a[N][N];
    int b[N][N];
    int c[N][N];
    int d[N][N];
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        scanf("%d",&a[i][j]);
        }
	}
		while(1)
		{
		scanf("%s",str);
		if(strcmp(str,"TRANSLATE")==0){
		for(m=0;m<N;m++){
            for(n=0;n<N-1;n++){
                b[m][n]=a[n][m];
                printf("%d ",b[m][n]);
            }b[m][n]=a[n][m];
				printf("%d\n",b[m][n]);
	 	} 
		}
		else if(strcmp(str,"ADD")==0){
		    for(k=0;k<N;k++){
                for(z=0;z<N;z++){
                scanf("%d",&c[k][z]);
                }
		    }
			for(m=0;m<N;m++){
                for(n=0;n<N-1;n++){
				  b[m][n]=a[m][n]+c[m][n];
                  printf("%d ",b[m][n]);
                }b[m][n]=a[m][n]+c[m][n];
				  printf("%d\n",b[m][n]);
	 	    }
		}
		else if(strcmp(str,"MULTIPLY")==0){
		       for(x=0;x<N;x++){
                   for(y=0;y<N;y++){
                    scanf("%d",&d[x][y]);
                    }
		        }		          
		        for(m=0;m<N;m++){
                    for(n=0;n<N;n++){
                          b[m][n]=0;
						for(s=0;s<N;s++){
						   b[m][n]+=a[m][s]*d[s][n];
						} 
					} 
                    }
				for(k=0;k<N;k++){
				for(z=0;z<N-1;z++){
					printf("%d ",b[k][z]);
				}printf("%d\n",b[k][z]);
				} 
		}
	    else if(strcmp(str,"SUM")==0){ 
		       sum1=0;sum2=0;
			for(t=0;t<N;t++){
               sum1+=a[t][t];
                sum2+=a[t][N-1-t];
	 	    }
			sum=sum1+sum2;
	 	    printf("%d\n",sum);
		}
		else if(strcmp(str,"BREAK")==0)
		    break;
            
		for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                a[i][j]=b[i][j];
            }
		}
	    
		}
	    return 0;
}  		