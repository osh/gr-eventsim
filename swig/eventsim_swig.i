/* -*- c++ -*- */

#define EVENTSIM_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "eventsim_swig_doc.i"

%{
#include "eventsim/dispatcher.h"
#include "eventsim/detector.h"
#include "eventsim/operation1.h"
#include "eventsim/operation2.h"
%}

%include "es/es_handler.h"

%include "eventsim/dispatcher.h"
GR_SWIG_BLOCK_MAGIC2(eventsim, dispatcher);
%include "eventsim/detector.h"
GR_SWIG_BLOCK_MAGIC2(eventsim, detector);
%include "eventsim/operation1.h"
GR_SWIG_BLOCK_MAGIC2(eventsim, operation1);
%include "eventsim/operation2.h"
GR_SWIG_BLOCK_MAGIC2(eventsim, operation2);
