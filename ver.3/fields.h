#ifndef FIELDS_H
#define FIELDS_H

struct fields{
	int **num;
	int	**matrix;
	int	n;
	int completeCount;
	int falseCount;
	int zeroCount;
	int totalCount;
	int falseBilCount;
};
typedef	struct fields field;
#endif