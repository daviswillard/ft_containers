cmake_minimum_required(VERSION 3.21)
project(ft_containers CXX)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)
include_directories(include)
include_directories(include/algorithm)
include_directories(include/iterator)
include_directories(include/map)
include_directories(include/utils)

add_executable(ft_containers
        include/algorithm/equal.h
        include/algorithm/lexicographical_compare.h
        include/iterator/adv_dist.h
        include/iterator/base.h
        include/iterator/dist_type.h
        include/iterator/insert_iterator.h
        include/iterator/inserter.h
        include/iterator/iter_cat.h
        include/iterator/iterator.h
        include/iterator/iterator_tag.h
        include/iterator/iterator_traits.h
        include/iterator/random_access_iterator.h
        include/iterator/reverse_iterator.h
        include/iterator/val_type.h
        include/map/map.h
        include/utils/enable_if.h
        include/utils/integral_constant.h
        include/utils/pair.h
        include/utils/utils.h
        include/core.h
        include/xtree/TreeIterator.h
        test_set.cpp
        include/algorithm/mismatch.h
        include/xtree/TreeInsert.h
        include/xtree/TreeErase.h
        include/xtree/TreeCopy.h
        include/xtree/TreeCIterator.h
        include/map/map_traits.h
        include/vector/vector.h
        include/vector/base_vec.h
        include/vector/protected_vec.h
        include/vector/constructors_vec.h
        include/vector/funcs.h
        include/vector/sequence_access.h
        include/vector/template_functions.h
        include/algorithm/fill.h)
