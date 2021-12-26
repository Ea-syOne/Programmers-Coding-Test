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
