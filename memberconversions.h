#ifndef MEMBERCONVERSIONS_H
#define MEMBERCONVERSIONS_H

#include <QDialog>

namespace Ui {
class MemberConversions;
}

class MemberConversions : public QDialog
{
		Q_OBJECT

public:
		explicit MemberConversions(QWidget *parent = nullptr);
		~MemberConversions();

private:
		Ui::MemberConversions *ui;
};

#endif // MEMBERCONVERSIONS_H
