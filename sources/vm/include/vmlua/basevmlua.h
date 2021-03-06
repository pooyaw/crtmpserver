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

#ifdef VM_LUA
#ifndef _BASEVMLUA_H
#define	_BASEVMLUA_H

#include "basevm.h"

class BaseVMLua
: public BaseVM {
private:
	lua_State *_pGlobalState;
public:
	BaseVMLua();
	virtual ~BaseVMLua();

	virtual bool Supports64bit();
	virtual bool SupportsUndefined();
	virtual bool Initialize();
	virtual bool Shutdown();
	virtual bool LoadScriptFile(string scriptFileName, string scriptName);
	virtual bool LoadScriptString(string scriptContent, string scriptName);
	virtual bool Call(string functionName, Variant &parameters, Variant &results);
};


#endif	/* _BASEVMLUA_H */
#endif /* VM_LUA */

