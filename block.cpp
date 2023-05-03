/*
Authors: Nicholas Storti, Alex Truitt, Jacob Meyer, Olivia Calusinski,
Jackson Davidson, Aidan Highsmith, and Piya Patel
Assignment Description: A group project using various classes and structures
that create a slightly more difficult version of tetris.
Date Created: 4/15/2023
Due Date: 5/4/2023
Date Last Modified: 5/4/2023
*/

#include "block.h"

Block::Block() {
    setType(square);
}

void Block::setLoc(const point& p) {
    point a;
    for(int i = 0; i < NUM_TILES; i++) {
        a.x = data[i].getLocation().x + p.x;
        a.y = data[i].getLocation().y + p.y;
        data[i].setLocation(a);
    }
    loc.x = p.x;
    loc.y = p.y;
}

void Block::setColor(const color& shade) {
    this->shade = shade;
    for(int i = 0; i < NUM_TILES; i++) {
        data[i].setColor(shade);
    }
}

void Block::setType(const blockType type) {
    point pos[NUM_TILES];
    rotCount = 0;

    this->type = type;

    switch(type) {
    case square:
        setColor(YELLOW);
        pos[1].x = data[0].getSize();
        pos[2].y = data[0].getSize();
        pos[3].x = data[0].getSize();
        pos[3].y = data[0].getSize();
        break;
    case bar:
        setColor(LIGHTBLUE);
        xrotation[0] = 1;
        yrotation[0] = -2;
        xrotation[1] = 0;
        yrotation[1] = -1;
        xrotation[2] = -1;
        yrotation[2] = 0;
        xrotation[3] = -2;
        yrotation[3] = 1;
        pos[1].x = data[0].getSize();
        pos[2].x = 2*data[0].getSize();
        pos[3].x = 3*data[0].getSize();
        break;
    case l_shape1:
        setColor(ORANGE);
        xrotation[0] = 1;
        yrotation[0] = -1;
        xrotation[1] = 0;
        yrotation[1] = 0;
        xrotation[2] = -1;
        yrotation[2] = 1;
        xrotation[3] = 0;
        yrotation[3] = -2;
        pos[1].x = data[0].getSize();
        pos[2].x = 2*data[0].getSize();
        pos[3].y = data[0].getSize();
        break;
    case l_shape2:
        setColor(BLUE);
        xrotation[0] = 1;
        yrotation[0] = -1;
        xrotation[1] = 0;
        yrotation[1] = 0;
        xrotation[2] = -1;
        yrotation[2] = 1;
        xrotation[3] = -2;
        yrotation[3] = 0;
        pos[1].x = data[0].getSize();
        pos[2].x = 2*data[0].getSize();
        pos[3].x = 2*data[0].getSize();
        pos[3].y = data[0].getSize();
        break;
    case t_shape:
        setColor(PURPLE);
        xrotation[0] = 1;
        yrotation[0] = 1;
        xrotation[1] = 1;
        yrotation[1] = -1;
        xrotation[2] = 0;
        yrotation[2] = 0;
        xrotation[3] = -1;
        yrotation[3] = 1;
        pos[0].x = data[0].getSize();
        pos[1].y = data[0].getSize();
        pos[2].x = data[0].getSize();
        pos[2].y = data[0].getSize();
        pos[3].x = 2*data[0].getSize();
        pos[3].y = data[0].getSize();
        break;
    case z_shape:
        setColor(GREEN);
        xrotation[0] = 1;
        yrotation[0] = -1;
        xrotation[1] = 0;
        yrotation[1] = 0;
        xrotation[2] = -1;
        yrotation[2] = -1;
        xrotation[3] = -2;
        yrotation[3] = 0;
        pos[1].x = data[0].getSize();
        pos[2].x = data[0].getSize();
        pos[2].y = data[0].getSize();
        pos[3].x = 2*data[0].getSize();
        pos[3].y = data[0].getSize();
        break;
    }

    for(int i = 0; i < NUM_TILES; i++) {
        data[i].setLocation(pos[i]);
    }

}

void Block::setSize(const int s) {
    size = s;
    for(int i = 0; i < NUM_TILES; i++) {
        data[i].setSize(size);
    }
}

point Block::getLoc() const {
    return loc;
}

color Block::getShade() const {
    return shade;
}

blockType Block::getType() const {
    return type;
}

int Block::getSize() const {
    return size;
}

tile Block::getTile(int index) const {
    return data[index];
}

