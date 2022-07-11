#include <bits/stdc++.h>
#include<fstream>
#include <algorithm> 
#include<string>
#include <cmath> 

using namespace std;

void inter(int n,vector<double>&v)
{
    double temp;
    for (int i = 0; i < n; i++)
    {
        cin>>temp;
        v.push_back(temp);

    }
	
}

class statistics
{
public:
	class CentralTendency
	{
	public:
		static double mean(vector<double>a)
		{
			double sum=0;
			for (double i:a)
			{
				sum+=i;
			}
				
			return sum/(a.size()+0.0);
		}

		static double median(vector<double>a)
		{
			sort(a.begin(), a.end());
			int size=a.size();
			if(size%2!=0)
				return a[floor(a.size()/2)];
			else
				return mean({a[size/2],a[(size/2)-1]});	
		}

		static double mode(vector<double>a)
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
		static double range(vector<double>v)
		{
			return v[v.size()-1]-v[0];
		}

		static double iqr(vector<double>v)
		{
			int size=v.size();
			int Q1 = (int) round(size / 4);
			int Q2 = (int) round(size / 2);
			int Q3 = (Q1 + Q2)+1;
			return (v[Q3]-v[Q1]);
		}

		static double percentile(vector<double>v,int k)
		{
			sort(v.begin(), v.end());
			return (v[(int)round(k*(v.size()/100))]);
		}

		static double variance(vector<double>v)
		{
			int sum = 0;
			int size=v.size();
			double sqDiff = 0;
			double mean =CentralTendency::mean(v); 
			
			//variance
			for (int i = 0; i < size; i++)
				sqDiff += (v[i] - mean) *(v[i] - mean);
			return (sqDiff / size);
		}

		static double StandardDeviation(vector<double>v)
		{
			return(sqrt(variance(v)));
		}

		static double StandardScores(vector<double>v,int x)
		{
			double sd =StandardDeviation(v);
			double mean=CentralTendency::mean(v);
			
			double value=((x - mean)/sd);
			return value;
		}
		
	}; 

	class probability
	{
	public:
		static double expected(vector<double>data,vector<double>prob)
		{
			double sum=0,size=data.size();	
			for(int i = 0; i < size; i++)
			{
				sum +=(data[i]+0.0)*prob[i];
			}
			return sum;
		}

		static double variance(vector<double>data,vector<double>prob)
		{
			int size=data.size();
			double sum=0;
			double a=expected(data,prob);
			for(int i :data)
			{
				sum +=(i-a)*(i-a);
			}
			return sum;
		}
		
		static double StandardDeviation(vector<double>v,vector<double>a)
		{
			return(sqrt(variance(v,a)));
		}
	
		static string RelationOldGainsNewGains(double gain_ratio,int old_cost,int new_cost)
		{
			string str=to_string(gain_ratio);
			string str1=to_string(gain_ratio*old_cost-new_cost);
			string res="Y = "+str+"X + "+str1;
			return (res);
		}
		
		static long double permutation(int n,int r)
		{
			//here where oder matters
			//n:NumberOfObjects
			//r:position we want to fill
			long long result1=1,result2=1,x=n-r;
			for(long long i=1;i<=n;i++)
   			{
    	    	result1 *=i;
    		}
			for(long long i=1;i<=x;i++)
   			{
    	    	result2 *=i;
    		}

			return(result1/result2);
		}
	
		static long double combinations(int n,int r)
		{
			//here where oder dose not matters
			//n:NumberOfObjects
			//r:position we want to fill
			long double result1=1,result2=1,result3=1,x=n-r;
			for(long long i=1;i<=n;i++)
   			{
    	    	result1 *=i;
    		}
			for(long long i=1;i<=x;i++)
   			{
    	    	result2 *=i;
    		}
			for(long long i=1;i<=r;i++)
   			{
    	    	result3 *=i;
    		}

			return(result1/(result2*result3));
		}
	};

	class DiscreteProbDist
	{
	public:
		/*If you have a fixed number of trials and you
		want to know the probability of getting a
		certain number of successes, you need to
		use the binomial distribution. You can also
		use this to find out how many successes you
		can expect to have in your n trials.
		If you’re interested in how many trials you’ll
		need before you have your first success,
		then you need to use the geometric
		distribution instead.*/
		class geometric
		{	
		public:	
			/*the geometric distribution is
			used for situations where you’re running
			independent trials (so the probability stays
			the same for each one), each trial ends in
			either success or failure*/
			//for infinite  number of trials
			static long double ProbabilityDist(long double p,long double q,long x)
			{
				// to calculate from prob tree
				// p: probality of succces
				// q: probality of failure
				// x: p(X = x)
				// P(X = r) is at its highest when r = 1, and it gets lower and lower as r increases
				return(pow(q,(x-1))*p);   
			}
		
