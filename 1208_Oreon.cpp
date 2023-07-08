#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cstdlib>

using namespace std;

class DisjoinSet{

    private:
        vector<int> parent;
        vector<int> size;

    public:
        DisjoinSet(int memberSize){
            this->parent.reserve(memberSize);
            this->size.reserve(memberSize);
            for(int i=0 ; i<memberSize ; i++){
                this->parent[i] = i;
                this->size[i] = 1; 
            }
        }

        int find_parent(int member){
            if(this->parent[member] != member){
                member = find_parent(this->parent[member]);
            }
            return(member);
        }

        void Union(int memberA, int memberB){
            int pA = find_parent(memberA);
            int pB = find_parent(memberB);

            if(pA != pB){
                if(size[pA] > size[pB]){
                    this->parent[pB] = pA;
                }
                else
                    this->parent[pA] = pB;
            }
        }
};

struct Route{
    int cost;
    int nodeA;
    int nodeB;

    Route(int c, int A, int B){
        cost = c;
        nodeA = A;
        nodeB = B;
    }

};

bool cmp(Route A, Route B){
    if(A.cost == B.cost)
        return(A.nodeA < B.nodeB);
    return A.cost < B.cost;
}


int main(){

    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int n, Case=1;
    cin>>n;
    while(n--){
        cout<<"Case "<<Case<<":\n";

        DisjoinSet disjointSet(26);
        int cityCount, needRoadCount, roadCount, ans = 0;
        vector<Route> road;
        string s;

        cin>>cityCount;
        getline(cin, s);

        for(int i=0 ; i<cityCount ; i++){
            getline(cin, s);

            stringstream ss(s);
            string s;
            int index = 0, cost;
            while( std::getline(ss,s,',')){
                cost = atoi(s.c_str());
                if(cost != 0){
                    if(i<index)
                        road.push_back(Route(cost, i, index));
                    else
                        road.push_back(Route(cost, index, i));
                }
                index++;
            }
        }



        sort(road.begin(), road.end(), cmp);

        needRoadCount = cityCount - 1;
        roadCount = road.size();

        for(int i=0 ; i<roadCount ; i++){
            int nodeA = road[i].nodeA;
            int nodeB = road[i].nodeB;
            int cost =  road[i].cost;

            //兩個node在同個集合就跳過
            if(disjointSet.find_parent(nodeA) == disjointSet.find_parent(nodeB)){
                continue;
            }

            else{
                cout<<char('A' + nodeA)<<"-"<<char('A' + nodeB)<<" "<<cost<<"\n";

                disjointSet.Union(nodeA, nodeB);
                needRoadCount--;
                // minimum spanning tree complete !
                if(needRoadCount == 0)
                    break;
            }
        }
        Case++;
    }
}
