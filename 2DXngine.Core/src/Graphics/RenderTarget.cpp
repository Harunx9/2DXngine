#include "RenderTarget.h"

RenderTarget::RenderTarget(int width, int height, GLuint wrapS, GLuint wrapT, GLuint filterMin, GLuint filterMax) : Texture("",0,width, height, wrapS, wrapT, filterMin, filterMax)
{
}

RenderTarget::~RenderTarget()
{
}
