#include <iostream>
#include <thread>
using namespace std;

class A
{
public:
    void operator()(int limit)
    {
        for(int i=0;i<=limit;i++)
        {
            cout<<"I am A"<<i<<endl;
        }
    }
};

int main()
{
    thread thread1=thread(A(),88);
    thread1.join();
    return 0;
}