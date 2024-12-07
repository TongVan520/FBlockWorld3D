//
// Created by FireFlower on 2024/12/4.
//

#ifndef FBLOCKWORLD3D_FREGION3I_H
#define FBLOCKWORLD3D_FREGION3I_H

#include <godot_cpp/variant/vector3i.hpp>
#include <godot_cpp/variant/typed_array.hpp>

#include <vector>

using godot::Vector3i, godot::TypedArray;
using std::vector;

namespace fireflower {
	/// @类名 3维区域（整型）
	class FRegion3i {
	private:
		/// @名称 起始位置
		/// @描述 包含区域边界
		Vector3i beginVec3i;
		
		/// @名称 结束位置
		/// @描述 <b>不包含</b>区域边界
		Vector3i endVec3i;
	
	public:
		FRegion3i() = default;
		FRegion3i(const FRegion3i& otherRegion3i) = default;
		FRegion3i& operator=(const FRegion3i& otherRegion3i) = default;
		virtual ~FRegion3i() = default;
		
		/// @名称 构造函数
		/// @描述 通过<i>起始位置</i>和<i>结束位置</i>构造一个区域
		/// @参数名称 <code>init_beginVec3i</code>
		/// @参数描述 起始位置（包含）
		/// @参数名称 <code>init_endVec3i</code>
		/// @参数描述 结束位置（<b>不包含</b>）
		FRegion3i(const Vector3i& init_beginVec3i, const Vector3i& init_endVec3i);
		
		/// @名称 构造函数
		/// @描述 通过<i>中心位置</i>和<i>大小</i>构造一个区域
		/// @参数名称 <code>centerVec3i</code>
		/// @参数描述 中心位置
		/// @参数名称 <code>sizeVec3i</code>
		/// @参数描述 区域大小
		static FRegion3i makeFromCenterSize(const Vector3i& centerVec3i, const Vector3i& sizeVec3i);
		
		void setBegin(const Vector3i& newBeginVec3i);
		Vector3i getBegin() const;
		
		void setEnd(const Vector3i& newEndVec3i);
		Vector3i getEnd() const;
		
		/// @名称 获取区域所包含的位置集合
		/// @返回值 位置集合
		TypedArray<Vector3i> getIncludedPositions() const;
		explicit operator vector<Vector3i>() const;
		
		/// @名称 相交
		/// @参数名称 <code>otherRegion3i</code>
		/// @参数描述 另一区域
		/// @返回值 <i>当前区域</i>与<i>另一区域</i>相交的区域
		FRegion3i intersect(const FRegion3i& otherRegion3i) const;
		
		/// @名称 排除
		/// @参数名称 <code>otherRegion3i</code>
		/// @参数描述 另一区域
		/// @返回值 排除<i>另一区域</i>后的区域所包含的<b>位置集合</b>
		TypedArray<Vector3i> exclude(const FRegion3i& otherRegion3i) const;
		
		/// @名称 判断是否包含指定位置
		/// @参数名称 <code>positionVec3i</code>
		/// @参数描述 位置
		/// @返回值 是否包含
		bool isContain(const Vector3i& positionVec3i) const;
	};
}

#endif //FBLOCKWORLD3D_FREGION3I_H
