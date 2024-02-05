#include <iostream>
#include <iomanip>
#include <string>


using namespace std;
// Global Variables
int no_of_property;
// structures
struct property
{
    string street;
    int plotno;
    char type;
    char status;
    int price;
};
property a[50]; // string structure
struct owner
{
    string ownername;
    int id;
    int plotenum;
};
owner z[5];
int totalowner;
void addowner()
{

    cout << "How Many Number of Owners You Want to Add(Limit is 5)" << endl;
    cin >> totalowner;
    for (int i = 0; i < totalowner; i++)
    {
        cout << "Enter name of owner" << endl;
        cin >> z[i].ownername;
        cout << "Enter Id of owner" << endl;
        cin >> z[i].id;
    }
}
void ownerassign()
{
    int plote;
    int owner2;
    int j;
    cout << "Enter Plot Number You Want To Assign:" << endl;
    cin >> plote;
    cout << "Enter owner id " << endl;
    cin >> owner2;
    for (j = 0; j < totalowner; j++)
    {
        if (owner2 == z[j].id)
        {
            break;
        }
        else
        {
            cout << "Owner not found" << endl;
        }
    }

    for (int i = 0; i < no_of_property; i++)
    {
        if (plote == a[i].plotno)
            cout << "Plot no" << a[i].plotno << "Assigned to owner" << z[j].ownername << endl;
        z[j].plotenum++;
    }
}
void ownerinfo()
{
    cout << "Information of all owners and number of properties they owned" << endl;
    for (int i = 0; i < totalowner; i++)
    {
        cout << "ID:" << z[i].id << endl;
        cout << "Name:" << z[i].ownername << endl;
        cout << "Number of plotes assigned to owner:" << z[i].plotenum << endl;
    }
}

