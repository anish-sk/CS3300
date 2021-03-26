int main() {
	int a;
	int b;
	int c;
	a = 33;
	c = 15;
	scanf("%d",&b);
	printf("%d\n", a);
	b = c;
	printf("%d\n", b);
	a=c*b;
	c=a/b;
	b=a+c;
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",c);
	return 0;
}
