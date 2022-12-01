#ifndef MEMBERCONVERSIONSWIDGET_H
#define MEMBERCONVERSIONSWIDGET_H

#include <QWidget>

namespace Ui {
class MemberConversions;
}

class MemberConversions : public QWidget
{
		Q_OBJECT

public:
		explicit MemberConversions(QWidget *parent = nullptr);
		~MemberConversions();

private:
		Ui::MemberConversions *ui;
};

#endif // MEMBERCONVERSIONSWIDGET_H
