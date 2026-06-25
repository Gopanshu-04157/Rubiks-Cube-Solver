#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Cube{
public: 
    enum Face{ UP, FRONT, RIGHT, BACK, LEFT, DOWN};
    enum Color{ WHITE, GREEN , RED, BLUE, ORANGE, YELLOW};
private:

    Color face[6][3][3];

public:

    Cube(){// solved cube
        // white <--> yellow
        // red <--> orange
        // blue <--> green
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                face[UP][i][j] = WHITE;
                face[FRONT][i][j] = GREEN;
                face[RIGHT][i][j] = RED;
                face[BACK][i][j] = BLUE;
                face[LEFT][i][j] = ORANGE;
                face[DOWN][i][j] = YELLOW;
            }
        }
    }

    char getColorChar(Color c){
        switch(c){
            case WHITE: return 'W';
            case GREEN: return 'G';
            case RED: return 'R';
            case BLUE: return 'B';
            case ORANGE: return 'O';
            case YELLOW: return 'Y';
        }
        return '?';
    }

    void printFace(Face f){
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                cout << getColorChar(face[f][i][j]) << " ";
            }
            cout << endl;
        }
    }

    void printCube(){
        cout << "UP" << endl;
        printFace(UP);
        cout << endl << "FRONT" << endl;
        printFace(FRONT);
        cout << endl << "RIGHT" << endl;
        printFace(RIGHT);
        cout << endl << "BACK" << endl;
        printFace(BACK);
        cout << endl << "LEFT" << endl;
        printFace(LEFT);
        cout << endl << "DOWN" << endl;
        printFace(DOWN);
    }

    void rotateFaceClockwise(Face f){
        for(int i = 0 ; i < 3 ; i ++){
            for(int j = i ; j < 3 ; j++){
                swap(face[f][i][j],face[f][j][i]);
            }
        }

        for(int i = 0 ; i < 3 ; i ++){
            swap(face[f][i][0],face[f][i][2]);
        }
    }
    
    void rotateFaceCounterClockwise(Face f){
        for(int i = 0 ; i < 3 ; i ++){
            for(int j = i ; j < 3 ; j++){
                swap(face[f][i][j],face[f][j][i]);
            }
        }

        for(int i = 0 ; i < 3 ; i ++){
            swap(face[f][0][i],face[f][2][i]);
        }
    }

    void u(){
        rotateFaceClockwise(UP);
        for(int i = 0 ; i < 3 ; i++){
            swap(face[FRONT][0][i],face[RIGHT][0][i]);
        }
        for(int i = 0 ; i < 3 ; i++){
            swap(face[RIGHT][0][i],face[BACK][0][i]);
        }
        for(int i = 0 ; i < 3 ; i++){
            swap(face[LEFT][0][i],face[BACK][0][i]);
        }
        // Color temp[3];
        // for(int i=0;i<3;i++) temp[i]=face[FRONT][0][i];
        // for(int i=0;i<3;i++) face[FRONT][0][i] = face[RIGHT][0][i];
        // for(int i=0;i<3;i++) face[RIGHT][0][i] = face[BACK][0][i];
        // for(int i=0;i<3;i++) face[BACK][0][i] = face[LEFT][0][i];
        // for(int i=0;i<3;i++) face[LEFT][0][i] = temp[i];
    }

    void up(){
        // rotateFaceCounterClockwise(UP);
        // // Color temp[3];
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[FRONT][0][i],face[RIGHT][0][i]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[LEFT][0][i],face[FRONT][0][i]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[LEFT][0][i],face[BACK][0][i]);
        // }
        u();
        u();
        u();
    }

    void d(){
        rotateFaceClockwise(DOWN); 
        for(int i = 0 ; i < 3 ; i++){
            swap(face[FRONT][2][i],face[RIGHT][2][i]);
        }
        for(int i = 0 ; i < 3 ; i++){
            swap(face[LEFT][2][i],face[FRONT][2][i]);
        }
        for(int i = 0 ; i < 3 ; i++){
            swap(face[LEFT][2][i],face[BACK][2][i]);
        }
        // Color temp[3]; 
        // for(int i=0;i<3;i++) temp[i]=face[FRONT][2][i];
    //     for(int i=0;i<3;i++) face[FRONT][2][i] = face[LEFT][2][i];
    //     for(int i=0;i<3;i++) face[LEFT][2][i] = face[BACK][2][i];
    //     for(int i=0;i<3;i++) face[BACK][2][i] = face[RIGHT][2][i];
    //     for(int i=0;i<3;i++) face[RIGHT][2][i] = temp[i];
    }
    
    void dp(){
        // rotateFaceCounterClockwise(DOWN);
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[FRONT][2][i],face[LEFT][2][i]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[RIGHT][2][i],face[FRONT][2][i]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[RIGHT][2][i],face[BACK][2][i]);
        // }
        d();
        d();
        d();
    }

    void r(){
        rotateFaceClockwise(RIGHT);
        for(int i = 0 ; i < 3 ; i++){
            swap(face[FRONT][i][2],face[DOWN][i][2]);
        }
        for(int i = 0 ; i < 3 ; i++){
            swap(face[DOWN][i][2],face[BACK][i][0]);
        }
        for(int i = 0 ; i < 3 ; i++){
            swap(face[UP][i][2],face[BACK][i][0]);
        }
        // Color temp[3];
        // for(int i=0;i<3;i++) temp[i]=face[UP][i][2];
        // for(int i=0;i<3;i++) face[UP][i][2] = face[FRONT][i][2];
        // for(int i=0;i<3;i++) face[FRONT][i][2] = face[DOWN][i][2];
        // for(int i=0;i<3;i++) face[DOWN][i][2] = face[BACK][2-i][0];
        // for(int i=0;i<3;i++) face[BACK][2-i][0] = temp[i];
    }

    void rp(){
        // rotateFaceCounterClockwise(RIGHT);
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[FRONT][i][2],face[UP][i][2]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[UP][i][2],face[BACK][i][2]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[DOWN][i][2],face[BACK][i][0]);
        // }
        r();
        r();
        r();
    }

    void l(){
        rotateFaceClockwise(LEFT);
        for(int i = 0 ; i < 3 ; i++){
            swap(face[FRONT][i][0],face[DOWN][i][0]);
        }
        for(int i = 0 ; i < 3 ; i++){
            swap(face[UP][i][0],face[FRONT][i][0]);
        }
        for(int i = 0 ; i < 3 ; i++){
            swap(face[FRONT][i][0],face[BACK][2-i][2]);
        }
        // Color temp[3];
        // for(int i=0;i<3;i++) temp[i]=face[UP][i][0];
        // for(int i=0;i<3;i++) face[UP][i][0] = face[BACK][2-i][2];
        // for(int i=0;i<3;i++) face[BACK][2-i][2] = face[DOWN][i][0];
        // for(int i=0;i<3;i++) face[DOWN][i][0] = face[FRONT][i][0];
        // for(int i=0;i<3;i++) face[FRONT][i][0] = temp[i];
    }

    void lp(){
        // rotateFaceCounterClockwise(LEFT);
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[FRONT][i][0],face[UP][i][0]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[DOWN][i][0],face[FRONT][i][0]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[DOWN][i][0],face[BACK][i][2]);
        // }
        l();
        l();
        l();
    }

    void f(){
        rotateFaceClockwise(FRONT);
        for(int i = 0 ; i < 3 ; i++){
            swap(face[RIGHT][i][0],face[DOWN][0][2-i]);
        }
        for(int i = 0 ; i < 3 ; i++){
            swap(face[UP][2][i],face[RIGHT][i][0]);
        }
        for(int i = 0 ; i < 3 ; i++){
            swap(face[LEFT][2-i][2],face[UP][2][i]);
        }
        // Color temp[3];
        // for(int i = 0 ; i < 3 ; i++) temp[i] = face[UP][2][i];
        // for(int i = 0 ; i < 3 ; i++) face[UP][2][i] = face[LEFT][2-i][2];
        // for(int i = 0 ; i < 3 ; i++) face[LEFT][i][2] = face[DOWN][0][i];
        // for(int i = 0 ; i < 3 ; i++) face[DOWN][0][i] = face[RIGHT][2-i][0];
        // for(int i = 0 ; i < 3 ; i++) face[RIGHT][i][0] = temp[i];
    }

    void fp(){
        // rotateFaceCounterClockwise(FRONT);
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[RIGHT][i][0],face[UP][2][2-i]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[RIGHT][i][0],face[DOWN][0][i]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[LEFT][i][2],face[DOWN][0][2-i]);
        // }
        f();
        f();
        f();
    }

    void b(){
        rotateFaceClockwise(BACK);
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[RIGHT][i][2],face[UP][0][i]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[DOWN][2][i],face[RIGHT][2-i][2]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[LEFT][i][0],face[DOWN][2][i]);
        // }
        Color temp[3];
        for(int i = 0 ; i < 3 ; i++)temp[i] = face[UP][0][i];
        for(int i = 0 ; i < 3 ; i++)face[UP][0][i] = face[RIGHT][i][2];
        for(int i = 0 ; i < 3 ; i++)face[RIGHT][i][2] = face[DOWN][2][2-i];
        for(int i = 0 ; i < 3 ; i++)face[DOWN][2][i] = face[LEFT][i][0];
        for(int i = 0 ; i < 3 ; i++)face[LEFT][i][0] = temp[2-i];
    }
    
    void bp(){
        // rotateFaceCounterClockwise(BACK);
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[LEFT][i][0],face[UP][0][i]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[DOWN][2][i],face[LEFT][2-i][0]);
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     swap(face[RIGHT][i][2],face[DOWN][2][i]);
        // }
        b();
        b();
        b();
    }

    void setSticker(Face f, int row, int col, Color c){
        face[f][row][col] = c;
    }

    bool operator==(const Cube& other) const{
        for(int f = 0 ; f < 6 ; f++){
            for(int i = 0 ; i < 3 ; i++){
                for(int j = 0 ; j < 3 ; j++){
                    if(face[f][i][j] != other.face[f][i][j])return false;
                }
            }
        }
        return true;
    }

    void move(string s){
        if(s == "U") u();
        else if(s == "U'") up();
        else if(s == "D") d();
        else if(s == "D'") dp();
        else if(s == "R") r();
        else if(s == "R'") rp();
        else if(s == "L") l();
        else if(s == "L'") lp();
        else if(s == "F") f();
        else if(s == "F'") fp();
        else if(s == "B") b();
        else if(s == "B'") bp();
    }

    void PerformAlgo(vector<string>& moves){
        for(const string& it: moves){
            move(it);
        }
    }

    string encode(){
        string state;
        for(int f = 0; f < 6; f++){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    state += char('0' + face[f][i][j]);
                }
            }
        }
        return state;
    }

    bool isSolved(){
        for(int f = 0; f < 6; f++){
            Color center = face[f][1][1];
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(i == 1 && j == 1)continue;
                    if(face[f][i][j] != center) return false;
                }
            }
        }
        return true;
    }

    int heuristic(){
        int wrong = 0;
        for(auto f = 0 ; f < 6 ; f++){
            auto clr = face[f][1][1];
            for(int i = 0 ; i < 3 ; i++){
                for(int j = 0 ; j < 3 ; j++){
                    if(face[f][i][j] != clr)wrong++;
                }
            }
        }return (wrong+7)/8;
    }

    vector<vector<Color>> corner = {
        {WHITE,GREEN,RED}, //UFR
        {WHITE,GREEN,ORANGE},//UFL
        {WHITE,RED,BLUE},//URB
        {WHITE,BLUE,ORANGE},//UBL
        {YELLOW,GREEN,RED},//DFR
        {YELLOW,GREEN,ORANGE},//DFL
        {YELLOW,ORANGE,BLUE},//DLB
        {YELLOW,BLUE,RED}//DBR
    };

    int cheuristic(){
        vector<vector<Color>> corners = {
            {face[UP][2][2],face[FRONT][0][2],face[RIGHT][0][0]},
            {face[UP][2][0],face[FRONT][0][0],face[LEFT][0][2]},
            {face[UP][0][0],face[BACK][0][2],face[LEFT][0][0]},
            {face[UP][0][2],face[BACK][0][0],face[RIGHT][0][2]},
            {face[DOWN][2][2],face[BACK][2][0],face[RIGHT][2][2]},
            {face[DOWN][0][2],face[FRONT][2][2],face[RIGHT][0][2]},
            {face[DOWN][2][0],face[BACK][2][2],face[LEFT][2][0]},
            {face[DOWN][0][0],face[FRONT][2][0],face[LEFT][2][2]}
        };
    }
};

