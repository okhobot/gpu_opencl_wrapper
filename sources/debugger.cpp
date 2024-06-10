#include "debugger.hpp"
void set_color(ConsoleColor text, ConsoleColor background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void call_error(bool critical,string func, string type, string data, vector<float> int_data)
{
    set_color(Red);
    if(data != "none")
    {
        cout<<type<<" in "<<func<<" - "<<data;
        for(int i=0;i<int_data.size();i++)cout<<int_data[i]<<"; ";
        cout<<endl;
    }
    else cout<<type<<" in "<<func<<endl;

    set_color();

    if(critical)
    {
        string tmp;
        cin>>tmp;
    }
}
