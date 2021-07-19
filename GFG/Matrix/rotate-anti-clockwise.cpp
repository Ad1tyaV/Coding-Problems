/*

https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/

*/

void rotate(vector<vector<int> >& matrix){
    
    int n = matrix.size();
    int x = 0;
    int y = n-1;
    
    while(x<n){
        
        int x_vertical = x+1;
        int y_vertical = y;
        
        int x_horizontal = x;
        int y_horizontal = y - 1;
        
        while(y_horizontal>=0 && x_vertical<n){

            int temp = matrix[x_vertical][y_vertical];
            matrix[x_vertical][y_vertical] = matrix[x_horizontal][y_horizontal];
            matrix[x_horizontal][y_horizontal] = temp;
            
            
            x_vertical ++;
            y_horizontal--;
            
        }
        
        reverse(matrix[x].begin(), matrix[x].end());
        
        x++;
        y--;
    }
    
    
    
}
