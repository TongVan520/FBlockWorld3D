//
// Created by FireFlower on 2024/12/8.
//

#include "FBlock.h"

// FBlock
namespace fireflower {

}

// FNormalBlock
namespace fireflower {
	FNormalBlock::FNormalBlock(const FBlock::IntType& init_id, const FBlock::IntType& init_orientation) :
		id(init_id), orientation(init_orientation) {
		
	}
	
	void FNormalBlock::setId(const FBlock::IntType& new_id) {
		this->id = new_id;
	}
	
	FBlock::IntType FNormalBlock::getId() const {
		return this->id;
	}
	
	bool FNormalBlock::isNull() const {
		return this->id == -1;
	}
	
	void FNormalBlock::setOrientation(const FBlock::IntType& new_orientation) {
		this->orientation = new_orientation;
	}
	
	FBlock::IntType FNormalBlock::getOrientation() const {
		return this->orientation;
	}
}
