/** 
 * Target processor phase-locked loop controller resource. 
 *
 * The class describes a skeleton implementation of a phase-locked loop resource.
 * It should be inherited by all classes, which aim expanding the implementation. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_DRIVER_PLL_RESOURCE_HPP_
#define BOOS_DRIVER_PLL_RESOURCE_HPP_

#include "boos.Object.hpp"
#include "boos.driver.Pll.hpp"

namespace driver
{
  class PllResource : public ::Object<>, public ::driver::Pll
  {
    typedef ::Object<>  Parent;
    
  public:
  
    /** 
     * Constructor.
     */     
    PllResource() : Parent(),
      isConstructed_ (getConstruct()){
    }    
  
    /** 
     * Destructor.
     */                               
    virtual ~PllResource()
    {
    }
    
    /**
     * Tests if this object has been constructed.
     *
     * @return true if object has been constructed successfully.
     */    
    virtual bool isConstructed() const
    {
      return isConstructed_;
    }
    
  protected:
    
    /** 
     * The root object constructed flag.
     */  
    const bool& isConstructed_;
    
  private:
  
    /**
     * Copy constructor.
     *
     * @param obj reference to source object.
     */
    PllResource(const PllResource& obj);

    /**
     * Assignment operator.
     *
     * @param obj reference to source object.
     * @return reference to this object.     
     */
    PllResource& operator =(const PllResource& obj);      

  };
}
#endif // BOOS_DRIVER_PLL_RESOURCE_HPP_