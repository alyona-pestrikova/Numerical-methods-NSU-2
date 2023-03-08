//
// Created by Алёна on 02.03.2023.
//

#ifndef NUMERICAL_METHODS_NSU_2_GAUSS_METHOD_H
#define NUMERICAL_METHODS_NSU_2_GAUSS_METHOD_H


class gauss_method {
private:
    double** mx;
    int size;
    double* count();
    double* result;
    double* vec;
    void swap_str(double**& mx, int i, int j);
    int max_abs_col(double** mx, int col, int start = 0);
public:
    gauss_method(int size, double** mx, double* vec);
    double* get_res();
    ~gauss_method();
};


#endif //NUMERICAL_METHODS_NSU_2_GAUSS_METHOD_H
