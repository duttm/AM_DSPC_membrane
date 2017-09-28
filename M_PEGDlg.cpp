// M_PEGDlg.cpp : implementation file
//

#include "stdafx.h"
#include "M_PEG.h"
#include "M_PEGDlg.h"

#include<stdio.h>
#include<string.h>
#include<Afxtempl.h>
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif






class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CM_PEGDlg dialog

CM_PEGDlg::CM_PEGDlg(CWnd* pParent /*=NULL*/)
: CDialog(CM_PEGDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CM_PEGDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CM_PEGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CM_PEGDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CM_PEGDlg, CDialog)
//{{AFX_MSG_MAP(CM_PEGDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()

ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CM_PEGDlg message handlers

BOOL CM_PEGDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CM_PEGDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CM_PEGDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CM_PEGDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


int CM_PEGDlg::ComputerLipID(int id)
{
	//	calculate LipID around AM
	int i,j;
	
	for (j=0;j<m_Array4.GetSize();j++)
	{
		if(id==m_Array4[j])
		{   
			id=-1;
			break;
		}
		
	}
	if(id!=-1)
	{
		//check AM
		
		for (j=0;j<m_Array2.GetSize();j++)
		{
			if(m_Array2[j].m_type==6&&m_Array2[j].m_m_Number==id)
			{
				id=-1;
				break;
			}
		}
	}
	
	if(id>0 &&id<=984)
		return id;
	else 
		return -1;
}


//float CM_PEGDlg::ComputerAMEED()
//{




//	int i=0;
//	  float m_x,m_y;
//	  float s,dis;
//	  s=0;
//
//	  m_x=0;m_y=0;
//     for(i=0;i<m_xh.GetSize();i++)
//	  {
//		  m_x=m_x+fabs(ls_Array2[m_xh[i]].m_x);
//          m_y=m_y+fabs(ls_Array2[m_xh[i]].m_y);
//	  }
//
//      m_x=m_x*1.0/m_xh.GetSize();
//      m_y=m_y*1.0/m_xh.GetSize();

//     for(i=0;i<m_xh.GetSize();i++)
//	  {
//		  dis=sqrt(pow(fabs(ls_Array2[m_xh[i]].m_x)-m_x,2)+pow(fabs(ls_Array2[m_xh[i]].m_y)-m_y,2));
//		  if(dis>s) s=dis;
//	  }

//	return 3.14*s*s;   //return area
//}



int CM_PEGDlg::ComputerAMEED_pj()
{
	//	LipMj
	return 1;
}

bool CM_PEGDlg:: Readextractcfg(CString mc)
{
	
	FILE *fp;
	CFileFind  finder;; 
	CString str,str2;
	
	CString FileName0,FileName1,FileName2,FileName3;
	int i,m;
	
	CStdioFile file;
	
	
	if(finder.FindFile(mc))    //WENJIANCUNZAI 
	{
		file.Open(mc,CFile::modeRead);//open profile
		file.ReadString(m_FileName[0]); 
		file.ReadString(str); 
		m_TimeVal=atoi(str);
		
		file.ReadString(m_FileName[1]); //AM ID, lipid bilayer max, min and mid position
		
		file.ReadString(m_FileName[2]); //around LIPiD ID around AM
		
		file.ReadString(m_FileName[3]); //around LIPiD atom matrix(atom_ID,molecule_ID,type,unwrap_x,u_y,u_z,wrap_x,w_y,w_z)
		
		file.ReadString(m_FileName[4]); //chain order for all frame
		file.ReadString(m_FileName[5]); //chain order mean S.D. for each frame
		
		file.ReadString(m_FileName[6]); //msd for all frame
		file.ReadString(m_FileName[7]); //msd mean S.D. for each frame
		
		file.ReadString(m_FileName[8]); //current:all atoms(6 dimension) in AM
		
		file.ReadString(m_FileName[9]); //PEG ROG for all frame
		file.ReadString(m_FileName[10]); //PEG ROG mean S.D. for each frame
		
		file.ReadString(m_FileName[11]); //EED of PEG for all frame
		file.ReadString(m_FileName[12]); //EED of PEG mean S.D. for each frame
		
		file.ReadString(m_FileName[13]); //global area mean S.D.
		
		file.ReadString(m_FileName[14]); //tail rg 
		file.ReadString(m_FileName[15]); //tail rg mean S.D.
		
		file.ReadString(m_FileName[16]); //thickness of up and down corona(mean and std) for each frame
		file.ReadString(m_FileName[17]); //Thickness of each single PEG chain
		
		file.ReadString(m_FileName[18]); //PEG bead number in each slab
		file.ReadString(m_FileName[19]); //PEG bead atoms matrix(atom_ID,molecule_ID,type,unwrap_x,u_y.u_z. time)
		
		file.Close();
		
		return true;
	}
	else
		return FALSE;
	
	
}

