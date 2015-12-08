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


#ifndef INCLUDED_EVENTSIM_DISPATCHER_H
#define INCLUDED_EVENTSIM_DISPATCHER_H

#include <eventsim/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace eventsim {

    /*!
     * \brief <+description of block+>
     * \ingroup eventsim
     *
     */
    class EVENTSIM_API dispatcher : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<dispatcher> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of eventsim::dispatcher.
       *
       * To avoid accidental use of raw pointers, eventsim::dispatcher's
       * constructor is in a private implementation
       * class. eventsim::dispatcher::make is the public interface for
       * creating new instances.
       */
      static sptr make(int len, int overlap);
    };

  } // namespace eventsim
} // namespace gr

#endif /* INCLUDED_EVENTSIM_DISPATCHER_H */

