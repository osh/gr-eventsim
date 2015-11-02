#ifndef ESS_COUNTER_H
#define ESS_COUNTER_H

#include <boost/atomic.hpp>
#include <stdio.h>

namespace gr {
    namespace eventsim {
        class counter {
            private:
        
            public:
                boost::atomic<uint64_t>     d_events;
                boost::atomic<uint64_t>     d_runs_detector;
                boost::atomic<uint64_t>     d_runs_type_a;
                boost::atomic<uint64_t>     d_runs_type_b;

                void print(){
                    printf("********** COUNTER ************\n");
                    printf("* events   = %lu\n", (uint64_t)d_events);
                    printf("* detector = %lu\n", (uint64_t)d_runs_detector);
                    printf("* type a   = %lu\n", (uint64_t)d_runs_type_a);
                    printf("* type b   = %lu\n", (uint64_t)d_runs_type_b);
                    printf("********** COUNTER ************\n");
                }
        
            static counter global_counter;
        };


    }
}



#endif
