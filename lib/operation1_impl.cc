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
#include "operation1_impl.h"
#include <es/es_common.h>
#include "counter.h"

namespace gr {
  namespace eventsim {

    operation1::sptr
    operation1::make(float fs, float dps, float load)
    {
      return gnuradio::get_initial_sptr
        (new operation1_impl(fs, dps, load));
    }

    operation1_impl::operation1_impl(float fs, float dps, float load)
      : gr::sync_block("operation1",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)),
        d_lg(load)
    {
        register_handler("type1_event");
    }

    operation1_impl::~operation1_impl()
    {
    }

    void 
    operation1_impl::handler( pmt_t msg, gr_vector_void_star buf )
    {
//        std::cout << "OPERATION1 HANDLER!!\n";
        counter::global_counter.d_events++;
        counter::global_counter.d_runs_type_a++;
        d_lg.work();

        uint64_t e_time = event_time(msg);
        uint64_t e_len = event_length(msg);

        // 60 percent chance of follow on event type2
        if(random() % 100 < 60){
            pmt_t evt = event_create( pmt::mp("type1_event"), e_time, e_len );
            message_port_pub(pmt::mp("which_stream"), evt);
            }
    }


  } /* namespace eventsim */
} /* namespace gr */

