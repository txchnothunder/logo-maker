//
// Created by Ethan Wong on 3/18/23.
//

#ifndef CS008MIDTERMPROJECT_SNAPSHOT_H
#define CS008MIDTERMPROJECT_SNAPSHOT_H

class Snapshot
{
public:
    // this function will return a snapshot of the object's current state
    virtual Snapshot* getSnapshot() = 0;

    // this function will apply a snapshot to the object.
    //This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot(const Snapshot* snapshot) = 0;
};

#endif //CS008MIDTERMPROJECT_SNAPSHOT_H
