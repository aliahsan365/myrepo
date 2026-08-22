#include <iostream>
#include <vector>
using namespace std;

int counter = 0;
int solutions = 0;

// N Towers placed on a NxN chessboard without threading each other.

// Key idea: To use both unidimensional array position  and content to represent
// tower position (i,j) on a chessboard.

void print_pretty_board(const vector<int> &v) {
  int N = v.size();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (v[i] == j) {
        cout << "T";
      } else {
        cout << "X";
      }
    }
    cout << endl;
  }
  cout << endl;
}
// A solution is only acceptable if and only if there is no repetitions within
// the unidimensional array. This means, no two towers on the same row.
bool check_constraint_all_different(const vector<int> &sol) {
  int N = sol.size();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      // DO NOT  compare with itself. Obiously, we allow to be the same in this
      // case.
      if (i != j) {
        if (sol[i] == sol[j])
          return false;
      }
    }
  }
  return true;
}

// Pure computation of ALL permutations, using backtracking, with no heuristics
// and no extra structures.
void permutation_with_backtraking(int depth, vector<int> &sol) {
  int N = sol.size();
  if (depth == N) {
    ++counter;
    if (check_constraint_all_different(sol)) {
      print_pretty_board(sol);
      ++solutions;
    }
  }
  for (int i = 0; i < N; ++i) {
    if (depth < N) {
      sol[depth] = i;
      permutation_with_backtraking(depth + 1, sol);
    }
  }
}

int main() {
  int N = 4;
  vector<int> sol(N, -1);
  permutation_with_backtraking(0, sol);
  cout << "number posible solutions checked: " << counter << endl;
  cout << "number of solutions founded: " << solutions << endl;
}