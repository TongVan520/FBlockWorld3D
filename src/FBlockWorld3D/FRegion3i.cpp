//
// Created by FireFlower on 2024/12/4.
//

#include "FRegion3i.h"

#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

namespace fireflower {
	FRegion3i::FRegion3i(const Vector3i& init_beginVec3i, const Vector3i& init_endVec3i) :
		beginVec3i(init_beginVec3i), endVec3i(init_endVec3i) {
		
	}
	
	FRegion3i FRegion3i::makeFromCenterSize(const Vector3i& centerVec3i, const Vector3i& sizeVec3i) {
		Vector3 centerVec3 = centerVec3i + Vector3(0.5, 0.5, 0.5);
		Vector3 half_sizeVec3 = sizeVec3i / 2;
		return FRegion3i(
			(centerVec3 - half_sizeVec3).ceil(),
			(centerVec3 + half_sizeVec3).floor()
		);
	}
	
	void FRegion3i::setBegin(const Vector3i& newBeginVec3i) {
		this->beginVec3i = newBeginVec3i;
	}
	
	Vector3i FRegion3i::getBegin() const {
		return this->beginVec3i;
	}
	
	void FRegion3i::setEnd(const Vector3i& newEndVec3i) {
		this->endVec3i = newEndVec3i;
	}
	
	Vector3i FRegion3i::getEnd() const {
		return this->endVec3i;
	}
	
	TypedArray<Vector3i> FRegion3i::getIncludedPositions() const {
		auto resultVec3iArr = TypedArray<Vector3i>();
		using NumberType = int32_t;
		for (NumberType x = this->beginVec3i.x; x < this->endVec3i.x; x++) {
			for (NumberType y = this->beginVec3i.y; y < this->endVec3i.y; y++) {
				for (NumberType z = this->beginVec3i.z; z < this->endVec3i.z; z++) {
					resultVec3iArr.append(Vector3i(x, y, z));
				}
			}
		}
		return resultVec3iArr;
	}
	
	FRegion3i::operator vector<Vector3i>() const {
		auto resultVec3iVec = vector<Vector3i>();
		using NumberType = int32_t;
		for (NumberType x = this->beginVec3i.x; x < this->endVec3i.x; x++) {
			for (NumberType y = this->beginVec3i.y; y < this->endVec3i.y; y++) {
				for (NumberType z = this->beginVec3i.z; z < this->endVec3i.z; z++) {
					resultVec3iVec.push_back(Vector3i(x, y, z));
				}
			}
		}
		return resultVec3iVec;
	}
	
	FRegion3i FRegion3i::intersect(const FRegion3i& otherRegion3i) const {
		return FRegion3i(
			this->beginVec3i.max(otherRegion3i.beginVec3i),
			this->endVec3i.min(otherRegion3i.endVec3i)
		);
	}
	
	TypedArray<Vector3i> FRegion3i::exclude(const FRegion3i& otherRegion3i) const {
		auto resultVec3iArr = TypedArray<Vector3i>();
		using NumberType = int32_t;
		for (NumberType x = this->beginVec3i.x; x < this->endVec3i.x; x++) {
			for (NumberType y = this->beginVec3i.y; y < this->endVec3i.y; y++) {
				for (NumberType z = this->beginVec3i.z; z < this->endVec3i.z; z++) {
					auto positionVec3i = Vector3i(x, y, z);
					// 排除otherRegion3i中的位置
					if (otherRegion3i.isContain(positionVec3i)) {
						continue;
					}
					resultVec3iArr.append(positionVec3i);
				}
			}
		}
		return resultVec3iArr;
	}
	
	bool FRegion3i::isContain(const Vector3i& positionVec3i) const {
		return this->beginVec3i <= positionVec3i and positionVec3i < this->endVec3i;
	}
}
