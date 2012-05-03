//
// JSONConfiguration.h
//
// $Id$
//
// Library: Util
// Package: Util
// Module:  JSONConfiguration
//
// Definition of the JSONConfiguration class.
//
// Copyright (c) 2012, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Util_JSONConfiguration_INCLUDED
#define Util_JSONConfiguration_INCLUDED


#include <istream>

#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/JSON/Object.h"

namespace Poco {
namespace Util {

class Util_API JSONConfiguration : public AbstractConfiguration
	/// This configuration class extracts configuration properties
	/// from a JSON object. An XPath-like syntax for property
	/// names is supported to allow full access to the JSON object.
	///
	/// Given the following JSON object as an example:
	/// {
	///   "config" : {
	///      "prop1" : "value1",
	///      "prop2" : 10,
	///      "prop3" : [
	///        "element1",
	///        "element2"
	///      ],
	///      "prop4" : {
	///        "prop5" : false,
	///        "prop6" : null
	///      }
	///   }
	/// }
	///	The following property names would be valid and would
	/// yield the shown values:
	///
	/// config.prop1       --> "value1"
	/// config.prop3[1]    --> "element2"
	/// config.prop4.prop5 --> false
{
public:

	JSONConfiguration();
		/// Creates an empty configuration


	JSONConfiguration(const std::string& path);
		/// Creates a configuration and loads the JSON structure from the given file


	JSONConfiguration(std::istream& istr);
		/// Creates a configuration and loads the JSON structure from the given stream


	JSONConfiguration(const JSON::Object::Ptr& object);
		/// Creates a configuration from the given JSON object


	virtual ~JSONConfiguration();
		/// Destructor


	void load(const std::string& path);
		/// Loads the configuration from the given file


	void load(std::istream& istr);
		/// Loads the configuration from the given stream


	void loadEmpty(const std::string& root);
		/// Loads an empty object containing only a root object with the given name.


	void save(std::ostream& ostr, unsigned int indent = 2) const;
		/// Saves the configuration to the given stream


	void setInt(const std::string& key, int value);


	void setBool(const std::string& key, bool value);


	void setDouble(const std::string& key, double value);



protected:

	bool getRaw(const std::string & key, std::string & value) const;


	void setRaw(const std::string& key, const std::string& value);


	void enumerate(const std::string& key, Keys& range) const;


private:


	JSON::Object::Ptr findStart(const std::string& key, std::string& lastPart);


	void getIndexes(std::string& name, std::vector<int>& indexes);


	void setValue(const std::string& key, const Poco::DynamicAny& value);


 	JSON::Object::Ptr _object;
};

} } // namespace Poco::Util


#endif // Util_JSONConfiguration_INCLUDED
