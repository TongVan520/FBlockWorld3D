//
// Created by FireFlower on 2024/11/21.
//

#ifndef FBLOCKWORLD3D_FCALLABLE_H
#define FBLOCKWORLD3D_FCALLABLE_H

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <functional>

/// 请在<code>register_types.cpp</code>中使用
#define FRegisterFCallable \
GDREGISTER_ABSTRACT_CLASS(fireflower::FCallable);\
GDREGISTER_CLASS(fireflower::FCallable0);        \
GDREGISTER_CLASS(fireflower::FCallable1);        \

namespace fireflower {
	using namespace godot;
	using std::function;
	
	/// @类名 函数包
	/// @描述 与Godot内置的<code>Callable</code>的区别：\n
	/// <code>FCallable</code>不依赖对象，可以独立使用
	class FCallable : public RefCounted {
	GDCLASS(FCallable, RefCounted);
	
	public:
		Callable toCallable();
		virtual operator Callable();
		virtual bool operator==(std::nullptr_t) const = 0;
		bool isValid() const;
	
	protected:
		static void _bind_methods();
		
	};
	
	class FCallable0 : public FCallable {
	GDCLASS(FCallable0, FCallable);
	
	public:
		using FunctionType = function<void()>;
	
	private:
		FunctionType callableFunc;
	
	public:
		FCallable0() = default;
		static Ref<FCallable0> make(const Callable& init_callable);
		FCallable0(const FunctionType& init_callableFunc);
		virtual bool operator==(std::nullptr_t) const override;
		
		void invoke();
	
	protected:
		static void _bind_methods();
		
	};
	
	class FCallable1 : public FCallable {
	GDCLASS(FCallable1, FCallable);
	
	public:
		using FunctionType = function<void(const Variant&)>;
	
	private:
		FunctionType callableFunc;
	
	public:
		FCallable1() = default;
		static Ref<FCallable1> make(const Callable& init_callable);
		FCallable1(const FunctionType& init_callableFunc);
		virtual bool operator==(std::nullptr_t) const override;
		
		void invoke(const Variant& arg);
	
	protected:
		static void _bind_methods();
		
	};
}

#endif //FBLOCKWORLD3D_FCALLABLE_H
