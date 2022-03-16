#ifndef TYPE_H
#define TYPE_H

typedef int Type;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B)  \
	{               \
		Type t = A; \
		A = B;      \
		B = t;      \
	}
#define compexch(A, B) \
	if (less(B, A)) exch(A, B)

#endif
