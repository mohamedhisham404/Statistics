#include <iostream>
#include <algorithm> 
#include <cmath> 

using namespace std;

int a[50],n;
void get()
{
    int input,op,x;
    cout<<"**************************WELCOME TO STAT**************************"<<endl;
	cout<<"ENTER THE SIZE OF ELEMENTS: "<<endl;
	cin>>n;
	cout<<"ENTER THE ELEMENTS: "<<endl;
	for(int i=0;i<n;i++)
	{
            cin>>a[i];
	}
	sort(a,a+n);
}

class CentralTendency
{
public:
	int sum=0;
	float value,mid;

	
	float mean(int a[],int n)
	{
	    cout<<"you are in the mean";
    	for (int i = 0; i < n; i++) 
		{
        	sum += a[i];
    	}
    	cout<<sum;
		value=sum/n;
		cout<<value;
		return value;
	}

	int median(int a[],int n)
	{
		int middleIndex = (n - 1) / 2;
		return a[middleIndex];
	}

	int mode(int a[],int n)
	{
		// find the max frequency using linear traversal
		int max_count = 1, res = a[0], curr_count = 1;
		for (int i = 1; i < n; i++) 
		{
			if (a[i] == a[i - 1])
				curr_count++;
			else 
			{
				if (curr_count > max_count) 
				{
					max_count = curr_count;
					res = a[i - 1];
				}
				curr_count = 1;
			}
		}
	
		// If last element is most frequent
		if (curr_count > max_count)
		{
			max_count = curr_count;
			res = a[n - 1];
		}
		return res;

	}

};

class dispersion 
{
public:
	CentralTendency cent;
	int n;

	void range(int a[],int n)
	{
		int max,min,range;
		min=*min_element(a, a + n);
		max=*max_element(a,a+n );
		range=max-min;
		cout<<range<<endl;
	}

	void iqr(int a[],int n)
	{
		auto const Q1 = (int) round(n / 4);
		auto const Q2 = (int) round(n / 2);
		auto const Q3 = (Q1 + Q2)+1;
		cout<<a[Q3]-a[Q1]<<endl;
	}

	void percentile(int a[],int n)
	{
		int k;
		cout<<"WHAT IS THE NUMBER YOU WANT TO FIND ITS PERCENTILE ?"<<endl;
		cin>>k;
		cout<<a[(int)round(k*(n/100))]<<endl;
	}

	double variance(int a[],int n)
	{
		
		int sum = 0;
		double sqDiff = 0;
		
		double mean = cent.mean(a,n);
		
		//variance
		for (int i = 0; i < n; i++)
			sqDiff += (a[i] - mean) *(a[i] - mean);
		//cout<<sqDiff / n<<endl;
		return (sqDiff / n);
	}

	double StandardDeviation(int arr[],int n)
	{
		return(sqrt(variance(arr, n)));
	}

	void StandardScores(int arr[],int n)
	{
		int x;
		cout<<"WHAT IS THE VALUE YOU WANT TO FIND ITS STANDARD SCORE ?"<<endl;
		cin>>x;
		double value=(x - cent.mean(a,n)/StandardDeviation(a,n));
		cout<<"THE STANDARD SCORES FO THE DATA IS: "<<endl;
		cout<<value<<endl;
	}
}; 

int main()
{
	int input,op,x;
	CentralTendency cent;
	dispersion dis;

	
	
	do
	{
		
		cout<<"WHAT DO YOU WANT TO DO?"<<endl;
		cout<<"0. EXIT"<<endl;
		cout<<"1. CALCULATE MEASURES OF CENTRAL TENDENCY"<<endl;
		cout<<"2. CALCULATE MEASURE OF DISPERSION"<<endl;
		cin>>op;

		switch (op)
		{
		case 1:
			cout<<"1. MEAN"<<endl;
			cout<<"2. MEDIAN"<<endl;
			cout<<"3. MODE"<<endl;
			cin>>x;
			if(x==1)
			{
			    get();
			    x = cent.mean(a , n);
			    cout<<"THE MEAN OF THE DATA IS: " << x<<endl;
				

			}
			else if(x==2)
			{
				cout<<"THE MEDIAN OF THE DATA IS: "<<endl;
				cout<<cent.median(a,n)<<endl;
			}
			else if(x==3)
			{
				cout<<"THE MODE OF THE DATA IS: "<<endl;
				cout<<cent.mode(a,n)<<endl;

			}
			break;
			
		case 2:
			cout<<"1. RANGE"<<endl;
			cout<<"2. IQR"<<endl;
			cout<<"3. PERCENTILE"<<endl;
			cout<<"4. VARIANCE"<<endl;
			cout<<"5. STANDARD DEVIATION"<<endl;
			cout<<"6. STANDARD SCORES"<<endl;
			cin>>x;
			if(x==1)
			{
				cout<<"THE RANGE OF THE DATA IS: "<<endl;
				dis.range(a,n);
			}
			else if(x==2)
			{
				cout<<"THE IQR F THE DATA IS: "<<endl;
				dis.iqr(a,n);
			}
			else if(x==3)
			{
				cout<<"THE PERCENTILE OF THE DATA IS: "<<endl;
				dis.percentile(a,n);
			}
			else if(x==4)
			{
				cout<<"THE VARIANCE OF THE DATA IS: "<<endl;
				cout<<dis.variance(a,n)<<endl;
			}
			else if(x==5)
			{
				cout<<"THE STANDARD DEVIATION OF THE DATA IS: "<<endl;
				cout<<dis.StandardDeviation(a,n)<<endl;

			}
			else if(x==6)
			{
				dis.StandardScores(a,n);
			}

			break;
			
		default:
			cout<<"VALID CHOICE!"<<endl;
			break;
		}

	} while (op != 0);
	
	return(0);
}
