/*

https://leetcode.com/problems/min-cost-to-connect-all-points/

*/

struct Point{
    int x;
    int y;
    Point(){}
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

struct PairOfPoints{

    Point firstPoint;
    Point secondPoint;
    int distance;

    int computeDistance(Point firstPoint, Point secondPoint){

        return abs(firstPoint.x - secondPoint.x) + abs(firstPoint.y - secondPoint.y);

    }

    PairOfPoints(Point firstPoint, Point secondPoint){
        this->firstPoint = firstPoint;
        this->secondPoint = secondPoint;
        this->distance = computeDistance(firstPoint, secondPoint);
    }

};

struct Cmp{

    public :
    bool operator()(PairOfPoints p1, PairOfPoints p2){

        return p1.distance>p2.distance;

    }

};

bool compareEquality(Point p1, Point p2){
    
    return p1.x==p2.x && p1.y==p2.y;
    
}


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int answer = 0;
        
        if(points.size()==1)
            return 0;
        
        if(points.size()==2)
            return abs(points[0][0]-points[1][0]) + abs(points[0][1]-points[1][1]);
        
        map<pair<int, int>, bool> visited;        
        
        
        priority_queue<PairOfPoints, vector<PairOfPoints>, Cmp> nextNearest;

        for(int i=1; i<points.size(); i++){
            nextNearest.push(PairOfPoints({points[0][0], points[0][1]}, {points[i][0], points[i][1]}));            
        }

        while(nextNearest.size()){

            PairOfPoints front = nextNearest.top();
            nextNearest.pop();
            
            visited[make_pair(front.firstPoint.x, front.firstPoint.y)] = true;            
            
            if(visited.find({front.secondPoint.x, front.secondPoint.y})!=visited.end())
                continue;

                        
            answer += front.distance;            

            for(int i=0; i<points.size(); i++){

                if(!(front.firstPoint.x == points[i][0] && front.firstPoint.y == points[i][1])){
                    
                    if(visited.find( {points[i][0], points[i][1]} ) == visited.end())
                        nextNearest.push( PairOfPoints(Point(front.secondPoint.x, front.secondPoint.y), Point(points[i][0], points[i][1])));
                    
                }
            }
            


        }
        
        return answer;

    }
};
