//
// Created by FireFlower on 2024/11/21.
//

#ifndef FBLOCKWORLD3D_FSIGNAL_H
#define FBLOCKWORLD3D_FSIGNAL_H

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include <godot_cpp/core/object.hpp>

/// 请在<code>register_types.cpp</code>中使用
#define FRegisterFSignal \
GDREGISTER_ABSTRACT_CLASS(fireflower::FSignal);\
GDREGISTER_CLASS(fireflower::FSignal0);        \
GDREGISTER_CLASS(fireflower::FSignal1);        \

namespace fireflower {
	using namespace godot;
	
	/// @类名 信号
	/// @描述 与Godot内置的<code>Signal</code>的区别：\n
	/// <code>FSignal</code>不依赖对象，可以独立使用
	class FSignal : public RefCounted {
	GDCLASS(FSignal, RefCounted);
	
	public:
		Error connectSignal(const Callable& callable, uint32_t flags = 0);
		void disconnectSignal(const Callable& callable);
		bool isConnected(const Callable& callable) const;
		// void emitSignal(const Variant** args, GDExtensionInt arg_count, GDExtensionCallError& error);
	
	protected:
		static void _bind_methods();
		static StringName getSignalName();
		
	};
	
	/// @类名 信号（无参数）
	/// @描述 无参数的信号
	class FSignal0 : public FSignal {
	GDCLASS(FSignal0, FSignal);
	
	public:
		void emitSignal();
	
	protected:
		static void _bind_methods();
		
	};
	
	/// @类名 信号（单参数）
	/// @描述 只有<code>1</code>个参数的信号
	class FSignal1 : public FSignal {
	GDCLASS(FSignal1, FSignal);
	
	public:
		void emitSignal(const Variant& arg);
	
	protected:
		static void _bind_methods();
		
	};
}

#endif //FBLOCKWORLD3D_FSIGNAL_H
