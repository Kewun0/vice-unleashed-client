//----------------------------------------------------
//
// GPL code license:
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
//----------------------------------------------------
//
// VC:MP Multiplayer Modification For GTA:VC
// Copyright 2004-2005 SA:MP team
//
// File Author: kyeman
//
//----------------------------------------------------


#pragma once

extern "C" {
#include "jpeg/jpeglib.h"
}

class CScreenshot
{
private:

	IDirect3DDevice8 *m_pD3DDevice;

	HANDLE CreateDibFromCurrentSurface();
	void FreeDib(HANDLE hDib);

	BOOL CreateJpegFileFromDib(HANDLE hDib, int nQuality, PCHAR szJpegFile);
	void ConvertDibToSamps(HANDLE hDib,int nSampsPerRow,
		struct jpeg_compress_struct cinfo,JSAMPARRAY jsmpPixels);

public:

	BOOL TakeScreenShot(PCHAR szFileName);
	CScreenshot(IDirect3DDevice8 *pD3DDevice);
	~CScreenshot() {};
};


//----------------------------------------------------