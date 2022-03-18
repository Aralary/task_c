// Copyright 2022 Your Name <your_email>
#include <gtest/gtest.h>

extern "C" {
#include "area_lib_area.h"
}
TEST(Area_test, area_good_count) {
    double a = 0;
    double b = 2;
    double *p = &a;
    double *k = &b;
    double *x_arr[4] = {p, p, k, k};
    double *y_arr[4] = {p, k, k, p};
    size_t x_size = sizeof(x_arr) / sizeof(double *);
    size_t y_size = sizeof(y_arr) / sizeof(double *);
    double *res = area(x_arr, x_size, y_arr, y_size);
    EXPECT_EQ(*res, 4);
    free(res);
}

TEST(Area_test, area_error_count1) {
    double a = 0;
    double b = 2;
    double *p = &a;
    double *k = &b;
    double *x_arr[3] = {p, p, k};
    double *y_arr[4] = {p, k, k, p};
    size_t x_size = sizeof(x_arr) / sizeof(double *);
    size_t y_size = sizeof(y_arr) / sizeof(double *);
    double *res = area(x_arr, x_size, y_arr, y_size);
    EXPECT_EQ(*res, -1);
    free(res);
}

TEST(Area_test, area_error_count2) {
    double a = 0;
    double b = 2;
    double *p = &a;
    double *k = &b;
    double *x_arr[5] = {p, p, k, p, p};
    double *y_arr[4] = {p, k, k, p};
    size_t x_size = sizeof(x_arr) / sizeof(double *);
    size_t y_size = sizeof(y_arr) / sizeof(double *);
    double *res = area(x_arr, x_size, y_arr, y_size);
    EXPECT_EQ(*res, -1);
    free(res);
}

TEST(Area_test, area_empty) {
    double *x_arr[0] = {};
    double *y_arr[0] = {};
    size_t x_size = sizeof(x_arr) / sizeof(double *);
    size_t y_size = sizeof(y_arr) / sizeof(double *);
    double *res = area(x_arr, x_size, y_arr, y_size);
    EXPECT_EQ(*res, 0);
//    free(res);
}
