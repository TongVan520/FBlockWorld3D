//
// Created by FireFlower on 2024/12/8.
//

#ifndef FBLOCKWORLD3D_FACQUIREDTERRAINMAID_H
#define FBLOCKWORLD3D_FACQUIREDTERRAINMAID_H

#include <godot_cpp/classes/node.hpp>

#include <memory>

#include "FBlock.h"

using godot::Node, godot::Vector3i, godot::Ref;
using std::shared_ptr;

namespace fireflower {
	/// @类名 后天地形女仆
	/// @描述 管理后天地形\n
	/// <b>抽象类</b>
	class FAcquiredTerrainMaid : public Node {
	GDCLASS(FAcquiredTerrainMaid, Node);
	
	public:
		/// @名称 获取方块
		/// @描述 获取指定位置的方块
		/// @参数名称 <code>positionVec3i</code>
		/// @参数描述 位置
		/// @返回值 方块
		virtual shared_ptr <FBlock> getBlock(const Vector3i& positionVec3i) const = 0;
	
	protected:
		static void _bind_methods();
		
	};
	
	// class
	
} // fireflower

#endif //FBLOCKWORLD3D_FACQUIREDTERRAINMAID_H
