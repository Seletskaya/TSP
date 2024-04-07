#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include "tspparser.cpp"
using namespace std;

class tspsolver{
    tspparser *el;
    double out;
public:
	vector <int> path;
	tspsolver(tspparser *p):el(p){
	    int i,j;
	    //cout<<"path:"<<endl;
	    for (i = 0;i<el->n;i++){// first path
            path.push_back(i);
           // cout<<path[i]<<" ";
	    }
	    double dist = 0;
	    for (i=0; i<(el->n-1); i++){
        for (j=i+2; j<(el->n); j++) {
            dist = length_1(path[i], path[j]) + length_1(path[i+1], path[(j+1)%el->n]) - length_1(path[i], path[i+1]) - length_1(path[j], path[(j+1)%el->n]);
           // cout<<dist<<endl;
            if (dist < 0) {
                reverse(path.begin()+i+1,path.begin()+j+1);
                j = i+2;
            }

        }
	    }
        out = 0;
	    for (i = 0;i<el->n-1;i++){
            out += length_1(path[i],path[i+1]);
	    }
	    cout<<endl;
	    out += length_1(path[el->n-1],path[0]);
        for (i = 0;i<el->n;i++){// end path
            cout<<path[i]<<" ";
	    }


	    cout<<endl<<out<<endl;
	}
double length_1(int a, int b){
    double l = sqrt(pow((el->V[a]-el->V[b]),2)+pow((el->W[a]-el->W[b]),2));
    return l;
}
};

