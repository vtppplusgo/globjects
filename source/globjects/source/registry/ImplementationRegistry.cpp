#include "ImplementationRegistry.h"

#include "Registry.h"

#include "../implementations/AbstractUniformImplementation.h"
#include "../implementations/AbstractBufferImplementation.h"
#include "../implementations/AbstractFrameBufferImplementation.h"
#include "../implementations/AbstractDebugImplementation.h"
#include "../implementations/AbstractProgramBinaryImplementation.h"
#include "../implementations/AbstractShadingLanguageIncludeImplementation.h"
#include "../implementations/AbstractObjectNameImplementation.h"

namespace glo 
{

ImplementationRegistry::ImplementationRegistry()
: m_uniformImplementation(nullptr)
, m_bufferImplementation(nullptr)
, m_framebufferImplementation(nullptr)
, m_debugImplementation(nullptr)
, m_programBinaryImplementation(nullptr)
, m_shadingLanguageIncludeImplementation(nullptr)
, m_objectNameImplementation(nullptr)
{
}

ImplementationRegistry::~ImplementationRegistry()
{
    delete m_uniformImplementation;
    delete m_bufferImplementation;
    delete m_framebufferImplementation;
    delete m_debugImplementation;
    delete m_programBinaryImplementation;
    delete m_shadingLanguageIncludeImplementation;
    delete m_objectNameImplementation;
}

ImplementationRegistry & ImplementationRegistry::current()
{
    return Registry::current().implementations();
}

void ImplementationRegistry::initialize()
{
    m_uniformImplementation = AbstractUniformImplementation::get();
    m_bufferImplementation = AbstractBufferImplementation::get();
    m_framebufferImplementation = AbstractFramebufferImplementation::get();
    m_debugImplementation = AbstractDebugImplementation::get();
    m_programBinaryImplementation = AbstractProgramBinaryImplementation::get();
    m_shadingLanguageIncludeImplementation = AbstractShadingLanguageIncludeImplementation::get();
    m_objectNameImplementation = AbstractObjectNameImplementation::get();
}

void ImplementationRegistry::initialize(const AbstractUniform::BindlessImplementation impl)
{
    m_uniformImplementation = AbstractUniformImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Buffer::BindlessImplementation impl)
{
    m_bufferImplementation = AbstractBufferImplementation::get(impl);
}

void ImplementationRegistry::initialize(const FrameBufferObject::BindlessImplementation impl)
{
    m_framebufferImplementation = AbstractFramebufferImplementation::get(impl);
}

void ImplementationRegistry::initialize(const DebugMessage::Implementation impl)
{
    m_debugImplementation = AbstractDebugImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Program::BinaryImplementation impl)
{
    m_programBinaryImplementation = AbstractProgramBinaryImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Shader::IncludeImplementation impl)
{
    m_shadingLanguageIncludeImplementation = AbstractShadingLanguageIncludeImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Object::NameImplementation impl)
{
    m_objectNameImplementation = AbstractObjectNameImplementation::get(impl);
}

AbstractUniformImplementation & ImplementationRegistry::uniformImplementation()
{
    if (!m_uniformImplementation)
        m_uniformImplementation = AbstractUniformImplementation::get();

    return *m_uniformImplementation;
}

AbstractBufferImplementation & ImplementationRegistry::bufferImplementation()
{
    if (!m_bufferImplementation)
        m_bufferImplementation = AbstractBufferImplementation::get();

    return *m_bufferImplementation;
}

AbstractFramebufferImplementation & ImplementationRegistry::framebufferImplementation()
{
    if (!m_framebufferImplementation)
        m_framebufferImplementation = AbstractFramebufferImplementation::get();

    return *m_framebufferImplementation;
}

AbstractDebugImplementation & ImplementationRegistry::debugImplementation()
{
    if (!m_debugImplementation)
        m_debugImplementation = AbstractDebugImplementation::get();

    return *m_debugImplementation;
}

AbstractProgramBinaryImplementation & ImplementationRegistry::programBinaryImplementation()
{
    if (!m_programBinaryImplementation)
        m_programBinaryImplementation = AbstractProgramBinaryImplementation::get();

    return *m_programBinaryImplementation;
}

AbstractShadingLanguageIncludeImplementation & ImplementationRegistry::shadingLanguageIncludeImplementation()
{
    if (!m_shadingLanguageIncludeImplementation)
        m_shadingLanguageIncludeImplementation = AbstractShadingLanguageIncludeImplementation::get();

    return *m_shadingLanguageIncludeImplementation;
}

AbstractObjectNameImplementation & ImplementationRegistry::objectNameImplementation()
{
    if (!m_objectNameImplementation)
        m_objectNameImplementation = AbstractObjectNameImplementation::get();

    return *m_objectNameImplementation;
}

} // namespace glo