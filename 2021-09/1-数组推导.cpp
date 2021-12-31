#include<iostream>
using namespace std;
const int maxn=100+5;
int b[maxn];
int sum_max=0;
int sum_min=0;
int main(){
	int n=0;
	scanf("%d",&n);
	
	scanf("%d",&b[0]);
	int temp=b[0];
	
	sum_max=b[0];sum_min=b[0];
	
	for(int i=1;i<n;++i){
		scanf("%d",&b[i]);
		if(b[i]>b[i-1]){
			sum_max+=b[i];
			sum_min+=b[i];
		}else{
			sum_max+=b[i];
			sum_min+=0;
		}
	}
	
	printf("%d\n%d",sum_max,sum_min);
	
	return 0;
}
