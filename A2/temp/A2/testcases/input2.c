extern int var; 
int main() 
{
float n;
n = 5.0; 
 var = 10; 
do {
 var = var + n;
 n--;
}while( n>0 );
 return 0; 
} 
