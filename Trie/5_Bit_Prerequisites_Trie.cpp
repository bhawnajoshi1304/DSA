// 32 bit or 64 bit number
// XOR 1^0=1 0^1=1 1^1=0 0^0=1
// xth bit is set: (n>>x) & 1
// set a bit at x position: n | (1<<x)
// unset a bit at x position: n & ~(1 << x);
// flip the bit at x position: n ^ (1 << x);