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

#ifndef OOML_REFSYSIEW_H_INCLUDED
#define OOML_REFSYSIEW_H_INCLUDED

#ifdef WIN32
#ifdef OOMLComponents_EXPORTS
#define OOMLComponents_EXP_DEC __declspec(dllexport)
#else
#define OOMLComponents_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLComponents_EXP_DEC
#endif


#include "../core/IndentWriter.h"
#include "../core/RefSys.h"
#include "../core/Component.h"
#include <math.h>

#include <utility>

/**
 * \brief 3D point primitive object
 *
 * This class provides a 3D point.
 */
class OOMLComponents_EXP_DEC RefSysView : public Component
{
public:
	/**
	 * \brief Default constructor.
	 */
    RefSysView() : _refSys()
    {
        set(genComponent().get());
    }
	/**
     * \brief constructor.
	 *
     * \param other Build from a RefSys.
	 */

    RefSysView(RefSys const & ref) :
        _refSys(ref)
    {
        set(genComponent().get());
    }

    RefSysView(RefSysView const & other):
        _refSys(other._refSys)
    {
        set(genComponent().get());
    }


	/**
	 * \brief Default destructor.
	 */
    virtual ~RefSysView() {}

private:
  RefSys _refSys;
  Component genComponent();
};

#endif // OOML_REFSYSIEW_H_INCLUDED
