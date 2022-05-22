The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of the previously selected activity. We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.
1) Sort the activities according to their finishing time 
2) Select the first activity from the sorted array and print it. 
3) Do the following for the remaining activities in the sorted array. 
…….a) If the start time of this activity is greater than or equal to the finish time of the previously selected activity then select this activity and print it.
In the following C implementation, it is assumed that the activities are already sorted according to their finish time.

Time Complexity: It takes O(n log n) time if input activities may not be sorted. It takes O(n) time when it is given that input activities are always sorted.