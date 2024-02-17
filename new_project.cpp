#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//#include "link_list.h"
#include "admin.h"
#include "custumer.h"
#include "employee.h"

using namespace std;

void first_window();

/*class stack
{
public:
    int top;
    int* data;
    int capacity;

    stack(int k)
    {
        capacity = k;
        data = new int[capacity];
        top = 0;
    }

    void push(int val)
    {
        if (top >= capacity)
        {
            cout << "STACK IS FULL" << endl;
        }
        else
        {
            data[top] = val;
            top++;
        }
    }

    void pop()
    {
        if (top == 0)
        {
            cout << "STACK IS EMPTY" << endl;
            return -1;
        }
        else
        {
            top--;
            return data[top];
        }
    }


}; */

Customer c1;
Employee e1;

int main()
{

    first_window();



}



void first_window()
{
    bool stop = false;
    while (!stop)
    {
        int x;






        cout << "\t---------------------------" << endl;
        cout << "\t\tMAIN MENU" << endl;
        cout << "\t---------------------------" << endl;
        cout << "1.admin" << endl;
        cout << "2.employee" << endl;
        cout << "3.customer" << endl;

        cout << "enter your choise : "; cin >> x;


        switch (x)
        {
        case 1:
            system("cls");
            a1.Admin_MainMenu();
            break;
        case 2:
            system("cls");
            e1.Employee_MainMenu();
            break;
        case 3:
            system("cls");
            c1.Customer_MainMenu();
            break;
        default:
            system("cls");
            cout << "Invalid Input! Please Try again" << endl;
            a1.Loading();
            system("cls");
        }
        if (a1.A_stop == true || e1.E_stop == true || c1.C_stop == true)
            break;



    }



}


 