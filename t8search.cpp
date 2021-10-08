#include <iostream>
#include <fstream>
using namespace std;
#define NDATA 10

struct ivdata{
	float volt;
	float amp;
};

int linSearch (float, ivdata[],int);
int binSearch (float, ivdata[],int, int);
void readData (istream&,ivdata[],int);
void printData (ivdata[],int);

int main (int argc, char *argv[])
{
	int res1,res2;
	float input;
	ivdata Data[NDATA];

	if (argc!= 2)
	{ cerr<<"Usage: \n\t"<<argv[0]<<" <IV data file>"<<endl;
	  exit(1);
	}

	ifstream inFile(argv[1]);
	
	if (!inFile.is_open())
	{ perror("opening input file");
	  exit(1);
	}

	readData(inFile,Data,NDATA);
	printData(Data,NDATA);

	//search voltage that matched the searched current
	cout<<"Enter the voltage value to search?"<<endl;
	cin>>input;
	
	//Call search functions,store results in res1,res2
	res1=linSearch(input,Data,NDATA);
	res2=binSearch(input,Data,0,NDATA-1);

	if (res1!=-1)
		cout<<"Linear search: V="<<Data[res1].volt<<",I="<<Data[res1].amp<<endl;
	else cout<<"Not found!"<<endl;

	if (res2!=-1)
		cout<<"Binary search: V="<<Data[res2].volt<<",I="<<Data[res2].amp<<endl;
	else printf("Not found!\n");

	inFile.close();
	return 0;
}
void readData (istream &inFile, ivdata data[],int N){
	int j=0;
	double v,a;
	while (j<N)
	{	//read data from file, 2 data points in each iteration
		inFile>>v>>a;
		data[j].volt=v;
		data[j].amp=a;
		j++;
	}
}

//print the data in 2-column format
void printData (ivdata data[],int N){
	int i;
	for (i=0;i<N;i++)
    	cout<<data[i].volt<<'\t'<<data[i].amp<<endl;
}

/******************************************************************/
// Put your name and ID here.

int linSearch (float x, ivdata data[],int N){
	//Implement linear search function
}

int binSearch (float x, ivdata data[],int start, int end){
	//Implement recursve binary search function
}
