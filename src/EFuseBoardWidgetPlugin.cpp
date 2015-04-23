#include "EFuseBoardWidgetPlugin.hpp"
#include "EFuseBoardWidget.hpp"

Q_EXPORT_PLUGIN2(EFuseBoardWidget, EFuseBoardWidgetPlugin)

EFuseBoardWidgetPlugin::EFuseBoardWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

EFuseBoardWidgetPlugin::~EFuseBoardWidgetPlugin()
{
}

bool EFuseBoardWidgetPlugin::isContainer() const
{
    return false;
}

bool EFuseBoardWidgetPlugin::isInitialized() const
{
    return initialized;
}

QIcon EFuseBoardWidgetPlugin::icon() const
{
    return QIcon("");
}

QString EFuseBoardWidgetPlugin::domXml() const
{
        return "<ui language=\"c++\">\n"
            " <widget class=\"EFuseBoardWidget\" name=\"efuseboard\">\n"
            "  <property name=\"geometry\">\n"
            "   <rect>\n"
            "    <x>0</x>\n"
            "    <y>0</y>\n"
            "     <width>520</width>\n"
            "     <height>625</height>\n"
            "   </rect>\n"
            "  </property>\n"
//            "  <property name=\"toolTip\" >\n"
//            "   <string>EFuseBoardWidget</string>\n"
//            "  </property>\n"
//            "  <property name=\"whatsThis\" >\n"
//            "   <string>EFuseBoardWidget</string>\n"
//            "  </property>\n"
            " </widget>\n"
            "</ui>\n";
}

QString EFuseBoardWidgetPlugin::group() const {
    return "Rock-Robotics";
}

QString EFuseBoardWidgetPlugin::includeFile() const {
    return "EFuseBoardWidget/EFuseBoardWidget.hpp";
}

QString EFuseBoardWidgetPlugin::name() const {
    return "EFuseBoardWidget";
}

QString EFuseBoardWidgetPlugin::toolTip() const {
    return whatsThis();
}

QString EFuseBoardWidgetPlugin::whatsThis() const
{
    return "";
}

QWidget* EFuseBoardWidgetPlugin::createWidget(QWidget *parent)
{
    return new EFuseBoardWidget(parent);
}

void EFuseBoardWidgetPlugin::initialize(QDesignerFormEditorInterface *core)
{
     if (initialized)
         return;
     initialized = true;
}
