
#ifndef _CCM_MGR_H_
#define _CCM_MGR_H_

namespace NSIspTuning
{

class IspTuningCustom;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// CCM Manager
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class CcmMgr
{
public:
    static CcmMgr* createInstance(ESensorDev_T const eSensorDev, ISP_NVRAM_REGISTER_STRUCT& rIspNvramReg, ISP_NVRAM_CCM_POLY22_STRUCT& rISPCcmPoly22, IspTuningCustom* pIspTuningCustom);
    virtual MVOID destroyInstance() = 0;


private:
    enum
    {
        CCM_IDX_D65 = 0,
        CCM_IDX_TL84,
        CCM_IDX_CWF,
        CCM_IDX_A,
        CCM_IDX_NUM
    };

private:

    inline
    MVOID
    setIfChange(MINT32 i4Idx)
    {
        if  ( i4Idx != m_i4Idx )
        {
            m_i4Idx = i4Idx;
            m_rCCMOutput = m_rCCMInput[m_i4Idx];
        }
    }

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Index
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public:     ////

    inline
    MINT32
    getIdx() const
    {
        return m_i4Idx;
    }

    inline
    MBOOL
    setIdx(MINT32 const i4Idx)
    {
        if  (( CCM_IDX_NUM <= i4Idx ) || ( 0 > i4Idx ))
            return  MFALSE;
        setIfChange(i4Idx);
        return  MTRUE;
    }

private:
    MINT32 m_i4Idx; //  CCM index
    ISP_NVRAM_CCM_T (&m_rCCMInput)[CCM_IDX_NUM];
    ISP_NVRAM_CCM_T m_rCCMOutput; // CCM output
    ESensorDev_T m_eSensorDev;
    ISP_NVRAM_CCM_POLY22_STRUCT& m_rISPCcmPoly22;
    IspTuningCustom*    m_pIspTuningCustom;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Ctor
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public:     ////
    CcmMgr(ESensorDev_T const eSensorDev, ISP_NVRAM_REGISTER_STRUCT& rIspNvramReg, ISP_NVRAM_CCM_POLY22_STRUCT& rISPCcmPoly22, IspTuningCustom* pIspTuningCustom)
        : m_i4Idx       (CCM_IDX_D65)
        , m_rCCMInput   (rIspNvramReg.CCM)
        , m_rCCMOutput  (m_rCCMInput[m_i4Idx])
        , m_eSensorDev  (eSensorDev)
        , m_rISPCcmPoly22 (rISPCcmPoly22)
        , m_pIspTuningCustom (pIspTuningCustom)
    {

    }

    virtual ~CcmMgr() {}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Operations.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public:

    MVOID 
    calculateCCM(AWB_INFO_T const& rAWBInfo);
    
    inline
    ISP_NVRAM_CCM_T&
    getCCM()
    {
        return m_rCCMOutput;
    }

    inline
    ESensorDev_T
    getSensorDev() const
    {
        return m_eSensorDev;
    }

};

};  //  NSIspTuning
#endif // _CCM_MGR_H_

