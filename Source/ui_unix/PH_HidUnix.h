#ifndef _PH_HIDUnix_H_
#define _PH_HIDUnix_H_

#include "PadHandler.h"
#include <memory>

class CPH_HidUnix : public CPadHandler
{
public:
    CPH_HidUnix();
    virtual					~CPH_HidUnix();

    void					Update(uint8*) override;

    static FactoryFunction			GetFactoryFunction();
    static void				InputValueCallbackPressed(CPH_HidUnix*, uint32 valueRef);
    static void				InputValueCallbackReleased(CPH_HidUnix*, uint32 valueRef);

private:
    class CBinding
    {
    public:
        virtual			~CBinding() {}

        virtual void		ProcessEvent(uint32, uint32) = 0;

        virtual uint32		GetValue() const = 0;
    };

    typedef std::shared_ptr<CBinding> BindingPtr;

    class CSimpleBinding : public CBinding
    {
    public:
        CSimpleBinding(uint32);
        virtual			~CSimpleBinding();

        virtual void		ProcessEvent(uint32, uint32);

        virtual uint32		GetValue() const;

    private:
        uint32			m_keyCode;
        uint32			m_state;
    };

    class CSimulatedAxisBinding : public CBinding
    {
    public:
        CSimulatedAxisBinding(uint32, uint32);
        virtual			~CSimulatedAxisBinding();

        virtual void		ProcessEvent(uint32, uint32);

        virtual uint32		GetValue() const;

    private:
        uint32			m_negativeKeyCode;
        uint32			m_positiveKeyCode;

        uint32			m_negativeState;
        uint32			m_positiveState;
    };

    static CPadHandler*		PadHandlerFactory(CPH_HidUnix*);


    void				InputValueCallback(uint32 value, uint32 action);


    BindingPtr			m_bindings[PS2::CControllerInfo::MAX_BUTTONS];
};

#endif
