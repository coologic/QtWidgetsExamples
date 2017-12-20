#ifndef TITLEBAR_H
#define TITLEBAR_H
#include <QToolBar>
class TitleBarPrivate;
class TitleBar : public QToolBar {
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = Q_NULLPTR);
protected:
    /**
     * @brief 被双击--标题栏被双击，放大还原
     * @param event 事件
     */
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    /**
     * @brief 鼠标按下--拖拽移动效果
     * @param event 事件
     */
    virtual void mousePressEvent(QMouseEvent *event);
    /**
     * @brief 鼠标抬起--拖拽移动效果
     * @param event 事件
     */
    virtual void mouseReleaseEvent(QMouseEvent *event);
    /**
     * @brief 鼠标移动--拖拽移动效果
     * @param event 事件
     */
    virtual void mouseMoveEvent(QMouseEvent *event);
    /**
     * @brief 事件过滤--修改题目、图标等操作
     * @param obj
     * @param event
     * @return
     */
    virtual bool eventFilter(QObject *obj, QEvent *event);
private slots:
    /**
     * @brief 最大化按钮被点击槽
     *      当前已经最大化则还原，未最大化则最大化
     *      系统还原和最大化分为两个槽不能直接connect故建立此槽
     */
    void MaximizeButtonClicked();
private:
    TitleBarPrivate *m_private;
};

#endif // TITLEBAR_H
