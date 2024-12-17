			                          AARYAN AGAIN
You are given a cake which is a polygon of size n with a cherry at one of its vertices.

You are given an array A which defines the deliciousness of the corresponding vertices.

You are also given a array B denoting the edge length between vertices 
i and i+1 for i = 1 to n-1
i and 1 for i = n. 

Rishabh does not like cherry. So he asked Aaryan to cut a piece of cake which does not have cherries.

To earn points, Aaryan decided to give Rishabh the cake piece with maximum possible deliciousness.

Aaryan will select two vertices and cut the cake piece between the two vertices.
The deliciousness of a cake piece is defined as [ (sum of edges on path between the two vertices which Aaryan will cut) + sum of the deliciousness at the vertices which Aaryan will cut] .


You are then given q queries each containing 2 numbers l and r and signifying that there might be a cherry between l and r.

If l<=r : there is a cherry at one of the vertices l, l+1, .. ,r-1, r 

If l>r : there is a cherry at one of the vertices r, r+1, ..,n,.. ,l-1,l 

Your task is to find the maximum deliciousness Aaryan can offer.

INPUT FORMAT:

N

A1 A2 A3 … AN

B1 B2 B3 … BN

Q

L1 R1

L2 R2

..

LQ RQ


OUTPUT FORMAT:

Q lines, each line containing a single integer, denoting the maximum deliciousness possible for the case.

SAMPLE TEST:

INPUT:

5

3 5 2 1 4

1 1 1 1 1

2

1 3 

2 2


OUTPUT:

6

8

