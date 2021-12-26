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
