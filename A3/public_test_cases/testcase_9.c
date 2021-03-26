int sum(int n) {
    int a;
     if (n != 1)
        {
        return n + (sum(n-1));  
        }
    else
        return n;
}

int main() {
	int a;
	int b;
	a = 9;
    a++;
	b = sum(a);
	printf("%d\n", b);
	return 0;
}
