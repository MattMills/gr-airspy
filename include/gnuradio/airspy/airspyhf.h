/* -*- c++ -*- */
/*
 * Copyright 2019 Albin Stigo.
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

#ifndef INCLUDED_AIRSPY_AIRSPYHF_H
#define INCLUDED_AIRSPY_AIRSPYHF_H

#include <gnuradio/airspy/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace airspy {

/*!
 * \brief Airspy HF+ source block
 * \ingroup airspy
 *
 */
class AIRSPY_API airspyhf : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<airspyhf> sptr;
    
    /*!
     * \brief Return a shared_ptr to a new instance of airspy::airspyhf.
     *
     * To avoid accidental use of raw pointers, airspy::airspyhf's
     * constructor is in a private implementation
     * class. airspy::airspyhf::make is the public interface for
     * creating new instances.
     */
    static sptr make(const std::string serial_number="",
                     int samplerate=768000,
                     int frequency=7000000);
    
    static std::vector<std::string> list_devices();
    
    virtual void set_freq(const uint32_t freq_hz) = 0;
    virtual void set_samplerate(const uint32_t samplerate) = 0;
    virtual std::vector<uint32_t> get_samplerates() = 0;
    virtual bool is_streaming() = 0;
    virtual void set_hf_agc(uint8_t flag) = 0;
    virtual void set_hf_agc_threshold(uint8_t flag) = 0;
    virtual void set_hf_att(uint8_t value) = 0;
    virtual void set_hf_lna(uint8_t flag) = 0;
    virtual void set_lib_dsp(uint8_t flag) = 0;
    // TODO: fix this method
    virtual void board_partid_serialno_read() = 0;
    virtual std::string version_string_read() = 0;
    
};

} // namespace airspy
} // namespace gr

#endif /* INCLUDED_AIRSPY_AIRSPYHF_H */
