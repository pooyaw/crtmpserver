/* 
*  Copyright (c) 2010,
*  Gavriloaie Eugen-Andrei (shiretu@gmail.com)
*  
*  This file is part of crtmpserver.
*  crtmpserver is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*  
*  crtmpserver is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*  
*  You should have received a copy of the GNU General Public License
*  along with crtmpserver.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "mediaformats/mp4/versionedatom.h"

VersionedAtom::VersionedAtom(MP4Document *pDocument, uint32_t type,
        uint64_t size, uint64_t start)
: BaseAtom(pDocument, type, size, start) {
    _version = 0;
    memset(_flags, 0, 3);
}

VersionedAtom::~VersionedAtom() {
}

bool VersionedAtom::Read() {
    if (!ReadUInt8(_version)) {
        FATAL("Unable to read version");
        return false;
    }
    //FINEST("_version: %d", _version);

    if (!ReadArray(_flags, 3)) {
        FATAL("Unable to read flags");
        return false;
    }
    //FINEST("_flags: %02x %02x %02x", _flags[0], _flags[1], _flags[2]);

    return ReadData();
}

string VersionedAtom::Hierarchy(uint32_t indent) {
    return string(4 * indent, ' ') + GetTypeString();
}
