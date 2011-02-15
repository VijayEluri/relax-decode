# Generated by the protocol buffer compiler.  DO NOT EDIT!

from google.protobuf import descriptor
from google.protobuf import message
from google.protobuf import reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)


import hypergraph_pb2

DESCRIPTOR = descriptor.FileDescriptor(
  name='tag.proto',
  package='',
  serialized_pb='\n\ttag.proto\x1a\x10hypergraph.proto\"&\n\x07Tagging\x12\x0b\n\x03ind\x18\x01 \x02(\x05\x12\x0e\n\x06tag_id\x18\x02 \x02(\x05:+\n\x07tagging\x12\x10.Hypergraph.Edge\x18x \x01(\x0b\x32\x08.Tagging:%\n\x0bhas_tagging\x12\x10.Hypergraph.Edge\x18y \x01(\x08')


TAGGING_FIELD_NUMBER = 120
tagging = descriptor.FieldDescriptor(
  name='tagging', full_name='tagging', index=0,
  number=120, type=11, cpp_type=10, label=1,
  has_default_value=False, default_value=None,
  message_type=None, enum_type=None, containing_type=None,
  is_extension=True, extension_scope=None,
  options=None)
HAS_TAGGING_FIELD_NUMBER = 121
has_tagging = descriptor.FieldDescriptor(
  name='has_tagging', full_name='has_tagging', index=1,
  number=121, type=8, cpp_type=7, label=1,
  has_default_value=False, default_value=False,
  message_type=None, enum_type=None, containing_type=None,
  is_extension=True, extension_scope=None,
  options=None)


_TAGGING = descriptor.Descriptor(
  name='Tagging',
  full_name='Tagging',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='ind', full_name='Tagging.ind', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='tag_id', full_name='Tagging.tag_id', index=1,
      number=2, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=31,
  serialized_end=69,
)

DESCRIPTOR.message_types_by_name['Tagging'] = _TAGGING

class Tagging(message.Message):
  __metaclass__ = reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _TAGGING
  
  # @@protoc_insertion_point(class_scope:Tagging)

tagging.message_type = _TAGGING
hypergraph_pb2.Hypergraph.Edge.RegisterExtension(tagging)
hypergraph_pb2.Hypergraph.Edge.RegisterExtension(has_tagging)
# @@protoc_insertion_point(module_scope)