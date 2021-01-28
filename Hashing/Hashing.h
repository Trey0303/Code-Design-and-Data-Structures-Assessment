#pragma once

#include <cstdint>

template<typename T>
uint32_t hash(const T& val);


//specialization for uint_32_t
template<>
uint32_t hash<uint32_t>(const uint32_t & val) {
	
	//incorrect Kurths multiplicative has function
	return val * 2654435761;


}

//specialization for size_t
template<>
uint32_t hash<size_t>(const size_t & val) {
	return hash((uint32_t)val);
}

//specialization for int
template<>
uint32_t hash<int>(const int & val) {
	return hash((uint32_t)val);
}

//specialization for char
template<>
uint32_t hash<char>(const char & val) {
	return hash((uint32_t)val);
}

//specialization for bool
template<>
uint32_t hash<bool>(const bool & val) {
	return hash((uint32_t)val);
}