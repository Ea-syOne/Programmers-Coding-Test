/*
로또 정답번호 win_nums와, 일부 숫자가 지워진 로또 번호 lottos를 인자로 받아 최소 순위와 최고 순위를 구하는 문제.
win_nums와 lottos는 정렬되어 있지 않으며, 지워진 번호는 0으로 처리.
로또 순위는 1 ~ 6위까지 있으며, 1위는 6개, 2위는 5개, ... , 6위는 1개 이하 일치할 경우를 의미.
qsort와 bsearch를 이용해 빠른 탐색을 구현.
*/
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int i, znum = 0, match = 0;
    int* ret;
    
    qsort(&win_nums[0], 6, sizeof(int), cmp);
    
    for(i = 0; i < 6; i++)
    {
        if(lottos[i] == 0) 
        {
            znum++;
        }
        else
        {
            ret = (int*)bsearch(&lottos[i], &win_nums[0], 6, sizeof(int), cmp);
            if (ret != NULL) match++;
        }
    }
    
    vector<int> answer(2, 0);
    answer[1] = 7 - match;
    answer[0] = answer[1] - znum;
    if(answer[0] > 6) answer[0] = 6;
    if(answer[1] > 6) answer[1] = 6;
    
    return answer;
}
