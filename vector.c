// MIT License

// Copyright (c) 2023 Ariyudo Pertama

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
  

#include <stdio.h>
#include <stdlib.h>

#pragma region vector

#ifndef _CVECTOR
#define _CVECTOR 1

#define declare_vector(Name, Tp) \
    typedef struct Name \
    { \
        int capacity; \
        int size; \
        Tp *data; \
    } Name; \
    \
    void Name##_initialize(Name *self) \
    { \
        self->capacity = 1; \
        self->size = 0; \
        self->data = (Tp *)malloc(self->capacity * sizeof(Tp)); \
    } \
    \
    void Name##_resize(Name *self, Tp size) \
    { \
        self->capacity = 1; \
        while (self->capacity <= size) \
            self->capacity *= 2; \
        \
        self->size = size; \
        self->data = (Tp *)realloc(self->data, self->capacity * sizeof(Tp)); \
    } \
    \
    void Name##_push_back(Name *self, Tp item) \
    { \
        if (self->capacity == self->size) \
        { \
            self->capacity *= 2; \
            self->data = (Tp *)realloc(self->data, self->capacity * sizeof(Tp)); \
        } \
        \
        self->data[self->size++] = item; \
    } \
    \
    void Name##_pop_back(Name *self) \
    { \
        if (self->capacity / 4 == --self->size) \
        { \
            self->capacity /= 2; \
            self->data = (Tp *)realloc(self->data, self->capacity * sizeof(Tp)); \
        } \
    } \
    \
    void Name##_scan(Name *self) \
    { \
        for (int i = 0; i < self->size; i++) \
            scanf("%d", self->data + i); \
    } \
    \
    void Name##_print(Name *self) \
    { \
        for (int i = 0; i < self->size; i++) \
            printf("%d ", self->data[i]); \
        printf("\n"); \
    }

#endif /* _CVECTOR */

#pragma endregion /* vector */
