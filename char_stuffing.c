#include<stdio.h>
#include<string.h>
void main(){
	int i=0,j=0,n,pos;
	char a[20],b[50],u[50],ch;
	printf("Enter String: ");
	scanf("%s",&a);
	b[0]='x';
	b[1]='x';
	j=j+2;
	while(a[i]!='\0'){
		if(a[i]=='x' && a[i+1]=='x'){
			b[j]='x';
			b[j+1]='x';
			j+=2;
		}
		b[j]=a[i];
		i++;
		j++;
	}
	b[j]='x';
	b[j+1]='x';
	b[j+2]='\0';
	printf("\nframe after stuffing\n");
	printf("%s",b);
	i=0,j=0;
	while(b[i]!='\0'){
		if(b[i]=='x'&&b[i+1]=='x'){
			u[j]=b[i+1];
			i+=2;
		}
		u[j]=b[i];
		i++;
		j++;
	}
	u[j]='\0';
	printf("\nUnstuffed data is %s",u);
}
