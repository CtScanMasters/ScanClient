#ifndef SCATTERWIDGET_H
#define SCATTERWIDGET_H

#include <QWidget>
#include <QtDataVisualization/q3dscatter.h>
#include <QtDataVisualization/QScatterDataProxy>
#include <QtDataVisualization/QValue3DAxis>
#include <QtDataVisualization/Q3DScene>
#include <QtDataVisualization/Q3DCamera>
#include <QtDataVisualization/QScatter3DSeries>
#include <QtDataVisualization/Q3DTheme>
#include <QtCore/qmath.h>
#include <QtCore/QTextStream>
#include <QtCore/QDebug>
#include <QtGui/QFont>
#include <QtCore/QTimer>
#include <QtCore/QPropertyAnimation>
#include <QtCore/QSequentialAnimationGroup>
#include <QtGui/QVector3D>
#include <QLabel>
#include <QVBoxLayout>


using namespace QtDataVisualization;

class ScatterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScatterWidget(QWidget *parent = 0);
    ~ScatterWidget();

    enum axisName
    {
        x_Axis, y_Axis, z_Axis
    };

    void setAxisRange(int axis, float min, float max);
    void setAxisGrid(int axis, int mainGrid, int subGrid);
    void setTheme(int themeSelection);
    void setPointSize(float size);
    void setData(QScatterDataArray &scatterArray);

private:

    Q3DScatter *m_graph;
    QString m_logName;
    QValue3DAxis *m_xAxis;
    QValue3DAxis *m_yAxis;
    QValue3DAxis *m_zAxis;
    QScatter3DSeries *m_graphSerie;
    QScatterDataProxy *m_dataProxy;
    Q3DTheme *m_graphTheme;
    QList<QColor> m_colorList;

    QWidget *m_graphWidgetContainer;
    QVBoxLayout *m_verticalLayout;    

};

#endif // SCATTERWIDGET_H
