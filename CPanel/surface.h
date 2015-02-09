//
//  surface.h
//  CPanel
//
//  Created by Chris Satterwhite on 5/1/14.
//  Copyright (c) 2014 Chris Satterwhite. All rights reserved.
//

#ifndef __CPanel__surface__
#define __CPanel__surface__

#include <iostream>
#include <Eigen/Dense>
#include <vector>
#include "panel.h"
#include "wakePanel.h"
#include "bodyPanel.h"

class surface
{
    typedef Eigen::Vector3i vertices;
    typedef Eigen::MatrixXd coordinates;
    
protected:
    std::vector<bodyPanel*> panels;
    short surfID;
    
public:
    surface(const int &surfaceID) : surfID(surfaceID) {}
    
    virtual ~surface();
    
    surface(const surface& copy) : surfID(copy.surfID)
    {
        for (int i=0; i<copy.panels.size(); i++)
        {
            panels[i] = new bodyPanel(*copy.panels[i]);
        }
    }
    
    virtual void addPanel(bodyPanel* bPan);

    std::vector<bodyPanel*> getPanels() const {return panels;}
    int getID() const {return surfID;}
    
};

#endif /* defined(__CPanel__surface__) */