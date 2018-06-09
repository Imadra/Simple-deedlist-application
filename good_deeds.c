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
} Deed;

	void taskTitle(char *task1,char *sortBy)
	{
		printf(" %s: after sort by %s", task1, sortBy);
		    printf("# |      --------- deed_name ---------       |deed   |total  |total");
		    printf("   |                                          |point  |times  |points");

	}



	int nColmn = 5;
	int nRows;

int main()
{
	char line[10009];
	Deed **deed_list = NULL;
	FILE *myfile1;
	FILE *myfile2;
	myfile1=fopen("deed_list.txt", "r");
		if(myfile1 == NULL)
		{
			printf("Cannot open file1\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			int number, i;
			//myfile1 >> number;
			fscanf(myfile1, "%i", &number);

			nRows = number;

            Deed  **deed_list = (Deed**)malloc(nRows*sizeof(Deed*));
            //for(i=0; i<number; i++)
            //    *(deed_list+i) = (Deed*)malloc(nRows *sizeof(Deed));

			int id;
			char name[55];
			int points;

				for(i = 0; nRows > i;i++)
					{
						//myfile1 >>id>>name>>points;
						fscanf(myfile1, "%i %s %i", &id, name, &points);
						deed_list[i]->deed_id = id;
						strcpy(deed_list[i]->deed_name, name );
						deed_list[i]->points_for_deed = points;
						deed_list[i]->total_times_done = 0;
						deed_list[i]->total_points_earned = 0;

					}



				fclose(myfile1);
		}

		myfile2=fopen("daylog.txt", "r");

		if(myfile2 == NULL)
		{
			printf("Cannot open file2\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			int id,ntimes, ind=1;
			while(ind<=28)
			{
			    fscanf(myfile2, "%i %i", &id, &ntimes);
			    printf("%i\n", deed_list[id - 1]->total_times_done);
				deed_list[id - 1]->total_times_done += ntimes;
				ind++;
			}
			printf("OK\n");
		}
		fclose(myfile2);
		int cnt = 0, i;
		for(i = 0; nRows > i; i++)
		{
			deed_list[i]->total_points_earned = deed_list[i]->total_times_done * deed_list[i]->points_for_deed;
		}


		//task1
		//sorting with bubble sort (total_times)

		for(i=0;i<nRows;i++){
                int j;
								        for(j=i+1;j<nRows;j++){
								if(deed_list[i]->total_times_done < deed_list[j]->total_times_done)
								{
                                int c = deed_list[j]->total_times_done;
                                deed_list[i]->total_times_done = deed_list[j]->total_times_done;
                                deed_list[j]->total_times_done = c;
                                c = deed_list[j]->deed_id;
                                deed_list[i]->deed_id = deed_list[j]->deed_id;
                                deed_list[j]->deed_id = c;
                                char *l;
                                int k=0;
                                while(deed_list[i]->deed_name[k]!='\0')
                                    l[k] = deed_list[i]->deed_name[k];
                                k=0;
                                while(deed_list[j]->deed_name[k]!='\0')
                                    deed_list[i]->deed_name[k] = deed_list[j]->deed_name[k];
                                k=0;
                                while(l[k]!='\0')
                                    deed_list[j]->deed_name[k] = l[k];
				                c = deed_list[j]->points_for_deed;
                                deed_list[i]->points_for_deed = deed_list[j]->points_for_deed;
                                deed_list[j]->points_for_deed = c;
				                c = deed_list[j]->total_points_earned;
                                deed_list[i]->total_points_earned = deed_list[j]->total_points_earned;
                                deed_list[j]->total_points_earned = c;
								}
				            }



				        if(deed_list[i]->total_times_done == 0){
				           	cnt++;
				        }
					}

		taskTitle("task1","total times");

		for(i = 0;  nRows - cnt  > i; i++)
			{
				   printf("%i    ", i);
				   printf("%i\t", deed_list[i]->deed_id);
				   printf("%s\t", deed_list[i]->deed_name);
				   printf("%i\t", deed_list[i]->points_for_deed);
				   printf("%i\t", deed_list[i]->total_times_done);
				   printf("%i\n", deed_list[i]->total_points_earned);
			}


		//END OF TASK1

		//task2
		for(i=0;i<nRows;i++){
                int j;
						        for(j=i+1;j<nRows;j++){
						            if(deed_list[i]->total_points_earned < deed_list[j]->total_points_earned){
						                int c = deed_list[j]->total_times_done;
                                deed_list[i]->total_times_done = deed_list[j]->total_times_done;
                                deed_list[j]->total_times_done = c;
                                c = deed_list[j]->deed_id;
                                deed_list[i]->deed_id = deed_list[j]->deed_id;
                                deed_list[j]->deed_id = c;
                                char *l;
                                int k=0;
                                while(deed_list[i]->deed_name[k]!='\0')
                                    l[k] = deed_list[i]->deed_name[k];
                                k=0;
                                while(deed_list[j]->deed_name[k]!='\0')
                                    deed_list[i]->deed_name[k] = deed_list[j]->deed_name[k];
                                k=0;
                                while(l[k]!='\0')
                                    deed_list[j]->deed_name[k] = l[k];
				                c = deed_list[j]->points_for_deed;
                                deed_list[i]->points_for_deed = deed_list[j]->points_for_deed;
                                deed_list[j]->points_for_deed = c;
				                c = deed_list[j]->total_points_earned;
                                deed_list[i]->total_points_earned = deed_list[j]->total_points_earned;
                                deed_list[j]->total_points_earned = c;
						            }


								}
						        if(deed_list[i]->total_points_earned == 0){
						           	cnt++;
						        }
							}

		printf("\n");

		taskTitle("task2","deeds_total_points_earned:");
		for(i = 0;  nRows - cnt  > i; i++)
					{

						   printf("%i    ", i);
				   printf("%i\t", deed_list[i]->deed_id);
				   printf("%s\t", deed_list[i]->deed_name);
				   printf("%i\t", deed_list[i]->points_for_deed);
				   printf("%i\t", deed_list[i]->total_times_done);
				   printf("%i\n", deed_list[i]->total_points_earned);
					}



		//END OF TASK2
		printf("\n");
		//task 3
		int deed_times_sum = 0;

		for(i = 0; nRows > i; i++)
		{
			deed_times_sum += deed_list[i]->total_times_done;
		}


		printf("task3: total deed_counts: \n");
		printf("%i deeds\n\n", deed_times_sum);

		//END OF TASK3

		//task4
		int deed_points_sum = 0;

		for(i = 0; nRows > i; i++)
		{
			deed_points_sum += deed_list[i]->total_points_earned;
		}


			printf("task4: total deed_points: \n");
			printf("%i points\n\n", deed_points_sum);


		//END OF TASK4


		//task5

        int j;
		for(j = 0; nRows > j; j++)
		{
				for(i = 1; nRows > i; i++)
				{
					if(strcmp(deed_list[i - 1]->deed_name, deed_list[i]->deed_name) > 0){

						int c = deed_list[j]->total_times_done;
                                deed_list[i]->total_times_done = deed_list[j]->total_times_done;
                                deed_list[j]->total_times_done = c;
                                c = deed_list[j]->deed_id;
                                deed_list[i]->deed_id = deed_list[j]->deed_id;
                                deed_list[j]->deed_id = c;
                                char *l;
                                int k=0;
                                while(deed_list[i]->deed_name[k]!='\0')
                                    l[k] = deed_list[i]->deed_name[k];
                                k=0;
                                while(deed_list[j]->deed_name[k]!='\0')
                                    deed_list[i]->deed_name[k] = deed_list[j]->deed_name[k];
                                k=0;
                                while(l[k]!='\0')
                                    deed_list[j]->deed_name[k] = l[k];
				                c = deed_list[j]->points_for_deed;
                                deed_list[i]->points_for_deed = deed_list[j]->points_for_deed;
                                deed_list[j]->points_for_deed = c;
				                c = deed_list[j]->total_points_earned;
                                deed_list[i]->total_points_earned = deed_list[j]->total_points_earned;
                                deed_list[j]->total_points_earned = c;
					}
				}
	}



		taskTitle("task5","alphabetically:");
			for(i = 0;  nRows > i; i++)
								{

									   printf("%i    ", i);
				   printf("%i\t", deed_list[i]->deed_id);
				   printf("%s\t", deed_list[i]->deed_name);
				   printf("%i\t", deed_list[i]->points_for_deed);
				   printf("%i\t", deed_list[i]->total_times_done);
				   printf("%i\n", deed_list[i]->total_points_earned);
								}



		//END OF TASK5

		//task6
		//binary search
		char inputName[10009];
		printf("Task6:Enter a deed_name\n");
		scanf("%s", inputName);

		int head = 0;
		int tail = nRows - 1;
		int mid;
		int position = -1;
		_Bool isExist = 0;

		while(isExist==0 && tail >= head)
		{
			mid = (head + tail)/2;
			if(deed_list[mid]->deed_name == inputName)
			{
				isExist = 1;
				position = mid;
			}

			else if(deed_list[mid]->deed_name > inputName)
			{
				tail = mid - 1;
			}

			else head = mid + 1;
		}

		if(position == -1)
		{
			printf("task6: search case2:\nNo such deed");
		}
		else
		{
			printf("task6: search case2:\n");
			printf("%s %i times %i points earned\n", deed_list[position]->deed_name, deed_list[position]->total_times_done, deed_list[position]->total_points_earned);
		}

		//END OF TASK6

				//deleting allocated memory
			for(i = 0; nRows > i; i++)
			{
				free(deed_list[i]);
			}

			free(deed_list);



			return 0;
}



