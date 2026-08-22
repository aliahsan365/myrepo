#include <iostream>
#include <vector>
using namespace std;

int solutions = 0;

// N Towers placed on a NxN chessboard without threading each other.

// Key idea: To use both unidimensional array position and content to represent
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

// Checks the constraint: no two towers placed on the same row.
bool check_left_row(const vector<int> &sol, int depth, int pos) {
  int n = sol.size();
  for (int i = 0; i < depth; ++i) {
    if (sol[i] == pos)
      return false;
  }
  return true;
}

// Different aproach by avoing repetitions by checking solution array from 0 to
// depth on each call. We prune recursion tree by using check_left_row. This
// improve the runtime. This way we avoid all possible permutations
void permutation_with_backtraking(int depth, vector<int> &sol) {
  int N = sol.size();
  for (int i = 0; i < N; ++i) {
    if (check_left_row(sol, depth, i)) {
      sol[depth] = i;
      permutation_with_backtraking(depth + 1, sol);
    }
  }
  if (depth == N - 1) { // At this point you already know the solution.
    ++solutions;        // Only a valid solution is counted.
    print_pretty_board(sol);
  }
}

int main() {
  int N = 8;
  vector<int> sol(N, -1);
  permutation_with_backtraking(0, sol);
  cout << "number of solutions founded: " << solutions << endl;
  return 0;
}