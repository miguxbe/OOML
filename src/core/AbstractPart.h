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

#ifndef ABSTRACTPART_H_INCLUDED
#define ABSTRACTPART_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include <core/Component.h>

#define PART_MARGIN 0.1

class IndentWriter;

/**
 * \brief Color decorator.
 *
 * This class provides a color decoration for an object.
 */
class OOMLCore_EXP_DEC AbstractPart : public Component
{
public:
	/**
	 * \brief Rebuild the part.
	 *
	 * This method rebuilds the part.
	 */
	void rebuild()
	{
		set(build().get());
	}

	/**
	 * \brief Generate SCAD output for this object.
	 *
	 * This method allow the object to write the SCAD code
	 * to the indent writer provided. The writer must be at the
	 * beggining of a line when leaving the method.
	 *
	 * \param writer An instance of indent writer to write to.
	 */
	virtual void genScad(IndentWriter& writer) const;
	/**
	 * \brief Generate AST output for this object.
	 *
	 * This method allow the object to write the AST code
	 * to the indent writer provided. The writer must be at the
	 * beggining of a line when leaving the method.
	 *
	 * \param writer An instance of indent writer to write to.
	 */
	virtual void printAst(IndentWriter& writer) const;

protected:
	/**
	 * \brief Default constructor.
	 */
	AbstractPart() :
		Component()
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~AbstractPart() {}

	/**
	 * \brief Build the part.
	 *
	 * This method build the part from simpler objects.
	 *
	 * \return The part built.
	 */
	virtual Component build() = 0;

  /**
   * \note Delete 'private' will not change anything because the
   * next declarations have no definition, so are useless.
   * Are only declared to enforce them as private and prevent
   * further use in other parts of the code.
   */
	/**
	 * \note The problem is that on Mac OS/X does not compile if
	 * it is private. We will see how to fix this. By now,
	 * better like that. Otherwise I get several mails every day
	 * saying the same.
	 * alberto :P
	 */
	/**
	 * \note The problem is without it, doesn't compile under WIN32,
	 * so, by now, and temporary, the private thing will be only
	 * defined in WIN32, leaving Unix-like systems without it.
	 */
#ifdef WIN32
private:
#endif
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	AbstractPart(AbstractPart const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	AbstractPart & operator=(AbstractPart const& other);
};

#endif // ABSTRACTPART_H_INCLUDED
