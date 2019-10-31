/*
 * This file is part of pcb2gcode.
 * 
 * Copyright (C) 2015 Nicola Corna <nicola@corna.info>
 *
 * pcb2gcode is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * pcb2gcode is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with pcb2gcode.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <boost/program_options.hpp>
#include <boost/system/api_config.hpp>  // for BOOST_POSIX_API or BOOST_WINDOWS_API

namespace Software {
// This enum contains the software codes. Note that all the items (except for CUSTOM)
// must start from 0 and be consecutive, as they are used as array indexes
enum Software { CUSTOM = -1, LINUXCNC = 0, MACH4 = 1, MACH3 = 2 };
}; // namespace Software

bool workSide( const boost::program_options::variables_map &options, std::string type );

// Based on the explanation here:
// https://www.geeksforgeeks.org/python-os-path-join-method/
static inline std::string build_filename(const std::string& a, const std::string& b) {
#ifdef BOOST_WINDOWS_API
  static constexpr auto seperator = '\\';
#endif

#ifdef BOOST_POSIX_API
  static constexpr auto seperator = '/';
#endif

  if (a.size() == 0 || b.front() == seperator) {
    return b; // One side is empty.
  }
  if (b.size() == 0) {
    if (a.back() != seperator) {
      return a + seperator; // The other side is empty.
    } else {
      return a;
    }
  }
  if (a.back() != seperator) {
    return a + seperator + b;
  } else {
    return a + b;
  }
}

#endif // COMMON_H
