struct Distance{
    int feet;
    float inch;
};

int main() {
    struct Distance d1;
	struct Distance *d2;
	int x;
	d1.feet = 10;
	d1.inch = 2.4;
	x = fib(0);
//Three way comparison operator
	d2->feet = ( x <=> 0 );
	
	
}
int fib(int n) {
    if ((n == 0)||(n == 1))
        return n;
    else
        return (fib(n-1)) + (fib(n-2));
}