// functions
// Manage function prototype+defination , void means it will return noting,empty braces means no parameter is passed:
void datamanage()
{
    int value1 = 1; // var for controll loop of function
    cout << "Select Option: \n 1]Add Property \n 2]Update Property Data \n 3]Delete Property \n 4]Display Data \n 5]Exit \n";
    int value11; // var for user input about above options
    cin >> value11;
    while (value1 == 1)
    {
        if (value11 == 1)
        {
            // add property
            cout << "How Many Number of Properties You Want to Add(Limit is 50)" << endl;
            cin >> no_of_property;
            for (int i = 0; i < no_of_property; i++)
            {
                cout << "Enter Data Of Plot" << i << endl;
                cout << "Enter Street Number of Plot" << endl;
                cin >> a[i].street;
                cout << "Enter Plot Number" << endl;
                cin >> a[i].plotno;
                cout << "Enter Type of Plot(a)Commercial / b)Ressident)" << endl;
                cin >> a[i].type;
                cout << "Enter Status of Plot(s)Sold /n)Not Sold)" << endl;
                cin >> a[i].status;
                cout << "Enter Price" << endl;
                cin >> a[i].price;
            }
            break;
        }
        else if (value11 == 2)
        { // update property
            int pltno;
            cout << "Enter Plot Number You Want to Update:" << endl;
            cin >> pltno;
            for (int i = 0; i < no_of_property; i++)
            {
                if (pltno == a[i].plotno)
                {
                    cout << "Which Field You Want to Update" << endl;
                    cout << "1)Street Update \t  2)Update Type(a)commercial(b)Ressident \t 3)Status Update(s or n)) \t 4)Update Price \n"
                         << endl;
                    int value21;
                    cin >> value21;
                    switch (value21)
                    {
                    case 1:
                    {
                        cout << "Street Update" << endl;
                        cin >> a[i].street;
                        break;
                    }
                    case 2:
                    {
                        cout << "Update Type:(a)Commercial / b)Ressident)" << endl;
                        cin >> a[i].type;
                        break;
                    }
                    case 3:
                    {
                        cout << "Status Update(s or n))" << endl;
                        cin >> a[i].status;
                        break;
                    }
                    case 4:
                    {
                        cout << "update price" << endl;
                        cin >> a[i].price;
                        break;
                    }

                    default:
                    {
                        cout << "your choice is invalid";
                        break;
                    }
                    }
                }
            }
            break;
        }
        else if (value11 == 3)
        {
            int i; // index you want to delete
            int pltno;
            cout << "Enter Plot Number You Want to delete:" << endl;
            cin >> pltno;
            for (int j = 0; j < no_of_property; j++)
            {
                if (pltno == a[j].plotno)
                {
                    i = j;
                }
            }

            if (i != no_of_property)
            {
                int d = 0;
                for (int b = i; b <= no_of_property - 1; b++)
                {
                    a[b] = a[b + 1];
                    d = 1;
                }
                if (d == 1)
                {
                    --no_of_property;
                }
            }
            break;
        }
        else if (value11 == 4)
        { // Display Data
            cout << "Data Of All Property Till Last Update" << endl;
            cout << "===============================Data Of Plot=================================" << endl;
            for (int i = 0; i < no_of_property; i++)
            {
                cout << "--------------------------------------------------------------------------------------------" << endl;
                cout << "Street Number of Plot";
                cout << a[i].street;
                cout << "\t";
                cout << "Plot Number";
                cout << a[i].plotno;
                cout << "\t";
                cout << "Type of Plot(a)Commercial / b)Ressident)";
                cout << a[i].type;
                cout << "\t";
                cout << "Status of Plot(s)Sold /n)Not Sold)";
                cout << a[i].status;
                cout << "\t";
                cout << "Price";
                cout << a[i].price;
                cout << endl;
            }
            break;
        }
        else
        {
            break;
        }

        cout << "You Want to Continue(press 1 for continue)" << endl;
        cin >> value1;
    }
}
void searchdata()
{
    cout << "======================Search Options=================================" << endl;
    cout << "1)Search By Plot No \t 2)Search  By Status \n"
         << endl;
    int value33;
    cin >> value33;
    switch (value33)
    {
    case 1:
    {
        cout << "Enter Plot Number You Want to Search" << endl;
        int plotnum;
        cin >> plotnum;
        for (int i = 0; i < no_of_property; i++)
        {
            if (plotnum == a[i].plotno)
            {
                cout << "--------------------------------------------------------------------------------------------" << endl;
                cout << "Street Number of Plot";
                cout << a[i].street;
                cout << "Type of Plot(a)Commercial / b)Ressident)";
                cout << a[i].type;
                cout << "Status of Plot(s)Sold /n)Not Sold)";
                cout << a[i].status;
                cout << "Price";
                cout << a[i].price;
                cout << endl;
            }
        }
        break;
    }
    case 2:
    {
        cout << "Search By Status" << endl;
        cout << "Enter Status(s)SOLD PLOTS (n)NOT SOLD) " << endl;
        char statusno;
        cin >> statusno;
        for (int i = 0; i < no_of_property; i++)
        {
            if (statusno == a[i].status)
            {
                cout << "-----------------------------------------------------------------------------------" << endl;
                cout << "Street Number of Plot";
                cout << a[i].street;
                cout << "Plot Number";
                cout << a[i].plotno;
                cout << "Type of Plot(a)Commercial / b)Ressident)";
                cout << a[i].type;
                cout << "Status of Plot(s)Sold /n)Not Sold)";
                cout << a[i].status;
                cout << "Price";
                cout << a[i].price;
                cout << endl;
            }
        }
        break;
    }
    }
}
void datareport()
{
    cout << "Select Report Option" << endl;
    cout << "1)Report BY Prices \n 2)Report By Street Number \n 3)Report By Type \n";
    int valuech;
    cin >> valuech;
    switch (valuech)
    {
    case 1:
    {
        int amount;
        cout << "Plots under Amount" << endl;
        cin >> amount;
        for (int i = 0; i < no_of_property; i++)
        {
            if (a[i].price < amount)
            {
                cout << "Street Number of Plot";
                cout << a[i].street;
                cout << "\t";
                cout << "Plot Number";
                cout << a[i].plotno;
                cout << "\t";
                cout << "Type of Plot(a)Commercial / b)Ressident)";
                cout << a[i].type;
                cout << "\t";
                cout << "Status of Plot(s)Sold /n)Not Sold)";
                cout << a[i].status;
                cout << "\t";
                cout << "Price";
                cout << a[i].price;
                cout << endl;
            }
        }
        break;
    }
    case 2:
    {
        cout << "Report about Streets " << endl;
        for (int i = 0; i < no_of_property; i++)
        {
            cout << "Street Number of Plot";
            cout << a[i].street;
            cout << "\t";
            cout << "Plot Number";
            cout << a[i].plotno;
            cout << "\t";
            cout << "Type of Plot(a)Commercial / b)Ressident)";
            cout << a[i].type;
            cout << "\t";
            cout << "Status of Plot(s)Sold /n)Not Sold)";
            cout << a[i].status;
            cout << "\t";
            cout << "Price";
            cout << a[i].price;
            cout << endl;
        }
        break;
    }
    case 3:
    {
        cout << "==============================Report Of Solded Plots================================" << endl;
        for (int i = 0; i < no_of_property; i++)
        {
            if (a[i].type = 's')
            {
                cout << "Street Number of Plot";
                cout << a[i].street;
                cout << "\t";
                cout << "Plot Number";
                cout << a[i].plotno;
                cout << "\t";
                cout << "Type of Plot(a)Commercial / b)Ressident)";
                cout << a[i].type;
                cout << "\t";
                cout << "Status of Plot(s)Sold /n)Not Sold)";
                cout << a[i].status;
                cout << "\t";
                cout << "Price";
                cout << a[i].price;
                cout << endl;
            }
        }
        cout << "==========================Report of UN-Solded Plots=================================" << endl;
        for (int i = 0; i < no_of_property; i++)
        {
            if (a[i].type = 'n')
            {
                cout << "Street Number of Plot";
                cout << a[i].street;
                cout << "\t";
                cout << "Plot Number";
                cout << a[i].plotno;
                cout << "\t";
                cout << "Type of Plot(a)Commercial / b)Ressident)";
                cout << a[i].type;
                cout << "\t";
                cout << "Status of Plot(s)Sold /n)Not Sold)";
                cout << a[i].status;
                cout << "\t";
                cout << "Price";
                cout << a[i].price;
                cout << endl;
            }
        }
        break;
    }
    }
}
int main()
{
    int value0;
    value0 = 1;
    while (value0 == 1)
    {
        int value01;
        cout << "value Option:\n 1)Manage Data \n 2)Search Property \n 3)Over All Report \n 4)Exit 5)Add Owner\n 6)Assign Plot to Owner\n 7)Data of All Owners\n";
        cin >> value01;
        if (value01 == 1)
        {
            // Manage Function Will Be Triggered
            datamanage(); // function call,never add return type in
        }
        else if (value01 == 2)
        {
            searchdata();
            // Search Function Will Be Triggered
        }
        else if (value01 == 3)
        {
            datareport();
            // Report Function Will Be Triggered
        }
        else if (value01 == 4)
        {
            break;
            // Exit From Program
        }
        else if (value01 == 5)
        {
            addowner();
        }
        else if (value01 == 6)
        {
            ownerassign();
        }
        else if (value01 == 7)
        {
            ownerinfo();
        }
        else
        {
            cout << "invalid option SELECTED:";
        }
        cout << "You Want TO Continue (press 1 for continue)" << endl;
        cin >> value0;
    }

    return 0;
}
