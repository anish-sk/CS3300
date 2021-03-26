int main()
{
	int x;
	int y;
	int z;
    x = 10;
	scanf("%d", &y);
	z = (x + y)*(x + y);
	if(y == 1)
	{
		scanf("%d", &x);
		y = (x + y)*(x + y);
		printf("%d\n", x);
		printf("%d\n", y);
	}
	else
	{
		y = (x + y)*(x + y);
		printf("%d\n", x);
		printf("%d\n", y);
	}
	return 0;
}
