#include <stdio.h>
typedef struct { //suppose, that is obvious
	int saleID;
	int date;
	int quantity;
	char type [80];
	double totalCost;
	char arrangement [80];
	char payment [80];
	int delivery;
	char courier [80];
} oneDay;

oneDay entries[200];
int dayDescript(int n){

	 int j;

    int sumOfOrders=0; //Here, just declarations of the necessary outputs
    int sumOfInF=0;
    int sumOfSmall=0;
    int sumOfBig=0;
    int sumOfGifts=0;
    int sumOfBirC=0;
    int sumOfBalloons=0;
    double sumOfTotal=0;
    double sumOfCash=0;
    double sumOfEpay=0;
    double sumOfQiwi=0;
    double sumOfYandex=0;
    double sumOfHalyq=0;
    double sumOfWeb=0;
    double sumOfPay=0;
    int sumOfDeliveries=0;
    int sumOfSpent=0;
    int sumOfDeliver=0;
    int a[3]={0}; //Array, that contains information about number of deliveries of each courier

    for (j=0; j<200; j++){
    if (entries[j].date==n){
        sumOfOrders++;
        sumOfInF+=entries[j].quantity;
        if(strcmp("small_bouquet", entries[j].type)==0){
            sumOfSmall++;
    }
        if (strcmp("big_bouquet", entries[j].type )==0){
            sumOfBig++;
    }
        if (strcmp("gift", entries[j].type )==0){
            sumOfGifts++;
        }
        if (strcmp("birthday_cake", entries[j].arrangement)==0){
            sumOfBirC++;
    }
        if (strcmp("balloons", entries[j].arrangement)==0){
            sumOfBalloons++;
    }
        sumOfTotal+=entries[j].totalCost;
        if (strcmp("cash", entries[j].payment)==0){
            sumOfCash+=entries[j].totalCost;
    }
        if (strcmp("yandex_money", entries[j].payment)==0){
            sumOfYandex+=entries[j].totalCost;
    }
        if (strcmp("Epay_Kazkom", entries[j].payment)==0){
            sumOfEpay+=entries[j].totalCost;
    }
        if (strcmp("halyq_bank", entries[j].payment)==0){
            sumOfHalyq+=entries[j].totalCost;
    }
        if (strcmp("paypal", entries[j].payment)==0){
            sumOfPay+=entries[j].totalCost;
    }
        if ((strcmp("Qiwi", entries[j].payment)==0)||(strcmp("qiwi", entries[j].payment)==0)){
            sumOfQiwi+=entries[j].totalCost;
    }
        if (strcmp("web_money", entries[j].payment)==0){
            sumOfWeb+=entries[j].totalCost;
    }
        if (entries[j].delivery!=0){
            sumOfDeliveries++;
            sumOfSpent+=entries[j].delivery;
    }
        if (strcmp("shapaghat", entries[j].courier)==0){
            a[0]++;
    }
    if (strcmp("qanat_agha", entries[j].courier)==0){
            a[1]++;
    }
    if (strcmp("azat", entries[j].courier)==0){
            a[2]++;
    }
    }
    }
    printf ("\n%i-orders were done;\n", sumOfOrders);
    printf ("%i-individual flowers were purchased;\n", sumOfInF-sumOfGifts);
    printf ("%i-small bouquets were purchased;\n", sumOfSmall);
    printf ("%i-big bouquets were purchased;\n", sumOfBig);
    printf ("%i-gifts were purchased:\n", sumOfGifts);
    printf ("  %i-birthday cakes;\n", sumOfBirC);
    printf ("  %i-balloons;\n", sumOfBalloons);
	printf ("%.3lf-total cost of the orders:\n", sumOfTotal);
	printf ("  %.3lf-Cash; \n", sumOfCash);
	printf ("  %.3lf-Yandex Money; \n", sumOfYandex);
	printf ("  %.3lf-Epay Kazkom; \n", sumOfEpay);
	printf ("  %.3lf-Qiwi; \n", sumOfQiwi);
	printf ("  %.3lf-Halyq Bank; \n", sumOfHalyq);
	printf ("  %.3lf-PayPal; \n", sumOfPay);
	printf ("  %.3lf-Web Money; \n", sumOfWeb);
	printf ("%i-deliveries were made;\n", sumOfDeliveries);
	printf ("%i-spent for deliveries;\n", sumOfSpent);
	int max=a[0];
	int i;
	for (i=1; i<=2; i++) {
        if (max<a[i]) {
            max=a[i];
        }
	}
	if (max=a[0]){
	printf ("Shapaghat made the most %i delivers\n", max);
	}
	if (max=a[1]){
	printf ("Qanat agha made the most %i delivers\n", max);
	}
	if (max=a[2]){
	printf ("Azat made the most %i delivers\n", max);
	}
}
int main (){
    FILE *flowers;    //Reading individual words from the file and saving each line as an array of structure
	 flowers=fopen("flower_sales.txt", "r");
    int j;
	 for (j=0; j<200; j++){
     fscanf(flowers, "%i %i %i %s %lf %s %s %i %s", &entries[j].saleID, &entries[j].date, &entries[j].quantity, entries[j].type, &entries[j].totalCost, entries[j].arrangement, entries[j].payment, &entries[j].delivery, entries[j].courier);
	 }
    fclose (flowers);
    int i;
	for (i=1; i<=31; ) {
    printf ("\nPlease, write down which day do you want to analyze(1-31)?   ");
	int n;
	scanf ("%i", &n);
	if (n>31||n<1){
		printf ("Sorry, this date does not exist");
		break;
	} else{
	dayDescript(n);
	}
 }
 }
