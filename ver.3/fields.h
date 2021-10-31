#ifndef FIELDS_H
#define FIELDS_H

struct fields{
	int **num;
	int	**matrix;
	int	n;
	int completeCount;
	int falseCount;
};
typedef	struct fields field;
#endif