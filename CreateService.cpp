#include "CreateService.h"

ServiceNode* CreateService(int id, string name, string type)
{
    ServiceNode* service = new ServiceNode;

    service->serviceID = id;
    service->customerName = name;
    service->serviceType = type;
    service->next = nullptr;

    return service;
}
