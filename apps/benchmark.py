#!/usr/bin/env python
from subprocess import Popen, PIPE
import time, subprocess

apps = [{"name": "Single Sink",
        "f": "test_sim.py"},
       {"name": "Multi Sink",
        "f": "test_sim_multi.py"}]

simlen_sec = 30
nthreads = [1,2,3,4,5,6,7,8];
ntrials = 2
py = "/usr/bin/python"
for nt  in nthreads:
    for trial in range(0,ntrials):
        for app in apps:
            print "RUNNING", nt, trial, app           
            p = subprocess.Popen([py, app['f'], '--t=%d'%(simlen_sec), '--nthreads=%d'%(nt)], stdout=subprocess.PIPE)
            #p = subprocess.Popen([py, app['f'], '--t=%d'%(simlen_sec), '--nthreads=%d'%(nt)], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            time.sleep(5)
            p.kill()
            
            o = p.stdout.read() 
            print o
            
            #print p.stdout.read()
            #print p.stdout.read()
#            output, err = p.communicate(b"input data that is passed to subprocess' stdin")
#            rc = p.returncode
#            print output
            print "DONE"

