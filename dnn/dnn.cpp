// derived from test10.cpp, try to use multi-blodd method
// creat a new vector<pair<string, bool>>bidirections to store ex:s->p,p->s
//goodsol different
// derived from test13.cpp, try to fix the problem in bidirection that only use once
// more detail we can run the test13.cpp using case8.txt, we can't get the best sol
// try to add who induce the false to true, that is, two pair in the bidirection
#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;               // let string to be int
vector<pair<string, string>> nodes;  // 
vector<string> obstacle;
vector<vector<string>> all_path;  //all sol. path
vector<vector<string>> goodsol;
//all_path will eventually become a contianer that contains all legal sol
//goodsol will store the shortest sol.(s) in all_path

//obtain vector<pair<string, string>> nodes, and vector<string> obstacle
//obtain map<string, int> mp

vector<pair<pair<string, string>, pair<string, bool>>>bidirections; // ex:((s,a),false)
// /*
void init() {
    ifstream fin("input6.txt");

    // construct nodes into vector
    string fi, se;
    string wholeline;
    while (1) {
        getline(fin, wholeline);
        // cout << wholeline<<endl;
        if (wholeline.find("Obstacle")>=0 && wholeline.find("Obstacle")<=wholeline.length()) break;
        fi = wholeline.substr(0, wholeline.find('-')-1);
        se = wholeline.substr(wholeline.find('>')+2);
        cout << fi << " "<<se<<endl;
        nodes.push_back(make_pair(fi, se));
        cout << wholeline<<endl;
    }
    //construct obstacles
    stringstream ss;
    ss << wholeline.substr(9);
    // cout << "ok"<<ss.str()<<"ok"<<endl;
    while(!ss.eof()) {
        string a;
        ss >> a;
        obstacle.push_back(a);
        // cout <<"*"<< a <<"*"<< endl;
    }
    // for(int i=0;i<obstacle.size();i++){
    //     cout << "*"<<obstacle.at(i)<<"*"<<endl;
    // }
    // for (int i = 9; i < wholeline.length(); i += 2)
    //     obstacle.push_back(wholeline[i]);
    fin.close();
    // for(int i=0;i<nodes.size();i++){
    //     cout << nodes.at(i).first<<" "<<nodes.at(i).second<<endl;
    // }

    // construct bidirection pair(it should be s->a,a->s,and not obstacle)
    for(int i=0;i<nodes.size();i++){
        for(int j=i+1;j<nodes.size();j++){
            if(nodes.at(i).first==nodes.at(j).second && nodes.at(i).second==nodes.at(j).first && (find(obstacle.begin(), obstacle.end(),nodes.at(i).first)==obstacle.end())&&(find(obstacle.begin(), obstacle.end(),nodes.at(i).second)==obstacle.end())){
                bidirections.push_back(make_pair(make_pair(nodes.at(i).first,nodes.at(i).second), make_pair("",false)));
            }
        }
    }

    // cout << "just after construct pair"<<endl;
    // for(int i=0;i<bidirections.size();i++){
    //     cout << bidirections.at(i).first.first << " "<< bidirections.at(i).first.second << endl;
    // }

    // construct map
    map<string, int>::iterator it;
    int index = 0;
    for (int i = 0; i < nodes.size(); i++) {
        if (mp.find(nodes.at(i).first) == mp.end()) {
            mp[nodes.at(i).first] = index;
            index++;
        }
    }
    if (mp.find("T") == mp.end()){
        mp["T"] = index;
        index++;
    }
    for(int i=0;i<nodes.size();i++){
        cout << nodes.at(i).second<<endl;
        if(mp.find(nodes.at(i).second) == mp.end()) {
            mp[nodes.at(i).second] = index;
            index++;
        }
    }
    cout << "index: "<<index<<endl;
    for(it = mp.begin();it!=mp.end();it++)
        cout << it->first << " "<< it->second<<endl;
    // cout << mp.size()<<endl;
    for(int i=0;i<obstacle.size();i++)
        cout << obstacle.at(i)<<" ";
    cout << endl;
}
// */
// A directed graph using
// adjacency list representation
class Graph {
    int V;           // No. of vertices in graph
    list<string>* adj;  
    // Pointer to an array containing adjacency lists，V size to record predecessorsof ecah element

    // A recursive function used by printAllPaths()
    void printAllPathsUtil(string, string, bool[], string[], int&);

   public:
    Graph(int V);  // Constructor
    void addEdge(string u, string v);
    void printAllPaths(string s, string d);
};

Graph::Graph(int n):V(n) {
    adj = new list<string>[n];
    // cout << "in constructor"<<endl;
}

void Graph::addEdge(string u, string v) {
    adj[mp[u]].push_back(v);  // Add v to u’s list. ex:(0,1),(0,2) 1 and 2
}

