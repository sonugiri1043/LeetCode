/*  No of Connected Components // Accounts merge Leetcode - 721

    Given a list accounts, each element accounts[i] is a list of strings, where the
    first element accounts[i][0] is a name, and the rest of the elements are emails
    representing emails of the account.

    Now, we would like to merge these accounts. Two accounts definitely belong to the same
    person if there is some email that is common to both accounts.

    Simple Example:
    
    a b c // now b, c have parent a
    d e f // now e, f have parent d
    g a d // now abc, def all merged to group g

    parents populated after parsing 1st account: a b c
    a->a
    b->a
    c->a

    parents populated after parsing 2nd account: d e f
    d->d
    e->d
    f->d

    parents populated after parsing 3rd account: g a d
    g->g
    a->g
    d->g
*/

class Solution {
public:
  int find( vector<int>& parent, int i) {
    while( parent[i] != i)
      i = parent[i];
    return i;
  }
    
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    vector<int> parent(n); // groups 0 ... n-1
    unordered_map<string, int> email_id; // email -> group
    
    for (int i = 0; i < n; i++) {
      parent[i] = i; // init parent
      for( int j=1; j < accounts[i].size(); j++ ) {
	string email = accounts[i][j];
	if( email_id.find( email ) != email_id.end() ) {
	  // Union
	  int root1 = find( parent, i );
	  int root2 = find( parent, email_id[email] );
	  parent[ root1 ] = root2;
	} else {
	  email_id[ email ] = i;
	}
      }
    }
    
    // We make a new map in order to store for every group the e-mails it contains
    unordered_map<int, vector<string>> mres;
    for( auto it : email_id ) {
      int root = find( parent, it.second );
      mres[root].push_back( it.first );
    }
        
    // In the previous (mres) map we have our answer but we must give the proper structure
    // We add the name of the account (we retieve it from the initial vector since we have
    // the number of the group) and we sort the e-mails.
    vector<vector<string>> res;
    for (auto it : mres) {
      sort(it.second.begin(), it.second.end());
      vector<string> tmp = {accounts[it.first][0]};
      for (auto i : it.second) tmp.push_back(i);
      res.push_back(tmp);
    }
    return res;
  }
};
