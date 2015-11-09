#!/usr/bin/env python
from subprocess import Popen, PIPE
import time, subprocess,sys,json

apps = [{"name": "Single Sink",
        "f": "test_sim.py"},
       {"name": "Multi Sink",
        "f": "test_sim_multi.py"}]

simlen_sec = 30
#nthreads = [1,2,4];
#nthreads = [1,2,3,4,5,6,7,8];
nthreads = [1,2,4,6,8];
ntrials = 2
py = "/usr/bin/python"
nstat = 10 # number of status updates to wait
numlines = 2+nstat*7

records = []
for nt  in nthreads:
    for trial in range(0,ntrials):
        for app in apps:
            print "RUNNING", nt, trial, app           
            p = subprocess.Popen([py, app['f'], '--nthreads=%d'%(nt)], stdout=subprocess.PIPE)
            op = []
            for i in range(0,numlines):
                o = p.stdout.readline() 
                op.append(o)
            print op
            p.kill()
            print "DONE"
    
            records.append(
                {"nthreads":nt,
                 "trial":trial,
                 "f":app["f"],
                 "d":app["name"],
                  "output":op} 
                    )

print "WRITING RESULTS!"
outf = open("stats.dat","w")
outf.write( json.dumps(records) )
print "finished..."
