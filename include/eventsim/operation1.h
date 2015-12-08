/* -*- c++ -*- */
/* 
 * Copyright 2015 O'Shea Research.
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


#ifndef INCLUDED_EVENTSIM_OPERATION1_H
#define INCLUDED_EVENTSIM_OPERATION1_H

#include <eventsim/api.h>
#include <gnuradio/sync_block.h>
#include <es/es_handler.h>
#include <es/es_trigger.h>

namespace gr {
  namespace eventsim {

    class EVENTSIM_API operation1 : virtual public es_trigger, public es_handler
    {
     public:
      typedef boost::shared_ptr<operation1> sptr;
      virtual int work(int, gr_vector_const_void_star&, gr_vector_void_star&) = 0;
      virtual void handler(pmt::pmt_t, gr_vector_void_star) = 0;
      static sptr make(float fs, float dps, float load);
    };

  } // namespace eventsim
} // namespace gr

#endif /* INCLUDED_EVENTSIM_OPERATION1_H */

