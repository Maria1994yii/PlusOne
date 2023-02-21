// PlusOne.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int array_to_integer(int* arr, int size);
void ineteger_to_array(int* arr, int size, int num);

int main()
{
    int size;
    int* arr;
    int num;
    int n;

    std::cout << "size = ";
    std::cin >> size;

    arr = (int*)new int[size + 1];

    std::cout << "Insert element of array\n";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    
    num = array_to_integer(arr, size);

    ineteger_to_array(arr, size, num);

    if (arr[size - 1] != 9)
    {
        n = size;
    }
    else if (arr[size - 1] == 9)
    {
        n = size + 1;
        arr[size - 1] = 1;
        arr[size] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout<< arr[i]<<", ";
    }

    delete[]arr;
    arr = nullptr;
    return 0;
}

int array_to_integer(int* arr, int size)
{   
    int integer = 0;
    int pow_of_ten = 1;

    for (int i = 0; i < size; ++i)
    {
        arr[size - i - 1] *= pow_of_ten;
        integer += arr[size - i - 1];
        pow_of_ten *= 10;
    }

    return integer;
}

void ineteger_to_array(int* arr, int size, int num)
{
    if (num % 10 != 9)
    {
        num++;
    }
   
    for (int i = 0; i < size; ++i)
    {
        arr[size - i - 1] = num % 10;
        num /= 10;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
