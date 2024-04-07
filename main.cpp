#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
//#include "kssolver.cpp"
#include "tspsolver.cpp"

int main(){
    int i;
    	tspparser Parser1("tsp_5_1.txt");
    	Parser1.tspparser_f();
    	tspsolver Solver1(&Parser1);

    	tspparser Parser2("tsp_100_5.txt");
    	Parser2.tspparser_f();
    	tspsolver Solver2(&Parser2);

    	tspparser Parser3("tsp_136_1.txt");
    	Parser3.tspparser_f();
    	tspsolver Solver3(&Parser3);



	return 0;
}
