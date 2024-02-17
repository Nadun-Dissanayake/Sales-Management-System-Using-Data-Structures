#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

void first_window();

class Node
{
public:
    string name;
    string feedback;
    double buyin_price;
    double selling_price;
    int Quantity;
    int profit;
    Node* next;
};

class Node_Sort
{
public:
    string name_for_sorting;
    int profit_for_sorting;
    Node_Sort* nexr_for_sorting;
};

class  Admin
{
private:


public:
    bool A_stop = false;
    Node* head;
    Node* tail;
    int size;
    Node_Sort* head_sort;
    Node_Sort* tail_sort;
    Admin()
    {
        head = NULL;
        tail = NULL;
        head_sort = NULL;
        tail_sort = NULL;
        size = 0;
    }

    void Admin_MainMenu()
    {
        bool stop = false;
        while (!stop)
        {
            system("cls");

            cout << "\t---------------------------" << endl;
            cout << "\t\tMAIN WINDOW" << endl;
            cout << "\t---------------------------" << endl;
            cout << "\n1.ADD NEW ITEM" << endl;
            cout << "2.LIST OF ITEM" << endl;
            cout << "3.SEARCH ITEM" << endl;
            cout << "4.DELETE ITEM" << endl;
            cout << "5.UPDATE ITEM" << endl;
            cout << "6.SEE ANALYSIS" << endl;
            cout << "7.SEE CUSTOMER FEEDBACK" << endl;
            cout << "8.BACK TO THE MAIN MENU" << endl;
            cout << "9.EXIT" << endl;

            int choise_2;
            cout << "\nEnter Your Choice :"; cin >> choise_2;

            bool stop_1 = false;
            while (!stop_1)
            {
                if (choise_2 == 1)
                {
                    system("cls");
                    Add_Item();
                    cout << "\nDo You Want to Add Another Item(Y/N) : ";


                }
                else if (choise_2 == 2)
                {
                    system("cls");
                    List_of_Items();
                    cout << "\nDo You Want to Refresh(Y/N) : ";

                }
                else if (choise_2 == 3)
                {
                    system("cls");
                    fflush(stdin);
                    Search_Item();

                    cout << "\nDo You Want to Search Another Item(Y/N) : ";
                }

                else if (choise_2 == 4)
                {
                    system("cls");
                    Delete_Item();

                    cout << "\nDo You Want to Delete Another Item(Y/N) : ";
                }

                else if (choise_2 == 5)
                {
                    system("cls");
                    Update_Item();

                    cout << "\nDo You Want to Update Another Item(Y/N) : ";
                }

                else if (choise_2 == 6)
                {
                    system("cls");
                    Analytics();

                    cout << "\nDo You Want to Back(Y/N) : ";
                }

                else if (choise_2 == 7)
                {
                    system("cls");
                    //c1.see_feedback();
                    break;
                }

                else if (choise_2 == 8)
                {
                    system("cls");
                    first_window();
                    break;
                }

                else if (choise_2 == 9)
                {
                    system("cls");
                    cout << "BYE" << endl;
                    Loading();
                    stop = true;
                    stop_1 = true;
                    A_stop = true;
                    break;

                }

                else
                {
                    system("cls");
                    cout << "INCORRECT CHOICE , PRESS ANY KEY FOR MAIN MANU...";
                    int getch();
                    Admin_MainMenu();
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
                    Loading();
                    stop_1 = true;
                    break;
                }
            }



        }
    }
    void Add_Item()
    {
        system("cls");
        cout << "How many Items do you want to Add : ";
        int Number_Of_Adding_Item;
        cin >> Number_Of_Adding_Item;
        for (int i = 1; i <= Number_Of_Adding_Item; i++)
        {
            //system("cls");
            //cout << "\t\tADMIN" << endl;
            Node* temp = new Node();

            cin.ignore();
            cout << "PRODUCT NAME : ";
            getline(cin, temp->name);
            cout << "PRODUCT BUYING PRICE :";
            cin >> temp->buyin_price;
            cout << "PRODUCT SELLING PRICE :";
            cin >> temp->selling_price;
            cout << "QUENTITY OF PRODUCT :";
            cin >> temp->Quantity;

            if (head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
            size++;

            cout << endl;
        }

        cout << "NEW RECORD INSERTED..." << endl;
        system("cls");
        List_of_Items();
    }
    void List_of_Items()
    {
        Node* current = head;
        int count = 1;


        cout << "==================================================================================================================" << endl;
        cout << setw(0) << "No" << setw(20) << "Name of the Item" << setw(20) << "Buying Price" << setw(20) << "Selling Price" << setw(20) << "Quentity" << endl;
        while (current != NULL) {

            cout << setw(0) << count;
            cout << setw(20) << current->name;
            cout << setw(20) << current->buyin_price;
            cout << setw(20) << current->selling_price;
            cout << setw(20) << current->Quantity << endl;

            current = current->next;
            count++;
        }
        cout << "==================================================================================================================" << endl;
        cout << endl;
    }
    void List_of_Item_Name()
    {
        Node* current = head;
        int count = 1;


        cout << "==================================================================================================================" << endl;
        cout << setw(0) << "No" << setw(20) << "Name of the Item" << endl;
        while (current != NULL) {

            cout << setw(0) << count;
            cout << setw(20) << current->name << endl;


            current = current->next;
            count++;
        }
        cout << "==================================================================================================================" << endl;
        cout << endl;
    }
    void Search_Item()
    {
        List_of_Item_Name();
        Node* current = head;
        string search_name;
        bool Is_Exist = true;
        cin.ignore();
        cout << "Enter the name of product : ";
        getline(cin, search_name);
        for (int i = 0; i < size; i++)
        {
            if (current->name == search_name)
            {
                Is_Exist = false;
                cout << "==================================================================================================================" << endl;
                cout << setw(20) << "Name of the Item" << setw(20) << "Buying Price" << setw(20) << "Selling Price" << setw(20) << "Quentity" << endl;

                cout << setw(20) << current->name;
                cout << setw(20) << current->buyin_price;
                cout << setw(20) << current->selling_price;
                cout << setw(20) << current->Quantity << endl;
                cout << "==================================================================================================================" << endl;
            }


            current = current->next;
        }
        if (Is_Exist == true)
            cout << "There is no any record for your search" << endl;
    }
    void Delete_Item()
    {
        List_of_Item_Name();
        string Input_delete;
        cin.ignore();
        cout << "Enter the name of product : ";
        getline(cin, Input_delete);
        bool Is_Exist = false;
        Node* current = head;
        if (head == NULL)
            cout << "The stock is empty" << endl;
        else if (current->name == Input_delete)
        {

            Node* temp = head;
            if (size == 1)
            {
                delete temp;
                head = NULL;
                tail = NULL;
                cout << "Successfully Delete the record" << endl;
                Is_Exist = true;
            }
            else
            {
                head = head->next;
                delete temp;
                cout << "Successfully Delete the record" << endl;
                Is_Exist = true;
            }
            size--;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (current->next->name == Input_delete)
                {
                    Node* temp = current->next;
                    current->next = temp->next;
                    delete temp;
                    size--;
                    cout << "Successfully Delete the record" << endl;
                    Is_Exist = true;
                    break;
                }
                current = current->next;
            }
        }
        if (Is_Exist == false)
            cout << "There is no such record to delete" << endl;



    }
    void Update_Item()
    {
        bool stop = false;
        while (!stop)
        {
            system("cls");
            List_of_Items();
            string Update_Item;
            //cin.ignore();
            cout << "Item name : ";
            getline(cin, Update_Item);

            Node* current = head;
            while (current != NULL)
            {
                system("cls");
                if (current->name == Update_Item)
                {
                    cout << "\t---------------------------" << endl;
                    cout << "\t\tUPDATE MENU" << endl;
                    cout << "\t---------------------------" << endl;
                    cout << "\n1.UPDATE FULL ITEM" << endl;
                    cout << "2.UPDATE NAME" << endl;
                    cout << "3.UPDATE BUYING PRICE" << endl;
                    cout << "4.UPDATE SELLING PRICE" << endl;
                    cout << "5.UPDATE QUENTITY" << endl;

                    int choise_2;
                    cout << "\nEnter Your Choice :"; cin >> choise_2;

                    if (choise_2 == 1)
                    {
                        cout << "Update the Name : "; cin >> current->name;
                        cout << "Update the Buying price : "; cin >> current->buyin_price;
                        cout << "Update the Selling price : "; cin >> current->selling_price;
                        cout << "Update the Quentity : "; cin >> current->Quantity;

                        cout << "Successfully Updated The Item " << endl;
                    }
                    else if (choise_2 == 2)
                    {
                        cout << "Update the Name : "; cin >> current->name;
                        cout << "Successfully Updated The Item Name" << endl;
                    }
                    else if (choise_2 == 3)
                    {
                        cout << "Update the Buying Price : "; cin >> current->buyin_price;
                        cout << "Successfully Updated The Item Buying Price" << endl;
                    }
                    else if (choise_2 == 4)
                    {
                        cout << "Update the Selling Price : "; cin >> current->selling_price;
                        cout << "Successfully Updated The Item Selling Price" << endl;
                    }
                    else if (choise_2 == 5)
                    {
                        cout << "Update the Quentity : "; cin >> current->Quantity;
                        cout << "Successfully Updated The Item Quentity" << endl;
                    }
                    else
                    {
                        cout << "Invalid Input Please Try Again !!!" << endl;
                        Loading();
                        break;
                    }
                    cout << "Do You Want to Go Back (Y/N)" << endl;
                    string choise_3;
                    cin >> choise_3;

                    if (choise_3 == "Y" || choise_3 == "y")
                        stop = false;
                    else if (choise_3 == "N" || choise_3 == "n")
                    {
                        stop = true;
                        break;
                    }

                    else
                    {
                        cout << "\n\nInvalid Inpur ! Please try again " << endl;
                        Loading();
                        stop = true;
                        break;
                    }
                }
                current = current->next;
            }


        }



    }

