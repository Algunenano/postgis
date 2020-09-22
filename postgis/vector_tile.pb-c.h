/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: vector_tile.proto */

#ifndef PROTOBUF_C_vector_5ftile_2eproto__INCLUDED
#define PROTOBUF_C_vector_5ftile_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003003 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _VectorTile__Tile VectorTile__Tile;
typedef struct _VectorTile__Tile__Value VectorTile__Tile__Value;
typedef struct _VectorTile__Tile__Feature VectorTile__Tile__Feature;
typedef struct _VectorTile__Tile__Layer VectorTile__Tile__Layer;


/* --- enums --- */

/*
 * GeomType is described in section 4.3.4 of the specification
 */
typedef enum _VectorTile__Tile__GeomType {
  VECTOR_TILE__TILE__GEOM_TYPE__UNKNOWN = 0,
  VECTOR_TILE__TILE__GEOM_TYPE__POINT = 1,
  VECTOR_TILE__TILE__GEOM_TYPE__LINESTRING = 2,
  VECTOR_TILE__TILE__GEOM_TYPE__POLYGON = 3
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(VECTOR_TILE__TILE__GEOM_TYPE)
} VectorTile__Tile__GeomType;

/* --- messages --- */

typedef enum {
  VECTOR_TILE__TILE__VALUE__TEST_ONEOF__NOT_SET = 0,
  VECTOR_TILE__TILE__VALUE__TEST_ONEOF_STRING_VALUE = 1,
  VECTOR_TILE__TILE__VALUE__TEST_ONEOF_FLOAT_VALUE = 2,
  VECTOR_TILE__TILE__VALUE__TEST_ONEOF_DOUBLE_VALUE = 3,
  VECTOR_TILE__TILE__VALUE__TEST_ONEOF_INT_VALUE = 4,
  VECTOR_TILE__TILE__VALUE__TEST_ONEOF_UINT_VALUE = 5,
  VECTOR_TILE__TILE__VALUE__TEST_ONEOF_SINT_VALUE = 6,
  VECTOR_TILE__TILE__VALUE__TEST_ONEOF_BOOL_VALUE = 7
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(VECTOR_TILE__TILE__VALUE__TEST_ONEOF)
} VectorTile__Tile__Value__TestOneofCase;

/*
 * Variant type encoding
 * The use of values is described in section 4.1 of the specification
 * PostGIS: Made oneof (protobuf-c 1.1+ required) to reduce memory usage
 */
struct  _VectorTile__Tile__Value
{
  ProtobufCMessage base;
  VectorTile__Tile__Value__TestOneofCase test_oneof_case;
  union {
    char *string_value;
    float float_value;
    double double_value;
    int64_t int_value;
    uint64_t uint_value;
    int64_t sint_value;
    protobuf_c_boolean bool_value;
  };
};
#define VECTOR_TILE__TILE__VALUE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&vector_tile__tile__value__descriptor) \
    , VECTOR_TILE__TILE__VALUE__TEST_ONEOF__NOT_SET, {0} }


/*
 * Features are described in section 4.2 of the specification
 */
struct  _VectorTile__Tile__Feature
{
  ProtobufCMessage base;
  protobuf_c_boolean has_id;
  uint64_t id;
  /*
   * Tags of this feature are encoded as repeated pairs of
   * integers.
   * A detailed description of tags is located in sections
   * 4.2 and 4.4 of the specification
   */
  size_t n_tags;
  uint32_t *tags;
  /*
   * The type of geometry stored in this feature.
   * PostGIS: Made mandatory
   */
  VectorTile__Tile__GeomType type;
  /*
   * Contains a stream of commands and parameters (vertices).
   * A detailed description on geometry encoding is located in
   * section 4.3 of the specification.
   */
  size_t n_geometry;
  uint32_t *geometry;
};
#define VECTOR_TILE__TILE__FEATURE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&vector_tile__tile__feature__descriptor) \
    , 0, 0ull, 0,NULL, VECTOR_TILE__TILE__GEOM_TYPE__UNKNOWN, 0,NULL }


/*
 * Layers are described in section 4.1 of the specification
 */
struct  _VectorTile__Tile__Layer
{
  ProtobufCMessage base;
  /*
   * Any compliant implementation must first read the version
   * number encoded in this message and choose the correct
   * implementation for this version number before proceeding to
   * decode other parts of this message.
   */
  uint32_t version;
  char *name;
  /*
   * The actual features in this tile.
   */
  size_t n_features;
  VectorTile__Tile__Feature **features;
  /*
   * Dictionary encoding for keys
   */
  size_t n_keys;
  char **keys;
  /*
   * Dictionary encoding for values
   */
  size_t n_values;
  VectorTile__Tile__Value **values;
  /*
   * PostGIS: Made mandatory (see https://github.com/mapbox/vector-tile-spec/issues/47)
   */
  uint32_t extent;
};
#define VECTOR_TILE__TILE__LAYER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&vector_tile__tile__layer__descriptor) \
    , 1u, NULL, 0,NULL, 0,NULL, 0,NULL, 4096u }


struct  _VectorTile__Tile
{
  ProtobufCMessage base;
  size_t n_layers;
  VectorTile__Tile__Layer **layers;
};
#define VECTOR_TILE__TILE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&vector_tile__tile__descriptor) \
    , 0,NULL }


/* VectorTile__Tile__Value methods */
void   vector_tile__tile__value__init
                     (VectorTile__Tile__Value         *message);
/* VectorTile__Tile__Feature methods */
void   vector_tile__tile__feature__init
                     (VectorTile__Tile__Feature         *message);
/* VectorTile__Tile__Layer methods */
void   vector_tile__tile__layer__init
                     (VectorTile__Tile__Layer         *message);
/* VectorTile__Tile methods */
void   vector_tile__tile__init
                     (VectorTile__Tile         *message);
size_t vector_tile__tile__get_packed_size
                     (const VectorTile__Tile   *message);
size_t vector_tile__tile__pack
                     (const VectorTile__Tile   *message,
                      uint8_t             *out);
size_t vector_tile__tile__pack_to_buffer
                     (const VectorTile__Tile   *message,
                      ProtobufCBuffer     *buffer);
VectorTile__Tile *
       vector_tile__tile__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   vector_tile__tile__free_unpacked
                     (VectorTile__Tile *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*VectorTile__Tile__Value_Closure)
                 (const VectorTile__Tile__Value *message,
                  void *closure_data);
typedef void (*VectorTile__Tile__Feature_Closure)
                 (const VectorTile__Tile__Feature *message,
                  void *closure_data);
typedef void (*VectorTile__Tile__Layer_Closure)
                 (const VectorTile__Tile__Layer *message,
                  void *closure_data);
typedef void (*VectorTile__Tile_Closure)
                 (const VectorTile__Tile *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor vector_tile__tile__descriptor;
extern const ProtobufCMessageDescriptor vector_tile__tile__value__descriptor;
extern const ProtobufCMessageDescriptor vector_tile__tile__feature__descriptor;
extern const ProtobufCMessageDescriptor vector_tile__tile__layer__descriptor;
extern const ProtobufCEnumDescriptor    vector_tile__tile__geom_type__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_vector_5ftile_2eproto__INCLUDED */
