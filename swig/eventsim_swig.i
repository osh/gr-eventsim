/* -*- c++ -*- */

#define EVENTSIM_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "eventsim_swig_doc.i"

%{
#include "eventsim/dispatcher.h"
#include "eventsim/detector.h"
%}


%include "eventsim/dispatcher.h"
GR_SWIG_BLOCK_MAGIC2(eventsim, dispatcher);
%include "eventsim/detector.h"
GR_SWIG_BLOCK_MAGIC2(eventsim, detector);
