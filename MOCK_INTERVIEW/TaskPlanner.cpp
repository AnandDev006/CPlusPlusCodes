#include <iostream>
#include <vector>

using namespace std;

vector<int> meetingPlanner( const vector<vector<int>>& slotsA, const vector<vector<int>>& slotsB, int dur) 
{
  // your code goes here
  int lenA = slotsA.size();
  int lenB = slotsB.size();
  
  int posA = 0, posB = 0;
  
  // if min(endpoints) - max(startpoints) >= DUR :
  //    return [max(startpoints), max(startpoints) + DUR]
  
  while(posA < lenA && posB < lenB) {
    int start = max(slotsA[posA][0], slotsB[posB][0]);
    int end = min(slotsA[posA][1], slotsB[posB][1]);
    if( end - start >= dur ) {
      return {start, start + dur};
    } else {
      int endA = slotsA[posA][1];
      int endB = slotsB[posB][1];
      if( endA < endB ) {
        posA += 1;
      } else {
        posB += 1;
      }
    }
  }
  
  return {};
}

int main() {
  return 0;
}

/*

  grpA -> A
  grpB -> B
  
  10
  0

slot[x][1] - slot[x][0] < DUR
  invalid slot


|0        15|
                |20            50|
   
   posA = 0
   posB = 0
   
[[10, 50], [60, 120], [140, 210]]
                |

[[0, 15], [60, 70]]
              |    
   
   if min(endpoints) - max(startpoints) >= DUR :
      return [max(startpoints), max(startpoints) + DUR]
   else:
      
