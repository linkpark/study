# !/usr/bin/python
# Filename: sort.py

def bubbleSort(sortList):
	n = len(sortList);
	for i in range(0,n):
		for j in range(i+1,n):
			if sortList[i] > sortList[j]:
				tmp = sortList[i];
				sortList[i] = sortList[j];
				sortList[j] = tmp;
			else:
				continue;
		else:
			continue;
	else:
		return sortList;
	
list = [2,8,1,3,19,23,121,4,21,33,11];
list = bubbleSort(list);
print list;

