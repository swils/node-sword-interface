/* This file is part of node-sword-interface.

   Copyright (C) 2019 - 2020 Tobias Klein <contact@ezra-project.net>

   node-sword-interface is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   node-sword-interface is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of 
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   See the GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with node-sword-interface. See the file COPYING.
   If not, see <http://www.gnu.org/licenses/>. */

#ifndef _MODULE_STORE
#define _MODULE_STORE

#include <string>

#include "file_system_helper.hpp"

namespace sword {
    class SWMgr;
    class SWModule;
};

class ModuleStore
{
public:
    ModuleStore();
    virtual ~ModuleStore();

    sword::SWModule* getLocalModule(std::string moduleName);
    std::vector<sword::SWModule*> getAllLocalModules();
    
    bool isModuleInUserDir(std::string moduleName);
    bool isModuleInUserDir(sword::SWModule* module);

private:
    void resetMgr();
    std::string getModuleDataPath(sword::SWModule* module);

    sword::SWMgr* _mgr = 0;
    FileSystemHelper _fileSystemHelper;
};

#endif // _MODULE_STORE