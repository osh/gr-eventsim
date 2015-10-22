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
#include "dispatcher_impl.h"

namespace gr {
  namespace eventsim {

    dispatcher::sptr
    dispatcher::make(int len, int overlap)
    {
      return gnuradio::get_initial_sptr
        (new dispatcher_impl(len, overlap));
    }

    /*
     * The private constructor
     */
    dispatcher_impl::dispatcher_impl(int len, int overlap)
      : gr::sync_block("dispatcher",
              gr::io_signature::make(1,1, sizeof(gr_complex)),
              gr::io_signature::make(1,1, sizeof(gr_complex))),
    
        d_len(len), d_shift(len-overlap)
    {
        if(d_shift <= 0){
            throw std::runtime_error("shift must be > 0");
        }
    }

    /*
     * Our virtual destructor.
     */
    dispatcher_impl::~dispatcher_impl()
    {
    }

    int
    dispatcher_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
        const gr_complex *in = (const gr_complex *) input_items[0];
        gr_complex *out = (gr_complex *) output_items[0];

        uint64_t first_sample = nitems_read(0);
        while(d_offset <= first_sample){
            // add_event( d_offset, d_len );
            d_offset += d_shift;
            }       

        memcpy(out, in, sizeof(gr_complex)*noutput_items);
        return noutput_items;
    }

  } /* namespace eventsim */
} /* namespace gr */

