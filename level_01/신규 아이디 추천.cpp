/*
사용자의 아이디를 인자로 받아 추천 아이디를 반환하는 문제. 아이디는 총 7단계에 걸쳐 검증하게 된다.
1단계: 대문자 사용 불가. 추천: 모든 대문자를 소문자로 전환. 
  ASCII 코드 상 대문자와 소문자가 일정한 값(= 32)차이가 남을 이용.
2단계: _, -, .을 제외한 특수문자 사용 불가. 추천: 해당 특수문자가 있을 경우 모두 제거. 
  특수문자 pool이 문제에 주어져 find_first_of로 탐색.
3단계: .이 2번 이상 연속 불가. 추천: 2번 이상 등장할 경우 . 하나로 치환.
4단계: 처음이나 마지막에 .이 등장 불가. 추천: 해당 . 제거.
5단계: 빈 문자열 사용 불가(2,3,4단계에 걸쳐 빈 문자열이 될 수 있음). 추천: "a" 대입.
6단계: 아이디 길이 16글자 이상 제한. 추천: 16번째 글자부터는 모두 제거(이 과정에서 3단계에 어긋날 경우 대응).
7단계: 아이디 길이 2글자 이하 제한. 추천: 아이디의 가장 마지막 글자를 반복하여 3글자로 만듦.
*/

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
