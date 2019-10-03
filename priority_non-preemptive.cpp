//Implementation of Priority(Non-Preeemptive) Using C++
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct proccess
{
	int at,bt,pr,ct,ta,wt;
	string pro_id;

			  /*
	artime = Arrival time,
	bt = Burst time,
	ct = Completion time,
	ta = Turn around time,
	wt = Waiting time
	*/

}process;

bool compare(process a,process b)
{
	return a.at<b.at;
		 /* This schedule will always return TRUE
if above condition comes*/

}

bool compare2(process a,process b)
{
	return a.pr>b.pr;
	 /* This schedule will always return TRUE
if above condition comes*/

}

int main()
{
	process pro[10];
	int n,i,j;
	cout<<"Enter the number of process::";
	cin>>n;
	cout<<"Enter the process id arrival time burst time and priority :::";

	for(i=0;i<n;i++)
	{
		cin>>pro[i].pro_id;
		cin>>pro[i].at;
		cin>>pro[i].bt;
		cin>>pro[i].pr;
	}

	sort(pro,pro+n,compare);

	 /*sort is a predefined funcion  defined in algorithm.h header file,
it will sort the schedulees according to their arrival time*/

	pro[0].ct=pro[0].bt+pro[0].at;
	pro[0].ta=pro[0].ct-pro[0].at;
	pro[0].wt=pro[0].ta-pro[0].bt;
	i=1;

	while(i<n-1)
	{

		for(j=i;j<n;j++)
		{
			if(pro[j].at>pro[i-1].ct)
			break;
		}
		sort(pro+i,pro+i+(j-i),compare2);
		pro[i].ct=pro[i-1].ct+pro[i].bt;
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].bt;
		i++;
		}
		pro[i].ct=pro[i-1].ct+pro[i].bt;
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].bt;

	for(i=0;i<n;i++)
	{
		//desplaying all the values
		cout<<pro[i].pro_id<<"\t"<<pro[i].at<<"\t"<<pro[i].bt<<"\t"<<pro[i].ct<<"\t"<<pro[i].ta<<"\t"<<pro[i].wt<<"\t"<<pro[i].pr;
		cout<<endl;
	}
	return 0;
}
