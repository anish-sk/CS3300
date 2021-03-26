int func(int n) {
   
if ((n > 0) && (n < 5))
  n++;
//switch statement

	switch(n) {
		case 1 : 
		  n = n + 3;
		  break;
		case 2 :
		  n = n -1;
		default :
		 n = n + 1;
	}

//while statement

while ( n > 2)
{
	n = n + 2;
	
}
    return n;
}

int main() {
    int x;
	x = func(10);
}


