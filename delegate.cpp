/****************************************************************************
 **INFO: clase de delegate para validar la entrada en una QTableView
 **
 **
 ** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 ** All rights reserved.
 ** Contact: Nokia Corporation (qt-info@nokia.com)
 **
 ** This file is part of the examples of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:LGPL$
 ** Commercial Usage
 ** Licensees holding valid Qt Commercial licenses may use this file in
 ** accordance with the Qt Commercial License Agreement provided with the
 ** Software or, alternatively, in accordance with the terms contained in
 ** a written agreement between you and Nokia.
 **
 ** GNU Lesser General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU Lesser
 ** General Public License version 2.1 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.LGPL included in the
 ** packaging of this file.  Please review the following information to
 ** ensure the GNU Lesser General Public License version 2.1 requirements
 ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 **
 ** In addition, as a special exception, Nokia gives you certain additional
 ** rights.  These rights are described in the Nokia Qt LGPL Exception
 ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
 **
 ** GNU General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU
 ** General Public License version 3.0 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.GPL included in the
 ** packaging of this file.  Please review the following information to
 ** ensure the GNU General Public License version 3.0 requirements will be
 ** met: http://www.gnu.org/copyleft/gpl.html.
 **
 ** If you have questions regarding the use of this file, please contact
 ** Nokia at qt-info@nokia.com.
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

 /*
     delegate.cpp
 */

 #include <QtGui>
 #include <QDebug>

 #include "delegate.h"

 lineEditDelegate::lineEditDelegate(QObject *parent)
     : QItemDelegate(parent)
 {
 }


 /*Este metodo es llamado por el QTableView al mostrarse en pantalla.
    Aqui se define el widget que se instanciara en cada celda.*/


 QWidget *lineEditDelegate::createEditor(QWidget *parent,
     const QStyleOptionViewItem &/* option */,
     const QModelIndex &/* index */) const
 {
     QLineEdit *editor = new QLineEdit(parent);
     //editor->setInputMask();  //TODO: validar!

     return editor;
 }

 /*Este metodo es llamado cuando el valor de una celda debe actualizarse en pantalla (por ejemplo
    debido a un cambio en la base de datos). Es decir, un cambio no realizado por el usuario*/

 void lineEditDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
 {
     QString value = index.model()->data(index, Qt::EditRole).toString();

     QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
     lineEdit->setText(value);
 }


 /*Este metodo es llamado cuando el usuario cambia una celda, desde aqui se envia el cambio al modelo*/
 void lineEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
 {
     QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);

     QString value = lineEdit->text();
     QVariant lastValue = model->data(index); /*Guardo el ultimo valor de la celda
                                              que estoy editando*/
     bool ok;

     value.toInt(&ok);


     /****************************************************************``****************************/
     /********************************************************************************************/
     /*Validacion correspondiente a cada columna. (Seguro que hay un lugar mejor para hacer esto)*/
     /********************************************************************************************/
     if (( (index.column() == 2/* temp */) && (!ok) ) || ( (value.toInt() <= 0) && (ok) ) )
     {
         qDebug() << "value.toInt(): " << value.toInt();
         value = lastValue.toString();
         //qDebug() << "index.column() == 3? => " << index.column();

     }

     if ( ( (index.column() == 3/* dias */) && (!ok) ) || ( (value.toInt() < 0) && (ok) ) )
     {
         qDebug() << "value.toInt(): " << value.toInt();
         value = lastValue.toString();
         //qDebug() << "index.column() == 4? => " << index.column();
     }

//     if ( ( (index.column() == 4/* horas */) && (!ok) ) || ( (value.toInt() < 0) && (ok) ) )
//     {
//         qDebug() << "value.toInt(): " << value.toInt();
//         value = lastValue.toString();
//         //qDebug() << "index.column() == 5? => " << index.column();
//     }

     if ( ( (index.column() == 5/* minutos */) && (!ok) ) || ( (value.toInt() < 0) && (ok) ) )
     {
         qDebug() << "value.toInt(): " << value.toInt();
         value = lastValue.toString();
         //qDebug() << "index.column() == 6? => " << index.column();
     }


     /********************************************************************************************/
     /*Termina la validacion**********************************************************************/
     /********************************************************************************************/
     /********************************************************************************************/

     model->setData(index, value, Qt::EditRole);
 }


 void lineEditDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
 {
     editor->setGeometry(option.rect);
 }
