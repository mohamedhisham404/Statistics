#include <iostream>
#include<vector>
#include <algorithm> 
#include<string>
#include <cmath> 

using namespace std;

class statistics
{
public:
	class CentralTendency
	{
	public:
		static float mean(vector<int>a)
		{
			int sum=0;
			for (int i:a)
			{
				sum+=i;
			}
				
			return sum/(a.size()+0.0);
		}

		static int median(vector<int>a)
		{
			int size=a.size();
			if(size%2!=0)
				return a[floor(a.size()/2)];
			else
				return mean({a[size/2],a[(size/2)-1]});	
		}

		static int mode(vector<int>a)
		{
			int max_count = 1, res = a[0], curr_count = 0,mode,size=a.size();
			for (int i = 0; i < size; ++i) 
			{
				if (a[i] == res)
					++curr_count;
				else 
				{
					if (curr_count > max_count) 
					{
						max_count = curr_count;
						mode=res;
						res=a[i];
					}
					curr_count = 0;
				}
			}
			if (max_count == 1)
			{
				return -1;
			}
			return mode;

		}

	};

	class dispersion 
	{
	public:
		static int range(vector<int>v)
		{
			return v[v.size()-1]-v[0];
		}

		static int iqr(vector<int>v)
		{
			int size=v.size();
			int Q1 = (int) round(size / 4);
			int Q2 = (int) round(size / 2);
			int Q3 = (Q1 + Q2)+1;
			return (v[Q3]-v[Q1]);
		}

		static float percentile(vector<int>v,int n)
		{
			return (v[(int)round(n*(v.size()/100))]);
		}

		static double variance(vector<int>v)
		{
			int sum = 0;
			int size=v.size();
			double sqDiff = 0;
			double mean =CentralTendency::mean(v); 
			
			//variance
			for (int i = 0; i < size; i++)
				sqDiff += (v[i] - mean) *(v[i] - mean);
			//cout<<sqDiff / n<<endl;
			return (sqDiff / size);
		}

		static double StandardDeviation(vector<int>v)
		{
			return(sqrt(variance(v)));
		}

		static float StandardScores(vector<int>v,int n)
		{
			float sd =StandardDeviation(v);
			float mean=CentralTendency::mean(v);
			
			double value=((n - mean)/sd);
			return value;
		}
		
	}; 

	class probability
	{
	public:
		static float expected(vector<int>data,vector<float>prob)
		{
			float sum=0,size=data.size();	
			for(int i = 0; i < size; i++)
			{
				sum +=(data[i]+0.0)*prob[i];
			}
			return sum;
		}

		static float variance(vector<int>data,vector<float>prob)
		{
			int size=data.size();
			float sum=0;
			double a=expected(data,prob);
			for(int i :data)
			{
				sum +=(i-a)*(i-a);
			}
			return sum;
		}
		
		static double StandardDeviation(vector<int>v,vector<float>a)
		{
			return(sqrt(variance(v,a)));
		}
	
		static string RelationOldGainsNewGains(float gain_ratio,int old_cost,int new_cost)
		{
			string str=to_string(gain_ratio);
			string str1=to_string(gain_ratio*old_cost-new_cost);
			string res="Y = "+str+"X + "+str1;
			return (res);
		}
	
		static int ExpectedOfRelation(auto relation,float expected)
		{
			
		}
	};
};
int main()
{
	// int input;
	// cin>>input;
	// vector<int>v(input);
	// vector<float>a(input);

	// for(int i=0 ; i<input ; ++i )
	// {
	// 	cin>>v[i];
	// }
	// for(int i=0 ; i<input ; ++i )
	// {
	// 	cin>>a[i];
	// }
	//cout<<"ex:"<<statistics::probability::expected(v, a);
	//cout<<"var"<<statistics::probability::variance(v, a);
	cout<<statistics::probability::RelationOldGainsNewGains(5,1,2);
	

	// do
	// {
	// 	cout<<"**************************WELCOME TO STAT**************************"<<endl;
	// 	cout<<"WHAT DO YOU WANT TO DO?"<<endl;
	// 	cout<<"0. EXIT"<<endl;
	// 	cout<<"1. CALCULATE MEASURES OF CENTRAL TENDENCY"<<endl;
	// 	cout<<"2. CALCULATE MEASURE OF DISPERSION"<<endl;
	// 	cin>>op;

	// 	switch (op)
	// 	{
	// 	case 1:
	// 		cout<<"1. MEAN"<<endl;
	// 		cout<<"2. MEDIAN"<<endl;
	// 		cout<<"3. MODE"<<endl;
	// 		cin>>x;
	// 		if(x==1)
	// 		{
	// 		    get();
	// 		    x = cent.mean(a , n);
	// 		    cout<<"THE MEAN OF THE DATA IS: " << x<<endl;
	// 		}
	// 		else if(x==2)
	// 		{
	// 			get();
	// 		    x = cent.median(a , n);
	// 		    cout<<"THE MEDIAN OF THE DATA IS: " << x<<endl;
	// 		}
	// 		else if(x==3)
	// 		{
	// 			get();
	// 		    x = cent.mode(a , n);
	// 		    cout<<"THE MODE OF THE DATA IS: " << x<<endl;
	// 		}
	// 		break;
			
	// 	case 2:
	// 		cout<<"1. RANGE"<<endl;
	// 		cout<<"2. IQR"<<endl;
	// 		cout<<"3. PERCENTILE"<<endl;
	// 		cout<<"4. VARIANCE"<<endl;
	// 		cout<<"5. STANDARD DEVIATION"<<endl;
	// 		cout<<"6. STANDARD SCORES"<<endl;
	// 		cin>>x;
	// 		if(x==1)
	// 		{
	// 			get();
	// 		    x = dis.range(a , n);
	// 		    cout<<"THE RANGE OF THE DATA IS: " << x<<endl;
	// 		}
	// 		else if(x==2)
	// 		{
	// 			get();
	// 		    x = dis.iqr(a , n);
	// 		    cout<<"THE IQR OF THE DATA IS: " << x<<endl;
	// 		}
	// 		else if(x==3)
	// 		{
	// 			get();
	// 		    x = dis.percentile(a , n);
	// 		    cout<<"THE PERCENTILE OF THE DATA IS: " << x<<endl;
	// 		}
	// 		else if(x==4)
	// 		{
	// 			get();
	// 		    x = dis.variance(a , n);
	// 		    cout<<"THE VARIANCE OF THE DATA IS: " << x<<endl;
	// 		}
	// 		else if(x==5)
	// 		{
	// 			get();
	// 		    x = dis.StandardDeviation(a , n);
	// 		    cout<<"THE STANDARD DEVIATION OF THE DATA IS: " << x<<endl;
	// 		}
	// 		else if(x==6)
	// 		{
	// 			dis.StandardScores(a,n);
	// 		}

	// 		break;
			
	// 	default:
	// 		cout<<"VALID CHOICE!"<<endl;
	// 		break;
	// 	}

	// } while (op != 0);

	
	return(0);
}
