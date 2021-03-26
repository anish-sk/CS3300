int main() {
	int temp1; 
	int temp2;
	int temp3;
	int value;
	int temp4;
	int temp5;
	temp1 = 72;
	temp2 = 18;
	temp3 = 1;
	value = 1;
	scanf("%d",&temp1);
	printf("%d\n",temp1);
	temp4 = temp1 != temp2;
	printf("%d\n",temp4);
	if(temp4){
		printf("%d\n",value);
	}
	temp5 = temp3 && temp4;
	printf("%d\n",temp3);
	printf("%d\n",temp5);
	return 0;
}
