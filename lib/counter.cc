
#include <counter.h>
#include <iostream>



namespace gr {
    namespace eventsim {
        counter counter::global_counter;

        counter::counter(){
            printf("Counter starting\n");
            }
        
        counter::~counter(){
            printf("Counter exiting!...\n");
            print();
        }

        void counter::print(){

                    double dur = d_timer.elapsed().wall * 1e-9;
                    uint64_t e(d_events),d(d_runs_detector),a(d_runs_type_a),b(d_runs_type_b);
                    printf("********** COUNTER ************\n");
                    printf("* events   = %lu (%f/sec)\n", e, e/dur);
                    printf("* detector = %lu (%f/sec)\n", d, d/dur);
                    printf("* type a   = %lu (%f/sec)\n", a, a/dur);
                    printf("* type b   = %lu (%f/sec)\n", b, b/dur);
                    printf("*  elapsed = %f\n", dur);
                    printf("********** COUNTER ************\n");
        }

    }
}


