//
// Created by FireFlower on 2024/11/21.
//

#include "FCallable.h"
#include <godot_cpp/variant/callable.hpp>

namespace fireflower {
	void FCallable::_bind_methods() {
		// toCallable
		ClassDB::bind_method(D_METHOD("toCallable"), &FCallable::toCallable);
		
		// isValid
		ClassDB::bind_method(D_METHOD("isValid"), &FCallable::isValid);
	}
	
	FCallable::operator Callable() {
		return Callable(this, "invoke");
	}
	
	Callable FCallable::toCallable() {
		return *this;
	}
	
	bool FCallable::isValid() const {
		return !(*this == nullptr);
	}
	
	Ref<FCallable0> FCallable0::make(const Callable& init_callable) {
		auto resultRef = Ref(memnew(FCallable0));
		
		resultRef->callableFunc = [=]() {
			if (init_callable.is_valid()) {
				init_callable.call();
			}
		};
		
		return resultRef;
	}
	
	FCallable0::FCallable0(const FunctionType& init_callableFunc) : callableFunc(init_callableFunc) {
	
	}
	
	void FCallable0::invoke() {
		if (this->callableFunc) {
			this->callableFunc();
		}
	}
	
	void FCallable0::_bind_methods() {
		// make
		ClassDB::bind_static_method(
			FCallable0::get_class_static(),
			D_METHOD("make", "init_callable"),
			&FCallable0::make
		);
		
		// invoke
		ClassDB::bind_method(D_METHOD("invoke"), &FCallable0::invoke);
	}
	
	bool FCallable0::operator==(std::nullptr_t) const {
		return this->callableFunc == nullptr;
	}
	
	FCallable1::FCallable1(const FunctionType& init_callableFunc) : callableFunc(init_callableFunc) {
	
	}
	
	void FCallable1::invoke(const Variant& arg) {
		if (this->callableFunc) {
			this->callableFunc(arg);
		}
	}
	
	void FCallable1::_bind_methods() {
		// invoke
		ClassDB::bind_method(D_METHOD("invoke", "arg"), &FCallable1::invoke);
		
		// make
		ClassDB::bind_static_method(
			FCallable1::get_class_static(),
			D_METHOD("make", "init_callable"),
			&FCallable1::make
		);
	}
	
	bool FCallable1::operator==(std::nullptr_t) const {
		return this->callableFunc == nullptr;
	}
	
	Ref<FCallable1> FCallable1::make(const Callable& init_callable) {
		auto resultRef = Ref(memnew(FCallable1));
		
		resultRef->callableFunc = [=](const Variant& arg) {
			if (init_callable.is_valid()) {
				init_callable.call(arg);
			}
		};
		
		return resultRef;
	}
}
