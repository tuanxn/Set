// Student ID: 20274909

#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

#ifndef Set_h
#define Set_h

template <typename T>
class Set {
private:
   vector<T>* _master_ptr;
   vector<size_t> _elems; // List of indices into this->master
   size_t _sum;

public:
   Set(vector<T>* mast_ptr = nullptr) : _master_ptr(mast_ptr), _sum(0) {}

   const size_t size() const { return _elems.size(); }
   const vector<T>* get_master_ptr() const { return _master_ptr; }
   const size_t get_sum() const { return _sum; }

   bool add_elem(size_t n) { // n is the index in master
      if (_master_ptr == nullptr) {
         return false;
      }
      else if (n < 0 || n >= _master_ptr->size()) {
         return false;
      }
      else {
         _elems.push_back(n);
         _sum = get_sum() + _master_ptr->at(n);
         return true;
      }
   }

   bool add_all_elems() {   // Add everything in the master
      if (_master_ptr == nullptr) {
         return false;
      }
      else if (_master_ptr->empty()) {
         return false;
      }
      else {
         for (size_t i = 0; i < _master_ptr->size(); i++)
            add_elem(i);
         return true;
      }
   }

   Set<T> find_biggest_subset_le(size_t target) {
      if (target == 0) {
         return Set<T>();
      }
      else if (_master_ptr == nullptr) {
         return Set<T>();
      }
      else if (add_all_elems() && _sum <= target) {
         return *this;
      }
      else {
         vector<Set<T>> candidates = { Set<T>(_master_ptr) };
         Set<T> biggest_subset = Set<T>(_master_ptr);
         for (size_t i = 0; i < _master_ptr->size(); i++) {
            size_t candidates_size = candidates.size();
            for (size_t j = 0; j < candidates_size; j++) {
               if (candidates[j].get_sum() + _master_ptr->at(i) == target) {
                  if (candidates[j].add_elem(i))
                  return candidates[j];
               }
               else if (candidates[j].get_sum() + _master_ptr->at(i) < target) {
                  Set<T> temp = candidates[j];
                  
                  if (temp.add_elem(i))
                     candidates.push_back(temp);
                  if (temp.get_sum() > biggest_subset.get_sum())
                     biggest_subset = temp;
               }
            }
         }
         return biggest_subset;
      }
   }

   friend ostream& operator<<(ostream& os, const Set<T>& set) {
      const vector<T>* mast_ptr = set.get_master_ptr();

      os << "{\n";
      if (mast_ptr->empty()) {
         os << "\n"; // check this
      }
      else {
         for (size_t index : set._elems)
            os << " " << mast_ptr->at(index) << "\n";
      }
      return os << "}";
   }

   friend class Tests; // Don't remove this line
};


#endif
