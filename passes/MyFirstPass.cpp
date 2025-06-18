#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

struct ConstantFoldingPass : PassInfoMixin<ConstantFoldingPass> {
    PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
        errs() << ">>> Running Constant Folding Pass\n";

        for (Function &F : M) {
            if (F.isDeclaration()) continue;

            for (BasicBlock &BB : F) {
                for (auto Inst = BB.begin(); Inst != BB.end(); ) {
                    Instruction *I = &*Inst++;
                    if (auto *BinOp = dyn_cast<BinaryOperator>(I)) {
                        auto *C1 = dyn_cast<ConstantInt>(BinOp->getOperand(0));
                        auto *C2 = dyn_cast<ConstantInt>(BinOp->getOperand(1));

                        if (C1 && C2) {
                            Constant *Folded = nullptr;
                            switch (BinOp->getOpcode()) {
                                case Instruction::Add:
                                    Folded = ConstantInt::get(BinOp->getType(), C1->getSExtValue() + C2->getSExtValue());
                                    break;
                                case Instruction::Sub:
                                    Folded = ConstantInt::get(BinOp->getType(), C1->getSExtValue() - C2->getSExtValue());
                                    break;
                                case Instruction::Mul:
                                    Folded = ConstantInt::get(BinOp->getType(), C1->getSExtValue() * C2->getSExtValue());
                                    break;
                                default:
                                    break;
                            }

                            if (Folded) {
                                errs() << "Folding: ";
                                BinOp->print(errs());
                                errs() << "  -->  ";
                                Folded->print(errs());
                                errs() << "\n";

                                BinOp->replaceAllUsesWith(Folded);
                                BinOp->eraseFromParent();
                            }
                        }
                    }
                }
            }
        }

        return PreservedAnalyses::none(); // We modified the IR
    }
};

extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo llvmGetPassPluginInfo() {
    return {
        LLVM_PLUGIN_API_VERSION, "ConstantFoldingPass", LLVM_VERSION_STRING,
        [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, ModulePassManager &MPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                    if (Name == "constant-folding-pass") {
                        MPM.addPass(ConstantFoldingPass());
                        return true;
                    }
                    return false;
                });
        }};
}

