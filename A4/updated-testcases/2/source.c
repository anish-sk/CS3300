int main() {
	int a;
	int b;
	int c;
	a = 42;
	b = 51;
	

	scanf("%d",&b);
	// printf("%d\n",b);
	if (a <= b) {
		printf("%d\n", a);
		c = 1;
	}
	else {
		printf("%d\n", b);
		scanf("%d",&c);
	}
	
	return 0;
}
