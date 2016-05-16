/*
I, <KO Chi Keung>, am submitting the assignment for
an individual project.
I declare that the assignment here submitted is original except for
source material explicitly acknowledged, the piece of work, or a part
of the piece of work has not been submitted for more than one purpose
(i.e. to satisfy the requirements in two different courses) without
declaration. I also acknowledge that I am aware of University policy
and regulations on honesty in academic work, and of the disciplinary
guidelines and procedures applicable to breaches of such policy and
regulations, as contained in the University website
http://www.cuhk.edu.hk/policy/academichonesty/.
It is also understood that assignments without a properly signed
declaration by the student concerned will not be graded by the
teacher(s).
*/

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>


int midsquare(int n,int H){
	unsigned int square=n*n;
	square=square<<(32-H)/2;
	square=square>>(32-H);
	return square;
}

int main() {
	int c,d,e,i,j,k,N,b,s,H,n,key[100],**ht,insert,*search,min,max,*count;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d%d%d%d",&b,&s,&H,&n);
		for(j=0;j<n;j++)
			scanf("%d",&key[j]);
		ht=(int**)malloc(b*sizeof(int*));
		for(k=0;k<b;k++)
			ht[k]=(int*)malloc(s*sizeof(int));
		search=(int*)malloc(n*sizeof(int));
		count=(int*)malloc(n*sizeof(int));
		for(j=0;j<b;j++){
			for(k=0;k<s;k++){
				ht[j][k]=-1;
			}
		}
		max=-1;
		min=9999;
		for(c=0;c<n;c++){
			d=0;
			insert=0;
			count[c]=0;
			while(d<b && insert==0){
				e=0;
				while(e<s && insert==0){
					if(H==1){
						if(ht[(key[c]+d)%b][e]==-1){
							ht[(key[c]+d)%b][e]=key[c];
							search[c]=(key[c]+d)%b;
							count[c]++;
							insert=1;
						}
						else{
							e++;
							if(e<s)
								count[c]++;
						}
					}
					else{
						if(ht[midsquare(key[c],H)][e]==-1){
							ht[midsquare(key[c],H)][e]=key[c];
							search[c]=midsquare(key[c],H);
							count[c]++;
							insert=1;
						}
						else{
							e++;
							if(e<s)
								count[c]++;
						}
					}
				}
				if(insert==0){
					d++;
					count[c]++;
				}
			}
			printf("%d %d %d\n",key[c],search[c],count[c]);
			if(count[c]>max)
				max=count[c];
			if(count[c]<min)
				min=count[c];
		}
		printf("%d %d\n",max,min);
		free(ht);
		free(search);
		free(count);
	}
	return 0;
}