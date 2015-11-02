

#include <load_generator.h>
#include <stdlib.h>

load_generator::load_generator(float load) :
    d_load(load)
    {

    }


void load_generator::work()
{
    int n_iter = d_load*100;
    //int n_iter = d_load*10000;
    d_state = 0x7283;
    for(int i=0; i<n_iter; i++){
        d_state ^= random();
        }
}
