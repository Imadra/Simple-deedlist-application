#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <cstring>
using namespace std;

	struct Deed
{
	int deed_id;
	char deed_name[55];
	int points_for_deed;
	int total_times_done;
	int total_points_earned;




};

	void taskTitle(string task1,string sortBy)
	{
		cout<<" "<<task1<<": after sort by "<<sortBy<<endl;
		    cout<<" # |      --------- deed_name ---------       |deed   |total  |total"<<endl;
		    cout<<"   |                                          |point  |times  |points"<<endl;

	}



	int nColmn = 5;
	int nRows;


int main()
{
	string line;
	Deed **deed_list = NULL;
	ifstream myfile1,myfile2;
	myfile1.open("deed_list.txt");

		if(myfile1.fail())
		{
			cout<<"Cannot open file1"<<endl;
			exit(EXIT_FAILURE);


		}
		else
		{
			int number;
			myfile1 >> number;

			nRows = number;



			deed_list = new Deed*[nRows];
			for(int i = 0; nRows > i; i++)
			{
				deed_list[i] = new Deed[nColmn];
			}

			int id;
			char name[55];
			int points;

				for(int i = 0; nRows > i;i++)
					{
						myfile1 >>id>>name>>points;
						deed_list[i]->deed_id = id;
						strcpy(deed_list[i]->deed_name, name );
						deed_list[i]->points_for_deed = points;
						deed_list[i]->total_times_done = 0;
						deed_list[i]->total_points_earned = 0;

					}



				myfile1.close();
		}


		myfile2.open("daylog.txt");
		if(myfile2.fail())
		{
			cout<<"Cannot open file2"<<endl;
				exit(EXIT_FAILURE);
		}
		else
		{
			int id,ntimes;
			while(myfile2 >> id >> ntimes)
			{

				deed_list[id - 1]->total_times_done += ntimes;
			}
		}

		myfile2.close();
		int cnt = 0;
		for(int i = 0; nRows > i; i++)
		{
			deed_list[i]->total_points_earned = deed_list[i]->total_times_done * deed_list[i]->points_for_deed;
		}


		//task1
		//sorting with bubble sort (total_times)

		for(int i=0;i<nRows;i++){
								        for(int j=i+1;j<nRows;j++){
								if(deed_list[i]->total_times_done < deed_list[j]->total_times_done)
								{
								swap(deed_list[i]->total_times_done,deed_list[j]->total_times_done);

				                swap(deed_list[i]->deed_id,deed_list[j]->deed_id);
				                swap(deed_list[i]->deed_name,deed_list[j]->deed_name);
				                swap(deed_list[i]->points_for_deed,deed_list[j]->points_for_deed);
				                swap(deed_list[i]->total_points_earned,deed_list[j]->total_points_earned);
								}
				            }



				        if(deed_list[i]->total_times_done == 0){
				           	cnt++;
				        }
					}





		taskTitle("task1","total times");

		for(int i = 0;  nRows - cnt  > i; i++)
			{
				   cout<<i<<"    ";
				   cout<<deed_list[i]->deed_id<<"\t";
				   cout<<deed_list[i]->deed_name<<"\t";
				   cout<<deed_list[i]->points_for_deed<<"\t";
				   cout<<deed_list[i]->total_times_done<<"\t";
				   cout<<deed_list[i]->total_points_earned<<endl;
			}


		//END OF TASK1

		//task2
		for(int i=0;i<nRows;i++){
						        for(int j=i+1;j<nRows;j++){
						            if(deed_list[i]->total_points_earned < deed_list[j]->total_points_earned){
						                swap(deed_list[i]->total_times_done,deed_list[j]->total_times_done);

						                swap(deed_list[i]->deed_id,deed_list[j]->deed_id);
						                swap(deed_list[i]->deed_name,deed_list[j]->deed_name);
						                swap(deed_list[i]->points_for_deed,deed_list[j]->points_for_deed);
						                swap(deed_list[i]->total_points_earned,deed_list[j]->total_points_earned);
						            }


								}
						        if(deed_list[i]->total_points_earned == 0){
						           	cnt++;
						        }
							}

		cout<<endl;

		taskTitle("task2","deeds_total_points_earned:");
		for(int i = 0;  nRows - cnt  > i; i++)
					{

						   cout<<i<<"    ";
						   cout<<deed_list[i]->deed_id<<"  ";
						   cout<<deed_list[i]->deed_name<<setw(35);
						   cout<<deed_list[i]->points_for_deed<<"  ";
						   cout<<deed_list[i]->total_times_done<<"  ";
						   cout<<deed_list[i]->total_points_earned<<endl;
					}



		//END OF TASK2
		cout<<endl;
		//task 3
		int deed_times_sum = 0;

		for(int i = 0; nRows > i; i++)
		{
			deed_times_sum += deed_list[i]->total_times_done;
		}


		cout<<"task3: total deed_counts: "<<endl;
		cout<<deed_times_sum<<" deeds"<<endl<<endl;

		//END OF TASK3

		//task4
		int deed_points_sum = 0;

		for(int i = 0; nRows > i; i++)
		{
			deed_points_sum += deed_list[i]->total_points_earned;
		}


			cout<<"task4: total deed_points: "<<endl;
			cout<<deed_points_sum<<" points"<<endl<<endl;


		//END OF TASK4


		//task5


		for(int j = 0; nRows > j; j++)
		{
				for(int i = 1; nRows > i; i++)
				{
					if(strcmp(deed_list[i - 1]->deed_name, deed_list[i]->deed_name) > 0)

						swap(deed_list[i - 1]->deed_name,deed_list[i]->deed_name);

						swap(deed_list[i - 1]->total_times_done,deed_list[i]->total_times_done);
						swap(deed_list[i - 1]->deed_id,deed_list[i]->deed_id);
						swap(deed_list[i - 1]->points_for_deed,deed_list[i]->points_for_deed);
						swap(deed_list[i - 1]->total_points_earned,deed_list[i]->total_points_earned);



				}
	}



		taskTitle("task5","alphabetically:");
			for(int i = 0;  nRows > i; i++)
								{

									   cout<<i<<"    ";
									   cout<<deed_list[i]->deed_id<<"  ";
									   cout<<deed_list[i]->deed_name<<setw(35);
									   cout<<deed_list[i]->points_for_deed<<"  ";
									   cout<<deed_list[i]->total_times_done<<"  ";
									   cout<<deed_list[i]->total_points_earned<<endl;
								}



		//END OF TASK5

		//task6
		//binary search
		string inputName;
		cout<<"Task6:Enter a deed_name"<<endl;
		getline(cin,inputName);

		int head = 0;
		int tail = nRows - 1;
		int mid;
		int position = -1;
		bool isExist = false;

		while(!isExist && tail >= head)
		{
			mid = (head + tail)/2;
			if(deed_list[mid]->deed_name == inputName)
			{
				isExist = true;
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
			cout<<"task6: search case2:"<<endl<<"No such deed";
		}
		else
		{
			cout<<"task6: search case2:"<<endl;
			cout<<deed_list[position]->deed_name <<" "<< deed_list[position]->total_times_done<< " times "<< deed_list[position]->total_points_earned<<" points earned"<<endl;
		}

		//END OF TASK6





















				//deleting allocated memory
			for(int i = 0; nRows > i; i++)
			{
				delete [] deed_list[i];
			}

			delete [] deed_list;



			return 0;
}



