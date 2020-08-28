#include <iostream>
#include <thread>

using namespace std;

template<class T>
void measurement(T&&func){
    using namespace std::chrono;
    auto start =system_clock::now();
    func();
    duration<double>diff =system_clock::now() -start;
    cout<<"elapsed: "<<diff.count()<<"seconds"<<endl;
}

void sum(long start,long end,long &ans)
{
    long s=0;
    for(long i=start;i<end;i++)
    {
        s+=i;
    }
    ans = s;
}

const long S=100000000;

int main()
{
    measurement([](){
        long ans1,ans2;
        thread th1 = thread(sum,0,S/2,std::ref(ans1));
        thread th2 = thread(sum,S/2,S,std::ref(ans2));
        th1.join();
        th2.join();
        cout << ans1+ans2 <<endl;
    });
    measurement([](){
        long ans;
        sum(0,S,ans);
        cout<<ans<<endl;
    });
}
