/*************************************************************************
 * Copyright (C) 2018,  Alexei Sibidanov                                 *
 * All rights reserved.                                                  *
 *                                                                       *
 * This file is part of the RANLUX++ random number generator.            *
 *                                                                       *
 * RANLUX++ is free software: you can redistribute it and/or modify it   *
 * under the terms of the GNU Lesser General Public License as published *
 * by the Free Software Foundation, either version 3 of the License, or  *
 * (at your option) any later version.                                   *
 *                                                                       *
 * RANLUX++ is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 * Lesser General Public License for more details.                       *
 *                                                                       *
 * You should have received a copy of the GNU Lesser General Public      *
 * License along with this program.  If not, see                         *
 * <http://www.gnu.org/licenses/>.                                       *
 *************************************************************************/

#include "ranluxpp.h"
#include "jlcxx/jlcxx.hpp"


JLCXX_MODULE define_julia_module(jlcxx::Module& m)
{

  m.add_type<ranluxpp>("ranluxpp")
    .constructor<uint64_t>()
    .method("get_double", &ranluxpp::get_double)
    .method("get_float", &ranluxpp::get_float)
    .method("get_uint", &ranluxpp::get_uint );
}