#include "Utils.hpp"

void populate_data(std::ifstream& ifstr, const double S, const int n, double* w_vector, double* r_vector) {
    std::string line;
    for (int i = 0; i<n; i++) {
        getline(ifstr, line);
        std::istringstream s(line);
        std::string r_val, w_val;
        std::getline(s, w_val, ';');
        std::getline(s, r_val, ';');
        std::cout << w_val << ";" << r_val << std::endl;
        *(w_vector + i) = std::stod(w_val);
        *(r_vector + i) = std::stod(r_val);
    }
    ifstr.close();
}

void compute_data(double& V, double& rr, double* w_vector, double* r_vector, const double S, const int n) {
    for(int i = 0; i<n; i++) {
        V += (1+*(r_vector + i)) * (S* *(w_vector + i));
    }
    rr = (V/S) - 1;
}

void write_output(std::string file_name, const double S, const int n, double* w_vector, double* r_vector, double V, double rr) {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "S: " << S << ", n: " << n << std::endl;

    std::cout << "w = [ ";
    for (int i = 0; i<n; i++) {
        std::cout << *(w_vector + i) << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "r = [ ";
    for (int i = 0; i<n; i++) {
        std::cout << *(r_vector + i) << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << std::setprecision(4) << "Rate of return of the portfolio: " << rr << std::endl;
    std::cout << std::setprecision(2) << "V: " << V << std::endl;

    std::ofstream ofstr;
    ofstr.open(file_name);
    if(ofstr.fail()) {
        std::cerr << "Error while writing on file" << std::endl;
    }
    ofstr << std::fixed;
    ofstr << std::setprecision(2);
    ofstr << "S: " << S << ", n: " << n << std::endl;

    ofstr << "w = [ ";
    for (int i = 0; i<n; i++) {
        ofstr << *(w_vector + i) << " ";
    }
    ofstr << "]" << std::endl;

    ofstr << "r = [ ";
    for (int i = 0; i<n; i++) {
        ofstr << *(r_vector + i) << " ";
    }
    ofstr << "]" << std::endl;

    ofstr << std::setprecision(4) << "Rate of return of the portfolio: " << rr << std::endl;
    ofstr << std::setprecision(2) << "V: " << V << std::endl;
    ofstr.close();
}
