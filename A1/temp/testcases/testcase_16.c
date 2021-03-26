//int* a = 10;
/*
float alpha = 20;
if(x){int temp = 3;}
*/
int a=5;
extern int a, **b;
int a=5,b=8,c;
int *x , ***y = &z;
int *var=6;
struct mystruct *ms=&var;
int *x = &3; // IS IT VALID?
int auto, static, inline;
int arr[3+2];
int arr[] = {(int)1,2};
int arr[3] = {"hello"};
char echo[3]="bash here";
int *p;
float *j;
void *static=&c;
short int a = 0;
float b = 0.0;
long double c = 03.3;
long long int d = 3;
long long e = 2;
long f = 3;
char g = 'c';
int x = 3;
int x = '\a';
int x[2] = {1,2,{1,2}};
int x = a = b = 1;

int fun(){
    x = 3;
    x = (y*3);
    x = x-+y;
    x = x+++y;
    x = x++-y;	
    p=&auto;
    j=0x1234;
    return(NULL);
    b[i-1] = i*i;
    b[b[i]+1] = x[x[x[1]]];
    *(x+3) = &y;
    x++;


    if(x<3){return;}else{break;}
    if(x){break;}
    if(a==9)
    {
        //NO-OP
    }
    if(a==1)
        x=3;
    else if(a==2)
        x++;
    else if(a==3)
        y=x*3+2;
    else
    {
        //NO-OP
    }


    switch(x+g){
        case 3+2: z=3; break;
        default: break;
    }
    switch(x){
        case 1:
            switch(y){
                case 2:
                default:
                break;
            }
        default:
        break;
    }

    for(int x=0;i<3;i++);
    for(a=1;a<=5;a++);
    for(;;);
}

int fun();
int *hh(char *p);

int main(int b)
{}
int main(int b)
{
	int auto=2,b=3,c;
	c = auto + b;
}

struct player
{
		int a;
		double c;
	} p1;

int main(int *argc, char* argv[]);