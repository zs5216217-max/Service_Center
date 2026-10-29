#ifndef CIRCULARSERVICELIST_H
#define CIRCULARSERVICELIST_H

#include "ServiceNode.h"

class CircularServiceList
{
private:
    ServiceNode* tail;
    ServiceNode* current;
    int count;

    ServiceNode* GetNodeAt(int index);
    void ResetCurrent();

public:
    CircularServiceList();
    ~CircularServiceList();

    bool IsEmpty();
    bool IsNotEmpty();

    void Insert(ServiceNode* service);
    ServiceNode* Remove();

    void InsertAt(ServiceNode* service, int index);
    ServiceNode* RemoveAt(int index);

    void Swap(int first, int second);
    void Sort();
    void Reverse();
    void Print();
    void MoveNext();
};

#endif