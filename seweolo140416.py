import sys
import os
import re

if len(sys.argv) < 3:
	print("python 'Network' '[How to insert into markdown](www.github.com/agavrel)' '{optional}Author'")
	exit()

topic = sys.argv[1]
pattern = "### 0x[0-9a-f][0-9af] " + topic
filename="README.md"
s = r"cat "+ filename +" | grep -n '" + pattern + "' " + filename + " | awk -F ':' '/0/ {print$1}'"
print(s)
pattern = re.compile("###")

stream = os.popen(s)
lineNb = int(stream.read().rstrip())

with open(filename, "r") as f:
	for _ in range(lineNb):
        	next(f)
	for line_i, line in enumerate(f, 1):
		if re.search(pattern, line):
			index = line_i + lineNb - 1
			print( "%d\n" % index )
			break
	
with open(filename, "r") as f:
	contents = f.readlines()
	s = "**" + sys.argv[2] + "** | :star::star::star: |"
	if len(sys.argv) > 3:
		s += " *by " + sys.argv[3] + "*"
	contents.insert(index - 2, s + "\n")
	
with open(filename, "w") as f:
	contents = "".join(contents)
	f.write(contents)


s = "grep -C 4 -F '" + sys.argv[2] + "' README.md"
print(s)
os.system(s)


# if writing to a different file
#outputFileName="b.md"
#f2 = open(outputFileName, "r")
#contents = f2.readlines()
#f2.close()
#f2 = open(outputFileName, "w")
#contents = "".join(contents)
#f2.write(contents)
#f2.close()

