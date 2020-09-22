/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: geobuf.proto */

#ifndef PROTOBUF_C_geobuf_2eproto__INCLUDED
#define PROTOBUF_C_geobuf_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003003 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Data Data;
typedef struct _Data__Feature Data__Feature;
typedef struct _Data__Geometry Data__Geometry;
typedef struct _Data__FeatureCollection Data__FeatureCollection;
typedef struct _Data__Value Data__Value;


/* --- enums --- */

typedef enum _Data__Geometry__Type {
  DATA__GEOMETRY__TYPE__POINT = 0,
  DATA__GEOMETRY__TYPE__MULTIPOINT = 1,
  DATA__GEOMETRY__TYPE__LINESTRING = 2,
  DATA__GEOMETRY__TYPE__MULTILINESTRING = 3,
  DATA__GEOMETRY__TYPE__POLYGON = 4,
  DATA__GEOMETRY__TYPE__MULTIPOLYGON = 5,
  DATA__GEOMETRY__TYPE__GEOMETRYCOLLECTION = 6
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(DATA__GEOMETRY__TYPE)
} Data__Geometry__Type;

/* --- messages --- */

typedef enum {
  DATA__FEATURE__ID_TYPE__NOT_SET = 0,
  DATA__FEATURE__ID_TYPE_ID = 11,
  DATA__FEATURE__ID_TYPE_INT_ID = 12
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(DATA__FEATURE__ID_TYPE)
} Data__Feature__IdTypeCase;

struct  _Data__Feature
{
  ProtobufCMessage base;
  Data__Geometry *geometry;
  /*
   * unique values
   */
  size_t n_values;
  Data__Value **values;
  /*
   * pairs of key/value indexes
   */
  size_t n_properties;
  uint32_t *properties;
  /*
   * arbitrary properties
   */
  size_t n_custom_properties;
  uint32_t *custom_properties;
  Data__Feature__IdTypeCase id_type_case;
  union {
    char *id;
    int64_t int_id;
  };
};
#define DATA__FEATURE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&data__feature__descriptor) \
    , NULL, 0,NULL, 0,NULL, 0,NULL, DATA__FEATURE__ID_TYPE__NOT_SET, {0} }


struct  _Data__Geometry
{
  ProtobufCMessage base;
  Data__Geometry__Type type;
  /*
   * coordinate structure in lengths
   */
  size_t n_lengths;
  uint32_t *lengths;
  /*
   * delta-encoded integer values
   */
  size_t n_coords;
  int64_t *coords;
  size_t n_geometries;
  Data__Geometry **geometries;
  size_t n_values;
  Data__Value **values;
  size_t n_custom_properties;
  uint32_t *custom_properties;
};
#define DATA__GEOMETRY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&data__geometry__descriptor) \
    , DATA__GEOMETRY__TYPE__POINT, 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL }


struct  _Data__FeatureCollection
{
  ProtobufCMessage base;
  size_t n_features;
  Data__Feature **features;
  size_t n_values;
  Data__Value **values;
  size_t n_custom_properties;
  uint32_t *custom_properties;
};
#define DATA__FEATURE_COLLECTION__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&data__feature_collection__descriptor) \
    , 0,NULL, 0,NULL, 0,NULL }


typedef enum {
  DATA__VALUE__VALUE_TYPE__NOT_SET = 0,
  DATA__VALUE__VALUE_TYPE_STRING_VALUE = 1,
  DATA__VALUE__VALUE_TYPE_DOUBLE_VALUE = 2,
  DATA__VALUE__VALUE_TYPE_POS_INT_VALUE = 3,
  DATA__VALUE__VALUE_TYPE_NEG_INT_VALUE = 4,
  DATA__VALUE__VALUE_TYPE_BOOL_VALUE = 5,
  DATA__VALUE__VALUE_TYPE_JSON_VALUE = 6
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(DATA__VALUE__VALUE_TYPE)
} Data__Value__ValueTypeCase;

struct  _Data__Value
{
  ProtobufCMessage base;
  Data__Value__ValueTypeCase value_type_case;
  union {
    char *string_value;
    double double_value;
    uint64_t pos_int_value;
    uint64_t neg_int_value;
    protobuf_c_boolean bool_value;
    char *json_value;
  };
};
#define DATA__VALUE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&data__value__descriptor) \
    , DATA__VALUE__VALUE_TYPE__NOT_SET, {0} }


typedef enum {
  DATA__DATA_TYPE__NOT_SET = 0,
  DATA__DATA_TYPE_FEATURE_COLLECTION = 4,
  DATA__DATA_TYPE_FEATURE = 5,
  DATA__DATA_TYPE_GEOMETRY = 6
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(DATA__DATA_TYPE)
} Data__DataTypeCase;

struct  _Data
{
  ProtobufCMessage base;
  /*
   * global arrays of unique keys
   */
  size_t n_keys;
  char **keys;
  /*
   * max coordinate dimensions
   */
  protobuf_c_boolean has_dimensions;
  uint32_t dimensions;
  /*
   * number of digits after decimal point for coordinates
   */
  protobuf_c_boolean has_precision;
  uint32_t precision;
  Data__DataTypeCase data_type_case;
  union {
    Data__FeatureCollection *feature_collection;
    Data__Feature *feature;
    Data__Geometry *geometry;
  };
};
#define DATA__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&data__descriptor) \
    , 0,NULL, 0, 2u, 0, 6u, DATA__DATA_TYPE__NOT_SET, {0} }


/* Data__Feature methods */
void   data__feature__init
                     (Data__Feature         *message);
/* Data__Geometry methods */
void   data__geometry__init
                     (Data__Geometry         *message);
/* Data__FeatureCollection methods */
void   data__feature_collection__init
                     (Data__FeatureCollection         *message);
/* Data__Value methods */
void   data__value__init
                     (Data__Value         *message);
/* Data methods */
void   data__init
                     (Data         *message);
size_t data__get_packed_size
                     (const Data   *message);
size_t data__pack
                     (const Data   *message,
                      uint8_t             *out);
size_t data__pack_to_buffer
                     (const Data   *message,
                      ProtobufCBuffer     *buffer);
Data *
       data__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   data__free_unpacked
                     (Data *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Data__Feature_Closure)
                 (const Data__Feature *message,
                  void *closure_data);
typedef void (*Data__Geometry_Closure)
                 (const Data__Geometry *message,
                  void *closure_data);
typedef void (*Data__FeatureCollection_Closure)
                 (const Data__FeatureCollection *message,
                  void *closure_data);
typedef void (*Data__Value_Closure)
                 (const Data__Value *message,
                  void *closure_data);
typedef void (*Data_Closure)
                 (const Data *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor data__descriptor;
extern const ProtobufCMessageDescriptor data__feature__descriptor;
extern const ProtobufCMessageDescriptor data__geometry__descriptor;
extern const ProtobufCEnumDescriptor    data__geometry__type__descriptor;
extern const ProtobufCMessageDescriptor data__feature_collection__descriptor;
extern const ProtobufCMessageDescriptor data__value__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_geobuf_2eproto__INCLUDED */
