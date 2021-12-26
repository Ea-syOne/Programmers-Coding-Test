/*
0~9 값을 갖는 전화번호 vector와 주로 사용하는 손을 의미하는 문자열 hand("left" or "right")를 인자로 받아
각 키패드를 누르는 손을 구하는 문제.
왼손은 *, 오른손은 #에서 시작하며, 키패드를 누르면 손은 해당 위치로 이동.
두 키패드 사이의 거리는 상,하,좌,우 이동을 거리 1로 계산한다. 1과 8의 거리는 1(우) + 1(하) + 1(하) = 3이다.
1,4,7은 왼손, 3,6,9는 오른손으로 누르며, 그 중간의 2,5,8,0의 경우 가까운 손가락으로 누름 - 만약 거리가 같다면 주로 쓰는 손으로 누름 -.
각 키패드 위치를 1 ~ 12 값(* = 10, 0 = 11, # = 12)으로 지정하고, 거리는 키패드와 현재 위치의 차를 3으로 나눈 몫과 나머지의 합으로 구했다.
*  3 * 4 키패드 내에서 A에서 B(B > A)로 이동하기 위해선 상하(= +- 3)로 움직이거나 좌우(= +- 1)로 움직여야 한다. A에서 위치를 B까지 올리려면 
   3 또는 1만큼 더해서 움직여야 한다는 의미. 따라서 3이 몇 번인지, 1이 몇 번인지를 구하면 거리를 구할 수 있다.
*/

#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int getDistance(int pos, int num)
{
    div_t d = div(abs(pos-num), 3);
    return d.quot + d.rem;
}

void reaction(int* pos, int num, string* ans, string s)
{
    *pos = num;
    (*ans).append(s);
}

string solution(vector<int> numbers, string hand) {
    int lpos = 10, rpos = 12, num, ldis, rdis;
    int len = numbers.size();
    div_t ld, rd;
    string answer = "";
    
    for(int i = 0; i < len; i++)
    {
        num = numbers[i];
        if (!num) num = 11;
        switch(num % 3)
        {
            case 0:
                reaction(&rpos, num, &answer, "R");
                break;
            case 1:
                reaction(&lpos, num, &answer, "L");
                break;
            case 2:
                ldis = getDistance(lpos,num);
                rdis = getDistance(rpos,num);
                if(ldis > rdis)
                {
                    reaction(&rpos, num, &answer, "R");
                }
                else if (ldis < rdis)
                {
                    reaction(&lpos, num, &answer, "L");
                }
                else
                {
                    if(hand[0] == 'l')
                    {
                        reaction(&lpos, num, &answer, "L");
                    }
                    else 
                    {
                        reaction(&rpos, num, &answer, "R");
                    }
                }
                break;
        }
    }
    
    return answer;
}
