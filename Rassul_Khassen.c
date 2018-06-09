#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int deed_id;
    char deed_name[55];
    int points_for_deed;
    int total_times_done;
    int total_points_earned;
} deed; //declaring a struct

int partition(deed **x, int first, int last, int type)
{
    //partition phase of quicksort
    int pivot = first;
    int up = first, down = last;
    while (up < down)
    {
        if(type == 1) //type 1 for sorting by total times done
        {
            while ((**(x+up)).total_times_done >= (**(x+pivot)).total_times_done && up < last)
            {
                up++;
            }
            while ((**(x+down)).total_times_done < (**(x+pivot)).total_times_done)
            {
                down--;
            }
        }

        if(type == 2) //type 2 for sorting by total points earned
        {
            while ((**(x+up)).total_points_earned >= (**(x+pivot)).total_points_earned && up < last)
            {
                up++;
            }
            while ((**(x+down)).total_points_earned < (**(x+pivot)).total_points_earned)
            {
                down--;
            }
        }

        if(type == 3) //type 3 for sorting alphabetically
        {
            while (strcmp((**(x+up)).deed_name , (**(x+pivot)).deed_name) <= 0 && up < last)
            {
                up++;
            }
            while (strcmp((**(x+down)).deed_name , (**(x+pivot)).deed_name) > 0)
            {
                down--;
            }
        }

        if (up < down)
        {
            deed *l = (*(x+up));
            (*(x+up)) = (*(x+down));
            (*(x+down)) = l; //swapping up deed and down deed
        }
    }
    deed *l2 = (*(x+pivot));
    (*(x+pivot)) = (*(x+down));
    (*(x+down)) = l2; //swapping pivot deed and down deed

    return down;
}
void sort(deed **a, int first, int last, int type)
{
    //quicksort
    //type indicates whether to sort by total times, total points or alphabetically
    if (first < last)
    {
        int pivIndex = partition(a, first, last, type);
        sort(a, first, pivIndex-1, type);
        sort(a, pivIndex+1, last, type);
    }
}
void print(deed **a, int sz, int type)
{
    int i, ind=0;
    if(type == 1)
        printf("task1: after sort by deeds_total_times_done:\n");
    if(type == 2)
        printf("task2: after sort by deeds_total_points_earned:\n");
    if(type == 3)
        printf("task5: after sort alphabetically:\n");
    printf("%2s%3s%-49.49s%8s%8s%8s\n", "No", "|", "--------- deed_name ---------", "|deed", "|total", "|total");
    printf("%2s%3s%-49.49s%8s%8s%8s\n", "  ", "|", "", "|point", "|times", "|points");
    //printing out the title of task
    for(i=0; i<sz; i++)
    {
        if((**(a+i)).total_times_done == 0)
            continue;
        printf("%2i", ind++);
        printf("%3i %-52.52s %4i %6i %7i\n", (**(a + i)).deed_id, (**(a + i)).deed_name, (**(a + i)).points_for_deed, (**(a + i)).total_times_done, (**(a + i)).total_points_earned);
        //printing out data of sorted deed
    }
    printf("\n\n");
}
int sum(deed **a, int sz, int task)
{
    //counts the sum of total times done or total points earned
    int i, ans = 0;
    for(i=0; i<sz; i++)
    {
        if(task==3) //if task is equal to 3, we have to count total times done
            ans += (**(a+i)).total_times_done;
        else  //if task is equal to 4, we have to count total points earned
            ans += (**(a+i)).total_points_earned;
    }
    return ans;
}
int bin_search(deed **a, int sz, char *ss)
{
    //binary search
    int min = 0;
    int max = sz-1;

    while (min <= max)
    {

        int guess = (min + max) / 2;

        if (strcmp((**(a+guess)).deed_name, ss) == 0) //if string comparing is 0, they are equal
        {
            return guess;
        }
        else if (strcmp((**(a+guess)).deed_name, ss) > 0)
        {
            max = guess - 1;
        }
        else
        {
            min = guess + 1;
        }
    }

    return -1; //not found
}
int main ()
{
    int n, i, j, x, y, m, ind = 1, index; //declaring integers to use
    char search_name[10009]; //declaring string to read in task 6

    FILE *ff;
    ff=fopen("deed_list.txt", "r"); //opening deed_list.txt file

    fscanf(ff, "%i", &n);

    deed  **deed_list = (deed**)malloc(n*sizeof(deed*));
    for(i=0; i<n; i++)
        *(deed_list+i) = (deed*)malloc(n *sizeof(deed));
    //allocating memory for array of pointers to pointers

    for (i=0; i<n; i++)
    {
        fscanf(ff, "%i %s %i ", &(**(deed_list+i)).deed_id, &(**(deed_list+i)).deed_name, &(**(deed_list+i)).points_for_deed);
        //reading deed_list.txt file data
        (**(deed_list+i)).total_times_done = (**(deed_list+i)).total_points_earned = 0;
    }
    fclose (ff); //closing deed_list.txt file

    FILE *ff2;
    ff2=fopen("daylog.txt", "r"); //opening daylog.txt file

    m = 28; //number of deeds in daylog.txt file

    for(i=0; i<m; i++)
    {
        fscanf(ff2, "%i %i ", &x, &y);
        //reading data from daylog.txt file
        for(j=0; j<n; j++)
        {
            if((**(deed_list+j)).deed_id == x) //appropriate deed
            {
                (**(deed_list+j)).total_times_done += y; //adding current deed done to the total times done of a deed
                int add = y * (**(deed_list+j)).points_for_deed; // points earned for current deed done
                (**(deed_list+j)).total_points_earned += add; //adding to the total points
                break;
            }
        }
    }
    fclose (ff2); //closing daylog.txt file

    sort(deed_list, 0, n-1, 1); //sorting by total times done (type 1)
    print(deed_list, n, 1); //printing out new sorted deed_list

    sort(deed_list, 0, n-1, 2); //sorting by total points earned (type 2)
    print(deed_list, n, 2); //printing out new sorted deed_list

    printf("task3: total deed_counts:\n%i deeds\n\n", sum(deed_list, n, 3)); //summing total deed counts (task 3)
    printf("task4: total deed_points:\n%i deeds\n\n", sum(deed_list, n, 4)); //summing total deed points (task 4)

    sort(deed_list, 0, n-1, 3); //sorting alphabetically (type 3)
    print(deed_list, n, 3); //printing out new sorted deed_list

    printf("task6: search until not existing deed input:\n");
    while(1) //program is going to proceed until it will accepts not existing deed input
    {
        printf("search case%i: ", ind++);
        scanf("%s", search_name);
        index = bin_search(deed_list, n, search_name); //binary search returns the index of found deed in the deed_list
        if(index == -1) //index equals to -1 if no such deeds found
        {
            printf("No such deed");
            break; //program stops here
        }
        printf("%s -> dead id:%i, %i times done and %i points earned\n", (**(deed_list+index)).deed_name, (**(deed_list+index)).deed_id, (**(deed_list+index)).total_times_done, (**(deed_list+index)).total_points_earned);
        //printing out information about the found deed
    }
    free(deed_list);
    for(i = 0; i < n; i++)
        free(*deed_list);
}
