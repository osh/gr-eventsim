#ifndef ESS_COUNTER_H
#define ESS_COUNTER_H

#include <boost/atomic.hpp>
#include <stdio.h>
#include <boost/timer.hpp>

namespace gr {
    namespace eventsim {
        class counter {
            private:
                boost::timer d_timer;

            public:
                boost::atomic<uint64_t>     d_events;
                boost::atomic<uint64_t>     d_runs_detector;
                boost::atomic<uint64_t>     d_runs_type_a;
                boost::atomic<uint64_t>     d_runs_type_b;

                counter();
                ~counter();
                void print();
        
            static counter global_counter;
        };


    }
}



#endif
