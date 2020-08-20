def f(n):
	ra, rb = 0, 1
	a, b = 1, 0
	while n > 0:
		if n % 2 == 1:
			ra2, rb2 = ra * a, rb * b
			ra, rb = ra2 + rb * a + ra * b, ra2 + rb2
		a2, b2 = a * a, b * b
		a, b = a2 + b2 * 2, a2 + b2
		n //= 2
	return ra

n = int(1e7)
import time
t0 = time.time()
fn = f(n)
print(time.time() - t0)