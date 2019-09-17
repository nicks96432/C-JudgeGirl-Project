 #include <stdio.h>
int main(void)
{
    int p=0,a,b,v,w,x,y,z,d=0,max__p=1,max__d=0;
    scanf("%d%d%d%d%d%d%d",&a,&b,&v,&w,&x,&y,&z);
    #ifdef DEBUG
    printf("%d %d %d %d %d %d %d\n",a,b,v,w,x,y,z);
    #endif
    for(p=1;p<2*b;p++){
		if(p<a){
			d=0;
		}
		else if(p<b){
			if(p%2==0)
			{
			d=w;
			}
			else
			{
			d=v;
			}
		}
		else{
			if(p%3==0)
			{
				d=x;
			}
			else if(p%3==1)
			{
				d=y;
			}
			else
			{
				d=z;
			}
		}
		if((float)d*max__p>p*max__d){
			max__p=p;
			max__d=d;
		}
	}
    printf("%d",max__p);
    return 0;
}