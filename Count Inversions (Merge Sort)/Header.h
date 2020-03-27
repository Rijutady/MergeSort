#pragma once

struct test
{
    static const int array_size = 0 ; // To fix, init array_size here.
    int size_array[array_size];  // C2131
};

array_size