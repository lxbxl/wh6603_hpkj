#include "Stdafx.h"
#include "GameOption.h"

//////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CGameOption, CSkinDialog)
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////

//构造函数
CGameOption::CGameOption() : CSkinDialog(IDD_OPTION)
{
	m_bEnableSound=true;
	m_bAllowLookon=false;
	m_bEanbleAnimate = true;

	return;
}

//析构函数
CGameOption::~CGameOption()
{
}

//控件绑定
void CGameOption::DoDataExchange(CDataExchange * pDX)
{
	__super::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_btOK);
	DDX_Control(pDX, IDCANCEL, m_btCancel);
}

//初始化函数
BOOL CGameOption::OnInitDialog()
{
	__super::OnInitDialog();

	//设置标题
	SetWindowText(TEXT("游戏配置"));


	if(m_bAllowLookon == true)
	{
		((CButton *)GetDlgItem(IDC_ENABLE_LOOKON))->SetCheck(BST_CHECKED);
	}

	//设置控件
	if (m_bEnableSound==true) 
		((CButton *)GetDlgItem(IDC_ENABLE_SOUND))->SetCheck(BST_CHECKED);

	//设置显示动画
	if( m_bEanbleAnimate )
		((CButton *)GetDlgItem(IDC_ENABLE_ANIMATE))->SetCheck(BST_CHECKED);


	return TRUE;
}

//确定消息
void CGameOption::OnOK()
{
	//获取变量
	m_bEnableSound=(((CButton *)GetDlgItem(IDC_ENABLE_SOUND))->GetCheck()==BST_CHECKED);
	m_bAllowLookon =(((CButton *)GetDlgItem(IDC_ENABLE_LOOKON))->GetCheck()==BST_CHECKED);
	m_bEanbleAnimate =(((CButton *)GetDlgItem(IDC_ENABLE_ANIMATE))->GetCheck()==BST_CHECKED);

	__super::OnOK();
}

//////////////////////////////////////////////////////////////////////////
