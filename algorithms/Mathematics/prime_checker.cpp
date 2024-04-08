#include<iostream>
using namespace std;
bool primechecker(int n)
{
	if(n==1)
	return false;
	else if(n==2 || n==3)
	return true;
	else if(n%2==0 || n%3==0)
	return false;
	for(int i=5;i*i<=n;i=i+6)
	{
		if(n%i==0 || n%(i+2)==0)
		return false;
	}
	return true;
}
int main()
{
	int x;
	cout<<"please enter a number"<<endl; 
	cin>>x;
	if(primechecker(x))
	cout<<"prime";
	else
	cout<<"not a prime";
}
