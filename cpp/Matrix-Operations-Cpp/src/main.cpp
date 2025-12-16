#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

// Function Declaration
void input(int **Matrix, int &row, int &column);
void display(int **Matrix, int row, int column, bool isResult);
void sum();
void Mul();
void Transpose();
void MenuUI();
void MatrixOperation();
void MemoryAllocation(int **&Matrix, int row, int column);
void freeDynamicMemory(int **&Matrix, int &row);
bool hasInputError(const string &errorMsg = "Invalid Input❌! Please enter integer only😑");


void input(int **Matrix, int &row, int &column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            while (true)
            {
                cout << "Matrix[" << i << "][" << j << "] -: ";
                cin >> Matrix[i][j];

                if (!cin.fail())
                    break;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input!❌, Enter only Integer🤗" << endl;
            }
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void display(int **Matrix, int row, int column, bool isResult)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (isResult)
                cout << BLUE << Matrix[i][j] << RESET << " ";
            else
                cout << GREEN << Matrix[i][j] << RESET << " ";
        }
        cout << endl;
    }
}
void sum()
{
    cout << GREEN << string(160, '=') << RESET << endl;
    cout << string(65, ' ') << MAGENTA << "ADDITION" << RESET << string(65, ' ') << endl;
    cout << "\033[1;32m" << string(160, '=') << "\033[0m\n"
         << endl;

    int row1, column1, row2, column2;
    while (true)
    {
        cout << RED << "Press -999(row or column) to exit Addition Operation" << RESET << endl;

        cout << "Enter the number of row and column for matrix 1 : ";
        cin >> row1 >> column1;
        if (hasInputError())
            continue;
        if (row1 == -999 || column1 == -999)
        {
            cout << YELLOW << "Exiting Addition Operation...." << RESET << endl;
            return;
        }

        cout << "Enter the number of row and column for matrix 2 : ";
        cin >> row2 >> column2;
        if (hasInputError())
            continue;
        if (row2 == -999 || column2 == -999)
        {
            cout << YELLOW << "Exiting Addition Operation...." << RESET << endl;
            return;
        }
        if (row1 < 1 || column1 < 1 || row2 < 1 || column2 < 1)
        {
            cout << CYAN << "\nInvalid Size!, Row and Column Must Be Positive." << RESET << endl;
            continue;
        }
        if (row1 != row2 || column1 != column2)
        {
            cout << MAGENTA << "Matrix Addition is Not Posible❌!, Dimensions Must be match.🤯🤔" << RESET << endl;
            continue;
        }

        int **Matrix_1 = nullptr;
        int **Matrix_2 = nullptr;
        int **Matrix_3 = nullptr;

        MemoryAllocation(Matrix_1, row1, column1);
        MemoryAllocation(Matrix_2, row2, column2);
        MemoryAllocation(Matrix_3, row1, column1);

        cout << YELLOW << "Enter the Element of Matrix 1 (" << row1 << "x" << column1 << "=" << row1 * column1 << ")" << RESET << endl;
        input(Matrix_1, row1, column1);
        cout << YELLOW << "Enter the Element of Matrix 2(" << row1 << "x" << column1 << "=" << row1 * column1 << ")" << RESET << endl;
        input(Matrix_2, row2, column2);

        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < column1; j++)
            {
                Matrix_3[i][j] = Matrix_1[i][j] + Matrix_2[i][j];
            }
        }
        cout << RED << string(160, '-') << RESET << endl;
        cout << YELLOW << "\nMatrix 1 Form" << RESET << endl;
        display(Matrix_1, row1, column1, false);
        cout << YELLOW << "\nMatrix 2 Form" << RESET << endl;
        display(Matrix_2, row2, column2, false);
        cout << YELLOW << "\nResultant Matrix (Sum)" << RESET << endl;
        display(Matrix_3, row1, column1, true);
        cout << RED << string(160, '-') << RESET << endl;

        freeDynamicMemory(Matrix_1, row1);
        freeDynamicMemory(Matrix_2, row2);
        freeDynamicMemory(Matrix_3, row1);
    }
}
void Mul()
{
    cout << GREEN << string(160, '=') << RESET << endl;
    cout << string(65, ' ') << MAGENTA << "MULTIPLICATION" << RESET << string(65, ' ') << endl;
    cout << "\033[1;32m" << string(160, '=') << "\033[0m\n"
         << endl;
    int row1, column1, row2, column2;

    while (true)
    {
        cout << RED << "Press -999(row or column) to exit Addition Operation" << RESET << endl;
        cout << "Enter the number of row and column for matrix 1 : ";
        cin >> row1 >> column1;
        if (hasInputError())
            continue;
        if (row1 == -999 || column1 == -999)
        {
            cout << YELLOW << "Exiting Maultiplication Operation...." << RESET << endl;
            return;
        }
        cout << "Enter the number of row and column for matrix 2 : ";
        cin >> row2 >> column2;
        if (hasInputError())
            continue;
        if (row2 == -999 || column2 == -999)
        {
            cout << YELLOW << "Exiting Maultiplication Operation...." << RESET << endl;
            return;
        }
        if (row1 < 1 || row2 < 1 || column1 < 1 || column2 < 1)
        {
            cout << YELLOW << "Invalid Size❌!, Row and Column must be Positive. " << RESET << endl;
            continue;
        }
        if (column1 != row2)
        {
            cout << MAGENTA << "Matrix Can't be Multiplied❌!, Column1 and Row2 must be Same.🤯🤔" << RESET << endl;
            continue;
        }
        int **Matrix_1 = nullptr;
        int **Matrix_2 = nullptr;
        int **Matrix_3 = nullptr;

        MemoryAllocation(Matrix_1, row1, column1);
        MemoryAllocation(Matrix_2, row2, column2);
        MemoryAllocation(Matrix_3, row1, column2);
        cout << YELLOW << "Enter the Element of Matrix 1 (" << row1 << "x" << column1 << "=" << row1 * column1 << ")" << RESET << endl;
        input(Matrix_1, row1, column1);
        cout << YELLOW << "Enter the Element of Matrix 1 (" << row2 << "x" << column2 << "=" << row2 * column2 << ")" << RESET << endl;
        input(Matrix_2, row2, column2);

        cout << RED << string(160, '-') << RESET << endl;
        cout << YELLOW << "\nMatrix_1 Form" << RESET << endl;
        display(Matrix_1, row1, column1, false);
        cout << YELLOW << "\nMatrix_2 Form" << RESET << endl;
        display(Matrix_2, row2, column2, false);

        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < column2; j++)
            {
                Matrix_3[i][j] = 0;
                for (int k = 0; k < row2; k++)
                {
                    Matrix_3[i][j] += Matrix_1[i][k] * Matrix_2[k][j];
                }
            }
        }

        cout << YELLOW "\nResultant Matrix" << RESET << endl;
        display(Matrix_3, row1, column2, true);
        cout << RED << string(160, '-') << RESET << endl;

        freeDynamicMemory(Matrix_1, row1);
        freeDynamicMemory(Matrix_2, row2);
        freeDynamicMemory(Matrix_3, row1);
    }
}
void Transpose()
{
    cout << GREEN << string(160, '=') << RESET << endl;
    cout << string(65, ' ') << MAGENTA << "TRANSPOSE" << RESET << string(65, ' ') << endl;
    cout << "\033[1;32m" << string(160, '=') << "\033[0m\n"
         << endl;
    while (true)
    {
        cout << RED << "Press -999(row or column) to exit Transpose Operation" << RESET << endl;

        int row, column;
        cout << "Enter the number of row and column for Matrix : ";
        cin >> row >> column;
        if (hasInputError())
            continue;

        if (row == -999 || column == -999)
        {
            cout << YELLOW << "Exiting Transpose Operation...." << RESET << endl;
            return;
        }

        if (row < 1 || column < 1)
        {
            cout << CYAN << "\nInvalid Size!, Row and Column Must Be Positive." << RESET << endl;
            continue;
        }

        int **Matrix = nullptr;
        MemoryAllocation(Matrix, row, column);
        int **Transpose_Matrix = nullptr;
        MemoryAllocation(Transpose_Matrix, column, row);

        cout << YELLOW << "Enter the Element of Matrix (" << row << "x" << column << "=" << row * column << ")" << RESET << endl;
        input(Matrix, row, column);

        cout << RED << string(160, '-') << RESET << endl;
        cout << YELLOW << "\nMatrix Form" << RESET << endl;
        display(Matrix, row, column, true);

        for (int i = 0; i < column; i++)
        {
            for (int j = 0; j < row; j++)
            {
                Transpose_Matrix[i][j] = Matrix[j][i];
            }
        }

        cout << YELLOW << "\nTranspose Matrix" << RESET << endl;
        display(Transpose_Matrix, column, row, false);
        cout << RED << string(160, '-') << RESET << endl;

        freeDynamicMemory(Matrix, row);
        freeDynamicMemory(Transpose_Matrix, column);
    }
}
void MenuUI()
{
    cout << CYAN << "1. Addition of Two Matrix." << endl;
    cout << "2. Multiplication of Two Matrix." << endl;
    cout << "3. Transpose of Matrix." << endl;
    cout << "4. Exit." << RESET << endl;
}

