#!/usr/bin/env python
from subprocess import Popen, PIPE
import time, subprocess,sys,json

#apps = [{"name": "Single Sink",
#        "f": "test_sim.py"},
apps =       [{"name": "Multi Sink",
        "f": "test_sim_multi.py"}]

nsinks = [1,2,3,4,5,6,12]
#nthreads = [1,4,8]
nthreads = [1,2,4,8,12,16,20,24,28,32,36,40]
ntrials = 1
py = "/usr/bin/python"
nstat = 20# number of status updates to wait
#nstat = 15# number of status updates to wait
numlines = 2+nstat*7

# detects per second (output of detector block)
dps = 230

# Event loading parameters
ld = 1
l1 = 8
l2 = 5
#ld = 4
#l1 = 20
#l2 = 80

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
