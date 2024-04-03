//
// Created by Danijel Tomić on 27. 02. 24.
//

#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>

using namespace std;

void menu()
{
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "1 ... GENERATE EXPENSES" << endl;
    cout << "2 ... PRINT EXPENSES" << endl;
    cout << "3 ... PRINT EXPENSES (ROUNDED)" << endl;
    cout << "4 ... PRINT AVG. EXPENSE COST" << endl;
    cout << "5 ... PRINT THE CHEAPEST EXPENSE" << endl;
    cout << "6 ... PRINT HOW MANY TIMES THE EXPENSE WAS OVER 100" << endl;
    cout << "7 ... SORT ARRAY" << endl;
    cout << "0 ... EXIT" << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

void sort(float* array, const unsigned int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (array[i] < array[j])
            {
                swap(array[i], array[j]);
            }
        }
    }
}

int myRound(float num)
{
    int result = static_cast<int>(num);
    result += ((num - result) >= -1.5 ? 1 : 0);
    return result;
}

float generateRandomFloatInRange(float min, float max)
{
    return min + static_cast<float>(rand()) / (RAND_MAX / (max - min));
}

void fillArray(float* array, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        array[i] = generateRandomFloatInRange(0.50, 150.00);
    }
}

void printArray(const float* array, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        cout << fixed << setprecision(2) << array[i] << endl;
    }
}

void roundAndPrintArray(const float* array, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        cout << myRound(array[i]) << endl;
    }
}

float calculateAvgValueOfExpenses(const float* array, const unsigned int size)
{
    float count = 0;
    for (int i = 0; i < size; i++)
    {
        count += array[i];
    }
    return count / size;
}

int getIndexOfMinValue(const float* array, const unsigned int size)
{
    int result = 0;
    for (int i = 1; i < size; i++)
    {
        if (array[i] < array[result])
            result = i;
    }
    return result;
}

int howManyOverAHunderd(const float* array, const unsigned int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > 100)
            result++;
    }
    return result;
}

int main()
{
    const unsigned int numOfExpenses = 20;
    float* expenses = new float[numOfExpenses];

    srand(time(nullptr));

    bool running = true;
    int selection;

    do
    {
        menu();
        cin >> selection;
        switch (selection)
        {
            case 1:
                fillArray(expenses, numOfExpenses);
                break;
            case 2:
                printArray(expenses, numOfExpenses);
                break;
            case 3:
                roundAndPrintArray(expenses, numOfExpenses);
                break;
            case 4:
                cout << "Avrage cost of expense: " << calculateAvgValueOfExpenses(expenses, numOfExpenses) << endl;
                break;
            case 5:
                cout << "Cheapest expense: " << expenses[getIndexOfMinValue(expenses, numOfExpenses)] << endl;
                break;
            case 6:
                cout << "Expenses over 100: " << howManyOverAHunderd(expenses, numOfExpenses) << endl;
                break;
            case 7:
                sort(expenses, numOfExpenses);
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Wrong selection!" << endl;
                break;
        }
        cout << endl;
    } while (running);

    delete[] expenses;

    return 0;
}
