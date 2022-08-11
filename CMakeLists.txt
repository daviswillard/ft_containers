cmake_minimum_required(VERSION 3.21)
project(ft_containers CXX)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)
include_directories(include)
include_directories(include/algorithm)
include_directories(include/iterator)
include_directories(include/map)
include_directories(include/utility)
include_directories(include/set)
include_directories(include/xtree)
include_directories(include/stack)

add_executable(ft_containers
        include/functional/binary_function.hpp
        include/functional/less.hpp
        include/algorithm/equal.hpp
        include/algorithm/lexicographical_compare.hpp
        include/iterator/adv_dist.hpp
        include/iterator/base.hpp
        include/iterator/dist_type.hpp
        include/iterator/insert_iterator.hpp
        include/iterator/inserter.hpp
        include/iterator/iter_cat.hpp
        include/iterator/iterator.hpp
        include/iterator/iterator_tag.hpp
        include/iterator/iterator_traits.hpp
        include/iterator/random_access_iterator.hpp
        include/iterator/reverse_iterator.hpp
        include/iterator/val_type.hpp
        include/map/map.hpp
        include/utility/enable_if.hpp
        include/utility/integral_constant.hpp
        include/utility/pair.hpp
        include/utility/utility.hpp
        include/xtree/TreeIterator.hpp
        test_set.cpp
        include/algorithm/mismatch.hpp
        include/xtree/TreeInsert.hpp
        include/xtree/TreeErase.hpp
        include/xtree/TreeCopy.hpp
        include/xtree/TreeCIterator.hpp
        include/map/map_traits.hpp
        include/vector/vector.hpp
        include/vector/base_vec.hpp
        include/vector/protected_vec.hpp
        include/vector/constructors_vec.hpp
        include/vector/funcs.hpp
        include/vector/sequence_access.hpp
        include/vector/template_functions.hpp
        include/algorithm/fill.hpp
        include/stack/stack.hpp
        include/stack/stack_capacity.hpp
        include/stack/stack_element_access.hpp
        include/stack/stack_member_functions.hpp
        include/stack/stack_modifiers.hpp
        include/stack/stack_non_member_functions.hpp
        include/stack/stack_protected.hpp
        include/algorithm/algorithm.hpp)
