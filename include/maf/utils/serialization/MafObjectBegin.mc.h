/**
 * @brief Use below MACROS to define a serializable object like this:
 *
 * Class(TheObject) // or Class(TheObject, BaseObject)
 *     properties
 *     (
 *          (std::string, Name),
 *          (int, Type),
 *          (std::string, Action),
 *          (Type, Name) //( <Type, Name> must be enclosed by parentheses)
 *     )
 * Ssalc(TheObject)
 *
 * After that, you can use it for serialization like this:
 *
 *  int type = 10;
 *  TheObject object("name", type, "Pull request action");
 *  std::vector<std::string> vec = {....};
 *
 *  maf::srz::BASerializer sr;
 *  sr << object << vec; // done serialize
 *
 *  //... write sr.c_str() to file, share it between programs
 *  //... now deserialize it
 *
 *  maf::srz::ByteArray ba = readFromFile/FromPipe();
 *  maf::srz::BADeserializer dsr(ba);
 *  TheObject object;
 *  std::vector<std::string> vec;
 *  dsr >> object >> vec; //The order must be kept same as serialization
 *
 *  std::cout << object.name() << object.type() << object.action();
 *  printVector(vec) ...;
 *
 * */

#ifndef MAFOBJECTBEGIN_MC_H
#   define MAFOBJECTBEGIN_MC_H
#   include "Serializer.h"
#   include "DumpHelper.h"
#endif // MAFOBJECTBEGIN_MC_H

// The rest of this file must be putted outside include guard
// Make it to be use with multiple files

#include "Internal/TplkdefBegin.mc.h"

#	ifdef Class
#		pragma push_macro("Class")
#		define maf_restore_macro_Class
#	endif
#	ifdef properties
#		pragma push_macro("properties")
#		define maf_restore_macro_properties
#	endif
#	ifdef Ssalc
#		pragma push_macro("Ssalc")
#		define maf_restore_macro_Ssalc
#	endif

#define Class(...) mc_maf_tuple_like_object(__VA_ARGS__)

#define Ssalc(ClassName) mc_maf_tuple_like_object_end_(ClassName)

#define properties(...) mc_maf_properties_map_(__VA_ARGS__)