void CM_PEGDlg::OnButton2() 
{
	
	
	int i;
    CString str1,str2;
	
    FILE *in,*out1,*out2,*out3,*out4,*out5,*out6,*out7,*out8,*out9,*out10,*out11,*out12,*out13,*out14,*out15,*out16,*out17,*out18,*out19;
	
	int m_min,m_max;
	int r_count;
	int m_time;	
	int m,n,k,j,h;  
	int id,id2;
	int m_ATOMS_nbuber;
	int count_up,count_down;
	float x,y,z,ix,iy,iz,wx,wy,wz;
	float m_Area; 
	float m_EED;
	float m_RG;
	float m_tRG;
	float m_RDF;
	float bd,flag_bd,bd_constant;
	float pegcount;
	float com_z;
	int tailcount;
	float AM_com_x,AM_com_y,AM_com_z,lipid_com_x,lipid_com_y,lipid_com_z,dis_AM_lipid;
	float id_AM,id_lipid;
	float delta_r,density;
	int thick,thick2;
	float peg;
	float chain_x,chain_y,chain_z;
	float peg_maxz_up,peg_minz_up,peg_maxz_down,peg_minz_down,thickness_up,thickness_down;
	flag_bd=-1;
	flag_x=1;
	flag_y=1;
	flag_z=1;
	
	
	
	float d[5];
	lip m_temp;
	
	LipofA m_A_temp;
	
	sd m_temp6;
	
	CFileFind  finder; 
	
	if(!Readextractcfg("extractcfg.txt")) return ;  //profile not exist
	
	
	if(!finder.FindFile(m_FileName[0]))    //timestep not exist
	{
		return;
	}
	
	
	out1 = fopen(m_FileName[1], "w");
	fclose(out1);
	
	
	out2 = fopen(m_FileName[2], "w");
	fclose(out2);
	
	
	out3 = fopen(m_FileName[3], "w");
	fclose(out3);
	
	
	out4 = fopen(m_FileName[4], "w");
	fclose(out4);
	
	
	out5 = fopen(m_FileName[5], "w");
	fclose(out5);
	
	out6 = fopen(m_FileName[6], "w");
	fclose(out6);
	
	out7 = fopen(m_FileName[7], "w");
	fclose(out7);
	
	out8 = fopen(m_FileName[8], "w");
	fclose(out8);
	
	out9 = fopen(m_FileName[9], "w");
	fclose(out9);
	
	out10 = fopen(m_FileName[10], "w");
	fclose(out10);
	
	
	out11 = fopen(m_FileName[11], "w");
	fclose(out11);
	
	out12 = fopen(m_FileName[12], "w");
	fclose(out12);
	
	out13 = fopen(m_FileName[13], "w");
	fclose(out13);
	
	out14 = fopen(m_FileName[14], "w");
	fclose(out14);
	
	out15 = fopen(m_FileName[15], "w");
	fclose(out15);
	
	out16 = fopen(m_FileName[16], "w");
	fclose(out16);
	
	out17 = fopen(m_FileName[17], "w");
	fclose(out17);
	
	out18 = fopen(m_FileName[18], "w");
	fclose(out18);
	
	out19 = fopen(m_FileName[19], "w");
	fclose(out19);
	
	/*
	++++++++++add new file
	
	  outxxx = fopen(m_FileName[xxx], "w");
	  fclose(outxxx);
	  
	*/
	
	CString strName;
	CStdioFile file;
	
	CStdioFile file1;
	
	strName=m_FileName[0]; 
	
	// strName="dump.AM.lammpstrj";
	
	
	file1.Open(strName,CFile::modeRead);//open file
	
	int p;
	
	
	//read dump file by line
	
	while(file1.GetPosition()!=file1.GetLength())
		
	{
		
		if(m_Array2.GetSize()>0) m_Array2.RemoveAll();
        
		bd=-1;
		
		file1.ReadString(str1); 
		
		file1.ReadString(str1); 
		m=atoi(str1);
		m_time=m;
		m_Array1.Add(m); 
		
		/*
		//////////
		file1.ReadString(str1); 
		file1.ReadString(str1); 
		m_ATOMS_nbuber=atoi(str1);
		AfxMessageBox("test1");
		file1.ReadString(str1); 
		file1.ReadString(str1); 
		str1.TrimLeft();
		str1.TrimRight();
        i=str1.Find(" "); //index start from 0
		bd=atof(str1.Right(str1.GetLength()-i-1));
		AfxMessageBox("test2");
		file1.ReadString(str1); 
		file1.ReadString(str1); 
		file1.ReadString(str1);
		AfxMessageBox("M_PEG");
		/////////////////
		*/
		
		if(m_Array1.GetSize()==1)
		{
			file1.ReadString(str1); 
			file1.ReadString(str1); 
			
			m_ATOMS_nbuber=atoi(str1);
			file1.ReadString(str1); 
			file1.ReadString(str1); 
			
            str1.TrimLeft();
			str1.TrimRight();
            i=str1.Find(" "); //index start from 0
			bd=atof(str1.Right(str1.GetLength()-i-1));
			
			file1.ReadString(str1); 
			file1.ReadString(str1); 
			file1.ReadString(str1); 
		}
		else 
		{
			
			while(str1.Find("type x y z")==-1)   
			{
				if(str1.Find("BOX BOUNDS")==-1)
				{
					file1.ReadString(str1); 
					
					
				}
				else
				{
					
					file1.ReadString(str1); 
                    str1.TrimLeft();
					str1.TrimRight();
                    i=str1.Find(" "); //index start from 0
					bd=atof(str1.Right(str1.GetLength()-i-1));
					
				}
			}
			
		}
		
		//AfxMessageBox("test");
		if(flag_bd==-1)
		{
			if(bd!=-1) 
			{
				bd_constant=bd;
				flag_bd=1;
			}
		}
		if(bd==-1) bd=bd_constant;
		
		for(k=1;k<=m_ATOMS_nbuber;k++)      //m_ATOMS_nbuber is atom num, read by loop
		{
			file1.ReadString(str1); 
			
			str1.TrimLeft();
			str1.TrimRight();
			
			i=str1.Find(" "); //index
			m=atoi(str1.Left(i));
			
			str1=str1.Right(str1.GetLength()-i-1);
			
			i=str1.Find(" ");
			n=atoi(str1.Left(i));
			str1=str1.Right(str1.GetLength()-i-1);
			str1.TrimLeft();
			
			i=str1.Find(" ");
			p=atoi(str1.Left(i));
			str1=str1.Right(str1.GetLength()-i-1);
			str1.TrimLeft();
			
			i=str1.Find(" ");
			x=atof(str1.Left(i));
			
			str2=str1.Left(i);
			str2.Format("%7.4f",x);
			
			
			str1=str1.Right(str1.GetLength()-i-1);
			str1.TrimLeft();
			
			i=str1.Find(" ");
			y=atof(str1.Left(i));
			
			str2=str1.Left(i);
			str2.Format("%7.4f",y);
			
			str1=str1.Right(str1.GetLength()-i-1);
			str1.TrimLeft();
			
			i=str1.Find(" ");
			z=atof(str1.Left(i));
			
			str2=str1.Left(i);
			str2.Format("%7.4f",z);
			
			str1=str1.Right(str1.GetLength()-i-1);
			str1.TrimLeft();
			
			i=str1.Find(" ");
			ix=atof(str1.Left(i));
			
			str2=str1.Left(i);
			str2.Format("%d",ix);
			
			str1=str1.Right(str1.GetLength()-i-1);
			str1.TrimLeft();
			
			i=str1.Find(" ");
			iy=atof(str1.Left(i));
			
			str2=str1.Left(i);
			str2.Format("%d",iy);
			
			str1=str1.Right(str1.GetLength()-i-1);
			str1.TrimLeft();
			
			
			str2=str1;
			iz=atof(str1);
			str2.Format("%7.4f",iz);
			//
			m_temp.m_A_Number=m;
			m_temp.m_m_Number=n;
			m_temp.m_type=p;
			m_temp.m_wx=x;
			m_temp.m_wy=y;
			m_temp.m_wz=z;
			m_temp.m_x=x+2*bd*ix;
			m_temp.m_y=y+2*bd*iy;
			m_temp.m_z=z+2*bd*iz;
            m_temp.m_ix=ix;
			m_temp.m_iy=iy;
			m_temp.m_iz=iz;
			m_temp.m_check=false;
			m_Array2.Add(m_temp); //
			if(m_Array1.GetSize()==1) m_Array22.Add(m_temp);
		}
		//AfxMessageBox("test");
		//calculate AM
		////////////////////////////
		//exclude AM outside bilayer
		//find max_z and min_z for bilayer (type 7)
		
		
		
		//if(m_Array1.GetSize()==1)   
		//{
		/*m_A_temp.max_z=0;
		m_A_temp.min_z=0;	
		m_A_temp.mid_z=0;
		n=0;
		count_up=0;
		count_down=0;
		
		  for (k=0;k<m_Array2.GetSize();k++)
		  {
		  if(m_Array2[k].m_type==7)
		  {				
		  if(m_Array2[k].m_m_Number>492)
		  {
		  m_A_temp.min_z=m_A_temp.min_z+m_Array2[k].m_wz;
		  count_down=count_down+1;
		  }
		  if(m_Array2[k].m_m_Number<493)
		  {
		  m_A_temp.max_z=m_A_temp.max_z+m_Array2[k].m_wz;
		  count_up=count_up+1;
		  }
		  m_A_temp.mid_z=m_A_temp.mid_z+m_Array2[k].m_wz;
		  n=n+1;
		  }
		  
			}
			
			  m_A_temp.max_z=m_A_temp.max_z/count_up;
			  m_A_temp.min_z=m_A_temp.min_z/count_down;
			  m_A_temp.mid_z=m_A_temp.mid_z/n;*/
			  
			  ////////////////////////////////////////////////////////////////////////////////////////////////////
			  m_A_temp.max_z=-80;
			  m_A_temp.min_z=80;	
			  for (k=0;k<m_Array2.GetSize();k++)
			  {
				  if(m_Array2[k].m_type==7)
				  {
					  if(m_Array2[k].m_wz>m_A_temp.max_z) 
					  {
						  m_A_temp.max_z=m_Array2[k].m_wz;
					  }
					  if(m_Array2[k].m_wz<m_A_temp.min_z) 
					  {
						  m_A_temp.min_z=m_Array2[k].m_wz;
					  }
				  }
				  
			  }
			  m_A_temp.mid_z=0.5*(m_A_temp.max_z+m_A_temp.min_z);
			  
			  ////////////////////////////////whole AM ID in m_Array33/////////////////////////
			  
			  
			  if(m_Array1.GetSize()==1)   
			  {
				  for (k=0;k<m_Array2.GetSize();k++)
				  {
					  if(m_Array2[k].m_type==6)
					  {
						  id=m_Array2[k].m_m_Number;
						  m=-1;
						  for (j=0;j<m_Array33.GetSize();j++)
						  {
							  if (m_Array33[j]==id)
							  {
								  m=id;
								  break;
							  }
							  
						  }
						  if (m==-1) m_Array33.Add(id);   //AM ID
					  }
					  
				  }
			  }
			  /////////////////////AM ID inside bilayer////////////	
			  if(m_Array3.GetSize()>0) m_Array3.RemoveAll();
			  
			  for (j=0;j<m_Array33.GetSize();j++)   //l
			  {
				  id=m_Array33[j];
				  com_z=0;
				  tailcount=0;
				  for (k=0;k<m_Array2.GetSize();k++)
				  {
					  if (m_Array2[k].m_m_Number==id)
					  {
						  if (m_Array2[k].m_type==4 || m_Array2[k].m_type==5)
						  {
							  com_z=com_z+m_Array2[k].m_wz;
							  tailcount=tailcount+1;					
						  }
					  }
				  }
				  com_z=com_z/tailcount;
				  if (com_z<m_A_temp.max_z && com_z>m_A_temp.min_z)
				  {
					  m_Array3.Add(id);
				  }			
			  }
			  
			  ///////////////////////////////////////////////////////////////////////////////
			  
			  out1 = fopen(m_FileName[1], "w");
			  for (j=0;j<m_Array3.GetSize();j++)
			  {
				  
				  fprintf(out1,"%d %7.2f %f %f\n",m_Array3[j],m_A_temp.mid_z,m_A_temp.max_z,m_A_temp.min_z);
			  }
			  fclose(out1);
			  //AfxMessageBox("AM selection done");
			  
			  
			  
			  
			  
			  //AfxMessageBox("flag1 done");
			  ///////////////all molecule ID for Array8/////////
			  //if(m_Array8.GetSize()>0) m_Array8.RemoveAll();
			  if(m_Array1.GetSize()==1) 
			  {
				  for (j=0;j<984;j++)
				  {
					  id=j+1;
					  
					  m_Array8.Add(id);
					  
				  }
			  }
			  ///////////////////////all DSPC ID for Array7/////////////////////////////
			  //if(m_Array7.GetSize()>0) m_Array7.RemoveAll();
			  if(m_Array1.GetSize()==1) 
			  {
				  for (j=0;j<984;j++)
				  {
					  id=j+1;
					  for (k=0;k<m_Array33.GetSize();k++)
					  {
						  
						  if(id == m_Array33[k]) 
						  {
							  id=-1;
						  }   
						  
					  }
					  if (id!=-1) m_Array7.Add(id);	 
				  }
			  }
			  //AfxMessageBox("t1 done");
			  
			  /////////////////////////////////center of mass for inside AM and all DSPC//////////
			  for (j=0;j<m_Array3.GetSize();j++)
			  {
				  id_AM=m_Array3[j];
				  AM_com_x=0;
				  AM_com_y=0;
				  AM_com_z=0;
				  tailcount=0;
				  for (k=0;k<m_Array2.GetSize();k++)
				  {
					  if(m_Array2[k].m_type==4 || m_Array2[k].m_type==5)
					  {
						  if(m_Array2[k].m_m_Number==id_AM)
						  {
							  AM_com_x=AM_com_x+m_Array2[k].m_x;
							  AM_com_y=AM_com_y+m_Array2[k].m_y;
							  AM_com_z=AM_com_z+m_Array2[k].m_z;
							  tailcount=tailcount+1;
						  }
					  }
				  }
				  AM_com_x=AM_com_x/tailcount;
				  AM_com_y=AM_com_y/tailcount;
				  AM_com_z=AM_com_z/tailcount;
				  m_temp.m_m_Number=id_AM;
				  m_temp.m_x=AM_com_x;
				  m_temp.m_y=AM_com_y;
				  m_temp.m_z=AM_com_z;
				  m_temp.m_check=false;
				  m_Array_AM.Add(m_temp);
			  }
			  ////////////////////////////////////////////////////////
			  for (k=0;k<m_Array7.GetSize();k++)
			  {   
				  id_lipid=m_Array7[k];
				  lipid_com_x=0;
				  lipid_com_y=0;
				  lipid_com_z=0;
				  tailcount=0;
				  
				  for (h=0;h<m_Array2.GetSize();h++)  
				  {
					  if(m_Array2[h].m_type==4 && m_Array2[h].m_m_Number==id_lipid)
					  {
						  lipid_com_x=lipid_com_x+m_Array2[h].m_x;
						  lipid_com_y=lipid_com_y+m_Array2[h].m_y;
						  lipid_com_z=lipid_com_z+m_Array2[h].m_z;
						  tailcount=tailcount+1;
					  }
				  }
				  lipid_com_x=lipid_com_x/tailcount;
				  lipid_com_y=lipid_com_y/tailcount;
				  lipid_com_z=lipid_com_z/tailcount;
				  m_temp.m_m_Number=id_lipid;
				  m_temp.m_x=lipid_com_x;
				  m_temp.m_y=lipid_com_y;
				  m_temp.m_z=lipid_com_z;
				  m_temp.m_check=false;
				  m_Array_lipid.Add(m_temp);
			  }
			  /////////////////////////////////////////////////////
			  
			  if(m_Array4.GetSize()>0) m_Array4.RemoveAll();
			  
			  for (j=0;j<m_Array3.GetSize();j++)
			  {
				  id_AM=m_Array3[j];
				  
				  for (k=0;k<m_Array7.GetSize();k++)
				  {   
					  id_lipid=m_Array7[k];
					  
					  dis_AM_lipid=sqrt(pow((m_Array_AM[j].m_x-m_Array_lipid[k].m_x),2)+pow((m_Array_AM[j].m_y-m_Array_lipid[k].m_y),2));
					  if(dis_AM_lipid<12)
					  {
						  if (m_Array_AM[j].m_z>m_A_temp.mid_z && m_Array_AM[j].m_z<m_A_temp.max_z && m_Array_lipid[k].m_z>m_A_temp.mid_z && m_Array_lipid[k].m_z<m_A_temp.max_z)
						  {
							  m_Array4.Add(id_lipid);
						  }
						  else if(m_Array_AM[j].m_z>m_A_temp.min_z && m_Array_AM[j].m_z<m_A_temp.mid_z&&m_Array_lipid[k].m_z>m_A_temp.min_z && m_Array_lipid[k].m_z<m_A_temp.mid_z)
						  {
							  m_Array4.Add(id_lipid);
						  }
						  
					  }	
					  
				  }
			  }
			  
			  
			  if(m_Array1.GetSize()==1) 
			  {
				  for (j=0;j<m_Array4.GetSize();j++)
				  {
					  id=m_Array4[j];
					  m_Array44.Add(id);						
				  }
			  }
			  //////////////////////////////////////////////////////////////////////////////////
			  
			  
			  ///////////////////////////judge neighbour lipid for m_Array4 //////////////////////
			  /*
			  //judge by ID realtionship not position relationship
			  if(m_Array4.GetSize()>0) m_Array4.RemoveAll();
			  for (j=0;j<m_Array3.GetSize();j++)
			  {
			  id=m_Array3[j];
			  if(ComputerLipID(id-17)>0) m_Array4.Add(id-17);
			  if(ComputerLipID(id-16)>0) m_Array4.Add(id-16);
			  if(ComputerLipID(id-15)>0) m_Array4.Add(id-15);
			  if(ComputerLipID(id-1)>0) m_Array4.Add(id-1);
			  if(ComputerLipID(id+1)>0) m_Array4.Add(id+1);
			  if(ComputerLipID(id+15)>0) m_Array4.Add(id+15);
			  if(ComputerLipID(id+16)>0) m_Array4.Add(id+16);
			  if(ComputerLipID(id+17)>0) m_Array4.Add(id+17);
			  }
			  */
			  ////////////////////////////////////////////////////////////////////////////////////
			  out2 = fopen(m_FileName[2], "w");
			  
			  
			  for (j=0;j<m_Array4.GetSize();j++)   //lipid ID
			  {
				  
				  fprintf(out2,"%d\n",m_Array4[j]);
			  }
			  
			  fclose(out2);
			  
			  ////////////////////////////////
			  
			  
			  
			  
			  ////////////////////////////////////////////////////////////////////////////////////
			  
			  
			  out3 = fopen(m_FileName[3], "w");
			  
			  
			  if(ls_Array2.GetSize()>0) ls_Array2.RemoveAll();
			  
			  for (j=0;j<m_Array4.GetSize();j++)
			  {
				  id=m_Array4[j];	
				  
				  for (k=0;k<m_Array2.GetSize();k++)
				  {
					  if (id==m_Array2[k].m_m_Number)
					  {
						  //fprintf(out3,"%d %d %d %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %6.4f\n",m_Array2[k].m_A_Number,m_Array2[k].m_m_Number,m_Array2[k].m_type,m_Array2[k].m_x,m_Array2[k].m_y,m_Array2[k].m_z,m_Array2[k].m_wx,m_Array2[k].m_wy,m_Array2[k].m_wz,m_A_temp.max_z,m_A_temp.min_z,bd);
						  fprintf(out3,"%d %d %d %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f\n",m_Array2[k].m_A_Number,m_Array2[k].m_m_Number,m_Array2[k].m_type,m_Array2[k].m_x,m_Array2[k].m_y,m_Array2[k].m_z,m_Array2[k].m_wx,m_Array2[k].m_wy,m_Array2[k].m_wz);
						  
						  
					  }
				  }
			  }
			  
			  fclose(out3);
			  //write out8
			  //AfxMessageBox("test");
			  out8 = fopen(m_FileName[8], "w");
			  
			  
			  
			  for (j=0;j<m_Array3.GetSize();j++)
			  {
				  id=m_Array3[j];	
				  
				  for (k=0;k<m_Array2.GetSize();k++)
				  {
					  if (id==m_Array2[k].m_m_Number)
					  {
						  fprintf(out8,"%d %d %d %0.4f %0.4f %0.4f %0.1f %0.1f %0.1f %0.4f %0.4f %0.4f\n",m_Array2[k].m_A_Number,m_Array2[k].m_m_Number,m_Array2[k].m_type,m_Array2[k].m_x,m_Array2[k].m_y,m_Array2[k].m_z,m_Array2[k].m_ix,m_Array2[k].m_iy,m_Array2[k].m_iz,m_Array2[k].m_wx,m_Array2[k].m_wy,m_Array2[k].m_wz);
						  
						  
						  
					  }
				  }
			  }
			  fclose(out8);
			  
			  //output out8 to ls_Aeeay1
			  if(ls_Array1.GetSize()>0) ls_Array1.RemoveAll();
			  
			  out8 = fopen(m_FileName[8], "r");
			  
			  while(!feof(out8))
			  {
				  fscanf(out8,"%d %d %d %f %f %f %f %f %f %f %f %f\n",&m,&n,&k,&x,&y,&z,&ix,&iy,&iz,&wx,&wy,&wz);  //　read ITEM: BOX BOUNDS pp pp pp
				  m_temp.m_A_Number=m;
				  m_temp.m_m_Number=n;
				  m_temp.m_type=k;
				  m_temp.m_x=x;
				  m_temp.m_y=y;
				  m_temp.m_z=z;
				  m_temp.m_ix=ix;
				  m_temp.m_iy=iy;
				  m_temp.m_iz=iz;
				  m_temp.m_wx=wx;
				  m_temp.m_wy=wy;
				  m_temp.m_wz=wz;
				  
				  m_temp.m_check=false;
				  //	if(m_temp.m_type==4)
				  ls_Array1.Add(m_temp);
			  }
			  
			  fclose(out8);
			  /////////////////////////////////////////////////////////////////////////////////
			  if(ls_Array2.GetSize()>0) ls_Array2.RemoveAll();
			  
			  
			  out3 = fopen(m_FileName[3], "r");
			  
			  while(!feof(out3))
			  {
				  fscanf(out3,"%d %d %d %f %f %f %f %f %f\n",&m,&n,&k,&x,&y,&z,&wx,&wy,&wz);  //　read ITEM: BOX BOUNDS pp pp pp
				  m_temp.m_A_Number=m;
				  m_temp.m_m_Number=n;
				  m_temp.m_type=k;
				  m_temp.m_x=x;
				  m_temp.m_y=y;
				  m_temp.m_z=z;			
				  m_temp.m_wx=wx;
				  m_temp.m_wy=wy;
				  m_temp.m_wz=wz;
				  m_temp.m_check=false;
				  //	if(m_temp.m_type==4)
				  ls_Array2.Add(m_temp);
			  }
			  
			  fclose(out3);
			  ///////////////////////////////////////////////////////////////////////////////////
			  
			  if(ls_Array3.GetSize()>0) ls_Array3.RemoveAll();
			  
			  
			  for (k=0;k<m_Array2.GetSize();k++)
			  {
				  for(j=0;j<m_Array33.GetSize();j++)
				  {
					  id=m_Array33[j];
					  if(m_Array2[k].m_type==4 && m_Array2[k].m_m_Number!=id)
					  {
						  m_temp.m_A_Number=m_Array2[k].m_A_Number;
						  m_temp.m_m_Number=m_Array2[k].m_m_Number;
						  m_temp.m_type=m_Array2[k].m_type;
						  m_temp.m_x=m_Array2[k].m_x;
						  m_temp.m_y=m_Array2[k].m_y;
						  m_temp.m_z=m_Array2[k].m_z;
						  m_temp.m_check=false;
						  ls_Array3.Add(m_temp);
						  break;
					  }
				  }
			  }
			  //AfxMessageBox("test");
			  
			  
			  //////////////////////////////////////////////////////////////////////////////////////
			  float center_x,center_y,center_z;
			  double r,r_mean=0,rt_mean=0;
			  double total_sum=0.0,ttotal_sum=0.0;
			  
			  float jd;
			  m_jd_jz=0;
			  m_jd_fc=0;
			  
			  m_Area_jz=0;
			  m_Area_fc=0;
			  
			  m_EED_jz=0;
			  m_EED_fc=0;
			  
			  m_RG_jz=0;
			  m_RG_fc=0;
			  
			  m_msd_jz=0;
			  m_msd_fc=0;
			  
			  m_tRG_jz=0;
			  m_tRG_fc=0;
			  
			  m_RDF_jz=0;
			  m_RDF_fc=0;
			  
			  m_upthick_jz=0;
              m_upthick_fc=0;
			  m_downthick_jz=0;
			  m_downthick_fc=0;
			  
			  if(ls_jd.GetSize()>0)  ls_jd.RemoveAll();
			  if(ls_Area.GetSize()>0)  ls_Area.RemoveAll();
			  if(ls_EED.GetSize()>0)  ls_EED.RemoveAll();
			  if(ls_RG.GetSize()>0)  ls_RG.RemoveAll();
			  if(ls_msd.GetSize()>0)  ls_msd.RemoveAll();
			  if(ls_tRG.GetSize()>0)  ls_tRG.RemoveAll();
			  if(ls_RDF.GetSize()>0)  ls_RDF.RemoveAll();
			  if(ls_thickness_up.GetSize()>0)  ls_thickness_up.RemoveAll();
			  if(ls_thickness_down.GetSize()>0)  ls_thickness_down.RemoveAll();
			  
			  //AfxMessageBox("calculation start"); //AfxMessageBox can be used as a check point when debugging
			  
			  ////  ++++++++++++++++++calculation starts here+++++++++++++++++++++++++++++++++++++++++++++++++++++
			  
			  ////  ++++++++++++++++++chain order of neighbour lipid++++++++++++++++++++++++++++++++++++++++++++++
			  
			  out4 = fopen( m_FileName[4], "a");   //lipid tail chain order in one single tail
			  
			  //select minimum atom ID
			  
			  for (j=0;j<m_Array4.GetSize();j++)   //lipid
			  {
				  id=m_Array4[j];
				  m_A_temp.max_id=-1;   //atom ID			
				  for(k=0;k<ls_Array2.GetSize();k++)
				  {				
					  if(ls_Array2[k].m_m_Number==id&&ls_Array2[k].m_type==4)    //calculate maximun atom ID in tail
					  {
						  if(ls_Array2[k].m_A_Number>m_A_temp.max_id) 
						  {
							  m_A_temp.max_id=ls_Array2[k].m_A_Number;
							  m_max=k;
						  }
					  }							
				  }
				  //tilt angle=180/3.1415926*(acos(fabs(ls_Array2[m_max-4].m_z-ls_Array2[m_max].m_z)/sqrt(pow(ls_Array2[m_max-4].m_x-ls_Array2[m_max].m_x,2)+pow(ls_Array2[m_max-4].m_y-ls_Array2[m_max].m_y,2)+pow(ls_Array2[m_max-4].m_z-ls_Array2[m_max].m_z,2)))+acos(fabs(ls_Array2[m_max-4-6].m_z-ls_Array2[m_max-6].m_z)/sqrt(pow(ls_Array2[m_max-4-6].m_x-ls_Array2[m_max-6].m_x,2)+pow(ls_Array2[m_max-4-6].m_y-ls_Array2[m_max-6].m_y,2)+pow(ls_Array2[m_max-4-6].m_z-ls_Array2[m_max-6].m_z,2))))/2;
				  jd=((0.5*(3*(pow((fabs(ls_Array2[m_max-4].m_z-ls_Array2[m_max].m_z)/sqrt(pow(ls_Array2[m_max-4].m_x-ls_Array2[m_max].m_x,2)+pow(ls_Array2[m_max-4].m_y-ls_Array2[m_max].m_y,2)+pow(ls_Array2[m_max-4].m_z-ls_Array2[m_max].m_z,2))),2))-1))+(0.5*(3*(pow((fabs(ls_Array2[m_max-4-5].m_z-ls_Array2[m_max-5].m_z)/sqrt(pow(ls_Array2[m_max-4-5].m_x-ls_Array2[m_max-5].m_x,2)+pow(ls_Array2[m_max-4-5].m_y-ls_Array2[m_max-5].m_y,2)+pow(ls_Array2[m_max-4-5].m_z-ls_Array2[m_max-5].m_z,2))),2))-1)))*0.5;
				  ls_jd.Add(jd);
				  fprintf(out4,"%d %d %f\n",(m_Array1.GetSize()-1)*m_TimeVal,id,jd); 
				  m_jd_jz=m_jd_jz+jd;		
			  }
			  fclose(out4);
			  //AfxMessageBox("chain order done");
			  ////+++++++++++++++++++++++++++++++++ msd of around lipid last tail bead +++++++++++++++++++++++++++++++++
			  
			  out6 = fopen(m_FileName[6], "a");   //msd of the last tail bead in 2 tails of neighbour lipid at current frame
			  
			  float msd,time;
			  
			  for (j=0;j<m_Array4.GetSize();j++)   //lipid
			  {
				  id=m_Array4[j];
				  m_A_temp.max_id=-1;   //atom ID
				  
				  for(k=0;k<ls_Array2.GetSize();k++)
				  {			
					  if(ls_Array2[k].m_m_Number==id&&ls_Array2[k].m_type==4)    //calculate maximun atom ID in tail
					  {
						  if(ls_Array2[k].m_A_Number>m_A_temp.max_id) 
						  {
							  m_A_temp.max_id=ls_Array2[k].m_A_Number;
							  m_max=k;
						  }
					  }				
				  }
				  
				  for (k=0;k<m_Array22.GetSize();k++)
				  {
					  //////////////initial postion of last tail bead in tail 1
					  if(m_Array22[k].m_A_Number==ls_Array2[m_max].m_A_Number) 
					  {	
						  first_x=m_Array22[k].m_x;
						  first_y=m_Array22[k].m_y;
						  first_z=m_Array22[k].m_z;						
					  }
					  //////////////initial postion of last tail bead in tail 2
					  if(m_Array22[k].m_A_Number==ls_Array2[m_max-5].m_A_Number) 
					  {	
						  first_x2=m_Array22[k].m_x;	
						  first_y2=m_Array22[k].m_y;
						  first_z2=m_Array22[k].m_z;						
					  }
				  }
				  //////average msd of two tails in neighbour lipid
				  msd=(((pow(ls_Array2[m_max].m_x-first_x,2)+pow(ls_Array2[m_max].m_y-first_y,2)+pow(ls_Array2[m_max].m_z-first_z,2))/m_Array1.GetSize())+((pow(ls_Array2[m_max-5].m_x-first_x2,2)+pow(ls_Array2[m_max-5].m_y-first_y2,2)+pow(ls_Array2[m_max-5].m_z-first_z2,2))/m_Array1.GetSize()))/2;
				  
				  ls_msd.Add(msd);
				  fprintf(out6,"%d %d %f\n",(m_Array1.GetSize()-1)*m_TimeVal,id,msd); 
				  m_msd_jz=m_msd_jz+msd;
				  
			  }
			  
			  fclose(out6);
			  
			  //AfxMessageBox("msd done");
			  
			  ////+++++++++++++++++++++++++++++++++ RG of AM PEG chain+++++++++++++++++++++++++++++++++		   
			  out9 = fopen(m_FileName[9], "a");		  
			  
			  float flag1,flag2;
			  
			  for (j=0;j<m_Array3.GetSize();j++)   //
			  {
				  id=m_Array3[j];
				  center_x=0;  //center of mass in x of PEG chain
				  center_y=0;
				  center_z=0;
				  r_mean=0;
				  total_sum=0;			
				  pegcount=0;		  
				  for(k=0;k<ls_Array1.GetSize();k++)
				  {				  
					  if(ls_Array1[k].m_m_Number==id&&ls_Array1[k].m_type==6)    //
					  {
						  center_x=center_x+ls_Array1[k].m_x;
						  center_y=center_y+ls_Array1[k].m_y;
						  center_z=center_z+ls_Array1[k].m_z;
						  pegcount=pegcount+1;				  
					  }												    				
				  }
				  center_x=center_x/pegcount;
				  center_y=center_y/pegcount;
				  center_z=center_z/pegcount;
				  
				  for(k=0;k<ls_Array1.GetSize();k++)
				  {  
					  if(ls_Array1[k].m_m_Number==id&&ls_Array1[k].m_type==6)    //
					  {
						  r=pow(ls_Array1[k].m_x - center_x, 2) + pow(ls_Array1[k].m_y - center_y, 2) + pow(ls_Array1[k].m_z - center_z, 2);
						  r_mean=r_mean+r;							 
					  }												    				
				  }	  
				  r_mean=r_mean/pegcount;
				  
				  //m_RG= sqrt(total_sum/pegcount);
				  m_RG= sqrt(r_mean);
				  ls_RG.Add(m_RG);
				  
				  //fprintf(out9,"%d %d %f\n",(m_Array1.GetSize()-1)*10000,id,m_RG); 
				  fprintf(out9,"%d %d %f\n",(m_Array1.GetSize()-1)*m_TimeVal,id,m_RG); 
				  m_RG_jz= m_RG_jz+m_RG; //calculate RG in this frame  
			  }  
			  
			  fclose(out9);
			  ////+++++++++++++++++++++++++++++++++ EED	+++++++++++++++++++++++++++++++++		   
			  out11 = fopen(m_FileName[11], "a");	
			  for (j=0;j<m_Array3.GetSize();j++)   //
			  {
				  id=m_Array3[j];
				  m_A_temp.max_id=-1;   //	  
				  for(k=0;k<ls_Array1.GetSize();k++)
				  {	  
					  if(ls_Array1[k].m_m_Number==id&&ls_Array1[k].m_type==6)    //
					  {
						  if(ls_Array1[k].m_A_Number>m_A_temp.max_id) 
						  {
							  m_A_temp.max_id=ls_Array1[k].m_A_Number;
							  m_max=k;
						  }
					  }				  
				  }
				  
				  m_A_temp.min_id=m_A_temp.max_id-109;
				  
				  for(k=0;k<ls_Array1.GetSize();k++)
				  {
					  if(ls_Array1[k].m_m_Number==id&&ls_Array1[k].m_type==6&&ls_Array1[k].m_A_Number==m_A_temp.min_id)    //记录右边尾部的原子id最小值
					  {
						  m_min=k;
					  }  
				  }
				  
				  m_EED=sqrt(pow(ls_Array1[m_min].m_z-ls_Array1[m_max].m_z,2)+pow(ls_Array1[m_min].m_y-ls_Array1[m_max].m_y,2)+pow(ls_Array1[m_min].m_x-ls_Array1[m_max].m_x,2));
				  ls_EED.Add(m_EED);
				  fprintf(out11,"%d %d %f\n",(m_Array1.GetSize()-1)*10000,id,m_EED); 
				  m_EED_jz= m_EED_jz+m_EED; //calculate total EED in this frame  
			  }  
			  	  
			  fclose(out11);
			  
			  //AfxMessageBox("EED done");
			  
			  ////+++++++++++++++++++++++++++++++++ RG of AM tail	+++++++++++++++++++++++++++++++++		   
			  /////////the method here is following same logic of PEG RG
			  out14 = fopen(m_FileName[14], "a");		
			  
			  for (j=0;j<m_Array3.GetSize();j++)   //l
			  {
				  id=m_Array3[j];
				  center_x=0;
				  center_y=0;
				  center_z=0;
				  r_mean=0;
				  total_sum=0;			
				  pegcount=0;	
				  for(k=0;k<ls_Array1.GetSize();k++)
				  {		
					  if(ls_Array1[k].m_m_Number==id)    
					  {		
						  if(ls_Array1[k].m_type==5 || ls_Array1[k].m_type==4)
						  {
							  center_x=center_x+ls_Array1[k].m_x;
							  center_y=center_y+ls_Array1[k].m_y;
							  center_z=center_z+ls_Array1[k].m_z;
							  pegcount=pegcount+1;
						  }
						  if(pegcount==10)
						  {
							  break;
						  }
					  }												    				
				  }
				  center_x=center_x/pegcount;
				  center_y=center_y/pegcount;
				  center_z=center_z/pegcount;
				  r_count=0;
				  for(k=0;k<ls_Array1.GetSize();k++)
				  {		
					  if(ls_Array1[k].m_m_Number==id)    
					  {
						  if(ls_Array1[k].m_type==5 || ls_Array1[k].m_type==4)
						  {
							  r=pow(ls_Array1[k].m_x - center_x, 2) + pow(ls_Array1[k].m_y - center_y, 2) + pow(ls_Array1[k].m_z - center_z, 2);
							  r_mean=r_mean+r;
							  r_count=r_count+1;
						  }	
						  if(r_count==10)
						  {
							  break;
						  }					
					  }												    				
				  }	  
				  r_mean=r_mean/pegcount;	
				  m_tRG= sqrt(r_mean);
				  ls_tRG.Add(m_tRG);
				  
				  fprintf(out14,"%d %d %f\n",(m_Array1.GetSize()-1)*m_TimeVal,id,m_tRG); 
				  m_tRG_jz= m_tRG_jz+m_tRG; //calculate RG in this frame  
			  }  
			  
			  fclose(out14);	
			  //AfxMessageBox("tRG done");
			  
			  ////++++++++++++++++++++++++++++++++++++++++++++++ PEG corona thickness +++++++++++++++++++++++++++++++++++++++++
			  //This section calculate the thickness of PEG layer(up/down) separately, but all of them are output into dump_17
			  //Molecule number below 492 are molecules in down layer, above 492 are molecules in up layer
			  out17 = fopen(m_FileName[17], "a");
			  for (j=0;j<m_Array3.GetSize();j++)   
			  {  
				  id=m_Array3[j];
				  if (id > 492)
				  {
					  peg_maxz_up=-400;
					  peg_minz_up=400;
					  for(k=0;k<ls_Array1.GetSize();k++)
					  { 
						  if(ls_Array1[k].m_m_Number==id&&ls_Array1[k].m_type==6)    //
						  {
							  if(ls_Array1[k].m_z > peg_maxz_up)    //
							  {
								  peg_maxz_up=ls_Array1[k].m_z;
							  }	
							  if(ls_Array1[k].m_z < peg_minz_up)    //
							  {
								  peg_minz_up=ls_Array1[k].m_z;
							  }	
						  }												    				
					  }
					  thickness_up=fabs(peg_maxz_up-peg_minz_up);
					  fprintf(out17,"%d %d %f\n",(m_Array1.GetSize()-1)*m_TimeVal,id,thickness_up); 
					  ls_thickness_up.Add(thickness_up);
					  m_upthick_jz=m_upthick_jz+thickness_up;
				  }
				  if (id < 492)
				  {
					  peg_maxz_down=-400;
					  peg_minz_down=400;
					  for(k=0;k<ls_Array1.GetSize();k++)
					  {
						  if(ls_Array1[k].m_m_Number==id&&ls_Array1[k].m_type==6)    //
						  {
							  if(ls_Array1[k].m_z > peg_maxz_down)    //
							  {
								  peg_maxz_down=ls_Array1[k].m_z;  
							  }	
							  if(ls_Array1[k].m_z < peg_minz_down)    //
							  {
								  peg_minz_down=ls_Array1[k].m_z;
							  }	
						  }												    				
					  }
					  thickness_down=fabs(peg_maxz_down-peg_minz_down);
					  fprintf(out17,"%d %d %f\n",(m_Array1.GetSize()-1)*m_TimeVal,id,thickness_down); 
					  ls_thickness_down.Add(thickness_down);
					  m_downthick_jz=m_downthick_jz+thickness_down;
				  }
			  }  		
			  
			  fclose(out17);
			  
			  ////++++++++++++++++++++++++++++++++++++++++++++++++++PEG_density++++++++++++++++++++++++++++++++++++++++
			  //This Section is used to calculate the PEG bead number in each slad, the simualtion box is devided to 160 same size slab
			  //results stored in dump_18, it needs post-process in matlab called 'thickness.m''		  
			  out18 = fopen(m_FileName[18], "a");
			  CString t1 = "time";
              CString t2 = "AM_num";
              CString t3 = "data";
			  fprintf(out18,"%s\n",t1);			
              fprintf(out18,"%d\n",(m_Array1.GetSize()-1)*m_TimeVal);
			  fprintf(out18,"%s\n",t2);
              fprintf(out18,"%d\n",m_Array3.GetSize());
			  fprintf(out18,"%s\n",t3);
			  //if (m_Array1.GetSize()==1) 
			  //{
			  for (h=0;h<160;h++)
			  {
				  thick=(h+1-80)*5;
				  thick2=(h-80)*5;
				  n=0;			  
				  for(k=0;k<ls_Array1.GetSize();k++)
				  {
					  if(ls_Array1[k].m_type==6 && ls_Array1[k].m_wz < thick && ls_Array1[k].m_wz > thick2)
					  {
						  n=n+1; 
					  }
				  }
				  peg=n/(110/2*m_Array3.GetSize());
				  fprintf(out18,"%d %d %d\n",thick2,n,(m_Array3.GetSize()*110/2)); 
			  }
			  //}	  
			  fclose(out18);
			  
			  ///////////////////////////////////output PEG bead matrix///////////////////////////////////////////
			  out19 = fopen(m_FileName[19], "a");	 
			  //char time='time', AM_num='AM_num', data='data';	
			  CString s1 = "time";
			  CString s2 = "AM_num";
			  CString s3 = "data";
			  //char   c = '\n'; 
			  fprintf(out19,"%s\n",s1);			
			  fprintf(out19,"%d\n",(m_Array1.GetSize()-1)*m_TimeVal);
			  fprintf(out19,"%s\n",s2);
			  fprintf(out19,"%d\n",m_Array3.GetSize());
			  fprintf(out19,"%s\n",s3);
			  
			  for(k=0;k<ls_Array1.GetSize();k++)
			  {
				  if(ls_Array1[k].m_type==6)
				  {
					  fprintf(out19,"%d %d %d %f %f %f %d\n",ls_Array1[k].m_A_Number,ls_Array1[k].m_m_Number,ls_Array1[k].m_type,ls_Array1[k].m_x,ls_Array1[k].m_y,ls_Array1[k].m_z,(m_Array1.GetSize()-1)*m_TimeVal); 	
				  }																    				
			  }	  
			  
			  fclose(out19);
			  
			  
			  /*	  //+++++++++++++++++++++++++++++Local Area of enighbour lipid+++++++++++++++++++
			  out11 = fopen(m_FileName[11], "a");
			  
				float z1_x,z1_y,z1_z;
				float z2_x,z2_y,z2_z;
				float z21_x,z21_y,z21_z;
				float z10_x,z10_y,z10_z;
				float m_distance,m_maxdis;
				
				  for (j=0;j<m_Array4.GetSize();j++)   //lipid
				  {
				  id=m_Array4[j];
				  m_A_temp.max_id=-1;   //atom ID
				  m_distance=-1;
				  m_maxdis=-1;
				  
					if (m_xh.GetSize()>0) m_xh.RemoveAll();   //
					
					  
						for(k=0;k<ls_Array2.GetSize();k++)
						{
						
						  if(ls_Array2[k].m_m_Number==id&&ls_Array2[k].m_type==4)    //calculate maximun atom ID in tail
						  {
						  if(ls_Array2[k].m_A_Number>m_A_temp.max_id) 
						  {
						  m_A_temp.max_id=ls_Array2[k].m_A_Number;
						  m_max=k;
						  }
						  }
							  
						}
							
								z1_x=(ls_Array2[m_max].m_x+ls_Array2[m_max-5].m_x)/2;
								z1_y=(ls_Array2[m_max].m_y+ls_Array2[m_max-5].m_y)/2;
								z1_z=(ls_Array2[m_max].m_z+ls_Array2[m_max-5].m_z)/2;
								  
								z2_x=(ls_Array2[m_max-4].m_x+ls_Array2[m_max-5-4].m_x)/2;
							    z2_y=(ls_Array2[m_max-4].m_y+ls_Array2[m_max-5-4].m_y)/2;
								z2_z=(ls_Array2[m_max-4].m_z+ls_Array2[m_max-5-4].m_z)/2;
									
								z21_x=z2_x-z1_x;//z21=z2-z1
								z21_y=z2_y-z1_y;
								z21_z=z2_z-z1_z;
									  
										//a=(X1,Y1,Z1),b=(X2,Y2,Z2), aXb=(Y1Z2-Y2Z1,Z1X2-Z2X1,X1Y2-X2Y1)
										
										  for(k=0;k<ls_Array2.GetSize();k++)
										  {				
										  if(ls_Array2[k].m_m_Number==id&&ls_Array2[k].m_type==4)    //calculate maximun atom ID in tail
										  {
										  z10_x=z1_x-ls_Array2[k].m_x;
										  z10_y=z1_y-ls_Array2[k].m_y;
										  z10_z=z1_z-ls_Array2[k].m_z;
										  m_distance= (sqrt(pow((z21_y*z10_z-z10_y*z21_z),2)+pow((z21_z*z10_x-z21_x*z10_z),2)+pow((z21_x*z10_y-z10_x*z21_y),2)))/(sqrt(pow(z21_x,2)+pow(z21_y,2)+pow(z21_z,2)));
										  if(m_distance>m_maxdis) 
										  {
										  m_maxdis=m_distance;
										  
										}
											
										}
										}
											  
						m_Area=3.1415926*pow(m_maxdis,2);
												
						ls_Area.Add(m_Area);
						fprintf(out11,"%d %d %f\n",(m_Array1.GetSize()-1)*m_TimeVal,id,m_Area); 
						m_Area_jz=m_Area_jz+m_Area;
												  
						}
						fclose(out11);
						//AfxMessageBox("Area done");
			  */
			  
			  //++++++++++++++++++++++++++++++++++++++++++++global area per lipid+++++++++++++++++++++++++++++++++++++++++
			  //boundary of box and avg area per lipid, useful in NPT
			  out13 = fopen(m_FileName[13], "a");  //
			  
			  fprintf(out13,"%d %f %7.4f\n",(m_Array1.GetSize()-1)*m_TimeVal,2*bd*2*bd/492,bd);
			  
			  fclose(out13);
			  
			  //+++++++++++++++++++++++++++++++++++++calculate mean/S.D. of previous results+++++++++++++++++++++++++++++++
			  //+++++++++++++chain order mean/SD+++++++++++++++
			  
			  out5 = fopen(m_FileName[5], "a");   //
			  
			  if(m_Array4.GetSize()>0)
			  {
				  m_jd_jz=m_jd_jz*1.0/ls_jd.GetSize();   //mean
				  
				  for (j=0;j<m_Array4.GetSize();j++)
				  {
					  m_jd_fc=m_jd_fc+pow(ls_jd[j]-m_jd_jz,2);
				  }
				  
				  m_jd_fc=pow(m_jd_fc*1.0/m_Array4.GetSize(),0.5);   //SD
				  
				  fprintf(out5,"%d %f %f\n",(m_Array1.GetSize()-1)*m_TimeVal,m_jd_jz,m_jd_fc); 
			  }
			  
			  fclose(out5);
			  
			  //AfxMessageBox("angle done");
			  //+++++++++++++msd mean/SD+++++++++++++++
			  
			  out7 = fopen(m_FileName[7], "a");   //
			  
			  if(m_Array4.GetSize()>0)
			  {
				  m_msd_jz=m_msd_jz*1.0/ls_msd.GetSize();   //mean
				  
				  for (j=0;j<m_Array4.GetSize();j++)
				  {
					  m_msd_fc=m_msd_fc+pow(ls_msd[j]-m_msd_jz,2);
				  }
				  
				  m_msd_fc=pow(m_msd_fc*1.0/m_Array4.GetSize(),0.5);   //SD
				  
				  fprintf(out7,"%d %f %f\n",(m_Array1.GetSize()-1)*m_TimeVal,m_msd_jz,m_msd_fc); 
			  }
			  
			  fclose(out7);
			  
			  //AfxMessageBox("msd done");
			  //++++++++++++++PEG RG mean/SD++++++++++++++		  
			  
			  out10 = fopen(m_FileName[10], "a");  //
			  
			  if(m_Array3.GetSize()>0)
			  {
				  m_RG_jz =m_RG_jz*1.0/ls_RG.GetSize();   //mean
				  
				  for (j=0;j<m_Array3.GetSize();j++)
				  {
					  m_RG_fc=m_RG_fc+pow(ls_RG[j]-m_RG_jz,2);
				  }
				  
				  m_RG_fc=pow(m_RG_fc*1.0/m_Array3.GetSize(),0.5);   //SD
				  
				  fprintf(out10,"%d %f %f\n",(m_Array1.GetSize()-1)*m_TimeVal,m_RG_jz,m_RG_fc); 
			  }			  
			  
			  fclose(out10);
			  
			  //AfxMessageBox("PEG RG done");
			  //++++++++++++++EED mean/SD++++++++++++++
			  
			  out12 = fopen(m_FileName[12], "a");  //
			  
			  if(m_Array3.GetSize()>0)
			  {
				  m_EED_jz =m_EED_jz*1.0/ls_EED.GetSize();   //mean
				  
				  for (j=0;j<m_Array3.GetSize();j++)
				  {
                      m_EED_fc=m_EED_fc+pow(ls_EED[j]-m_EED_jz,2);
				  }
				  
				  m_EED_fc=pow(m_EED_fc*1.0/m_Array3.GetSize(),0.5);   //SD
				  
				  fprintf(out12,"%d %f %f\n",(m_Array1.GetSize()-1)*10000,m_EED_jz,m_EED_fc); 
			  }
			  
			  fclose(out12);
			  
			  //++++++++++++++AM tail RG mean/SD++++++++++++++
			  
			  
			  
			  out15 = fopen(m_FileName[15], "a");  //
			  
			  if(m_Array3.GetSize()>0)
			  {
				  m_tRG_jz =m_tRG_jz*1.0/ls_tRG.GetSize();   //?????
				  
				  for (j=0;j<m_Array3.GetSize();j++)
				  {
					  m_tRG_fc=m_tRG_fc+pow(ls_tRG[j]-m_tRG_jz,2);
				  }
				  
				  m_tRG_fc=pow(m_tRG_fc*1.0/m_Array3.GetSize(),0.5);   //??????
				  
				  fprintf(out15,"%d %f %f\n",(m_Array1.GetSize()-1)*m_TimeVal,m_tRG_jz,m_tRG_fc); 
			  }
			  
			  
			  fclose(out15);
			  
			  //AfxMessageBox("tRG done");			   
			  //++++++++++++++thickness mean/SD++++++++++++++		  
			  
			  out16 = fopen(m_FileName[16], "a");  //
			  
			  if(m_Array3.GetSize()>0)
			  {
				  m_upthick_jz =m_upthick_jz*1.0/ls_thickness_up.GetSize();   //mean of up thickness
				  
				  for (j=0;j<ls_thickness_up.GetSize();j++)
				  {
					  m_upthick_fc=m_upthick_fc+pow(ls_thickness_up[j]- m_upthick_jz,2);
				  }	  
				  m_upthick_fc=pow(m_upthick_fc*1.0/ls_thickness_up.GetSize(),0.5);   //SD of up thickness
				  ////////////////////////////////////////////////////////////////////////////////////////	  
				  m_downthick_jz =m_downthick_jz*1.0/ls_thickness_down.GetSize();   //mean of down thickness
				  
				  for (j=0;j<ls_thickness_down.GetSize();j++)
				  {
					  m_downthick_fc=m_downthick_fc+pow(ls_thickness_down[j]- m_downthick_jz,2);
				  }				  
				  m_downthick_fc=pow(m_downthick_fc*1.0/ls_thickness_down.GetSize(),0.5);   //SD of down thickness			  	  
				  fprintf(out16,"%d %f %f %f %f\n",(m_Array1.GetSize()-1)*m_TimeVal,m_upthick_jz,m_upthick_fc,m_downthick_jz,m_downthick_fc); 
			  }		  
			  fclose(out16);
			  
			  //AfxMessageBox("thickness done");			  
			  
   	  }
	  
	  //close file
	  file1.Close(); 
	  
	  AfxMessageBox("meansure done");
}
