//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// bwtree_index.cpp
//
// Identification: src/index/bwtree_index.cpp
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "common/logger.h"
#include "index/bwtree_index.h"
#include "index/index_key.h"
#include "storage/tuple.h"

namespace peloton {
namespace index {

template <typename KeyType, typename ValueType, class KeyComparator,
          class KeyEqualityChecker>
BWTreeIndex<KeyType, ValueType, KeyComparator, KeyEqualityChecker>::BWTreeIndex(
    IndexMetadata *metadata)
    : Index(metadata), equals(metadata), comparator(metadata) {
  // Add your implementation here
}

template <typename KeyType, typename ValueType, class KeyComparator,
          class KeyEqualityChecker>
BWTreeIndex<KeyType, ValueType, KeyComparator,
            KeyEqualityChecker>::~BWTreeIndex() {
  // Add your implementation here
}

template <typename KeyType, typename ValueType, class KeyComparator,
          class KeyEqualityChecker>
bool BWTreeIndex<KeyType, ValueType, KeyComparator,
                 KeyEqualityChecker>::InsertEntry(UNUSED_ATTRIBUTE const
                                                  storage::Tuple *key,
                                                  UNUSED_ATTRIBUTE const
                                                  ItemPointer &location) {
  // Add your implementation here
  return false;
}

template <typename KeyType, typename ValueType, class KeyComparator,
          class KeyEqualityChecker>
bool BWTreeIndex<KeyType, ValueType, KeyComparator,
                 KeyEqualityChecker>::DeleteEntry(UNUSED_ATTRIBUTE const
                                                  storage::Tuple *key,
                                                  UNUSED_ATTRIBUTE const
                                                  ItemPointer &location) {
  // Add your implementation here
  return false;
}

template <typename KeyType, typename ValueType, class KeyComparator,
          class KeyEqualityChecker>
bool BWTreeIndex<KeyType, ValueType, KeyComparator,
                 KeyEqualityChecker>::CondInsertEntry(
    UNUSED_ATTRIBUTE const storage::Tuple *key,
    UNUSED_ATTRIBUTE const ItemPointer &location, UNUSED_ATTRIBUTE
    std::function<bool(const ItemPointer &)> predicate) {
  return false;
}

template <typename KeyType, typename ValueType, class KeyComparator,
          class KeyEqualityChecker>
void BWTreeIndex<KeyType, ValueType, KeyComparator, KeyEqualityChecker>::Scan(
    UNUSED_ATTRIBUTE const std::vector<Value> &values,
    UNUSED_ATTRIBUTE const std::vector<oid_t> &key_column_ids,
    UNUSED_ATTRIBUTE const std::vector<ExpressionType> &expr_types,
    UNUSED_ATTRIBUTE const ScanDirectionType &scan_direction,
    UNUSED_ATTRIBUTE std::vector<ItemPointer> &result) {}

template <typename KeyType, typename ValueType, class KeyComparator,
          class KeyEqualityChecker>
void
BWTreeIndex<KeyType, ValueType, KeyComparator, KeyEqualityChecker>::ScanAllKeys(
    UNUSED_ATTRIBUTE std::vector<ItemPointer> &result) {}

template <typename KeyType, typename ValueType, class KeyComparator,
          class KeyEqualityChecker>
void
BWTreeIndex<KeyType, ValueType, KeyComparator, KeyEqualityChecker>::ScanKey(
    UNUSED_ATTRIBUTE const storage::Tuple *key,
    UNUSED_ATTRIBUTE std::vector<ItemPointer> &result) {}

template <typename KeyType, typename ValueType, class KeyComparator,
          class KeyEqualityChecker>
void BWTreeIndex<KeyType, ValueType, KeyComparator, KeyEqualityChecker>::Scan(
    UNUSED_ATTRIBUTE const std::vector<Value> &values,
    UNUSED_ATTRIBUTE const std::vector<oid_t> &key_column_ids,
    UNUSED_ATTRIBUTE const std::vector<ExpressionType> &expr_types,
    UNUSED_ATTRIBUTE const ScanDirectionType &scan_direction,
    UNUSED_ATTRIBUTE std::vector<ItemPointer *> &result) {}

template <typename KeyType, typename ValueType, class KeyComparator,
          class KeyEqualityChecker>
void
BWTreeIndex<KeyType, ValueType, KeyComparator, KeyEqualityChecker>::ScanAllKeys(
    UNUSED_ATTRIBUTE std::vector<ItemPointer *> &result) {}

template <typename KeyType, typename ValueType, class KeyComparator,
          class KeyEqualityChecker>
void
BWTreeIndex<KeyType, ValueType, KeyComparator, KeyEqualityChecker>::ScanKey(
    UNUSED_ATTRIBUTE const storage::Tuple *key,
    UNUSED_ATTRIBUTE std::vector<ItemPointer *> &result) {}

template <typename KeyType, typename ValueType, class KeyComparator,
          class KeyEqualityChecker>
std::string BWTreeIndex<KeyType, ValueType, KeyComparator,
                        KeyEqualityChecker>::GetTypeName() const {
  return "BWTree";
}

// Explicit template instantiation
template class BWTreeIndex<IntsKey<1>, ItemPointer *,
                           IntsComparator<1>, IntsEqualityChecker<1>>;
template class BWTreeIndex<IntsKey<2>, ItemPointer *,
                           IntsComparator<2>, IntsEqualityChecker<2>>;
template class BWTreeIndex<IntsKey<3>, ItemPointer *,
                           IntsComparator<3>, IntsEqualityChecker<3>>;
template class BWTreeIndex<IntsKey<4>, ItemPointer *,
                           IntsComparator<4>, IntsEqualityChecker<4>>;

template class BWTreeIndex<GenericKey<4>, ItemPointer *,
                           GenericComparator<4>, GenericEqualityChecker<4>>;
template class BWTreeIndex<GenericKey<8>, ItemPointer *,
                           GenericComparator<8>, GenericEqualityChecker<8>>;
template class BWTreeIndex<GenericKey<12>, ItemPointer *,
                           GenericComparator<12>, GenericEqualityChecker<12>>;
template class BWTreeIndex<GenericKey<16>, ItemPointer *,
                           GenericComparator<16>, GenericEqualityChecker<16>>;
template class BWTreeIndex<GenericKey<24>, ItemPointer *,
                           GenericComparator<24>, GenericEqualityChecker<24>>;
template class BWTreeIndex<GenericKey<32>, ItemPointer *,
                           GenericComparator<32>, GenericEqualityChecker<32>>;
template class BWTreeIndex<GenericKey<48>, ItemPointer *,
                           GenericComparator<48>, GenericEqualityChecker<48>>;
template class BWTreeIndex<GenericKey<64>, ItemPointer *,
                           GenericComparator<64>, GenericEqualityChecker<64>>;
template class BWTreeIndex<GenericKey<96>, ItemPointer *,
                           GenericComparator<96>, GenericEqualityChecker<96>>;
template class BWTreeIndex<GenericKey<128>, ItemPointer *,
                           GenericComparator<128>, GenericEqualityChecker<128>>;
template class BWTreeIndex<GenericKey<256>, ItemPointer *,
                           GenericComparator<256>, GenericEqualityChecker<256>>;
template class BWTreeIndex<GenericKey<512>, ItemPointer *,
                           GenericComparator<512>, GenericEqualityChecker<512>>;

template class BWTreeIndex<TupleKey, ItemPointer *, TupleKeyComparator,
                           TupleKeyEqualityChecker>;

}  // End index namespace
}  // End peloton namespace