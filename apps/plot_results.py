#!/usr/bin/env python
import json, sys, pprint, re
import matplotlib.pyplot as plt
import numpy as np

fn = sys.argv[1]
print "loading %s"%(fn)
records = json.loads(open(fn,"r").read())

# Compute and extract numbers from output strings
for i in range(0,len(records)):
    e = filter(lambda y: not y == None, map(lambda x: re.search('events\W+= \d+ \((\d+\.\d+)\/sec', x), records[i]['output']))
    assert(len(e) >= 1)
    records[i]['eps_final'] = float(e[-1].group(1))

nthreads = set(map(lambda x: x["nthreads"], records))
names = set(map(lambda x: x["d"], records))


plt.figure()
handles = []
for name in names:
    perf = [];
    print name
    for nt in nthreads: 
        p = np.mean( map(lambda x: x["eps_final"], filter( lambda y:  y["d"]==name and y["nthreads"]==nt, records) ) )
        perf.append(p)
    h, = plt.plot(list(nthreads), perf, label=name)
    handles.append(h)

plt.xlabel("Number of Threads");
plt.ylabel("Events/Sec");
plt.legend(handles=handles)
plt.show()