    void sort_linked_list(Node* k)
    {
        Node* i, * j;
        i = k;
        for (i = k; i->next != NULL; i = i->next)
        {
            /*for (j = i->next; j != NULL; j = j->next)
            {
                if (i->profit > j->profit)
                {
                    int temp = i->profit;
                    string temp_1 = i->name;
                    i->profit = j->profit;
                    i->name = j->name;
                    j->profit = temp;
                    j->name = temp_1;
                }
            }*/
        }

        /*Node* current = k;
        while (current != NULL)
        {
            cout << "TOTAL PROFIT OF " << current->name << ": " << current->profit<< endl;
            current = current->next;
        }*/
    }

    void Analytics()
    {
        system("cls");

        cout << "\t---------------------------" << endl;
        cout << "\tANALYTIC WINDOW" << endl;
        cout << "\t---------------------------" << endl;
        cout << "\n1.TOTAL PROFIT OF THE STORE" << endl;
        cout << "2.TOTAL PROFIT OF EACH ITEM" << endl;
        cout << "3.TOTAL ITEM" << endl;
        cout << "4.TOTAL COST FOR THE STORE" << endl;

        int choise_2;
        cout << "\nEnter Your Choice :"; cin >> choise_2;

        Node* current = head;
        Node_Sort* temp_sort = new Node_Sort;

        int Total_Buying_Price = 0;
        int Total_Selling_Price = 0;


        if (choise_2 == 1)
        {
            while (current != NULL)
            {
                Total_Buying_Price = Total_Buying_Price + current->buyin_price * current->Quantity;
                Total_Selling_Price = Total_Selling_Price + current->selling_price * current->Quantity;
                current = current->next;
            }
            cout << "TOTAL PROFIT OF THE STORE : " << Total_Selling_Price - Total_Buying_Price;
        }

        else if (choise_2 == 2)
        {
            while (current != NULL)
            {
                int Total_Buying_Price_Item = 0;
                int Total_Selling_Price_Item = 0;
                Total_Buying_Price_Item = Total_Buying_Price_Item + current->buyin_price * current->Quantity;
                Total_Selling_Price_Item = Total_Selling_Price_Item + current->selling_price * current->Quantity;
                current->profit = Total_Selling_Price_Item - Total_Buying_Price_Item;
                cout << "TOTAL PROFIT OF " << current->name << ": " << current->profit << endl;
                current = current->next;
            }

            /*string choise;
            cout << "Do you want to sort (Y/N) :";
            cin >> choise;

            if (choise == "N" || choise == "n")
            {

            }
            else if (choise == "Y" || choise == "y")
            {
                sort_linked_list(current);
            }
            else
            {

                cout << "Invalid Input !!! please try again" << endl;
            }*/

            //Node_Sort* current_sort = head_sort;


        }

        else if (choise_2 == 3)
        {
            int Total_Item = 0;
            while (current != NULL)
            {
                Total_Item = Total_Item + current->Quantity;
                current = current->next;
            }

            cout << "TOTAL ITEMS IN THE STORE : " << Total_Item;
        }

        else if (choise_2 == 4)
        {
            int Total_Cost = 0;
            while (current != NULL)
            {
                Total_Cost = Total_Cost + current->buyin_price * current->Quantity;
                current = current->next;
            }

            cout << "TOTAL COST FOR THE STORE : " << Total_Cost;
        }

    }
    void List_of_Item_Employee()
    {
        Node* current = head;
        int count = 1;


        cout << "==================================================================================================================" << endl;
        cout << setw(0) << "No" << setw(20) << "Name of the Item" << setw(20) << "Price" << setw(20) << "Quentity" << endl;
        while (current != NULL) {

            cout << setw(0) << count;
            cout << setw(20) << current->name;
            cout << setw(20) << current->selling_price;
            cout << setw(20) << current->Quantity << endl;

            current = current->next;
            count++;
        }
        cout << "==================================================================================================================" << endl;
        cout << endl;
    }
    void list_for_customer()
    {
        Node* current = head;
        int count = 1;


        cout << "==================================================================================================================" << endl;
        cout << setw(0) << "No" << setw(20) << "Name of the Item" << setw(20) << "Price" << setw(20) << "Quentity" << endl;
        while (current != NULL) {

            cout << setw(0) << count;
            cout << setw(20) << current->name;
            //cout << setw(20) << current->buyin_price;
            cout << setw(20) << current->selling_price;
            cout << setw(20) << current->Quantity << endl;

            current = current->next;
            count++;
        }
        cout << "==================================================================================================================" << endl;
        cout << endl;
    }
    void Search_for_Customer()
    {
        List_of_Item_Name();
        Node* current = head;
        string search_name;
        bool Is_Exist = true;
        cin.ignore();
        cout << "Enter the name of product : ";
        getline(cin, search_name);
        for (int i = 0; i < size; i++)
        {
            if (current->name == search_name)
            {
                Is_Exist = false;
                cout << "==================================================================================================================" << endl;
                cout << setw(20) << "Name of the Item" << setw(20) << "Price" << setw(20) << "Quentity" << endl;

                cout << setw(20) << current->name;
                cout << setw(20) << current->selling_price;
                cout << setw(20) << current->Quantity << endl;
                cout << "==================================================================================================================" << endl;
            }
            current = current->next;
        }
        if (Is_Exist == true)
            cout << "There is no any record for your search" << endl;
    }
    void Purchase_Item()
    {
        Node* current = head;
        bool Is_Exist = true;
        string purchase_item;
        List_of_Item_Employee();
        cout << "What do you want to buy : " << endl;
        cin.ignore();
        getline(cin, purchase_item);

        for (int i = 0; i < size; i++)
        {
            if (current->name == purchase_item)
            {
                Is_Exist = false;
                int Purchasing_Quentity;
                cout << "How many Quentity do you want : ";
                cin >> Purchasing_Quentity;

                current->Quantity = (current->Quantity) - Purchasing_Quentity;
            }


            current = current->next;
        }
        if (Is_Exist == true)
            cout << "There is no any record for your search" << endl;

    }
    void Loading()
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 100000000; j++)
            {

            }
            cout << "* ";
        }
    }
};

Admin a1;

