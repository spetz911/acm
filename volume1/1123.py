
import sys




def solve():
	ll = sys.stdin.readline().rstrip()

	if ll == ll[::-1]:
		return ll

	data = [int(x) for x in ll]

	s = ll

	center = None

	half = len(ll)//2

	data_rev = data[::-1]
	ll_rev = data[:len(s)//2:-1]

	num_left = int(ll[len(s)//2-1::-1])
	num_right = int(ll[(len(s)+1)//2:])

	num_orig = int(ll)

	condx = num_left < num_right

	# print("num_str1:", num_left)
	# print("num_str2:", num_right)

	if condx:
		if len(ll) % 2:
			num_orig += 10 ** half
		else:
			num_orig += 10 ** half


	# print (num_orig)

	num_str = str(num_orig)


	# print("num_str1:", num_str[:half])
	# print("num_str2:", num_str[half-1::-1])

	res = None

	if len(ll) % 2:
		res = num_str[:half+1] + num_str[half-1::-1]
	else:
		res = num_str[:half] + num_str[half-1::-1]

	return res


print (solve())



# data_xxx = 

# less1 = True
# for a,b in zip(data, data_rev):
# 	if a<b:
# 		less1 = False

# less = data < data_rev


# if len(ll) % 2:
# 	# not odd
# 	x = int(ll[len//2])
# 	center
# else:
# 	x1 = int(ll[len//2])
# 	x2 = int(ll[len//2+1])




