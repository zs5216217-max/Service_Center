#include <iostream>
#include <utility>
#include "CircularServiceList.h"

using namespace std;

CircularServiceList::CircularServiceList()
{
    tail = nullptr;
    current = nullptr;
    count = 0;
}

CircularServiceList::~CircularServiceList()
{
    while (!IsEmpty())
    {
        ServiceNode* service = Remove();
        delete service;
    }
}

bool CircularServiceList::IsEmpty()
{
    return count == 0;
}

bool CircularServiceList::IsNotEmpty()
{
    return count > 0;
}

void CircularServiceList::ResetCurrent()
{
    current = nullptr;
}

ServiceNode* CircularServiceList::GetNodeAt(int index)
{
    if (IsEmpty())
        return nullptr;

    ServiceNode* temp = tail->next;

    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp;
}

void CircularServiceList::Insert(ServiceNode* service)
{
    if (service == nullptr)
        return;

    if (IsEmpty())
    {
        tail = service;
        service->next = service;
    }
    else
    {
        service->next = tail->next;
        tail->next = service;
    }

    count++;
    ResetCurrent();
}

ServiceNode* CircularServiceList::Remove()
{
    if (IsEmpty())
        return nullptr;

    ServiceNode* first = tail->next;

    if (count == 1)
        tail = nullptr;
    else
        tail->next = first->next;

    first->next = nullptr;
    count--;
    ResetCurrent();

    return first;
}

void CircularServiceList::InsertAt(
    ServiceNode* service, int index)
{
    if (service == nullptr)
        return;

    if (IsEmpty() || index <= 0)
    {
        Insert(service);
        return;
    }

    if (index >= count)
    {
        service->next = tail->next;
        tail->next = service;
        tail = service;
        count++;
        ResetCurrent();
        return;
    }

    ServiceNode* previous = GetNodeAt(index - 1);

    service->next = previous->next;
    previous->next = service;

    count++;
    ResetCurrent();
}

ServiceNode* CircularServiceList::RemoveAt(int index)
{
    if (IsEmpty())
        return nullptr;

    if (index <= 0)
        return Remove();

    if (index >= count)
        index = count - 1;

    ServiceNode* previous = GetNodeAt(index - 1);
    ServiceNode* removed = previous->next;

    previous->next = removed->next;

    if (removed == tail)
        tail = previous;

    removed->next = nullptr;
    count--;
    ResetCurrent();

    return removed;
}

void CircularServiceList::Swap(int first, int second)
{
    if (first < 0 || second < 0 ||
        first >= count || second >= count)
    {
        cout << "Invalid index!\n";
        return;
    }

    ServiceNode* a = GetNodeAt(first);
    ServiceNode* b = GetNodeAt(second);

    swap(a->serviceID, b->serviceID);
    swap(a->customerName, b->customerName);
    swap(a->serviceType, b->serviceType);

    ResetCurrent();
}

void CircularServiceList::Sort()
{
    if (count < 2)
        return;

    for (int i = 0; i < count - 1; i++)
    {
        ServiceNode* a = tail->next;

        for (int j = 0; j < count - i - 1; j++)
        {
            ServiceNode* b = a->next;

            if (a->serviceID > b->serviceID)
            {
                swap(a->serviceID, b->serviceID);
                swap(a->customerName, b->customerName);
                swap(a->serviceType, b->serviceType);
            }

            a = a->next;
        }
    }

    ResetCurrent();
}

void CircularServiceList::Reverse()
{
    if (count < 2)
        return;

    ServiceNode* oldFirst = tail->next;
    ServiceNode* previous = tail;
    ServiceNode* node = oldFirst;

    for (int i = 0; i < count; i++)
    {
        ServiceNode* nextNode = node->next;
        node->next = previous;
        previous = node;
        node = nextNode;
    }

    tail = oldFirst;
    ResetCurrent();
}

void CircularServiceList::Print()
{
    if (IsEmpty())
    {
        cout << "No service records available.\n";
        return;
    }

    ServiceNode* temp = tail->next;

    cout << "\n--- Service Center Records ---\n";

    for (int i = 0; i < count; i++)
    {
        cout << "Service ID: " << temp->serviceID
             << " | Customer: " << temp->customerName
             << " | Service: " << temp->serviceType << endl;

        temp = temp->next;
    }

    cout << "Total Records: " << count << endl;
}

void CircularServiceList::MoveNext()
{
    if (IsEmpty())
    {
        cout << "No service records available.\n";
        return;
    }

    if (current == nullptr)
        current = tail->next;
    else
        current = current->next;

    cout << "Current Customer: " << current->customerName
         << " | Service: " << current->serviceType << endl;
}