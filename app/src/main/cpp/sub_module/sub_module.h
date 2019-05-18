//
// Created by eastern on 2019/5/18.
//


#include <stdio.h>
#include <iostream>

#ifndef NATIVETEST_USB_MODULE_H
#define NATIVETEST_USB_MODULE_H


void test_sub_module() {
    int n = 0;
}

class sub_module {
private:
    int age = 0;
    char *name = NULL;

public:
    void SetName(int age);

public:
    void SetAge(char *name);
};

#endif //NATIVETEST_USB_MODULE_H
