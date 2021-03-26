int b1(int b){

  if (b == 10) return 1;
  b++;
  return b1(b);
}



int fib(int num){
 int a;
 int b;
 int c;
 a = 0;
 b = 1;
 c = b1(b);
 if (num == 1) return a;
 if (num == 2) return b;
	while (num !=2 ) {
	int c;
	c = a;
	a = b;
	b = c+b;
	num--;
	}
	return b;
}
int main() {
	int a;
        a = 6;
	a= fib(40);
	printf("%d\n",a);
	return 0;
}
