#include<iostream>
#include<fstream>
using namespace std;
main()
{
}

string parseRecord(string record, int field)
{
    int commaCount = 1;
    string item="";
    for(int x = 0; x<record.length();x++)
    {
        if(record[x]==',')
        {
            commaCount++;
        }
        else if(commaCount==field)
        {
            item+=record[x];
        }
    }
    return item;
}