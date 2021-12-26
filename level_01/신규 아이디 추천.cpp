#include <string>
#include <vector>

using namespace std;

int isBigger(char c)
{
    return (c >= 'A' && c <= 'Z');
}

string solution(string new_id) {
    int i, found, len;
    int toSmall = 'a' - 'A';
    
    // 1단계
    len = new_id.length();
    for(i = 0; i < len; i++)
    {
        if (isBigger(new_id[i]))
            new_id[i] += toSmall;
    }
    
    //2단계
    found = new_id.find_first_of("~!@#$%^&*()=+[{]}:?,<>/");
    while(found != string::npos)
    {
        new_id.erase(found, 1);
        found = new_id.find_first_of("~!@#$%^&*()=+[{]}:?,<>/", found);
    }
    
    //3단계
    found = new_id.find('.');
    while(found != string::npos)
    {
        i = 1;
        while(new_id[found+i] == '.')
        {
            i++;
        }
        if (i > 1) {
            new_id.replace(found, i, 1, '.');
        }
        found = new_id.find('.', found+1);
    }
    
    //4단계
    if(new_id.front() == '.') new_id.erase(new_id.begin());
    if(new_id.back() == '.') new_id.erase(new_id.end() - 1);
    
    //5단계
    if(new_id.empty()) new_id = "a";
    
    //6단계
    if(new_id.length() > 15)
    {
        new_id.erase(15);
        if(new_id.back() == '.') new_id.erase(new_id.end() - 1);
    }
    
    //7단계
    if((len = new_id.length()) < 3)
    {
        new_id.insert(len, 3 - len, new_id.back());
    }
        
    string answer = new_id;
    return answer;
}
