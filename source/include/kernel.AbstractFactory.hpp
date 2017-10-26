/**
 * Base class of the factory of an operating system kernel.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef KERNEL_ABSTRACT_FACTORY_HPP_
#define KERNEL_ABSTRACT_FACTORY_HPP_

#include "Object.hpp"
#include "kernel.Factory.hpp"

namespace kernel
{
    class AbstractFactory : public ::Object<>, public ::kernel::Factory
    {
        typedef ::Object<> Parent;
      
    public:
    
        /** 
         * Constructor.
         */    
        AbstractFactory() : Parent(),
            isConstructed_ (getConstruct()){
        }        
  
        /** 
         * Destructor.
         */
        virtual ~AbstractFactory(){}
        
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
         * Creates new mutex resource.
         *
         * @return new mutex resource, or NULL if error has been occurred.
         */      
        virtual ::api::Mutex* createMutex()
        {
            return NULL;
        }
        
        /** 
         * Creates new semaphore resource.
         *
         * @param permits the initial number of permits available.   
         * @return new semaphore resource, or NULL if error has been occurred.
         */      
        virtual ::api::Semaphore* createSemaphore(int32 permits)
        {
            return NULL;
        }
        
        /** 
         * Creates new semaphore resource.
         *
         * @param permits the initial number of permits available.      
         * @param isFair  true if this semaphore will guarantee FIFO granting of permits under contention.
         * @return new semaphore resource, or NULL if error has been occurred.         
         */      
        virtual ::api::Semaphore* createSemaphore(int32 permits, bool isFair)
        {
            return NULL;
        }
        
        /**
         * Creates new interrupt resource.
         *
         * @param handler user class which implements an interrupt handler interface.
         * @param source  available interrupt source number.
         * @return new interrupt resource.
         */
        virtual ::api::Interrupt* createInterrupt(::api::Task& handler, int32 source)
        {
            return NULL;
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
        AbstractFactory(const AbstractFactory& obj);
      
        /**
         * Assignment operator.
         *
         * @param obj reference to source object.
         * @return reference to this object.     
         */
        AbstractFactory& operator =(const AbstractFactory& obj);            
        
    };
}
#endif // KERNEL_ABSTRACT_FACTORY_HPP_