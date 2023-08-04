#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0; //Priority Queue is Empty
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                swap(pq[childIndex], pq[parentIndex]);
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int remove()
    {
        if (isEmpty())
        {
            return 0;
        }
        int oldMin = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int leftChild, rightChild;
        leftChild = (2 * parentIndex) + 1;
        rightChild = (2 * parentIndex) + 2;

        while (leftChild < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChild])
                minIndex = leftChild;
            if (rightChild < pq.size() && pq[rightChild] < pq[minIndex])
                minIndex = rightChild;
            if (minIndex == parentIndex)
                break;

            swap(pq[minIndex], pq[parentIndex]);
            parentIndex = minIndex;
            leftChild = (2 * parentIndex) + 1;
            rightChild = (2 * parentIndex) + 2;
        }
        return oldMin;
    }
};