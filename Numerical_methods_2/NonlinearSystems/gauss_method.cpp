//
// Created by Алёна on 02.03.2023.
//
#include <iostream>
#include <iomanip>
#include "gauss_method.h"
using namespace std;

gauss_method::gauss_method(int _size, double **_mx, double *_vec) {
    size = _size;
    mx = new double* [size];
    vec = new double[size];
    result = new double[size];
    for (int i = 0; i < size; i++) {
        mx[i] = new double[size];
        vec[i] = _vec[i];
        for (int j = 0; j < size; j++) {
            mx[i][j] = _mx[i][j];
        }
    }
    vec = _vec;
    double* res = count();
    for (int i = 0; i < size; i++) {
        result[i] = res[i];
    }
   //result = count();
}

double *gauss_method::get_res() {
    return result;
}

void gauss_method::swap_str(double **& mx, int i, int j) {
    for (int k = 0; k < size; k++) {
        swap(mx[i], mx[j]);
    }
}

int gauss_method::max_abs_col(double **mx, int col, int start) {
    double max = 0;
    int id = start;
    for(int i = start; i < size; i++) {
        if (abs(mx[i][col]) > max) {
            max = abs(mx[i][col]);
            id = i;
        }
    }
    if (max == 0) {
        cout << "COL = " << col << " VALUE = " << mx[id][col] << endl;
        throw "det is 0";
    }
    return id;
}

double *gauss_method::count() {
    double** copy = new double*[size];
    double* b = new double[size];
    for (int i = 0; i < size; i++) {
        copy[i] = new double[size];
        b[i] = vec[i];
        for (int j = 0; j < size; j++) {
            copy[i][j] = mx[i][j];
        }
    }

    for (int i = 0; i < size; i++) {

        //меняем местами i-ю строку и строку, содержащую максимальный по модулю элемент в столбце
        int max = max_abs_col(copy, i, i);
        swap_str(copy, i, max);
        swap(b[i], b[max]);
        //делим i=ю строку на диагональный элемент
        double diag = copy[i][i];
        for (int j = 0; j < size; j++)
            copy[i][j] /= diag;
        b[i] /= diag;
        //зануляем все элементы i-го столбца над и под диагональю
        for (int j = 0; j < size; j++) {
            if (j == i) {
                continue;
            }
            double elem = copy[j][i];
            for (int k = 0; k < size; k++) {
                copy[j][k] -= copy[i][k] * elem;
            }
            b[j] -= b[i] * elem;
        }
    }

    for (int i = 0; i < size; i++) {
        delete[] copy[i];
    }
    delete[] copy;

    return b;
}

gauss_method::~gauss_method() {
    for (int i = 0; i < size; i++) {
        delete[] mx[i];
    }
    delete[] mx;
    delete[] result;
    delete[] vec;
}
