#ifdef MSVC
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

#include <iostream>

#include <node.h>
#include <uv.h>
#include <v8.h>

using namespace node;
using namespace v8;

namespace {

class Extension : public ObjectWrap {
public:
	Extension();
	~Extension();

	static void Initialize(Handle<Object> target);
	static Handle<Value> New(const Arguments& args);

private:
	Extension(const Extension&);
	Extension& operator=(const Extension&);

	static Persistent<FunctionTemplate> d_template;
};

Persistent<FunctionTemplate> Extension::d_template;

Extension::Extension()
{
	std::cout << "Extension::Extension" << std::endl;
}

Extension::~Extension()
{
	std::cout << "Extension::~Extension" << std::endl;
}

void
Extension::Initialize(Handle<Object> target)
{
	std::cout << "Extension::Initialize" << std::endl;

	HandleScope scope;
	Local<FunctionTemplate> t = FunctionTemplate::New(Extension::New);
	d_template = Persistent<FunctionTemplate>::New(t);
	d_template->InstanceTemplate()->SetInternalFieldCount(1);
	target->Set(String::New("Extension"), d_template->GetFunction());
}

Handle<Value>
Extension::New(const Arguments& args)
{
	std::cout << "Extension::New" << std::endl;

	if (!args.IsConstructCall())
		return ThrowException(Exception::Error(String::New(
			"Cannot call constructor as function.")));

	HandleScope scope;
	Extension *ext = new Extension();
	ext->Wrap(args.This());
	return args.This();
}

extern "C" {
	void NODE_EXTERN init(Handle<Object> target) {
		std::cout << "init" << std::endl;
		Extension::Initialize(target);
	}
	NODE_MODULE(extension, init)
}

} // close namespace