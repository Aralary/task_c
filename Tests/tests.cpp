// Copyright 2022 Your Name <your_email>
#include <gtest/gtest.h>

extern "C" {
#include "area_lib/area_lib.h"
}
TEST(Area_test, area_good_count) {
    double a = 0;
    double b = 2;
//    double *p = &a;
//    double *k = &b;
    double *x_arr[4] = {&a, &a, &b, &b};
    double *y_arr[4] = {&a, &b, &b, &a};
    size_t x_size = sizeof(x_arr) / sizeof(double *);
    size_t y_size = sizeof(y_arr) / sizeof(double *);
    double *res = area(x_arr, x_size, y_arr, y_size);
    EXPECT_EQ(*res, 4);
//    free(res);

    double mas[] = {100, 150, 180, 200, 210, 220, 240, 250, 300};
    double *x_arr1[5] = {&mas[1], &mas[5], &mas[3], &mas[7], &mas[4]};
    double *y_arr1[5] = {&mas[3], &mas[2], &mas[8], &mas[6], &mas[0]};
    size_t x_size1 = sizeof(x_arr1) / sizeof(double *);
    size_t y_size1 = sizeof(y_arr1) / sizeof(double *);
    double *res1 = area(x_arr1, x_size1, y_arr1, y_size1);
    EXPECT_EQ(*res1, 6200);
    free(res1);
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
    free(res);
}
