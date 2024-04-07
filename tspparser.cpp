#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class tspparser {
	string filename;
	ifstream file;
public:
   	int n;
    double* V;
    double* W;

tspparser(const string& s):filename (s){
    //cout<<"parser srart"<<endl;
    n=0;
}

void tspparser_f (){
  int i;
  file.open (filename);
    if(!file.is_open()){
        cout<<"The file is not opened";
    }
    string s,s1;
    getline (file, s);
    n = stod (s);
    //cout<<"n:"<<n<<endl;
  V = new double[n];
  W = new double[n];
  for (i = 0; i < n; i++){
      V[i] = 0;
      W[i] = 0;
    }
  for (i = 0; i < n; i++){
      getline (file, s,' ');
      V[i] = stod (s);	//get V
      getline (file, s1);	//get W
      W[i] = stod (s1);
    }
/*
    cout<<"V:"<<endl;
    for(i=0;i<n;i++){
        cout<<V[i]<<" ";
    }
    cout<<endl;
    cout<<"W:"<<endl;
    for(i=0;i<n;i++){
        cout<<W[i]<<" ";
    }
    cout<<endl;
*/
  file.close();
  return;
}

~tspparser (){
  if (file.is_open ()){
      file.close ();
    }
    delete[]V;
    delete[]W;
}

};
