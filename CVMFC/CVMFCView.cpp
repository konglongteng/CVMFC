// CVMFCView.cpp : implementation of the CCVMFCView class
//

#include "stdafx.h"
 
#include "CVMFCDoc.h"
#include "CVMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCVMFCView

IMPLEMENT_DYNCREATE(CCVMFCView, CScrollView)

BEGIN_MESSAGE_MAP(CCVMFCView, CScrollView)
	//{{AFX_MSG_MAP(CCVMFCView)
 	ON_UPDATE_COMMAND_UI(ID_REFRESH, OnUpdateRefresh)
	ON_UPDATE_COMMAND_UI(ID_COLOR_IMAGE_REFRESH, OnUpdateColorImageRefresh)
	ON_UPDATE_COMMAND_UI(ID_CAPTURE_IMAGE, OnUpdateCaptureImage)
 	ON_UPDATE_COMMAND_UI(ID_CAP_ABORT, OnUpdateCapAbort)
 	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	ON_UPDATE_COMMAND_UI(ID_FILE_CLOSE, OnUpdateFileClose)
 	ON_UPDATE_COMMAND_UI(ID_START_CAPTURE, OnUpdateStartCapture)
	ON_UPDATE_COMMAND_UI(ID_OPEN_AVI_FILE, OnUpdateOpenAviFile)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONTINUE, OnUpdateViewContinue)
  	ON_COMMAND(ID_REFRESH, OnRefresh)
	ON_COMMAND(ID_COLOR_IMAGE_REFRESH, OnColorImageRefresh)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
 	ON_COMMAND(ID_START_CAPTURE, OnStartCapture)
	ON_COMMAND(ID_CAPTURE_IMAGE, OnCaptureImage)
 	ON_COMMAND(ID_CAP_ABORT, OnCapAbort)
	ON_COMMAND(ID_OPEN_AVI_FILE, OnOpenAviFile)
	ON_COMMAND(ID_VIEW_CONTINUE, OnViewContinue)
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(ID_GAUSS_SMOOTH, OnUpdateGaussSmooth)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_SHRINK, OnUpdateImageShrink)
	ON_UPDATE_COMMAND_UI(ID_CANNY_BORDDETEC, OnUpdateCannyBorddetec)
	ON_COMMAND(ID_GAUSS_SMOOTH, OnGaussSmooth)
	ON_COMMAND(ID_IMAGE_SHRINK, OnImageShrink)
	ON_COMMAND(ID_CANNY_BORDDETEC, OnCannyBorddetec)
	ON_UPDATE_COMMAND_UI(ID_COLOR_TO_GRAY, OnUpdateColorToGray)
	ON_UPDATE_COMMAND_UI(ID_FLIP_V, OnUpdateFlipV)
	ON_UPDATE_COMMAND_UI(ID_FLIP_H, OnUpdateFlipH)
	ON_COMMAND(ID_COLOR_TO_GRAY, OnColorToGray)
	ON_COMMAND(ID_FLIP_V, OnFlipV)
	ON_COMMAND(ID_FLIP_H, OnFlipH)
	ON_UPDATE_COMMAND_UI(ID_FLIP, OnUpdateFlip)
	ON_COMMAND(ID_FLIP, OnFlip)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_INVERT, OnUpdateImageInvert)
	ON_COMMAND(ID_IMAGE_INVERT, OnImageInvert)
	ON_UPDATE_COMMAND_UI(ID_SOBEL, OnUpdateSobel)
	ON_UPDATE_COMMAND_UI(ID_LAPLACE, OnUpdateLaplace)
	ON_COMMAND(ID_SOBEL, OnSobel)
	ON_COMMAND(ID_LAPLACE, OnLaplace)
	ON_UPDATE_COMMAND_UI(ID_CONSERVATION_IMAGE, OnUpdateConservationImage)
	ON_COMMAND(ID_CONSERVATION_IMAGE, OnConservationImage)
	ON_UPDATE_COMMAND_UI(ID_SET_PARAMETER, OnUpdateSetParameter)
	ON_COMMAND(ID_SET_PARAMETER, OnSetParameter)
	ON_UPDATE_COMMAND_UI(ID_RADIAL_GRADS, OnUpdateRadialGrads)
	ON_COMMAND(ID_RADIAL_GRADS, OnRadialGrads)
	ON_UPDATE_COMMAND_UI(ID_EROSION, OnUpdateErosion)
	ON_UPDATE_COMMAND_UI(ID_DILATION, OnUpdateDilation)
	ON_UPDATE_COMMAND_UI(ID_OPENNING, OnUpdateOpenning)
	ON_UPDATE_COMMAND_UI(ID_CLOSING, OnUpdateClosing)
	ON_UPDATE_COMMAND_UI(ID_GRADS, OnUpdateGrads)
	ON_UPDATE_COMMAND_UI(ID_GRAY_TOPHAT, OnUpdateGrayTophat)
	ON_UPDATE_COMMAND_UI(ID_GRAY_BLACKHAT, OnUpdateGrayBlackhat)
	ON_COMMAND(ID_EROSION, OnErosion)
	ON_COMMAND(ID_DILATION, OnDilation)
	ON_COMMAND(ID_OPENNING, OnOpenning)
	ON_COMMAND(ID_CLOSING, OnClosing)
	ON_COMMAND(ID_GRADS, OnGrads)
	ON_COMMAND(ID_GRAY_TOPHAT, OnGrayTophat)
	ON_COMMAND(ID_GRAY_BLACKHAT, OnGrayBlackhat)
	ON_UPDATE_COMMAND_UI(ID_ADAPTIVE_THRESHOLD, OnUpdateAdaptiveThreshold)
	ON_COMMAND(ID_ADAPTIVE_THRESHOLD, OnAdaptiveThreshold)
	ON_UPDATE_COMMAND_UI(ID_BASIC_GLOBAL_THRESHOLD, OnUpdateBasicGlobalThreshold)
	ON_COMMAND(ID_BASIC_GLOBAL_THRESHOLD, OnBasicGlobalThreshold)
	ON_UPDATE_COMMAND_UI(ID_CONTOUR_TRACK, OnUpdateContourTrack)
	ON_COMMAND(ID_CONTOUR_TRACK, OnContourTrack)
	ON_UPDATE_COMMAND_UI(ID_DISTANCE, OnUpdateDistance)
	ON_COMMAND(ID_DISTANCE, OnDistance)
	ON_UPDATE_COMMAND_UI(ID_AVERAGE_IMAGE, OnUpdateAverageImage)
	ON_COMMAND(ID_AVERAGE_IMAGE, OnAverageImage)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_HISTOGRAM, OnUpdateImageHistogram)
	ON_COMMAND(ID_IMAGE_HISTOGRAM, OnImageHistogram)
	ON_UPDATE_COMMAND_UI(ID_ROTATION_30, OnUpdateRotation30)
	ON_COMMAND(ID_ROTATION_30, OnRotation30)
	ON_UPDATE_COMMAND_UI(ID_BLUR_SMOOTH, OnUpdateBlurSmooth)
	ON_UPDATE_COMMAND_UI(ID_MEDIAN_SMOOTH, OnUpdateMedianSmooth)
	ON_COMMAND(ID_BLUR_SMOOTH, OnBlurSmooth)
	ON_COMMAND(ID_MEDIAN_SMOOTH, OnMedianSmooth)
	ON_UPDATE_COMMAND_UI(ID_SNAKE, OnUpdateSnake)
	ON_COMMAND(ID_SNAKE, OnSnake)
	ON_UPDATE_COMMAND_UI(ID_CONVEX_HULL, OnUpdateConvexHull)
	ON_COMMAND(ID_CONVEX_HULL, OnConvexHull)
	ON_UPDATE_COMMAND_UI(ID_FIT_ELLIPSE, OnUpdateFitEllipse)
	ON_COMMAND(ID_FIT_ELLIPSE, OnFitEllipse)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_ADJUST, OnUpdateImageAdjust)
	ON_UPDATE_COMMAND_UI(ID_HIST_EQUALIZE, OnUpdateHistEqualize)
	ON_COMMAND(ID_IMAGE_ADJUST, OnImageAdjust)
	ON_COMMAND(ID_HIST_EQUALIZE, OnHistEqualize)
	ON_UPDATE_COMMAND_UI(ID_AREA_CONVEX_HULL, OnUpdateAreaConvexHull)
	ON_COMMAND(ID_AREA_CONVEX_HULL, OnAreaConvexHull)
	ON_UPDATE_COMMAND_UI(ID_MIN_AREA_RECT, OnUpdateMinAreaRect)
	ON_COMMAND(ID_MIN_AREA_RECT, OnMinAreaRect)
	ON_UPDATE_COMMAND_UI(ID_AREA_RECT, OnUpdateAreaRect)
	ON_COMMAND(ID_AREA_RECT, OnAreaRect)
	ON_UPDATE_COMMAND_UI(ID_APPROX_POLY, OnUpdateApproxPoly)
	ON_COMMAND(ID_APPROX_POLY, OnApproxPoly)
	ON_WM_SIZE()
	ON_UPDATE_COMMAND_UI(ID_CONVEXITY_DEFECTS, OnUpdateConvexityDefects)
	ON_COMMAND(ID_CONVEXITY_DEFECTS, OnConvexityDefects)
	ON_UPDATE_COMMAND_UI(ID_WATERSHED, OnUpdateWatershed)
	ON_COMMAND(ID_WATERSHED, OnWatershed)
	ON_UPDATE_COMMAND_UI(ID_FLOOD_FILL, OnUpdateFloodFill)
	ON_UPDATE_COMMAND_UI(ID_PYR_SEGMENTATION, OnUpdatePyrSegmentation)
	ON_COMMAND(ID_FLOOD_FILL, OnFloodFill)
	ON_COMMAND(ID_PYR_SEGMENTATION, OnPyrSegmentation)
	ON_UPDATE_COMMAND_UI(ID_THRESHOLDING_1, OnUpdateThresholding1)
	ON_COMMAND(ID_THRESHOLDING_1, OnThresholding1)
	ON_UPDATE_COMMAND_UI(ID_THRESHOLDING_2, OnUpdateThresholding2)
	ON_COMMAND(ID_THRESHOLDING_2, OnThresholding2)
	ON_UPDATE_COMMAND_UI(ID_CORNERS_TEST, OnUpdateCornersTest)
	ON_COMMAND(ID_CORNERS_TEST, OnCornersTest)
	ON_UPDATE_COMMAND_UI(ID_DYNAMIC_BORDER_TEST, OnUpdateDynamicBorderTest)
	ON_COMMAND(ID_DYNAMIC_BORDER_TEST, OnDynamicBorderTest)
	ON_UPDATE_COMMAND_UI(ID_OPTICAL_FLOW_TRACK, OnUpdateOpticalFlowTrack)
	ON_COMMAND(ID_OPTICAL_FLOW_TRACK, OnOpticalFlowTrack)
	ON_UPDATE_COMMAND_UI(ID_CONVEX_HULL_2, OnUpdateConvexHull2)
	ON_COMMAND(ID_CONVEX_HULL_2, OnConvexHull2)
	ON_UPDATE_COMMAND_UI(ID_MOTION_DETECT, OnUpdateMotionDetect)
	ON_COMMAND(ID_MOTION_DETECT, OnMotionDetect)
	ON_UPDATE_COMMAND_UI(ID_MIN_AREA_RECT_2, OnUpdateMinAreaRect2)
	ON_COMMAND(ID_MIN_AREA_RECT_2, OnMinAreaRect2)
	ON_UPDATE_COMMAND_UI(ID_CAM_SHIFT_DEMO, OnUpdateCamShiftDemo)
	ON_COMMAND(ID_CAM_SHIFT_DEMO, OnCamShiftDemo)
	ON_UPDATE_COMMAND_UI(ID_CLUSTERS, OnUpdateClusters)
	ON_COMMAND(ID_CLUSTERS, OnClusters)
	ON_UPDATE_COMMAND_UI(ID_HOUGH_LINES, OnUpdateHoughLines)
	ON_COMMAND(ID_HOUGH_LINES, OnHoughLines)
	ON_UPDATE_COMMAND_UI(ID_SQUARES_TEST, OnUpdateSquaresTest)
	ON_COMMAND(ID_SQUARES_TEST, OnSquaresTest)
	ON_UPDATE_COMMAND_UI(ID_ROTATION_TRACK, OnUpdateRotationTrack)
	ON_COMMAND(ID_ROTATION_TRACK, OnRotationTrack)
	ON_UPDATE_COMMAND_UI(ID_FACE_DETECT, OnUpdateFaceDetect)
	ON_COMMAND(ID_FACE_DETECT, OnFaceDetect)
	ON_UPDATE_COMMAND_UI(IF_FOREGROUND_DETECT, OnUpdateForegroundDetect)
	ON_COMMAND(IF_FOREGROUND_DETECT, OnForegroundDetect)
	ON_UPDATE_COMMAND_UI(ID_FACE_DETECT_2, OnUpdateFaceDetect2)
	ON_COMMAND(ID_FACE_DETECT_2, OnFaceDetect2)
	ON_UPDATE_COMMAND_UI(ID_DRAWING, OnUpdateDrawing)
	ON_UPDATE_COMMAND_UI(ID_DELAUNAY, OnUpdateDelaunay)
	ON_COMMAND(ID_DRAWING, OnDrawing)
	ON_COMMAND(ID_DELAUNAY, OnDelaunay)
	ON_UPDATE_COMMAND_UI(ID_DFT, OnUpdateDft)
	ON_COMMAND(ID_DFT, OnDft)
	ON_UPDATE_COMMAND_UI(ID_HOUGH_CIRCLE, OnUpdateHoughCircle)
	ON_COMMAND(ID_HOUGH_CIRCLE, OnHoughCircle)
	ON_UPDATE_COMMAND_UI(ID_BLUR_SMOOTH_C, OnUpdateBlurSmoothC)
	ON_UPDATE_COMMAND_UI(ID_GAUSS_SMOOTH_C, OnUpdateGaussSmoothC)
	ON_UPDATE_COMMAND_UI(ID_MEDIAN_SMOOTH_C, OnUpdateMedianSmoothC)
	ON_UPDATE_COMMAND_UI(ID_SOBEL_C, OnUpdateSobelC)
	ON_UPDATE_COMMAND_UI(ID_LAPLACE_C, OnUpdateLaplaceC)
	ON_COMMAND(ID_BLUR_SMOOTH_C, OnBlurSmoothC)
	ON_COMMAND(ID_GAUSS_SMOOTH_C, OnGaussSmoothC)
	ON_COMMAND(ID_MEDIAN_SMOOTH_C, OnMedianSmoothC)
	ON_COMMAND(ID_SOBEL_C, OnSobelC)
	ON_COMMAND(ID_LAPLACE_C, OnLaplaceC)
	ON_UPDATE_COMMAND_UI(ID_LOG_POLAR, OnUpdateLogPolar)
	ON_COMMAND(ID_LOG_POLAR, OnLogPolar)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_RGB, OnUpdateImageRgb)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_HSV, OnUpdateImageHsv)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_LAB, OnUpdateImageLab)
	ON_COMMAND(ID_IMAGE_RGB, OnImageRgb)
	ON_COMMAND(ID_IMAGE_HSV, OnImageHsv)
	ON_COMMAND(ID_IMAGE_LAB, OnImageLab)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_XYZ, OnUpdateImageXyz)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_YCRCB, OnUpdateImageYcrcb)
	ON_COMMAND(ID_IMAGE_XYZ, OnImageXyz)
	ON_COMMAND(ID_IMAGE_YCRCB, OnImageYcrcb)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_LUV, OnUpdateImageLuv)
	ON_COMMAND(ID_IMAGE_LUV, OnImageLuv)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_RGB_C, OnUpdateImageRgbC)
	ON_COMMAND(ID_IMAGE_RGB_C, OnImageRgbC)
	ON_UPDATE_COMMAND_UI(ID_2D_HISTOGRAM, OnUpdate2dHistogram)
	ON_COMMAND(ID_2D_HISTOGRAM, On2dHistogram)
	ON_UPDATE_COMMAND_UI(ID_SEQ_PARTITION, OnUpdateSeqPartition)
	ON_COMMAND(ID_SEQ_PARTITION, OnSeqPartition)
	ON_UPDATE_COMMAND_UI(ID_WARP_AFFINE, OnUpdateWarpAffine)
	ON_COMMAND(ID_WARP_AFFINE, OnWarpAffine)
	ON_UPDATE_COMMAND_UI(ID_WARP_PERSPECT, OnUpdateWarpPerspect)
	ON_COMMAND(ID_WARP_PERSPECT, OnWarpPerspect)
	ON_UPDATE_COMMAND_UI(ID_FILE_OPEN, OnUpdateFileOpen)
	ON_UPDATE_COMMAND_UI(ID_APP_EXIT, OnUpdateAppExit)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCVMFCView construction/destruction

CFile fCapture;
CFileException eCapture;
char pbuf[20];
int  captSetFlag=0;
 
CCVMFCView::CCVMFCView()
{
	// TODO: add construction code here
	saveImg    = NULL;
	workImg    = NULL;
  
	m_lpBmi    = 0;

	m_CaptFlag = 0;
	m_dibFlag  = 0;
 	m_ImageType= 0;
  
	CSize sizeTotal;
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);

	if(fCapture.Open( "CaptSetup.txt", CFile::modeRead, &eCapture ) )
	{
		fCapture.Read( pbuf, 20 );          //  取出分辨率设置数据
 		sscanf(pbuf,"%d  %d",&frameSetW,&frameSetH);
		fCapture.Close();
	}
}

CCVMFCView::~CCVMFCView()
{
	if (m_CaptFlag)
		AbortCapture(workImg);              //  关闭视频

 	if (saveImg)
		cvReleaseImage(&saveImg);           //  释放位图
 	if (workImg)
		cvReleaseImage(&workImg);
 
	if (m_lpBmi)
		free(m_lpBmi);                      //  释放位图信息
	

	if (captSetFlag==1) {
		if(fCapture.Open( "CaptSetup.txt", CFile::modeCreate | 
			CFile::modeWrite, &eCapture ) )
		{
			sprintf(pbuf,"%d  %d",frameSetW,frameSetH);
			fCapture.Write( pbuf, 20 );     //  分辨率设置数据存盘
			fCapture.Close();
		}
		captSetFlag=0;
	}
}

BOOL CCVMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCVMFCView drawing

void CCVMFCView::OnDraw(CDC* pDC)
{
	CCVMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	if (pDoc->pImg!=NULL)	{	            //  有磁盘输入图像
		if (pDoc->m_Display==0) {           //  尚未显示
 			imageClone(pDoc->pImg,&saveImg);         //  复制到备份位图
			m_dibFlag=imageClone(saveImg,&workImg);  //  复制到工作位图

			m_ImageType=imageType(workImg);
			m_SaveFlag=m_ImageType;
			pDoc->m_Display=1;
		}
	}
 
	if (m_dibFlag) {                        //  DIB 结构改变
 		if (m_lpBmi)
			free(m_lpBmi);
		m_lpBmi=CtreateMapInfo(workImg,m_dibFlag);
		m_dibFlag=0;

		CSize  sizeTotal;
 		sizeTotal = CSize(workImg->width,workImg->height);
		SetScrollSizes(MM_TEXT,sizeTotal);  //  设置滚动条
	}

	char *pBits;
	if (m_CaptFlag==1) pBits=m_Frame->imageData;
	else if (workImg)  pBits=workImg->imageData;

	if (workImg) {                          //  刷新窗口画面
		StretchDIBits(pDC->m_hDC,
			    0,0,workImg->width,workImg->height,
				0,0,workImg->width,workImg->height,
				pBits,m_lpBmi,DIB_RGB_COLORS,SRCCOPY);
	}
}

void CCVMFCView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CCVMFCView diagnostics

