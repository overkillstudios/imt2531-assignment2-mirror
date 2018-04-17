#pragma once

#include <sstream>
#include <fstream>
#include <string>

#include <PMS/logger.h>
#include <overkill/MaterialSystem.hpp>
#include <overkill/ShaderSystem.hpp>
#include <overkill/Watcher.hpp>
#include <overkill/Config.hpp>

namespace overkill::Util 
{

auto fileToString(const std::string& filepath) -> std::string;  
void everyTwoSeconds(float t);

}