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


#ifndef INCLUDED_EVENTSIM_DETECTOR_H
#define INCLUDED_EVENTSIM_DETECTOR_H

#include <eventsim/api.h>
#include <gnuradio/sync_block.h>
#include <es/es_handler.h>
#include <es/es_trigger.h>

namespace gr {
  namespace eventsim {

    /*!
     * \brief <+description of block+>
     * \ingroup eventsim
     *
     */
    class EVENTSIM_API detector : public es_trigger, es_handler
    {
     public:
      void handler( pmt_t msg, gr_vector_void_star buf );
      typedef boost::shared_ptr<detector> sptr;
      detector(float fs, float dps, float load);
      ~detector();

      virtual int work (int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items) { return noutput_items; }

      static es_handler_sptr make(float fs, float dps, float load);
    };

  } // namespace eventsim
} // namespace gr

#endif /* INCLUDED_EVENTSIM_DETECTOR_H */

