int main() {
	int a;
	int b;
	int c;
	a = 1054;
	b = 1064;
	c = (a >= b);
	c = !(c);
	scanf("%d",&c);
	if (c) {
		int d;
		printf("%d\n", a);
		d = a;
		a = b;
		b = d;
	}else{
		printf("%d\n", b);
	}
	return 0;
}