			static double expectation(double p)
			{
				// p:successful outcome
				return(1/p);
			}
		
			static double variance(double p,double q)
			{
				// p:successful outcome
				// q:failure outcome
				return(q/(p*p));
			}
		};
	
		class binomial
		{
		public:
		    //with infinite trials
			static long double ProbabilityDist(long double p,long double q,int n,double r)
			{
				// p:successful outcome
				// q:failure outcome
				// n:NumberOftrials
				// r:prob for success
				//P(X = r) = Cr pr qn - r				
				return(statistics::probability::combinations(n,r)*pow(p,r)*pow(q,(n-r)));
			}
		
			static int  expectation(double p,int n)
			{
				return(n*p);
			}
		
			static double variance(double p,double q,int n)
			{
				return(p*q*n);
			}
		
		};
	
		class Poisson
		{
		public:	
			/*The key difference is that the Poisson
			distribution doesn’t involve a series of
			trials. Instead, it models the number of
			occurrences in a particular interval.*/

			//p(x =r)
			static long double ProbabilityDist(double lambda,int r)
			{
				int result =1;
				for(long long i=1;i<=r;i++)
   				{
    	    		result *=i;
    			}
				return((exp(-lambda)*pow(lambda,r))/result);
			}
		
			static int expectation(double lambda){return(lambda);}

			static int varianc(double lambda){return(lambda);}
		};
	};

	class continuousProbDist
	{
	public:
		class normal
		{
		public:
			//The normal distribution is an “ideal” model for continuous data
			static double ProbabilityDist(double mean,double variance,double x)
			{
				vector<vector<string>> content;
				vector<string> row;
				string line, word;
				int i, j,xa;		
				
				//Z ~ N(0, 1)
				double z=(x-mean)/sqrt(variance);
				double zToOneDecimalPlace = ceil(z * 10.0) / 10.0;
				int intz = (ceil(z * 100.0) / 100.0)*100;
				double lastDigitOfz=(intz%10)/100.0;

				vector<double>mo={0,0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.09};
				vector<double>y={-4.9,-4.8,-4.7,-4.6,-4.5,-4.4,-4.3,-4.2,-4.1,-4.0,-3.9,-3.8,-3.7,-3.6,-3.5,-3.4,-3.3,-3.2,-3.1,-3.0,-2.9,-2.8,-2.7,-2.6,-2.5,-2.4,-2.2,-2.1,-2.0,-1.9,-1.8,-1.7,-1.6,-1.5,-1.4,-1.3,-1.2,-1.1,-1.0,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1,-0.0,0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9};

				for (int l = 0; l < mo.size(); l++)
				{  
					if (mo[l] == lastDigitOfz*-1)
						i = l;
				}

				for (int k = 0; k < y.size(); k++)
				{

					if (y[k] == zToOneDecimalPlace)
						j = k;
				}
								
				fstream file ("z table.csv", ios::in);
				if(file.is_open())
				{
					while(getline(file, line))
					{
						row.clear();
						stringstream str(line);
						while(getline(str, word, ','))
							row.push_back(word);
						content.push_back(row);
					}
				}
				else
					cout<<"Could not open the file\n";
				
				if(lastDigitOfz*-1>=0.05)
					 xa=2;
				else
					 xa=1;
					string num=content[j+1][i+xa];
					float result=stof(num);
					return (1-result);
					
				
			}
		
			static double IndependetObservationDist(double mean,double variance,int n,int x)
			{
				//X1 + X2 + ... + Xn ~ N(nμ, nσ2)
				double newmean=mean*n;
				double newvariance=variance*n;
				return(1-(normal::ProbabilityDist(newmean,newvariance,x)));

			}
		
			static double linearTransfomationDist(double mean,double variance,double a,double b,double x)
			{
				//X ~ N(μ, σ2)
				//Y = aX + b
				//Y ~ N(aX + b, a^2σ2)
				double newmean=a*mean+b;
				double newvariance=pow(a,2)*variance;
				return(1-(normal::ProbabilityDist(newmean,newvariance,x)));
			}
		
