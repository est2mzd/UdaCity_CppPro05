#ifndef BLOCK_SINGLE_H
#define BLOCK_SINGLE_H

class Block_Single {
    public:
        Block_Single();
        void init();

        int   id;
        int   row_num;
        bool  is_active;
        bool  is_colliding;

        float pos_x;
        float pos_y;

        float width;
        float height;

    private:

};

#endif