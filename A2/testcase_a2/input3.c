
int main()
{
     int num;
	 int x;
	 int *p;
	 p = &num;
//sizeof operator
	 x = sizeof(p);

//switch case	
     switch(num+2)
     {
         case 1:
           printf("%d", num);
         case 2:
           printf("%d", num);
         case 3:
           printf("%d", num);
         default:
           printf("%d", num);
    }
    return 0;
}
