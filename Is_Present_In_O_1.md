## Problem
Design a data structure which takes only space of two arrays of size n.
Operations needed:
 - insert(a), where 0 <= a <n
 - isPresent(a), returns true/false
 - clearAll(), resets all the value i.e. isPresent(a) = false for all a
 - pre Processing

## Solution
  We will use a reference variable ( ref_index ) which indicate how many elements have been
  inserted. This would start from -1, meaning no element has been inserted.
  Whenever an element is inserted we increment ref_index and store the element 'a' at index ref_index.
  In other half array, n - 2n - 1, we store the index where a is stored.

## Pseudo code

```c++
  int arr[2n];
  int ref_index = -1;
  void insert( int a ) {
     if ( ! isPresent( a ) ) {
        ref_index = ref_index + 1;
        arr[ ref_index ] = a;
        arr[ n + a ] = ref_index;
     }
  }

  bool isPresent( int a ) {
     int index = arr[ n + a ];
     if ( ref_index >= index ) {
        if ( arr[ index ] == a ) {
           return true;
        }
     }
     return false;
  }

  void clearAll() {
     ref_index = -1;
  }

  void preProcess():{
     ref_index = -1;
  }
```