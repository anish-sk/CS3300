int main() {
	int a; 
	int b;
	int c;
	b = 0;
	a = 0;
	c = a || b;
	scanf("%d",&c);
	printf("%d\n", c);
	a = 1;
	b = 1;
	c = b || a;
	printf("%d\n", c);
	return 0;
}
