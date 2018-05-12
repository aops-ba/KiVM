//
// Created by kiva on 2018/3/27.
//
#pragma once

#include <kivm/oop/instanceKlass.h>
#include <kivm/runtime/thread.h>
#include <kivm/runtime/stack.h>
#include <kivm/runtime/constantPool.h>
#include <deque>

/* used in NEWARRAY */
#define T_BOOLEAN               4
#define T_CHAR                  5
#define T_FLOAT                 6
#define T_DOUBLE                7
#define T_BYTE                  8
#define T_SHORT                 9
#define T_INT                  10
#define T_LONG                 11

namespace kivm {
    class Resolver {
    public:
        static oop javaOop(jobject obj);

        static instanceOop instance(jobject obj);

        static mirrorOop mirror(jobject obj);

        static arrayOop array(jobject obj);

        static typeArrayOop typeArray(jobject obj);

        static objectArrayOop objectArray(jobject object);

        static Klass* javaClass(jclass clazz);

        static InstanceKlass *instanceClass(jclass clazz);

        static void *nativePointer(Method *method);
    };

    /**
     * Each country has an execution officer,
     * and virtual machines are no exception.
     */
    class Execution {
    public:
        static oop invokeInterface(JavaThread *thread, RuntimeConstantPool *rt,
                                    Stack &stack, int constantIndex, int count);

        static oop invokeVirtual(JavaThread *thread, RuntimeConstantPool *rt,
                                  Stack &stack, int constantIndex);

        static oop invokeStatic(JavaThread *thread, RuntimeConstantPool *rt,
                                 Stack &stack, int constantIndex);

        static oop invokeSpecial(JavaThread *thread, RuntimeConstantPool *rt,
                                  Stack &stack, int constantIndex);

        static void putField(JavaThread *thread, RuntimeConstantPool *rt,
                             Stack &stack, int constantIndex, bool isStatic);

        static void getField(JavaThread *thread, RuntimeConstantPool *rt,
                             instanceOop receiver, Stack &stack,
                             int constantIndex);

        static void loadIntArrayElement(Stack &stack);

        static void loadFloatArrayElement(Stack &stack);

        static void loadDoubleArrayElement(Stack &stack);

        static void loadLongArrayElement(Stack &stack);

        static void loadObjectArrayElement(Stack &stack);

        static void storeIntArrayElement(Stack &stack);

        static void storeFloatArrayElement(Stack &stack);

        static void storeDoubleArrayElement(Stack &stack);

        static void storeLongArrayElement(Stack &stack);

        static void storeObjectArrayElement(Stack &stack);

        static void loadConstant(RuntimeConstantPool *rt, Stack &stack,
                                 int constantIndex);

        static void initializeClass(JavaThread *javaThread, InstanceKlass *klass);

        static bool instanceOf(Klass *S, Klass *T);

        static void instanceOf(RuntimeConstantPool *rt, Stack &stack, int constantIndex,
                               bool checkCast);

        static instanceOop newInstance(JavaThread *thread, RuntimeConstantPool *rt,
                                       int constantIndex);

        static typeArrayOop newPrimitiveArray(JavaThread *thread,
                                              int arrayType, int length);

        static objectArrayOop newObjectArray(JavaThread *thread, RuntimeConstantPool *rt,
                                             int constantIndex, int length);

        static arrayOop newMultiObjectArray(JavaThread *thread, RuntimeConstantPool *rt,
                                            int constantIndex, int dimension,
                                            const std::deque<int> &length);
    };
}
