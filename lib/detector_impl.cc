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
              gr::io_signature::make(0,0,0))
    {
        register_handler("detect_event");
    }

    detector_impl::~detector_impl()
    {
    }

    void 
    detector_impl::handler( pmt_t msg, gr_vector_void_star buf )
    {
        std::cout << "DETECTOR HANDLER!!\n";

        uint64_t e_time = event_time(msg);
        uint64_t e_len = event_length(msg);
        
//        pmt_t evt = event_create( pmt::mp("sample_timer_event"), event_time, event_len );
 //       message_port_pub(pmt::mp("which_stream"), evt);
    }


  } /* namespace eventsim */
} /* namespace gr */

