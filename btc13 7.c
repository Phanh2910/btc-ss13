#include<stdio.h>
int hang(){
	int rows;
	printf("nhap so hang: ");
	scanf("%d",&rows);
	return rows; 
} 
int cot(){
	int cols;
	printf("nhap so cot: ");
	scanf("%d",&cols);
	return cols;
}
void mang(int rows,int cols,int arr[rows][cols]){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			printf("gia tri arr[%d][%d]= ",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
}
void in(int rows,int cols,int arr[rows][cols]){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			printf("arr[%d][%d]= %d\n",i,j,arr[i][j]);
		}
	}
}
int main(){
	int rows=hang();
	int cols=cot(); 
	int arr[rows][cols];
	mang(rows,cols,arr);
	in(rows,cols,arr);
	return 0;
} 
