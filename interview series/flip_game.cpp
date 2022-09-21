class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> answer;
        for(int i=0;i<currentState.size()-1;++i){
            if(currentState[i]=='+' and currentState[i+1]=='+'){
                string newState=currentState;
                newState[i]='-';
                newState[i+1]='-';
                answer.push_back(newState);
            }
        }
        return answer;
    }
};