//Arrays + increment + composite functions

int fib(int x)
{
	int a[2];
	int n;
	if (x == 0)
		return 0;
	a[0] = 0;
	a[1] = 1;
	n = x;
	while(n > 1)
	{
		int temp;
		temp = a[1];
		a[1] = (a[1]) + (a[0]);
		a[0] = temp;
		n--;	
	}
	return a[1];
}

int printintt(int x)
{
	printf("%d\n", x);
    return 0;
}

int main()
{
    int a;
	a = printintt(fib(10));
}
