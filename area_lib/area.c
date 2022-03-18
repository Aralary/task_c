// Copyright 2022 Your Name <your_email>
#include "area_lib_area.h"

double *area(double *x_arr[], size_t x_size, double *y_arr[], size_t y_size) {
    double *res = malloc(sizeof(double));
    if (x_size != y_size) {
        *res = -1;
        return res;
    }
    if (x_size == 0) {
        *res = 0;
        return res;
    }
    double part1 = 0;
    double part2 = 0;
    for (size_t i = 0; i < x_size - 1; ++i) {
        part1 += (*x_arr[i]) * (*y_arr[i + 1]);
        part2 += (*x_arr[i + 1]) * (*y_arr[i]);
    }
    part1 += ((*x_arr[x_size - 1]) * (*y_arr[0]));
    part2 += ((*x_arr[0]) * (*y_arr[x_size - 1]));

    *res = (part1 - part2) > 0 ? (part1 - part2) / 2 : (part2 - part1) / 2;
    return res;
}
