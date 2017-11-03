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
#ifndef MODULE_INTERRUPT_BASE_HPP_
#define MODULE_INTERRUPT_BASE_HPP_

#include "Object.hpp"
#include "module.Interrupt.hpp"

namespace module
{
    class InterruptBase : public ::Object<>, public ::module::Interrupt
    {
        typedef ::Object<>  Parent;  
  
    public:
    
        /** 
         * Constructor.
         */    
        InterruptBase() : Parent(),
            isConstructed_ (getConstruct()){
        }    
        
        /** 
         * Destructor.
         */                               
        virtual ~InterruptBase()
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
         * Sets new registers context for storing.
         *
         * @param reg new registers context.
         */
        virtual void setContext(::module::Register& reg)
        {
        }        
        
        /**
         * Restores registers context for storing to the default.
         */
        virtual void restoreContext()
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
        InterruptBase(const InterruptBase& obj);
        
        /**
         * Assignment operator.
         *
         * @param obj reference to source object.
         * @return reference to this object.     
         */
        InterruptBase& operator =(const InterruptBase& obj);  
        
    };
}
#endif // MODULE_INTERRUPT_BASE_HPP_