#include <stdio.h>
#include <math.h>
typedef struct {
    int sale_id, dd, qty;
    double total_cost;
    int delivery;
	char type[109], arrangement[109], payment[109], courier[109];
} data;
int compare_strings_for_equality(char a[], char b[])
{
    int ind = 0, p = 1;
    while (a[ind] == b[ind])
    {
        if (a[ind] == '\0' || b[ind] == '\0')
            break;
        ind++;
    }
    if (a[ind] != '\0' || b[ind] != '\0')
        p = 0;

    return p;
}
int maxi(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
	FILE *infile;
	infile  = fopen("flower_sales.txt", "r");
	if (infile == NULL)
    {
		printf("Problem opening files.");
		return 1;
	}
	data sales[501];
    int day, j, i = 0;

	do
	{
        fscanf(infile, "%i %i %i %s %lf %s %s %i %s", &sales[i].sale_id, &sales[i].dd, &sales[i].qty, sales[i].type, &sales[i].total_cost, sales[i].arrangement, sales[i].payment, &sales[i].delivery, sales[i].courier);
        if(sales[i].sale_id==0)
            break;
        i++;
    } while (!feof(infile));

	while(1)
    {
        printf("Enter the number of the day in a month: ");
        scanf("%i", &day);
        if(day<1 || day>31)
        {
            printf("The program has completed its process. Analysis was made by Rassul Khassen. Have a good day and enjoy programming!");
            break;
        }
        int sum_of_orders = 0, sum_of_flowers=0, sum_of_bouquets=0, sum_of_gifts=0;
        char forcheck1[]="big_bouquet", forcheck2[]="small_bouquet", forcheck3[]="gift";
        for(j = 0; j < i; j++)
        {
            if(sales[j].dd == day)
            {
                sum_of_orders++;
                if(compare_strings_for_equality(sales[j].type, forcheck1)==1 || compare_strings_for_equality(sales[j].type, forcheck2)==1)
                {
                    sum_of_bouquets++;
                }
                if(compare_strings_for_equality(sales[j].type, forcheck3)==1)
                {
                    sum_of_gifts++;
                }
                else
                {
                    sum_of_flowers += sales[j].qty;
                }
            }
        }
        printf("The number of orders that were placed is: %i\n", sum_of_orders);
        printf("The number of individual flowers that were purchased is: %i\n", sum_of_flowers);
        printf("The number of bouquets that were purchased is: %i\n", sum_of_bouquets);
        printf("The number of gifts that were purchased is: %i. ", sum_of_gifts);
        if(sum_of_gifts>0)
        {
            printf("They are:\n");
            int index_of_gifts = 0;
            for(j = 0; j < i; j++)
            {
                if(sales[j].dd == day)
                {
                    if(compare_strings_for_equality(sales[j].type, forcheck3))
                    {
                        index_of_gifts++;
                        printf("%i: id->%i, arrangement->%s\n", index_of_gifts, sales[j].sale_id, sales[j].arrangement);
                    }
                }
            }
        }
        else
            printf("\n");
        double cost = 0;
        for(j = 0; j < i; j++)
        {
            if(sales[j].dd == day)
            {
                cost += sales[j].total_cost;
            }
        }
        printf("The total cost of the orders for the given day is:%lf\n", cost);
        printf("The total costs were broken down by following payment types:\n");
        double cash = 0, epay=0, paypal=0, qiwi=0, yandex=0, halyq=0, web=0;
        char pay1[]="cash", pay2[]="Epay_Kazkom", pay3[]="paypal", pay4[]="Qiwi", pay4_2[]="qiwi", pay5[]="yandex_money",
             pay6[]="halyq_bank", pay7[]="web_money";
        for(j = 0; j < i; j++)
        {
            if(sales[j].dd == day)
            {
                if(compare_strings_for_equality(sales[j].payment, pay1)==1)
                    cash += sales[j].total_cost;
                if(compare_strings_for_equality(sales[j].payment, pay2)==1)
                    epay += sales[j].total_cost;
                if(compare_strings_for_equality(sales[j].payment, pay3)==1)
                    paypal += sales[j].total_cost;
                if(compare_strings_for_equality(sales[j].payment, pay4)==1 || compare_strings_for_equality(sales[j].payment, pay4_2)==1)
                    qiwi += sales[j].total_cost;
                if(compare_strings_for_equality(sales[j].payment, pay5)==1)
                    yandex += sales[j].total_cost;
                if(compare_strings_for_equality(sales[j].payment, pay6)==1)
                    halyq += sales[j].total_cost;
                if(compare_strings_for_equality(sales[j].payment, pay7)==1)
                    web += sales[j].total_cost;
            }
        }
        printf("Cash: %lf\n", cash);
        printf("Epay Kazkom: %lf\n", epay);
        printf("Paypal: %lf\n", paypal);
        printf("Qiwi: %lf\n", qiwi);
        printf("Yandex_money: %lf\n", yandex);
        printf("halyq_bank: %lf\n", halyq);
        printf("Web money: %lf\n", web);
        int delivery=0, cost_of_deliveries=0;
        for(j = 0; j < i; j++)
        {
            if(sales[j].dd == day)
            {
                if(sales[j].delivery!=0)
                {
                    delivery++;
                    cost_of_deliveries += sales[j].delivery;
                }
            }
        }
        printf("Number of deliveries: %i, total cost of money spent on deliveries:%i\n", delivery, cost_of_deliveries);
        int c1 = 0, c2 = 0, c3 = 0;
        char courier1[]="shapaghat", courier2[]="qanat_agha", courier3[]="azat";
        for(j = 0; j < i; j++)
        {
            if(sales[j].dd == day)
            {
                if(compare_strings_for_equality(sales[j].courier, courier1)==1)
                {
                    c1++;
                }
                if(compare_strings_for_equality(sales[j].courier, courier2)==1)
                {
                    c2++;
                }
                if(compare_strings_for_equality(sales[j].courier, courier3)==1)
                {
                    c3++;
                }
            }
        }
        int maximum = maxi(maxi(c1, c2), c3);
        int number_of_couriers = 0;
        if(c1 == maximum)
        {
            printf("shapaghat ");
            number_of_couriers++;
        }
        if(c2 == maximum)
        {
            if(number_of_couriers > 0)
                printf("and ");
            printf("qanat_agha ");
            number_of_couriers++;
        }
        if(c3 == maximum)
        {
            if(number_of_couriers > 0)
                printf("and ");
            printf("azat ");
            number_of_couriers++;
        }
        printf("made the most deliveries this day. The number of deliveries is: %i\n\n", maximum);
    }

	fclose(infile);
    return 0;
}
