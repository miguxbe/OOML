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

#ifndef ROUNDEDCUBE_H_INCLUDED
#define ROUNDEDCUBE_H_INCLUDED

#ifdef WIN32
#ifdef OOMLComponents_EXPORTS
#define OOMLComponents_EXP_DEC __declspec(dllexport)
#else
#define OOMLComponents_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLComponents_EXP_DEC
#endif

#include <components/Cube.h>
#include <components/Cylinder.h>
#include <components/Sphere.h>
#include <core/Union.h>

/**
 * \brief Rounded cube primitive object
 *
 * This class provides a rounded cube.
 */
class OOMLComponents_EXP_DEC RoundedCube: public Component
{
public:
	/**
	 * \brief Constructor
	 *
	 * Creates a rounded cube.
	 *
	 * \param sx Cube dimension in the x axis.
	 * \param sy Cube dimension in the y axis.
	 * \param sz Cube dimension in the z axis.
	 * \param radius Cube corner radius.
	 * \param faces Number of faces of the rendered rounded cube.
	 * \param center Centered cube flag.
	 *
	 */
	RoundedCube(double sx, double sy, double sz, double radius, unsigned int faces=100, bool center=true) :
		Component()
	{
		if (radius > sx / 2)
			radius = sx / 2;
		if (radius > sy / 2)
			radius = sy / 2;
		if (radius > sz / 2)
			radius = sz / 2;

	 Component body(Cube(sx-2*radius , sy-2*radius , sz-2*radius));

	 Component flat_updown(Cube(sx-2*radius , sy-2*radius , 2*radius));
	 Component flat_rightleft(Cube(sx-2*radius , 2*radius , sz-2*radius));
	 Component flat_frontback(Cube(2*radius , sy-2*radius , sz-2*radius));

    Component round_cube = body
			+ flat_updown.translatedCopy(0,0,sz/2-radius)
			+ flat_updown.translatedCopy(0,0,-(sz/2-radius))
			+ flat_rightleft.translatedCopy(0,sy/2-radius,0)
			+ flat_rightleft.translatedCopy(0,-(sy/2-radius),0)
			+ flat_frontback.translatedCopy(sx/2-radius,0,0)
			+ flat_frontback.translatedCopy(-(sx/2-radius),0,0);

	 Component round_sidex(Cylinder(radius,sx-2*radius).rotate(0,90,0));
	 Component round_sidey(Cylinder(radius,sy-2*radius).rotate(90,0,0));
	 Component round_sidez(Cylinder(radius,sz-2*radius));

    round_cube = round_cube
			+ round_sidex.translatedCopy(0,sy/2-radius,sz/2-radius)
			+ round_sidex.translatedCopy(0,-(sy/2-radius),sz/2-radius)
			+ round_sidex.translatedCopy(0,sy/2-radius,-(sz/2-radius))
			+ round_sidex.translatedCopy(0,-(sy/2-radius) ,-(sz/2-radius))

			+ round_sidey.translatedCopy(sx/2-radius, 0 , sz/2-radius)
			+ round_sidey.translatedCopy(-(sx/2-radius), 0, sz/2-radius)
			+ round_sidey.translatedCopy(sx/2-radius, 0, -(sz/2-radius))
			+ round_sidey.translatedCopy(-(sx/2-radius), 0 ,-(sz/2-radius))

			+ round_sidez.translatedCopy(sx/2-radius, sy/2-radius,0)
			+ round_sidez.translatedCopy(-(sx/2-radius), sy/2-radius,0)
			+ round_sidez.translatedCopy(sx/2-radius, -(sy/2-radius),0)
			+ round_sidez.translatedCopy(-(sx/2-radius), -(sy/2-radius),0);

		Component round_corner = Sphere(radius);

    round_cube = round_cube
			+ round_corner.translatedCopy(sx/2 - radius , sy/2 -radius , sz/2 - radius)
			+ round_corner.translatedCopy(-(sx/2 - radius) , sy/2 -radius , sz/2 - radius)
			+ round_corner.translatedCopy(sx/2 - radius , -(sy/2 -radius) , sz/2 - radius)
			+ round_corner.translatedCopy(sx/2 - radius , -(sy/2 -radius) , -(sz/2 - radius))
			+ round_corner.translatedCopy(-(sx/2 - radius) , -(sy/2 -radius) , sz/2 - radius)
			+ round_corner.translatedCopy(-(sx/2 - radius) , -(sy/2 -radius) , -(sz/2 - radius))
			+ round_corner.translatedCopy((sx/2 - radius) , (sy/2 -radius) , -(sz/2 - radius))
			+ round_corner.translatedCopy(-(sx/2 - radius) , (sy/2 -radius) , -(sz/2 - radius));

    if (!center)
			round_cube.translate(sx/2,sy/2,sz/2);

    set(round_cube.get());
	}
};

#endif // ROUNDEDCUBE_H_INCLUDED