#ifdef _DEBUG
void CCVMFCView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CCVMFCView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CCVMFCDoc* CCVMFCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCVMFCDoc)));
	return (CCVMFCDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCVMFCView message handlers

//---------------------------------------------------------
//  图像恢复与存储

void CCVMFCView::OnUpdateFileOpen(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable(m_ImageType!=-3);
}

void CCVMFCView::OnUpdateRefresh(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateConservationImage(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateFileClose(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateColorImageRefresh(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateAppExit(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable(m_ImageType!=-3);
}

void CCVMFCView::OnRefresh() 
{
	m_dibFlag=imageClone(saveImg,&workImg);
	m_ImageType=m_SaveFlag;
  	Invalidate();
}

void CCVMFCView::OnConservationImage() 
{
 	imageClone(workImg,&saveImg);
	m_SaveFlag=m_ImageType;
}

void CCVMFCView::OnColorImageRefresh() 
{
	CCVMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->m_Display=0;
	Invalidate();
}

void CCVMFCView::OnFileSaveAs() 
{
    CString csBMP="BMP Files(*.BMP)|*.BMP|";
	CString csJPG="JPEG Files(*.JPG)|*.JPG|";
	CString csTIF="TIF Files(*.TIF)|*.TIF|";
	CString csPNG="PNG Files(*.PNG)|*.PNG|";
	CString csDIB="DIB Files(*.DIB)|*.DIB|";
	CString csPBM="PBM Files(*.PBM)|*.PBM|";
	CString csPGM="PGM Files(*.PGM)|*.PGM|";
	CString csPPM="PPM Files(*.PPM)|*.PPM|";
	CString csSR ="SR  Files(*.SR) |*.SR|";
	CString csRAS="RAS Files(*.RAS)|*.RAS||";

    CString csFilter=csBMP+csJPG+csTIF+csPNG+csDIB
					 +csPBM+csPGM+csPPM+csSR+csRAS;

	CString name[]={"","bmp","jpg","tif","png","dib",
		               "pbm","pgm","ppm","sr", "ras",""};

	CString strFileName;
	CString strExtension;
 
	CFileDialog FileDlg(false,NULL,NULL,OFN_HIDEREADONLY,csFilter);
	                                        //  文件存盘对话框
	if (FileDlg.DoModal()==IDOK ) {         //  选择了文件名
 		strFileName = FileDlg.m_ofn.lpstrFile;
		if (FileDlg.m_ofn.nFileExtension == 0) {  //  无文件后缀
			strExtension = name[FileDlg.m_ofn.nFilterIndex];
			strFileName = strFileName + '.' + strExtension;
			                                //  加文件后缀
		}

		CCVMFCDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);

		pDoc->Save(strFileName,workImg);   //  当前画面存盘
	}
}

void CCVMFCView::OnSize(UINT nType, int cx, int cy) 
{
	CScrollView::OnSize(nType, cx, cy);
	
	if (workImg) {                          //  刷新窗口画面
 		CSize  sizeTotal;
 		sizeTotal = CSize(workImg->width,workImg->height);
		SetScrollSizes(MM_TEXT, sizeTotal);   //  设置滚动条
	}
}

//---------------------------------------------------------
//  视频采集

void CCVMFCView::OnUpdateStartCapture(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateOpenAviFile(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateCaptureImage(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable(m_CaptFlag==1);
}

void CCVMFCView::OnUpdateAverageImage(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable(m_CaptFlag==1);
}

void CCVMFCView::OnUpdateViewContinue(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable(m_CaptFlag==2);
}

void CCVMFCView::OnUpdateCapAbort(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag)&&(m_ImageType!=-3));
}
 
void CCVMFCView::OnUpdateSetParameter(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}

//---------------------------------------------------------
//
//  m_CaptFlag  视频状态标志  0 -- 关闭， 1 -- 开启， 2 -- 冻结 
//
 
void CCVMFCView::OnStartCapture()           //  启动视频
{
	BOOL  bl;

 	if (workImg) {
 		CCVMFCDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		cvReleaseImage(&pDoc->pImg);
		pDoc->m_Display=0;

		CClientDC dc(this);
		dc.PatBlt(0,0,1024,768,WHITENESS);  //  清除画面
	}

	bl=StartCapture();                      //  启动视频
	if (!bl) {
 		AfxMessageBox("本机没有安装摄像头！");
		return;
	}
	else if (bl==-1) {
		if (frameSetW>640) {
			frameSetW=640;     frameSetH=480;
			bl=StartCapture();
			if (bl==-1) {
				AfxMessageBox("无法打开摄像头");
				return;
			}
		}
	}

	if (workImg) {
		cvReleaseImage(&workImg);
	}
	workImg =cvCreateImage(cvSize(frameW,frameH), IPL_DEPTH_8U, 3);
	if (saveImg) {
		cvReleaseImage(&saveImg);
	}
	m_dibFlag=1;
   	
 	SetTimer(ID_TIMER,67,NULL);             //  每秒采样 15 次
	m_CaptFlag=1;                           //  视频状态标志初始化
}

void CCVMFCView::OnOpenAviFile() 
{
	BOOL  bl;

	CString csFilter="AVI Files(*.AVI)|*.AVI||";
	CString strFileName;
  
	CFileDialog FileDlg(true,NULL,NULL,OFN_HIDEREADONLY,csFilter);
	                                        //  文件存盘对话框
	if (FileDlg.DoModal()==IDOK ) {         //  选择了文件名
 		strFileName = FileDlg.m_ofn.lpstrFile;
		if (FileDlg.m_ofn.nFileExtension == 0) {  //  无文件后缀
			strFileName = strFileName + ".avi";
			                                //  加文件后缀
		}
	}

	if (workImg) {
 		CCVMFCDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (pDoc->pImg) {
			cvReleaseImage(&pDoc->pImg);
		}
		pDoc->m_Display=0;

		CClientDC dc(this);
		dc.PatBlt(0,0,1024,768,WHITENESS);  //  清除画面
	}

	bl=OpenAviFile(strFileName);            //  打开视频文件
	if (!bl) {
		AfxMessageBox("无法打开视频文件");
		return;
	}

	if (workImg) {
		cvReleaseImage(&workImg);
	}
	workImg =cvCreateImage(cvSize(frameW,frameH), IPL_DEPTH_8U, 3);
	if (saveImg) {
		cvReleaseImage(&saveImg);
	}
	m_dibFlag=1;
   	
	SetTimer(ID_TIMER,67,NULL);             //  每秒采样 15 次
	m_CaptFlag=1;                           //  视频状态标志初始化
}

void CCVMFCView::OnCaptureImage()           //  视频冻结
{
	BOOL bl=LoadImageFrame(workImg,1);      //  读出视频图像
	if (bl) {
 		imageClone(workImg,&saveImg);       //  保存为备份图像

		KillTimer(ID_TIMER);                //  关定时器
		m_ImageType=m_SaveFlag=workImg->nChannels;
		m_CaptFlag = 2;                     //  修改视频状态标志
		Invalidate(false);
	}
}

void CCVMFCView::OnAverageImage() 
{
	StartAverage();
}

void CCVMFCView::OnViewContinue()           //  视频解冻
{
	SetTimer(ID_TIMER,67,NULL);             //  每秒采样 15 次
	m_CaptFlag=1;                           //  恢复视频状态
}

void CCVMFCView::OnCapAbort()               //  关闭视频
{
	CCVMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	IplImage *p;

	AbortCapture(workImg);                  //  关闭视频
	if (saveImg) p=saveImg;                 //  已有冻结图像
	else p=workImg;
 	imageClone(p,&pDoc->pImg);              //  保存为原始图像
  
	KillTimer(ID_TIMER);                    //  关定时器
	pDoc->m_Display=0;
	m_CaptFlag=0;                           //  清视频状态标志
	Invalidate(false);
}

void CCVMFCView::OnSetParameter() 
{
	BOOL  bl;

	bl=SetParameter();
	if (bl==0) {
 		AfxMessageBox("本机没有安装摄像头！");
	}
	else {
		if ((frameSetW != frameW) ||
			(frameSetH != frameH)) {
			captSetFlag=1;
		}
	}
}

void CCVMFCView::OnTimer(UINT nIDEvent)     //  定时器响应
{
	int  bl=LoadImageFrame(workImg,0);      //  读出视频图像

	if (bl==0) {
 		OnCapAbort();                       //  关闭视频
	}
	else if (bl==1) {
  		Invalidate(false);                  //  刷新画面
	}
	else if (bl==2) {
		KillTimer(ID_TIMER);                //  关定时器

		AverageImage(workImg);              //  取出平均值
 		imageClone(workImg,&saveImg);       //  保存为备份图像

		m_ImageType=m_SaveFlag=workImg->nChannels;
		m_CaptFlag = 2;                     //  修改视频状态标志
		Invalidate(false);
	}
 
	CScrollView::OnTimer(nIDEvent);
}

//---------------------------------------------------------
//  OpenCV图像处理

//---------------------------------------------------------
//  点处理

void CCVMFCView::OnUpdateColorToGray(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType>1));
}

void CCVMFCView::OnUpdateImageInvert(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateFlipV(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateFlipH(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateFlip(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateRotation30(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateWarpAffine(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateWarpPerspect(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateImageHistogram(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateImageAdjust(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateHistEqualize(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnColorToGray()            //  图像彩色变灰阶   
{
	IplImage* pImage;
	IplImage* pImg8u = NULL;
 
	pImage = workImg;                       //  待处理图像换名

    //  建立辅助位图
 	pImg8u = cvCreateImage(cvGetSize(pImage),IPL_DEPTH_8U,1);

 	cvCvtColor(pImage,pImg8u,CV_BGR2GRAY);  //  彩色变灰阶

	m_dibFlag=imageReplace(pImg8u,&workImg);  //  输出处理结果
 
 	imageClone(workImg,&saveImg);           //  保存当前位图
     
	m_SaveFlag=m_ImageType=1;               //  设置灰阶位图标志
	Invalidate();
}

void CCVMFCView::OnImageInvert()            //  图像反相
{
	cvNot(workImg,workImg);                 //  像素反相
 	Invalidate();
}

void CCVMFCView::OnFlipV() 
{
 	cvFlip(workImg);                        //  垂直镜像 cvFlip(in,0,0) 
	Invalidate();
}

void CCVMFCView::OnFlipH() 
{
 	cvFlip(workImg,0,1);                    //  水平镜像
 	Invalidate();
}

void CCVMFCView::OnFlip() 
{
  	cvFlip(workImg,0,-1);                   //  180 度旋转
 	Invalidate();
}

void CCVMFCView::OnRotation30()             //  30 度旋转
{   //  根据《基于OpenCV的计算机视觉技术实现》程序 6-7 改编

 	int angle = 30;                         //  旋转 30 度
	int opt = 0;                            //  1: 加缩放   0: 仅旋转
	double factor;                          //  缩放因子
    IplImage *pImage;
    IplImage *pImgRotation = NULL;

	pImage = workImg;
	pImgRotation = cvCloneImage(workImg);

	angle=-angle;

	//  创建 M 矩阵
	float m[6];
	//      Matrix m looks like:
	//      [ m0  m1  m2 ] ----> [ a11  a12  b1 ]
	//      [ m3  m4  m5 ] ----> [ a21  a22  b2 ]

	CvMat M = cvMat(2,3,CV_32F,m);
	int w = workImg->width;
	int h = workImg->height;

	if (opt) factor = (cos(angle*CV_PI/180.)+1.0)*2;
	else factor = 1;

	m[0] = (float)(factor*cos(-angle*CV_PI/180.));
	m[1] = (float)(factor*sin(-angle*CV_PI/180.));
	m[3] = -m[1];
	m[4] =  m[0];
	//  将旋转中心移至图像中心
	m[2] = w*0.5f;
	m[5] = h*0.5f;

//---------------------------------------------------------
	//  dst(x,y) = A * src(x,y) + b
	cvZero(pImgRotation);
	cvGetQuadrangleSubPix(pImage,pImgRotation,&M);
//---------------------------------------------------------

	cvNamedWindow("Rotation Image");
 	cvFlip(pImgRotation);
	cvShowImage("Rotation Image",pImgRotation);

    cvReleaseImage( &pImgRotation );
    cvWaitKey(0);

    cvDestroyWindow("Rotation Image");
}

void CCVMFCView::OnWarpAffine()             //  仿射变换
{                         //  根据《学习OpenCV》例 6-2 改编
	CvPoint2D32f srcTri[3], dstTri[3];
	CvMat* rot_mat  = cvCreateMat(2,3,CV_32FC1);
	CvMat* warp_mat = cvCreateMat(2,3,CV_32FC1);
	IplImage *src=0, *dst=0;

	src = cvCloneImage(workImg);
	cvFlip(src);
	dst = cvCloneImage(src);
	dst->origin = src->origin;
	cvZero(dst);

	//COMPUTE WARP MATRIX
	srcTri[0].x = 0;                          //src Top left
	srcTri[0].y = 0;
	srcTri[1].x = (float) src->width - 1;     //src Top right
	srcTri[1].y = 0;
	srcTri[2].x = 0;                          //src Bottom left
	srcTri[2].y = (float) src->height - 1;
	//- - - - - - - - - - - - - - -//
	dstTri[0].x = (float)(src->width*0.0);    //dst Top left
	dstTri[0].y = (float)(src->height*0.33);
	dstTri[1].x = (float)(src->width*0.85);   //dst Top right
	dstTri[1].y = (float)(src->height*0.25);
	dstTri[2].x = (float)(src->width*0.15);   //dst Bottom left
	dstTri[2].y = (float)(src->height*0.7);
	cvGetAffineTransform(srcTri,dstTri,warp_mat);
	cvWarpAffine(src,dst,warp_mat);
	cvCopy(dst,src);

	//COMPUTE ROTATION MATRIX
	CvPoint2D32f center = cvPoint2D32f(src->width/2,src->height/2);
	double angle = -50.0;
	double scale = 0.6;
	cv2DRotationMatrix(center,angle,scale,rot_mat);
	cvWarpAffine(src,dst,rot_mat);

	//DO THE TRANSFORM:
	cvNamedWindow( "Affine_Transform", 1 );
    cvShowImage( "Affine_Transform", dst );

	m_ImageType=-3;
    cvWaitKey();

    cvDestroyWindow( "Affine_Transform" );
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	cvReleaseMat(&rot_mat);
	cvReleaseMat(&warp_mat);

	m_ImageType=imageType(workImg);
}

void CCVMFCView::OnWarpPerspect()           //  透视变换
{                         //  根据《学习OpenCV》例 6-3 改编
	CvPoint2D32f srcQuad[4], dstQuad[4];
	CvMat* warp_matrix = cvCreateMat(3,3,CV_32FC1);
	IplImage *src=0, *dst=0;

	src = cvCloneImage(workImg);
	cvFlip(src);
	dst = cvCloneImage(src);
	dst->origin = src->origin;
	cvZero(dst);

	srcQuad[0].x = 0;                         //src Top left
	srcQuad[0].y = 0;
	srcQuad[1].x = (float) src->width - 1;    //src Top right
	srcQuad[1].y = 0;
	srcQuad[2].x = 0;                         //src Bottom left
	srcQuad[2].y = (float) src->height - 1;
	srcQuad[3].x = (float) src->width - 1;    //src Bot right
	srcQuad[3].y = (float) src->height - 1;
      //- - - - - - - - - - - - - -//
	dstQuad[0].x = (float)(src->width*0.05);  //dst Top left
	dstQuad[0].y = (float)(src->height*0.33);
	dstQuad[1].x = (float)(src->width*0.9);   //dst Top right
	dstQuad[1].y = (float)(src->height*0.25);
	dstQuad[2].x = (float)(src->width*0.2);   //dst Bottom left
	dstQuad[2].y = (float)(src->height*0.7);      
	dstQuad[3].x = (float)(src->width*0.8);   //dst Bot right
	dstQuad[3].y = (float)(src->height*0.9);

	cvGetPerspectiveTransform(srcQuad,dstQuad,warp_matrix);
	cvWarpPerspective(src,dst,warp_matrix);

	cvNamedWindow( "Perspective_Warp", 1 );
    cvShowImage( "Perspective_Warp", dst );

	m_ImageType=-3;
    cvWaitKey();

    cvDestroyWindow( "Perspective_Warp" );
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	cvReleaseMat(&warp_matrix);

	m_ImageType=imageType(workImg);
}

//-------------------------------------
//  亮度变换
//  根据《OpenCV教程(基础篇)》例 5-10 改编

/*
  src and dst are grayscale, 8-bit images;
  Default input value: 
           [low, high] = [0,1];  X-Direction
           [bottom, top] = [0,1]; Y-Direction
           gamma ;
  if adjust successfully, return 0, otherwise, return non-zero.
*/
int ImageAdjust(IplImage* src, IplImage* dst, 
    	double low, double high,   // X方向：low and high are the intensities of src
    	double bottom, double top, // Y方向：mapped to bottom and top of dst
    	double gamma )
{
	if( 	low<0 && low>1 && high <0 && high>1&&
		bottom<0 && bottom>1 && top<0 && top>1 && low>high)
        return -1;
    double low2 = low*255;
    double high2 = high*255;
    double bottom2 = bottom*255;
    double top2 = top*255;
    double err_in = high2 - low2;
    double err_out = top2 - bottom2;

    int x,y;
    double val;

    // intensity transform
    for( y = 0; y < src->height; y++)
    {
        for (x = 0; x < src->width; x++)
        {
            val = ((uchar*)(src->imageData + src->widthStep*y))[x]; 
            val = pow((val - low2)/err_in, gamma) * err_out + bottom2;
            if(val>255) val=255; if(val<0) val=0; // Make sure src is in the range [low,high]
            ((uchar*)(dst->imageData + dst->widthStep*y))[x] = (uchar) val;
        }
    }
    return 0;
}

void CCVMFCView::OnImageAdjust()            //  亮度变换
{
    IplImage *src = 0, *dst = 0;
    
//    if( argc != 2 || (src=cvLoadImage(argv[1], 0)) == NULL)  // force to gray image
//        return -1;
    
	src = workImg;

//    cvNamedWindow( "src", 1 );
    cvNamedWindow( "result", 1 );
    
    // Image adjust
    dst = cvCloneImage(src);
    // 输入参数 [0,0.5] 和 [0.5,1], gamma=1
	if( ImageAdjust( src, dst, 0, 0.5, 0.5, 1, 1)!=0) return;
    
//    cvShowImage( "src", src );
	cvFlip(dst);
    cvShowImage( "result", dst );
    cvWaitKey(0);

//    cvDestroyWindow("src");
    cvDestroyWindow("result");
//    cvReleaseImage( &src );
//    cvReleaseImage( &dst );

	cvFlip(dst);
	m_dibFlag=imageReplace(dst,&workImg);
  	
	Invalidate();
}

void CCVMFCView::OnImageHistogram()         //  灰阶图像直方图
{                //  根据《OpenCV教程(基础篇)》例 5-11 改编

    IplImage *src;
    IplImage *histimg = 0;
    CvHistogram *hist = 0;
    
    int hdims = 256;     // 划分HIST的个数，越高越精确
    float hranges_arr[] = {0,255};
    float* hranges = hranges_arr;
    int bin_w;  
    float max_val;
    int i;
    
	src = workImg;
    
    cvNamedWindow( "Histogram", 0 );
     
    hist = cvCreateHist( 1, &hdims, CV_HIST_ARRAY, &hranges, 1 );  // 计算直方图
    histimg = cvCreateImage( cvSize(320,200), 8, 3 );
    cvZero( histimg );
    cvCalcHist( &src, hist, 0, 0 ); // 计算直方图
    cvGetMinMaxHistValue( hist, 0, &max_val, 0, 0 );  // 只找最大值
	cvConvertScale( hist->bins, hist->bins, 
		max_val ? 255. / max_val : 0., 0 ); // 缩放 bin 到区间 [0,255] 
    cvZero( histimg );
    bin_w = histimg->width / hdims;  // hdims: 条的个数，则 bin_w 为条的宽度
    
    // 画直方图
    for( i = 0; i < hdims; i++ )
    {
        double val = ( cvGetReal1D(hist->bins,i)*histimg->height/255 );
        CvScalar color = CV_RGB(255,255,0); //(hsv2rgb(i*180.f/hdims);
        cvRectangle( histimg, cvPoint(i*bin_w,histimg->height),
            cvPoint((i+1)*bin_w,(int)(histimg->height - val)),
            color, 1, 8, 0 );
    }
    
    cvShowImage( "Histogram", histimg );

    cvReleaseImage( &histimg );
    cvReleaseHist ( &hist );
    cvWaitKey(0);

    cvDestroyWindow("Histogram");
}

//-------------------------------------
//  直方图均衡化
//  根据《OpenCV教程(基础篇)》例 5-13 改编

#define HDIM    256    // bin of HIST, default = 256

void CCVMFCView::OnHistEqualize()           //  直方图均衡化
{

    IplImage *src = 0, *dst = 0;
    CvHistogram *hist = 0;
    
    int n = HDIM;     
    double nn[HDIM];
    uchar T[HDIM];
    CvMat *T_mat;
    
    int x;
    int sum = 0; // sum of pixels of the source image 图像中象素点的总和
    double val = 0;
    
//    if( argc != 2 || (src=cvLoadImage(argv[1], 0)) == NULL)  // force to gray image
//        return -1;

	src = workImg;
    
//    cvNamedWindow( "source", 1 );
    cvNamedWindow( "result", 1 );
    
    // 计算直方图
    hist = cvCreateHist( 1, &n, CV_HIST_ARRAY, 0, 1 );  
    cvCalcHist( &src, hist, 0, 0 ); 
    
    // Create Accumulative Distribute Function of histgram
    val = 0;
    for ( x = 0; x < n; x++)
    {
        val = val + cvGetReal1D (hist->bins, x);
        nn[x] = val;
    }

    // 归一化直方图
    sum = src->height * src->width;
    for( x = 0; x < n; x++ )
    {
        T[x] = (uchar) (255 * nn[x] / sum); // range is [0,255]
    }

    // Using look-up table to perform intensity transform for source image 
    dst = cvCloneImage( src );
    T_mat = cvCreateMatHeader( 1, 256, CV_8UC1 );
    cvSetData( T_mat, T, 0 );    
    // 直接调用内部函数完成 look-up-table 的过程
    cvLUT( src, dst, T_mat ); 

//    cvShowImage( "source", src );
	cvFlip(dst);
    cvShowImage( "result", dst );

    cvReleaseHist ( &hist );
    cvWaitKey(0);

//    cvDestroyWindow("source");
    cvDestroyWindow("result");
//    cvReleaseImage( &src );
//    cvReleaseImage( &dst );

	cvFlip(dst);
	m_dibFlag=imageReplace(dst,&workImg);
  	
	Invalidate();
}

//---------------------------------------------------------
//  邻域处理

void CCVMFCView::OnUpdateBlurSmooth(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateGaussSmooth(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateMedianSmooth(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateSobel(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateLaplace(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnBlurSmooth()             //  邻域平均
{
	IplImage* in;
 
	in = workImg;
 
	IplImage* out = cvCreateImage(cvGetSize(in),
		IPL_DEPTH_8U,workImg->nChannels); 

	cvSmooth(in,out,CV_BLUR,3,workImg->nChannels);  //  简单平均

	m_dibFlag=imageReplace(out,&workImg); 

	Invalidate();
}

void CCVMFCView::OnGaussSmooth()            //  Gauss 滤波
{                         //  根据《学习OpenCV》例 2-4 改编
	IplImage* in;
 
	in = workImg;
 
	IplImage* out = cvCreateImage(cvGetSize(in),
		IPL_DEPTH_8U,workImg->nChannels);   //  建立辅助位图

	cvSmooth(in,out,CV_GAUSSIAN,3,workImg->nChannels);  //  Gauss 平滑

	m_dibFlag=imageReplace(out,&workImg);   //  输出处理结果

	Invalidate();
}

void CCVMFCView::OnMedianSmooth()           //  中值滤波
{
	IplImage* in;
 
	in = workImg;
 
	IplImage* out = cvCreateImage(cvGetSize(in),
		IPL_DEPTH_8U,workImg->nChannels); 

	cvSmooth(in,out,CV_MEDIAN,3,workImg->nChannels);  //  中值滤波

	m_dibFlag=imageReplace(out,&workImg);

	Invalidate();
}

void CCVMFCView::OnSobel()                  //  Sobel 边缘检测
{   //  根据《基于OpenCV的计算机视觉技术实现》程序 6-1 改编

	IplImage* pImage;
	IplImage* pImgSobel = NULL;
	IplImage* pImgPlanes[3] = {0,0,0};
	int   i;
 
	pImage = workImg;
 
	pImgSobel= cvCreateImage(cvGetSize(pImage),
						IPL_DEPTH_16S,1);   //  建立工作位图

	if (workImg->nChannels==1) {            //  单通道图像处理
		cvSobel(pImage,pImgSobel,1,1,3);
		cvConvertScaleAbs(pImgSobel,pImage, 1, 0 );
	}
	else {                                  //  三通道图像处理
		for (i=0;i<3;i++) {
			pImgPlanes[i] = cvCreateImage(cvGetSize(pImage),
						IPL_DEPTH_8U,1);    //  建立分量位图
		}
 
		cvCvtPixToPlane(pImage,pImgPlanes[0],
				pImgPlanes[1],pImgPlanes[2],0);  //  取出各分量

		for (i=0;i<3;i++) {                 //  各分量单独处理
			cvSobel(pImgPlanes[i],pImgSobel,1,1,3);
			cvConvertScaleAbs(pImgSobel,pImgPlanes[i], 1, 0 );
		}

		cvCvtPlaneToPix(pImgPlanes[0],pImgPlanes[1],
				pImgPlanes[2],0,pImage);    //  由分量组装成彩色图像

		for (i=0;i<3;i++) {
			cvReleaseImage(&pImgPlanes[i]);  //  释放分量位图
		}
	}
	cvReleaseImage(&pImgSobel);             //  释放工作位图

	Invalidate();
}

void CCVMFCView::OnLaplace()                //  Laplace 边缘检测
{                                           //  程序结构同 Sobel
	IplImage* pImage;
	IplImage* pImgLaplace = NULL;
	IplImage* pImgPlanes[3] = {0,0,0};
	int   i;
 
	pImage = workImg;
 
	pImgLaplace= cvCreateImage(cvGetSize(pImage),
						IPL_DEPTH_16S,1);

	if (workImg->nChannels==1) {
		cvLaplace(pImage,pImgLaplace,3);
		cvConvertScaleAbs(pImgLaplace,pImage, 1, 0 );
	}
	else {
		for (i=0;i<3;i++) {
			pImgPlanes[i] = cvCreateImage(cvGetSize(pImage),
						IPL_DEPTH_8U,1);
		}
 
		cvCvtPixToPlane(pImage,pImgPlanes[0],
				pImgPlanes[1],pImgPlanes[2],0);

		for (i=0;i<3;i++) {
			cvLaplace(pImgPlanes[i],pImgLaplace,3);
			cvConvertScaleAbs(pImgLaplace,pImgPlanes[i], 1, 0 );
		}

		cvCvtPlaneToPix(pImgPlanes[0],pImgPlanes[1],
				pImgPlanes[2],0,pImage);

		for (i=0;i<3;i++) {
			cvReleaseImage(&pImgPlanes[i]);
		}
	}
	cvReleaseImage(&pImgLaplace);

	Invalidate();
}

//---------------------------------------------------------
//  二值图像处理

void CCVMFCView::OnUpdateThresholding1(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateThresholding2(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateBasicGlobalThreshold(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateAdaptiveThreshold(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateContourTrack(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}


void CCVMFCView::OnUpdateDistance(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}

void CCVMFCView::OnUpdateConvexHull(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateConvexHull2(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateAreaConvexHull(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}

void CCVMFCView::OnUpdateConvexityDefects(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}

void CCVMFCView::OnUpdateMinAreaRect2(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateAreaRect(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}

void CCVMFCView::OnUpdateMinAreaRect(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}

void CCVMFCView::OnUpdateApproxPoly(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}
 
char *threWin="Threshold Window";
IplImage *threImage0 = 0;
IplImage *threImage  = 0;
int  Threshold       = 128;

void onThreChange(int pos)
{
	cvThreshold(threImage,threImage0,Threshold,
				255,CV_THRESH_BINARY);
	cvShowImage( threWin, threImage0 );
}

void CCVMFCView::OnThresholding1() 
{
  	threImage  = cvCloneImage(workImg);
	cvFlip(threImage);
   	threImage0 = cvCloneImage(threImage);
  
    cvNamedWindow(threWin, 0);
	cvResizeWindow(threWin, 300, 320);

    cvCreateTrackbar( "Thresh", threWin, &Threshold, 255, onThreChange );
	onThreChange(0);
 	
	cvWaitKey(0);

	cvReleaseImage(&threImage);
    cvDestroyWindow(threWin);

	cvFlip(threImage0);
	m_dibFlag=imageReplace(threImage0,&workImg);
  	
	m_ImageType=-1;
	Invalidate();
}
 
void onThreChange2(int pos)
{
	cvThreshold(threImage,threImage0,Threshold,
				255,CV_THRESH_BINARY);
}

void CCVMFCView::OnThresholding2() 
{
	int   flag=0,thre=0;

  	threImage  = cvCloneImage(workImg);
	cvFlip(threImage);
   	threImage0 = cvCloneImage(threImage);
  
    cvNamedWindow(threWin, 0);
	cvResizeWindow(threWin, 300, 320);

    cvCreateTrackbar( "Thresh", threWin, &Threshold, 255, onThreChange2 );
	cvShowImage( threWin, threImage );
	onThreChange2(0);
 	
	m_ImageType=-3;
	for (;;) {
		if (cvWaitKey(40)==27) break;

 		if (flag==0) {
			free(m_lpBmi);
			m_lpBmi=CtreateMapInfo(workImg,1);
			flag=1;
		}
		if (Threshold != thre) {
			cvCopy(threImage0,workImg);
 			cvFlip(workImg);

			CClientDC dc(this);
			StretchDIBits(dc.m_hDC,         //  刷新视图窗口
				0,0,workImg->width,workImg->height,  
				0,0,workImg->width,workImg->height,
				workImg->imageData,m_lpBmi,DIB_RGB_COLORS,SRCCOPY);
			thre = Threshold;
		}
	}

	cvReleaseImage(&threImage);
	cvReleaseImage(&threImage0);
    cvDestroyWindow(threWin);
   	
	m_ImageType=-1;
	Invalidate();
}

void CCVMFCView::OnBasicGlobalThreshold()   //  基本全局阈值法二值化
{
	int  pg[256],i,thre;

	for (i=0;i<256;i++) pg[i]=0;
	for (i=0;i<workImg->imageSize;i++)      //  直方图统计
		pg[(BYTE)workImg->imageData[i]]++;

	thre=BasicGlobalThreshold(pg,0,256);    //  确定阈值

	cvThreshold(workImg,workImg,thre,255,CV_THRESH_BINARY);  //  二值化

	m_ImageType=-1;
 	Invalidate();
}

void CCVMFCView::OnAdaptiveThreshold()      //  自适应阈值
{
 	cvAdaptiveThreshold(workImg,workImg,255,
			CV_ADAPTIVE_THRESH_GAUSSIAN_C,
			CV_THRESH_BINARY_INV,3,5);

	m_ImageType=-1;
 	Invalidate();
}

//-------------------------------------
//  点集最小区域
//  根据 OpenCV 系统软件程序实例 minarea.c 改编
 
void CCVMFCView::OnMinAreaRect2() 
{
    IplImage* img = cvCreateImage( cvSize( 500, 500 ), 8, 3 );
 
    cvNamedWindow( "rect & circle", 1 );
        
	m_ImageType=-3;
    for(;;)
    {
        char key;
        int i, count = rand()%100 + 1;
        CvPoint pt0, pt;
        CvBox2D box;
        CvPoint2D32f box_vtx[4];
        CvPoint2D32f center;
        CvPoint icenter;
        float radius;

        CvPoint* points = (CvPoint*)malloc( count * sizeof(points[0]));
        CvMat pointMat = cvMat( 1, count, CV_32SC2, points );

        for( i = 0; i < count; i++ )
        {
            pt0.x = rand() % (img->width/2) + img->width/4;
            pt0.y = rand() % (img->height/2) + img->height/4;
            points[i] = pt0;
        }
        box = cvMinAreaRect2( &pointMat, 0 );
        cvMinEnclosingCircle( &pointMat, &center, &radius );

        cvBoxPoints( box, box_vtx );
        cvZero( img );
        for( i = 0; i < count; i++ )
        {
            pt0 = points[i];

            cvCircle( img, pt0, 2, CV_RGB( 255, 0, 0 ), CV_FILLED, CV_AA, 0 );
        }

        pt0.x = cvRound(box_vtx[3].x);
        pt0.y = cvRound(box_vtx[3].y);
        for( i = 0; i < 4; i++ )
        {
            pt.x = cvRound(box_vtx[i].x);
            pt.y = cvRound(box_vtx[i].y);
            cvLine(img, pt0, pt, CV_RGB(0, 255, 0), 1, CV_AA, 0);
            pt0 = pt;
        }
        icenter.x = cvRound(center.x);
        icenter.y = cvRound(center.y);
        cvCircle( img, icenter, cvRound(radius), CV_RGB(255, 255, 0), 1, CV_AA, 0 );

        cvShowImage( "rect & circle", img );

        key = (char) cvWaitKey(0);
        if( key == 27 || key == 'q' || key == 'Q' ) // 'ESC'
            break;

        free( points );
	}
    
    cvDestroyWindow( "rect & circle" );

	m_ImageType=0;
}

void CCVMFCView::OnAreaRect()               //  外接矩形 (单连通)
{
	IplImage *image  = 0;
	IplImage *image2 = 0;

 	image = cvCloneImage( workImg );        //  建立工作位图
	cvFlip(image);

 	image2=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,3);
	cvCvtColor(image,image2,CV_GRAY2BGR);

	cvThreshold(image,image,128,255,CV_THRESH_BINARY);  //  二值化

	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* contours = 0;

	cvFindContours(image,storage,&contours,sizeof(CvContour),
			CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);   //  轮廓跟踪

	CvSeq* contourn = contours;

	int n=0;


	for (n=0; contourn != 0; contourn = contourn->h_next,n++) {
	}                                       //  检查边界数
	if ((!contours)||(n>1)) {
		cvReleaseMemStorage(&storage);
  		cvReleaseImage(&image2);
 		AfxMessageBox("请选择单连通区域！");
		return;
	}
 	int  length = contours->total;
	if (length<10) {
		cvReleaseMemStorage(&storage);
  		cvReleaseImage(&image2);
		return;
	}
 
	CvPoint* point = new CvPoint[length];
	CvSeqReader  reader;
	CvPoint pt = cvPoint(0,0);
 
	cvStartReadSeq(contours, &reader);      //  取出边界点
	for (int i = 0; i < length; i++) {
		CV_READ_SEQ_ELEM(pt, reader);
		point[i]=pt;
	}

    CvRect  rect;
	CvPoint pt1,pt2;
    
    rect = cvBoundingRect( contours, 0 );   //  生成外接矩形

 	pt1.x =rect.x;
	pt1.y =rect.y;
 	pt2.x =rect.x + rect.width -1;
	pt2.y =rect.y + rect.height-1;

	pt.x  =(pt1.x+pt2.x+1)/2;
	pt.y  =(pt1.y+pt2.y+1)/2;

 	cvCircle(image2, pt,  2, CV_RGB( 0, 255, 0 ), CV_FILLED );
	cvRectangle(image2,cvPoint(pt1.x,pt1.y),
			 cvPoint(pt2.x,pt2.y),CV_RGB(0,255,0),1,8,0);

	for (int i = 0; i < length; i++) {          //  绘制原来边界
		int j = (i+1)%length;
		cvLine(image2,point[i],point[j],CV_RGB(255,0,0),1,8,0);
	}
 	
	cvReleaseMemStorage(&storage);          //  释放资源
	delete [] point;
 	cvReleaseImage(&image);

	cvFlip(image2);
	m_dibFlag=imageReplace(image2,&workImg);
  	
	m_ImageType=-2;
	Invalidate();
}

void CCVMFCView::OnMinAreaRect()            //  最小面积矩形 (单连通)
{
	IplImage *image  = 0;
	IplImage *image2 = 0;

 	image = cvCloneImage( workImg );        //  建立工作位图
	cvFlip(image);

 	image2=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,3);
	cvCvtColor(image,image2,CV_GRAY2BGR);

	cvThreshold(image,image,128,255,CV_THRESH_BINARY);  //  二值化

	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* contours = 0;

	cvFindContours(image,storage,&contours,sizeof(CvContour),
			CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);   //  轮廓跟踪

	CvSeq* contourn = contours;
	int n=0;
	for (n=0; contourn != 0; contourn = contourn->h_next,n++) {
	}                                       //  检查边界数
	if ((!contours)||(n>1)) {
		cvReleaseMemStorage(&storage);
  		cvReleaseImage(&image2);
 		AfxMessageBox("请选择单连通区域！");
		return;
	}
 	int  length = contours->total;
	if (length<10) {
		cvReleaseMemStorage(&storage);
  		cvReleaseImage(&image2);
		return;
	}
 
	CvPoint* point = new CvPoint[length];
	CvSeqReader  reader;
	CvPoint pt = cvPoint(0,0);
 
	cvStartReadSeq(contours, &reader);      //  取出边界点
	for (int i = 0; i < length; i++) {
		CV_READ_SEQ_ELEM(pt, reader);
		point[i]=pt;
	}

    CvBox2D box2d;
	CvPoint pt1,pt2,pt3,pt4;
	double  dx,dy,alpha,beta,r,x0,y0,x1,y1,x2,y2;
  
    box2d = cvMinAreaRect2( contours, 0 );  //  生成最小面积矩形

	x0 = box2d.center.x;                    //  中心位置
	y0 = box2d.center.y;
	alpha = -box2d.angle*CV_PI/180;         //  角度转换成弧度
 	dx = box2d.size.height/2;               //  宽度之半(长边、第一条边)
 	dy = box2d.size.width/2;                //  高度之半
    
	pt = cvPoint((int) (x0+0.5),(int) (y0+0.5));  //  四舍五入
	beta  = atan(dy/dx);
	r  = sqrt(dx*dx+dy*dy);
	x1 = r*cos(alpha+beta);
	y1 = r*sin(alpha+beta);
	x2 = r*cos(alpha-beta);
	y2 = r*sin(alpha-beta);

	pt1.x =(int) ( x0 + x1 + 0.5 );         //  计算四个角点坐标
	pt1.y =(int) ( y0 + y1 + 0.5 );
	pt2.x =(int) ( x0 + x2 + 0.5 );
	pt2.y =(int) ( y0 + y2 + 0.5 );
	pt3.x =(int) ( x0 - x1 + 0.5 );
	pt3.y =(int) ( y0 - y1 + 0.5 );
	pt4.x =(int) ( x0 - x2 + 0.5 );
	pt4.y =(int) ( y0 - y2 + 0.5 );
 
	cvCircle(image2, pt,  2, CV_RGB( 0, 255, 0 ), CV_FILLED );
	cvLine(image2,pt1,pt2,CV_RGB(0,255,0),1,8,0);
	cvLine(image2,pt2,pt3,CV_RGB(0,255,0),1,8,0);
	cvLine(image2,pt3,pt4,CV_RGB(0,255,0),1,8,0);
	cvLine(image2,pt4,pt1,CV_RGB(0,255,0),1,8,0);
 
	int i = 0;
	for (i = 0; i < length; i++) {          //  绘制原来边界
		int j = (i+1)%length;
		cvLine(image2,point[i],point[j],CV_RGB(255,0,0),1,8,0);
	}
 	
	cvReleaseMemStorage(&storage);          //  释放资源
	delete [] point;
 	cvReleaseImage(&image);

	cvFlip(image2);
	m_dibFlag=imageReplace(image2,&workImg);
  	
	m_ImageType=-2;
	Invalidate();
}

void CCVMFCView::OnApproxPoly()             //  多边形逼近 (单连通)
{
	IplImage *image  = 0;
	IplImage *image2 = 0;

 	image = cvCloneImage( workImg );        //  建立工作位图
	cvFlip(image);

 	image2=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,3);
	cvCvtColor(image,image2,CV_GRAY2BGR);

	cvThreshold(image,image,128,255,CV_THRESH_BINARY);  //  二值化

	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* contours = 0;

	cvFindContours(image,storage,&contours,sizeof(CvContour),
			CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);   //  轮廓跟踪

	CvSeq* contourn = contours;
	int n=0;
	for (n=0; contourn != 0; contourn = contourn->h_next,n++) {
	}                                       //  检查边界数
	if ((!contours)||(n>1)) {
		cvReleaseMemStorage(&storage);
  		cvReleaseImage(&image2);
 		AfxMessageBox("请选择单连通区域！");
		return;
	}

	int  length = contours->total;
	if (length<100) {
		cvReleaseMemStorage(&storage);
  		cvReleaseImage(&image2);
		return;
	}
 
	CvPoint* point = new CvPoint[length];
	CvSeqReader  reader;
	CvPoint pt = cvPoint(0,0);
	CvSeq* contour2 = contours;

	cvStartReadSeq(contour2, &reader);      //  取出边界点
	for (int i = 0; i < length; i++) {
		CV_READ_SEQ_ELEM(pt, reader);
		point[i]=pt;
	}

	int i = 0;
	for (i = 0; i < length; i++) {          //  绘制原来边界
		int j = (i+1)%length;
		cvLine(image2,point[i],point[j],CV_RGB(255,0,0),1,8,0);
	}
	
    contour2 = cvApproxPoly( contours, sizeof(CvContour), storage,
                    CV_POLY_APPROX_DP, cvContourPerimeter(contours)*0.001, 0 );

	length = contour2->total;
	cvStartReadSeq(contour2, &reader);      //  取出边界点
	for (i = 0; i < length; i++) {
		CV_READ_SEQ_ELEM(pt, reader);
		point[i]=pt;
	}

	for (i = 0; i < length; i++) {          //  绘制逼近边界
		int j = (i+1)%length;
		cvLine(image2,point[i],point[j],CV_RGB(0,255,0),1,8,0);
	}
 	
	cvReleaseMemStorage(&storage);
 	delete [] point;
 	cvReleaseImage(&image);

	cvFlip(image2);
	m_dibFlag=imageReplace(image2,&workImg);
  	
	m_ImageType=-2;
	Invalidate();
}

//-------------------------------------
//  点集凸包
//  根据《OpenCV教程(基础篇)》例 5-18 改编
//  OpenCV 系统软件程序实例 convexhull.c
//  清除条件编译中的数组输入部分
 
void CCVMFCView::OnConvexHull2() 
{
    cvNamedWindow( "hull", 1 );
    IplImage* img = cvCreateImage( cvSize( 500, 500 ), 8, 3 );

    CvMemStorage* storage = cvCreateMemStorage();

	m_ImageType=-3;
	for(;;)
	{
        int i, count = rand()%100 + 1, hullcount;
        CvPoint pt0;

        CvSeq* ptseq = cvCreateSeq( CV_SEQ_KIND_GENERIC|CV_32SC2, sizeof(CvContour),
                                     sizeof(CvPoint), storage );
        CvSeq* hull;

        for( i = 0; i < count; i++ )
        {
            pt0.x = rand() % (img->width/2) + img->width/4;
            pt0.y = rand() % (img->height/2) + img->height/4;
            cvSeqPush( ptseq, &pt0 );
        }
        hull = cvConvexHull2( ptseq, 0, CV_CLOCKWISE, 0 );
        hullcount = hull->total;

        cvZero( img );
        for( i = 0; i < count; i++ )
        {
            pt0 = *CV_GET_SEQ_ELEM( CvPoint, ptseq, i );
            cvCircle( img, pt0, 3, CV_RGB( 255, 0, 0 ), CV_FILLED );
        }

        pt0 = **CV_GET_SEQ_ELEM( CvPoint*, hull, hullcount - 1 );

        for( i = 0; i < hullcount; i++ )
        {
            CvPoint pt = **CV_GET_SEQ_ELEM( CvPoint*, hull, i );
            cvLine( img, pt0, pt, CV_RGB( 0, 255, 0 ));
            pt0 = pt;
        }
 
        cvShowImage( "hull", img );

        int key = cvWaitKey(0);
        if( key == 27 ) // 'ESC'
            break;
	}

    cvClearMemStorage( storage );
    cvDestroyWindow("hull");

	m_ImageType=0;
}

void CCVMFCView::OnConvexHull()             //  点集凸包 (事件驱动)
{
    IplImage* img = cvCreateImage( cvSize( 500, 500 ), 8, 3 );

    CvMemStorage* storage = cvCreateMemStorage();

    int i, count = rand()%100 + 1, hullcount;
    CvPoint pt0;

    CvSeq* ptseq = cvCreateSeq( CV_SEQ_KIND_GENERIC|CV_32SC2, sizeof(CvContour),
                                     sizeof(CvPoint), storage );
    CvSeq* hull;

    for( i = 0; i < count; i++ )
    {
        pt0.x = rand() % (img->width/2) + img->width/4;
        pt0.y = rand() % (img->height/2) + img->height/4;
        cvSeqPush( ptseq, &pt0 );
    }
    hull = cvConvexHull2( ptseq, 0, CV_CLOCKWISE, 0 );
    hullcount = hull->total;

    cvZero( img );
    for( i = 0; i < count; i++ )
    {
        pt0 = *CV_GET_SEQ_ELEM( CvPoint, ptseq, i );
        cvCircle( img, pt0, 3, CV_RGB( 255, 0, 0 ), CV_FILLED );
    }

    pt0 = **CV_GET_SEQ_ELEM( CvPoint*, hull, hullcount - 1 );

    for( i = 0; i < hullcount; i++ )
    {
        CvPoint pt = **CV_GET_SEQ_ELEM( CvPoint*, hull, i );
        cvLine( img, pt0, pt, CV_RGB( 0, 255, 0 ));
        pt0 = pt;
    }

	cvClearMemStorage( storage );

	cvFlip(img);                            //  垂直镜像
	m_dibFlag=imageReplace(img,&workImg);   //  输出处理结果
 
	m_ImageType=0;
 	Invalidate();
}

void CCVMFCView::OnAreaConvexHull()         //  区域凸包 (单连通)
{
	IplImage *image  = 0;
	IplImage *image2 = 0;

 	image = cvCloneImage( workImg );        //  建立工作位图
//	cvFlip(image);

 	image2=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,3);
	cvCvtColor(image,image2,CV_GRAY2BGR);

	cvThreshold(image,image,128,255,CV_THRESH_BINARY);  //  二值化

	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* contours = 0;

	cvFindContours(image,storage,&contours,sizeof(CvContour),
			CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);   //  轮廓跟踪

	CvSeq* contourn = contours;
	int n=0;
	for (n=0; contourn != 0; contourn = contourn->h_next,n++) {
	}                                       //  检查边界数
	if ((!contours)||(n>1)) {
		cvReleaseMemStorage(&storage);
  		cvReleaseImage(&image2);
 		AfxMessageBox("请选择单连通区域！");
		return;
	}
 	int  length = contours->total;
	if (length<100) {
		cvReleaseMemStorage(&storage);
  		cvReleaseImage(&image2);
		return;
	}
 
	CvPoint* point = new CvPoint[length];
	CvSeqReader  reader;
	CvPoint pt = cvPoint(0,0);
	CvSeq* contour2 = contours;

    CvSeq* hull;
	int    hullcount;
    CvPoint pt0;

    hull = cvConvexHull2( contour2, 0, CV_CLOCKWISE, 0 );  //  生成凸包
    hullcount = hull->total;

    pt0 = **CV_GET_SEQ_ELEM( CvPoint*, hull, hullcount - 1 );
    for(int i = 0; i < hullcount; i++ ) {                  //  绘制凸包
        CvPoint pt = **CV_GET_SEQ_ELEM( CvPoint*, hull, i );
        cvLine( image2, pt0, pt, CV_RGB( 0, 255, 0 ), 2);
        pt0 = pt;
    }

	cvStartReadSeq(contour2, &reader);      //  取出边界点
	int i;
	for (i = 0; i < length; i++) {
		CV_READ_SEQ_ELEM(pt, reader);
		point[i]=pt;
	}

	for (i = 0; i < length; i++) {          //  绘制原来边界
		int j = (i+1)%length;
		cvLine(image2,point[i],point[j],CV_RGB(255,0,0),1,8,0);
	}
 	
	cvReleaseMemStorage(&storage);
	delete [] point;
 	cvReleaseImage(&image);

//	cvFlip(image2);
	m_dibFlag=imageReplace(image2,&workImg);
  	
	m_ImageType=-2;
	Invalidate();
}

void CCVMFCView::OnConvexityDefects()       //  生成凹差 (单连通)
{
	IplImage *image  = 0;
	IplImage *image2 = 0;
	int  n, i, j, k, length, hullcount, defectcount;
 
 	image = cvCloneImage( workImg );        //  建立工作位图
	cvFlip(image);

 	image2=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,3);
	cvCvtColor(image,image2,CV_GRAY2BGR);

	cvThreshold(image,image,128,255,CV_THRESH_BINARY);  //  二值化

	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* contours = 0;

	cvFindContours(image,storage,&contours,sizeof(CvContour),
			CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);   //  轮廓跟踪

	CvSeq* contourn = contours;
	for ( n=0; contourn != 0; contourn = contourn->h_next,n++) {
	}                                       //  检查边界数
	if ((!contours)||(n>1)) {
		cvReleaseMemStorage(&storage);
  		cvReleaseImage(&image2);
 		AfxMessageBox("请选择单连通区域！");
		return;
	}
 	length = contours->total;
	if (length<100) {
		cvReleaseMemStorage(&storage);
  		cvReleaseImage(&image2);
		return;
	}
 
	CvSeqReader  reader;
	CvPoint* point = new CvPoint[length];
	CvSeq* contour2 = contours;

	cvStartReadSeq(contour2, &reader);      //  取出边界点
	for ( i = 0; i < length; i++) {
 		CV_READ_SEQ_ELEM(point[i], reader);
	}
  	
    CvSeq* hull = 0;
  
    hull = cvConvexHull2( contour2, 0, CV_COUNTER_CLOCKWISE, 0 );  //  生成凸包
    hullcount = hull->total;

    CvSeq* defects = 0;
 
	defects = cvConvexityDefects( contour2, hull, 0);  //  生成凹差
    defectcount = defects->total;
 	CvConvexityDefect* defectArray = 
		new CvConvexityDefect[defectcount];

	CvPoint pts,pte;

	cvStartReadSeq( defects, &reader, 0);
    for( i = 0, j = 0, k = 1; i < defectcount; i++ ) {
        CV_READ_SEQ_ELEM( defectArray[i], reader );
		if (defectArray[i].depth>1) {       //  深度大于 1
			pts = *defectArray[i].start;    //  凹差起点
			pte = *defectArray[i].end;      //  凹差终点

			while((point[j%length].x != pts.x)||
				(point[j%length].y != pts.y)) j++;  //  边界上寻找凹差起点
 			do {
 				cvLine( image2, point[j%length], point[(j+1)%length],
					CV_RGB( VgaDefPal[k].rgbRed ,   //  连接凹差内边界
					VgaDefPal[k].rgbGreen , VgaDefPal[k].rgbBlue ), 2);
				j++;
			}
			while((point[j%length].x != pte.x)||    //  边界上寻找凹差终点
				(point[j%length].y != pte.y));

			cvLine( image2, pts, pte,       //  连接凹差起点终点
				CV_RGB( VgaDefPal[k].rgbRed , 
				VgaDefPal[k].rgbGreen , VgaDefPal[k].rgbBlue ), 2);
			k = NextColor( 1, k, 4 );       //  修改颜色值
		}
	}
  	
	cvReleaseMemStorage(&storage);
 	delete [] point;
 	delete [] defectArray;
 	cvReleaseImage(&image);

	cvFlip(image2);
	m_dibFlag=imageReplace(image2,&workImg);
  	
	m_ImageType=-2;
	Invalidate();
}

void CCVMFCView::OnContourTrack()           //  轮廓跟踪
{   //  根据《基于OpenCV的计算机视觉技术实现》程序 5-3 改编

 	int  mode = CV_RETR_CCOMP;
	int  contours_num = 0,color;
	CvScalar external_color;
	CvScalar hole_color;
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* contour = 0;
	IplImage* pImg;
	IplImage* pContourImg = NULL;
	CvFont  font;
	char  ch[20];

 	cvFlip(workImg);
 	pImg = workImg;
	pContourImg = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,3);
	cvZero(pContourImg);

	mode = CV_RETR_LIST;
//---------------------------------------------------------
	contours_num=cvFindContours(pImg,storage,&contour,  //  轮廓跟踪
		sizeof(CvContour),mode,CV_CHAIN_APPROX_NONE);
//---------------------------------------------------------

	color=2;
	int n=0;
	for (n=0; contour != 0; contour = contour->h_next,n++) {
//		external_color = CV_RGB(rand()&255,rand()&255,rand()&255);
//		hole_color = CV_RGB(rand()&255,rand()&255,rand()&255);
		external_color = CV_RGB(VgaDefPal[color].rgbRed,
			VgaDefPal[color].rgbGreen,VgaDefPal[color].rgbBlue);
		color=NextColor(2,color,4);         //  1 or 4
		hole_color = CV_RGB(192,192,192);
		cvDrawContours(pContourImg,contour,
				external_color,hole_color,1,1,8);
	}

	cvReleaseMemStorage(&storage);

	m_dibFlag=imageReplace(pContourImg,&workImg);  //  输出处理结果

	if ((n>2)&&(workImg->width>200)&&(workImg->height>150)) {
		cvInitFont(&font,CV_FONT_HERSHEY_COMPLEX,0.4,0.4,0,1,CV_AA);
		sprintf(ch,"%d",contours_num);
		cvPutText(workImg,"contours_num",cvPoint(30,40),&font,CV_RGB(255,255,255));
		cvPutText(workImg,ch,cvPoint(30,60),&font,CV_RGB(255,255,255));
	}

 	cvFlip(workImg);
 
	m_ImageType=-2;
 	Invalidate();
}

/*
void CCVMFCView::OnDistance()               //  距离变换
{                //  根据《OpenCV教程(基础篇)》例 5-16 改编

	IplImage* pImg;
	IplImage* dist = NULL;
	IplImage* dist32s = NULL;
   
	pImg = workImg;
	dist = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_32F,1);
	dist32s = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_32S,1);

    cvDistTransform(pImg,dist,CV_DIST_L2,5,NULL);

	cvConvertScale(dist,dist,5000.0,0);
	cvPow(dist,dist,0.5);
 
	cvConvertScale(dist,dist32s,1.0,0.5);
//	cvAndS(dist32s,cvScalarAll(255),dist32s,0);
 	cvConvertScale(dist32s,pImg,1,0);
 
	cvReleaseImage(&dist);
	cvReleaseImage(&dist32s);
  
	m_ImageType=1;
 	Invalidate();
}
*/

void CCVMFCView::OnDistance()               //  距离变换
{                                           //  用不同颜色作标记
	IplImage* pImg;
	IplImage* dist = NULL;
	IplImage* dist32s = NULL;
    
	pImg = workImg;                         //  输入位图换名

	dist = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_32F,1);
	dist32s = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_32S,1);

//---------------------------------------------------------
//  距离变换
    cvDistTransform(pImg,dist,CV_DIST_L2,5,NULL);

	cvConvertScale(dist,dist32s,1.0,0);     //  转变为整数

//---------------------------------------------------------
//  距离值转换成颜色标记
	int   i,j,k,*pi,*tab,startColor,max;
	BYTE  *pb;

	pi=(int*)  (dist32s->imageData);
	for (i=0,max=0;i<dist->imageSize/4;i++,pi++) {
		if (abs(*pi)>max) max=(abs(*pi));   //  寻找最大距离
	}
	max++;

	tab =(int*) malloc(max*sizeof(int));
	startColor=1;
	tab[0]=255;                             //  背景用白色
	tab[1]=startColor;
	for (i=2;i<max;i++) {                   //  生成颜色标记转换表
		tab[i]=NextColor(startColor,tab[i-1],4);    //  1 or 4
	}

	k=min(pImg->width,dist32s->width);
	for (i=0;i<pImg->height;i++) {
		pb=(BYTE*) (pImg->imageData+i*pImg->widthStep);
		pi=(int*)  (dist32s->imageData+i*dist32s->widthStep);
		for (j=0;j<k;j++) pb[j]=tab[pi[j]];  //  查表转换
	}
	free(tab);
//---------------------------------------------------------

	cvReleaseImage(&dist);
	cvReleaseImage(&dist32s);
  
	m_dibFlag  = 2;                         //  设置 VGA 默认调色板
	m_ImageType=-2;                         //  默认调色板
 	Invalidate();
}

//---------------------------------------------------------
//  形态学处理

void CCVMFCView::OnUpdateErosion(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(abs(m_ImageType)==1));
}

void CCVMFCView::OnUpdateDilation(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(abs(m_ImageType)==1));
}

void CCVMFCView::OnUpdateOpenning(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(abs(m_ImageType)==1));
}

void CCVMFCView::OnUpdateClosing(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(abs(m_ImageType)==1));
}

void CCVMFCView::OnUpdateGrads(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(abs(m_ImageType)==1));
}

void CCVMFCView::OnUpdateGrayTophat(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateGrayBlackhat(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

//  二值与灰值形态学处理
void CCVMFCView::OnErosion()                //  腐蚀
{
  	cvErode(workImg,workImg,0,1);
 	Invalidate();
}

void CCVMFCView::OnDilation()               //  膨胀
{
  	cvDilate(workImg,workImg,0,1);
 	Invalidate();
}

void CCVMFCView::OnOpenning()               //  开运算
{
   	cvErode(workImg,workImg,0,1);
  	cvDilate(workImg,workImg,0,1);
  	Invalidate();
}

void CCVMFCView::OnClosing()                //  闭运算
{
  	cvDilate(workImg,workImg,0,1);
  	cvErode(workImg,workImg,0,1);
  	Invalidate();
}
  
void CCVMFCView::OnGrads()                  //  形态学梯度
{
	IplImage* in;
	IplImage* temp = NULL;
	IplImage* out  = NULL;
 
	in = workImg;

	temp = cvCreateImage(cvGetSize(in),
		IPL_DEPTH_8U,workImg->nChannels);
	out  = cvCreateImage(cvGetSize(in),
		IPL_DEPTH_8U,workImg->nChannels);

	cvMorphologyEx(in,out,temp,0,CV_MOP_GRADIENT,1);
/*	
	temp=cvCloneImage(in);   //  此段程序与上面语句等价
	cvDilate(workImg,workImg,0,1);
  	cvErode(temp,temp,0,1);
	cvSub(workImg,temp,out,0);
*/
	m_dibFlag=imageReplace(out,&workImg);
   
	cvReleaseImage(&temp);
 
	Invalidate();
}

//  仅灰值形态学处理
void CCVMFCView::OnGrayTophat()             //  顶帽变换
{
	IplImage* in;
	IplImage* temp = NULL;
	IplImage* out  = NULL;
 
	in = workImg;

	temp = cvCreateImage(cvGetSize(in),
		IPL_DEPTH_8U,workImg->nChannels);
	out  = cvCreateImage(cvGetSize(in),
		IPL_DEPTH_8U,workImg->nChannels);

	cvMorphologyEx(in,out,temp,0,CV_MOP_TOPHAT,1);
/*
	temp=cvCloneImage(in);   //  此段程序与上面语句等价
   	cvErode(temp, temp,0,1);
  	cvDilate(temp,temp,0,1);
	cvSub(workImg,temp,out,0);
*/
	m_dibFlag=imageReplace(out,&workImg);
    
	cvReleaseImage(&temp);
 
	Invalidate();
}

void CCVMFCView::OnGrayBlackhat()           //  波谷检测 (黑顶帽变换)
{
	IplImage* in;
	IplImage* temp = NULL;
	IplImage* out  = NULL;
 
	in = workImg;

	temp = cvCreateImage(cvGetSize(in),
		IPL_DEPTH_8U,workImg->nChannels);
	out  = cvCreateImage(cvGetSize(in),
		IPL_DEPTH_8U,workImg->nChannels);

	cvMorphologyEx(in,out,temp,0,CV_MOP_BLACKHAT,1);
/*	
	temp=cvCloneImage(in);   //  此段程序与上面语句等价
	cvDilate(temp,temp,0,1);
  	cvErode(temp,temp,0,1);
	cvSub(temp,workImg,out,0);
*/
	m_dibFlag=imageReplace(out,&workImg);
	cvNot(workImg,workImg);
   
	cvReleaseImage(&temp);
 
	Invalidate();
}

//---------------------------------------------------------
//  综合处理

void CCVMFCView::OnUpdateImageShrink(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateRadialGrads(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType>2));
}

void CCVMFCView::OnUpdateCannyBorddetec(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&
		(m_ImageType)&&(m_ImageType>0));
}
 
void CCVMFCView::OnUpdateHoughLines(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&
		(m_ImageType)&&(m_ImageType>0));
}

void CCVMFCView::OnUpdateHoughCircle(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&
		(m_ImageType)&&(m_ImageType>0));
}

void CCVMFCView::OnUpdateSquaresTest(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&
		(m_ImageType)&&(m_ImageType>0));
}

void CCVMFCView::OnUpdateFloodFill(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdatePyrSegmentation(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateFitEllipse(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType>0));
}

void CCVMFCView::OnUpdateSnake(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateWatershed(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateCornersTest(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType>0));
}

void CCVMFCView::OnUpdateClusters(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateSeqPartition(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateRotationTrack(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateFaceDetect(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

//-------------------------------------
//  图像缩半
//  根据《学习OpenCV》例 2-5 改编

IplImage* doPyrDown(IplImage* in, int filter=IPL_GAUSSIAN_5x5)
{                                           //  位图缩小一倍
	if (in->width%2) in->width++;
	IplImage* out = cvCreateImage(cvSize(in->width/2,
			in->height/2),in->depth,in->nChannels);
	cvPyrDown(in,out);                      //  位图缩小
	return(out);
}

void CCVMFCView::OnImageShrink()            //  图像缩半
{
	IplImage* in;
	IplImage* out = 0;
 
	in = workImg;
	if ((in->nChannels==3)&&                //  长或宽非偶数的真彩色图像
			((in->width%2)||(in->height%2))) {
		out = cvCreateImage(cvSize((in->width+1)/2,
			(in->height+1)/2),in->depth,in->nChannels);
		ImageDwindle(in,out,2,in->nChannels);
	}
	else 
 		out = doPyrDown(in);                //  图像缩小

	if (out)
		m_dibFlag=imageReplace(out,&workImg);   //  输出处理结果
	Invalidate();
}

void CCVMFCView::OnRadialGrads()            //  径向梯度变换 
{   //  根据《基于OpenCV的计算机视觉技术实现》程序 1-1 改编

	CvPoint center;
	double  scale = -3;
	IplImage* image;
 
	image = workImg;

	center = cvPoint(image->width/2,image->height/2);

	for (int i=0; i<image->height; i++) {
		for (int j=0; j<image->width; j++) {
			double dx=(double)(j-center.x)/center.x;
			double dy=(double)(i-center.y)/center.y;
			double weight=exp((dx*dx+dy*dy)*scale);
			uchar *ptr = &CV_IMAGE_ELEM(image,uchar,i,j*3);
			ptr[0]=cvRound(ptr[0]*weight);
			ptr[1]=cvRound(ptr[1]*weight);
			ptr[2]=cvRound(ptr[2]*weight);
		}
	}
 
	Invalidate();
}

void CCVMFCView::OnCannyBorddetec()         //  Canny 边缘检测
{                         //  根据《学习OpenCV》例 2-6 改编
    //  定义工作位图
	IplImage* pImg8u = NULL;
	IplImage* pImg8uSmooth = NULL;
	IplImage* pImgCanny = NULL;
 
	//**  输入待处理图像  **                //  修改部分 1

	if (workImg->nChannels==3) {
 		pImg8u=cvCreateImage(cvGetSize(workImg),IPL_DEPTH_8U,1);
		cvCvtColor(workImg,pImg8u,CV_BGR2GRAY);
		imageReplace(pImg8u,&workImg);
	}
 	pImg8u = workImg;

    //  建立辅助位图
	pImg8uSmooth=cvCreateImage(cvGetSize(pImg8u),IPL_DEPTH_8U,1);
	pImgCanny   =cvCreateImage(cvGetSize(pImg8u),IPL_DEPTH_8U,1);

	//  图像处理
 	cvSmooth(pImg8u,pImg8uSmooth,CV_GAUSSIAN,3,0,0);
	cvCanny(pImg8uSmooth,pImgCanny,100,200,3);

 	//  释放位图
	cvReleaseImage(&pImg8uSmooth);
  
	//**  输出处理结果  **                  //  修改部分 2
	m_dibFlag=imageReplace(pImgCanny,&workImg);
  	
	//**  设置标志及刷新窗口  **            //  修改部分 3
	m_ImageType=1;
	Invalidate();
}

//-------------------------------------
//  Hough 变换 (直线)
//  根据 OpenCV 系统软件程序实例 houghlines.c 改编

void CCVMFCView::OnHoughLines() 
{
    IplImage* src = 0;
    IplImage* dst = 0;
    IplImage* color_dst = 0;
    CvMemStorage* storage = cvCreateMemStorage(0);
    CvSeq* lines = 0;
    int i;

	if (workImg->nChannels==3) {
 		src = cvCreateImage(cvGetSize(workImg), IPL_DEPTH_8U, 1);
		cvCvtColor(workImg, src, CV_BGR2GRAY);
	}
	else {
        src = cvCloneImage( workImg );
	}
	cvFlip(src);
     
    dst = cvCreateImage( cvGetSize(src), 8, 1 );
    color_dst = cvCreateImage( cvGetSize(src), 8, 3 );
    
    cvCanny( src, dst, 50, 200, 3 );
    cvCvtColor( dst, color_dst, CV_GRAY2BGR );

    lines = cvHoughLines2( dst, storage, CV_HOUGH_PROBABILISTIC, 1, CV_PI/180, 50, 50, 10 );
    for( i = 0; i < lines->total; i++ )
    {
        CvPoint* line = (CvPoint*)cvGetSeqElem(lines,i);
        cvLine( color_dst, line[0], line[1], CV_RGB(255,0,0), 3, CV_AA, 0 );
    }

    cvNamedWindow( "Hough", 1 );
    cvShowImage( "Hough", color_dst );

    cvWaitKey(0);

    cvReleaseMemStorage(&storage );
    cvReleaseImage( &src );
    cvReleaseImage( &dst );
    cvReleaseImage( &color_dst );
    cvDestroyWindow( "Hough" );
}

//-------------------------------------
//  Hough 变换 (圆)
//  根据《基于OpenCV的计算机视觉技术实现》程序6-6 改编

void CCVMFCView::OnHoughCircle() 
{
    IplImage* pImage = NULL;
    IplImage* pImg8U = NULL;
    CvMemStorage* storage = NULL;
    CvSeq* circles = NULL;

	if (workImg->nChannels==3) {
        pImage = cvCloneImage( workImg );
	}
	else {
 		pImage = cvCreateImage(cvGetSize(workImg), IPL_DEPTH_8U, 3);
		cvCvtColor(workImg, pImage, CV_GRAY2BGR);
	}
	cvFlip(pImage);
     
    pImg8U = cvCreateImage( cvGetSize(pImage), 8, 1 );
	cvCvtColor(pImage, pImg8U, CV_BGR2GRAY);
    cvSmooth( pImg8U, pImg8U, CV_GAUSSIAN, 7, 7 );
 
	storage = cvCreateMemStorage(0);

    circles = cvHoughCircles( pImg8U, storage, CV_HOUGH_GRADIENT,
					2, pImg8U->height/10, 100, 55 );

    int i;
    for( i = 0; i < circles->total; i++ )
    {
        float* p = (float*)cvGetSeqElem(circles,i);
        cvCircle( pImage, cvPoint(cvRound(p[0]), cvRound(p[1])), 
					cvRound(p[2]),CV_RGB(255,0,0), 1, CV_AA, 0 );
    }

    cvReleaseMemStorage( &storage );
    cvReleaseImage( &pImg8U );

	cvFlip(pImage);
	m_dibFlag=imageReplace( pImage, &workImg);
  	
	m_ImageType=-2;
	Invalidate();
}

//-------------------------------------
//  平行四边形检测
//  根据 OpenCV 系统软件程序实例 squares.c 改编

int thresh = 50;
IplImage* img = 0;
IplImage* img0 = 0;
CvMemStorage* storage = 0;
const char* wndname = "Square Detection Demo";

// helper function:
// finds a cosine of angle between vectors
// from pt0->pt1 and from pt0->pt2 
double angle( CvPoint* pt1, CvPoint* pt2, CvPoint* pt0 )
{
    double dx1 = pt1->x - pt0->x;
    double dy1 = pt1->y - pt0->y;
    double dx2 = pt2->x - pt0->x;
    double dy2 = pt2->y - pt0->y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

// returns sequence of squares detected on the image.
// the sequence is stored in the specified memory storage
CvSeq* findSquares4( IplImage* img, CvMemStorage* storage )
{
    CvSeq* contours;
    int i, c, l, N = 11;
    CvSize sz = cvSize( img->width & -2, img->height & -2 );
    IplImage* timg = cvCloneImage( img ); // make a copy of input image
    IplImage* gray = cvCreateImage( sz, 8, 1 ); 
    IplImage* pyr = cvCreateImage( cvSize(sz.width/2, sz.height/2), 8, 3 );
    IplImage* tgray;
    CvSeq* result;
    double s, t;
    // create empty sequence that will contain points -
    // 4 points per square (the square's vertices)
    CvSeq* squares = cvCreateSeq( 0, sizeof(CvSeq), sizeof(CvPoint), storage );
    
    // select the maximum ROI in the image
    // with the width and height divisible by 2
    cvSetImageROI( timg, cvRect( 0, 0, sz.width, sz.height ));
    
    // down-scale and upscale the image to filter out the noise
    cvPyrDown( timg, pyr, 7 );
    cvPyrUp( pyr, timg, 7 );
    tgray = cvCreateImage( sz, 8, 1 );
    
    // find squares in every color plane of the image
    for( c = 0; c < 3; c++ )
    {
        // extract the c-th color plane
        cvSetImageCOI( timg, c+1 );
        cvCopy( timg, tgray, 0 );
        
        // try several threshold levels
        for( l = 0; l < N; l++ )
        {
            // hack: use Canny instead of zero threshold level.
            // Canny helps to catch squares with gradient shading   
            if( l == 0 )
            {
                // apply Canny. Take the upper threshold from slider
                // and set the lower to 0 (which forces edges merging) 
                cvCanny( tgray, gray, 0, thresh, 5 );
                // dilate canny output to remove potential
                // holes between edge segments 
                cvDilate( gray, gray, 0, 1 );
            }
            else
            {
                // apply threshold if l!=0:
                //     tgray(x,y) = gray(x,y) < (l+1)*255/N ? 255 : 0
                cvThreshold( tgray, gray, (l+1)*255/N, 255, CV_THRESH_BINARY );
            }
            
            // find contours and store them all as a list
            cvFindContours( gray, storage, &contours, sizeof(CvContour),
                CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0) );
            
            // test each contour
            while( contours )
            {
                // approximate contour with accuracy proportional
                // to the contour perimeter
                result = cvApproxPoly( contours, sizeof(CvContour), storage,
                    CV_POLY_APPROX_DP, cvContourPerimeter(contours)*0.02, 0 );
                // square contours should have 4 vertices after approximation
                // relatively large area (to filter out noisy contours)
                // and be convex.
                // Note: absolute value of an area is used because
                // area may be positive or negative - in accordance with the
                // contour orientation
                if( result->total == 4 &&
                    fabs(cvContourArea(result,CV_WHOLE_SEQ)) > 1000 &&
                    cvCheckContourConvexity(result) )
                {
                    s = 0;
                    
                    for( i = 0; i < 5; i++ )
                    {
                        // find minimum angle between joint
                        // edges (maximum of cosine)
                        if( i >= 2 )
                        {
                            t = fabs(angle(
                            (CvPoint*)cvGetSeqElem( result, i ),
                            (CvPoint*)cvGetSeqElem( result, i-2 ),
                            (CvPoint*)cvGetSeqElem( result, i-1 )));
                            s = s > t ? s : t;
                        }
                    }
                    
                    // if cosines of all angles are small
                    // (all angles are ~90 degree) then write quandrange
                    // vertices to resultant sequence 
                    if( s < 0.3 )
                        for( i = 0; i < 4; i++ )
                            cvSeqPush( squares,
                                (CvPoint*)cvGetSeqElem( result, i ));
                }
                
                // take the next contour
                contours = contours->h_next;
            }
        }
    }
    
    // release all the temporary images
    cvReleaseImage( &gray );
    cvReleaseImage( &pyr );
    cvReleaseImage( &tgray );
    cvReleaseImage( &timg );
    
    return squares;
}

// the function draws all the squares in the image
void drawSquares( IplImage* img, CvSeq* squares )
{
    CvSeqReader reader;
    IplImage* cpy = cvCloneImage( img );
    int i;
    
    // initialize reader of the sequence
    cvStartReadSeq( squares, &reader, 0 );
    
    // read 4 sequence elements at a time (all vertices of a square)
    for( i = 0; i < squares->total; i += 4 )
    {
        CvPoint pt[4], *rect = pt;
        int count = 4;
        
        // read 4 vertices
        CV_READ_SEQ_ELEM( pt[0], reader );
        CV_READ_SEQ_ELEM( pt[1], reader );
        CV_READ_SEQ_ELEM( pt[2], reader );
        CV_READ_SEQ_ELEM( pt[3], reader );
        
        // draw the square as a closed polyline 
        cvPolyLine( cpy, &rect, &count, 1, 1, CV_RGB(0,255,0), 3, CV_AA, 0 );
    }
    
    // show the resultant image
    cvShowImage( wndname, cpy );
    cvReleaseImage( &cpy );
}

void CCVMFCView::OnSquaresTest()            //  平行四边形检测
{
    storage = cvCreateMemStorage(0);

	if (workImg->nChannels==1) {
 		img0 = cvCreateImage(cvGetSize(workImg), IPL_DEPTH_8U, 3);
		cvCvtColor(workImg, img0, CV_GRAY2BGR);
	}
	else {
        img0 = cvCloneImage( workImg );
	}
	cvFlip(img0);
    img = cvCloneImage( img0 );
        
    // create window and a trackbar (slider) with parent "image" and set callback
    // (the slider regulates upper threshold, passed to Canny edge detector) 
    cvNamedWindow( wndname, 1 );
        
    // find and draw the squares
    drawSquares( img, findSquares4( img, storage ) );
        
    // wait for key.
    // Also the function cvWaitKey takes care of event processing
    int c = cvWaitKey(0);
    // release both images
    cvReleaseImage( &img );
    cvReleaseImage( &img0 );
    // clear memory storage - reset free space position
    
    cvDestroyWindow( wndname );
}

//-------------------------------------
//  区域填充
//  根据《OpenCV教程(基础篇)》例 5-7 改编
//  OpenCV 系统软件程序实例 ffilldemo.c

IplImage* color_img0;
IplImage* mask;
IplImage* color_img;
IplImage* gray_img0 = NULL;
IplImage* gray_img = NULL;
int ffill_case = 1;
int lo_diff = 20, up_diff = 20;
int connectivity = 4;
int is_color = 1;
int is_mask = 0;
int new_mask_val = 255;

void on_mousef( int event, int x, int y, int flags, void* param )
{
    if( !color_img )
        return;

    switch( event )
    {
    case CV_EVENT_LBUTTONDOWN:
        {
            CvPoint seed = cvPoint(x,y);
            int lo = ffill_case == 0 ? 0 : lo_diff;
            int up = ffill_case == 0 ? 0 : up_diff;
            int flags = connectivity + (new_mask_val << 8) +
                        (ffill_case == 1 ? CV_FLOODFILL_FIXED_RANGE : 0);
            int b = rand() & 255, g = rand() & 255, r = rand() & 255;
            CvConnectedComp comp;

            if( is_mask )
                cvThreshold( mask, mask, 1, 128, CV_THRESH_BINARY );
            
            if( is_color )
            {
                CvScalar color = CV_RGB( r, g, b );
                cvFloodFill( color_img, seed, color, CV_RGB( lo, lo, lo ),
                             CV_RGB( up, up, up ), &comp, flags, is_mask ? mask : NULL );
                cvShowImage( "image", color_img );
            }
            else
            {
                CvScalar brightness = cvRealScalar((r*2 + g*7 + b + 5)/10);
                cvFloodFill( gray_img, seed, brightness, cvRealScalar(lo),
                             cvRealScalar(up), &comp, flags, is_mask ? mask : NULL );
                cvShowImage( "image", gray_img );
            }

            printf("%g pixels were repainted\n", comp.area );

            if( is_mask )
                cvShowImage( "mask", mask );
        }
        break;
    }
}

void CCVMFCView::OnFloodFill() 
{
//    char* filename = argc >= 2 ? argv[1] : (char*)"fruits.jpg";

//    if( (color_img0 = cvLoadImage(filename,1)) == 0 )
//        return 0;

	color_img0 = cvCloneImage(workImg);
	cvFlip(color_img0);

/*
    printf( "Hot keys: \n"
            "\tESC - quit the program\n"
            "\tc - switch color/grayscale mode\n"
            "\tm - switch mask mode\n"
            "\tr - restore the original image\n"
            "\ts - use null-range floodfill\n"
            "\tf - use gradient floodfill with fixed(absolute) range\n"
            "\tg - use gradient floodfill with floating(relative) range\n"
            "\t4 - use 4-connectivity mode\n"
            "\t8 - use 8-connectivity mode\n" );
*/ 
	
    color_img = cvCloneImage( color_img0 );
    gray_img0 = cvCreateImage( cvSize(color_img->width, color_img->height), 8, 1 );
    cvCvtColor( color_img, gray_img0, CV_BGR2GRAY );
    gray_img = cvCloneImage( gray_img0 );
    mask = cvCreateImage( cvSize(color_img->width + 2, color_img->height + 2), 8, 1 );

    cvNamedWindow( "image", 0 );
    cvCreateTrackbar( "lo_diff", "image", &lo_diff, 255, NULL );
    cvCreateTrackbar( "up_diff", "image", &up_diff, 255, NULL );

    cvSetMouseCallback( "image", on_mousef, 0 );

	m_ImageType=-3;
    for(;;)
    {
        int c;
        
        if( is_color )
            cvShowImage( "image", color_img );
        else
            cvShowImage( "image", gray_img );

        c = cvWaitKey(0);
        switch( (char) c )
        {
        case '\x1b':
            printf("Exiting ...\n");
            goto exit_main;
        case 'c':
            if( is_color )
            {
                printf("Grayscale mode is set\n");
                cvCvtColor( color_img, gray_img, CV_BGR2GRAY );
                is_color = 0;
            }
            else
            {
                printf("Color mode is set\n");
                cvCopy( color_img0, color_img, NULL );
                cvZero( mask );
                is_color = 1;
            }
            break;
        case 'm':
            if( is_mask )
            {
                cvDestroyWindow( "mask" );
                is_mask = 0;
            }
            else
            {
                cvNamedWindow( "mask", 0 );
                cvZero( mask );
                cvShowImage( "mask", mask );
                is_mask = 1;
            }
            break;
        case 'r':
            printf("Original image is restored\n");
            cvCopy( color_img0, color_img, NULL );
            cvCopy( gray_img0, gray_img, NULL );
            cvZero( mask );
            break;
        case 's':
            printf("Simple floodfill mode is set\n");
            ffill_case = 0;
            break;
        case 'f':
            printf("Fixed Range floodfill mode is set\n");
            ffill_case = 1;
            break;
        case 'g':
            printf("Gradient (floating range) floodfill mode is set\n");
            ffill_case = 2;
            break;
        case '4':
            printf("4-connectivity mode is set\n");
            connectivity = 4;
            break;
        case '8':
            printf("8-connectivity mode is set\n");
            connectivity = 8;
            break;
        }
    }

exit_main:

    cvDestroyWindow( "image" );
	if (is_mask)
		cvDestroyWindow( "mask" );
    cvReleaseImage( &gray_img );
    cvReleaseImage( &gray_img0 );
    cvReleaseImage( &color_img );
    cvReleaseImage( &color_img0 );
    cvReleaseImage( &mask );

	m_ImageType=imageType(workImg);
}

//-------------------------------------
//  金字塔法图像分割
//  根据《OpenCV教程(基础篇)》例 5-9 改编
//  OpenCV 系统软件程序实例 pyramid_segmentation.c

IplImage*  images[2] = { 0, 0 }, *images0 = 0, *images1 = 0;
CvSize size;

int  w0, h0,i;
int  threshold1, threshold2;
int  l,level = 4;
int sthreshold1, sthreshold2;
int  l_comp;
int block_size = 1000;
float  parameter;
double threshold;
double rezult, min_rezult;
CvFilter filter = CV_GAUSSIAN_5x5;
CvConnectedComp *cur_comp, min_comp;
CvSeq *comp;
//CvMemStorage *storage;

CvPoint pt1, pt2;

void ON_SEGMENT(int a)
{   
    cvPyrSegmentation(images0, images1, storage, &comp, 
                      level, threshold1+1, threshold2+1);

    /*l_comp = comp->total;

    i = 0;
    min_comp.value = cvScalarAll(0);
    while(i<l_comp)
    {
        cur_comp = (CvConnectedComp*)cvGetSeqElem ( comp, i );
        if(fabs(255- min_comp.value.val[0])>
           fabs(255- cur_comp->value.val[0]) &&
           fabs(min_comp.value.val[1])>
           fabs(cur_comp->value.val[1]) &&
           fabs(min_comp.value.val[2])>
           fabs(cur_comp->value.val[2]) )
           min_comp = *cur_comp;
        i++;
    }*/
    cvShowImage("Segmentation", images1);
}

void CCVMFCView::OnPyrSegmentation() 
{
//    char* filename = argc == 2 ? argv[1] : (char*)"fruits.jpg";
//        if( (images[0] = cvLoadImage( filename, 1)) == 0 )
//        return -1;

//    cvNamedWindow("Source", 1);
//    cvShowImage("Source", images[0]);

	images[0] = cvCloneImage(workImg);
	cvFlip(images[0]);
 
    cvNamedWindow("Segmentation", 1);

    storage = cvCreateMemStorage ( block_size );

    images[0]->width &= -(1<<level);
    images[0]->height &= -(1<<level);

    images0 = cvCloneImage( images[0] );
    images1 = cvCloneImage( images[0] );
    // 对彩色图像进行分割
    l = 1;
    threshold1 =255;
    threshold2 =30;

    ON_SEGMENT(1);

	sthreshold1 = cvCreateTrackbar("Threshold1", "Segmentation", 
						&threshold1, 255, ON_SEGMENT);
	sthreshold2 = cvCreateTrackbar("Threshold2", "Segmentation",   
						&threshold2, 255,ON_SEGMENT);

    cvShowImage("Segmentation", images1);

    cvWaitKey(0);

    cvReleaseMemStorage(&storage );
    cvReleaseImage(&images[0]);
    cvReleaseImage(&images0);
    cvReleaseImage(&images1);

    cvDestroyWindow("Segmentation");
//    cvDestroyWindow("Source");
}

//-------------------------------------
//  椭圆曲线拟合
//  根据《OpenCV教程(基础篇)》例 5-17 改编
//  OpenCV 系统软件程序实例 fitellipse.c

int slider_pos = 110;

IplImage *image02 = 0, *image03 = 0, *image04 = 0;

// Define trackbar callback functon. This function find contours,
// draw it and approximate it by ellipses.
void process_image(int h)
{
    CvMemStorage* stor;
    CvSeq* cont;
    CvBox2D32f* box;
    CvPoint* PointArray;
    CvPoint2D32f* PointArray2D32f;
    
    // 创建动态结构序列
    stor = cvCreateMemStorage(0);
    cont = cvCreateSeq(CV_SEQ_ELTYPE_POINT, sizeof(CvSeq), sizeof(CvPoint) , stor);
    
    // 二值化图像.
    cvThreshold( image03, image02, slider_pos, 255, CV_THRESH_BINARY );
    
    // 寻找所有轮廓.
    cvFindContours( image02, stor, &cont, sizeof(CvContour), 
                    CV_RETR_LIST, CV_CHAIN_APPROX_NONE, cvPoint(0,0));
    
    // Clear images. IPL use.
    cvZero(image02);
    cvZero(image04);
    
    // 本循环绘制所有轮廓并用椭圆拟合.
    for(;cont;cont = cont->h_next)
    {   
        int i; // Indicator of cycle.
        int count = cont->total; // This is number point in contour
        CvPoint center;
        CvSize size;
        
        // Number point must be more than or equal to 6 (for cvFitEllipse_32f).        
        if( count < 6 )
            continue;
        
        // Alloc memory for contour point set.    
        PointArray = (CvPoint*)malloc( count*sizeof(CvPoint) );
        PointArray2D32f= (CvPoint2D32f*)malloc( count*sizeof(CvPoint2D32f) );
        
        // Alloc memory for ellipse data.
        box = (CvBox2D32f*)malloc(sizeof(CvBox2D32f));
        
        // Get contour point set.
        cvCvtSeqToArray(cont, PointArray, CV_WHOLE_SEQ);
        
        // Convert CvPoint set to CvBox2D32f set.
        for(i=0; i<count; i++)
        {
            PointArray2D32f[i].x = (float)PointArray[i].x;
            PointArray2D32f[i].y = (float)PointArray[i].y;
        }
        
        //拟合当前轮廓.
        cvFitEllipse(PointArray2D32f, count, box);
        
        // 绘制当前轮廓.
        cvDrawContours(image04,cont,CV_RGB(255,255,255),
					CV_RGB(255,255,255),0,1,8,cvPoint(0,0));
        
        // Convert ellipse data from float to integer representation.
        center.x = cvRound(box->center.x);
        center.y = cvRound(box->center.y);
        size.width = cvRound(box->size.width*0.5);
        size.height = cvRound(box->size.height*0.5);
        box->angle = -box->angle;
        
        // Draw ellipse.
        cvEllipse(image04, center, size,
                  box->angle, 0, 360,
                  CV_RGB(0,0,255), 1, CV_AA, 0);
        
        // Free memory.          
        free(PointArray);
        free(PointArray2D32f);
        free(box);
    }
    
    // Show image. HighGUI use.
	cvFlip(image04);
    cvShowImage( "Result", image04 );
}

void CCVMFCView::OnFitEllipse()             //  椭圆曲线拟合
{
//  const char* filename = argc == 2 ? argv[1] : (char*)"stuff.jpg";
    
    //  读入图像，强制为灰度图像
//  if( (image03 = cvLoadImage(filename, 0)) == 0 )
//      return -1;

	if (workImg->nChannels==1) image03=workImg;
	else {
 		image03=cvCreateImage(cvGetSize(workImg),IPL_DEPTH_8U,1);
		cvCvtColor(workImg,image03,CV_BGR2GRAY);
		imageReplace(image03,&workImg);
		m_dibFlag=1;                        //  workImg 类型改变设标志
	}

    // Create the destination images
    image02 = cvCloneImage( image03 );
    image04 = cvCloneImage( image03 );

    // Create windows.
//  cvNamedWindow("Source", 1);
    cvNamedWindow("Result", 1);

    // Show the image.
//  cvShowImage("Source", image03);

    // Create toolbars. HighGUI use.
    cvCreateTrackbar( "Threshold", "Result", &slider_pos, 255, process_image );

    process_image(0);

    // Wait for a key stroke; the same function arranges events processing                
	m_ImageType=-3;
    cvWaitKey(0);

    cvReleaseImage(&image02);
//  cvReleaseImage(&image03);

//  cvDestroyWindow("Source");
    cvDestroyWindow("Result");

	cvFlip(image04);
	m_dibFlag=imageReplace(image04,&workImg);
  	
	m_ImageType=-1;
	Invalidate();
}

//-------------------------------------
//  Snake 算法 
//  根据《基于OpenCV的计算机视觉技术实现》 13.7 节程序改编

char *theWin="Snake Window";
IplImage *image0 = 0;
IplImage *image1 = 0;
IplImage *image  = 0;
IplImage *image2 = 0;

int  Thresholdness = 80;
int  ialpha = 20;
int  ibeta  = 20;
int  igamma = 20;
   
void onChange(int pos)
{
	cvCopy(image0,image);                   //  恢复原始图像
	cvCopy(image1,image2);

	cvThreshold(image,image,Thresholdness,255,CV_THRESH_BINARY);  //  二值化

	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* contours = 0;

	cvFindContours(image,storage,&contours,sizeof(CvContour),
			CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);   //  轮廓跟踪

	if (!contours) return;
 	int  length = contours->total;
	if (length<10) return;
 
	CvPoint* point = new CvPoint[length];
	CvSeqReader  reader;
	CvPoint pt = cvPoint(0,0);
	CvSeq* contour2 = contours;

	cvStartReadSeq(contour2, &reader);      //  取出边界点
	for (int i = 0; i < length; i++) {
		CV_READ_SEQ_ELEM(pt, reader);
		point[i]=pt;
	}
	cvReleaseMemStorage(&storage);

	for (i = 0; i < length; i++) {          //  绘制原来边界
		int j = (i+1)%length;
		cvLine(image2,point[i],point[j],CV_RGB(255,0,0),1,8,0);
	}

	float alpha = ialpha/100.0f;
	float beta  = ibeta /100.0f;
	float gamma = igamma/100.0f;
	CvTermCriteria criteria;
	criteria.type = CV_TERMCRIT_ITER;
	criteria.max_iter = 1000;
	criteria.epsilon = 0.1;
    CvSize win;

    win.height = win.width = 3;
	
	cvSnakeImage(image, point, length, &alpha, &beta,
			&gamma, CV_VALUE, win, criteria, 0);  //  搜索新边界

	for (i = 0; i < length; i++) {          //  绘制新边界
		int j = (i+1)%length;
		cvLine(image2,point[i],point[j],CV_RGB(0,255,0),1,8,0);
	}

	delete [] point;
 
	cvShowImage( theWin, image2 );
}

void CCVMFCView::OnSnake()                  //  Snake 原理
{
	int  flag=0,thre=0;

  	image0 = cvCloneImage( workImg );       //  建立工作位图
	cvFlip(image0);
 	image =cvCreateImage(cvGetSize(image0),IPL_DEPTH_8U,1);
 	image1=cvCreateImage(cvGetSize(image0),IPL_DEPTH_8U,3);
	cvCvtColor(image0,image1,CV_GRAY2BGR);
 	image2=cvCreateImage(cvGetSize(image0),IPL_DEPTH_8U,3);
 
    cvNamedWindow(theWin, 0);
	cvResizeWindow(theWin, 400, 600);

    cvCreateTrackbar( "Thresh", theWin, &Thresholdness, 255, onChange );
    cvCreateTrackbar( "Alpha", theWin, &ialpha, 255, onChange );
    cvCreateTrackbar( "Beta", theWin, &ibeta, 255, onChange );
    cvCreateTrackbar( "Gamma", theWin, &igamma, 255, onChange );

	onChange(0);

	m_ImageType=-3;
	for (;;) {
		if (cvWaitKey(40)==27) break;

		if (flag==0) {
  			imageClone(image2,&workImg);
 			free(m_lpBmi);
			m_lpBmi=CtreateMapInfo(workImg,m_dibFlag);
			flag=1;
		}
		if (Threshold != thre) {
  			cvCopy(image2,workImg);
			cvFlip(workImg);

			CClientDC dc(this);
			StretchDIBits(dc.m_hDC,0,0,workImg->width,workImg->height,  //  刷新主窗口
				0,0,workImg->width,workImg->height,
				workImg->imageData,m_lpBmi,DIB_RGB_COLORS,SRCCOPY);
			thre = Thresholdness;
		}
	}

 	cvReleaseImage(&image);
 	cvReleaseImage(&image0);
 	cvReleaseImage(&image1);
    cvDestroyWindow(theWin);

	cvFlip(image2);
	m_dibFlag=imageReplace(image2,&workImg);
  	
	Invalidate();
}
 
//-------------------------------------
//  分水岭算法原理
//  根据 OpenCV 系统软件程序实例 watershed.cpp 改编

IplImage* marker_mask = 0;
IplImage* markers = 0;
//IplImage* img0 = 0, *img = 0, *img_gray = 0, *wshed = 0;
IplImage  *img_gray = 0, *wshed = 0;
CvPoint prev_pt = {-1,-1};

void on_mouse( int event, int x, int y, int flags, void* param )
{
    if( !img )
        return;

    if( event == CV_EVENT_LBUTTONUP || !(flags & CV_EVENT_FLAG_LBUTTON) )
        prev_pt = cvPoint(-1,-1);
    else if( event == CV_EVENT_LBUTTONDOWN )
        prev_pt = cvPoint(x,y);
    else if( event == CV_EVENT_MOUSEMOVE && (flags & CV_EVENT_FLAG_LBUTTON) )
    {
        CvPoint pt = cvPoint(x,y);
        if( prev_pt.x < 0 )
            prev_pt = pt;
        cvLine( marker_mask, prev_pt, pt, cvScalarAll(255), 5, 8, 0 );
        cvLine( img, prev_pt, pt, cvScalarAll(255), 5, 8, 0 );
        prev_pt = pt;
        cvShowImage( "image", img );
    }
}

void CCVMFCView::OnWatershed()              //  分水岭原理
{
	int   flag=0;
    CvRNG rng = cvRNG(-1);

	img0 = cvCloneImage( workImg );         //  建立工作位图
	cvFlip(img0);

    cvNamedWindow( "image", 1 );
//  cvNamedWindow( "watershed transform", 1 );

    img = cvCloneImage( img0 );
    img_gray = cvCloneImage( img0 );
    wshed = cvCloneImage( img0 );
    marker_mask = cvCreateImage( cvGetSize(img), 8, 1 );
    markers = cvCreateImage( cvGetSize(img), IPL_DEPTH_32S, 1 );
    cvCvtColor( img, marker_mask, CV_BGR2GRAY );
    cvCvtColor( marker_mask, img_gray, CV_GRAY2BGR );

    cvZero( marker_mask );
    cvZero( wshed );
    cvShowImage( "image", img );
//  cvShowImage( "watershed transform", wshed );
    cvSetMouseCallback( "image", on_mouse, 0 );

	m_ImageType=-3;
    for(;;)
    {
        int c = cvWaitKey(0);

        if( c == 27 ) {
			if (!flag) {                    //  未加标记
  				wshed = cvCloneImage( img0 );
			}
            break;
		}

        if( c == 'r' )
        {
            cvZero( marker_mask );
            cvCopy( img0, img );
            cvShowImage( "image", img );
        }

        if( c == 'w' || c == '\r' )
        {
			CvMemStorage* storage = cvCreateMemStorage(0);
			CvSeq* contours = 0;
			CvMat* color_tab;
			int i, j, comp_count = 0;
			//cvSaveImage( "wshed_mask.png", marker_mask );
			//marker_mask = cvLoadImage( "wshed_mask.png", 0 );
			cvFindContours( marker_mask, storage, &contours, sizeof(CvContour),
							CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );

			CvSeq* contourn = contours;
			int n=0;
			for (n=0; contourn != 0; contourn = contourn->h_next,n++) {
			}                               //  检查边界数
			if (n) {                        //  已作标记才进行处理             
				cvZero( markers );
				for( ; contours != 0; contours = contours->h_next, comp_count++ )
				{
					cvDrawContours( markers, contours, cvScalarAll(comp_count+1),
                            cvScalarAll(comp_count+1), -1, -1, 8, cvPoint(0,0) );
				}

				color_tab = cvCreateMat( 1, comp_count, CV_8UC3 );
				for( i = 0; i < comp_count; i++ )
				{
					uchar* ptr = color_tab->data.ptr + i*3;
					ptr[0] = (uchar)(cvRandInt(&rng)%180 + 50);
					ptr[1] = (uchar)(cvRandInt(&rng)%180 + 50);
					ptr[2] = (uchar)(cvRandInt(&rng)%180 + 50);
				}

				{
					double t = (double)cvGetTickCount();
					cvWatershed( img0, markers );  //  分水岭算法处理
					t = (double)cvGetTickCount() - t;
//					printf( "exec time = %gms\n", t/(cvGetTickFrequency()*1000.) );
				}

				// paint the watershed image
				for( i = 0; i < markers->height; i++ ) {
					for( j = 0; j < markers->width; j++ )
					{
						int idx = CV_IMAGE_ELEM( markers, int, i, j );
						uchar* dst = &CV_IMAGE_ELEM( wshed, uchar, i, j*3 );
						if( idx == -1 )
							dst[0] = dst[1] = dst[2] = (uchar)255;
						else if( idx <= 0 || idx > comp_count )
							dst[0] = dst[1] = dst[2] = (uchar)0; // should not get here
						else
						{
							uchar* ptr = color_tab->data.ptr + (idx-1)*3;
							dst[0] = ptr[0]; dst[1] = ptr[1]; dst[2] = ptr[2];
						}
					}
				}

				cvAddWeighted( wshed, 0.5, img_gray, 0.5, 0, wshed );  //  图像合成
//				cvShowImage( "watershed transform", wshed );
				cvReleaseMemStorage( &storage );
				cvReleaseMat( &color_tab );
			}
			else {                          //  未加标记
  				wshed = cvCloneImage( img0 );
			}
			cvCopy(wshed,workImg);
			cvFlip(workImg);

			CClientDC dc(this);
			StretchDIBits(dc.m_hDC,         //  刷新主窗口
				0,0,workImg->width,workImg->height,
				0,0,workImg->width,workImg->height,
				workImg->imageData,m_lpBmi,DIB_RGB_COLORS,SRCCOPY);
			flag=1;
		}
	}

	cvDestroyWindow( "image" );
	cvReleaseImage(&img0);
 	cvReleaseImage(&img);
 	cvReleaseImage(&img_gray);
 	cvReleaseImage(&marker_mask);
 	cvReleaseImage(&markers);
 
	cvFlip(wshed);
	m_dibFlag=imageReplace(wshed,&workImg);
  	
	Invalidate();
}

//-------------------------------------
//  角点检测 
//  根据《基于OpenCV的计算机视觉技术实现》 程序 12-1 改编

#define max_corners 200;                    //  限定的最大角点数

IplImage* srcImage  = 0;                    //  待处理的源图像
IplImage* ImageShow = 0;                    //  存储显示带角点的图像
IplImage* grayImage = 0;                    //  原始图像转换成的灰阶图像
IplImage* corners1  = 0;                    //  临时图像
IplImage* corners2  = 0;                    //  临时图像

int cornerCount0 = max_corners;
int cornerCount;                            //  实际测得角点数
int qualityLevel = 0;                       //  最小质量因子
int minDistance  = 15;                      //  角点最小距离
CvScalar color = CV_RGB(255,0,0);           //  绘图颜色
CvPoint2D32f corners[200];                  //  角点坐标
CvRect ROI_rect;                            //  测试范围
char   chek_area_state = 0;                 //  鼠标状态
 
void re_find_corners(int)                   //  滑动条响应函数
{
	int   i,x,y,xl,yu,xr,yd,k;
	int   radius = 5;
	int   thickness = 1;
	double quality_level = (double) qualityLevel / 100 + 0.02;
	double min_distance  = (double) minDistance;

	cornerCount=cornerCount0;               //  设置最大角点数
	cvGoodFeaturesToTrack(grayImage,        //  角点检测
					corners1,corners2,corners,&cornerCount,
					quality_level,min_distance,NULL);

	if (cornerCount>0) {                    //  测到角点
		xl=ROI_rect.x;     yu=ROI_rect.y;   //  设置初始测试范围
		xr=ROI_rect.x+ROI_rect.width;
		yd=ROI_rect.y+ROI_rect.height;
		cvCopy(srcImage,ImageShow);         //  恢复源图像
		for (i=0,k=0;i<cornerCount;i++) {
 			x=(int)corners[i].x;
			y=(int)corners[i].y;
			if ((xl<x)&&(x<xr)&&(yu<y)&&(y<yd)) {  //  范围检查
				corners[k].x=corners[i].x;  //  保存范围内角点
				corners[k].y=corners[i].y;
				k++;
			}
		}
 		cornerCount=k;                      //  范围内角点数
		cvCopy(srcImage,ImageShow);
		for (i=0;i<cornerCount;i++) {
 			x=(int)corners[i].x;
			y=(int)corners[i].y;
 			cvCircle(ImageShow,cvPoint(x,y),   //  角点处画圈
				radius,color,thickness,CV_AA,0);
		}
		cvRectangle(ImageShow,cvPoint(xl,yu),cvPoint(xr,yd),
			CV_RGB(0,255,0),thickness,CV_AA,0);  //  画矩形
		cvShowImage("image", ImageShow);    //  显示画圈图像
	}
}

void on_mouse2(int event,int x,int y,int flags,void* param)
{                                           //  鼠标响应函数
	int  thickness = 1;
	CvPoint point1,point2;

	if (event == CV_EVENT_LBUTTONDOWN) {    //  鼠标左键按下
		ROI_rect.x = x;                     //  记录检测窗口一角坐标
		ROI_rect.y = y;
		chek_area_state = 1;                //  设置状态标志
	}
	else if (chek_area_state && event == CV_EVENT_MOUSEMOVE) {  //  鼠标移动
 		cvCopy(srcImage,ImageShow);         //  恢复原始图像
		point1 = cvPoint(ROI_rect.x, ROI_rect.y);
		point2 = cvPoint(x,y);              //  当前坐标
		cvRectangle(ImageShow,point1,point2,CV_RGB(0,255,0),
				thickness,CV_AA,0);         //  画矩形
		cvShowImage("image", ImageShow);    //  显示检测结果
		cvWaitKey(20);                      //  延时
	}
	else if (chek_area_state && event == CV_EVENT_LBUTTONUP) {  //  鼠标左键抬起
		ROI_rect.width  = abs(x - ROI_rect.x);  //  记录检测窗口对角坐标
		ROI_rect.height = abs(y - ROI_rect.y);

   		re_find_corners(0);                 //  角点检测
		chek_area_state = 0;                //  恢复状态标志
		cvWaitKey(20); 
	}
}

void CCVMFCView::OnCornersTest()            //  角点检测
{
	if (workImg->nChannels>1) {             //  原图为真彩色图像
		srcImage = cvCloneImage(workImg);
	}
	else {                                  //  原图为灰阶图像
 		srcImage = cvCreateImage(cvGetSize(workImg),IPL_DEPTH_8U,3);
		cvCvtColor(workImg,srcImage,CV_GRAY2BGR);
	}
 	cvFlip(srcImage);

 	grayImage = cvCreateImage(cvGetSize(srcImage),IPL_DEPTH_8U,1);
	cvCvtColor(srcImage,grayImage,CV_BGR2GRAY);  //  转换为灰阶图像
	ImageShow = cvCloneImage(srcImage);

	ROI_rect.x =0;
	ROI_rect.y =0;
	ROI_rect.width  = grayImage->width;
	ROI_rect.height = grayImage->height;
  
	corners1 = cvCreateImage(cvGetSize(grayImage),IPL_DEPTH_32F,1);
	corners2 = cvCreateImage(cvGetSize(grayImage),IPL_DEPTH_32F,1);

	cvNamedWindow("image",0);               //  设置显示窗口
	cvResizeWindow("image",325,350);        //  改变窗口尺寸

	cvCreateTrackbar("minDistance", "image",  //  设置距离滑动条
		&minDistance, 200,re_find_corners);
	cvCreateTrackbar("qualityLevel","image",  //  设置质量滑动条
		&qualityLevel,100,re_find_corners);
  
	re_find_corners(0);                     //  角点检测

	cvSetMouseCallback("image",on_mouse2,0);  //  设置鼠标响应函数

	cvWaitKey(0);                           //  等待键输入

	cvDestroyWindow( "image" );             //  关闭窗口
 
	cvReleaseImage(&srcImage);              //  释放图像存储单元
	cvReleaseImage(&grayImage);
	cvReleaseImage(&corners1);
	cvReleaseImage(&corners2);

	cvFlip(ImageShow);
	m_dibFlag=imageReplace(ImageShow,&workImg);  //  输出检测结果
  	
	m_ImageType=-2;
	Invalidate();
}

//-------------------------------------
//  点集聚类
//  根据《OpenCV教程(基础篇)》例 4-6 改编
//  OpenCV 系统软件程序实例 kmeans.c

void CCVMFCView::OnClusters()               //  点集聚类
{
    #define MAX_CLUSTERS 5
    CvScalar color_tab[MAX_CLUSTERS];
    IplImage* img = cvCreateImage( cvSize( 500, 500 ), 8, 3 );
    CvRNG rng = cvRNG(-1);
    CvPoint ipt;

    color_tab[0] = CV_RGB(255,0,0);
    color_tab[1] = CV_RGB(0,255,0);
    color_tab[2] = CV_RGB(100,100,255);
    color_tab[3] = CV_RGB(255,0,255);
    color_tab[4] = CV_RGB(255,255,0);

    cvNamedWindow( "clusters", 1 );
        
	m_ImageType=-3;
    for(;;)
    {
        char key;
        int k, cluster_count = cvRandInt(&rng)%MAX_CLUSTERS + 1;
        int i, sample_count = cvRandInt(&rng)%1000 + 1;
        CvMat* points = cvCreateMat( sample_count, 1, CV_32FC2 );
        CvMat* clusters = cvCreateMat( sample_count, 1, CV_32SC1 );
        
        /* generate random sample from multigaussian distribution */
        for( k = 0; k < cluster_count; k++ )
        {
            CvPoint center;
            CvMat point_chunk;
            center.x = cvRandInt(&rng)%img->width;
            center.y = cvRandInt(&rng)%img->height;
            cvGetRows( points, &point_chunk, k*sample_count/cluster_count,
                       k == cluster_count - 1 ? sample_count :
                       (k+1)*sample_count/cluster_count, 1 );
                        
            cvRandArr( &rng, &point_chunk, CV_RAND_NORMAL,
                       cvScalar(center.x,center.y,0,0),
                       cvScalar(img->width*0.1,img->height*0.1,0,0));
        }

        /* shuffle samples */
        for( i = 0; i < sample_count/2; i++ )
        {
            CvPoint2D32f* pt1 = (CvPoint2D32f*)points->data.fl + cvRandInt(&rng)%sample_count;
            CvPoint2D32f* pt2 = (CvPoint2D32f*)points->data.fl + cvRandInt(&rng)%sample_count;
            CvPoint2D32f temp;
            CV_SWAP( *pt1, *pt2, temp );
        }

        cvKMeans2( points, cluster_count, clusters,
                   cvTermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 10, 1.0 ));

        cvZero( img );

        for( i = 0; i < sample_count; i++ )
        {
            int cluster_idx = clusters->data.i[i];
            ipt.x = (int)points->data.fl[i*2];
            ipt.y = (int)points->data.fl[i*2+1];
            cvCircle( img, ipt, 2, color_tab[cluster_idx], CV_FILLED, CV_AA, 0 );
        }

        cvReleaseMat( &points );
        cvReleaseMat( &clusters );

        cvShowImage( "clusters", img );

        key = (char) cvWaitKey(0);
        if( key == 27 || key == 'q' || key == 'Q' ) // 'ESC'
            break;
    }
    
    cvDestroyWindow( "clusters" );

	m_ImageType=0;
}

//-------------------------------------
//  分割二维点集
//  根据《OpenCV教程(基础篇)》例 4-7 改编

CvSeq* point_seq = 0;
IplImage* canvas = 0;
CvScalar* colors = 0;
int pos = 10;

int is_equal( const void* _a, const void* _b, void* userdata )
{
    CvPoint a = *(const CvPoint*)_a;
    CvPoint b = *(const CvPoint*)_b;
    double threshold = *(double*)userdata;
    return (double)(a.x - b.x)*(a.x - b.x) + (double)(a.y - b.y)*(a.y - b.y) <= threshold;
}

void on_trackSP( int pos )
{
    CvSeq* labels = 0;
    double threshold = pos*pos;
    int i, class_count = cvSeqPartition( point_seq, 0, &labels, is_equal, &threshold );
    printf("%4d classes\n", class_count );
    cvZero( canvas );

    for( i = 0; i < labels->total; i++ )
    {
        CvPoint pt = *(CvPoint*)cvGetSeqElem( point_seq, i );
        CvScalar color = colors[*(int*)cvGetSeqElem( labels, i )];
        cvCircle( canvas, pt, 1, color, -1 );
    }

    cvShowImage( "points", canvas );
}

void CCVMFCView::OnSeqPartition() 
{
    CvMemStorage* storage = cvCreateMemStorage(0);
    point_seq = cvCreateSeq( CV_32SC2, sizeof(CvSeq), sizeof(CvPoint), storage );
    CvRNG rng = cvRNG(0xffffffff);

    int width = 500, height = 500;
    int i, count = 1000;
    canvas = cvCreateImage( cvSize(width,height), 8, 3 );

    colors = (CvScalar*)cvAlloc( count*sizeof(colors[0]) );
    for( i = 0; i < count; i++ )
    {
        CvPoint pt;
        int icolor;
        pt.x = cvRandInt( &rng ) % width;
        pt.y = cvRandInt( &rng ) % height;
        cvSeqPush( point_seq, &pt );
        icolor = cvRandInt( &rng ) | 0x00404040;
        colors[i] = CV_RGB(icolor & 255, (icolor >> 8)&255, (icolor >> 16)&255);
    }

    cvNamedWindow( "points", 1 );
    cvCreateTrackbar( "threshold", "points", &pos, 50, on_trackSP );
    on_trackSP( pos );

	m_ImageType=-3;
    cvWaitKey(0);

    cvDestroyWindow( "points" );
	cvReleaseMemStorage( &storage );
    cvReleaseImage( &canvas );

	m_ImageType=0;
}

//-------------------------------------
//  旋转点跟踪
//  根据 OpenCV 系统软件程序实例 kalman.c 改编

void CCVMFCView::OnRotationTrack() 
{
    const float A[] = { 1, 1, 0, 1 };
    
    IplImage* img = cvCreateImage( cvSize(500,500), 8, 3 );
    CvKalman* kalman = cvCreateKalman( 2, 1, 0 );
    CvMat* state = cvCreateMat( 2, 1, CV_32FC1 ); /* (phi, delta_phi) */
    CvMat* process_noise = cvCreateMat( 2, 1, CV_32FC1 );
    CvMat* measurement = cvCreateMat( 1, 1, CV_32FC1 );
    CvRNG rng = cvRNG(-1);
    char code = -1;

    cvZero( measurement );
    cvNamedWindow( "Kalman", 1 );

	m_ImageType=-3;
    for(;;)
    {
        cvRandArr( &rng, state, CV_RAND_NORMAL, cvRealScalar(0), cvRealScalar(0.1) );
        
        memcpy( kalman->transition_matrix->data.fl, A, sizeof(A));
        cvSetIdentity( kalman->measurement_matrix, cvRealScalar(1) );
        cvSetIdentity( kalman->process_noise_cov, cvRealScalar(1e-5) );
        cvSetIdentity( kalman->measurement_noise_cov, cvRealScalar(1e-1) );
        cvSetIdentity( kalman->error_cov_post, cvRealScalar(1));
        cvRandArr( &rng, kalman->state_post, CV_RAND_NORMAL, cvRealScalar(0), cvRealScalar(0.1) );
        
        for(;;)
        {
            #define calc_point(angle)                                      \
                cvPoint( cvRound(img->width/2 + img->width/3*cos(angle)),  \
                         cvRound(img->height/2 - img->width/3*sin(angle))) 

            float state_angle = state->data.fl[0];
            CvPoint state_pt = calc_point(state_angle);
            
            const CvMat* prediction = cvKalmanPredict( kalman, 0 );
            float predict_angle = prediction->data.fl[0];
            CvPoint predict_pt = calc_point(predict_angle);
            float measurement_angle;
            CvPoint measurement_pt;

            cvRandArr( &rng, measurement, CV_RAND_NORMAL, cvRealScalar(0),
                       cvRealScalar(sqrt(kalman->measurement_noise_cov->data.fl[0])) );

            /* generate measurement */
            cvMatMulAdd( kalman->measurement_matrix, state, measurement, measurement );

            measurement_angle = measurement->data.fl[0];
            measurement_pt = calc_point(measurement_angle);
            
            /* plot points */
            #define draw_cross( center, color, d )                                 \
                cvLine( img, cvPoint( center.x - d, center.y - d ),                \
                             cvPoint( center.x + d, center.y + d ), color, 1, CV_AA, 0); \
                cvLine( img, cvPoint( center.x + d, center.y - d ),                \
                             cvPoint( center.x - d, center.y + d ), color, 1, CV_AA, 0 )

            cvZero( img );
            draw_cross( state_pt, CV_RGB(255,255,255), 3 );
            draw_cross( measurement_pt, CV_RGB(255,0,0), 3 );
            draw_cross( predict_pt, CV_RGB(0,255,0), 3 );
            cvLine( img, state_pt, measurement_pt, CV_RGB(255,0,0), 3, CV_AA, 0 );
            cvLine( img, state_pt, predict_pt, CV_RGB(255,255,0), 3, CV_AA, 0 );
            
            cvKalmanCorrect( kalman, measurement );

            cvRandArr( &rng, process_noise, CV_RAND_NORMAL, cvRealScalar(0),
                       cvRealScalar(sqrt(kalman->process_noise_cov->data.fl[0])));
            cvMatMulAdd( kalman->transition_matrix, state, process_noise, state );

            cvShowImage( "Kalman", img );
            code = (char) cvWaitKey( 100 );
            
            if( code > 0 )
                break;
        }
        if( code == 27 || code == 'q' || code == 'Q' )
            break;
    }
    
    cvDestroyWindow("Kalman");

	m_ImageType=0;
}

//-------------------------------------
//  人脸检测
//  根据 OpenCV 系统软件程序实例 facedetect.c 改编

CvMemStorage* storage1 = 0;
CvHaarClassifierCascade* cascade = 0;

void detect_and_draw( IplImage* img ,int flag)
{
    static CvScalar colors[] = 
    {
        {{0,0,255}},
        {{0,128,255}},
        {{0,255,255}},
        {{0,255,0}},
        {{255,128,0}},
        {{255,255,0}},
        {{255,0,0}},
        {{255,0,255}}
    };

    double scale = 1.3;
    IplImage* gray = cvCreateImage( cvSize(img->width,img->height), 8, 1 );
    IplImage* small_img = cvCreateImage( cvSize( cvRound (img->width/scale),
                         cvRound (img->height/scale)),
                     8, 1 );
    int i;

    cvCvtColor( img, gray, CV_BGR2GRAY );
    cvResize( gray, small_img, CV_INTER_LINEAR );
    cvEqualizeHist( small_img, small_img );
    cvClearMemStorage( storage1 );

    if( cascade )
    {
        double t = (double)cvGetTickCount();
        CvSeq* faces = cvHaarDetectObjects( small_img, cascade, storage1,
                                            1.1, 2, 0/*CV_HAAR_DO_CANNY_PRUNING*/,
                                            cvSize(30, 30) );
        t = (double)cvGetTickCount() - t;
        printf( "detection time = %gms\n", t/((double)cvGetTickFrequency()*1000.) );
        for( i = 0; i < (faces ? faces->total : 0); i++ )
        {
            CvRect* r = (CvRect*)cvGetSeqElem( faces, i );
            CvPoint center;
            int radius;
            center.x = cvRound((r->x + r->width*0.5)*scale);
            center.y = cvRound((r->y + r->height*0.5)*scale);
            radius = cvRound((r->width + r->height)*0.25*scale);
            cvCircle( img, center, radius, colors[i%8], 3, 8, 0 );
        }
    }

	if (flag==1)
		cvShowImage( "result", img );
    cvReleaseImage( &gray );
    cvReleaseImage( &small_img );
}

void CCVMFCView::OnFaceDetect()             //  人脸检测
{
	char cascade_name[] = "image\\haarcascade_frontalface_alt2.xml";
  
    cascade = (CvHaarClassifierCascade*)cvLoad( cascade_name, 0, 0, 0 );
    
    storage1 = cvCreateMemStorage(0);
    
	cvFlip(workImg);                        //  恢复原始图像
    detect_and_draw( workImg , 0);          //  人脸检测

	cvReleaseMemStorage(&storage1);
	cvReleaseHaarClassifierCascade( &cascade );
	cvFlip(workImg);                        //  因显示需要作镜像

	Invalidate();
}

//---------------------------------------------------------
//  视频处理

void CCVMFCView::OnUpdateDynamicBorderTest(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}
 
void CCVMFCView::OnUpdateOpticalFlowTrack(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateMotionDetect(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateCamShiftDemo(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateForegroundDetect(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateFaceDetect2(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}

//-------------------------------------
//  动态边缘检测
//  根据 OpenCV 系统软件程序实例 laplace.cpp 改编

void CCVMFCView::OnDynamicBorderTest()      //  动态边缘检测
{
    IplImage* laplace = 0;
    IplImage* colorlaplace = 0;
    IplImage* planes[3] = { 0, 0, 0 };
    CvCapture* capture = 0;
    
    capture = cvCaptureFromCAM(0);
 
    if( !capture )
    {
 		AfxMessageBox("本机没有安装摄像头！");
        return;
    }

	m_CaptFlag=3;                           //  设置视频状态标志

    cvNamedWindow( "Laplacian", 0 );
 
	m_ImageType=-3;
    for(;;)
    {
        IplImage* frame = 0;
        int i;

        frame = cvQueryFrame( capture );
        if( !frame )
            break;

        if( !laplace )
        {
            for( i = 0; i < 3; i++ )
                planes[i] = cvCreateImage( cvSize(frame->width,frame->height), 8, 1 );
            laplace = cvCreateImage( cvSize(frame->width,frame->height), IPL_DEPTH_16S, 1 );
            colorlaplace = cvCreateImage( cvSize(frame->width,frame->height), 8, 3 );
        }

        cvCvtPixToPlane( frame, planes[0], planes[1], planes[2], 0 );
        for( i = 0; i < 3; i++ )
        {
            cvLaplace( planes[i], laplace, 3 );
            cvConvertScaleAbs( laplace, planes[i], 1, 0 );
        }
        cvCvtPlaneToPix( planes[0], planes[1], planes[2], 0, colorlaplace );
        colorlaplace->origin = frame->origin;

        cvShowImage("Laplacian", colorlaplace );

        if( cvWaitKey(10) >= 0 )
            break;
    }

    cvReleaseCapture( &capture );
    cvDestroyWindow("Laplacian");

	m_CaptFlag=0;
	m_ImageType=0;
}

//-------------------------------------
//  L_K 算法光流跟踪
//  根据 OpenCV 系统软件程序实例 lkdemo.cpp 改编

//IplImage *image = 0, *grey = 0, *prev_grey = 0, *pyramid = 0, *prev_pyramid = 0, *swap_temp;
IplImage *grey = 0, *prev_grey = 0, *pyramid = 0, *prev_pyramid = 0, *swap_temp;

int win_size = 10;
const int MAX_COUNT = 500;
CvPoint2D32f* points[2] = {0,0}, *swap_points;
char* status = 0;
int count = 0;
int need_to_init = 0;
int night_mode = 0;
int flags = 0;
int add_remove_pt = 0;
CvPoint pt;

void on_mouse3( int event, int x, int y, int flags, void* param )
{
    if( !image )
        return;

    if( image->origin )
        y = image->height - y;

    if( event == CV_EVENT_LBUTTONDOWN )
    {
        pt = cvPoint(x,y);
        add_remove_pt = 1;
    }
}

void CCVMFCView::OnOpticalFlowTrack()       //  L_K 算法光流跟踪
{
    CvCapture* capture = 0;
    
    capture = cvCaptureFromCAM(0);
 
    if( !capture )
    {
 		AfxMessageBox("本机没有安装摄像头！");
        return;
    }

	m_CaptFlag=3;                           //  设置视频状态标志

	if( image )
		cvReleaseImage( &image );

    /* print a welcome message, and the OpenCV version */
/*
    printf ("Welcome to lkdemo, using OpenCV version %s (%d.%d.%d)\n",
	    CV_VERSION,
	    CV_MAJOR_VERSION, CV_MINOR_VERSION, CV_SUBMINOR_VERSION);

    printf( "Hot keys: \n"
            "\tESC - quit the program\n"
            "\tr - auto-initialize tracking\n"
            "\tc - delete all the points\n"
            "\tn - switch the \"night\" mode on/off\n"
            "To add/remove a feature point click it\n" );
*/
    cvNamedWindow( "LkDemo", 0 );
    cvSetMouseCallback( "LkDemo", on_mouse3, 0 );

	m_ImageType=-3;
    for(;;)
    {
        IplImage* frame = 0;
        int i, k, c;

        frame = cvQueryFrame( capture );
        if( !frame )
            break;

        if( !image )
        {
            /* allocate all the buffers */
            image = cvCreateImage( cvGetSize(frame), 8, 3 );
            image->origin = frame->origin;
            grey = cvCreateImage( cvGetSize(frame), 8, 1 );
            prev_grey = cvCreateImage( cvGetSize(frame), 8, 1 );
            pyramid = cvCreateImage( cvGetSize(frame), 8, 1 );
            prev_pyramid = cvCreateImage( cvGetSize(frame), 8, 1 );
            points[0] = (CvPoint2D32f*)cvAlloc(MAX_COUNT*sizeof(points[0][0]));
            points[1] = (CvPoint2D32f*)cvAlloc(MAX_COUNT*sizeof(points[0][0]));
            status = (char*)cvAlloc(MAX_COUNT);
            flags = 0;
        }

        cvCopy( frame, image, 0 );
        cvCvtColor( image, grey, CV_BGR2GRAY );

        if( night_mode )
            cvZero( image );
        
        if( need_to_init )
        {
            /* automatic initialization */
            IplImage* eig = cvCreateImage( cvGetSize(grey), 32, 1 );
            IplImage* temp = cvCreateImage( cvGetSize(grey), 32, 1 );
            double quality = 0.01;
            double min_distance = 10;

            count = MAX_COUNT;
            cvGoodFeaturesToTrack( grey, eig, temp, points[1], &count,
                                   quality, min_distance, 0, 3, 0, 0.04 );
            cvFindCornerSubPix( grey, points[1], count,
                cvSize(win_size,win_size), cvSize(-1,-1),
                cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03));
            cvReleaseImage( &eig );
            cvReleaseImage( &temp );

            add_remove_pt = 0;
        }
        else if( count > 0 )
        {
            cvCalcOpticalFlowPyrLK( prev_grey, grey, prev_pyramid, pyramid,
                points[0], points[1], count, cvSize(win_size,win_size), 3, status, 0,
                cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03), flags );
            flags |= CV_LKFLOW_PYR_A_READY;
            for( i = k = 0; i < count; i++ )
            {
                if( add_remove_pt )
                {
                    double dx = pt.x - points[1][i].x;
                    double dy = pt.y - points[1][i].y;

                    if( dx*dx + dy*dy <= 25 )
                    {
                        add_remove_pt = 0;
                        continue;
                    }
                }
                
                if( !status[i] )
                    continue;
                
                points[1][k++] = points[1][i];
                cvCircle( image, cvPointFrom32f(points[1][i]), 3, CV_RGB(0,255,0), -1, 8,0);
            }
            count = k;
        }

        if( add_remove_pt && count < MAX_COUNT )
        {
            points[1][count++] = cvPointTo32f(pt);
            cvFindCornerSubPix( grey, points[1] + count - 1, 1,
                cvSize(win_size,win_size), cvSize(-1,-1),
                cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03));
            add_remove_pt = 0;
        }

        CV_SWAP( prev_grey, grey, swap_temp );
        CV_SWAP( prev_pyramid, pyramid, swap_temp );
        CV_SWAP( points[0], points[1], swap_points );
        need_to_init = 0;
        cvShowImage( "LkDemo", image );

        c = cvWaitKey(10);
        if( (char)c == 27 )
            break;
        switch( (char) c )
        {
        case 'r':
            need_to_init = 1;
            break;
        case 'c':
            count = 0;
            break;
        case 'n':
            night_mode ^= 1;
            break;
        default:
            ;
        }
    }

    cvReleaseCapture( &capture );
    cvDestroyWindow("LkDemo");

	m_CaptFlag=0;
	m_ImageType=0;
}

//-------------------------------------
//  背景建模检测运动物体
//  根据《学习OpenCV》例 5-20 改编

#include "cvcam.h"

void CCVMFCView::OnForegroundDetect()       //  背景建模检测运动物体
{
	//声明IplImage指针
	IplImage* pFrame = NULL; 
	IplImage* pFrImg = NULL;
	IplImage* pBkImg = NULL;

	CvMat* pFrameMat = NULL;
	CvMat* pFrMat = NULL;
	CvMat* pBkMat = NULL;
  
	CvCapture* pCapture = NULL;
  
	int nFrmNum = 0;
 
    pCapture = cvCaptureFromCAM(0);

    if( !pCapture )
    {
 		AfxMessageBox("本机没有安装摄像头！");
        return;
    }

	m_CaptFlag=3;                           //  设置视频状态标志

	//创建窗口
	cvNamedWindow("video", 0);
	cvNamedWindow("background",0);
	cvNamedWindow("foreground",0);

	cvResizeWindow("video",320,240);
	cvResizeWindow("background",320,240);
	cvResizeWindow("foreground",320,240);

	//使窗口有序排列
	cvMoveWindow("video", 30, 0);
	cvMoveWindow("background", 360, 0);
	cvMoveWindow("foreground", 690, 0);

  
	m_ImageType=-3;
	//逐帧读取视频
  	while(pFrame = cvQueryFrame( pCapture ))
    {
      	nFrmNum++;
      
      	//如果是第一帧，需要申请内存，并初始化
      	if(nFrmNum == 1)
		{
	  		pBkImg = cvCreateImage(cvSize(pFrame->width, pFrame->height),
  									IPL_DEPTH_8U,1);
	  		pFrImg = cvCreateImage(cvSize(pFrame->width, pFrame->height),  
									IPL_DEPTH_8U,1);
			pBkMat = cvCreateMat(pFrame->height, pFrame->width, CV_32FC1);
	  		pFrMat = cvCreateMat(pFrame->height, pFrame->width, CV_32FC1);
	  		pFrameMat = cvCreateMat(pFrame->height, pFrame->width, CV_32FC1);

	  		//转化成单通道图像再处理
	  		cvCvtColor(pFrame, pBkImg, CV_BGR2GRAY);
	  		cvCvtColor(pFrame, pFrImg, CV_BGR2GRAY);

	  		cvConvert(pFrImg, pFrameMat);
	  		cvConvert(pFrImg, pFrMat);
	  		cvConvert(pFrImg, pBkMat);
		}
      	else
		{
	  		cvCvtColor(pFrame, pFrImg, CV_BGR2GRAY);
	  		cvConvert(pFrImg, pFrameMat);
	  		//先做高斯滤波，以平滑图像
	  		//cvSmooth(pFrameMat, pFrameMat, CV_GAUSSIAN, 3, 0, 0, 0);
	  
	  		//当前帧跟背景图相减
	  		cvAbsDiff(pFrameMat, pBkMat, pFrMat);

	  		//二值化前景图
	  		cvThreshold(pFrMat, pFrImg, 60, 255.0, CV_THRESH_BINARY);
			pFrImg->origin=pFrame->origin;

	  		//进行形态学滤波，去掉噪音  
	 		//cvErode(pFrImg, pFrImg, 0, 1);
	  		//cvDilate(pFrImg, pFrImg, 0, 1);

	  		//更新背景
	  		cvRunningAvg(pFrameMat, pBkMat, 0.003, 0);
	  		//将背景转化为图像格式，用以显示
	  		cvConvert(pBkMat, pBkImg);
			pBkImg->origin=pFrame->origin;

	  		//显示图像
	  		cvShowImage("video", pFrame);
	  		cvShowImage("background", pBkImg);
	  		cvShowImage("foreground", pFrImg);

	  		//如果有按键事件，则跳出循环
	  		//此等待也为cvShowImage函数提供时间完成显示
	  		//等待时间可以根据CPU速度调整
	  		if( cvWaitKey(2) >= 0 )
	    		break;
		}  // end of if-else
    } // end of while-loop

  	//销毁窗口
  	cvDestroyWindow("video");
  	cvDestroyWindow("background");
  	cvDestroyWindow("foreground");

  	//释放图像和矩阵
  	cvReleaseImage(&pFrImg);
  	cvReleaseImage(&pBkImg);

  	cvReleaseMat(&pFrameMat);
  	cvReleaseMat(&pFrMat);
  	cvReleaseMat(&pBkMat);

  	cvReleaseCapture(&pCapture);

	m_CaptFlag=0;
	m_ImageType=0;
}

//-------------------------------------
//  运动目标跟踪
//  根据《OpenCV教程(基础篇)》例 5-21 改编
//  OpenCV 系统软件程序实例 motempl.c

// various tracking parameters (in seconds)
const double MHI_DURATION = 1;
const double MAX_TIME_DELTA = 0.5;
const double MIN_TIME_DELTA = 0.05;
// number of cyclic frame buffer used for motion detection
// (should, probably, depend on FPS)
const int N = 4;

// ring image buffer
IplImage **buf = 0;
int last = 0;

// temporary images
IplImage *mhi = 0; // MHI
IplImage *orient = 0; // orientation
//IplImage *mask = 0; // valid orientation mask
IplImage *segmask = 0; // motion segmentation map
//CvMemStorage* storage = 0; // temporary storage

// parameters:
//  img - input video frame
//  dst - resultant motion picture
//  args - optional parameters
void  update_mhi( IplImage* img, IplImage* dst, int diff_threshold )
{
    double timestamp = (double)clock()/CLOCKS_PER_SEC; // get current time in seconds
    CvSize size = cvSize(img->width,img->height); // get current frame size
    int i, idx1 = last, idx2;
    IplImage* silh;
    CvSeq* seq;
    CvRect comp_rect;
    double count;
    double angle;
    CvPoint center;
    double magnitude;          
    CvScalar color;

    // allocate images at the beginning or
    // reallocate them if the frame size is changed
    if( !mhi || mhi->width != size.width || mhi->height != size.height ) {
        if( buf == 0 ) {
            buf = (IplImage**)malloc(N*sizeof(buf[0]));
            memset( buf, 0, N*sizeof(buf[0]));
        }
        
        for( i = 0; i < N; i++ ) {
            cvReleaseImage( &buf[i] );
            buf[i] = cvCreateImage( size, IPL_DEPTH_8U, 1 );
            cvZero( buf[i] );
        }
        cvReleaseImage( &mhi );
        cvReleaseImage( &orient );
        cvReleaseImage( &segmask );
        cvReleaseImage( &mask );
        
        mhi = cvCreateImage( size, IPL_DEPTH_32F, 1 );
        cvZero( mhi ); // clear MHI at the beginning
        orient = cvCreateImage( size, IPL_DEPTH_32F, 1 );
        segmask = cvCreateImage( size, IPL_DEPTH_32F, 1 );
        mask = cvCreateImage( size, IPL_DEPTH_8U, 1 );
    }

    cvCvtColor( img, buf[last], CV_BGR2GRAY ); // convert frame to grayscale

    idx2 = (last + 1) % N; // index of (last - (N-1))th frame
    last = idx2;

    silh = buf[idx2];
    cvAbsDiff( buf[idx1], buf[idx2], silh ); // get difference between frames
    
    cvThreshold( silh, silh, diff_threshold, 1, CV_THRESH_BINARY ); // and threshold it
    cvUpdateMotionHistory( silh, mhi, timestamp, MHI_DURATION ); // update MHI

    // convert MHI to blue 8u image
    cvCvtScale( mhi, mask, 255./MHI_DURATION,
                (MHI_DURATION - timestamp)*255./MHI_DURATION );
    cvZero( dst );
    cvCvtPlaneToPix( mask, 0, 0, 0, dst );

    // calculate motion gradient orientation and valid orientation mask
    cvCalcMotionGradient( mhi, mask, orient, MAX_TIME_DELTA, MIN_TIME_DELTA, 3 );
    
    if( !storage )
        storage = cvCreateMemStorage(0);
    else
        cvClearMemStorage(storage);
    
    // segment motion: get sequence of motion components
    // segmask is marked motion components map. It is not used further
    seq = cvSegmentMotion( mhi, segmask, storage, timestamp, MAX_TIME_DELTA );

    // iterate through the motion components,
    // One more iteration (i == -1) corresponds to the whole image (global motion)
    for( i = -1; i < seq->total; i++ ) {

        if( i < 0 ) { // case of the whole image
            comp_rect = cvRect( 0, 0, size.width, size.height );
            color = CV_RGB(255,255,255);
            magnitude = 100;
        }
        else { // i-th motion component
            comp_rect = ((CvConnectedComp*)cvGetSeqElem( seq, i ))->rect;
            if( comp_rect.width + comp_rect.height < 100 ) // reject very small components
                continue;
            color = CV_RGB(255,0,0);
            magnitude = 30;
        }

        // select component ROI
        cvSetImageROI( silh, comp_rect );
        cvSetImageROI( mhi, comp_rect );
        cvSetImageROI( orient, comp_rect );
        cvSetImageROI( mask, comp_rect );

        // calculate orientation
        angle = cvCalcGlobalOrientation( orient, mask, mhi, timestamp, MHI_DURATION);
        angle = 360.0 - angle;  // adjust for images with top-left origin

        count = cvNorm( silh, 0, CV_L1, 0 ); // calculate number of points within silhouette ROI

        cvResetImageROI( mhi );
        cvResetImageROI( orient );
        cvResetImageROI( mask );
        cvResetImageROI( silh );

        // check for the case of little motion
        if( count < comp_rect.width*comp_rect.height * 0.05 )
            continue;

        // draw a clock with arrow indicating the direction
        center = cvPoint( (comp_rect.x + comp_rect.width/2),
                          (comp_rect.y + comp_rect.height/2) );

        cvCircle( dst, center, cvRound(magnitude*1.2), color, 3, CV_AA, 0 );
        cvLine( dst, center, cvPoint( cvRound( center.x + magnitude*cos(angle*CV_PI/180)),
                cvRound( center.y - magnitude*sin(angle*CV_PI/180))), color, 3, CV_AA, 0 );
    }
}

void CCVMFCView::OnMotionDetect()           //  运动目标跟踪
{
    IplImage* motion = 0;
    CvCapture* capture = 0;
    
    capture = cvCaptureFromCAM(0);
 
    if( !capture )
    {
 		AfxMessageBox("本机没有安装摄像头！");
        return;
    }

	m_CaptFlag=3;                           //  设置视频状态标志

    cvNamedWindow( "Motion", 1 );
        
	m_ImageType=-3;
    for(;;)
    {
        IplImage* image;
        if( !cvGrabFrame( capture ))
            break;
        image = cvRetrieveFrame( capture );

        if( image )
        {
            if( !motion )
            {
                motion = cvCreateImage( cvSize(image->width,image->height), 8, 3 );
                cvZero( motion );
                motion->origin = image->origin;
            }
        }

        update_mhi( image, motion, 30 );
        cvShowImage( "Motion", motion );

        if( cvWaitKey(10) >= 0 )
            break;
    }
    cvReleaseCapture( &capture );
    cvDestroyWindow( "Motion" );
 
	m_CaptFlag=0;
	m_ImageType=0;
}

//-------------------------------------
//  彩色目标跟踪
//  根据《OpenCV教程(基础篇)》例 5-22 改编
//  OpenCV 系统软件程序实例 camshiftdemo.c

//IplImage *image = 0, *hsv = 0, *hue = 0, *mask = 0, *backproject = 0, *histimg = 0;
IplImage *hsv = 0, *hue = 0, *backproject = 0, *histimg = 0;
CvHistogram *hist = 0;

int backproject_mode = 0;
int select_object = 0;
int track_object = 0;
int show_hist = 1;
CvPoint origin;
CvRect selection;
CvRect track_window;
CvBox2D track_box;
CvConnectedComp track_comp;
int hdims = 16;
float hranges_arr[] = {0,180};
float* hranges = hranges_arr;
int vmin = 10, vmax = 256, smin = 30;

void on_mouse4( int event, int x, int y, int flags, void* param )
{
    if( !image )
        return;

    if( image->origin )
        y = image->height - y;

    if( select_object )
    {
        selection.x = MIN(x,origin.x);
        selection.y = MIN(y,origin.y);
        selection.width = selection.x + CV_IABS(x - origin.x);
        selection.height = selection.y + CV_IABS(y - origin.y);
        
        selection.x = MAX( selection.x, 0 );
        selection.y = MAX( selection.y, 0 );
        selection.width = MIN( selection.width, image->width );
        selection.height = MIN( selection.height, image->height );
        selection.width -= selection.x;
        selection.height -= selection.y;
    }

    switch( event )
    {
    case CV_EVENT_LBUTTONDOWN:
        origin = cvPoint(x,y);
        selection = cvRect(x,y,0,0);
        select_object = 1;
        break;
    case CV_EVENT_LBUTTONUP:
        select_object = 0;
        if( selection.width > 0 && selection.height > 0 )
            track_object = -1;
        break;
    }
}

CvScalar hsv2rgb( float hue )
{
    int rgb[3], p, sector;
    static const int sector_data[][3]=
        {{0,2,1}, {1,2,0}, {1,0,2}, {2,0,1}, {2,1,0}, {0,1,2}};
    hue *= 0.033333333333333333333333333333333f;
    sector = cvFloor(hue);
    p = cvRound(255*(hue - sector));
    p ^= sector & 1 ? 255 : 0;

    rgb[sector_data[sector][0]] = 255;
    rgb[sector_data[sector][1]] = 0;
    rgb[sector_data[sector][2]] = p;

    return cvScalar(rgb[2], rgb[1], rgb[0],0);
}

void CCVMFCView::OnCamShiftDemo() 
{
    CvCapture* capture = 0;
    
    capture = cvCaptureFromCAM(0);
 
    if( !capture )
    {
 		AfxMessageBox("本机没有安装摄像头！");
        return;
    }

	m_CaptFlag=3;                           //  设置视频状态标志

	if( image )
		cvReleaseImage( &image );
	if( mask )
		cvReleaseImage( &mask );
/*
    printf( "Hot keys: \n"
        "\tESC - quit the program\n"
        "\tc - stop the tracking\n"
        "\tb - switch to/from backprojection view\n"
        "\th - show/hide object histogram\n"
        "To initialize tracking, select the object with mouse\n" );
*/
    cvNamedWindow( "Histogram", 1 );
    cvNamedWindow( "CamShiftDemo", 1 );
    cvSetMouseCallback( "CamShiftDemo", on_mouse4, 0 );
    cvCreateTrackbar( "Vmin", "CamShiftDemo", &vmin, 256, 0 );
    cvCreateTrackbar( "Vmax", "CamShiftDemo", &vmax, 256, 0 );
    cvCreateTrackbar( "Smin", "CamShiftDemo", &smin, 256, 0 );

	m_ImageType=-3;
    for(;;)
    {
        IplImage* frame = 0;
        int i, bin_w, c;

        frame = cvQueryFrame( capture );
        if( !frame )
            break;

        if( !image )
        {
            /* allocate all the buffers */
            image = cvCreateImage( cvGetSize(frame), 8, 3 );
            image->origin = frame->origin;
            hsv = cvCreateImage( cvGetSize(frame), 8, 3 );
            hue = cvCreateImage( cvGetSize(frame), 8, 1 );
            mask = cvCreateImage( cvGetSize(frame), 8, 1 );
            backproject = cvCreateImage( cvGetSize(frame), 8, 1 );
            hist = cvCreateHist( 1, &hdims, CV_HIST_ARRAY, &hranges, 1 );
            histimg = cvCreateImage( cvSize(320,200), 8, 3 );
            cvZero( histimg );
        }

        cvCopy( frame, image, 0 );
        cvCvtColor( image, hsv, CV_BGR2HSV );

        if( track_object )
        {
            int _vmin = vmin, _vmax = vmax;

            cvInRangeS( hsv, cvScalar(0,smin,MIN(_vmin,_vmax),0),
                        cvScalar(180,256,MAX(_vmin,_vmax),0), mask );
            cvSplit( hsv, hue, 0, 0, 0 );

            if( track_object < 0 )
            {
                float max_val = 0.f;
                cvSetImageROI( hue, selection );
                cvSetImageROI( mask, selection );
                cvCalcHist( &hue, hist, 0, mask );
                cvGetMinMaxHistValue( hist, 0, &max_val, 0, 0 );
                cvConvertScale( hist->bins, hist->bins, max_val ? 255. / max_val : 0., 0 );
                cvResetImageROI( hue );
                cvResetImageROI( mask );
                track_window = selection;
                track_object = 1;

                cvZero( histimg );
                bin_w = histimg->width / hdims;
                for( i = 0; i < hdims; i++ )
                {
                    int val = cvRound( cvGetReal1D(hist->bins,i)*histimg->height/255 );
                    CvScalar color = hsv2rgb(i*180.f/hdims);
                    cvRectangle( histimg, cvPoint(i*bin_w,histimg->height),
                                 cvPoint((i+1)*bin_w,histimg->height - val),
                                 color, -1, 8, 0 );
                }
            }

            cvCalcBackProject( &hue, backproject, hist );
            cvAnd( backproject, mask, backproject, 0 );
            cvCamShift( backproject, track_window,
                        cvTermCriteria( CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1 ),
                        &track_comp, &track_box );
            track_window = track_comp.rect;
            
            if( backproject_mode )
                cvCvtColor( backproject, image, CV_GRAY2BGR );
            if( image->origin )
                track_box.angle = -track_box.angle;
            cvEllipseBox( image, track_box, CV_RGB(255,0,0), 3, CV_AA, 0 );
        }
        
        if( select_object && selection.width > 0 && selection.height > 0 )
        {
            cvSetImageROI( image, selection );
            cvXorS( image, cvScalarAll(255), image, 0 );
            cvResetImageROI( image );
        }

        cvShowImage( "CamShiftDemo", image );
        cvShowImage( "Histogram", histimg );

        c = cvWaitKey(10);
        if( (char) c == 27 )
            break;
        switch( (char) c )
        {
        case 'b':
            backproject_mode ^= 1;
            break;
        case 'c':
            track_object = 0;
            cvZero( histimg );
            break;
        case 'h':
            show_hist ^= 1;
            if( !show_hist )
                cvDestroyWindow( "Histogram" );
            else
                cvNamedWindow( "Histogram", 1 );
            break;
        default:
            ;
        }
    }

    if( show_hist )
        cvDestroyWindow( "Histogram" );
    cvReleaseCapture( &capture );
    cvDestroyWindow("CamShiftDemo");
 
	m_CaptFlag=0;
	m_ImageType=0;
}

//-------------------------------------
//  人脸检测二
//  根据 OpenCV 系统软件程序实例 facedetect.c 改编

void CCVMFCView::OnFaceDetect2()            //  人脸检测二
{
    CvCapture* capture = 0;
    IplImage *frame, *frame_copy = 0;
	char cascade_name[] = "image\\haarcascade_frontalface_alt.xml";

    capture = cvCaptureFromCAM(0);
 
    if( !capture )
    {
 		AfxMessageBox("本机没有安装摄像头！");
        return;
    }

	m_CaptFlag=3;                           //  设置视频状态标志

    cascade = (CvHaarClassifierCascade*)cvLoad( cascade_name, 0, 0, 0 );
    
    storage1 = cvCreateMemStorage(0);
    
    cvNamedWindow( "result", 1 );

	m_ImageType=-3;
    for(;;)
    {
        if( !cvGrabFrame( capture ))
            break;
        frame = cvRetrieveFrame( capture );
        if( !frame )
            break;
        if( !frame_copy )
            frame_copy = cvCreateImage( cvSize(frame->width,frame->height),
                                    IPL_DEPTH_8U, frame->nChannels );
        if( frame->origin == IPL_ORIGIN_TL )
            cvCopy( frame, frame_copy, 0 );
        else
            cvFlip( frame, frame_copy, 0 );
           
        detect_and_draw( frame_copy , 1);

        if( cvWaitKey( 10 ) >= 0 )
            break;
    }

    cvReleaseImage( &frame_copy );
    cvReleaseCapture( &capture );
    
	cvReleaseMemStorage(&storage1);
	cvReleaseHaarClassifierCascade( &cascade );
    cvDestroyWindow("result");
 
	m_CaptFlag=0;
	m_ImageType=0;
}

//---------------------------------------------------------
//  彩色图像处理

void CCVMFCView::OnUpdateImageRgb(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateImageRgbC(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateImageHsv(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateImageLab(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateImageXyz(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateImageYcrcb(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateImageLuv(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdate2dHistogram(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateBlurSmoothC(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateGaussSmoothC(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateMedianSmoothC(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateSobelC(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateLaplaceC(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnImageRgb() 
{
	IplImage* pImage    = NULL; 
	IplImage* pRedImg   = NULL; 
	IplImage* pGreenImg = NULL;
	IplImage* pBlueImg  = NULL;
 	IplImage* pMaskImg  = NULL; 
	int   wid,hei,top;
 
	pImage = cvCloneImage( workImg );
	cvFlip(pImage);

	pRedImg   = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	pGreenImg = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	pBlueImg  = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);

    cvCvtPixToPlane( pImage, pBlueImg, pGreenImg, pRedImg, 0 );

	cvNamedWindow("Red Image", 0);
	cvNamedWindow("Green Image", 0);
	cvNamedWindow("Blue Image", 0);
 
	if (pImage->width>320) wid=320;
	else wid=pImage->width;
	hei = wid*pImage->height/pImage->width;
	cvResizeWindow("Red Image",wid,hei);
	cvResizeWindow("Green Image",wid,hei);
	cvResizeWindow("Blue Image",wid,hei);

	top = 695 - hei;
	cvMoveWindow("Red Image", 15, top);
	cvMoveWindow("Green Image", 345, top);
	cvMoveWindow("Blue Image", 675, top);

	cvShowImage("Red Image", pRedImg);
 	cvShowImage("Green Image", pGreenImg);
 	cvShowImage("Blue Image", pBlueImg);

	m_ImageType=-3;
	cvWaitKey(0);

  	cvDestroyWindow("Red Image");
  	cvDestroyWindow("Green Image");
  	cvDestroyWindow("Blue Image");
  	cvReleaseImage(&pImage);
  	cvReleaseImage(&pRedImg);
  	cvReleaseImage(&pGreenImg);
  	cvReleaseImage(&pBlueImg);

	m_ImageType=3;
}

void CCVMFCView::OnImageHsv() 
{
	IplImage* pImage  = NULL; 
	IplImage* pHueImg = NULL; 
	IplImage* pSatImg = NULL;
	IplImage* pValImg = NULL;
 	IplImage* pMaskImg  = NULL; 
	int   wid,hei,top,i,j,k,bplc,bplh;
	BYTE  *buf,*bufc,*bufh;

	pImage = cvCloneImage( workImg );
	cvFlip(pImage);

	pHueImg = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	pSatImg = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	pValImg = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);

	cvCvtColor( pImage, pImage ,CV_BGR2HSV );  //  模式转换
    cvCvtPixToPlane( pImage, pHueImg, pSatImg, pValImg, 0 );  //  各分量分离

	pMaskImg = cvCreateImage(cvSize(256, 1),IPL_DEPTH_8U,3);
	buf=(BYTE*) pMaskImg->imageData;
	memset(buf,232,pMaskImg->imageSize);    //  设置基色值
	for (i=0;i<=180;i++) {                  //  181 种色调模式
		buf[3*i]=(BYTE) i;                  //  hue
//		buf[3*i+1]=255;                     //  Saturation
//		buf[3*i+2]=255;                     //  Value
	}
	cvCvtColor( pMaskImg, pMaskImg ,CV_HSV2BGR );  //  转换成显示用 BGR 分量

	bufh =(BYTE*) pHueImg->imageData;       //  灰阶色调图
	bplh = pHueImg->widthStep;
	bufc =(BYTE*) pImage->imageData;        //  彩色色调图
	bplc = pImage->widthStep;
	for (i=0;i<pHueImg->height;i++) {
		for (j=0,k=0;j<pHueImg->width;j++,k+=3) {
			memcpy(&bufc[k],&buf[3*bufh[j]],3);  //  逐点查表转换
		}
		bufc+=bplc;     bufh+=bplh;         //  指向下一行
	}

	cvNamedWindow("Hue Image", 0);
	cvNamedWindow("Saturation Image", 0);
	cvNamedWindow("Value Image", 0);

	if (pImage->width>320) wid=320;
	else wid=pImage->width;
	hei = wid*pImage->height/pImage->width;
	cvResizeWindow("Hue Image",wid,hei);
	cvResizeWindow("Saturation Image",wid,hei);
	cvResizeWindow("Value Image",wid,hei);

	top = 695 - hei;
	cvMoveWindow("Hue Image", 15, top);
	cvMoveWindow("Saturation Image", 345, top);
	cvMoveWindow("Value Image", 675, top);

//	cvShowImage("Hue Image", pHueImg);      //  灰阶色调图
	cvShowImage("Hue Image", pImage);       //  彩色色调图
	cvShowImage("Saturation Image", pSatImg);
	cvShowImage("Value Image", pValImg);

	m_ImageType=-3;
	cvWaitKey(0);

  	cvDestroyWindow("Hue Image");
  	cvDestroyWindow("Saturation Image");
  	cvDestroyWindow("Value Image");
  	cvReleaseImage(&pImage);
   	cvReleaseImage(&pHueImg);
  	cvReleaseImage(&pSatImg);
  	cvReleaseImage(&pValImg);
  	cvReleaseImage(&pMaskImg);

	m_ImageType=3;
}

void CCVMFCView::OnImageLab() 
{
	IplImage* pImage  = NULL; 
	IplImage* pLImg   = NULL; 
	IplImage* paImg   = NULL;
	IplImage* pbImg   = NULL;
	int   wid,hei,top;

	pImage = cvCloneImage( workImg );
	cvFlip(pImage);

	pLImg   = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	paImg   = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	pbImg   = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);

	cvCvtColor( pImage, pImage ,CV_BGR2Lab );

    cvCvtPixToPlane( pImage, pLImg, paImg, pbImg, 0 );

	cvNamedWindow("L Image", 0);
	cvNamedWindow("a Image", 0);
	cvNamedWindow("b Image", 0);
 
	if (pImage->width>320) wid=320;
	else wid=pImage->width;
	hei = wid*pImage->height/pImage->width;
	cvResizeWindow("L Image",wid,hei);
	cvResizeWindow("a Image",wid,hei);
	cvResizeWindow("b Image",wid,hei);

	top = 695 - hei;
	cvMoveWindow("L Image", 15, top);
	cvMoveWindow("a Image", 345, top);
	cvMoveWindow("b Image", 675, top);

	cvShowImage("L Image", pLImg);
	cvShowImage("a Image", paImg);
	cvShowImage("b Image", pbImg);

	m_ImageType=-3;
	cvWaitKey(0);

  	cvDestroyWindow("L Image");
  	cvDestroyWindow("a Image");
  	cvDestroyWindow("b Image");
  	cvReleaseImage(&pImage);
   	cvReleaseImage(&pLImg);
  	cvReleaseImage(&paImg);
  	cvReleaseImage(&pbImg);

	m_ImageType=3;
}

void CCVMFCView::OnImageRgbC() 
{
	IplImage* pImage    = NULL; 
	IplImage* pRedImg   = NULL; 
	IplImage* pGreenImg = NULL;
	IplImage* pBlueImg  = NULL;
 	IplImage* pMaskImg  = NULL; 
	int   wid,hei,top,i,j,k,bplc,bplh;
	BYTE  *buf,*bufc,*bufh;

	pImage = cvCloneImage( workImg );
	cvFlip(pImage);

	pRedImg   = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	pGreenImg = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	pBlueImg  = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);

    cvCvtPixToPlane( pImage, pBlueImg, pGreenImg, pRedImg, 0 );

	cvNamedWindow("Red Image", 0);
	cvNamedWindow("Green Image",0);
	cvNamedWindow("Blue Image",0);
 
	if (pImage->width>320) wid=320;
	else wid=pImage->width;
	hei = wid*pImage->height/pImage->width;
	cvResizeWindow("Red Image",wid,hei);
	cvResizeWindow("Green Image",wid,hei);
	cvResizeWindow("Blue Image",wid,hei);

	top = 695 - hei;
	cvMoveWindow("Red Image", 15, top);
	cvMoveWindow("Green Image", 345, top);
	cvMoveWindow("Blue Image", 675, top);

	pMaskImg = cvCreateImage(cvSize(256, 1),IPL_DEPTH_8U,3);
	buf=(BYTE*) pMaskImg->imageData;
	memset(buf,0,pMaskImg->imageSize);
	for (i=0;i<256;i++) {  
		buf[3*i+2]=(BYTE) i;                //  红分量
	}
	bufc =(BYTE*) pImage->imageData;
	bplc = pImage->widthStep;
	bufh =(BYTE*) pRedImg->imageData;
	bplh = pRedImg->widthStep;
	for (i=0;i<pRedImg->height;i++) {
		for (j=0,k=0;j<pRedImg->width;j++,k+=3) {
			memcpy(&bufc[k],&buf[3*bufh[j]],3);  //  逐点查表转换
		}
		bufc+=bplc;     bufh+=bplh;         //  指向下一行
	}
	cvShowImage("Red Image", pImage);

	memset(buf,0,pMaskImg->imageSize);
	for (i=0;i<256;i++) {  
		buf[3*i+1]=(BYTE) i;                //  绿分量
	}
	bufc =(BYTE*) pImage->imageData;
	bplc = pImage->widthStep;
	bufh =(BYTE*) pGreenImg->imageData;
	bplh = pRedImg->widthStep;
	for (i=0;i<pRedImg->height;i++) {
		for (j=0,k=0;j<pRedImg->width;j++,k+=3) {
			memcpy(&bufc[k],&buf[3*bufh[j]],3); 
		}
		bufc+=bplc;     bufh+=bplh; 
	}
	cvShowImage("Green Image", pImage);

	memset(buf,0,pMaskImg->imageSize);
	for (i=0;i<256;i++) {  
		buf[3*i]=(BYTE) i;                  //  蓝分量
	}
	bufc =(BYTE*) pImage->imageData;
	bplc = pImage->widthStep;
	bufh =(BYTE*) pBlueImg->imageData;
	bplh = pRedImg->widthStep;
	for (i=0;i<pRedImg->height;i++) {
		for (j=0,k=0;j<pRedImg->width;j++,k+=3) {
			memcpy(&bufc[k],&buf[3*bufh[j]],3); 
		}
		bufc+=bplc;     bufh+=bplh; 
	}
	cvShowImage("Blue Image", pImage);

	m_ImageType=-3;
	cvWaitKey(0);

  	cvDestroyWindow("Red Image");
  	cvDestroyWindow("Green Image");
  	cvDestroyWindow("Blue Image");
  	cvReleaseImage(&pImage);
  	cvReleaseImage(&pRedImg);
  	cvReleaseImage(&pGreenImg);
  	cvReleaseImage(&pBlueImg);
  	cvReleaseImage(&pMaskImg);

	m_ImageType=3;
}

void CCVMFCView::OnImageXyz() 
{
	IplImage* pImage  = NULL; 
 	IplImage* pXImg   = NULL; 
	IplImage* pYImg   = NULL;
	IplImage* pZImg   = NULL;
	int   wid,hei,top;

	pImage = cvCloneImage( workImg );
	cvFlip(pImage);

 	pXImg   = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	pYImg   = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	pZImg   = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);

	cvCvtColor( pImage, pImage ,CV_BGR2XYZ );

    cvCvtPixToPlane( pImage, pXImg, pYImg, pZImg, 0 );

	cvNamedWindow("X Image", 0);
	cvNamedWindow("Y Image", 0);
	cvNamedWindow("Z Image", 0);
 
	if (pImage->width>320) wid=320;
	else wid=pImage->width;
	hei = wid*pImage->height/pImage->width;
	cvResizeWindow("X Image",wid,hei);
	cvResizeWindow("Y Image",wid,hei);
	cvResizeWindow("Z Image",wid,hei);

	top = 695 - hei;
	cvMoveWindow("X Image", 15, top);
	cvMoveWindow("Y Image", 345, top);
	cvMoveWindow("Z Image", 675, top);

	cvShowImage("X Image", pXImg);
	cvShowImage("Y Image", pYImg);
	cvShowImage("Z Image", pZImg);

	m_ImageType=-3;
	cvWaitKey(0);

  	cvDestroyWindow("X Image");
  	cvDestroyWindow("Y Image");
  	cvDestroyWindow("Z Image");
  	cvReleaseImage(&pImage);
   	cvReleaseImage(&pXImg);
  	cvReleaseImage(&pYImg);
  	cvReleaseImage(&pZImg);

	m_ImageType=3;
}

void CCVMFCView::OnImageYcrcb() 
{
	IplImage* pImage = NULL; 
 	IplImage* pYImg  = NULL; 
	IplImage* pCrImg = NULL;
	IplImage* pCbImg = NULL;
	int   wid,hei,top;

	pImage = cvCloneImage( workImg );
	cvFlip(pImage);

	pYImg     = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	pCrImg    = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	pCbImg    = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);

	cvCvtColor( pImage, pImage ,CV_BGR2YCrCb );

    cvCvtPixToPlane( pImage, pYImg, pCrImg, pCbImg, 0 );

	cvNamedWindow("Y Image", 0);
	cvNamedWindow("Cr Image", 0);
	cvNamedWindow("Cb Image", 0);
 
	if (pImage->width>320) wid=320;
	else wid=pImage->width;
	hei = wid*pImage->height/pImage->width;
	cvResizeWindow("Y Image",wid,hei);
	cvResizeWindow("Cr Image",wid,hei);
	cvResizeWindow("Cb Image",wid,hei);

	top = 695 - hei;
	cvMoveWindow("Y Image", 15, top);
	cvMoveWindow("Cr Image", 345, top);
	cvMoveWindow("Cb Image", 675, top);

	cvShowImage("Y Image", pYImg);
	cvShowImage("Cr Image", pCrImg);
	cvShowImage("Cb Image", pCbImg);

	m_ImageType=-3;
	cvWaitKey(0);

  	cvDestroyWindow("Y Image");
  	cvDestroyWindow("Cr Image");
  	cvDestroyWindow("Cb Image");
  	cvReleaseImage(&pImage);
  	cvReleaseImage(&pYImg);
  	cvReleaseImage(&pCrImg);
  	cvReleaseImage(&pCbImg);

	m_ImageType=3;
}

void CCVMFCView::OnImageLuv() 
{
	IplImage* pImage  = NULL; 
	IplImage* pLImg   = NULL; 
	IplImage* puImg   = NULL;
	IplImage* pvImg   = NULL;
	int   wid,hei,top;

	pImage = cvCloneImage( workImg );
	cvFlip(pImage);

	pLImg   = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	puImg   = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);
	pvImg   = cvCreateImage(cvSize(pImage->width, pImage->height),
  						IPL_DEPTH_8U,1);

	cvCvtColor( pImage, pImage ,CV_BGR2Lab );

    cvCvtPixToPlane( pImage, pLImg, puImg, pvImg, 0 );

	cvNamedWindow("L Image", 0);
	cvNamedWindow("u Image", 0);
	cvNamedWindow("v Image", 0);
 
	if (pImage->width>320) wid=320;
	else wid=pImage->width;
	hei = wid*pImage->height/pImage->width;
	cvResizeWindow("L Image",wid,hei);
	cvResizeWindow("u Image",wid,hei);
	cvResizeWindow("v Image",wid,hei);

	top = 695 - hei;
	cvMoveWindow("L Image", 15, top);
	cvMoveWindow("u Image", 345, top);
	cvMoveWindow("v Image", 675, top);

	cvShowImage("L Image", pLImg);
	cvShowImage("u Image", puImg);
	cvShowImage("v Image", pvImg);

	m_ImageType=-3;
	cvWaitKey(0);

  	cvDestroyWindow("L Image");
  	cvDestroyWindow("u Image");
  	cvDestroyWindow("v Image");
  	cvReleaseImage(&pImage);
   	cvReleaseImage(&pLImg);
  	cvReleaseImage(&puImg);
  	cvReleaseImage(&pvImg);

	m_ImageType=3;
}

//-------------------------------------
//  彩色图像二维直方图
//  根据《OpenCV教程(基础篇)》例 5-12 改编

void CCVMFCView::On2dHistogram() 
{
    IplImage* src = cvCloneImage( workImg );
 
    IplImage* h_plane = cvCreateImage( cvGetSize(src), 8, 1 );
    IplImage* s_plane = cvCreateImage( cvGetSize(src), 8, 1 );
    IplImage* v_plane = cvCreateImage( cvGetSize(src), 8, 1 );
    IplImage* planes[] = { h_plane, s_plane };
    IplImage* planev[] = { h_plane, v_plane };
    IplImage* plane3[] = { s_plane, v_plane };

    int h_bins = 180, s_bins = 128, v_bins = 128;
    int hist_size[] = {h_bins, s_bins};
    int hist_size3[] = {s_bins, v_bins};
    float h_ranges[] = { 0, 180 }; /* hue varies from 0 (~0°red) to 180 (~360°red again) */
    float s_ranges[] = { 0, 255 }; /* saturation varies from 0 (black-gray-white) to 255 (pure spectrum color) */
    float v_ranges[] = { 0, 255 }; /* value varies from 0 (black-gray-white) to 255 (pure spectrum color) */
    float* ranges[] = { h_ranges, s_ranges };
    float* rangev[] = { h_ranges, v_ranges };
    float* range3[] = { s_ranges, v_ranges };
    IplImage* hist_img = cvCreateImage( cvSize(h_bins,s_bins), 8, 3 );
    CvHistogram* hist;
    int   h, s, v, intensity;
	RGBQUAD pal[256];
	char  *buf;
    int   k, bpl,factor;

	factor = src->imageSize/3/(512*512/4);  //  确定比例因子
	if (factor==0) factor=1;

	GrayColorTransfor(pal);                 //  建立伪彩色调色板

    cvCvtColor( src, src, CV_BGR2HSV );
    cvCvtPixToPlane( src, h_plane, s_plane, v_plane, 0 );
    hist = cvCreateHist( 2, hist_size, CV_HIST_ARRAY, ranges, 1 );

    cvCalcHist( planes, hist, 0, 0 );
 
	buf=hist_img->imageData;
	bpl=hist_img->widthStep;
    for( s = 0; s < s_bins; s++ )
    {
		for( h = 0, k = 0; h < h_bins; h++, k += 3 )
        {
			intensity =(int) (cvQueryHistValue_2D( hist, h, s )/factor);
			if (intensity>255) intensity=255;
			memcpy(&buf[k],&pal[intensity],3);  //  逐点查表转换
        }
		buf+=bpl;
    }
    cvNamedWindow( "H-S", 1 );
	cvMoveWindow("H-S", 820, 160);
	cvFlip(hist_img);
    cvShowImage( "H-S", hist_img );

    cvCalcHist( planev, hist, 0, 0 );
 
	buf=hist_img->imageData;
	bpl=hist_img->widthStep;
    for( v = 0; v < v_bins; v++ )
    {
		for( h = 0, k = 0; h < h_bins; h++, k += 3 )
        {
 			intensity =(int) (cvQueryHistValue_2D( hist, h, v )/factor);
			if (intensity>255) intensity=255;
			memcpy(&buf[k],&pal[intensity],3);
        }
		buf+=bpl;
    }
    cvNamedWindow( "H-V", 1 );
 	cvMoveWindow("H-V", 820, 325);
	cvFlip(hist_img);
    cvShowImage( "H-V", hist_img );

  	cvReleaseImage(&hist_img);
  	cvReleaseHist(&hist);
	hist_img=cvCreateImage( cvSize(s_bins,v_bins), 8, 3 );
    hist = cvCreateHist( 2, hist_size3, CV_HIST_ARRAY, range3, 1 );

    cvCalcHist( plane3, hist, 0, 0 );
 
	buf=hist_img->imageData;
	bpl=hist_img->widthStep;
    for( v = 0; v < v_bins; v++ )
    {
		for( s = 0, k = 0; s < s_bins; s++, k += 3 )
        {
 			intensity =(int) (cvQueryHistValue_2D( hist, s, v )/factor);
			if (intensity>255) intensity=255;
			memcpy(&buf[k],&pal[intensity],3);
        }
		buf+=bpl;
    }
    cvNamedWindow( "S-V", 1 );
 	cvMoveWindow("S-V", 820, 490);
	cvFlip(hist_img);
    cvShowImage( "S-V", hist_img );

	m_ImageType=-3;
    cvWaitKey(0);
  	cvDestroyWindow("H-S");
  	cvDestroyWindow("H-V");
  	cvDestroyWindow("S-V");
  	cvReleaseImage(&src);
  	cvReleaseImage(&h_plane);
  	cvReleaseImage(&s_plane);
  	cvReleaseImage(&v_plane);
  	cvReleaseImage(&hist_img);
  	cvReleaseHist(&hist);

	m_ImageType=3;
}

void CCVMFCView::OnBlurSmoothC() 
{
	OnBlurSmooth();
}

void CCVMFCView::OnGaussSmoothC() 
{
	OnGaussSmooth();
}

void CCVMFCView::OnMedianSmoothC() 
{
	OnMedianSmooth();
}

void CCVMFCView::OnSobelC() 
{
	OnSobel();
}

void CCVMFCView::OnLaplaceC() 
{
	OnLaplace();
}

//---------------------------------------------------------
//  其他

void CCVMFCView::OnUpdateDrawing(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateDelaunay(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateLogPolar(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateDft(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType>0));
}

//-------------------------------------
//  绘制图形
//  根据 OpenCV 系统软件程序实例 drawing.c 改编

#define NUMBER 100
#define DELAY 5
char wndnamed[] = "Drawing Demo";

CvScalar random_color(CvRNG* rng)
{
    int icolor = cvRandInt(rng);
    return CV_RGB(icolor&255, (icolor>>8)&255, (icolor>>16)&255);
}

void CCVMFCView::OnDrawing() 
{
    int line_type = CV_AA; // change it to 8 to see non-antialiased graphics
    int i;
    CvPoint pt1,pt2;
    double angle;
    CvSize sz;
    CvPoint  ptt[6];
    CvPoint* pt[2];
    int  arr[2];
    CvFont font;
    CvRNG rng;
    int width = 1000, height = 700;
    int width3 = width*3, height3 = height*3;
    CvSize text_size;
    int ymin = 0;
    // Load the source image
    IplImage* image = cvCreateImage( cvSize(width,height), 8, 3 );
    IplImage* image2;

    // Create a window
    cvNamedWindow(wndnamed, 1 );
    cvZero( image );
    cvShowImage(wndnamed,image);

    rng = cvRNG((unsigned)-1);
    pt[0] = &(ptt[0]);
    pt[1] = &(ptt[3]);

    arr[0] = 3;
    arr[1] = 3;

	m_ImageType=-3;
    for (i = 0; i< NUMBER; i++)
    {
        pt1.x=cvRandInt(&rng) % width3 - width;
        pt1.y=cvRandInt(&rng) % height3 - height;
        pt2.x=cvRandInt(&rng) % width3 - width;
        pt2.y=cvRandInt(&rng) % height3 - height;

        cvLine( image, pt1, pt2, random_color(&rng), cvRandInt(&rng)%10, line_type, 0 );
        cvShowImage(wndnamed,image);
        cvWaitKey(DELAY);
    }

    for (i = 0; i< NUMBER; i++)
    {
        pt1.x=cvRandInt(&rng) % width3 - width;
        pt1.y=cvRandInt(&rng) % height3 - height;
        pt2.x=cvRandInt(&rng) % width3 - width;
        pt2.y=cvRandInt(&rng) % height3 - height;

        cvRectangle( image,pt1, pt2, random_color(&rng), cvRandInt(&rng)%10-1, line_type, 0 );
        cvShowImage(wndnamed,image);
        cvWaitKey(DELAY);
    }

    for (i = 0; i< NUMBER; i++)
    {
        pt1.x=cvRandInt(&rng) % width3 - width;
        pt1.y=cvRandInt(&rng) % height3 - height;
        sz.width =cvRandInt(&rng)%200;
        sz.height=cvRandInt(&rng)%200;
        angle = (cvRandInt(&rng)%1000)*0.180;

        cvEllipse( image, pt1, sz, angle, angle - 100, angle + 200,
                   random_color(&rng), cvRandInt(&rng)%10-1, line_type, 0 );
        cvShowImage(wndnamed,image);
        cvWaitKey(DELAY);
    }

    for (i = 0; i< NUMBER; i++)
    {
        pt[0][0].x=cvRandInt(&rng) % width3 - width;
        pt[0][0].y=cvRandInt(&rng) % height3 - height;
        pt[0][1].x=cvRandInt(&rng) % width3 - width;
        pt[0][1].y=cvRandInt(&rng) % height3 - height;
        pt[0][2].x=cvRandInt(&rng) % width3 - width;
        pt[0][2].y=cvRandInt(&rng) % height3 - height;
        pt[1][0].x=cvRandInt(&rng) % width3 - width;
        pt[1][0].y=cvRandInt(&rng) % height3 - height;
        pt[1][1].x=cvRandInt(&rng) % width3 - width;
        pt[1][1].y=cvRandInt(&rng) % height3 - height;
        pt[1][2].x=cvRandInt(&rng) % width3 - width;
        pt[1][2].y=cvRandInt(&rng) % height3 - height;

        cvPolyLine( image, pt, arr, 2, 1, random_color(&rng), cvRandInt(&rng)%10, line_type, 0 );
        cvShowImage(wndnamed,image);
        cvWaitKey(DELAY);
    }

    for (i = 0; i< NUMBER; i++)
    {
        pt[0][0].x=cvRandInt(&rng) % width3 - width;
        pt[0][0].y=cvRandInt(&rng) % height3 - height;
        pt[0][1].x=cvRandInt(&rng) % width3 - width;
        pt[0][1].y=cvRandInt(&rng) % height3 - height;
        pt[0][2].x=cvRandInt(&rng) % width3 - width;
        pt[0][2].y=cvRandInt(&rng) % height3 - height;
        pt[1][0].x=cvRandInt(&rng) % width3 - width;
        pt[1][0].y=cvRandInt(&rng) % height3 - height;
        pt[1][1].x=cvRandInt(&rng) % width3 - width;
        pt[1][1].y=cvRandInt(&rng) % height3 - height;
        pt[1][2].x=cvRandInt(&rng) % width3 - width;
        pt[1][2].y=cvRandInt(&rng) % height3 - height;

        cvFillPoly( image, pt, arr, 2, random_color(&rng), line_type, 0 );
        cvShowImage(wndnamed,image);
        cvWaitKey(DELAY);
    }

    for (i = 0; i< NUMBER; i++)
    {
        pt1.x=cvRandInt(&rng) % width3 - width;
        pt1.y=cvRandInt(&rng) % height3 - height;

        cvCircle( image, pt1, cvRandInt(&rng)%300, random_color(&rng),
                  cvRandInt(&rng)%10-1, line_type, 0 );
        cvShowImage(wndnamed,image);
        cvWaitKey(DELAY);
    }

    for (i = 1; i< NUMBER; i++)
    {
        pt1.x=cvRandInt(&rng) % width3 - width;
        pt1.y=cvRandInt(&rng) % height3 - height;

        cvInitFont( &font, cvRandInt(&rng) % 8,
                    (cvRandInt(&rng)%100)*0.05+0.1, (cvRandInt(&rng)%100)*0.05+0.1, 
                    (cvRandInt(&rng)%5)*0.1, cvRound(cvRandInt(&rng)%10), line_type );

        cvPutText( image, "Testing text rendering!", pt1, &font, random_color(&rng));
        cvShowImage(wndnamed,image);
        cvWaitKey(DELAY);
    }

    cvInitFont( &font, CV_FONT_HERSHEY_COMPLEX, 3, 3, 0.0, 5, line_type );

    cvGetTextSize( "OpenCV forever!", &font, &text_size, &ymin );

    pt1.x = (width - text_size.width)/2;
    pt1.y = (height + text_size.height)/2;
    image2 = cvCloneImage(image);

    for( i = 0; i < 255; i++ )
    {
        cvSubS( image2, cvScalarAll(i), image, 0 );
        cvPutText( image, "OpenCV forever!", pt1, &font, CV_RGB(255,i,i));
        cvShowImage(wndnamed,image);
        cvWaitKey(DELAY);
    }

    // Wait for a key stroke; the same function arranges events processing
    cvWaitKey(0);
    cvReleaseImage(&image);
    cvReleaseImage(&image2);
    cvDestroyWindow(wndnamed);

	m_ImageType=0;
}

//-------------------------------------
//  绘制 Delaunay 图形
//  根据 OpenCV 系统软件程序实例 delaunay.c 改编

CvSubdiv2D* init_delaunay( CvMemStorage* storage,
                           CvRect rect )
{
    CvSubdiv2D* subdiv;

    subdiv = cvCreateSubdiv2D( CV_SEQ_KIND_SUBDIV2D, sizeof(*subdiv),
                               sizeof(CvSubdiv2DPoint),
                               sizeof(CvQuadEdge2D),
                               storage );
    cvInitSubdivDelaunay2D( subdiv, rect );

    return subdiv;
}


void draw_subdiv_point( IplImage* img, CvPoint2D32f fp, CvScalar color )
{
    cvCircle( img, cvPoint(cvRound(fp.x), cvRound(fp.y)), 3, color, CV_FILLED, 8, 0 );
}


void draw_subdiv_edge( IplImage* img, CvSubdiv2DEdge edge, CvScalar color )
{
    CvSubdiv2DPoint* org_pt;
    CvSubdiv2DPoint* dst_pt;
    CvPoint2D32f org;
    CvPoint2D32f dst;
    CvPoint iorg, idst;

    org_pt = cvSubdiv2DEdgeOrg(edge);
    dst_pt = cvSubdiv2DEdgeDst(edge);

    if( org_pt && dst_pt )
    {
        org = org_pt->pt;
        dst = dst_pt->pt;

        iorg = cvPoint( cvRound( org.x ), cvRound( org.y ));
        idst = cvPoint( cvRound( dst.x ), cvRound( dst.y ));

        cvLine( img, iorg, idst, color, 1, CV_AA, 0 );
    }
}


void draw_subdiv( IplImage* img, CvSubdiv2D* subdiv,
                  CvScalar delaunay_color, CvScalar voronoi_color )
{
    CvSeqReader  reader;
    int i, total = subdiv->edges->total;
    int elem_size = subdiv->edges->elem_size;

    cvStartReadSeq( (CvSeq*)(subdiv->edges), &reader, 0 );

    for( i = 0; i < total; i++ )
    {
        CvQuadEdge2D* edge = (CvQuadEdge2D*)(reader.ptr);

        if( CV_IS_SET_ELEM( edge ))
        {
            draw_subdiv_edge( img, (CvSubdiv2DEdge)edge + 1, voronoi_color );
            draw_subdiv_edge( img, (CvSubdiv2DEdge)edge, delaunay_color );
        }

        CV_NEXT_SEQ_ELEM( elem_size, reader );
    }
}


void locate_point( CvSubdiv2D* subdiv, CvPoint2D32f fp, IplImage* img,
                   CvScalar active_color )
{
    CvSubdiv2DEdge e;
    CvSubdiv2DEdge e0 = 0;
    CvSubdiv2DPoint* p = 0;

    cvSubdiv2DLocate( subdiv, fp, &e0, &p );

    if( e0 )
    {
        e = e0;
        do
        {
            draw_subdiv_edge( img, e, active_color );
            e = cvSubdiv2DGetEdge(e,CV_NEXT_AROUND_LEFT);
        }
        while( e != e0 );
    }

    draw_subdiv_point( img, fp, active_color );
}


void draw_subdiv_facet( IplImage* img, CvSubdiv2DEdge edge )
{
    CvSubdiv2DEdge t = edge;
    int i, count = 0;
    CvPoint* buf = 0;

    // count number of edges in facet
    do
    {
        count++;
        t = cvSubdiv2DGetEdge( t, CV_NEXT_AROUND_LEFT );
    } while (t != edge );

    buf = (CvPoint*)malloc( count * sizeof(buf[0]));

    // gather points
    t = edge;
    for( i = 0; i < count; i++ )
    {
        CvSubdiv2DPoint* pt = cvSubdiv2DEdgeOrg( t );
        if( !pt ) break;
        buf[i] = cvPoint( cvRound(pt->pt.x), cvRound(pt->pt.y));
        t = cvSubdiv2DGetEdge( t, CV_NEXT_AROUND_LEFT );
    }

    if( i == count )
    {
        CvSubdiv2DPoint* pt = cvSubdiv2DEdgeDst( cvSubdiv2DRotateEdge( edge, 1 ));
        cvFillConvexPoly( img, buf, count, CV_RGB(rand()&255,rand()&255,rand()&255), CV_AA, 0 );
        cvPolyLine( img, &buf, &count, 1, 1, CV_RGB(0,0,0), 1, CV_AA, 0);
        draw_subdiv_point( img, pt->pt, CV_RGB(0,0,0));
    }
    free( buf );
}

void paint_voronoi( CvSubdiv2D* subdiv, IplImage* img )
{
    CvSeqReader  reader;
    int i, total = subdiv->edges->total;
    int elem_size = subdiv->edges->elem_size;

    cvCalcSubdivVoronoi2D( subdiv );

    cvStartReadSeq( (CvSeq*)(subdiv->edges), &reader, 0 );

    for( i = 0; i < total; i++ )
    {
        CvQuadEdge2D* edge = (CvQuadEdge2D*)(reader.ptr);

        if( CV_IS_SET_ELEM( edge ))
        {
            CvSubdiv2DEdge e = (CvSubdiv2DEdge)edge;
            // left
            draw_subdiv_facet( img, cvSubdiv2DRotateEdge( e, 1 ));

            // right
            draw_subdiv_facet( img, cvSubdiv2DRotateEdge( e, 3 ));
        }

        CV_NEXT_SEQ_ELEM( elem_size, reader );
    }
}

void CCVMFCView::OnDelaunay() 
{
    char win[] = "Delaunay";
    int i;
    CvRect rect = { 0, 0, 600, 600 };
    CvMemStorage* storage;
    CvSubdiv2D* subdiv;
    IplImage* img;
    CvScalar active_facet_color, delaunay_color, voronoi_color, bkgnd_color;

    active_facet_color = CV_RGB( 255, 0, 0 );
    delaunay_color  = CV_RGB( 0,0,0);
    voronoi_color = CV_RGB(0, 180, 0);
    bkgnd_color = CV_RGB(255,255,255);

    img = cvCreateImage( cvSize(rect.width,rect.height), 8, 3 );
    cvSet( img, bkgnd_color, 0 );

    cvNamedWindow( win, 1 );

    storage = cvCreateMemStorage(0);
    subdiv = init_delaunay( storage, rect );

    printf("Delaunay triangulation will be build now interactively.\n"
           "To stop the process, press any key\n\n");

	m_ImageType=-3;
    for( i = 0; i < 200; i++ )
    {
        CvPoint2D32f fp = cvPoint2D32f( (float)(rand()%(rect.width-10)+5),
                                        (float)(rand()%(rect.height-10)+5));

        locate_point( subdiv, fp, img, active_facet_color );
        cvShowImage( win, img );

        if( cvWaitKey( 100 ) >= 0 )
            break;

        cvSubdivDelaunay2DInsert( subdiv, fp );
        cvCalcSubdivVoronoi2D( subdiv );
        cvSet( img, bkgnd_color, 0 );
        draw_subdiv( img, subdiv, delaunay_color, voronoi_color );
        cvShowImage( win, img );

        if( cvWaitKey( 100 ) >= 0 )
            break;
    }

    cvSet( img, bkgnd_color, 0 );
    paint_voronoi( subdiv, img );
    cvShowImage( win, img );

    cvWaitKey(0);

    cvReleaseMemStorage( &storage );
    cvReleaseImage(&img);
    cvDestroyWindow( win );

	m_ImageType=0;
}

//-------------------------------------
//  极坐标变换
//  根据《OpenCV教程(基础篇)》例 5-4 改编

void CCVMFCView::OnLogPolar() 
{
    IplImage* src = 0;

	src = cvCloneImage( workImg );
	cvFlip(src);
 
    IplImage* dst = cvCreateImage( cvSize(src->width/2,src->height/2), 8, 3 );
    IplImage* src2 = cvCreateImage( cvGetSize(src), 8, 3 );
    cvLogPolar( src, dst, cvPoint2D32f(src->width/2,src->height/2), 40, 
		CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS );
    cvLogPolar( dst, src2, cvPoint2D32f(src->width/2,src->height/2), 40, 
		CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS+CV_WARP_INVERSE_MAP );
    cvNamedWindow( "log-polar", 1 );
    cvShowImage( "log-polar", dst );
    cvNamedWindow( "inverse log-polar", 1 );
    cvShowImage( "inverse log-polar", src2 );

    cvWaitKey();
    cvDestroyWindow( "log-polar" );
    cvDestroyWindow( "inverse log-polar" );
    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    cvReleaseImage(&src2);
}

//-------------------------------------
//  DFT
//  根据《OpenCV教程(基础篇)》例 4-2 改编
//  OpenCV 系统软件程序实例 dft.c

// Rearrange the quadrants of Fourier image so that the origin is at
// the image center
// src & dst arrays of equal size & type
void cvShiftDFT(CvArr * src_arr, CvArr * dst_arr )
{
    CvMat * tmp;
    CvMat q1stub, q2stub;
    CvMat q3stub, q4stub;
    CvMat d1stub, d2stub;
    CvMat d3stub, d4stub;
    CvMat * q1, * q2, * q3, * q4;
    CvMat * d1, * d2, * d3, * d4;

    CvSize size = cvGetSize(src_arr);
    CvSize dst_size = cvGetSize(dst_arr);
    int cx, cy;

    if(dst_size.width != size.width || 
       dst_size.height != size.height){
        cvError( CV_StsUnmatchedSizes, "cvShiftDFT", "Source and Destination arrays must have equal sizes", __FILE__, __LINE__ );   
    }

    if(src_arr==dst_arr){
        tmp = cvCreateMat(size.height/2, size.width/2, cvGetElemType(src_arr));
    }
    
    cx = size.width/2;
    cy = size.height/2; // image center

    q1 = cvGetSubRect( src_arr, &q1stub, cvRect(0,0,cx, cy) );
    q2 = cvGetSubRect( src_arr, &q2stub, cvRect(cx,0,cx,cy) );
    q3 = cvGetSubRect( src_arr, &q3stub, cvRect(cx,cy,cx,cy) );
    q4 = cvGetSubRect( src_arr, &q4stub, cvRect(0,cy,cx,cy) );
    d1 = cvGetSubRect( src_arr, &d1stub, cvRect(0,0,cx,cy) );
    d2 = cvGetSubRect( src_arr, &d2stub, cvRect(cx,0,cx,cy) );
    d3 = cvGetSubRect( src_arr, &d3stub, cvRect(cx,cy,cx,cy) );
    d4 = cvGetSubRect( src_arr, &d4stub, cvRect(0,cy,cx,cy) );

    if(src_arr!=dst_arr){
        if( !CV_ARE_TYPES_EQ( q1, d1 )){
            cvError( CV_StsUnmatchedFormats, "cvShiftDFT", "Source and Destination arrays must have the same format", __FILE__, __LINE__ ); 
        }
        cvCopy(q3, d1, 0);
        cvCopy(q4, d2, 0);
        cvCopy(q1, d3, 0);
        cvCopy(q2, d4, 0);
    }
    else{
        cvCopy(q3, tmp, 0);
        cvCopy(q1, q3, 0);
        cvCopy(tmp, q1, 0);
        cvCopy(q4, tmp, 0);
        cvCopy(q2, q4, 0);
        cvCopy(tmp, q2, 0);
    }
}

void CCVMFCView::OnDft() 
{
//    const char* filename = "image\\lena.jpg";
    IplImage * im;

    IplImage * realInput;
    IplImage * imaginaryInput;
    IplImage * complexInput;
    int dft_M, dft_N;
    CvMat* dft_A, tmp;
    IplImage * image_Re;
    IplImage * image_Im;
    double m, M;

	if (workImg->nChannels==3) {
 		im = cvCreateImage(cvGetSize(workImg), IPL_DEPTH_8U, 1);
		cvCvtColor(workImg, im, CV_BGR2GRAY);
	}
	else {
        im = cvCloneImage( workImg );
	}
	cvFlip(im);

    realInput = cvCreateImage( cvGetSize(im), IPL_DEPTH_64F, 1);
    imaginaryInput = cvCreateImage( cvGetSize(im), IPL_DEPTH_64F, 1);
    complexInput = cvCreateImage( cvGetSize(im), IPL_DEPTH_64F, 2);

    cvScale(im, realInput, 1.0, 0.0);
    cvZero(imaginaryInput);
    cvMerge(realInput, imaginaryInput, NULL, NULL, complexInput);

    dft_M = cvGetOptimalDFTSize( im->height - 1 );
    dft_N = cvGetOptimalDFTSize( im->width - 1 );

    dft_A = cvCreateMat( dft_M, dft_N, CV_64FC2 );
    image_Re = cvCreateImage( cvSize(dft_N, dft_M), IPL_DEPTH_64F, 1);
    image_Im = cvCreateImage( cvSize(dft_N, dft_M), IPL_DEPTH_64F, 1);

    // copy A to dft_A and pad dft_A with zeros
    cvGetSubRect( dft_A, &tmp, cvRect(0,0, im->width, im->height));
    cvCopy( complexInput, &tmp, NULL );
    if( dft_A->cols > im->width )
    {
        cvGetSubRect( dft_A, &tmp, cvRect(im->width,0, dft_A->cols - im->width, im->height));
        cvZero( &tmp );
    }

    // no need to pad bottom part of dft_A with zeros because of
    // use nonzero_rows parameter in cvDFT() call below

    cvDFT( dft_A, dft_A, CV_DXT_FORWARD, complexInput->height );

    cvNamedWindow("win", 0);
    cvNamedWindow("magnitude", 0);
    cvShowImage("win", im);

    // Split Fourier in real and imaginary parts
    cvSplit( dft_A, image_Re, image_Im, 0, 0 );

    // Compute the magnitude of the spectrum Mag = sqrt(Re^2 + Im^2)
    cvPow( image_Re, image_Re, 2.0);
    cvPow( image_Im, image_Im, 2.0);
    cvAdd( image_Re, image_Im, image_Re, NULL);
    cvPow( image_Re, image_Re, 0.5 );

    // Compute log(1 + Mag)
    cvAddS( image_Re, cvScalarAll(1.0), image_Re, NULL ); // 1 + Mag
    cvLog( image_Re, image_Re ); // log(1 + Mag)


    // Rearrange the quadrants of Fourier image so that the origin is at
    // the image center
    cvShiftDFT( image_Re, image_Re );

    cvMinMaxLoc(image_Re, &m, &M, NULL, NULL, NULL);
    cvScale(image_Re, image_Re, 1.0/(M-m), 1.0*(-m)/(M-m));
    cvShowImage("magnitude", image_Re);

    cvWaitKey(-1);
    cvDestroyWindow( "win" );
    cvDestroyWindow( "magnitude" );

    cvReleaseImage(&im);
    cvReleaseImage(&realInput);
    cvReleaseImage(&imaginaryInput);
    cvReleaseImage(&complexInput);
    cvReleaseImage(&image_Re);
    cvReleaseImage(&image_Im);
}




