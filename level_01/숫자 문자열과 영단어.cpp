/*
숫자와 각 숫자를 영어로 표기한 영단어(zero, one, two, ..., nine)가 섞인 문자열(ex - 1fourseven34zero)을 인자로 받아 문자열이 의미하는 정수 값을 반환하는 문제. 
각 영단어의 앞 두 글자가 unique함을 이용하여 최대한 빠르게 영단어를 판단할 수 있도록 구현.
*/

#include <string>
#include <vector>

using namespace std;

int isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

char toDigit(string s, int* len)
{
    switch (s[0])
    {
      case 'o':
        *len = 3;
        return '1';
      case 't':
        if(s[1] == 'w')
        {
          *len = 3;
          return '2';
        }
        *len = 5;
        return '3';
      case 'f':
        *len = 4;
        if(s[1] == 'o') return '4';
        else return '5';
      case 's':
        if(s[1] == 'i')
        {
          *len = 3;
          return '6';
        }
        *len = 5;
        return '7';
      case 'e':
        *len = 5;
        return '8';
      case 'n':
        *len = 4;
        return '9';
      case 'z':
        *len = 4;
        return '0';
      default:
        *len = 1;
        return ' ';
    }
}

int solution(string s) {
    int idx, len;
    char c;
    string sub;
    idx = s.find_first_not_of("0123456789");
    while (idx != string::npos)
    {
        sub = s.substr(idx, 2);
        c = toDigit(sub, &len);
        s.replace(idx, len, 1, c);
        idx = s.find_first_not_of("0123456789", idx+1);
    }
    
    int answer = stoi(s);
    return answer;
}
