int d[10];
int foo (int c, int b[]){
    return b[c];
}
int main(){
    int i;
    i=0;
    if(i == 0)
    i = i+1;
    while(i<10){
        i = i+1;
    }
    return foo (4, d);
}
//int main() {
//    struct Distance d1;
//	struct Distance *d2;
//	int x;
//	d1.feet = 10;
//	d1.inch = 2.4;
//	x = fib(0);
////Three way comparison operator
//	d2->feet = ( x <=> 0 );
//	
//	
//}
//int foo (int c, int b[]){
//      a=10;
//}
