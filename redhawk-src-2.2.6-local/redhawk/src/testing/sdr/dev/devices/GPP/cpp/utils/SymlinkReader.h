/*
 * This file is protected by Copyright. Please refer to the COPYRIGHT file
 * distributed with this source distribution.
 *
 * This file is part of REDHAWK GPP.
 *
 * REDHAWK GPP is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * REDHAWK GPP is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */
#ifndef SYMLINK_READER_H_
#define SYMLINK_READER_H_

#include "OverridableSingleton.h"
#include <string>

class SymlinkReader : public OverridableSingleton<SymlinkReader>
{
public:
    virtual ~SymlinkReader(){}
    static std::string ReadLink(const std::string& filename);

protected:
    virtual std::string readlink(const std::string& filename);
};

#endif
