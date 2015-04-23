#ifndef EFUSEBOARDWIDGETPLUGIN_HPP
#define EFUSEBOARDWIDGETPLUGIN_HPP

#include <QtGui>
#include <QtDesigner/QDesignerCustomWidgetInterface>

class EFuseBoardWidgetPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    EFuseBoardWidgetPlugin(QObject *parent = 0);
    virtual ~EFuseBoardWidgetPlugin();

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget* createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool initialized; 
};

#endif /* EFUSEBOARDWIDGETPLUGIN_HPP */  
