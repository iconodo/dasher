#ifndef __nodemanager_h__
#define __nodemanager_h__

namespace Dasher {
  class CDasherNode; // Forward declaration

  ///
  /// Virtual base class for node managers
  ///
  
  class CNodeManager {
  public:
    ///
    /// Increment reference count
    ///

    virtual void Ref() = 0;
    
    ///
    /// Decrement reference count
    ///
    
    virtual void Unref() = 0;

    ///
    /// Get a new root node owned by this manager
    ///

    virtual CDasherNode *GetRoot(CDasherNode *pParent, int iLower, int iUpper) = 0;

    ///
    /// Provide children for the supplied node
    ///

    virtual void PopulateChildren( CDasherNode *pNode ) = 0;
    
    ///
    /// Delete any storage alocated for this node
    ///

    virtual void ClearNode( CDasherNode *pNode ) = 0;

    ///
    /// Called whenever a node belonging to this manager first 
    /// moves under the crosshair
    ///

    virtual void Output( CDasherNode *pNode ) {};
    virtual void Undo( CDasherNode *pNode ) {};
  };

}

#endif