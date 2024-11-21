//
// Created by FireFlower on 2024/11/21.
//

#include "FSignal.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/signal.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

namespace fireflower {
	void FSignal::_bind_methods() {
		// getSignalName
		ClassDB::bind_static_method(FSignal::get_class_static(), D_METHOD("getSignalName"), &FSignal::getSignalName);
		
		// connectSignal
		ClassDB::bind_method(D_METHOD("connectSignal", "callable", "flags"), &FSignal::connectSignal, DEFVAL(0));
		
		// disconnectSignal
		ClassDB::bind_method(D_METHOD("disconnectSignal", "callable"), &FSignal::disconnectSignal);
		
		// isConnected
		ClassDB::bind_method(D_METHOD("isConnected", "callable"), &FSignal::isConnected);
		
		// emitSignal
		// ClassDB::bind_vararg_method(MethodFlags::METHOD_FLAGS_DEFAULT, "emitSignal", &FSignal::emitSignal);
	}
	
	StringName FSignal::getSignalName() {
		static const StringName signal_name = "SignalName";
		return signal_name;
	}
	
	Error FSignal::connectSignal(const Callable& callable, uint32_t flags) {
		return this->connect(FSignal::getSignalName(), callable, flags);
	}
	
	void FSignal::disconnectSignal(const Callable& callable) {
		this->disconnect(FSignal::getSignalName(), callable);
	}
	
	bool FSignal::isConnected(const Callable& callable) const {
		return this->is_connected(FSignal::getSignalName(), callable);
	}
	
	// void FSignal::emitSignal(const Variant** args, GDExtensionInt arg_count, GDExtensionCallError& error) {
	// 	auto argArr = Array::make(FSignal::getSignalName());
	// 	for (int i = 0; i < arg_count; i++) {
	// 		argArr.append(*args[i]);
	// 	}
	//
	// 	UtilityFunctions::print("FSignal::emitSignal(", argArr, ")");
	//
	// 	this->callv("emit_signal", argArr);
	// }
	
	void FSignal0::_bind_methods() {
		// 信号
		ClassDB::add_signal(FSignal0::get_class_static(), MethodInfo(FSignal::getSignalName()));
		
		// emitSignal
		ClassDB::bind_method(D_METHOD("emitSignal"), &FSignal0::emitSignal);
	}
	
	void FSignal0::emitSignal() {
		this->emit_signal(FSignal::getSignalName());
	}
	
	void FSignal1::_bind_methods() {
		// 信号
		ClassDB::add_signal(FSignal1::get_class_static(), MethodInfo(FSignal::getSignalName(), PropertyInfo(Variant::NIL, "arg")));
		
		// emitSignal
		ClassDB::bind_method(D_METHOD("emitSignal", "arg"), &FSignal1::emitSignal);
	}
	
	void FSignal1::emitSignal(const Variant& arg) {
		this->emit_signal(FSignal::getSignalName(), arg);
	}
}
