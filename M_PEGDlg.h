// M_PEGDlg.h : header file
//

#include<stdio.h>
#include<string.h>
#include<Afxtempl.h>

#if !defined(AFX_M_PEGDLG_H__91AA3EEC_5D9A_4766_BCBF_65217D4D35DF__INCLUDED_)
#define AFX_M_PEGDLG_H__91AA3EEC_5D9A_4766_BCBF_65217D4D35DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CM_PEGDlg dialog

struct Sample  
{
 int m_A_Number;//
 int m_m_Number;
 int m_type;
 float m_x;
 float m_y;
 float m_z;
 float m_ix;
 float m_iy;
 float m_iz;
 float m_wx;
 float m_wy;
 float m_wz;
 
};
struct LipofA    //
{
 int m_m_Number;
 int m_type;
 float matr[4][3];
 float m_r;    //
 float m_s;    //
 float m_jd;    //
 float m_s_jz;  //
 float m_jd_jz;  //
 int min_id,max_id;
 float max_z,min_z,mid_z;
 float m_x_jz;  // 
 float m_y_jz;  //
};

struct lip  
{
 int m_A_Number;//
 int m_m_Number;
 int m_type;
 float m_x;   //
 float m_y;   //
 float m_z;   //
 float m_ix;  //image flag
 float m_iy;
 float m_iz;
 float m_wx;  //wraped coordinates
 float m_wy;
 float m_wz;
 bool m_check;
 bool m_lx;
 }  ;

struct sd  
{
 int m_id;
 float m_x;   //
 float m_y;   //
 float m_z;   //
 
 }  ;

class CM_PEGDlg : public CDialog
{
// Construction
public:
	CM_PEGDlg(CWnd* pParent = NULL);	// standard constructor
    
	CArray <int,int> m_Array1;  //time
	
	CArray <lip,lip> m_Array2; //all atoms (6 demension) in current system
	CArray <lip,lip> m_Array22;//all atoms (6 demension) in initial system
	CArray <int,int> m_Array3;  //AM ID inside bilayer(cause some AM pumped out of the membrane)
	CArray <int,int> m_Array33;  //whole AM ID
	CArray <int,int> m_Array4;  // neighbour lipid 
	CArray <int,int> m_Array44;  // neighbour lipid at first frame
	CArray <LipofA,LipofA> m_Array5;  // last bead coordinates of AM tail

    CArray <sd,sd> m_Array6;;  //atom ID of last bead of AM tail
    CArray <int,int> m_Array7; //all DSPC ID
	CArray <int,int> m_Array8; //all molecule ID
	CArray <lip,lip> m_Array_AM; //all AM center of mass
	CArray <lip,lip> m_Array_lipid; //all DSPC center of mass





	CArray <lip,lip> ls_Array1; //all atoms (6 dimension) in AM
	CArray <lip,lip> ls_Array2; //all atoms (6 dimension) in neighbour lipid
	CArray <lip,lip> ls_Array3; //type 4 atoms (6 dimension) in all DSPC lipid

    CArray <float,float> ls_jd;  //tilt angle of lipid
    CArray <float,float> ls_jd2;
	CArray <float,float> ls_Area; //
    CArray <float,float> ls_EED; //
	CArray <float,float> ls_RG; //RG of PEG chain
	CArray <float,float> ls_msd;
	CArray <float,float> ls_tRG;
	CArray <float,float> ls_RDF;
	CArray <float,float> ls_thickness_up;
	CArray <float,float> ls_thickness_down;

	float first_x,first_y,first_z,first_x2,first_y2,first_z2;
	float flag_x,flag_y,flag_z;
	
	
	float m_jd_jz,m_Area_jz,m_EED_jz,m_RG_jz,m_msd_jz,m_tRG_jz,m_RDF_jz,m_upthick_jz,m_downthick_jz;  //mean
	float m_jd_fc,m_Area_fc,m_EED_fc,m_RG_fc,m_msd_fc,m_tRG_fc,m_RDF_fc,m_upthick_fc,m_downthick_fc;  //Standard Deviation

	
	float ls_x,ls_y,ls_r;

    //++++++++++++set of extractcfg¡¡+++++++++++++
	int m_TimeVal;    //time interval
	CString m_FileName[20]; //
/////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~focus abovefilename number//!!!!!!!!!!!!!!!!!!!!!!!!!!!
	

	  
// Dialog Data
	//{{AFX_DATA(CM_PEGDlg)
	enum { IDD = IDD_M_PEG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CM_PEGDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	int ComputerLipID(int id);
    float ComputerAMEED();
	int ComputerAMEED_pj();

	bool Readextractcfg(CString mc);
	// Generated message map functions
	//{{AFX_MSG(CM_PEGDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_M_PEGDLG_H__91AA3EEC_5D9A_4766_BCBF_65217D4D35DF__INCLUDED_)
