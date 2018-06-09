/*
 ============================================================================
 Name        : ualikhan.tursinov.c Author      : uali
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{  //let's define, what an ordinary order consist of
	int sale_id;
	int dd;
	int qty;
	char type[88]; //it does not matter, what is massive  size. in my case 88
	double total_cost;
	char arrangement[88];
	char payment[88];
	int delivery;
	char courier[88];
} info_of_an_order;

int main () {
	FILE *file;
	file = fopen ("flower_sales.txt", "r");
	if (file==NULL) {
		printf("troubleshoot with opening or file is missing.");
		return 0;
	}
	info_of_an_order an_order[200];	      //rewriting to simpler name
	int Day;        //let's declare the main variable, which will be inputed by user
	int k;
	k=0;            //k is actually, the number of order. Indeed. the first order must be labeled 1, but in array, it is 0

	do {
	fscanf(file, "%i %i %i %s %lf %s %s %i %s", &an_order[k].sale_id, &an_order[k].dd, &an_order[k].qty, an_order[k].type,
			&an_order[k].total_cost, an_order[k].arrangement, an_order[k].payment, &an_order[k].delivery, an_order[k].courier);
	k++;
	} while (!feof(file));

	int l;
	while (1) {
		printf("Enter the day you want to check");
		scanf("\n %i",&Day);
		if (Day>31) {
		break;}
		int sum1;
		sum1=0;
		for (l=0; l<k; l++) {
			if (an_order[l].dd==Day) {     //this line check the day, you want to check
				sum1++;}                  //this line adds matchings as the sum
		}	printf("Orders were placed this day: %i", sum1);
		printf("\n");

		int sum2=0;
		for(l=0; l<k; l++) {
			if (an_order[l].dd==Day) {
				sum2 +=an_order[l].qty;}    //adding the values of flowers, if days have matched
			} printf("Number of individual flowers, that were purchased this day: %i", sum2);
			printf("\n");

		int sum3=0;
		for (l=0; l<k; l++) {
			if (an_order[l].dd==Day) {
				if (an_order[l].type[1]== 'm') {
					sum3++;}
				if (an_order[l].type[2]=='g') {
					sum3++;}                //adding one by one the bouquets
				}
			} printf("Number of bouquets, that were purchased this day is: %i", sum3);
			printf("\n");

		int sum4=0;
		for (l=0; l<k; l++) {
			if (an_order[l].dd==Day) {
				if (an_order[l].type[2]=='f') {
				sum4++;}
			}
		} printf("The types of all %i gifts:", sum4);
		printf("\n");
		sum4=0;
		for (l=0; l<k; l++) {
			if (an_order[l].dd==Day) {
				if (an_order[l].type[2]=='f') {
				printf("%s ", an_order[l].arrangement);}
			}
		}
		printf("\n");

		double sum5=0;
		for (l=0; l<k; l++) {
			if (an_order[l].dd==Day) {
				sum5+=an_order[l].total_cost;} //summing up all costs for given day
			} printf("Total earnings of this day: %lf ", sum5);
			printf("\n");

		double sum6=0;
		double sum7=0;
		double sum8=0;
		double sum9=0;
		double sum10=0;
		double sum11=0;
		double sum12=0;     //I've found 6 payment types. Now we will calculate the earnings of each of them
		//we need to show, what is going to be listed next, so
		printf("The total costs of each payment type:\n");
		for (l=0; l<k; l++) {
			if (an_order[l].dd==Day) {     //for the given day
				if (an_order[l].payment[0]=='c') {
					sum6+=an_order[l].total_cost;
				}
				if (an_order[l].payment[0]=='E') {
					sum7+=an_order[l].total_cost;
				}
				if (an_order[l].payment[0]=='p') {
					sum8+=an_order[l].total_cost;
				}
				if (an_order[l].payment[0]=='Q' || an_order[l].payment[0]=='q') {
					sum9+=an_order[l].total_cost;
				}
				if (an_order[l].payment[0]=='y') {
					sum10+=an_order[l].total_cost;
				}
				if (an_order[l].payment[0]=='h') {
					sum11+=an_order[l].total_cost;
				}
				if (an_order[l].payment[0]=='w') {
					sum12+=an_order[l].total_cost;
				}
				}
			}
        printf("The total cost of cash payment is %lf", sum6);
        printf("\n");
        printf("The total cost of Epay_Kazkom payment is %lf", sum7);
        printf("\n");
        printf("The total cost of paypal payment is %lf", sum8);
        printf("\n");
        printf("The total cost of Qiwi payment is %lf", sum9);
        printf("\n");
        printf("The total cost of yandex money payment is %lf", sum10);
        printf("\n");
        printf("The total cost of halyq banq payment is %lf", sum11);
        printf("\n");
        printf("The total cost of web money payment is %lf", sum12);
        printf("\n");

		int sum13=0;
		int sum14=0;   //we need to compute number of courier calls and the money paid for them
		for (l=0; l<k; l++) {
			if (an_order[l].dd==Day) {
				if (an_order[l].delivery != 0) {   //if there was not any courier delivery, the value of sum13 will sustain 0
					sum13++;
                sum14+=an_order[l].delivery;
			}
			}
		}
		printf("The number of courier deliveries: %i", sum13);
        printf("\n");
        printf("The cost of deliveries = %i", sum14);
        printf("\n");
        int sum15=0;
        int sum16=0;
        int sum17=0;
        for(l=0; l<k; l++){
                if (an_order[l].dd==Day) {
                    if(an_order[l].courier[0]=='s')
                        sum15++;
                    if(an_order[l].courier[0]=='a')
                        sum16++;
                    if(an_order[l].courier[0]=='q')
                        sum17++;
                }
        }
        int ll=sum15;
        if(sum16>ll)
            ll=sum16;
        if(sum17>=ll)
        {
            ll=sum17;
            printf("Qanat agha ");
        }
        if(sum16==ll)
            printf("Azat ");
        if(sum15==ll)
            printf("Shapagat ");
        printf("did the most %i deliveries in one day", ll);
        printf("\n");
    }
}


