// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "lexical.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {


}  // namespace


void protobuf_AssignDesc_lexical_2eproto() {
  protobuf_AddDesc_lexical_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "lexical.proto");
  GOOGLE_CHECK(file != NULL);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_lexical_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_lexical_2eproto() {
}

void protobuf_AddDesc_lexical_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protobuf_AddDesc_hypergraph_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rlexical.proto\032\020hypergraph.proto:!\n\007is_"
    "word\022\020.Hypergraph.Node\030n \001(\010:\036\n\004word\022\020.H"
    "ypergraph.Node\030o \001(\t", 100);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "lexical.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::ExtensionSet::RegisterExtension(
    &::Hypergraph_Node::default_instance(),
    110, 8, false, false);
  ::google::protobuf::internal::ExtensionSet::RegisterExtension(
    &::Hypergraph_Node::default_instance(),
    111, 9, false, false);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_lexical_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_lexical_2eproto {
  StaticDescriptorInitializer_lexical_2eproto() {
    protobuf_AddDesc_lexical_2eproto();
  }
} static_descriptor_initializer_lexical_2eproto_;

::google::protobuf::internal::ExtensionIdentifier< ::Hypergraph_Node,
    ::google::protobuf::internal::PrimitiveTypeTraits< bool >, 8, false >
  is_word(kIsWordFieldNumber, false);
const ::std::string word_default("");
::google::protobuf::internal::ExtensionIdentifier< ::Hypergraph_Node,
    ::google::protobuf::internal::StringTypeTraits, 9, false >
  word(kWordFieldNumber, word_default);

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
