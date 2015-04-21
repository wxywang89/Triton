
#ifndef   __PROCESSINGPYCONF_H__
#define   __PROCESSINGPYCONF_H__

#include "AnalysisProcessor.h"
#include "IRBuilder.h"
#include "Inst.h"
#include "PINContextHandler.h"
#include "PythonBindings.h"
#include "Trigger.h"
#include "TritonPyObject.h"

class ProcessingPyConf
{
  private:
    AnalysisProcessor   *ap;
    Trigger             *analysisTrigger;

  public:
    ProcessingPyConf(AnalysisProcessor *ap, Trigger *analysisTrigger);
    ~ProcessingPyConf();

    void applyConfBeforeProcessing(IRBuilder *irb);

    void callbackBefore(IRBuilder *irb, AnalysisProcessor *ap);
    void callbackAfter(Inst *inst, AnalysisProcessor *ap);
    void callbackFini(void);
    void callbackSyscallEntry(uint64_t threadId, uint64_t std);
    void callbackSyscallExit(uint64_t threadId, uint64_t std);

    void startAnalysisFromAddr(IRBuilder *irb);
    void stopAnalysisFromAddr(IRBuilder *irb);

    void taintRegFromAddr(IRBuilder *irb);
    void untaintRegFromAddr(IRBuilder *irb);
};

#endif     /* !__PROCESSINGPYCONF_H__ */