void Block::draw(SDL_Plotter& g) {
    for(int i = 0; i < NUM_TILES; i++) {
        data[i].draw(g);
    }
}

void Block::move() {
    switch(type) {
    case bar:
        switch(rotCount) {
        case 1:
        case 3:
            if(loc.y <= NUM_ROW - (2*size)) {
                data[3].move();
                data[2].move();
                data[1].move();
                data[0].move();
                loc.y++;
            }
            break;
        case 0:
        case 2:
            for(int i = 0; i < NUM_TILES; i++) {
                data[i].move();
            }
            if(loc.y <= NUM_ROW - size) {
                loc.y++;
            }
        }
        break;
    case square:
        if(loc.y <= NUM_ROW - (2*size)) {
            data[0].move();
            data[1].move();
            loc.y++;
        }
        data[2].move();
        data[3].move();
        break;
    case l_shape1:
        switch(rotCount) {
        case 2:
            if(loc.y <= NUM_ROW - size) {
                for(int i = 0; i < NUM_TILES; i++) {
                    data[i].move();
                }
                loc.y++;
            }
            break;
        case 0:
        case 1:
        case 3:
            if(loc.y <= NUM_ROW - (2*size)) {
                for(int i = 0; i < NUM_TILES; i++) {
                    data[i].move();
                }
                loc.y++;
            }
        }
        break;
    case l_shape2:
        switch(rotCount) {
        case 0:
        case 1:
            if(loc.y <= NUM_ROW - (2*size)) {
                data[0].move();
                data[1].move();
                data[2].move();
                loc.y++;
            }
            data[3].move();
            break;
        case 2:
            if(loc.y <= NUM_ROW - size) {
                data[3].move();
                loc.y++;
            }
            data[0].move();
            data[1].move();
            data[2].move();
            break;
        case 3:
            if(loc.y <= NUM_ROW - (2*size)) {
                data[1].move();
                data[2].move();
                data[3].move();
                loc.y++;
            }
            data[0].move();
            break;
        }
        break;
    case t_shape:
        switch(rotCount) {
        case 0:
            if(loc.y <= NUM_ROW - (2*size)) {
                data[0].move();
                loc.y++;
            }
            data[1].move();
            data[2].move();
            data[3].move();
            break;
        case 1:
            if(loc.y <= NUM_ROW - (2*size)) {
                data[0].move();
                data[1].move();
                data[2].move();
                loc.y++;
            }
            data[3].move();
            break;
        case 2:
            if(loc.y <= NUM_ROW - (2*size)) {
                data[1].move();
                data[2].move();
                data[3].move();
                loc.y++;
            }
            data[0].move();
            break;
        case 3:
            if(loc.y <= NUM_ROW - (2*size)) {
                data[0].move();
                data[2].move();
                data[3].move();
                loc.y++;
            }
            data[1].move();
            break;
        }
        break;
    case z_shape:
        switch(rotCount) {
        case 0:
            if(loc.y <= NUM_ROW - (2*size)) {
                data[0].move();
                data[1].move();
                loc.y++;
            }
            data[2].move();
            data[3].move();
            break;
        case 1:
            if(loc.y <= NUM_ROW - (2*size)) {
                data[0].move();
                data[1].move();
                data[2].move();
                loc.y++;
            }
            data[3].move();
            break;
        case 2:
            if(loc.y <= NUM_ROW - (2*size)) {
                data[3].move();
                data[2].move();
                loc.y++;
            }
            data[1].move();
            data[0].move();
            break;
        case 3:
            if(loc.y <= NUM_ROW - (2*size)) {
                data[1].move();
                data[2].move();
                data[3].move();
                loc.y++;
            }
            data[0].move();
            break;
        }
        break;
    }
}

