/*
    2-3 Trees are the simplest kind of balanced search trees
    Balanced search trees are trees that are guaranteed to have a height of O(log n)
    A height of O(log n) means that the worst case scenario for searching for a node in the tree is O(log n)
    This height is optimal compared to a standard binary search tree which has a worst case scenario of O(n)
    Deleting and inserting nodes in a 2-3 tree is also O(log n) in the worst case scenario

    Why is a 2-3 Tree optimal to a regular binary search tree:
        1) better worst case scenario of O(log n) compared to O(n)
        2) better average case scenario of O(log n) compared to O(n)

    Disadvantages of a 2-3 Tree:
        1) More complex
        2) Worse best case scenario of O(log n) compared to O(1) for a regular BST
        3) Worse constant factor compared to a regular BST

    General Notes:
        1) 2-3 trees heavily utilize merge sort, which is beneficial for the average case scenario
        2) 2-3 trees are not as good for the best case scenario
        3) 2-3 trees are good for worst case scenario 


*/