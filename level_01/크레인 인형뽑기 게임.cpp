/*
n * n 인형 보드에서 1~n번째 line의 인형 블록을 뽑아 한 층에 인형 블록 하나 쌓이는 바구니에 담는 상황에서,
바구니에 새 인형을 넣을 때 꼭대기와 동일한 블록이 들어오면 해당 블록들을 터트린다고 가정할 때, 
board 상황과 매 차례 선택한 line들의 vector moves를 받아 터진 블록 수를 구하는 문제.
모든 인형은 1x1 크기이며, 인형을 뽑으면 해당 인형의 자리는 비게 되고, 빈 자리는 0으로 표기한다.
board[i]는 i번째 가로 줄의 상황을 나타내며, 방향은 위에서 아래로 표현한다(바닥 = board[n-1]).  
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int move, doll, depth, top, answer = 0;
    int n = board[0].size();
    int m = moves.size();
    vector<int> stack;
    
    for(int i = 0; i < m; i++)
    {
        move = moves[i] - 1;
        for(depth = 0; depth < n; depth++)
        {
            doll = board[depth][move];
            if (doll) 
                break;
        }
        if(depth == n) continue;
        
        top = 0;
        if(stack.size() > 0) 
          top = stack.back();

        if (top == doll)
        {
            stack.pop_back();
            answer += 2;
        }
        else 
        {
            stack.push_back(doll);
        }
        board[depth][move] = 0;
    }
    return answer;
}
