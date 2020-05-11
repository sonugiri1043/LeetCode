/*
  An image is represented by a 2-D array of integers, each integer representing the
  pixel value of the image (from 0 to 65535).

  Given a coordinate (sr, sc) representing the starting pixel (row and column) of the
  flood fill, and a pixel value newColor, "flood fill" the image.

  To perform a "flood fill", consider the starting pixel, plus any pixels connected
  4-directionally to the starting pixel of the same color as the starting pixel,
  plus any pixels connected 4-directionally to those pixels (also with the same
  color as the starting pixel), and so on. Replace the color of all of the
  aforementioned pixels with the newColor.

  At the end, return the modified image.
  
  Example 1:
  Input: 
  image = [[1,1,1],[1,1,0],[1,0,1]]
  sr = 1, sc = 1, newColor = 2
  Output: [[2,2,2],[2,2,0],[2,0,1]]
  Explanation: 
  From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
  by a path of the same color as the starting pixel are colored with the new color.
  Note the bottom corner is not colored 2, because it is not 4-directionally connected
  to the starting pixel.
 */

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if( newColor == image[sr][sc] )
      return image;
        
    int m = image.size(), n = image[0].size(), i, j;
    int origColor = image[sr][sc];

    queue< pair<int,int> > q;
    q.push( {sr,sc} );
    image[sr][sc] = newColor;
    while( !q.empty() ) {
      auto t = q.front(); q.pop();
      i = t.first; j = t.second;
      if( i-1 >= 0 && image[i-1][j] == origColor ) {
	q.push( {i-1, j} );
	image[i-1][j] = newColor;
      }
      if( j-1 >= 0 && image[i][j-1] == origColor ) {
	q.push( {i, j-1} );
	image[i][j-1] = newColor;
      }
      if( i+1 < m && image[i+1][j] == origColor ) {
	q.push( {i+1, j} );
	image[i+1][j] = newColor;
      }
      if( j+1 < n && image[i][j+1] == origColor ) {
	q.push( {i, j+1} );
	image[i][j+1] = newColor;
      } 
    }
    return image;
  }
};
