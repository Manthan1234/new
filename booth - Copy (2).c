#include<stdio.h>
#include<stdlib.h>

int A[4],Q[4],M[4];
int q;

int shift()
{
	int i;
	q=Q[0];
	int temp=A[0];
	for(i=0;i<=2;i++)
	{
		A[i]=A[i+1];
	}
	for(i=0;i<=2;i++)
	{
		Q[i]=Q[i+1];
	}
	Q[3]=temp;
}

int binary(int arr[],int a)
{
	int i=0;
	int rem=0;
	a =abs(a);
	while(a>=0 && i<=3)
	{
		rem=a%2;
		arr[i]=rem;
		a=a/2;
		i++;
	}
}

int two_comp(int arr[])
{
	int i;
	for(i=3;i>=0;i--)
	{
		if(arr[i]!=0)
		{
			arr[i]=0;
		}
		else
		{
			arr[i]=1;
		}
	}
		
	//adding one
	i=0;
	int rem=0;
	while(i<=3)
	{
		int temp = arr[i];
		if(i!=0)
		{			
		arr[i]=(arr[i]+rem) % 2;
		rem=(temp + rem) / 2;
		i++;}
		else
		{
			arr[i]=(arr[i]+1)%2;
			rem=(temp+1)/2;
			i++;
		}
	}
}

int add()
{
	int i=0,rem=0;
    while(i<=3)
	    {
	    	int temp=A[i];
			A[i] = (A[i] + M[i] +rem) % 2;
		    rem = (temp + M[i] + rem) / 2;
		    i++;
		}
}

int print_arr(int arr[],int a)
{
	int i=3;
	printf("Binary equivalent of %d ",a);
	while(i>=0)
	{
		printf("%d",arr[i--]);
	}
}

int main()
{
	int a=0,m=0,i=0;

	printf("Enter an integer : ");
	scanf("%d",&m);
	printf("Enter another integer : ");
	scanf("%d",&a);
	
	//convert first in binary
	if(m>=0)
	{
		binary(M,m);
	}
	else
	{
		//first convert it into binary
		binary(M,m);
		
		//then its 2s complement
		two_comp(M);
	}

	//another no
	//convert first in binary
	if(a>=0)
	{
		binary(Q,a);
	}
	else
	{
		//first convert it into binary
		binary(Q,a);
		//then its 2s complement
		two_comp(Q);
	}

	print_arr(M,m);printf(" <-M\n");
	print_arr(Q,a);printf(" <-Q\nA -> ");
	for(i=3;i>=0;i--)
			{printf("%d",A[i]);}
	q=0;
	printf("\nq -> %d\n\n",q);
	
	int count=4;
	while(count>=1)
	{
		if(Q[0]==q)
		{
			shift();
			printf("\nAfter shift A : ");
			for(i=3;i>=0;i--)
			{printf("%d",A[i]);}
			printf("\nAfter shift Q : ");
			for(i=3;i>=0;i--)
			{printf("%d",Q[i]);}
			printf("\nAfter shift q : %d\n",q);
			printf("\n");
			count--;
		}
		else
		{
			if(Q[0]!=0)
			{
				two_comp(M);
				add();
				
				printf("After A<- A-M : ");
				for(i=3;i>=0;i--)
				{printf("%d",A[i]);}
				
				two_comp(M);
				
				shift();
				
				printf("\nAfter shift A : ");
				for(i=3;i>=0;i--)
				{printf("%d",A[i]);}
				printf("\nAfter shift Q : ");
				for(i=3;i>=0;i--)
				{printf("%d",Q[i]);}
				printf("\nAfter shift q : %d\n",q);
				printf("\n");
				
				count--;
			}
			else
			{
				add();
				
				printf("After A<- A+M : ");
				for(i=3;i>=0;i--)
				{printf("%d",A[i]);}
				
				shift();
				
				printf("\nAfter shift A : ");
				for(i=3;i>=0;i--)
				{printf("%d",A[i]);}
				printf("\nAfter shift Q : ");
				for(i=3;i>=0;i--)
				{printf("%d",Q[i]);}
				printf("\nAfter shift q : %d\n",q);
				printf("\n");
				
				count--;
			}
		}
	}

	printf("\n\nThe answer is : ");
	
	for(i=3;i>=0;i--)
	{
		printf("%d",A[i]);
	}
	for(i=3;i>=0;i--)
	{
		printf("%d",Q[i]);
	}
	printf("\n");
}
