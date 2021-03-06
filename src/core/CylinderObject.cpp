/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Juan Gonzalez-Gomez, Alberto Valero-Gomez, Rafael Trevio
 *
 * OOML is licenced under the Common Creative License,
 * Attribution-ShareAlike 3.0
 *
 * You are free:
 *   - to Share - to copy, distribute and transmit the work
 *   - to Remix - to adapt the work
 *
 * Under the following conditions:
 *   - Attribution. You must attribute the work in the manner specified
 *     by the author or licensor (but not in any way that suggests that
 *     they endorse you or your use of the work).
 *   - Share Alike. If you alter, transform, or build upon this work,
 *     you may distribute the resulting work only under the same or
 *     similar license to this one.
 *
 * Any of the above conditions can be waived if you get permission
 * from the copyright holder.  Nothing in this license impairs or
 * restricts the author's moral rights.
 *
 * It is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 **********************************************************************/

#include "CylinderObject.h"
#include "IndentWriter.h"

#include <iostream>

void CylinderObject::genScad(IndentWriter& writer) const
{
    writer << "cylinder(h=" << _height <<", r1=" << _radius1 <<", r2=" << _radius2 << ", $fn=" << _faces
        << ", center=" << _center << ");" << std::endl;
}

void CylinderObject::printAst(IndentWriter& writer) const
{
    writer << "// CYLINDER(" << _height << ", " << _radius1 << ", " << _radius2 << ", " << _faces << ", " << _center << ")" << std::endl;
}
