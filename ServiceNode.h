#ifndef SERVICENODE_H
#define SERVICENODE_H

#include <string>
using namespace std;

struct ServiceNode
{
    int serviceID;
    string customerName;
    string serviceType;
    ServiceNode* next;

    ServiceNode();
};

#endif