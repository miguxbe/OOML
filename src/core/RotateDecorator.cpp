/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Juan Gonzalez-Gomez, Alberto Valero-Gomez, Rafael Trevi�o
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

#include <core/RotateDecorator.h>
#include <core/IndentWriter.h>

void RotateDecorator::genScad(IndentWriter& writer) const
{
	if (_vx == 0.0 && _vy == 0.0 && _vz == 0)
	{
		writer << "rotate(a=[" << _ax << ", " << _ay << ", " << _az << "]) {"
			<< std::endl;
	}
	else
	{
		writer << "rotate(a=" << _ax << ", v=[" << _vx << ", " << _vy << ", "
			<< _vz << "]) {" << std::endl;
	}
	{
		IndentBlock block(writer);
		ObjectDecorator::genScad(writer);
	}
	writer << "} // End rotate" << std::endl;
}

void RotateDecorator::printAst(IndentWriter& writer) const
{
	if (_vx == 0.0 && _vy == 0.0 && _vz == 0)
	{
		writer << "ROTATE(" << _ax << ", " << _ay << ", " << _az << ")"
			<< std::endl;
	}
	else
	{
		writer << "ROTATE(" << _ax << ", " << _vx << ", " << _vy << ", "
			<< _vz << ")" << std::endl;
	}
	ObjectDecorator::printAst(writer);
}
