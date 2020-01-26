/**
 * Copyright (c) 2006-2020 LOVE Development Team
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 **/

#pragma once

#include "graphics/Shader.h"
#include "graphics/Graphics.h"
#include "Metal.h"

namespace love
{
namespace graphics
{
namespace metal
{

class Shader final : public love::graphics::Shader
{
public:

	Shader(love::graphics::ShaderStage *vertex, love::graphics::ShaderStage *pixel);
	virtual ~Shader();

	// Implements Shader.
	void attach() override;
	std::string getWarnings() const override;
	int getVertexAttributeIndex(const std::string &name) override;
	const UniformInfo *getUniformInfo(const std::string &name) const override;
	const UniformInfo *getUniformInfo(BuiltinUniform builtin) const override;
	void updateUniform(const UniformInfo *info, int count) override;
	void sendTextures(const UniformInfo *info, Texture **textures, int count) override;
	bool hasUniform(const std::string &name) const override;
	ptrdiff_t getHandle() const override;
	void setVideoTextures(Texture *ytexture, Texture *cbtexture, Texture *crtexture) override;

private:

	id<MTLLibrary> library;

}; // Metal

extern Metal metal;

} // metal
} // graphics
} // love
