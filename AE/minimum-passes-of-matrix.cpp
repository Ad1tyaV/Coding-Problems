/*

AlgoExpert - Minimum Passes Of Matrix

*/

#include <vector>
using namespace std;

int minimumPassesOfMatrix(vector<vector<int>> matrix) {
  
	set<pair<int, int>> track;
	vector<vector<int>> _matrix(matrix.size(), vector<int>(matrix[0].size(), 0));
	int ans = 0;
	
	for(int i=0; i<matrix.size(); i++){		
		for(int j=0; j<matrix[i].size(); j++){	
			_matrix[i][j] = matrix[i][j];
			if(matrix[i][j]<0)
				track.insert({i, j});			
		}		
	}
	int prevSize = track.size();
	// int ans = 0;
	while(track.size()){
		ans++;
		// cout<<"track="<<track.size()<<endl;		
		
		for(auto it = track.begin(); it!=track.end();){
			
			int x = it->first;
			int y = it->second;
												
			//Check Top			
			if(x>0){
				if(matrix[x-1][y]>0){					
					_matrix[x][y]*=-1;
					it = track.erase(it);					
					if(track.size()==0)
						break;
					
					continue;
				}
			}
			if(x+1<matrix.size()){ //Check down				
				if(matrix[x+1][y]>0){					
					_matrix[x][y]*=-1;
					it = track.erase(it);					
					
					if(track.size()==0)
						break;
					
					continue;
				}					
			} 
			if(y>0){ //Check left				
				if(matrix[x][y-1]>0){					
					_matrix[x][y]*=-1;
					it = track.erase(it);
					
					if(track.size()==0)
						break;
					
					continue;
				}
			}
			//Check right
			if(y+1<matrix[0].size()){
				
				if(matrix[x][y+1]>0){					
					_matrix[x][y]*=-1;
					it = track.erase(it);
				
					if(track.size()==0)
						break;
				
					continue;
					
				}				
			}
			
			it++;
		}
		if(prevSize==track.size())
			return -1;
		
		prevSize = track.size();
		
		for(int i=0;i<matrix.size(); i++){
			for(int j=0;j<matrix[i].size(); j++){
				matrix[i][j] = _matrix[i][j];
			}
		}
		
		
	}
	
	
  return ans;
}
