#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

int main()
{
    std::string inputFile = "data.csv";
    std::string outputFile = "result.txt";
    double S;
    int n;

    std::ifstream ifstr;
    ifstr.open(inputFile);
    if(ifstr.fail()) {
        std::cerr << "Input file not found" << std::endl;
        return 1;
    }
    std::string line;
    char spacer;
    std::istringstream convert(line);
    getline(ifstr, line);
    convert.clear();
    convert.str(line);
    convert >> spacer >> spacer >> S;
    getline(ifstr, line);
    convert.clear();
    convert.str(line);
    convert >> spacer >> spacer >> n;
    getline(ifstr, line);
    std::cout << "S:" << S << std::endl;
    std::cout << "n:" << n << std::endl;
    std::cout << "w:r" << std::endl;

    double *w_vector = new double[n];
    double *r_vector = new double[n];
    populate_data(ifstr, S, n, w_vector, r_vector);

    double V = 0;
    double rr = 0;
    compute_data(V, rr, w_vector, r_vector, S, n);
    std::cout << std::endl;
    write_output(outputFile, S, n, w_vector, r_vector, V, rr);

    delete[] w_vector;
    delete[] r_vector;

    return 0;
}


