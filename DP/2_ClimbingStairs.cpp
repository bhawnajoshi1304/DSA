// ways to climb stairs: climb 1 stair or climb 2 stair.
// ways to be at stair 0: 1 (0 climb)
// ways to be at stair 1: 1 (climb 1 stair from 0)
// ways to be at stair 2: 2 (climb 2 stairs from 0, climb 1 stair from 1)
// ...
// ...
// ways to be at stair n: f(n-1) + f(n-2) (ways to reach from 1 stair back + ways to reach from 2 stairs back)
// Fibonacci solution

// Modification to q: Allowed climbs 1 stair or 3 stair:
// Recurrence relation = f(n-1) + f(n-3)


// WRITING RECURRENCE RELATION
// 1. Try to represent in terms of index
// 2. Do some stuff on indexes
// 3. To count no. of ways => sum of stuff
//    To find best way => min/max of stuff