			static double ApproximateBinomalDist(double n,double p,double x)
			{
				//the shape of the binomial distribution looks
				//very similar to the normal distribution. In these situations, we can use the
				//normal distribution in place of the binomial to give a close approximation of its
				//probabilities
				double mean=n*p;
				double variance=n*p*(1-p);
				return(1-(normal::ProbabilityDist(mean,variance,x)));

			}
		};	
	};

	class estimation
	{
	public:	
		//estimating the population information by samble information
		class pointEstimation
		{
		public:
			static double mean(vector<double>v){return CentralTendency::mean(v);}

			static double variance(vector<double>v)
			{
				int sum = 0;
				int size=v.size();
				double sqDiff = 0;
				double mean =CentralTendency::mean(v); 
				
				//variance
				for (int i = 0; i < size; i++)
					sqDiff += (v[i] - mean) *(v[i] - mean);
				//cout<<sqDiff / n<<endl;
				return (sqDiff / (size-1));
			}		

			static double StandardErrorOfPropotion(double q,double p,int n)
			{
				return(sqrt((p*q)/n));
			}	
		};
		
		class ConfidenceIntervals
		{
		public:	
				static double normal(double variance,double mean,double level)
				{
					vector<vector<string>> content;
					vector<string> row;
					string line, word;
					int i, j,xa;

					double z=(1-(level/100.0))/2;

					double zToOneDecimalPlace = ceil(z * 10.0) / 10.0;
					int intz = (ceil(z * 100.0) / 100.0)*100;
					double lastDigitOfz=(intz%10)/100.0;

					vector<double>mo={0,0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.09};
					vector<double>y={-4.9,-4.8,-4.7,-4.6,-4.5,-4.4,-4.3,-4.2,-4.1,-4.0,-3.9,-3.8,-3.7,-3.6,-3.5,-3.4,-3.3,-3.2,-3.1,-3.0,-2.9,-2.8,-2.7,-2.6,-2.5,-2.4,-2.2,-2.1,-2.0,-1.9,-1.8,-1.7,-1.6,-1.5,-1.4,-1.3,-1.2,-1.1,-1.0,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1,-0.0,0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9};

					for (int l = 0; l < mo.size(); l++)
					{  
						if (mo[l] == lastDigitOfz*-1)
							i = l;
					}

					for (int k = 0; k < y.size(); k++)
					{

						if (y[k] == zToOneDecimalPlace)
							j = k;
					}
									
					fstream file ("z table.csv", ios::in);
					if(file.is_open())
					{
						while(getline(file, line))
						{
							row.clear();
							stringstream str(line);
							while(getline(str, word, ','))
								row.push_back(word);
							content.push_back(row);
						}
					}
					else
						cout<<"Could not open the file\n";
					
					if(lastDigitOfz*-1>=0.05)
						xa=2;
					else
						xa=1;
						string num=content[j+1][i+xa];
						float result=stof(num);
						
					double mresult=-1*result;

					double result2=sqrt(variance)*result;
					double mresult2=sqrt(variance)*mresult;	

					double a=mean+result2;
					double b=mean+mresult2;
					cout<<b<<"   "<<a<<endl;
					return 0;			
				}
		};
		
	};

};

