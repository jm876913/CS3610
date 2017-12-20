#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void swap(vector<int>& list, int a, int b){
  int temp = list[a];
  list[a] = list[b];
  list[b] = temp;
}

int partition(vector<int>& list, int first, int last) {
  // The pivot should be the median of the
  // first, middle, and last elements.
  int pivot;
  int index, smallindex;

  swap(list, first, (first+last)/2); // takes the middles, swaps witht he first

  pivot = list[first];
  smallindex = first;

  for(index = first+1; index <= last; index++){ // cases 1 and 2 move to the next
    if(list[index] < pivot){
      smallindex++;
      swap(list, smallindex, index);// throws the current element into a smaller list
    }
    //swap(first, smallindex);
  }
  swap(list, first, smallindex); // settles the pivot
  return smallindex;

}


void quicksort(vector<int>& list, int first, int last) { //nlgn time complex
  if(first >= last){
    return;
  }
  else{
   int j = partition(list, first, last);// partition into 2 parts
   quicksort(list, first, j-1);//recursve sort of the left sub array
   quicksort(list, j+1, last);// recursive sort of the right sub array
  }
}

void multiway_merge(vector<vector<int> >& input_lists, vector<int>& output_list) 
{
  output_list.clear(); //clearing output list
  int num;
  int index = 0;

  /*cout << "sorted list" << endl;
  for(int index = 0; index < input_lists.size(); index++) {
    for(int n = 0; n < input_lists.size(); n++) {
      cout << input_lists[index][n] << " ";
    }
    cout << endl;
  }*/
  priority_queue<int, vector<int>, greater<int> > que; //creating a priority queue to easily manage list
  const int size = input_lists.size();
  //size = input_lists.size();
  int I_array[size];// making a place holder

  while(index < size){ //filling the queue with the first element of each array
    //index = 0;
    que.push(input_lists[index][0]);
    I_array[index] = 0;
    index++;
  }
  

  while(!que.empty()){// getting the smallest number and moving it to the output_list
    num = que.top();
    que.pop();
    output_list.push_back(num);

    for(index = 0; index<size; index++){//get element of the pop num
      if(I_array[index] < size && num ==input_lists[index][I_array[index]]){
        I_array[index]++;
        que.push(input_lists[index][I_array[index]]);
      }
    }
  }

} 

int main(int argc, char** argv) {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > input_lists(n, vector<int>(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> input_lists[i][j];
    }
  }

  // Quicksort k sublists
  for (int i = 0; i < input_lists.size(); ++i)
    quicksort(input_lists[i], 0, m-1);

  // Merge n input sublists into one sorted list
  vector<int> output_list(n * m);
  multiway_merge(input_lists, output_list);

  for (int i = 0; i < output_list.size(); ++i)
    cout << output_list[i] << " ";
  cout << endl;
}
