/*
  Find the Town Judge [LeetCode 997]
  In a town, there are N people labelled from 1 to N.  There is a rumor that
  one of these people is secretly the town judge.
  
  If the town judge exists, then:
  The town judge trusts nobody.
  Everybody (except for the town judge) trusts the town judge.
  There is exactly one person that satisfies properties 1 and 2.
  You are given trust, an array of pairs trust[i] = [a, b] representing that the person
  labelled a trusts the person labelled b.
  If the town judge exists and can be identified, return the label of the town judge.
  Otherwise, return -1.
  
  Input: N = 2, trust = [[1,2]]
  Output: 2
  Input: N = 3, trust = [[1,3],[2,3]]
  Output: 3
  Input: N = 3, trust = [[1,3],[2,3],[3,1]]
  Output: -1
*/

/*
  Indegree of Judge should be N-1 and outdegree = 0.
  We maintain it in a vector of pairs.
*/

int findJudge( int N, vector<vector<int>>& trust ) {
  vector< pair<int,int> > degrees(N, { 0, 0 } ); // vector of pairs <indegree, outdegree>
  
  for( auto t : trust ) {
    ++degrees[ t[1]-1 ].first;
    ++degrees[ t[0]-1 ].second;
  }
  
  for( int i=0; i<N; i++ )
    if( degrees[i].first == N - 1 && degrees[i].second == 0 ) return i+1;
  return -1;
}