int main()
{
	int op,n,z,K,x,n1,r,z2,x1;
	double ratio,old,new1,success,p,q,lambda,xvariable,xco,ab,mean,variance,level;
	vector<double>v;
	vector<double>data;
	vector<double>prob;

	do
	{
		cout<<"**************************WELCOME TO STAT**************************"<<endl;
		cout<<"WHAT DO YOU WANT TO DO?"<<endl;
		cout<<"0. EXIT"<<endl;
		cout<<"1. CALCULATE MEASURES OF CENTRAL TENDENCY"<<endl;
		cout<<"2. CALCULATE MEASURES OF DISPERSION"<<endl;
		cout<<"3. CALCULATE DISCRETE PROBABILITY DISTRIBUTION"<<endl;
		cout<<"4. CALCULATE PERMUTATION AND COMBINATION"<<endl;
		cout<<"5. CALCULATE LINEAR RELATIONSHIP BETWEEN E(X) AND E(Y)"<<endl;
		cout<<"6. CALCULATE DISCRETE PROBABILITY DISTRIBUTION"<<endl;
		cout<<"7. CALCULATE CONTINUOUES PROBABILITY DISTRIBUTION(NORMAL)"<<endl;
		cout<<"8. CALCULATE THE ESTIMATION"<<endl;
		cin>>op;

		switch (op)
		{
		case 1:
			cout<<"ENTER THE SIZE OF DATA"<<endl;
			cin>>n;
			cout<<"ENTER THE DATA"<<endl;
			inter(n,v);

			cout<<"MEAN: "<<statistics::CentralTendency::mean(v)<<endl;
			cout<<"MEDIAN: "<<statistics::CentralTendency::median(v)<<endl;
			cout<<"MODE: "<<statistics::CentralTendency::mode(v)<<endl;
			break;

		case 2:
			cout<<"ENTER THE SIZE OF DATA"<<endl;
			cin>>n;
			cout<<"ENTER THE DATA"<<endl;
			inter(n,v);

			cout<<"WHAT DO YOU WANT TO CACULATE"<<endl;
			cout<<"1. PERCENTILE"<<endl;
			cout<<"2. STANDARD SCORES"<<endl;
			cout<<"3. OTHER MEASURING OF VARIABILITY"<<endl;
			cin>>z;
			if(z==1)
			{
				cout<<"ENTER kth PERCENTILE"<<endl;
				cin>>K;
				cout<<"PERCENTILE: "<<statistics::dispersion::percentile(v,K)<<endl;
			}
			else if (z==2)
			{
				cout<<"ENTER x value"<<endl;
				cin>>x;
				cout<<"STANDARD SCORES: "<<statistics::dispersion::StandardScores(v,x)<<endl;
			}
			else if (z==3)
			{
				cout<<"RANGE: "<<statistics::dispersion::range(v) <<endl;
				cout<<"IQR: "<<statistics::dispersion::iqr(v)<<endl;
				cout<<"VARIANCE: "<<statistics::dispersion::variance(v)<<endl;
				cout<<"STANDARD DEVIATION: "<<statistics::dispersion::StandardDeviation(v)<<endl;				
			}
			break;

		case 3:
			cout<<"ENTER THE SIZE OF DATA"<<endl;
			cin>>n;
			cout<<"ENTER THE DATA"<<endl;
			inter(n,data);
			cout<<"ENTER THE PROBABILITY"<<endl;
			inter(n,prob);
			cout<<"EXPECTED: "<<statistics::probability::expected(data,prob)<<endl;
			cout<<"VARIANCE: "<<statistics::probability::expected(data,prob)<<endl;
			cout<<"STANDARD DEVIATION: "<<statistics::probability::expected(data,prob)<<endl;
			break;	
			
		case 4:
			cout<<"ENTER THE NUMBER OF OBJECTS"<<endl;
			cin>>n1;
			cout<<"ENTER THE POSITION YOU WANT TO FILL"<<endl;
			cin>>r;
			cout<<"PERMIOTATION: "<<statistics::probability::permutation(n1,r) <<endl;
			cout<<"COMBINATION: "<<statistics::probability::combinations(n1,r)<<endl;
			break;	

		case 5:
			cout<<"ENTER THE GAIN RATIO"<<endl;
			cin>>ratio;
			cout<<"ENTER THE OLD COST"<<endl;
			cin>>old;
			cout<<"ENTER THE NEW COST"<<endl;
			cin>>new1;
			cout<<"THE RELATION: "<<statistics::probability::RelationOldGainsNewGains(ratio,old,new1)<<endl;
			break;

		case 6:
			cout<<"WHAT DISTRIBUTION DO YOU WANT TO CALCULATE"<<endl;
			cout<<"1. GEOMETRIC"<<endl;
			cout<<"2. BINOMIAL"<<endl;
			cout<<"3. BOIASSON"<<endl;

			if (z2==1)
			{
				cout<<"ENTER THE PROBABILITY OF SUCCESS"<<endl;
				cin>>success;
				double failure=1-success;
				cout<<"ENTER THE PROBABILITY X"<<endl;
				cin>>x1;
				cout<<"PROBABILITY DISTRIBUTION: "<<statistics::DiscreteProbDist::geometric::ProbabilityDist(success,failure,x1)<<endl;
				cout<<"EXPECTATION: "<<statistics::DiscreteProbDist::geometric::expectation(success)<<endl;
				cout<<"VARIANCE: "<<statistics::DiscreteProbDist::geometric::variance(success,failure)<<endl;
			}
			else if (z2==2)
			{
				cout<<"ENTER THE NUMBER OF TRIALS"<<endl;
				cin>>n;
				cout<<"ENTER THE SUCCESSFUL OUTCOME"<<endl;
				cin>>p;
				cout<<"ENTER THE FAILUR OUTCOME"<<endl;
				cin>>q;
				cout<<"ENTER THE PROBABILITY OF SUCCESS"<<endl;
				cin>>success;
				cout<<"PROBABILITY DISTRIBUTION: "<<statistics::DiscreteProbDist::binomial::ProbabilityDist(p,q,n,success)<<endl;
				cout<<"EXPECTATION: "<<statistics::DiscreteProbDist::binomial::expectation(p,n)<<endl;
				cout<<"VARIANCE: "<<statistics::DiscreteProbDist::binomial::variance(p,q,n)<<endl;	
			}
			else if (z2==3)
			{
				cout<<"ENTER THE MEAN NUMBER OF OCCURRENCES(LAMBDA)"<<endl;
				cin>>lambda;
				cout<<"ENTER THE RATE OF OCCURRENCES"<<endl;
				cin>>r;
				cout<<"PROBABILITY DISTRIBUTION: "<<statistics::DiscreteProbDist::Poisson::ProbabilityDist(lambda,r)<<endl;
				cout<<"EXPECTATION: "<<statistics::DiscreteProbDist::Poisson::expectation(lambda)<<endl;
				cout<<"VARIANCE: "<<statistics::DiscreteProbDist::Poisson::varianc(lambda)<<endl;
			}
			break;

		case 7:
			cout<<"ENTER X VARIABLE"<<endl;
			cin>>xvariable;
			cout<<"DO YOU HAVE THE INFORMATION OR DATA?"<<endl;
			cout<<"1. DATA"<<endl;
			cout<<"2. INFORMATION"<<endl;
			cin>>z;
			if(z==1)
			{
				cout<<"WHAT DO YOU WANT TO CALCULATE"<<endl;
				cout<<"1. PROBABILITY DISTRIBUTION AND INDEPENDENT OBSERVATION DISTRIBUTION"<<endl;
				cout<<"2. LINEAR TRANSFORMATION DISTRIBUTION"<<endl;
				cout<<"3. APPROXIMATE BINOMIAL DISTRIBUTION"<<endl;
				cin>>z2;
				if (z2==1)
				{
					cout<<"ENTER THE SIZE OF DATA"<<endl;
					cin>>n;
					cout<<"ENTER THE DATA"<<endl;
					inter(n,v);	
					mean=statistics::CentralTendency::mean(v);
					variance = statistics::dispersion::variance(v);
					cout<<"PROBABILITY DISTRIBUTION"<<statistics::continuousProbDist::normal::ProbabilityDist(mean,variance,xvariable)<<endl;
					cout<<"INDEPENDENT OBSERVATION DISTRIBUTION"<<statistics::continuousProbDist::normal::IndependetObservationDist(mean,variance,n,xvariable)<<endl;
				}
				else if(z2==2)
				{
					cout<<"ENTER THE X COEFFICIENT"<<endl;
					cin>>xco;
					cout<<"ENTER THE ABSLOUT PART"<<endl;
					cin>>ab;
					cout<<"ENTER THE SIZE OF DATA"<<endl;
					cin>>n;
					cout<<"ENTER THE DATA"<<endl;
					inter(n,v);	
					mean=statistics::CentralTendency::mean(v);
					variance = statistics::dispersion::variance(v);
					cout<<"LINEAR TRANSFORMATION DITRIBUTION"<<statistics::continuousProbDist::normal::linearTransfomationDist(mean,variance,xco,ab,xvariable)<<endl;
				}
				else if(z2==3)
				{
					cout<<"ENTER THE PROBABILITY OF SUCCESS"<<endl;
					cin>>success;
					cout<<"ENTER THE NUMBER OF VALUES"<<endl;
					cin>>n;
					cout<<"APPROXIMATION OF BINOMIAL DISTRIBUTION"<<statistics::continuousProbDist::normal::ApproximateBinomalDist(n,success,xvariable)<<endl;
				}	
			}
			else if(z==2)
			{
				cout<<"WHAT DO YOU WANT TO CALCULATE"<<endl;
				cout<<"1. PROBABILITY DISTRIBUTION AND INDEPENDENT OBSERVATION DISTRIBUTION"<<endl;
				cout<<"2. LINEAR TRANSFORMATION DISTRIBUTION"<<endl;
				cout<<"3. APPROXIMATE BINOMIAL DISTRIBUTION"<<endl;
				cin>>z2;
				if (z2==1)
				{
					cout<<"ENTER THE MEAN"<<endl;
					cin>>mean;
					cout<<"ENTER THE VARIANCE"<<endl;
					cin>>variance;
					cout<<"PROBABILITY DISTRIBUTION"<<statistics::continuousProbDist::normal::ProbabilityDist(mean,variance,xvariable)<<endl;
					cout<<"INDEPENDENT OBSERVATION DISTRIBUTION"<<statistics::continuousProbDist::normal::IndependetObservationDist(mean,variance,n,xvariable)<<endl;
				}
				else if (z2==2)
				{
					cout<<"ENTER THE X COEFFICIENT"<<endl;
					cin>>xco;
					cout<<"ENTER THE ABSLOUT PART"<<endl;
					cin>>ab;
					cout<<"ENTER THE MEAN"<<endl;
					cin>>mean;
					cout<<"ENTER THE VARIANCE"<<endl;
					cin>>variance;
					cout<<"LINEAR TRANSFORMATION DITRIBUTION"<<statistics::continuousProbDist::normal::linearTransfomationDist(mean,variance,xco,ab,xvariable)<<endl;
				}
				else if (z2==3)
				{
					cout<<"ENTER THE PROBABILITY OF SUCCESS"<<endl;
					cin>>success;
					cout<<"ENTER THE NUMBER OF VALUES"<<endl;
					cin>>n;
					cout<<"APPROXIMATION OF BINOMIAL DISTRIBUTION"<<statistics::continuousProbDist::normal::ApproximateBinomalDist(n,success,xvariable)<<endl;
				}
			}
			break;

		case 8:
			cout<<"WHAT DO YOU WANT TO CALCULATE"<<endl;
			cout<<"1. POINT ESTIMATION"<<endl;
			cout<<"2. STANDARD ERROR OF PROPOTION"<<endl;
			cout<<"3. CONFIDENCE INTERVAL"<<endl;
			cin>>z;

			if (z==1)
			{
				cout<<"ENTER THE SIZE OF DATA"<<endl;
				cin>>n;
				cout<<"ENTER THE DATA"<<endl;
				inter(n,v);
				cout<<"MEAN: "<<statistics::estimation::pointEstimation::mean(v)<<endl;
				cout<<"VARIANCE: "<<statistics::estimation::pointEstimation::variance(v)<<endl;	
			}
			else if(z==2)
			{
				cout<<"ENTER THE PROBABILITY OF SUCCESS"<<endl;
				cin>>success;
				double failure=1-success;
				cout<<"ENTER THE NUMBER OF DATA"<<endl;
				cin>>n;
				cout<<"VARIANCE: "<<statistics::estimation::pointEstimation::StandardErrorOfPropotion(failure,success,n)<<endl;
			}
			else if (z==3)
			{
				cout<<"ENTER THE LEVEL OF COFIDENCE"<<endl;
				cin>>level;
				cout<<"DO YOU HAVE THE INFORMATION OR DATA?"<<endl;
				cout<<"1. DATA"<<endl;
				cout<<"2. INFORMATION"<<endl;
				cin>>z2;
				if (z2==1)
				{
					cout<<"ENTER THE SIZE OF DATA"<<endl;
					cin>>n;
					cout<<"ENTER THE DATA"<<endl;
					inter(n,v);	
					mean=statistics::CentralTendency::mean(v);
					variance = statistics::dispersion::variance(v);
					cout<<"THE CONFIDENCE INTERVAL: "<<statistics::estimation::ConfidenceIntervals::normal(variance,mean,level)<<endl;
				}
				else if (z2==2)
				{
					cout<<"ENTER THE MEAN"<<endl;
					cin>>mean;
					cout<<"ENTER THE VARIANCE"<<endl;
					cin>>variance;
					cout<<"THE CONFIDENCE INTERVAL: "<<statistics::estimation::ConfidenceIntervals::normal(variance,mean,level)<<endl;
				}
			}
			break;	
		default:
			cout<<"VALID CHOICE!"<<endl;
			break;
		}

	} while (op != 0);
	
	return(0);
}
