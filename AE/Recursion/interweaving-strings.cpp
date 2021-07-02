using namespace std;

bool recurse(string one, string two, string three, int first, int second, int third){
	
	if(first==one.size() && second==two.size() && third==three.size())
		return true;
	
	if(one[first]==three[third] && two[second]==three[third])
		return recurse(one, two, three, first+1, second, third+1) || recurse(one, two, three, first, second+1, third+1);
	
	if(one[first]==three[third])
		return recurse(one, two, three, first+1, second, third+1);
	
	if(two[second]==three[third])
		return recurse(one, two, three, first, second+1, third+1);
	
	return false;
}

bool interweavingStrings(string one, string two, string three) {
  
	return recurse(one, two, three, 0, 0, 0);
	
  return false;
}
