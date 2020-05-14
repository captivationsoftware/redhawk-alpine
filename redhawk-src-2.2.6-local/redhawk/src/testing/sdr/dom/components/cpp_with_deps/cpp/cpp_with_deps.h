/*
 * This file is protected by Copyright. Please refer to the COPYRIGHT file
 * distributed with this source distribution.
 *
 * This file is part of REDHAWK core.
 *
 * REDHAWK core is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * REDHAWK core is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */
#ifndef CPP_WITH_DEPS_I_IMPL_H
#define CPP_WITH_DEPS_I_IMPL_H

#include "cpp_with_deps_base.h"

class cpp_with_deps_i : public cpp_with_deps_base
{
    ENABLE_LOGGING
    public:
        cpp_with_deps_i(const char *uuid, const char *label);
        ~cpp_with_deps_i();

        void constructor();

        int serviceFunction();
};

#endif // CPP_WITH_DEPS_I_IMPL_H
