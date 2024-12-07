//
// Created by FireFlower on 2024/12/7.
//

#ifndef FBLOCKWORLD3D_FINNATETERRIANMAID_H
#define FBLOCKWORLD3D_FINNATETERRIANMAID_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/vector3i.hpp>
#include <godot_cpp/classes/fast_noise_lite.hpp>

#include <memory>

#include "FBlock.h"

using godot::Node, godot::Vector3i, godot::Ref, godot::FastNoiseLite;
using std::shared_ptr;

namespace fireflower {
	/// @类名 先天地形女仆
	/// @描述 管理先天地形\n
	/// <b>抽象类</b>
	class FInnateTerrianMaid : public Node {
	GDCLASS(FInnateTerrianMaid, Node);
	
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
	
	/// @类名 种子先天地形女仆
	/// @描述 使用种子生成先天地形
	class FSeedInnateTerrainMaid : public FInnateTerrianMaid {
	GDCLASS(FSeedInnateTerrainMaid, FInnateTerrianMaid)
	
	private:
		Ref <FastNoiseLite> noise;
	
	public:
		virtual shared_ptr <FBlock> getBlock(const Vector3i& positionVec3i) const override;
		
		virtual void _ready() override;
	
	protected:
		static void _bind_methods();
		
	};
	
} // fireflower

#endif //FBLOCKWORLD3D_FINNATETERRIANMAID_H
