// Setup routines for creating fully populated DWFLs. Used in pass 2 and 3.
// Copyright (C) 2009 Red Hat, Inc.
//
// This file is part of systemtap, and is free software.  You can
// redistribute it and/or modify it under the terms of the GNU General
// Public License (GPL); either version 2, or (at your option) any
// later version.
//
#ifndef SETUP_DWFLPP_H
#define SETUP_DWFLPP_H

#include "config.h"
#include "session.h"

#include <set>
#include <string>
#include <vector>

extern "C" {
#include <elfutils/libdwfl.h>
}

Dwfl *setup_dwfl_kernel(const std::string &name,
			unsigned *found,
			systemtap_session &s);
Dwfl *setup_dwfl_kernel(const std::set<std::string> &names,
			unsigned *found,
			systemtap_session &s);

Dwfl* setup_dwfl_user(const std::string &name);
Dwfl* setup_dwfl_user(std::vector<std::string>::const_iterator &begin,
		      const std::vector<std::string>::const_iterator &end,
		      bool all_needed);

// user-space files must be full paths and not end in .ko
bool is_user_module(const std::string &m);

#endif
