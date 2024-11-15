//
// Created by FireFlower on 2024/11/16.
//

#ifndef FBLOCKWORLD3D_FBLOCKWORLD3D_H
#define FBLOCKWORLD3D_FBLOCKWORLD3D_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/core/class_db.hpp>

namespace godot {
	/// @类名 3D方块世界
	/// @描述 自动生成、加载、保存地形的方块世界类
	class FBlockWorld3D : public Node3D {
	GDCLASS(FBlockWorld3D, Node3D);
	
	private:
	
	public:
		FBlockWorld3D() = default;
		
		virtual ~FBlockWorld3D() = default;
		
		FBlockWorld3D(const FBlockWorld3D&) = delete;
		
		// FBlockWorld3D& operator=(const FBlockWorld3D&) = delete;
		
		void sayHello() const;
	
	protected:
		static void _bind_methods();
		
	};
	
} // godot

#endif //FBLOCKWORLD3D_FBLOCKWORLD3D_H
