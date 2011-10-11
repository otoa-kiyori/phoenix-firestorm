/**
 * @file   lllinstancetracker.cpp
 * 
 * $LicenseInfo:firstyear=2009&license=viewerlgpl$
 * Second Life Viewer Source Code
 * Copyright (C) 2010, Linden Research, Inc.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation;
 * version 2.1 of the License only.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 * Linden Research, Inc., 945 Battery Street, San Francisco, CA  94111  USA
 * $/LicenseInfo$
 */

// Precompiled header
#include "linden_common.h"
// associated header
#include "llinstancetracker.h"
// STL headers
// std headers
// external library headers
// other Linden headers

//static 
void * & LLInstanceTrackerBase::getInstances(std::type_info const & info)
{
// <ND> This is called a HUGE amount of times. Just use the name() ptr in a map instead of making expensive string compares each time
//	static std::map<std::string, void *> instances;
//
//	std::string k = info.name();
//	if(instances.find(k) == instances.end())
//	{
//		instances[k] = NULL;
//	}
//
//	return instances[k];

	static std::map<char const*, void *> instances;
	std::map< char const *, void* >::iterator itr = instances.find( info.name() );
	//	std::string k = info.name();
	if(itr == instances.end())
	{
		itr = instances.insert( std::make_pair( info.name(), (void*)0 ) ).first;
	}
	return itr->second;
// </ND>

}

