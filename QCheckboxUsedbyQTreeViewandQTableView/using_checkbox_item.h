/**
 * @file using_checkbox_item.h
 * @brief 本文件包含支持复选框item类声明。
 * @version 1.0.0.0
 * @date 2017.12.18
 * @author Techie亮
 */
#ifndef _H_USINGCHECKBOXITEM_
#define _H_USINGCHECKBOXITEM_
#include <QStandardItem>
#include <QString>
/**
 * @brief 支持复选框item类
 *   支持复选框三态转变-全选对勾、全不选空白、半选黑点
 *   子类会自动通知父子节点item，若不符合设计需要可仿照此方式在model中的setDate重现
 */
class UsingCheckboxItem : public QStandardItem {
public:
    /**
     * @brief 构造函数
     * @param item显示内容
     */
    explicit UsingCheckboxItem(const QString &text);
    /**
     * @brief setData重写
     * @param value data值
     * @param role data类型
     */
    virtual void setData(const QVariant &value, int role = Qt::UserRole + 1);
};
#endif // _H_USINGCHECKBOXITEM_
