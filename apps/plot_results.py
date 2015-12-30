#!/usr/bin/env python
import json, sys, pprint, re
import matplotlib.pyplot as plt
import numpy as np

#metric = "e_final"
#metric = "eps_final"
metrics = ["e_final", "eps_final"]

fn = sys.argv[1]
print "loading %s"%(fn)
records = json.loads(open(fn,"r").read())

# Compute and extract numbers from output strings
for i in range(0,len(records)):
    e = filter(lambda y: not y == None, map(lambda x: re.search('events\W+= (\d+) \((\d+\.\d+)\/sec', x), records[i]['output']))
    print len(e)
    if(len(e) >= 1):
        records[i]['e_final'] = float(e[-1].group(1))
        records[i]['eps_final'] = float(e[-1].group(2))

records = filter(lambda x: x.has_key("eps_final"), records);
nsinks = sorted(list(set(map(lambda x: x["nsinks"], records))))
nthreads = sorted(list(set(map(lambda x: x["nthreads"], records))))
names = set(map(lambda x: x["d"], records))

plt.figure()
handles = []

for metric in metrics:
    plt.figure()
    for name in names:
        for ns in nsinks: 
            perf = [];
            lbl = "Nsinks = %d"%(ns)
            for nt in nthreads: 
                p = np.mean( map(lambda x: x[metric], filter( lambda y:  y["d"]==name and y["nthreads"]==nt and y["nsinks"]==ns, records) ) )
                perf.append(p)
            print len(nthreads), len(perf)
            h, = plt.plot(nthreads, perf, label=lbl)
        print nthreads,perf
        handles.append(h)
    
    plt.xlabel("Number of Threads");
    plt.ylabel("%s"%(metric));
    ax = plt.subplot(111)
    handles, labels = ax.get_legend_handles_labels()
    ax.legend(handles, labels)
#plt.legend(handles=handles)
plt.show()



