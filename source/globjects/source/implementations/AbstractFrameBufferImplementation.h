#pragma once

#include <glbinding/gl/types.h>

#include <globjects/FrameBufferObject.h>


namespace glo
{

class FrameBufferObject;
class Texture;
class RenderBufferObject;

class AbstractFramebufferImplementation
{
public:
    AbstractFramebufferImplementation();
    virtual ~AbstractFramebufferImplementation();

    static AbstractFramebufferImplementation * get(FrameBufferObject::BindlessImplementation impl = 
        FrameBufferObject::BindlessImplementation::DirectStateAccessARB);


    virtual gl::GLuint create() const = 0;
    virtual void destroy(gl::GLuint id) const = 0;

    virtual gl::GLenum checkStatus(const FrameBufferObject * fbo) const = 0;
    virtual void setParameter(const FrameBufferObject * fbo, gl::GLenum pname, gl::GLint param) const = 0;
    virtual gl::GLint getAttachmentParameter(const FrameBufferObject * fbo, gl::GLenum attachment, gl::GLenum pname) const = 0;
    virtual void attachTexture(const FrameBufferObject * fbo, gl::GLenum attachment, Texture * texture, gl::GLint level) const = 0;
    virtual void attachTextureLayer(const FrameBufferObject * fbo, gl::GLenum attachment, Texture * texture, gl::GLint level, gl::GLint layer) const = 0;
    virtual void attachRenderBuffer(const FrameBufferObject * fbo, gl::GLenum attachment, RenderBufferObject * renderBuffer) const = 0;
    virtual void setReadBuffer(const FrameBufferObject * fbo, gl::GLenum mode) const = 0;
    virtual void setDrawBuffer(const FrameBufferObject * fbo, gl::GLenum mode) const = 0;
    virtual void setDrawBuffers(const FrameBufferObject * fbo, gl::GLsizei n, const gl::GLenum * modes) const = 0;

public:
    static gl::GLenum s_workingTarget;
};

} // namespace glo