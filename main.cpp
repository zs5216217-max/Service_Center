#include "CircularServiceList.h"
#include "CreateService.h"
#include "ServiceFunctions.h"

int main()
{
    CircularServiceList services;

    services.Insert(
        CreateService(103, "Ali", "Repair"));

    services.Insert(
        CreateService(101, "Ahmed", "Maintenance"));

    services.Insert(
        CreateService(105, "Sara", "Inspection"));

    RunServiceMenu(services);

    return 0;
}