void Block::moveLeft() {
    switch(type) {
    case bar:
        if(loc.y <= NUM_ROW - size) {
            switch(rotCount) {
            case 0:
                data[0].moveLeft();
                if(!data[1].isCollide(data[0])) {
                    data[1].moveLeft();
                    data[2].moveLeft();
                    data[3].moveLeft();
                    loc.x -= size;
                }
                break;
            case 2:
                data[3].moveLeft();
                if(!data[2].isCollide(data[3])) {
                    data[2].moveLeft();
                    data[1].moveLeft();
                    data[0].moveLeft();
                    loc.x -= size;
                }
                break;
            case 1:
            case 3:
                for(int i = 0; i < NUM_TILES; i++) {
                    data[i].moveLeft();
                }
                if(loc.x > 0) {
                    loc.x -= size;
                }
            }
        }
        break;
    case square:
        if(loc.y <= NUM_ROW - (2*size)) {
            data[0].moveLeft();
            data[2].moveLeft();
            if(!data[1].isCollide(data[0])) {
                data[1].moveLeft();
                data[3].moveLeft();
                loc.x -= size;
            }
        }
        break;
    case l_shape1:
        if(loc.y <= NUM_ROW - (2*size)) {
            switch(rotCount) {
            case 0:
                data[0].moveLeft();
                data[3].moveLeft();
                if(!data[1].isCollide(data[0])) {
                    data[1].moveLeft();
                    data[2].moveLeft();
                    loc.x -= size;
                }
                break;
            case 1:
                data[3].moveLeft();
                if(!data[0].isCollide(data[3])) {
                    data[0].moveLeft();
                    data[1].moveLeft();
                    data[2].moveLeft();
                    loc.x -= size;
                }
                break;
            case 2:
                data[2].moveLeft();
                if(!data[1].isCollide(data[2])) {
                    data[0].moveLeft();
                    data[1].moveLeft();
                    data[3].moveLeft();
                    loc.x -= size;
                }
                break;
            case 3:
                data[0].moveLeft();
                data[1].moveLeft();
                data[2].moveLeft();
                if(!data[3].isCollide(data[0])) {
                    data[3].moveLeft();
                    loc.x -= size;
                }
                break;
            }
        }
        break;
    case l_shape2:
        if(loc.y <= NUM_ROW - (2*size)) {
            switch(rotCount) {
            case 0:
                data[0].moveLeft();
                if(!data[1].isCollide(data[0])) {
                    data[1].moveLeft();
                    data[2].moveLeft();
                    data[3].moveLeft();
                    loc.x -= size;
                }
                break;
            case 1:
                data[3].moveLeft();
                if(!data[2].isCollide(data[3])) {
                    data[2].moveLeft();
                    data[1].moveLeft();
                    data[0].moveLeft();
                    loc.x -= size;
                }
                break;
            case 2:
                data[3].moveLeft();
                data[2].moveLeft();
                if(!data[1].isCollide(data[2])) {
                    data[1].moveLeft();
                    data[0].moveLeft();
                    loc.x -= size;
                }
                break;
            case 3:
                data[0].moveLeft();
                data[1].moveLeft();
                data[2].moveLeft();
                if(!data[3].isCollide(data[2])) {
                    data[3].moveLeft();
                    loc.x -= size;
                }
                break;
            }
        }
        break;
    case t_shape:
        if(loc.y <= NUM_ROW - (2*size)) {
            switch(rotCount) {
            case 0:
                data[1].moveLeft();
                if(!data[2].isCollide(data[1])) {
                    data[0].moveLeft();
                    data[2].moveLeft();
                    data[3].moveLeft();
                    loc.x -= size;
                }
                break;
            case 1:
                if(loc.y <= NUM_ROW - (3*size)) {
                data[1].moveLeft();
                data[2].moveLeft();
                data[3].moveLeft();
                if(!data[0].isCollide(data[2])) {
                    data[0].moveLeft();
                    loc.x -= size;
                }
                }
                break;
            case 2:
                data[3].moveLeft();
                if(!data[2].isCollide(data[3])) {
                    data[0].moveLeft();
                    data[1].moveLeft();
                    data[2].moveLeft();
                    loc.x -= size;
                }
                break;
            case 3:
                if(loc.y <= NUM_ROW - (3*size)) {
                data[0].moveLeft();
                if(!data[2].isCollide(data[0])) {
                    data[1].moveLeft();
                    data[2].moveLeft();
                    data[3].moveLeft();
                    loc.x -= size;
                }
                }
                break;
            }
        }
        break;
    case z_shape:
        if(loc.y <= NUM_ROW - (2*size)) {
            switch(rotCount) {
            case 0:
                data[0].moveLeft();
                if(!data[1].isCollide(data[0])) {
                    data[1].moveLeft();
                    data[2].moveLeft();
                    data[3].moveLeft();
                    loc.x -= size;
                }
                break;
            case 1:
                data[2].moveLeft();
                data[3].moveLeft();
                if(!data[1].isCollide(data[2])) {
                    data[0].moveLeft();
                    data[1].moveLeft();
                    loc.x -= size;
                }
                break;
            case 2:
                data[3].moveLeft();
                if(!data[2].isCollide(data[3])) {
                    data[2].moveLeft();
                    data[1].moveLeft();
                    data[0].moveLeft();
                    loc.x -= size;
                }
                break;
            case 3:
                data[0].moveLeft();
                data[1].moveLeft();
                if(!data[2].isCollide(data[1])) {
                    data[2].moveLeft();
                    data[3].moveLeft();
                    loc.x -= size;
                }
                break;
            }
        }
        break;
    }
}

