/******************************************************************************
 * THE OMEGA LIB PROJECT
 *-----------------------------------------------------------------------------
 * Copyright 2010-2013		Electronic Visualization Laboratory, 
 *							University of Illinois at Chicago
 * Authors:										
 *  Alessandro Febretti		febret@gmail.com
 *-----------------------------------------------------------------------------
 * Copyright (c) 2010-2013, Electronic Visualization Laboratory,  
 * University of Illinois at Chicago
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 * 
 * Redistributions of source code must retain the above copyright notice, this 
 * list of conditions and the following disclaimer. Redistributions in binary 
 * form must reproduce the above copyright notice, this list of conditions and 
 * the following disclaimer in the documentation and/or other materials provided 
 * with the distribution. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *-----------------------------------------------------------------------------
 * What's in this file
 *	The interface between the Scalable Adaptive Graphics Environment (SAGE)
 *	and omegalib.
 ******************************************************************************/
#ifndef __SAGE_MANAGER__
#define __SAGE_MANAGER__

#include <omega.h>

class sail;

namespace omega
{
	struct DisplayConfig;

	///////////////////////////////////////////////////////////////////////////
	class SageManager: public EngineModule
	{
	public:
		SageManager();
		virtual ~SageManager();

		virtual void initialize();
		virtual void dispose();
		virtual void update(const UpdateContext& context);

		String getFsManagerAddress() { return myFsManagerAddress; }

		void switchToWindowedMode();
		void switchToFullscreenMode();

	private:
		String myFsManagerAddress;

		bool myWindowed;
		// Hostname of the node doing windowed rendering.
		String myWindowedRenderNode;
		// Windowed mode tile configuration
		Ref<DisplayTileConfig> myWindowedConfig;

		// The camera used for SAGE rendering (usually the omegalib default camera)
		Ref<Camera> myCamera;
		
		// The render surface used for SAGE rendering
		Ref<PixelData> myImage;
		Ref<RenderTarget> myRenderTarget;

		sail* mySail;
	};
}; // namespace omega

#endif