// Student ID: 20274909

#include "Set.h"
#include <iostream>

using namespace std;

int main()
{

   const int NUM_ENTRIES = 3; // What happens if this is 0?

   vector<int> master;
   size_t master_total = 0;
   for (size_t i = 0; i < NUM_ENTRIES; i++) {
      int val = rand() % 300;
      master_total += val;
      master.push_back(val);
   }

   // Select an arbitrary target.
   size_t target = master_total / 2;

   //vector<int> master = { 11, 3, 6, 20, 9 };

   //size_t target = 19;

   Set<int> master_set(&master);
   Set<int> best_subset = master_set.find_biggest_subset_le(target);

   cout << "Target = " << target << endl;
   cout << "Best sum = " << best_subset.get_sum() << endl;
   cout << best_subset << endl;
}
