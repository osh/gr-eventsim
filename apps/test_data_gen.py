#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Test Data Gen
# Generated: Tue Dec  8 14:33:43 2015
##################################################

from gnuradio import analog
from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from optparse import OptionParser


class test_data_gen(gr.top_block):

    def __init__(self):
        gr.top_block.__init__(self, "Test Data Gen")

        ##################################################
        # Variables
        ##################################################
        self.samp_rate = samp_rate = 25e6

        ##################################################
        # Blocks
        ##################################################
        self.blocks_head_0 = blocks.head(gr.sizeof_gr_complex*1, int(samp_rate*10))
        self.blocks_file_sink_0 = blocks.file_sink(gr.sizeof_gr_complex*1, "test.dat", False)
        self.blocks_file_sink_0.set_unbuffered(False)
        self.analog_fastnoise_source_x_0 = analog.fastnoise_source_c(analog.GR_GAUSSIAN, 1, 0, 8192)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.analog_fastnoise_source_x_0, 0), (self.blocks_head_0, 0))    
        self.connect((self.blocks_head_0, 0), (self.blocks_file_sink_0, 0))    

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate
        self.blocks_head_0.set_length(int(self.samp_rate*10))


def main(top_block_cls=test_data_gen, options=None):

    tb = top_block_cls()
    tb.start()
    tb.wait()


if __name__ == '__main__':
    main()
