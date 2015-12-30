#!/usr/bin/env python
from subprocess import Popen, PIPE
import time, subprocess,sys,json

#apps = [{"name": "Single Sink",
#        "f": "test_sim.py"},
apps =       [{"name": "Multi Sink",
        "f": "test_sim_multi.py"}]

nsinks = [1,2,4]
nthreads = [1,2,4]
ntrials = 1
py = "/usr/bin/python"
nstat = 5# number of status updates to wait
#nstat = 15# number of status updates to wait
numlines = 2+nstat*7

# detects per second (output of detector block)
#dps = 50.0 
dps = 500.0 

# Event loading parameters
ld = 10
l1 = 50
l2 = 100

records = []
for ns in nsinks:
  for nt  in nthreads:
    for trial in range(0,ntrials):
      for app in apps:
            t1 = time.time()
            print "RUNNING nsink=%d, nthread=%d, trial=%d, app=%s"%(ns,nt,trial,app)
            p = subprocess.Popen([py, app['f'], '--nsinks=%d'%(ns), '--nthreads=%d'%(nt), "--dps=%f"%(dps), "--l1=%f"%(l1), "--l2=%f"%(l2), "--ld=%f"%(ld)], stdout=subprocess.PIPE)
            op = []
            for i in range(0,numlines):
                o = p.stdout.readline() 
                op.append(o)
            print op
            p.kill()
            t2 = time.time()
            print "DONE (elapsed = %f sec)"%(t2-t1)
    
            records.append(
                {"nsinks":ns, "nthreads":nt,
                 "trial":trial,
                 "f":app["f"],
                 "d":app["name"],
                  "output":op} 
                    )

print "WRITING RESULTS!"
outf = open("stats.dat","w")
outf.write( json.dumps(records) )
print "finished..."
