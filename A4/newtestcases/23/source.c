int main() {

	int a;
	int b;
	int c;
	int z;

	scanf("%d", &a);
	scanf("%d", &b);
	c = (a + b) + (128*(a*b));

	if(32*b){
		z = 5;
	}
	else{
		z = (12 + (4*a));
	}
	
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", z);

	return 0;
}
