/***************************************************************************
* Copyright (C) 2014 by Renaud Guezennec                                   *
* http://renaudguezennec.homelinux.org/accueil,3.html                      *
*                                                                          *
*  This file is part of DiceParser                                         *
*                                                                          *
* DiceParser is free software; you can redistribute it and/or modify       *
* it under the terms of the GNU General Public License as published by     *
* the Free Software Foundation; either version 2 of the License, or        *
* (at your option) any later version.                                      *
*                                                                          *
* This program is distributed in the hope that it will be useful,          *
* but WITHOUT ANY WARRANTY; without even the implied warranty of           *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the             *
* GNU General Public License for more details.                             *
*                                                                          *
* You should have received a copy of the GNU General Public License        *
* along with this program; if not, write to the                            *
* Free Software Foundation, Inc.,                                          *
* 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.                 *
***************************************************************************/
#include "booleancondition.h"


BooleanCondition::BooleanCondition()
{
}
qint64 BooleanCondition::hasValid(Die* b,bool recursive) const
{
    QList<qint64> listValues;
    if(recursive)
    {
        listValues = b->getListValue();
    }
    else
    {
        listValues.append(b->getLastRolledValue());
    }

    qint64 sum= 0;
    foreach(qint64 value, listValues)
    {

        switch(m_operator)
        {
            case Equal:
                sum+=(value==m_value)?1:0;
                break;
            case GreaterThan:
                sum+= (value>m_value)?1:0;
                break;
            case LesserThan:
                sum+= (value<m_value)?1:0;
                break;
            case GreaterOrEqual:
                sum+= (value>=m_value)?1:0;
                break;
            case LesserOrEqual:
                sum+= (value<=m_value)?1:0;
                break;


        }
    }

    return sum;
}

void BooleanCondition::setOperator(LogicOperator m)
{
    m_operator = m;
}

void BooleanCondition::setValue(qint64 v)
{
    m_value=v;
}
QString BooleanCondition::toString()
{
    return QString("BooleanCondition_op_%1_value_%2").arg(m_operator).arg(m_value);
}
