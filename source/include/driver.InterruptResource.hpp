/** 
 * Target processor interrupt controller resource.
 *
 * The class describes a skeleton implementation of an interrupt resource.
 * It should be inherited by all classes, which aim expanding the implementation.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef DRIVER_INTERRUPT_RESOURCE_HPP_
#define DRIVER_INTERRUPT_RESOURCE_HPP_

#include "Object.hpp"
#include "driver.Interrupt.hpp"

namespace driver
{
  class InterruptResource : public ::Object<>, public ::driver::Interrupt
  {
    typedef ::Object<>  Parent;  

  public:
  
    /** 
     * Constructor.
     */    
    InterruptResource() : Parent(),
      isConstructed_ (getConstruct()){
    }    
  
    /** 
     * Destructor.
     */                               
    virtual ~InterruptResource()
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
    
    /**
     * Jumps to interrupt hardware vector.
     */      
    virtual void jump() = 0;
    
    /**
     * Clears an interrupt status of this source.
     */     
    virtual void clear()
    {
    }
    
    /**
     * Sets an interrupt status of this source.
     */    
    virtual void set()
    {
    }
    
    /** 
     * Disables a controller.
     *
     * @return an enable source bit value of a controller before method was called.
     */ 
    virtual bool disable()
    {
      return false;
    }
    
    /** 
     * Enables a controller.
     *
     * The true passed argument directly turns a controller on, 
     * and the false does nothing, a controller stays in the current state.
     * 
     * @param status returned status by disable method, or true for directly turning a controller on.
     */    
    virtual void enable(bool status=true)
    {
    }
    
    /**
     * Sets interrupt source handler.
     *
     * @param handler pointer to user class which implements an interrupt handler interface.
     * @param source  available interrupt source.
     * @return true if handler is set successfully.
     */      
    virtual bool setHandler(::api::Task& handler, int32 source)
    {
      return false;
    }
    
    /**
     * Removes this interrupt source.
     */        
    virtual void removeHandler()
    {
    }
    
    /**
     * Resets registers context for storing to the default.
     * 
     * Method restores default registers for storing the CPU registers to it.
     * This method may be called in an user interrupt handler, it means
     * the default conxet will be restored by the context restore procedure.
     */
    virtual void resetRegister()
    {
    }
    
    /**
     * Sets new registers context for storing.
     * 
     * Method sets a new register context for storing the CPU registers to it.
     * This method may be called in an user interrupt handler, it means
     * given conxet will be restored by the context restore procedure.
     *
     * @param reg new registers context.
     */
    virtual void setRegister(::driver::Register& reg)
    {
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
    InterruptResource(const InterruptResource& obj);

    /**
     * Assignment operator.
     *
     * @param obj reference to source object.
     * @return reference to this object.     
     */
    InterruptResource& operator =(const InterruptResource& obj);  
      
  };
}
#endif // DRIVER_INTERRUPT_RESOURCE_HPP_