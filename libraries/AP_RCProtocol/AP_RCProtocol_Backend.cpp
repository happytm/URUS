/*
 * This file is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Code by Andrew Tridgell and Siddharth Bharat Purohit
 */

#include "AP_RCProtocol.h"

AP_RCProtocol_Backend::AP_RCProtocol_Backend(AP_RCProtocol &_frontend) : 
    frontend(_frontend),
    rc_input_count(0),
    last_rc_input_count(0),
    _num_channels(0)
{}

bool AP_RCProtocol_Backend::new_input()
{
    bool ret = rc_input_count != last_rc_input_count;
    if (ret) {
        last_rc_input_count = rc_input_count;
    }
    return ret;
}

uint8_t AP_RCProtocol_Backend::num_channels()
{
    return _num_channels;
}

uint16_t AP_RCProtocol_Backend::read(uint8_t chan)
{
    return _pwm_values[chan];
}
