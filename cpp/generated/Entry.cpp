// Copyright 2004-present Facebook. All Rights Reserved.
// @generated SignedSource<<f763974fdc7595dd259410699c77dfb5>>

#include <cstring>
#include <stdexcept>
#include <loom/entries/Entry.h>

namespace facebook {
namespace loom {
namespace entries {

/* Alignment requirement: dst must be 4-byte aligned. */
void StandardEntry::pack(const StandardEntry& entry, void* dst, size_t size) {
  if (size < StandardEntry::calculateSize(entry)) {
      throw std::out_of_range("Cannot fit StandardEntry in destination");
  }
  if (dst == nullptr) {
      throw std::invalid_argument("dst == nullptr");
  }
  uint8_t* dst_byte = reinterpret_cast<uint8_t*>(dst);
  *dst_byte = kSerializationType;
  size_t offset = 1;

  
  std::memcpy((dst_byte) + offset, &(entry.id), sizeof((entry.id)));
  offset += sizeof((entry.id));
  
  
  std::memcpy((dst_byte) + offset, &(entry.type), sizeof((entry.type)));
  offset += sizeof((entry.type));
  
  
  std::memcpy((dst_byte) + offset, &(entry.timestamp), sizeof((entry.timestamp)));
  offset += sizeof((entry.timestamp));
  
  
  std::memcpy((dst_byte) + offset, &(entry.tid), sizeof((entry.tid)));
  offset += sizeof((entry.tid));
  
  
  std::memcpy((dst_byte) + offset, &(entry.callid), sizeof((entry.callid)));
  offset += sizeof((entry.callid));
  
  
  std::memcpy((dst_byte) + offset, &(entry.matchid), sizeof((entry.matchid)));
  offset += sizeof((entry.matchid));
  
  
  std::memcpy((dst_byte) + offset, &(entry.extra), sizeof((entry.extra)));
  offset += sizeof((entry.extra));
  
}


/* Alignment requirement: src must be 4-byte aligned. */
void StandardEntry::unpack(StandardEntry& entry, const void* src, size_t size) {
  if (src == nullptr) {
      throw std::invalid_argument("src == nullptr");
  }
  const uint8_t* src_byte = reinterpret_cast<const uint8_t*>(src);
  if (*src_byte != kSerializationType) {
      throw std::invalid_argument("Serialization type is incorrect");
  }
  size_t offset = 1;
  
  std::memcpy(&(entry.id), (src_byte) + offset, sizeof((entry.id)));
  offset += sizeof((entry.id));
  
  
  std::memcpy(&(entry.type), (src_byte) + offset, sizeof((entry.type)));
  offset += sizeof((entry.type));
  
  
  std::memcpy(&(entry.timestamp), (src_byte) + offset, sizeof((entry.timestamp)));
  offset += sizeof((entry.timestamp));
  
  
  std::memcpy(&(entry.tid), (src_byte) + offset, sizeof((entry.tid)));
  offset += sizeof((entry.tid));
  
  
  std::memcpy(&(entry.callid), (src_byte) + offset, sizeof((entry.callid)));
  offset += sizeof((entry.callid));
  
  
  std::memcpy(&(entry.matchid), (src_byte) + offset, sizeof((entry.matchid)));
  offset += sizeof((entry.matchid));
  
  
  std::memcpy(&(entry.extra), (src_byte) + offset, sizeof((entry.extra)));
  offset += sizeof((entry.extra));
  
}


size_t StandardEntry::calculateSize(StandardEntry const& entry) {
  size_t offset = 1 /*serialization format*/;
  (offset) += sizeof(entry.id);
  (offset) += sizeof(entry.type);
  (offset) += sizeof(entry.timestamp);
  (offset) += sizeof(entry.tid);
  (offset) += sizeof(entry.callid);
  (offset) += sizeof(entry.matchid);
  (offset) += sizeof(entry.extra);
  return offset;
}


/* Alignment requirement: dst must be 4-byte aligned. */
void FramesEntry::pack(const FramesEntry& entry, void* dst, size_t size) {
  if (size < FramesEntry::calculateSize(entry)) {
      throw std::out_of_range("Cannot fit FramesEntry in destination");
  }
  if (dst == nullptr) {
      throw std::invalid_argument("dst == nullptr");
  }
  uint8_t* dst_byte = reinterpret_cast<uint8_t*>(dst);
  *dst_byte = kSerializationType;
  size_t offset = 1;

  
  std::memcpy((dst_byte) + offset, &(entry.id), sizeof((entry.id)));
  offset += sizeof((entry.id));
  
  
  std::memcpy((dst_byte) + offset, &(entry.type), sizeof((entry.type)));
  offset += sizeof((entry.type));
  
  
  std::memcpy((dst_byte) + offset, &(entry.timestamp), sizeof((entry.timestamp)));
  offset += sizeof((entry.timestamp));
  
  
  std::memcpy((dst_byte) + offset, &(entry.tid), sizeof((entry.tid)));
  offset += sizeof((entry.tid));
  
  
  auto _size_size = sizeof(entry.frames.size);
  std::memcpy((dst_byte + offset), &(entry.frames.size), (_size_size));
  offset += _size_size;
  
  auto _values_size = (entry.frames.size) *
      sizeof(*entry.frames.values);
  // Must align target on a 4-byte boundary. Assuming dst_byte is aligned.
  offset = (offset + 0x03) & ~0x03;
  std::memcpy(
    (dst_byte + offset),
    (entry.frames.values),
    _values_size
  );
  offset += _values_size;
  
}


/* Alignment requirement: src must be 4-byte aligned. */
void FramesEntry::unpack(FramesEntry& entry, const void* src, size_t size) {
  if (src == nullptr) {
      throw std::invalid_argument("src == nullptr");
  }
  const uint8_t* src_byte = reinterpret_cast<const uint8_t*>(src);
  if (*src_byte != kSerializationType) {
      throw std::invalid_argument("Serialization type is incorrect");
  }
  size_t offset = 1;
  
  std::memcpy(&(entry.id), (src_byte) + offset, sizeof((entry.id)));
  offset += sizeof((entry.id));
  
  
  std::memcpy(&(entry.type), (src_byte) + offset, sizeof((entry.type)));
  offset += sizeof((entry.type));
  
  
  std::memcpy(&(entry.timestamp), (src_byte) + offset, sizeof((entry.timestamp)));
  offset += sizeof((entry.timestamp));
  
  
  std::memcpy(&(entry.tid), (src_byte) + offset, sizeof((entry.tid)));
  offset += sizeof((entry.tid));
  
  
  auto _size_size = sizeof(entry.frames.size);
  std::memcpy(&(entry.frames).size, (src_byte + offset), (_size_size));
  offset += _size_size;
  
  // Must align values on a 4-byte boundary. Assuming src_byte is aligned.
  offset = (offset + 0x03) & ~0x03;
  
  // Retains pointer to incoming data!
  (entry.frames).values = reinterpret_cast<decltype((entry.frames).values)>(
    (src_byte + offset)
  );
  offset += (entry.frames).size * sizeof(*(entry.frames).values);
  
}


size_t FramesEntry::calculateSize(FramesEntry const& entry) {
  size_t offset = 1 /*serialization format*/;
  (offset) += sizeof(entry.id);
  (offset) += sizeof(entry.type);
  (offset) += sizeof(entry.timestamp);
  (offset) += sizeof(entry.tid);
  // Must align entry.frames on a 4-byte boundary.
  offset = (offset + 0x03) & ~0x03;
  
  offset += sizeof(entry.frames.size) +
    entry.frames.size * sizeof(*entry.frames.values);
  return offset;
}


/* Alignment requirement: dst must be 4-byte aligned. */
void BytesEntry::pack(const BytesEntry& entry, void* dst, size_t size) {
  if (size < BytesEntry::calculateSize(entry)) {
      throw std::out_of_range("Cannot fit BytesEntry in destination");
  }
  if (dst == nullptr) {
      throw std::invalid_argument("dst == nullptr");
  }
  uint8_t* dst_byte = reinterpret_cast<uint8_t*>(dst);
  *dst_byte = kSerializationType;
  size_t offset = 1;

  
  std::memcpy((dst_byte) + offset, &(entry.id), sizeof((entry.id)));
  offset += sizeof((entry.id));
  
  
  std::memcpy((dst_byte) + offset, &(entry.type), sizeof((entry.type)));
  offset += sizeof((entry.type));
  
  
  std::memcpy((dst_byte) + offset, &(entry.matchid), sizeof((entry.matchid)));
  offset += sizeof((entry.matchid));
  
  
  auto _size_size = sizeof(entry.bytes.size);
  std::memcpy((dst_byte + offset), &(entry.bytes.size), (_size_size));
  offset += _size_size;
  
  auto _values_size = (entry.bytes.size) *
      sizeof(*entry.bytes.values);
  // Must align target on a 4-byte boundary. Assuming dst_byte is aligned.
  offset = (offset + 0x03) & ~0x03;
  std::memcpy(
    (dst_byte + offset),
    (entry.bytes.values),
    _values_size
  );
  offset += _values_size;
  
}


/* Alignment requirement: src must be 4-byte aligned. */
void BytesEntry::unpack(BytesEntry& entry, const void* src, size_t size) {
  if (src == nullptr) {
      throw std::invalid_argument("src == nullptr");
  }
  const uint8_t* src_byte = reinterpret_cast<const uint8_t*>(src);
  if (*src_byte != kSerializationType) {
      throw std::invalid_argument("Serialization type is incorrect");
  }
  size_t offset = 1;
  
  std::memcpy(&(entry.id), (src_byte) + offset, sizeof((entry.id)));
  offset += sizeof((entry.id));
  
  
  std::memcpy(&(entry.type), (src_byte) + offset, sizeof((entry.type)));
  offset += sizeof((entry.type));
  
  
  std::memcpy(&(entry.matchid), (src_byte) + offset, sizeof((entry.matchid)));
  offset += sizeof((entry.matchid));
  
  
  auto _size_size = sizeof(entry.bytes.size);
  std::memcpy(&(entry.bytes).size, (src_byte + offset), (_size_size));
  offset += _size_size;
  
  // Must align values on a 4-byte boundary. Assuming src_byte is aligned.
  offset = (offset + 0x03) & ~0x03;
  
  // Retains pointer to incoming data!
  (entry.bytes).values = reinterpret_cast<decltype((entry.bytes).values)>(
    (src_byte + offset)
  );
  offset += (entry.bytes).size * sizeof(*(entry.bytes).values);
  
}


size_t BytesEntry::calculateSize(BytesEntry const& entry) {
  size_t offset = 1 /*serialization format*/;
  (offset) += sizeof(entry.id);
  (offset) += sizeof(entry.type);
  (offset) += sizeof(entry.matchid);
  // Must align entry.bytes on a 4-byte boundary.
  offset = (offset + 0x03) & ~0x03;
  
  offset += sizeof(entry.bytes.size) +
    entry.bytes.size * sizeof(*entry.bytes.values);
  return offset;
}



uint8_t peek_type(const void* src, size_t len) {
  const uint8_t* src_byte = reinterpret_cast<const uint8_t*>(src);
  return *src_byte;
}

} // namespace entries
} // namespace loom
} // namespace facebook