void Block::moveRight() {
    switch(type) {
    case bar:
        if(loc.y <= NUM_ROW - size) {
            switch(rotCount) {
            case 0:
                data[3].moveRight();
                if(!data[2].isCollide(data[3])) {
                    data[2].moveRight();
                    data[1].moveRight();
                    data[0].moveRight();
                    loc.x += size;
                }
                break;
            case 2:
                data[0].moveRight();
                if(!data[1].isCollide(data[0])) {
                    data[1].moveRight();
                    data[2].moveRight();
                    data[3].moveRight();
                    loc.x += size;
                }
                break;
            case 1:
            case 3:
                for(int i = 0; i < NUM_TILES; i++) {
                    data[i].moveRight();
                }
                if(loc.x < NUM_COL - size) {
                    loc.x += size;
                }
                break;
            }
        }
        break;
    case square:
        if(loc.y <= NUM_ROW - (2*size)) {
            data[1].moveRight();
            data[3].moveRight();
            if(!data[0].isCollide(data[1])) {
                data[0].moveRight();
                data[2].moveRight();
                loc.x += size;
            }
        }
        break;
    case l_shape1:
        if(loc.y <= NUM_ROW - (2*size)) {
            switch(rotCount) {
            case 0:
                data[2].moveRight();
                if(!data[1].isCollide(data[2])) {
                    data[1].moveRight();
                    data[0].moveRight();
                    data[3].moveRight();
                    loc.x += size;
                }
                break;
            case 1:
                data[0].moveRight();
                data[1].moveRight();
                data[2].moveRight();
                if(!data[3].isCollide(data[0])) {
                    data[3].moveRight();
                    loc.x += size;
                }
                break;
            case 2:
                data[0].moveRight();
                data[3].moveRight();
                if(!data[1].isCollide(data[0])) {
                   data[1].moveRight();
                   data[2].moveRight();
                   loc.x += size;
                }
                break;
            case 3:
                data[3].moveRight();
                if(!data[0].isCollide(data[3])) {
                    data[0].moveRight();
                    data[1].moveRight();
                    data[2].moveRight();
                    loc.x += size;
                }
                break;
            }
        }
        break;
    case l_shape2:
        if(loc.y <= NUM_ROW - (2*size)) {
            switch(rotCount) {
            case 0:
                data[2].moveRight();
                data[3].moveRight();
                if(!data[1].isCollide(data[2])) {
                    data[1].moveRight();
                    data[0].moveRight();
                    loc.x += size;
                }
                break;
            case 1:
                data[0].moveRight();
                data[1].moveRight();
                data[2].moveRight();
                if(!data[3].isCollide(data[2])) {
                    data[3].moveRight();
                    loc.x += size;
                }
                break;
            case 2:
                data[0].moveRight();
                if(!data[1].isCollide(data[0])) {
                    data[1].moveRight();
                    data[2].moveRight();
                    data[3].moveRight();
                    loc.x += size;
                }
                break;
            case 3:
                data[3].moveRight();
                if(!data[2].isCollide(data[3])) {
                    data[2].moveRight();
                    data[1].moveRight();
                    data[0].moveRight();
                    loc.x += size;
                }
                break;
            }
        }
        break;
    case t_shape:
        if(loc.y <= NUM_ROW - (2*size)) {
            switch(rotCount) {
            case 0:
                data[3].moveRight();
                if(!data[2].isCollide(data[3])) {
                    data[0].moveRight();
                    data[1].moveRight();
                    data[2].moveRight();
                    loc.x += size;
                }
                break;
            case 1:
                if(loc.y <= NUM_ROW - (3*size)) {
                data[0].moveRight();
                if(!data[2].isCollide(data[0])) {
                    data[1].moveRight();
                    data[2].moveRight();
                    data[3].moveRight();
                    loc.x += size;
                }
                }
                break;
            case 2:
                data[1].moveRight();
                if(!data[2].isCollide(data[1])) {
                    data[0].moveRight();
                    data[2].moveRight();
                    data[3].moveRight();
                    loc.x += size;
                }
                break;
            case 3:
                if(loc.y <= NUM_ROW - (3*size)) {
                data[1].moveRight();
                data[2].moveRight();
                data[3].moveRight();
                if(!data[0].isCollide(data[2])) {
                    data[0].moveRight();
                    loc.x += size;
                }
                }
                break;
            }
        }
        break;
    case z_shape:
        if(loc.y <= NUM_ROW - (2*size)) {
            switch(rotCount) {
            case 0:
                data[3].moveRight();
                if(!data[2].isCollide(data[3])) {
                    data[2].moveRight();
                    data[1].moveRight();
                    data[0].moveRight();
                    loc.x += size;
                }
                break;
            case 1:
                data[0].moveRight();
                data[1].moveRight();
                if(!data[2].isCollide(data[1])) {
                    data[2].moveRight();
                    data[3].moveRight();
                    loc.x += size;
                }
                break;
            case 2:
                data[0].moveRight();
                if(!data[1].isCollide(data[0])) {
                    data[1].moveRight();
                    data[2].moveRight();
                    data[3].moveRight();
                    loc.x += size;
                }
                break;
            case 3:
                data[3].moveRight();
                data[2].moveRight();
                if(!data[1].isCollide(data[2])) {
                    data[1].moveRight();
                    data[0].moveRight();
                    loc.x += size;
                }
                break;
            }
        }
        break;
    }
}

