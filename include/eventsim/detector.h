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

namespace gr {
  namespace eventsim {

    /*!
     * \brief <+description of block+>
     * \ingroup eventsim
     *
     */
    class EVENTSIM_API detector : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<detector> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of eventsim::detector.
       *
       * To avoid accidental use of raw pointers, eventsim::detector's
       * constructor is in a private implementation
       * class. eventsim::detector::make is the public interface for
       * creating new instances.
       */
      static sptr make(float fs, float dps, float load);
    };

  } // namespace eventsim
} // namespace gr

#endif /* INCLUDED_EVENTSIM_DETECTOR_H */

