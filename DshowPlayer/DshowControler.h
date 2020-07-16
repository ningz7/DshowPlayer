#pragma once

#include <QObject>
#include <QStringList>
#include <QPixmap>
#include <QVariant>

class QWidget;
class IMoniker;
class CaptureVideo;

extern "C"
{
	struct AVCodecContext;
	struct AVFrame;
	struct SwsContext;
}

class DshowControler : public QObject
{
	Q_OBJECT

public:
	DshowControler(QVariantMap params);
	~DshowControler();

	bool setParams();

private:
	void ReleaseMoniker();
	void EnumDevices();
	void OpenDevice();

signals:
	void updateDevNameList(QStringList);
	void finished();
	void updateImage(QPixmap img);

public slots:
	void startPlay();
	void process();

private:
	IMoniker *m_rgpmVideo[10];
	CaptureVideo *m_pCaptureVideo = nullptr;
	QStringList m_devNameList;

	int m_nCurDev = -1;	// ��ǰ�豸index

	//AVFrame *m_rgbFrame = nullptr;
	//uint8_t *m_rgbFrameBuf = nullptr;
	//SwsContext *m_swsCtx = nullptr;

	int m_srcWidth = 1920;
	int m_dstHeight = 1080;

	int m_dstWinWidth;	// Ŀ�괰�ڿ��
	int m_dstWinHeight;	// Ŀ�괰�ڸ߶�

    bool m_paused = false;
    bool m_stopped = false;
    int m_duration = 0;

    QWidget *m_wid = nullptr;
};
