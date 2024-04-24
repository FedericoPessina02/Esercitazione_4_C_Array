#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

void populate_data(std::ifstream& file, const double S, const int n, double* w_vector, double* r_vector);
void compute_data(double& V, double& rr, double* w_vector, double* r_vector, const double S, const int n);
void write_output(std::string file_name, const double S, const int n, double* w_vector, double* r_vector, double V, double rr);
