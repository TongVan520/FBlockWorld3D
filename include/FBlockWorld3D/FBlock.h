//
// Created by FireFlower on 2024/12/8.
//

#ifndef FBLOCKWORLD3D_FBLOCK_H
#define FBLOCKWORLD3D_FBLOCK_H

#include <cstdint>

namespace fireflower {
	/// @类名 方块
	/// @描述 <b>抽象类</b>
	class FBlock {
	public:
		using IntType = int32_t;
	
	public:
		/// @名称 获取方块ID
		/// @描述 此ID与<code>MeshLibrary</code>中的<i>Item ID</i>相对应
		/// @返回值 方块ID
		virtual IntType getId() const = 0;
		
		/// @名称 判断方块是否为空
		/// @返回值 是否为空
		virtual bool isNull() const = 0;
		
		/// @名称 获取方块的旋转方向
		/// @描述 参考<code>GridMap::get_orthogonal_index_from_basis</code> https://docs.godotengine.org/zh-cn/4.x/classes/class_gridmap.html#class-gridmap-method-get-orthogonal-index-from-basis
		/// @返回值 方块的旋转方向
		virtual IntType getOrientation() const = 0;
	
	};
	
	/// @类名 普通方块
	/// @描述 <code>FBlock</code>的一个预设类型
	class FNormalBlock : public FBlock {
	private:
		IntType id = -1;
		IntType orientation = 0;
	
	public:
		FNormalBlock(const IntType& init_id, const IntType& init_orientation = 0);
		
		virtual void setId(const IntType& new_id);
		virtual IntType getId() const override;
		
		virtual bool isNull() const override;
		
		virtual void setOrientation(const IntType& new_orientation);
		virtual IntType getOrientation() const override;
		
	};
} // fireflower

#endif //FBLOCKWORLD3D_FBLOCK_H
