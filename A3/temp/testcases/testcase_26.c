int main()
{
	int a[100];
	int b;
	int i;
	i=0;
	while(i<100){
		a[i]=i+1;
		i++;
	}
	i=0;
	b=0;
	while(i<100){
		b=b+(a[i]);
		i++;
	}
	printf("%d\n", b);
}
