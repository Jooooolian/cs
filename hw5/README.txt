// Name: Julian Bartholomee                                                        
// Email: jbp402@psu.edu                                                           
// Due Date: December 10 2018                                                     
// Class: CMPSC 122 - Intermediate Programming Fall 2018                           
// Professor Sukmoon - T, Th: 1:35                                                 
                                                                                
// Description:                                                                    
// This program is an implementaton of a Binary Search Tree. It includes traversal methods, and clear(), insert(), and search()

// Acknowledgement:                                                                
// I used the Data Structures class book for guidence in this assignment.

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Copy the results of "Test 7" and paste it in your readme file,
  and write a discussion about which sorting method is better
  when its input size is large.


Test 7: compare sorting times by selection sort and by building BST
    1) sorting 10 random values
       BstSort      (..) takes 0.000004 secs
       SelectionSort(..) takes 0.000001 secs
       Success
    2) sorting 100 random values
       BstSort      (..) takes 0.000020 secs
       SelectionSort(..) takes 0.000018 secs
       Success
    3) sorting 500 random values
       BstSort      (..) takes 0.000105 secs
       SelectionSort(..) takes 0.000360 secs
       Success
    4) sorting 1000 random values
       BstSort      (..) takes 0.000306 secs
       SelectionSort(..) takes 0.001390 secs
       Success
    5) sorting 5000 random values
       BstSort      (..) takes 0.001244 secs
       SelectionSort(..) takes 0.022020 secs
       Success
    6) sorting 10000 random values
       BstSort      (..) takes 0.002035 secs
       SelectionSort(..) takes 0.089696 secs
       Success
    7) sorting 50000 random values
       BstSort      (..) takes 0.013740 secs
       SelectionSort(..) takes 2.110587 secs
       Success
    8) sorting 100000 random values
       BstSort      (..) takes 0.050169 secs
       SelectionSort(..) takes 8.589718 secs
       Success


We can plainly see that as the size of the sorted array increases, the BST Sort becomes more obviously desirable. However, at smaller sizes of arrays, selection sort is simply less overhead and thus takes less time. This stops somewhere around an input size of 100-500. So unless you are working with more than this interval sized data, selection sort would be recommended to save on time and space. Selection sort is O(n^2), while BST Sort is O(n*log(n)). This is true since the average time to insert to a BST is log(n), 
So if you insert n, then nlog(n). We take the ignorer traversal and the tree is automatically sorted. 


COMPLETE RESULTS:

Test 1: build BST
        init      is success: structure is ()
     1) insert 10 is success: structure is (10)
     2) insert  5 is success: structure is (5,10,_)
     3) insert 20 is success: structure is (5,10,20)
     4) insert  2 is success: structure is ((2,5,_),10,20)
     5) insert  1 is success: structure is (((1,2,_),5,_),10,20)
     6) insert  7 is success: structure is (((1,2,_),5,7),10,20)
     7) insert  4 is success: structure is (((1,2,4),5,7),10,20)
     8) insert  6 is success: structure is (((1,2,4),5,(6,7,_)),10,20)
     9) insert 30 is success: structure is (((1,2,4),5,(6,7,_)),10,(_,20,30))
    10) insert  8 is success: structure is (((1,2,4),5,(6,7,8)),10,(_,20,30))
    11) insert  3 is success: structure is (((1,2,(3,4,_)),5,(6,7,8)),10,(_,20,30))
    12) insert 25 is success: structure is (((1,2,(3,4,_)),5,(6,7,8)),10,(_,20,(25,30,_)))
      expected structure: (((1,2,(3,4,_)),5,(6,7,8)),10,(_,20,(25,30,_)))
    your final structure: (((1,2,(3,4,_)),5,(6,7,8)),10,(_,20,(25,30,_)))
    The above two outputs shuld be the same to each other!

Test 2: search elements
     1) search 10 in BST: success <- found
     2) search 25 in BST: success <- found
     3) search  4 in BST: success <- found
     4) search  7 in BST: success <- found
     5) search  0 in BST: success <- cannot find
     6) search  9 in BST: success <- cannot find
     7) search 15 in BST: success <- cannot find
     8) search 50 in BST: success <- cannot find

Test 3: print preorder
    expected output: 10,5,2,1,4,3,7,6,8,20,30,25,
        your output: 10,5,2,1,4,3,7,6,8,20,30,25,
    The above two outputs shuld be the same to each other!

Test 4: print postorder
    expected output: 1,3,4,2,6,8,7,5,25,30,20,10,
        your output: 1,3,4,2,6,8,7,5,25,30,20,10,
    The above two outputs shuld be the same to each other!

Test 5: print inorder
    expected output: 1,2,3,4,5,6,7,8,10,20,25,30,
        your output: 1,2,3,4,5,6,7,8,10,20,25,30,
    The above two outputs shuld be the same to each other!
    Additionally, both outputs should be sorted!

Test 6: compare sorting results by selection sort and by building BST
    1) sorting { 1 }
       input        : 1,
       solution     : 1,
       BstSort      : 1,
       SelectionSort: 1,
       Success
    2) sorting { 1, 0, 2 })
       input        : 1,0,2,
       solution     : 0,1,2,
       BstSort      : 0,1,2,
       SelectionSort: 0,1,2,
       Success
    3) sorting { 2, 0, 2, 1, 4 })
       input        : 2,0,2,1,4,
       solution     : 0,1,2,2,4,
       BstSort      : 0,1,2,2,4,
       SelectionSort: 0,1,2,2,4,
       Success
    4) sorting { 0, 2, 1, 9, 3, 8, 6, 3, 5, 4, 9, 7, 1, 5 })
       input        : 0,2,1,9,3,8,6,3,5,4,9,7,1,5,
       solution     : 0,1,1,2,3,3,4,5,5,6,7,8,9,9,
       BstSort      : 0,1,1,2,3,3,4,5,5,6,7,8,9,9,
       SelectionSort: 0,1,1,2,3,3,4,5,5,6,7,8,9,9,
       Success

Test 7: compare sorting times by selection sort and by building BST
    1) sorting 10 random values
       BstSort      (..) takes 0.000003 secs
       SelectionSort(..) takes 0.000002 secs
       Success
    2) sorting 100 random values
       BstSort      (..) takes 0.000020 secs
       SelectionSort(..) takes 0.000020 secs
       Success
    3) sorting 500 random values
       BstSort      (..) takes 0.000101 secs
       SelectionSort(..) takes 0.000342 secs
       Success
    4) sorting 1000 random values
       BstSort      (..) takes 0.000225 secs
       SelectionSort(..) takes 0.001361 secs
       Success
    5) sorting 5000 random values
       BstSort      (..) takes 0.001024 secs
       SelectionSort(..) takes 0.021348 secs
       Success
    6) sorting 10000 random values
       BstSort      (..) takes 0.002150 secs
       SelectionSort(..) takes 0.085156 secs
       Success
    7) sorting 50000 random values
       BstSort      (..) takes 0.014480 secs
       SelectionSort(..) takes 2.144888 secs
       Success
    8) sorting 100000 random values
       BstSort      (..) takes 0.039629 secs
       SelectionSort(..) takes 8.485050 secs
       Success

Copy the results of "Test 7" and paste it in your readme file,
  and write a discussion about which sorting method is better
  when its input size is large.