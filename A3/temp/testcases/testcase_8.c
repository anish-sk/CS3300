int foo (int q) {
	int x;
	x = -3;
	q = x+1;
    x = x+1;
	return q;
}

int check(int a,int b,int c,int d,int e,int f){
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",c);
	return a+(b+e);
}

int main() {
	int a;
	int b;
	a = 13;
	b = foo(a);
	a = check(a,b,b,a,a,b);
	printf("%d\n", a);
	return 0;
}
