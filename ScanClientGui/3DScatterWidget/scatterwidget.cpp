#include "scatterwidget.h"
#include <QDebug>

ScatterWidget::ScatterWidget(QWidget *parent) :
    QWidget(parent)
{
    m_logName = "ScatterWidget : ";

    qInfo() << m_logName + "creating graph";

    //Create graph
    m_graph = new Q3DScatter();
    m_graph->setShadowQuality(QAbstract3DGraph::ShadowQualityNone);
    m_graph->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetIsometricLeft);

    //Create graph axis
    m_xAxis = new QValue3DAxis(this);
    m_yAxis = new QValue3DAxis(this);
    m_zAxis = new QValue3DAxis(this);

    m_xAxis->setTitle("X-axis");    
    m_xAxis->setTitleVisible(true);
    m_yAxis->setTitle("Y-axis");
    m_yAxis->setTitleVisible(true);
    m_zAxis->setTitle("Z-axis");
    m_zAxis->setTitleVisible(true);

    m_graph->setAxisX(m_xAxis);
    m_graph->setAxisY(m_yAxis);
    m_graph->setAxisZ(m_zAxis);

    //Create graph axis attributes
    m_graphSerie = new QScatter3DSeries(this);
    m_graphSerie->setItemLabelFormat(QStringLiteral("@xLabel, @yLabel, @zLabel"));
    m_graphSerie->setMesh(QAbstract3DSeries::MeshCube);
    m_graph->addSeries(m_graphSerie);


    //Set the dataProxy
    m_dataProxy = new QScatterDataProxy(this);
    m_graphSerie->setDataProxy(m_dataProxy);

    //Create theme
    m_graphTheme = new Q3DTheme(this);
    m_graphTheme->setAmbientLightStrength(0.3f);
    m_graphTheme->setBackgroundColor(QColor::fromRgb(150,150,150));
    m_graphTheme->setBackgroundEnabled(true);
    m_graphTheme->setColorStyle(Q3DTheme::ColorStyleUniform);
    m_graphTheme->setFont(QFont(QStringLiteral("Impact"), 15));
    m_graphTheme->setGridEnabled(true);
    m_graphTheme->setGridLineColor(QColor::fromRgb(255,255,255));
    m_graphTheme->setHighlightLightStrength(1.0f);
    m_graphTheme->setLabelBackgroundColor(QColor::fromRgb(255,255,255));
    m_graphTheme->setLabelBackgroundEnabled(false);
    m_graphTheme->setLabelBorderEnabled(false);
    m_graphTheme->setLabelTextColor(QColor::fromRgb(150,150,150));
    m_graphTheme->setLightColor(Qt::white);
    m_graphTheme->setLightStrength(2.0f);
    m_graphTheme->setMultiHighlightColor(QColor(QRgb(0x6d5fd5)));
    m_graphTheme->setSingleHighlightColor(QColor(QRgb(0xf6a625)));
    m_graphTheme->setWindowColor(QColor::fromRgb(0,0,0));

    m_colorList.append(QColor::fromRgb(255,50,255));
    m_graphTheme->setBaseColors(m_colorList);

    //Do the default cosmetics
    for(int i = 0; i < 3; i++)
    {
        setAxisRange(i, -10, 10);
        setAxisGrid(i, 10, 5);
    }
    m_graph->setActiveTheme(m_graphTheme);
    setPointSize(0.1f);

    //Add graph to widget container
    m_graphWidgetContainer = QWidget::createWindowContainer(m_graph);

    //Create layout
    m_verticalLayout = new QVBoxLayout(this);
    m_verticalLayout->addWidget(m_graphWidgetContainer);

}

ScatterWidget::~ScatterWidget()
{
    delete m_graph;
}

void ScatterWidget::setAxisRange(int axis, float min, float max)
{

    switch(axis)
    {
        case 0: {
                    m_xAxis->setRange(min, max);
                    break;
                }

        case 1: {
                     m_yAxis->setRange(min, max);
                    break;
                }

        case 2: {
                    m_zAxis->setRange(min, max);
                    break;
                }
        default: //Make error here
                 break;
    }

    qInfo() << m_logName + QString("axis %1 range set: %2 - %3").arg(axis).arg(min).arg(max);

}

void ScatterWidget::setAxisGrid(int axis, int mainGrid, int subGrid)
{

    switch(axis)
    {
        case 0: {
                    m_xAxis->setSegmentCount(mainGrid);
                    m_xAxis->setSubSegmentCount(subGrid);
                    break;
                }

        case 1: {
                    m_yAxis->setSegmentCount(mainGrid);
                    m_yAxis->setSubSegmentCount(subGrid);
                    break;
                }

        case 2: {
                    m_zAxis->setSegmentCount(mainGrid);
                    m_zAxis->setSubSegmentCount(subGrid);
                    break;
                }
        default: //Make error here
                 break;
    }

    qInfo() << m_logName + QString("grid %1 main: %2 sub: %3").arg(axis).arg(mainGrid).arg(subGrid);

}

void ScatterWidget::setTheme(int themeSelection)
{
    Q3DTheme::Theme theme = Q3DTheme::Theme(themeSelection);

    m_graph->activeTheme()->setType(theme);

    qInfo() << m_logName << Q_FUNC_INFO;
}

void ScatterWidget::setPointSize(float size)
{
    m_graphSerie->setItemSize(size);

    qInfo() << m_logName << Q_FUNC_INFO;
}

void ScatterWidget::setData(QScatterDataArray &scatterArray)
{
    m_dataProxy->removeItems(0, m_dataProxy->itemCount());
    m_dataProxy->addItems(scatterArray);

    qInfo() << m_logName << Q_FUNC_INFO;
}
