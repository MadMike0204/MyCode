#include<stdio.h>
int main(){
int N,i,j,m,Xi,Yj,p,t,k;
    scanf("%d",&N);
    int magic[N][N]={0};
    m=N*N;
    i=0;
    j=(N-1)/2;//确定第一个数字的位置
	for(k=1;k<=m;k++){
	   magic[i][j]=k;//判断右上方数字的位置  
	   Xi=(i-1+N)%N;//防止i-1的时候小于零而越界 
	   Yj=(j+1)%N;//防止j+1超过N-1而越界 
	   if(magic[Xi][Yj]==0){//右上方无值
	    i=Xi;
		j=Yj;
		}  
		else//右上方有值，填在正下方
		i=(i+1)%N;//防止超过N-1而越界 
}
	for(t=0;t<N;t++){
		for(p=0;p<N;p++){
			printf("%d",magic[t][p]);
			if(p!=N-1){
			printf(" ");
		    }
			else
			printf("\n");
			}
		}	return 0;
}