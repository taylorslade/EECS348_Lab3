/*
Taylor Slade
KU ID: 3079517
purpose: lab 3 part one
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void months(int Num){
	char *name_months[] = {"Jan.", "Feb.", "March", "April", "May", "June","July", "Aug.", "Sept.", "Oct.", "Nov.", "Dec."};
	printf("%s", name_months[Num]);
}
void monthlysales(float sales[], int len){
    printf("Month		Sales\n");
    for(int x = 0; x < len; ++x){
        months(x);
        printf("\t\t$%.2f\n", sales[x]);
    }
}

void sales_summary(float sales[], int len){
	float min = sales[0];
	float max = sales[0];
	int min_index = 0;
	int max_index = 0;
	float total = sales[0];
	
	for(int i = 0;i<len; ++i){
		if (sales[i]<min){
			min = sales[i];
			min_index = i;
		}
		if (sales[i]>max){
			max = sales[i];
			max_index = i;
		}
		total += sales[i];
	}

	float avg = total / len;

	printf("Minimum sales: $%.2f\t(", min);
	months(min_index);
	printf(")\nMaximum sales: $%.2f\t(", max);
	months(max_index);
	printf(")\nAverage Sales: $%.2f", avg);
}

void sixmonthavg(float sales[], int len){
	float total;
	for (int i=0; i<len; ++i) {
		months(i);
		printf("-");
		months(i+5);
		for (int j=i; j<i+5; ++j) {
			total += sales[j];
		}
		printf("\t$%.2f\n", total/6);
		total = 0.0;
	}
}

void hightolow(float sales[], int len) {
	float hightolow[12];
    int index[12];
    for(int i = 0; i < len; ++i){
        hightolow[i] = sales[i];
        index[i] = i;
    }
    for(int i = 0; i < len; ++i){
        for(int j = i + 1; j < len; ++j){
            if(hightolow[i] < hightolow[j]){
                float x = hightolow[i];
                hightolow[i] = hightolow[j];
                hightolow[j] = x;
                int myNum = index[i];
                index[i] = index[j];
                index[j] = myNum;
            }
        }
    }
    printf("  Month       Sales\n");
    for(int i = 0; i < len; ++i){
        months(index[i]);
        printf("\t$%.2f\n", hightolow[i]);
    }
}

int main(){
    FILE* inputFile;
    inputFile = fopen("input1.txt", "r");

	if (inputFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }

    float sales_nums[12];

	for(int i = 0; i < 12; i++){
        fscanf(inputFile, "%f", &sales_nums[i]);
    }
	fclose(inputFile);

	printf("Monthly Sales report for 2022: \n");
	monthlysales(sales_nums, 12);
	printf("\n\nSales Summary:\n");
	sales_summary(sales_nums, 12);
	printf("\n\n\nSix Month Moving Average Report: \n");
	sixmonthavg(sales_nums, 7);
	printf("\n\nSales Report (Highest to Lowest): \n");
	hightolow(sales_nums, 12);
}