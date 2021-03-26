long long int a, b, c;

int main(int *argc, char* argv[])
{
	long long a, i;
	long short b[10];
	for(i=1; i<=10; ++i) {
		b[i-1] = i*i;		// square
	}
	short double *c = b;
	i = 0;
	short void d= 0;
	while(i<10) {
		d = *(c + i);
	}
	printf("%d\n", d);	// print sum of values

	if(1)
		a++;
	else if(0)
		b++;
	else if(1)
		c++;
	else if(3)
	{
		if(1)
			a++;
		else if(0)
			b++;
		else
			c++;	
	}
	
	return 0;
}
