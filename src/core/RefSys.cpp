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

#include "RefSys.h"
#include "Union.h"
#include "IndentWriter.h"

#include <iostream>

void RefSys::translate(double x, double y, double z){
    _origin = _origin + Translation(x,y,z);
}

void RefSys::rotate(double x, double y, double z){
    _rot.rotateFixedXYZ(x,y,z);
}

void RefSys::rotateEulerZYZ(double z, double yp, double zpp){
    _rot.rotateEulerZYZ(z,yp,zpp);
}

void RefSys::rotateEulerZXZ(double z, double xp, double zpp){
    _rot.rotateEulerZXZ(z,xp,zpp);
}