vector<string> inverse(vector<string>& scrbl){
    vector<string> ans(scrbl.rbegin(),scrbl.rend());
    for(auto& it : ans){
        if(it == "R")it = "R'";
        else if(it == "L")it = "L'";
        else if(it == "U")it = "U'";
        else if(it == "D")it = "D'";
        else if(it == "F")it = "F'";
        else if(it == "B")it = "B'";
        else if(it == "L'")it = "L";
        else if(it == "U'")it = "U";
        else if(it == "D'")it = "D";
        else if(it == "F'")it = "F";
        else if(it == "B'")it = "B";
        else if(it == "R'")it = "R";
    }
    return ans;
}

bool areInverse(string a, string b){
    if(a.empty())return false;
    if(a.size() == 1) return (a + "'" == b);
    return string(1,a[0]) == b;
}

vector<string> solve_BFS(Cube& c){
    long long node = 1;
    long long trans = 1;
    vector<string> moves = {"R","R'","L","L'","U","U'","D","D'","F","F'","B","B'"};
    // queue<pair<pair<Cube,vector<string>>,string>> q;
    queue<pair<Cube,vector<string>>> q;
    unordered_set<string> vis;
    q.push({c,{}});
    // q.push({{c,{}},{}});
    vis.insert(c.encode());
    while(!q.empty()){
        // Cube curr = q.front().first.first;
        // vector<string> path = q.front().first.second;
        // string parent = q.front().second;
        Cube curr = q.front().first;
        vector<string> path = q.front().second;
        q.pop();
        if(curr.isSolved()){
            cout << "Nodes:- " << node << endl;
            cout << "Transitions:- " << trans << endl;
            return path;
        }
        for(auto& it : moves){
            // if(areInverse(parent,it))continue;
            trans++;
            Cube nxt = curr;
            nxt.move(it);
            string key = nxt.encode();
            if(!vis.count(key)){
                node++;
                vis.insert(key);
                vector<string> new_path = path;
                new_path.push_back(it);
                // q.push({{nxt,new_path},it});
                q.push({nxt,new_path});
            }
        }
    }
    return {};
}

