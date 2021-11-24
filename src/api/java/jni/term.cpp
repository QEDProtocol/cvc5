/******************************************************************************
 * Top contributors (to current version):
 *   Mudathir Mohamed
 *
 * This file is part of the cvc5 project.
 *
 * Copyright (c) 2009-2021 by the authors listed in the file AUTHORS
 * in the top-level source directory and their institutional affiliations.
 * All rights reserved.  See the file COPYING in the top-level source
 * directory for licensing information.
 * ****************************************************************************
 *
 * The cvc5 Java API.
 */

#include "api/cpp/cvc5.h"
#include "api_utilities.h"
#include "io_github_cvc5_api_Term.h"

using namespace cvc5::api;

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    deletePointer
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_io_github_cvc5_api_Term_deletePointer(JNIEnv* env,
                                                                  jobject,
                                                                  jlong pointer)
{
  delete reinterpret_cast<Term*>(pointer);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    equals
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_equals(JNIEnv* env,
                                                               jobject,
                                                               jlong pointer1,
                                                               jlong pointer2)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* term1 = reinterpret_cast<Term*>(pointer1);
  Term* term2 = reinterpret_cast<Term*>(pointer2);
  // We compare the actual terms, not their pointers.
  return static_cast<jboolean>(*term1 == *term2);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    compareTo
 * Signature: (JJ)I
 */
JNIEXPORT jint JNICALL Java_io_github_cvc5_api_Term_compareTo(JNIEnv* env,
                                                              jobject,
                                                              jlong pointer1,
                                                              jlong pointer2)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* term1 = reinterpret_cast<Term*>(pointer1);
  Term* term2 = reinterpret_cast<Term*>(pointer2);
  if (*term1 < *term2)
  {
    return static_cast<jint>(-1);
  }
  if (*term1 == *term2)
  {
    return 0;
  }
  return static_cast<jint>(1);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getNumChildren
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_io_github_cvc5_api_Term_getNumChildren(JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jint>(current->getNumChildren());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getChild
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_io_github_cvc5_api_Term_getChild(JNIEnv* env,
                                                              jobject,
                                                              jlong pointer,
                                                              jint index)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  Term* ret = new Term((*current)[static_cast<size_t>(index)]);
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getId
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_io_github_cvc5_api_Term_getId(JNIEnv* env,
                                                           jobject,
                                                           jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jlong>(current->getId());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getKind
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_io_github_cvc5_api_Term_getKind(JNIEnv* env,
                                                            jobject,
                                                            jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jint>(current->getKind());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_io_github_cvc5_api_Term_getSort(JNIEnv* env,
                                                             jobject,
                                                             jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  Sort* ret = new Sort(current->getSort());
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    substitute
 * Signature: (JJJ)J
 */
JNIEXPORT jlong JNICALL
Java_io_github_cvc5_api_Term_substitute__JJJ(JNIEnv* env,
                                             jobject,
                                             jlong pointer,
                                             jlong termPointer,
                                             jlong replacementPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  Term* replacement = reinterpret_cast<Term*>(replacementPointer);
  Term* ret = new Term(current->substitute(*term, *replacement));
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    substitute
 * Signature: (J[J[J)J
 */
JNIEXPORT jlong JNICALL
Java_io_github_cvc5_api_Term_substitute__J_3J_3J(JNIEnv* env,
                                                 jobject,
                                                 jlong pointer,
                                                 jlongArray termPointers,
                                                 jlongArray replacementPointers)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  jsize termsSize = env->GetArrayLength(termPointers);
  jsize replacementsSize = env->GetArrayLength(replacementPointers);
  jlong* termElements = env->GetLongArrayElements(termPointers, nullptr);
  jlong* replacementElements =
      env->GetLongArrayElements(replacementPointers, nullptr);

  std::vector<Term> terms(termsSize);
  std::vector<Term> replacements(replacementsSize);

  for (jsize i = 0; i < termsSize; i++)
  {
    Term* term = (Term*)termElements[i];
    terms[i] = *term;
  }
  env->ReleaseLongArrayElements(termPointers, termElements, 0);

  for (jsize i = 0; i < replacementsSize; i++)
  {
    Term* term = (Term*)replacementElements[i];
    replacements[i] = *term;
  }
  env->ReleaseLongArrayElements(replacementPointers, replacementElements, 0);

  Term* ret = new Term(current->substitute(terms, replacements));
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    hasOp
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_hasOp(JNIEnv* env,
                                                              jobject,
                                                              jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->hasOp());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getOp
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_io_github_cvc5_api_Term_getOp(JNIEnv* env,
                                                           jobject,
                                                           jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  Op* ret = new Op(current->getOp());
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    hasSymbol
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_hasSymbol(JNIEnv* env,
                                                                  jobject,
                                                                  jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->hasSymbol());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getSymbol
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_io_github_cvc5_api_Term_getSymbol(JNIEnv* env,
                                                                 jobject,
                                                                 jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return env->NewStringUTF(current->getSymbol().c_str());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isNull
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_isNull(JNIEnv* env,
                                                               jobject,
                                                               jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isNull());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isConstArray
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_io_github_cvc5_api_Term_isConstArray(JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isConstArray());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getConstArrayBase
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_io_github_cvc5_api_Term_getConstArrayBase(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  Term* ret = new Term(current->getConstArrayBase());
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    notTerm
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_io_github_cvc5_api_Term_notTerm(JNIEnv* env,
                                                             jobject,
                                                             jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  Term* ret = new Term(current->notTerm());
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    andTerm
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_io_github_cvc5_api_Term_andTerm(JNIEnv* env,
                                                             jobject,
                                                             jlong pointer,
                                                             jlong termPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  Term* ret = new Term(current->andTerm(*term));
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    orTerm
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_io_github_cvc5_api_Term_orTerm(JNIEnv* env,
                                                            jobject,
                                                            jlong pointer,
                                                            jlong termPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  Term* ret = new Term(current->orTerm(*term));
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    xorTerm
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_io_github_cvc5_api_Term_xorTerm(JNIEnv* env,
                                                             jobject,
                                                             jlong pointer,
                                                             jlong termPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  Term* ret = new Term(current->xorTerm(*term));
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    eqTerm
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_io_github_cvc5_api_Term_eqTerm(JNIEnv* env,
                                                            jobject,
                                                            jlong pointer,
                                                            jlong termPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  Term* ret = new Term(current->eqTerm(*term));
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    impTerm
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_io_github_cvc5_api_Term_impTerm(JNIEnv* env,
                                                             jobject,
                                                             jlong pointer,
                                                             jlong termPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  Term* ret = new Term(current->impTerm(*term));
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    iteTerm
 * Signature: (JJJ)J
 */
JNIEXPORT jlong JNICALL Java_io_github_cvc5_api_Term_iteTerm(
    JNIEnv* env, jobject, jlong pointer, jlong thenPointer, jlong elsePointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  Term* thenTerm = reinterpret_cast<Term*>(thenPointer);
  Term* elseTerm = reinterpret_cast<Term*>(elsePointer);
  Term* ret = new Term(current->iteTerm(*thenTerm, *elseTerm));
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    toString
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_io_github_cvc5_api_Term_toString(JNIEnv* env,
                                                                jobject,
                                                                jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return env->NewStringUTF(current->toString().c_str());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isIntegerValue
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_io_github_cvc5_api_Term_isIntegerValue(JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isIntegerValue());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getIntegerValue
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_io_github_cvc5_api_Term_getIntegerValue(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  std::string value = current->getIntegerValue();
  jstring ret = env->NewStringUTF(value.c_str());
  return ret;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isStringValue
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_io_github_cvc5_api_Term_isStringValue(JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isStringValue());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getStringValue
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_io_github_cvc5_api_Term_getStringValue(JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  std::wstring termString = current->getStringValue();

  size_t length = termString.length();
  jchar* unicode = new jchar[length];
  const wchar_t* s = termString.c_str();
  for (size_t i = 0; i < length; i++)
  {
    unicode[i] = s[i];
  }
  jstring ret = env->NewString(unicode, length);
  delete[] unicode;
  return ret;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isRealValue
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_io_github_cvc5_api_Term_isRealValue(JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isRealValue());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getRealValue
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_io_github_cvc5_api_Term_getRealValue(JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  std::string realValue = current->getRealValue();
  return env->NewStringUTF(realValue.c_str());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isBooleanValue
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_io_github_cvc5_api_Term_isBooleanValue(JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isBooleanValue());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getBooleanValue
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_getBooleanValue(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->getBooleanValue());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isBitVectorValue
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_isBitVectorValue(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isBitVectorValue());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getBitVectorValue
 * Signature: (JI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_io_github_cvc5_api_Term_getBitVectorValue(
    JNIEnv* env, jobject, jlong pointer, jint base)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  std::string ret =
      current->getBitVectorValue(static_cast<std::uint32_t>(base));
  return env->NewStringUTF(ret.c_str());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isAbstractValue
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_isAbstractValue(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isAbstractValue());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getAbstractValue
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_io_github_cvc5_api_Term_getAbstractValue(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  std::string ret = current->getAbstractValue();
  return env->NewStringUTF(ret.c_str());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isTupleValue
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_io_github_cvc5_api_Term_isTupleValue(JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isTupleValue());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getTupleValue
 * Signature: (J)[J
 */
JNIEXPORT jlongArray JNICALL
Java_io_github_cvc5_api_Term_getTupleValue(JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  std::vector<Term> terms = current->getTupleValue();
  jlongArray ret = getPointersFromObjects<Term>(env, terms);
  return ret;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isFloatingPointPosZero
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_isFloatingPointPosZero(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isFloatingPointPosZero());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isFloatingPointNegZero
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_isFloatingPointNegZero(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isFloatingPointNegZero());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isFloatingPointPosInf
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_isFloatingPointPosInf(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isFloatingPointPosInf());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isFloatingPointNegInf
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_isFloatingPointNegInf(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isFloatingPointNegInf());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isFloatingPointNaN
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_isFloatingPointNaN(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isFloatingPointNaN());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isFloatingPointValue
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_isFloatingPointValue(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isFloatingPointValue());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getFloatingPointValue
 * Signature: (J)Lio/github/cvc5/api/Triplet;
 */
JNIEXPORT jobject JNICALL Java_io_github_cvc5_api_Term_getFloatingPointValue(
    JNIEnv* env, jobject thisObject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  auto [exponent, significand, term] = current->getFloatingPointValue();
  Term* termPointer = new Term(term);

  // Long longObject = new Long(pointer)
  jclass longClass = env->FindClass("Ljava/lang/Long;");
  jmethodID longConstructor = env->GetMethodID(longClass, "<init>", "(J)V");
  jobject e = env->NewObject(longClass, longConstructor, exponent);
  jobject s = env->NewObject(longClass, longConstructor, significand);
  jobject t = env->NewObject(longClass, longConstructor, termPointer);

  // Triplet triplet = new Triplet<Long, Long, Long>(e, s, t);
  jclass tripletClass = env->FindClass("Lio/github/cvc5/api/Triplet;");
  jmethodID tripletConstructor = env->GetMethodID(
      tripletClass,
      "<init>",
      "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)V");
  jobject triplet = env->NewObject(tripletClass, tripletConstructor, e, s, t);

  return triplet;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isSetValue
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_io_github_cvc5_api_Term_isSetValue(JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isSetValue());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getSetValue
 * Signature: (J)[J
 */
JNIEXPORT jlongArray JNICALL
Java_io_github_cvc5_api_Term_getSetValue(JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  std::set<Term> terms = current->getSetValue();
  std::vector<jlong> pointers(terms.size());
  int i = 0;
  for (const Term& t : terms)
  {
    pointers[i] = reinterpret_cast<jlong>(new Term(t));
    i++;
  }
  jlongArray ret = env->NewLongArray(pointers.size());
  env->SetLongArrayRegion(ret, 0, pointers.size(), pointers.data());
  return ret;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isSequenceValue
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_isSequenceValue(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isSequenceValue());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getSequenceValue
 * Signature: (J)[J
 */
JNIEXPORT jlongArray JNICALL Java_io_github_cvc5_api_Term_getSequenceValue(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  std::vector<Term> terms = current->getSequenceValue();
  jlongArray ret = getPointersFromObjects<Term>(env, terms);
  return ret;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    isUninterpretedValue
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_github_cvc5_api_Term_isUninterpretedValue(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  return static_cast<jboolean>(current->isUninterpretedValue());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    getUninterpretedValue
 * Signature: (J)Lio/github/cvc5/api/Pair;
 */
JNIEXPORT jobject JNICALL Java_io_github_cvc5_api_Term_getUninterpretedValue(
    JNIEnv* env, jobject, jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  std::pair<Sort, std::int32_t> value = current->getUninterpretedValue();

  Sort* sort = new Sort(value.first);
  jlong sortPointer = reinterpret_cast<jlong>(sort);

  // Long longObject = new Long(pointer)
  jclass longClass = env->FindClass("Ljava/lang/Long;");
  jmethodID longConstructor = env->GetMethodID(longClass, "<init>", "(J)V");
  jobject longObject = env->NewObject(longClass, longConstructor, sortPointer);

  // Integer integerObject = new Integer(pair.second)
  jclass integerClass = env->FindClass("Ljava/lang/Integer;");
  jmethodID integerConstructor =
      env->GetMethodID(integerClass, "<init>", "(I)V");
  jobject integerObject = env->NewObject(
      integerClass, integerConstructor, static_cast<jint>(value.second));

  // Pair<String, Long> pair = new Pair<String, Long>(jName, longObject)
  jclass pairClass = env->FindClass("Lio/github/cvc5/api/Pair;");
  jmethodID pairConstructor = env->GetMethodID(
      pairClass, "<init>", "(Ljava/lang/Object;Ljava/lang/Object;)V");
  jobject pair =
      env->NewObject(pairClass, pairConstructor, longObject, integerObject);

  return pair;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     io_github_cvc5_api_Term
 * Method:    iterator
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_io_github_cvc5_api_Term_iterator(JNIEnv* env,
                                                              jobject,
                                                              jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* current = reinterpret_cast<Term*>(pointer);
  Term::const_iterator* retPointer = new Term::const_iterator(current->begin());
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}