// Prints all paths from 's' to 'd'
void Graph::printAllPaths(string s, string d) {
    // Mark all the vertices as not visited
    bool* visited = new bool[V];//bool arr

    // Create an array to store paths
    string* path = new string[(10*V)];
    int path_index = 0;  // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++) visited[i] = false;

    // Initialize all obstacles as visited
    for(int i=0;i<obstacle.size();i++){
        if(mp.find(obstacle.at(i))!=mp.end())
            visited[mp[obstacle.at(i)]] = true;
    }
    // cout << "in test visited\n";
    // for(int i=0;i<V;i++){
    //     cout << static_cast<int>(visited[i])<<endl;
    // }
    // cout << "out test visited\n";
    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(string u, string d, bool visited[], string path[],
                              int& path_index) {
    // Mark the current node and store it in path[]
    visited[mp[u]] = true;
    path[path_index] = u;
    cout << u << endl;
    cout << path_index<<endl;
    path_index++;


    // If current vertex is same as destination, then print
    // current path[]
    if (u == d) {
        cout << "okoko"<<endl;
        for (int i = 0; i < path_index; i++) cout << path[i] << " ";
        cout << endl;
        vector<string> one_sol;
        for(int i=0;i<path_index;i++) one_sol.push_back(path[i]);
        all_path.push_back(one_sol);

        

    } else  // If current vertex is not destination
    {   
        // Recur for all the vertices adjacent to current vertex
            list<string>::iterator i;
            for (i = adj[mp[u]].begin(); i != adj[mp[u]].end(); ++i){
                cout << "predecessor is "<<u<<" "<<*i<<" in recur "<<mp[*i]<<endl;
            if (!visited[mp[*i]])
                printAllPathsUtil(*i, d, visited, path, path_index);
            else if(visited[mp[*i]]){ // s->a->s case
                for(int j=0;j<bidirections.size();j++){
                    if(bidirections.at(j).first.first==u&&bidirections.at(j).first.second==*i&&bidirections.at(j).second.second==false){
                        bidirections.at(j).second.second = true;
                        bidirections.at(j).second.first = u;//********
                        printAllPathsUtil(*i, d, visited, path, path_index);
                    }
                    else if(bidirections.at(j).first.second==u&&bidirections.at(j).first.first==*i&&bidirections.at(j).second.second==false){
                        bidirections.at(j).second.second = true;
                        bidirections.at(j).second.first = u;//********
                        printAllPathsUtil(*i, d, visited, path, path_index);
                    }
                }
            }
        }
        cout <<u<< " going out of else loop\n";
    }

    for(int i=0;i<bidirections.size();i++) {
        if(u==bidirections.at(i).second.first) {
            bidirections.at(i).second.second = false;
            cout << "after enable the bidirection "<<endl;
        }
    }
    path_index--;
    visited[mp[u]] = false;
    cout << "after minus path_index "<<path_index<<endl;    
    
    /*
    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[mp[u]] = false;
    cout << "after minus path_index "<<path_index<<endl;
    // cout << "path things\n";
    // for (int i = 0; i < path_index; i++) cout << path[i] << " ";
    //     cout << endl;
    */

}
void addallnodes(Graph& g2){
    for(int i=0;i<nodes.size();i++){
        g2.addEdge(nodes.at(i).first, nodes.at(i).second);
    }
}
//check all path 
//1. contians P
//2.have K,G, TA says not necessary
//3. K first and then G
void checkpath(){
    vector<vector<string>>::iterator IT;
    vector<string>::iterator it;
    //step1.
    for(int i=0;i<all_path.size();i++){
        it = find(all_path.at(i).begin(), all_path.at(i).end(), "P");
        if(it == all_path.at(i).end()){
            cout << "i want to delete: ";
            for(int k=0;k<all_path.at(i).size();k++){
                cout << all_path.at(i).at(k)<<" ";
            }
            cout << endl;
            all_path.erase(find(all_path.begin(),all_path.end(),all_path.at(i)));
            i--;
        }
    }
    // //step2.
    // for(int i=0;i<all_path.size();i++){
    //     if(find(all_path.at(i).begin(), all_path.at(i).end(),'K')==all_path.at(i).end() ||find(all_path.at(i).begin(), all_path.at(i).end(),'G')==all_path.at(i).end())
    //         all_path.erase(find(all_path.begin(),all_path.end(),all_path.at(i)));
    // }
    //step3.
    for(int i=0;i<all_path.size();i++){
        if(find(all_path.at(i).begin(), all_path.at(i).end(),"K")>find(all_path.at(i).begin(), all_path.at(i).end(),"G")){
            cout << "i want to delete: ";
            for(int k=0;k<all_path.at(i).size();k++){
                cout << all_path.at(i).at(k)<<" ";
            }
            cout << endl;
            all_path.erase(find(all_path.begin(),all_path.end(),all_path.at(i)));
            i--;
        }
    }
}
//shortest path
void shortest() {
    int index = 0;
    for(int i=1;i<all_path.size();i++){
        if(all_path.at(i).size()<all_path.at(index).size()) index = i;
        /*
        else if(all_path.at(i).size()==all_path.at(index).size()) {
            goodsol.push_back(index);
            index = i;
        }
        */
    }
    // check sols
    if(all_path.size()==0){
        cerr <<"no good sol!!!!!!!!!!!!!!!"<<endl;
        exit(1);
    }
    // goodsol.push_back(all_path.at(index));
    for(int i=0;i<all_path.size();i++){
        // if(all_path.at(i).size()==all_path.at(index).size()&&i!=index)
        if(all_path.at(i).size()==all_path.at(index).size())
            goodsol.push_back(all_path.at(i));
    }
}
// Driver program
int main() {
    init();
    Graph g2(mp.size());
    cout << "g2 prepared"<< endl;
    addallnodes(g2);
    cout << "all prepared"<<endl;
    g2.printAllPaths("S","T");
    cout << "all finish"<<endl;
    for(int i=0;i<all_path.size();i++){
        for(int j=0;j<all_path.at(i).size();j++)
        cout << all_path.at(i).at(j)<<" ";
        cout << endl;
    }
    cout << "start check\n";
    checkpath();
    cout << "finish check\n";
    for(int i=0;i<all_path.size();i++){
        for(int j=0;j<all_path.at(i).size();j++)
        cout << all_path.at(i).at(j)<<" ";
        cout << endl;
    }
    cout << "start shortest\n";
    shortest();
    cout << "finish shortest\n";
    for(int i=0;i<goodsol.size();i++){
        for(int j=0;j<goodsol.at(i).size();j++)
            cout << goodsol.at(i).at(j)<<" ";
        cout << endl;
    }

    return 0;
}