#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>

struct IntArray {
    int* data;
    int size;
};

void checkMasVoi(void* ptr)
{
    if (ptr == nullptr)
    {
        std::cerr << "Разыменовывыем указатель(нулевой)\n" << std::endl;
        exit(-1);
        return;
    }
}

void create(IntArray& arr, const int size)
{
    if (size <= 0)
    {
        std::cerr << "Нельзя сделать массив с размером '" << size << "' т.к. он является отрицательным" << std::endl;
        return;
    }

    arr.data = new int[size];

    if (!arr.data)
    {
        std::cerr << "Нельзя сделать массив с размером " << size << std::endl;
        return;
    }

    arr.size = size;
}

void create(IntArray* arr, const int size)
{
    checkMasVoi(arr);
    create(*arr, size);
}

int get(IntArray& arr, const int index)
{
    if (index < 0 || index >= arr.size)
    {
        std::cerr << "Индекс за пределами массива. Размер массива: " << arr.size << "Полученный индекс: " << index << std::endl;
        exit(-1);
        return -1;
    }

    return arr.data[index];
}

int get(IntArray* arr, const int index)
{
    checkMasVoi(arr);
    return get(*arr, index);
}

void set(IntArray& arr, const int index, const int value)
{
    if (index < 0 || index >= arr.size)
    {
        std::cerr << "Индекс за пределами массива. Размер массива: " << arr.size << "Полученный индекс: " << index << std::endl;
        exit(-1);
        return;
    }

    arr.data[index] = value;
}

void set(IntArray* arr, const int index, const int value)
{
    checkMasVoi(arr);
    set(*arr, index, value);
}

void print(IntArray& arr)
{
    std::cout << '[';
    for (int i = 0; i < arr.size; i++)
    {
        std::cout << arr.data[i];

        if (i < arr.size - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << ']' << std::endl;
}

void print(IntArray* arr)
{
    checkMasVoi(arr);
    print(*arr);
}

void resize(IntArray& arr, const int newSize)
{
    if (newSize < 0)
    {
        return;
    }

    if (newSize == arr.size)
    {
        return;
    }

    if (newSize > arr.size)
    {
        int* newArr = new int[newSize];

        if (!newArr)
        {
            std::cerr << "Нельзя сделать массив с размером " << newSize << std::endl;
            return;
        }

        memcpy(newArr, arr.data, sizeof(int) * arr.size);

        for (int i = arr.size; i < newSize; ++i)
        {
            newArr[i] = 0;
        }

        delete[] arr.data;

        arr.data = newArr;
        arr.size = newSize;

        return;
    }

    int* newArr = new int[newSize];

    if (!newArr)
    {
        std::cerr << "Нельяз сделать массив с размером " << newSize << std::endl;
        return;
    }

    memcpy(newArr, arr.data, sizeof(int) * newSize);

    delete[] arr.data;
    arr.data = newArr;
    arr.size = newSize;
}

void resize(IntArray* arr, const int newSize)
{
    checkMasVoi(arr);
    resize(*arr, newSize);
}

void destroy(IntArray& arr)
{
    if (!arr.data)
    {
        return;
    }

    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
}

void destroy(IntArray* arr)
{
    checkMasVoi(arr);
    destroy(*arr);
}

int main()
{
    constexpr int size = 30;
    IntArray arr;

    create(arr, size);
    for (int i = 0; i < size; i++)
    {
        set(arr, i, i + 1);
    }

    print(arr);
    resize(arr, 50);
    print(arr);
    resize(arr, 10);
    print(arr);
    destroy(arr);
    return 0;
}