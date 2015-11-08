/* -*- c++ -*- */
/* 
 * Copyright 2015 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "detector_impl.h"
#include <es/es_common.h>
#include <stdio.h>
#include "counter.h"

namespace gr {
  namespace eventsim {

    detector::sptr
    detector::make(float fs, float dps, float load)
    {
      return gnuradio::get_initial_sptr
        (new detector_impl(fs, dps, load));
    }

    detector_impl::detector_impl(float fs, float dps, float load)
      : gr::sync_block("detector_impl",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)),
        d_fs(fs),
        d_dps(dps),
        d_lg(load)
    {
        register_handler("detect_type1_event");
        register_handler("detect_type2_event");
    }

    detector_impl::~detector_impl()
    {
    }

    void 
    detector_impl::handler( pmt_t msg, gr_vector_void_star buf )
    {
        counter::global_counter.d_events++;
        if(counter::global_counter.d_runs_detector++ % 100 == 99){
            counter::global_counter.print();
        }
//        std::cout << "DETECTOR HANDLER!!\n";
        d_lg.work();

        uint64_t e_time = event_time(msg);
        uint64_t e_len = event_length(msg);
        
        int next_evt_len = 2048;

        // pick a random number of events to target our detection rate (detection per second/dps)
        int expected_num_events = (e_len/d_fs)*d_dps;
        int num_events = random()%(2*expected_num_events);
//        printf("expected num events: %d ... number detected: %d\n", expected_num_events, num_events);

        for(int i=0; i<num_events; i++){

            // pick a random time within our window of detection
            uint64_t evt_start = e_time + random()%(e_len);
            //printf("evt(%ulu) --> new evt(%lu)\n", e_time, evt_start);

            // pick a random event type
            pmt::pmt_t event_type(pmt::mp("detect_type1_event"));
            // send it downstream
            if(random()%2==1)
                event_type = pmt::mp("detect_type2_event");


            pmt_t evt = event_create( event_type, evt_start, next_evt_len );
            //message_port_pub(pmt::mp("which_stream"), evt);
            event_queue->add_event(evt);
            }

    }


  } /* namespace eventsim */
} /* namespace gr */

