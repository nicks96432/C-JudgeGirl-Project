#include <stdio.h>
#include <string.h>
int main()
{
	int i, n, m, num[7],ans=0;
	scanf("%d %d", &n, &m);
	num[0] = m / 1000000;
	num[1] = (m % 1000000) / 100000;
	num[2] = (m % 100000) / 10000;
	num[3] = (m % 10000) / 1000;
	num[4] = (m % 1000) / 100;
	num[5] = (m % 100) / 10;
	num[6] = m % 10;
	for(i=0;i<n-1;i++){
		if(num[i]==n/10&&num[i+1]==n%10){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}