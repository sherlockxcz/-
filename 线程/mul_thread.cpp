#include <iostream>
#include <thread>
#include <string>
using namespace std;

void func1()
{
    cout<<"this is my thread,thread id is"
    <<this_thread::get_id()<<endl;
}
void func2(string& s)
{
    cout<<"this is my thread,the arg is" << s << endl;
}

int main()
{
    string s="test";
    thread th = thread (func2,std::ref(s));
    
    //子线程与主线程无关
    //th.detach();
    th.join();//主线程等待与子线程回合
    cout<<"this is main thread,thread id is"
    <<this_thread::get_id()<<endl;
    return 0;
}