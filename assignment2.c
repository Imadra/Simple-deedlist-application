#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	int id;
	int date;
	int qty;
	char type[100];
	char argmt[100];
	double tcost;
	char payment[100];
	int delivery;
	char courier[100];
} flower_sales;
int main(){
    int n =200;
	flower_sales flw[n];
	FILE *file;
	file = fopen("flower_sales.txt", "r");
	if(file == NULL){
		printf("File Opening Problem");
		return 1;
		}
	else {printf("File opened successfully\n");
	int i = 0;
	do{
		fscanf(file, "%i %i %i %s %lf %s %s %i %s", &flw[i].id, &flw[i].date, &flw[i].qty, flw[i].type, &flw[i].tcost, flw[i].argmt, flw[i].payment, &flw[i].delivery, flw[i].courier);
        i++;
}
while (!feof(file));

    int d; // entered day
	printf("Type the date, please:");
	scanf("%i", &d);
	if(d > 0 && d<32){
	} else {
		return 1;
	}
    int total_orders=0; // number of orders
     if(d==flw[i].date){
    total_orders++;
    printf("Orders: %i\n", total_orders);

	int total_flowers=0;
	if(d==flw[i].date){
        total_flowers+=flw[i].qty;
	}
	printf("Flowers: %i\n", total_flowers);

	int total_bouquets=0, total_bouquets1=0, total_bouquets2=0;
	if (d==flw[i].date) {
           if (flw[i].type[0] == 'b' && flw[i].type[1] == 'i')  {
            total_bouquets1 += flw[i].qty;
        } if (flw[i].type[0] == 's' && flw[i].type[1] == 'm'){
        	total_bouquets2 += flw[i].qty;
        }	total_bouquets = total_bouquets1 + total_bouquets2;
	} printf("Bouquets: %i\n", total_bouquets);
     int total_gifts=0, ballons=0, birthday_cake=0;
     if(d==flw[i].date) {
            if (flw[i].type[0] =='g'){
                total_gifts+=flw[i].qty;
    }
            if (flw[i].argmt[0] == 'b' && flw[i].argmt[1] == 'a' && flw[i].argmt[2] == 'l'){
            	ballons++;
            }
            if(flw[i].argmt[0] == 'b' && flw[i].argmt[1] == 'i' && flw[i].argmt[2] == 'r'){
            	birthday_cake++;
            }

    } printf ("Gifts: %i \n Ballons: %i \n Birthday cake: %i \n", total_gifts, ballons, birthday_cake);

    double total_cost=0;
	if(d==flw[i].date){
            total_cost +=  flw[i].tcost;
	}
	printf("Total cost of orders: %lf \n", total_cost);

	double total_cash=0, total_EK=0, total_PP=0, total_QW=0, total_WM=0, total_YM=0, total_HB=0;
	if(d==flw[i].date){
                if (flw[i].payment[0] == 'c'){
                    total_cash+=flw[i].tcost;
                }
                if (flw[i].payment[0] == 'E'){
                    total_EK+=flw[i].tcost;
                }
                if (flw[i].payment[0] == 'p'){
                    total_PP+=flw[i].tcost;
                }
                if (flw[i].payment[0] == 'q'|| flw[i].payment[0] == 'Q'){
                    total_QW+=flw[i].tcost;
                }
                if (flw[i].payment[0] == 'w'){
                    total_WM+=flw[i].tcost;
                }
                if (flw[i].payment[0] == 'y'){
                    total_YM+=flw[i].tcost;
                }
                if (flw[i].payment[0] == 'h'){
                    total_HB+=flw[i].tcost;
                }
	}
	printf("i. Cash: %lf\n ii. Epay_kazkom: %lf \n iii. qiwi: %lf \n iv. PayPal: %lf \n v. Halyq_bank: %lf \n vi. Web Money: %lf \n vii. Yandex Money: %lf \n", total_cash, total_EK, total_QW, total_PP, total_HB, total_WM, total_YM);
	int total_dlvs=0;
	double total_dlvs_money=0;
	if(d==flw[i].date){
	    total_dlvs++;
	    total_dlvs_money+=flw[i].delivery;
	}
	printf("Deliveries: %i\n Money spent on deliveries: %lf \n", total_dlvs, total_dlvs_money);

	int a=0, s=0, q=0;
	int max;
	if (d==flw[i].date){
        if(flw[i].courier[0]=='a'){
        a++;
        }
        if(flw[i].courier[0]=='s'){
        s++;
	}
        if(flw[i].courier[0] == 'q'){
            q++;
        }
    }
        if (a>s && a>q){
        	max = a;
        }


        if (s>a && s>q){
        	max = s;
        }


        if(q>a && q>s){
        	max =q;
        }
        if(max == q){
        	printf ("Best Courier is Qanat aga with %i deliveries", q);
        }
        if(max == s){
        	printf ("Best Courier is Shapagat with %i deliveries", s);
               }
        if(max == a){
        	printf ("Best Courier is Azat with %i deliveries", a);
               }
        }
        }
	fclose(file);
    return 0;
}
