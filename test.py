#!/usr/bin/python3
from itertools import product


def main():
	M = [int(x) for x in input().split()]
	
	c = 0;
	ololo = True;
	while 42:
		c += 1;
		delta = [ abs(x1 - x2) for (x1,x2) in product(M,M)]
		print("delta = ", M)
		non_zero = [x for x in delta if x != 0 ]
		if delta.count(0) > len(M):
			print(c)
			return
		M.append( min(non_zero))
	

	return 0;


main()
