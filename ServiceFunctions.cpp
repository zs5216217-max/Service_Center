#include <iostream>
#include <limits>
#include <string>
#include "ServiceFunctions.h"
#include "CreateService.h"

using namespace std;

void RunServiceMenu(CircularServiceList& services)
{
    int choice, id, index, first, second;
    string name, type;

    do
    {
        cout << "\n===== SERVICE CENTER MANAGEMENT =====\n";
        cout << "1. Display All Services\n";
        cout << "2. Insert Service at Head\n";
        cout << "3. Remove Service from Head\n";
        cout << "4. Insert Service at Index\n";
        cout << "5. Remove Service at Index\n";
        cout << "6. Swap Services\n";
        cout << "7. Sort Services by ID\n";
        cout << "8. Reverse Service List\n";
        cout << "9. Move to Next Service\n";
        cout << "10. Check Collection Status\n";
        cout << "11. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            services.Print();
            break;

        case 2:
            cout << "Enter service ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter customer name: ";
            getline(cin, name);

            cout << "Enter service type: ";
            getline(cin, type);

            services.Insert(CreateService(id, name, type));
            cout << "Service added.\n";
            break;

        case 3:
        {
            ServiceNode* removed = services.Remove();

            if (removed != nullptr)
            {
                cout << "Removed customer: "
                     << removed->customerName << endl;
                delete removed;
            }
            else
                cout << "Service list is empty.\n";

            break;
        }

        case 4:
            cout << "Enter service ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter customer name: ";
            getline(cin, name);

            cout << "Enter service type: ";
            getline(cin, type);

            cout << "Enter index (starting from 0): ";
            cin >> index;

            services.InsertAt(
                CreateService(id, name, type), index);

            cout << "Service added.\n";
            break;

        case 5:
        {
            cout << "Enter index: ";
            cin >> index;

            ServiceNode* removed = services.RemoveAt(index);

            if (removed != nullptr)
            {
                cout << "Removed customer: "
                     << removed->customerName << endl;
                delete removed;
            }
            else
                cout << "Service list is empty.\n";

            break;
        }

        case 6:
            cout << "Enter first index: ";
            cin >> first;

            cout << "Enter second index: ";
            cin >> second;

            services.Swap(first, second);
            break;

        case 7:
            services.Sort();
            cout << "Services sorted by ID.\n";
            break;

        case 8:
            services.Reverse();
            cout << "Service list reversed.\n";
            break;

        case 9:
            services.MoveNext();
            break;

        case 10:
            if (services.IsEmpty())
                cout << "Service list is empty.\n";
            else
                cout << "Service list is not empty.\n";
            break;

        case 11:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 11);
}