#include<stdio.h>
#include<stdlib.h>
#define max 100
void main(){
	char in[max],stuff[max],destuff[max];
	int count=0,i=0,j=0;
	printf("Enter the input character string (0's and 1's): ");
	scanf("%s",&in);
	while(in[i]!='\0'){
		stuff[j]=in[i];
		if(in[i]=='1'){
			count++;
		if(count==5){
			j++;
			stuff[j]='0';
			count=0;
		}
	    }else{
		count=0;
	    }
	    i++;
	    j++;
    }
	stuff[j]='\0';
	printf("\nAfter stuffing: %s\n",stuff);
	i=0,j=0;
	while(stuff[i]!='\0'){
		destuff[j]=stuff[i];
		if(stuff[i]=='1'){
			count++;
		if(count==5){
			if(stuff[i+1]=='0'){
				i++;
			}
			count=0;
		}
	}else{
		count=0;
	}
	i++;
	j++;
}
	destuff[j]='\0';
	printf("After destuffing: %s",destuff);
}
