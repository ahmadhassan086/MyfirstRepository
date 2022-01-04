#include<iostream>
using namespace std;
int main()
{
	int process[]={0}, BT[]={0},AT[]={0};
	int FT[]={0}, wt[]={0},tat[]={0},avgwt=0,avgtat=0;
	int n= sizeof (process)/sizeof(process[0]);
	
	for(int i=0;i<n;i++){
		if(process[i]==0)
		{
		FT[i]=BT[i]+AT[i];
		}
	//Handle the Idle CASE when there will be CPU idle	
		else{
		
		if(FT[i-1]-AT[i]< 0)
		{
			FT[i]=BT[i]+FT[i-1]-(FT[i-1]-AT[i]);
			
		}
		else{
				FT[i]=BT[i]+FT[i-1];
			}
		}
		
	}
	for(int i=0;i<n;i++)
	{
		tat[i]=FT[i]-AT[i];
		wt[i]=tat[i]-BT[i];
		avgtat= avgtat+tat[i];
		avgwt= avgwt+wt[i];
	}
	avgtat= avgtat/n;
	avgwt=avgwt/n;
}

