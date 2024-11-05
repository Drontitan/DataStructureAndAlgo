// i we have two different component and we have to tell either this element belong to same component
// the disjoint set will help

// User in dynamic graph  [at any step if anyone will ask if these element belong to same component
// then we will able to answer in constant time ]

// find the parent |  union- >  rank or size  [2 fucntion ]

// union(u,v)  TC -O(4alpha) alpha close to 1 
// find ultimate parent  u & v , pu,pv 
// find parent of pu , pv 
// convert smaller rank to large rank always 

// path compression to directly assign the ultimate parent to that node directly 
// rank should not be reduced in path compression


