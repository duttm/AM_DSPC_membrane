// M_PEG.h : main header file for the M_PEG application
//

#if !defined(AFX_M_PEG_H__2B829215_800A_4497_A57E_BA5F1E342EDA__INCLUDED_)
#define AFX_M_PEG_H__2B829215_800A_4497_A57E_BA5F1E342EDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CM_PEGApp:
// See M_PEG.cpp for the implementation of this class
//

class CM_PEGApp : public CWinApp
{
public:
	CM_PEGApp();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CM_PEGApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CM_PEGApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_M_PEG_H__2B829215_800A_4497_A57E_BA5F1E342EDA__INCLUDED_)
