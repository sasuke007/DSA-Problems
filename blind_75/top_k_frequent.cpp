vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for(auto num:nums){
        freq[num]++;
    }
    map<int,vector<int>,greater<int>> count;
    for(auto it=freq.begin();it!=freq.end();++it){
        count[it->second].push_back(it->first);
    }
    vector<int> answer;
    int i=0;
    for(auto it=count.begin();i<k && it!=count.end();++it){
        if((k-i)<it->second.size()){
            int noOfElem=k-i;
            answer.insert(answer.end(),it->second.begin(),it->second.begin()+noOfElem);
            i+=noOfElem;
        }
        else{
            answer.insert(answer.begin(),it->second.begin(),it->second.end());
            i+=it->second.size();
        }
    }
    return answer;
}