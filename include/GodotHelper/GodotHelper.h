//
// Created by FireFlower on 2024/11/21.
//

#ifndef FBLOCKWORLD3D_GODOTHELPER_H
#define FBLOCKWORLD3D_GODOTHELPER_H

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/weak_ref.hpp>

namespace fireflower {
	
	/// @名称 直接子节点引用
	/// @描述 创建并引用一个直接子节点\n
	/// 在类声明中使用\n
	/// 记得调用宏<code>InitDirectChildNodeRef</code>或对应<code>initRef</code>函数
#define DirectChildNodeRef(node_type, var_name, node_name) \
private:                                                   \
    ::godot::Ref<::godot::WeakRef> _##var_name;            \
                                                           \
private:                                                   \
    node_type* get##var_name() const {                     \
        return ::godot::Object::cast_to<node_type>(this->_##var_name->get_ref()); \
    }                                                      \
                                                           \
public:                                                    \
    void initRef##var_name() {                             \
        auto p_##var_name = memnew(node_type);             \
        p_##var_name->set_name(node_name);                 \
        p_##var_name->set_unique_name_in_owner(true);      \
        this->add_child(p_##var_name, true, InternalMode::INTERNAL_MODE_FRONT);   \
        p_##var_name->set_owner(this);                     \
                                                           \
        this->_##var_name = Ref(                           \
            ::godot::Object::cast_to<::godot::WeakRef>(    \
                ::godot::UtilityFunctions::weakref(        \
                    p_##var_name                           \
                )                                          \
            )                                              \
        );                                                 \
    }                                                      \
private:
	
	/// 在函数<code>_ready()</code>中或信号<code>ready()</code>回调中使用
#define InitDirectChildNodeRef(var_name) this->init##var_name##Ref()

}

#endif //FBLOCKWORLD3D_GODOTHELPER_H
