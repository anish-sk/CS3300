int main() {
	int a;
	int b;
	int c;
	a = 995;
	b = 1064;
	c = a == b;
	scanf("%d",&a);
	if (c) {
		printf("%d\n", a);
	}
	else {
		c = 1;
		printf("%d\n", b);
	}
	return 0;
}
