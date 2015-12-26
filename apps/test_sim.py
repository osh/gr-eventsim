#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Test Sim
# Generated: Fri Dec 18 10:12:06 2015
##################################################

from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from optparse import OptionParser
import es
import eventsim


class test_sim(gr.top_block):

    def __init__(self, dps=500, l1=10.0, l2=15.0, ld=4.0, nthreads=8):
        gr.top_block.__init__(self, "Test Sim")

        ##################################################
        # Parameters
        ##################################################
        self.dps = dps
        self.l1 = l1
        self.l2 = l2
        self.ld = ld
        self.nthreads = nthreads

        ##################################################
        # Variables
        ##################################################
        self.samp_rate = samp_rate = 25e6
        self.dbps = dbps = 100

        ##################################################
        # Blocks
        ##################################################
        self.eventsim_operation2_0 = eventsim.operation2(samp_rate, 0, l2)
        self.eventsim_operation1_0 = eventsim.operation1(samp_rate, 0, l1)
        self.eventsim_detector_0 = eventsim.detector(samp_rate, dps, ld)
        self.es_trigger_sample_timer_0 = es.trigger_sample_timer(gr.sizeof_gr_complex, int(samp_rate/dbps), 10000, int(samp_rate), int(samp_rate/dbps) )
        (self.es_trigger_sample_timer_0).set_min_output_buffer(2000000)
        self.es_sink_0 = es.sink(1*[gr.sizeof_gr_complex],nthreads,256,0,2,"")
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_gr_complex*1, "test.dat", True)

        ##################################################
        # Connections
        ##################################################
        self.msg_connect((self.es_trigger_sample_timer_0, 'which_stream'), (self.es_sink_0, 'schedule_event'))    
        self.msg_connect((self.es_trigger_sample_timer_0, 'sample_timer_event'), (self.eventsim_detector_0, 'handle_event'))    
        self.msg_connect((self.eventsim_detector_0, 'which_stream'), (self.es_sink_0, 'schedule_event'))    
        self.msg_connect((self.eventsim_detector_0, 'detect_type1_event'), (self.eventsim_operation1_0, 'handle_event'))    
        self.msg_connect((self.eventsim_detector_0, 'detect_type2_event'), (self.eventsim_operation2_0, 'handle_event'))    
        self.msg_connect((self.eventsim_operation1_0, 'which_stream'), (self.es_sink_0, 'schedule_event'))    
        self.msg_connect((self.eventsim_operation1_0, 'type1_event'), (self.eventsim_operation2_0, 'handle_event'))    
        self.msg_connect((self.eventsim_operation2_0, 'which_stream'), (self.es_sink_0, 'schedule_event'))    
        self.connect((self.blocks_file_source_0, 0), (self.es_trigger_sample_timer_0, 0))    
        self.connect((self.es_trigger_sample_timer_0, 0), (self.es_sink_0, 0))    

    def get_dps(self):
        return self.dps

    def set_dps(self, dps):
        self.dps = dps

    def get_l1(self):
        return self.l1

    def set_l1(self, l1):
        self.l1 = l1

    def get_l2(self):
        return self.l2

    def set_l2(self, l2):
        self.l2 = l2

    def get_ld(self):
        return self.ld

    def set_ld(self, ld):
        self.ld = ld

    def get_nthreads(self):
        return self.nthreads

    def set_nthreads(self, nthreads):
        self.nthreads = nthreads

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate

    def get_dbps(self):
        return self.dbps

    def set_dbps(self, dbps):
        self.dbps = dbps


def argument_parser():
    parser = OptionParser(option_class=eng_option, usage="%prog: [options]")
    parser.add_option(
        "", "--dps", dest="dps", type="eng_float", default=eng_notation.num_to_str(500),
        help="Set dps [default=%default]")
    parser.add_option(
        "", "--l1", dest="l1", type="eng_float", default=eng_notation.num_to_str(10.0),
        help="Set l1 [default=%default]")
    parser.add_option(
        "", "--l2", dest="l2", type="eng_float", default=eng_notation.num_to_str(15.0),
        help="Set l2 [default=%default]")
    parser.add_option(
        "", "--ld", dest="ld", type="eng_float", default=eng_notation.num_to_str(4.0),
        help="Set ld [default=%default]")
    parser.add_option(
        "", "--nthreads", dest="nthreads", type="intx", default=8,
        help="Set nthreads [default=%default]")
    return parser


def main(top_block_cls=test_sim, options=None):
    if options is None:
        options, _ = argument_parser().parse_args()

    tb = top_block_cls(dps=options.dps, l1=options.l1, l2=options.l2, ld=options.ld, nthreads=options.nthreads)
    tb.start()
    tb.wait()


if __name__ == '__main__':
    main()