string resiprocal(string s){
    if(s.size() == 1) return s + "'";
    return string(1,s[0]);
}

vector<string> moves = {"R","R'","L","L'","U","U'","D","D'","F","F'","B","B'"};
bool dfs(Cube& c, int depth, vector<string>& path,long long & node){
    node++;
    if(c.isSolved())return true;
    if(depth == 0)return false;
    for(auto& mv : moves){
        if(!path.empty() && areInverse(path.back(),mv))continue;
        c.move(mv);
        path.push_back(mv);
        if(dfs(c,depth-1,path,node)) return true;
        path.pop_back();
        c.move(resiprocal(mv));
    }
    return false;
}

vector<string> solve_IDDFS(Cube& c){ 
    long long node = 1;
    for(int depth = 0; depth <= 20 ; depth++){
        vector<string> path;
        Cube temp = c;
        if(dfs(temp,depth,path,node)){
            cout << node << endl;
            return path;
        }
    }
    return {};
}

bool search(Cube& c ,int g, int bound, vector<string>& path,long long& node){
    if(c.isSolved())return true;
    int h = c.heuristic();
    if(g+h > bound)return false;
    node++;
    for(auto& mv : moves){
        if(!path.empty() && areInverse(path.back(),mv))continue;
        c.move(mv);
        path.push_back(mv);
        if(search(c,g+1,bound, path,node)){
            return true;
        }
        path.pop_back();
        c.move(resiprocal(mv));
    }
    return false;
}

vector<string> solve_IDA(Cube& c){
    long long node = 0;
    int bound = c.heuristic();
    while(true){
        vector<string> path;
        Cube temp = c;
        if(search(temp,0,bound,path,node)){
            cout << node << endl;
            return path;
        }
        bound++;
    }
    return {};
}

int main(){
    Cube c;
    vector<string> scramble = {"R","U","F","L","D","B","R","U","L","F"};// ,"B","R'","U'"
    c.PerformAlgo(scramble);
    // cout << c.heuristic() << endl;
    auto start = chrono::high_resolution_clock::now();
    // auto ans = solve_BFS(c);
    // auto ans = solve_IDDFS(c);
    auto ans = solve_IDA(c);
    auto end = chrono::high_resolution_clock::now();
    for(auto it : ans){
        cout << it << " ";
    }cout << endl;
    auto duration = chrono::duration_cast<chrono::milliseconds> (end - start).count();
    cout << "Time taken: " << duration / 1000.0 << " seconds\n";
}
