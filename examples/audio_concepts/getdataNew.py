#!/usr/bin/python

layers ={}
bias = {}
rowcolumn = {}
layer = 0
index = 0
arrayCurrent = 0
arrayline = []
arraylen = 0
array = []
baisnumber = 0


def getlayerweight( row,  col,  start):
    #print "row\t",  row, "col\t", col, "i\t", start
    for m in range(start, start + int(row)):
        column = 0
        for value in array[m].split() :
            layers[index,  m - start,  column] = value
            column= column+ 1;
            f.write("    data: "+value+"\n");
    return;

def getbais(startbias):
		tempbaisarray = []
		for bais in array[startbias].split():
				 tempbaisarray.append(bais);
		for b in range(0,  int(baisnumber)):
				bias[index - 1, b] = tempbaisarray[b + 2]
				f.write("    data: "+tempbaisarray[b + 2]+"\n");
		return;


with open("trainedMLP2NetWoSOFTMAX", "r") as f:
  for line in f:
    array.append(line)
array_len = len(array)

f = open("output.txt", "w")

for i in range(0,  array_len):
		
		token = []
		for float in array[i].split():
				token.append(float)
		if token[0] == 'm':
				row = token[1]
				col = token[2]
				#print "row\t",  row, "col\t", col, "i\t", i
				f.write("layer \t"+str(index)+"\n\n")
				getlayerweight(row,  col, i+1)
				index = index+1
        
		elif token[0]=='v':
				#print "v\t", i
				f.write("bias \t"+str(index)+"\n\n")
				baisnumber = token[1]
				getbais(i);

f.close()
