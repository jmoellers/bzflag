/* bzflag
 * Copyright (c) 1993 - 2004 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef __GUIDEDMISSLESTRATEGY_H__
#define __GUIDEDMISSLESTRATEGY_H__

/* interface header */
#include "ShotStrategy.h"

/* system interface headers */
#include <vector>

/* common interface headers */
#include "SceneDatabase.h"
#include "TimeKeeper.h"
#include "BoltSceneNode.h"
#include "Address.h"

/* local interface headers */
#include "LocalPlayer.h"
#include "ShotPathSegment.h"


class GuidedMissileStrategy : public ShotStrategy {
  public:
			GuidedMissileStrategy(ShotPath*);
			~GuidedMissileStrategy();

    void		update(float dt);
    float		checkHit(const BaseLocalPlayer*, float[3]) const;
    void		sendUpdate(const FiringInfo&) const;
    void		readUpdate(uint16_t, void*);
    void		addShot(SceneDatabase*, bool colorblind);
    void		expire();
    void		radarRender() const;

  private:
    float		checkBuildings(const Ray& ray);

  private:
    TimeKeeper		prevTime;
    TimeKeeper		currentTime;
    std::vector<ShotPathSegment>	segments;
    int			renderTimes;
    float		azimuth;
    float		elevation;
    float		nextPos[3];
    BoltSceneNode*	ptSceneNode;

    bool		needUpdate;
    PlayerId		lastTarget;
};


#endif /* __GUIDEDMISSLESTRATEGY_H__ */

// Local Variables: ***
// mode: C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8