void MatrixOperation()
{
    system("clear");
    cout << string(160, '.') << endl;
    cout << CYAN << "Loading Program...\n"
         << RESET;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000)); // 3 seconds

    cout << GREEN << string(160, '=') << RESET << "\n"
         << endl;
    cout << string(65, ' ') << MAGENTA << "Welcome To Matrix" << RESET << string(65, ' ') << endl;
    cout << "\n\033[1;32m" << string(160, '=') << "\033[0m\n"
         << endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    int choice;
    while (true)
    {
        MenuUI();
        cout << "Enter your choice : ";
        cin >> choice;
        if (hasInputError())
            continue;
        switch (choice)
        {
        case 1:
            sum();
            break;
        case 2:
            Mul();
            break;
        case 3:
            Transpose();
            break;
        case 4:
        {
            cout << GREEN << "PROGRAM FINISHED SUCCESSFULLY✅🙏😉" << RESET << endl;
            return;
        }
        default:
            cout << RED << "Invalid choice!❌" << RESET << endl;
            break;
        }
    }
}
void freeDynamicMemory(int **&Matrix, int &row)
{
    for (int i = 0; i < row; i++)
    {
        delete[] Matrix[i];
        Matrix[i] = nullptr;
    }
    delete[] Matrix;
    Matrix = nullptr;
}
void MemoryAllocation(int **&Matrix, int row, int column)
{
    Matrix = new int *[row];
    for (int i = 0; i < row; i++)
    {
        Matrix[i] = new int[column];
    }
}
bool hasInputError(const string &errorMsg)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << errorMsg << RESET << endl;
        return true;
    }
    return false;
}
int main()
{
    MatrixOperation();
    return 0;
}