void Block::rotate() {
    point pos[NUM_TILES];

    for(int i = 0; i < NUM_TILES; i++) {
        pos[i] = data[i].getLocation();
    }
    switch(type) {
    case bar:
        if((loc.y <= NUM_ROW - (2*size)) &&
           (loc.y >= 2*size) && !((loc.x == 0) &&
           (rotCount == 1)) && !((loc.x < 2*size) &&
           (rotCount == 3)) && !((loc.x > NUM_COL - (3*size)) &&
           (rotCount == 1)) && !((loc.x > NUM_COL - (2*size)) &&
           (rotCount == 3))) {
            for(int i = 0; i < NUM_TILES; i++) {
                pos[i].x += xrotation[i]*size;
                pos[i].y += yrotation[i]*size;
            }
            if(rotCount == 0) {
                xrotation[0] = 2;
                yrotation[0] = 1;
                xrotation[1] = 1;
                yrotation[1] = 0;
                xrotation[2] = 0;
                yrotation[2] = -1;
                xrotation[3] = -1;
                yrotation[3] = -2;
                loc.x += size;
                rotCount++;
            }
            else if(rotCount == 1) {
                xrotation[0] = -1;
                yrotation[0] = 2;
                xrotation[1] = 0;
                yrotation[1] = 1;
                xrotation[2] = 1;
                yrotation[2] = 0;
                xrotation[3] = 2;
                yrotation[3] = -1;
                loc.x -= size;
                rotCount++;
            }
            else if(rotCount == 2) {
                xrotation[0] = -2;
                yrotation[0] = -1;
                xrotation[1] = -1;
                yrotation[1] = 0;
                xrotation[2] = 0;
                yrotation[2] = 1;
                xrotation[3] = 1;
                yrotation[3] = 2;
                loc.x += 2*size;
                rotCount++;
            }
            else if(rotCount == 3) {
                xrotation[0] = 1;
                yrotation[0] = -2;
                xrotation[1] = 0;
                yrotation[1] = -1;
                xrotation[2] = -1;
                yrotation[2] = 0;
                xrotation[3] = -2;
                yrotation[3] = 1;
                loc.x -= 2*size;
                rotCount = 0;
            }
        }
        break;
    case square:
        break;
    case l_shape1:
        if((loc.y <= NUM_ROW - (2*size)) &&
          (loc.y >= size) && !((loc.x < size) &&
          (rotCount == 3)) && !((loc.x > NUM_COL - (3*size))
          && (rotCount == 1))) {
            for(int i = 0; i < NUM_TILES; i++) {
                pos[i].x += xrotation[i]*size;
                pos[i].y += yrotation[i]*size;
            }
            if(rotCount == 0) {
                yrotation[0] = 1;
                yrotation[2] = -1;
                xrotation[3] = 2;
                yrotation[3] = 0;
                rotCount++;
            }
            else if(rotCount == 1) {
                xrotation[0] = -1;
                xrotation[2] = 1;
                xrotation[3] = 0;
                yrotation[3] = 2;
                rotCount++;
            }
            else if(rotCount == 2) {
                yrotation[0] = -1;
                yrotation[2] = 1;
                xrotation[3] = -2;
                yrotation[3] = 0;
                loc.x += size;
                rotCount++;
            }
            else if(rotCount == 3) {
                xrotation[0] = 1;
                xrotation[2] = -1;
                xrotation[3] = 0;
                yrotation[3] = -2;
                loc.x -= size;
                rotCount = 0;
            }
        }
        break;
    case l_shape2:
        if((loc.y <= NUM_ROW - (2*size)) &&
          (loc.y >= size) && !((loc.x == 0) &&
          (rotCount == 3)) && !((loc.x > NUM_COL - (3*size))
          && (rotCount == 1))) {
            for(int i = 0; i < NUM_TILES; i++) {
                pos[i].x += xrotation[i]*size;
                pos[i].y += yrotation[i]*size;
            }
           if(rotCount == 0) {
                yrotation[0] = 1;
                yrotation[2] = -1;
                xrotation[3] = 0;
                yrotation[3] = -2;
                rotCount++;
            }
            else if(rotCount == 1) {
                xrotation[0] = -1;
                xrotation[2] = 1;
                xrotation[3] = 2;
                yrotation[3] = 0;
                rotCount++;
            }
            else if(rotCount == 2) {
                yrotation[0] = -1;
                yrotation[2] = 1;
                xrotation[3] = 0;
                yrotation[3] = 2;
                loc.x += size;
                rotCount++;
            }
            else if(rotCount == 3) {
                xrotation[0] = 1;
                xrotation[2] = -1;
                xrotation[3] = -2;
                yrotation[3] = 0;
                loc.x -= size;
                rotCount = 0;
            }
        }
        break;
    case t_shape:
        if((loc.y <= NUM_ROW - (2*size)) &&
          (loc.y >= size) && !((loc.x == 0) &&
          (rotCount == 1)) && !((loc.x > NUM_COL - (3*size))
          && (rotCount == 3))) {
            for(int i = 0; i < NUM_TILES; i++) {
                    pos[i].x += xrotation[i]*size;
                    pos[i].y += yrotation[i]*size;
            }
            if(rotCount == 0) {
                xrotation[0] = -1;
                yrotation[1] = 1;
                yrotation[3] = -1;
                loc.x += size;
                loc.y += size;
                rotCount++;
            }
            else if(rotCount == 1) {
                yrotation[0] = -1;
                xrotation[1] = -1;
                xrotation[3] = 1;
                loc.x -= size;
                rotCount++;
            }
            else if(rotCount == 2) {
                xrotation[0] = 1;
                yrotation[1] = -1;
                yrotation[3] = 1;
                rotCount++;
            }
            else if(rotCount == 3) {
                yrotation[0] = 1;
                xrotation[1] = 1;
                xrotation[3] = -1;
                loc.y -= size;
                rotCount = 0;
            }
        }
        break;
    case z_shape:
        if((loc.y <= NUM_ROW - (2*size)) &&
          (loc.y >= size) && !((loc.x < size) &&
          (rotCount == 3)) && !((loc.x > NUM_COL - (4*size))
          && (rotCount == 1))) {
            for(int i = 0; i < NUM_TILES; i++) {
                    pos[i].x += xrotation[i]*size;
                    pos[i].y += yrotation[i]*size;
            }
            if(rotCount == 0) {
                yrotation[0] = 1;
                xrotation[2] = 1;
                xrotation[3] = 0;
                yrotation[3] = -2;
                loc.x -= size;
                rotCount++;
            }
            else if(rotCount == 1) {
                xrotation[0] = -1;
                yrotation[2] = 1;
                xrotation[3] = 2;
                yrotation[3] = 0;
                loc.x += size;
                loc.y -= size;
                rotCount++;
            }
            else if(rotCount == 2) {
                yrotation[0] = -1;
                xrotation[2] = -1;
                xrotation[3] = 0;
                yrotation[3] = 2;
                loc.x += size;
                loc.y += size;
                rotCount++;
            }
            else if(rotCount == 3) {
                xrotation[0] = 1;
                yrotation[2] = -1;
                xrotation[3] = -2;
                yrotation[3] = 0;
                loc.x -= size;
                rotCount = 0;
            }
        }
        break;
    }
    for(int i = 0; i < NUM_TILES; i++) {
        data[i].setLocation(pos[i]);
    }
}

