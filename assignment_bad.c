#include <stdio.h>
#include <stdbool.h>
struct flowershop {
    int saleid, dd, qty,delivery;
    char type[60],arrangement[60], payment[60], courier[60];
    double totalcost;
};
struct flowershop id[200];
int main (){
    setvbuf (stdout, NULL, _IONBF, 0);
    FILE *file;
    file = fopen("flower_sales.txt", "r");
    if (file == NULL){
        printf("Problem opening file.");
        return 1;
    }
    do { int i;
    for (i=0; i<200; i++){
        fscanf (file, " %i %i %i %s %lf %s %s %i %s",
            &id[i].saleid, &id[i].dd, &id[i].qty,
            &id[i].type, &id[i].totalcost, &id[i].arrangement,
            &id[i].payment, &id[i].delivery, &id[i].courier );}
        int day, k=0;
    for (;k<100;) {
        printf ("\nEnter the day: ");
        scanf ("%i", &day);
    if (day<1 || day>31){
            printf ("Day is inappropriate \n");
            return 0;}
    else if ( day<=31 || day>=1) {
            int numberoforders = 0, qtofflowers=0, numofbouq=0, bigbouq=0, smallbouq=0;
            int qtofgifts=0, deliveries=0, numberofdeliveries=0, baloons=0, birthdaycake=0 ;
            double cash=0, epay=0, halyk=0, paypal=0, qiwi=0, web=0, yandex=0, cost=0;
            int azat=0, shapagat=0, qanat=0;

               for(i=0; i<201; i++){
                     if(day==id[i].dd){
                            numberoforders+=1;
                            cost+=id[i].totalcost;
                            deliveries+=id[i].delivery;
                            if(id[i].type[2]== 'a'|| id[i].type[2]== 'g' || id[i].type[2]== 'x' ){
                                qtofflowers=id[i].qty+qtofflowers;}
                            if(id[i].type[2]== 'a'|| id[i].type[2]== 'g'){
                                numofbouq+=1;}
                            if(id[i].type[2]== 'a'){
                                smallbouq+=1;}
                            if(id[i].type[2]== 'g'){
                                bigbouq+=1;}
                            if(id[i].type[2]== 'f'){
                                qtofgifts+=1;
                                    if(id[i].arrangement[1]=='i'){
                                        birthdaycake+=1;                                }
                                    if(id[i].arrangement[1]=='a'){
                                        baloons+=1;                             }}
                            if(id[i].payment[0]=='c'){
                                cash+=id[i].totalcost;}
                            if(id[i].payment[0]=='h'){
                                halyk+=id[i].totalcost;}
                            if(id[i].payment[0]=='E'){
                                epay+=id[i].totalcost;}
                            if(id[i].payment[0]=='p'){
                                paypal+=id[i].totalcost;}
                            if(id[i].payment[0]=='q' || id[i].payment[0]=='Q'){
                                qiwi+=id[i].totalcost;}
                            if(id[i].payment[0]=='y'){
                                yandex+=id[i].totalcost;}
                            if(id[i].payment[0]=='w'){
                                web+=id[i].totalcost;}
                            if(id[i].courier[0]=='s' || id[i].courier[0]=='a'|| id[i].courier[0]=='q'){
                                numberofdeliveries+=1;}
                            if (id[i].courier[0]=='s'){
                                shapagat+=1; }
                            else if (id[i].courier[0]=='a'){
                                azat+=1; }
                            else if (id[i].courier[0]=='q'){
                                qanat+=1;} }  }
                    printf ("Amount of orders : %i \n", numberoforders);
                    printf ("Amount of individual flowers: %i \n", qtofflowers);
                    printf ("Amount of bouquets: %i \n", numofbouq);
                    printf ("Amount of small bouquets: %i \n", smallbouq);
                    printf ("Amount of big bouquets: %i \n", bigbouq);
                    printf ("Quantity of gifts that were purchased: %i \n", qtofgifts);
                    int g,h;
                   if (birthdaycake!=0){
                        for(g=0;g<birthdaycake; g++){
                    h=g+1;                   }
                   printf ("This amount of birthday cakes were purchased at that day :%i  \n", h);}

                   if(baloons!=0){
                        for(g=0;g<baloons; g++){
                    h=g+1;                   }
                    printf ("This amount of baloons were purchased at that day :%i \n", h);}
                    printf ("Total cost at that day : %.1f \n", cost);
                    printf ("Total cost which was done by paypal : %.1f \n", paypal);
                    printf ("Total cost which was done by cash: %.1f \n", cash);
                    printf ("Total cost which was done by halyk_bank: %.1f \n", halyk);
                    printf ("Total cost which was done by Epay_kazakom: %.1f \n", epay);
                    printf ("Total cost which was done by qiwi : %.1f \n",qiwi );
                    printf ("Total cost which was done by yandex_money : %.1f \n",yandex );
                    printf ("Total cost which was done by web_money: %.1f \n", web);
                    if (deliveries==0){
                                      printf("No deliveries were done \n");}
                    printf ("Total amount of deliveries at that day: %i \n", numberofdeliveries);
                    printf ("For deliveries in total was spent : %i \n", deliveries);

                    if(shapagat>azat && shapagat>qanat){
                                printf("Maximum deliveries done by Shapagat : %i \n", shapagat);  }
                        else if(azat>shapagat && azat>qanat) {
                                printf("Maximum deliveries done by Azat : %i\n", azat);  }
                        else if(qanat>azat && qanat>shapagat){
                                printf("Maximum deliveries done by Qanat agha : %i\n", qanat);    }
                        else if(azat==shapagat && shapagat> qanat ){
                                printf("Maximum deliveries done by Azat and Shapagat : %i\n", azat);   }
                        else if(qanat==shapagat && shapagat> azat ){
                                printf("Maximum deliveries done by Qanat agha and Shapagat : %i\n", qanat);    }
                        else if(azat==qanat &&  qanat>shapagat ){
                                printf("Maximum deliveries done by Qanat agha and Azat : %i\n", azat);   }
                        else if(azat==qanat && shapagat==azat && azat!=0 ){
                                printf("Maximum deliveries done by Qanat agha and Azat and Shapagat : %i\n", azat);   }
                                          }
                        else {
                            printf ("input is incorrect");
                            return 0;

                        }}
              }while (!feof(file));
           fclose(file);
           return 0;}

