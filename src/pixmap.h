// CPixmap.h

#pragma once

#include <SDL2/SDL.h>

#include "blupi.h"

#define MAXIMAGE	100
#define MAXCURSORS	14

class CPixmap
{
public:
	CPixmap();
	~CPixmap();

	bool	Create(POINT dim, bool bFullScreen, int mouseType);
	bool	Flush();
	void	Fill(RECT rect, COLORREF color);

	bool	Cache(int channel, const char *pFilename, POINT totalDim, POINT iconDim);
	bool	Cache(int channel, const char *pFilename, POINT totalDim);
	bool	Cache(int channel, SDL_Surface *surface, POINT totalDim);
	void	SetClipping(RECT clip);
	RECT	GetClipping();

	bool	IsIconPixel(int channel, int rank, POINT pos);

	bool	DrawIcon(int chDst, int channel, int rank, POINT pos, bool bMask=false);
	bool	DrawIconDemi(int chDst, int channel, int rank, POINT pos, bool bMask=false);
	bool	DrawIconPart(int chDst, int channel, int rank, POINT pos, int startY, int endY, bool bMask=false);
	bool	DrawPart(int chDst, int channel, POINT dest, RECT rect, bool bMask=false);
	bool	DrawImage(int chDst, int channel, RECT rect);

	bool	BuildIconMask(int channelMask, int rankMask,
						  int channel, int rankSrc, int rankDst);

	bool	Display();

	void	SetMouseSprite(int sprite, bool bDemoPlay);
	void	MouseShow(bool bShow);
	void	LoadCursors ();
	void	ChangeSprite (MouseSprites sprite);

protected:
	int	BltFast(int chDst, int channel, POINT dst, RECT rcRect);
	int	BltFast(SDL_Texture *lpSDL, int channel, POINT dst, RECT rcRect);

	RECT	MouseRectSprite();
	SDL_Point GetCursorHotSpot (int sprite);
	SDL_Rect GetCursorRect (int sprite);

protected:
	bool					m_bFullScreen;
	int						m_mouseType;
	bool					m_bDebug;
	bool					m_bPalette;
	POINT					m_dim;					// dimensions totales
	RECT					m_clipRect;				// rectangle de clipping

	int						m_mouseSprite;
	bool					m_bBackDisplayed;

	SDL_Cursor *			m_lpCurrentCursor;
	SDL_Cursor *			m_lpSDLCursors[MAXCURSORS];
	SDL_Surface *			m_lpSDLBlupi;
	SDL_Texture *			m_lpSDLTexture[MAXIMAGE];
	COLORREF				m_colorSurface[2*MAXIMAGE];

	char					m_filename[MAXIMAGE][20];
	POINT					m_totalDim[MAXIMAGE];	// dimensions totale image
	POINT					m_iconDim[MAXIMAGE];	// dimensions d'une icï¿½ne
};

/////////////////////////////////////////////////////////////////////////////
