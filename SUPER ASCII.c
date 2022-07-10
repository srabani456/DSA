#include<stdio.h>
#include<string.h>
int main ()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{		
		int a[26],len;
		for(i=0;i<26;i++)
		a[i]=0;
		char s[50];
		scanf("%s",s);
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			a[s[i]-97]++;
		}
		int flag=1;
		for( i=0;i<26;i++)
		{
			if(a[i]!=i+1 && a[i]!=0)
			{
				flag=0;
				printf("No\n");
				break;
			}
		}
		if(flag)
		printf("Yes\n");
	}
}
