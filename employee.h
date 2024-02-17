#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


using namespace std;




class Employee
{
public:
    bool E_stop = false;
    void Employee_MainMenu()
    {
        bool stop = false;
        while (!stop)
        {
            bool stop_1 = false;
            while (!stop_1)
            {
                system("cls");
                cout << "==================================" << endl;
                cout << "Employee Main Menu" << endl;
                cout << "==================================" << endl;
                cout << "1.LIST OF ITEM" << endl;
                cout << "2.SEARCH ITEM" << endl;
                cout << "3.BACK TO MAIN MENU" << endl;
                cout << "4.EXIT" << endl;

                int choise_2;
                cout << "\nEnter Your Choice :"; cin >> choise_2;

                if (choise_2 == 1)
                {
                    system("cls");
                    a1.list_for_customer();
                    cout << "\nDo You Want to Refresh (Y/N) :";


                }
                else if (choise_2 == 2)
                {
                    system("cls");
                    a1.Search_for_Customer();

                    cout << "\nDo You Want to Search Another Item (Y/N) : ";

                }

                else if (choise_2 == 3)
                {
                    system("cls");
                    first_window();
                    break;
                }
                else if (choise_2 == 4)
                {
                    system("cls");
                    cout << "BYE" << endl;
                    stop = true;
                    stop_1 = true;
                    E_stop = true;
                    a1.Loading();
                    break;
                }
                else
                {
                    system("cls");
                    cout << "INCORRECT CHOICE , PRESS ANY KEY FOR MAIN MANU...";
                    int getch();
                    break;
                }
                string choise_3;
                cin >> choise_3;

                if (choise_3 == "Y" || choise_3 == "y")
                    stop_1 = false;
                else if (choise_3 == "N" || choise_3 == "n")
                {
                    stop_1 = true;
                    break;
                }

                else
                {
                    cout << "\n\nInvalid Inpur ! Please try again " << endl;
                    a1.Loading();
                    stop_1 = true;
                    break;
                }

            }
        }

    }


    void List_of_Items()
    {
        a1.list_for_customer();
    }

    void Search_Item()
    {
        a1.Search_for_Customer();
    }

};
