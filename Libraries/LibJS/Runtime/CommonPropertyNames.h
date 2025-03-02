/*
 * Copyright (c) 2020, Andreas Kling <andreas@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/DeprecatedFlyString.h>
#include <LibJS/Forward.h>
#include <LibJS/Runtime/PropertyKey.h>

namespace JS {

#define ENUMERATE_STANDARD_PROPERTY_NAMES(P) \
    P(_)                                     \
    P(__defineGetter__)                      \
    P(__defineSetter__)                      \
    P(__lookupGetter__)                      \
    P(__lookupSetter__)                      \
    P(__proto__)                             \
    P($1)                                    \
    P($2)                                    \
    P($3)                                    \
    P($4)                                    \
    P($5)                                    \
    P($6)                                    \
    P($7)                                    \
    P($8)                                    \
    P($9)                                    \
    P(abs)                                   \
    P(acos)                                  \
    P(acosh)                                 \
    P(add)                                   \
    P(adopt)                                 \
    P(all)                                   \
    P(allSettled)                            \
    P(alphabet)                              \
    P(anchor)                                \
    P(any)                                   \
    P(apply)                                 \
    P(arguments)                             \
    P(asin)                                  \
    P(asinh)                                 \
    P(asIntN)                                \
    P(assert)                                \
    P(assign)                                \
    P(asUintN)                               \
    P(at)                                    \
    P(atan)                                  \
    P(atan2)                                 \
    P(atanh)                                 \
    P(Atomics)                               \
    P(baseName)                              \
    P(big)                                   \
    P(BigInt)                                \
    P(bind)                                  \
    P(blank)                                 \
    P(blink)                                 \
    P(bold)                                  \
    P(Boolean)                               \
    P(buffer)                                \
    P(byteLength)                            \
    P(byteOffset)                            \
    P(BYTES_PER_ELEMENT)                     \
    P(calendar)                              \
    P(calendarId)                            \
    P(calendarName)                          \
    P(call)                                  \
    P(callee)                                \
    P(caller)                                \
    P(caseFirst)                             \
    P(cause)                                 \
    P(cbrt)                                  \
    P(ceil)                                  \
    P(charAt)                                \
    P(charCodeAt)                            \
    P(cleanupSome)                           \
    P(clear)                                 \
    P(clz32)                                 \
    P(codePointAt)                           \
    P(collation)                             \
    P(compactDisplay)                        \
    P(compare)                               \
    P(compareExchange)                       \
    P(compile)                               \
    P(composite)                             \
    P(computedOffset)                        \
    P(concat)                                \
    P(configurable)                          \
    P(console)                               \
    P(construct)                             \
    P(constructor)                           \
    P(containing)                            \
    P(copyWithin)                            \
    P(cos)                                   \
    P(cosh)                                  \
    P(columns)                               \
    P(count)                                 \
    P(countReset)                            \
    P(create)                                \
    P(currency)                              \
    P(currencyDisplay)                       \
    P(currencySign)                          \
    P(dateStyle)                             \
    P(day)                                   \
    P(dayOfWeek)                             \
    P(dayOfYear)                             \
    P(dayPeriod)                             \
    P(days)                                  \
    P(daysDisplay)                           \
    P(daysInMonth)                           \
    P(daysInWeek)                            \
    P(daysInYear)                            \
    P(debug)                                 \
    P(decodeURI)                             \
    P(decodeURIComponent)                    \
    P(defer)                                 \
    P(defineProperties)                      \
    P(defineProperty)                        \
    P(deleteProperty)                        \
    P(deref)                                 \
    P(description)                           \
    P(detached)                              \
    P(difference)                            \
    P(dir)                                   \
    P(direction)                             \
    P(disabledFeatures)                      \
    P(disambiguation)                        \
    P(disposeAsync)                          \
    P(disposed)                              \
    P(done)                                  \
    P(dotAll)                                \
    P(drop)                                  \
    P(E)                                     \
    P(easing)                                \
    P(encodeURI)                             \
    P(encodeURIComponent)                    \
    P(endsWith)                              \
    P(entries)                               \
    P(enumerable)                            \
    P(epochMilliseconds)                     \
    P(epochNanoseconds)                      \
    P(EPSILON)                               \
    P(equals)                                \
    P(era)                                   \
    P(eraYear)                               \
    P(error)                                 \
    P(errors)                                \
    P(escape)                                \
    P(eval)                                  \
    P(evaluate)                              \
    P(every)                                 \
    P(exchange)                              \
    P(exec)                                  \
    P(exp)                                   \
    P(expm1)                                 \
    P(f16round)                              \
    P(fallback)                              \
    P(fill)                                  \
    P(filter)                                \
    P(finally)                               \
    P(find)                                  \
    P(findIndex)                             \
    P(findLast)                              \
    P(findLastIndex)                         \
    P(firstDay)                              \
    P(firstDayOfWeek)                        \
    P(fixed)                                 \
    P(flags)                                 \
    P(flat)                                  \
    P(flatMap)                               \
    P(floor)                                 \
    P(fontcolor)                             \
    P(fontsize)                              \
    P(forEach)                               \
    P(formAssociated)                        \
    P(format)                                \
    P(formatMatcher)                         \
    P(formatRange)                           \
    P(formatRangeToParts)                    \
    P(formatToParts)                         \
    P(fractionalDigits)                      \
    P(fractionalSecondDigits)                \
    P(freeze)                                \
    P(from)                                  \
    P(fromAsync)                             \
    P(fromBase64)                            \
    P(fromCharCode)                          \
    P(fromCodePoint)                         \
    P(fromEntries)                           \
    P(fromEpochMilliseconds)                 \
    P(fromEpochNanoseconds)                  \
    P(fromHex)                               \
    P(fround)                                \
    P(Function)                              \
    P(gc)                                    \
    P(get)                                   \
    P(getBigInt64)                           \
    P(getBigUint64)                          \
    P(getCalendars)                          \
    P(getCanonicalLocales)                   \
    P(getCollations)                         \
    P(getDate)                               \
    P(getDay)                                \
    P(getFloat16)                            \
    P(getFloat32)                            \
    P(getFloat64)                            \
    P(getFullYear)                           \
    P(getHourCycles)                         \
    P(getHours)                              \
    P(getInt8)                               \
    P(getInt16)                              \
    P(getInt32)                              \
    P(getMilliseconds)                       \
    P(getMinutes)                            \
    P(getMonth)                              \
    P(getNumberingSystems)                   \
    P(getOwnPropertyDescriptor)              \
    P(getOwnPropertyDescriptors)             \
    P(getOwnPropertyNames)                   \
    P(getOwnPropertySymbols)                 \
    P(getPrototypeOf)                        \
    P(getSeconds)                            \
    P(getTextInfo)                           \
    P(getTime)                               \
    P(getTimezoneOffset)                     \
    P(getTimeZones)                          \
    P(getTimeZoneTransition)                 \
    P(getUint8)                              \
    P(getUint16)                             \
    P(getUint32)                             \
    P(getUTCDate)                            \
    P(getUTCDay)                             \
    P(getUTCFullYear)                        \
    P(getUTCHours)                           \
    P(getUTCMilliseconds)                    \
    P(getUTCMinutes)                         \
    P(getUTCMonth)                           \
    P(getUTCSeconds)                         \
    P(getWeekInfo)                           \
    P(getYear)                               \
    P(global)                                \
    P(globalThis)                            \
    P(granularity)                           \
    P(group)                                 \
    P(groupBy)                               \
    P(groupCollapsed)                        \
    P(groupEnd)                              \
    P(groups)                                \
    P(has)                                   \
    P(hasIndices)                            \
    P(hasOwn)                                \
    P(hasOwnProperty)                        \
    P(hour)                                  \
    P(hour12)                                \
    P(hourCycle)                             \
    P(hours)                                 \
    P(hoursDisplay)                          \
    P(hoursInDay)                            \
    P(hypot)                                 \
    P(id)                                    \
    P(ignoreCase)                            \
    P(ignorePunctuation)                     \
    P(importValue)                           \
    P(imul)                                  \
    P(includes)                              \
    P(index)                                 \
    P(indexOf)                               \
    P(indices)                               \
    P(Infinity)                              \
    P(info)                                  \
    P(inLeapYear)                            \
    P(input)                                 \
    P(instant)                               \
    P(intersection)                          \
    P(Intl)                                  \
    P(is)                                    \
    P(isArray)                               \
    P(isDisjointFrom)                        \
    P(isError)                               \
    P(isExtensible)                          \
    P(isFinite)                              \
    P(isFrozen)                              \
    P(isInteger)                             \
    P(isLockFree)                            \
    P(isNaN)                                 \
    P(isPrototypeOf)                         \
    P(isSafeInteger)                         \
    P(isSealed)                              \
    P(isSubsetOf)                            \
    P(isSupersetOf)                          \
    P(isView)                                \
    P(isWellFormed)                          \
    P(isWordLike)                            \
    P(italics)                               \
    P(join)                                  \
    P(JSON)                                  \
    P(keyFor)                                \
    P(keys)                                  \
    P(language)                              \
    P(languageDisplay)                       \
    P(largestUnit)                           \
    P(lastChunkHandling)                     \
    P(lastIndex)                             \
    P(lastIndexOf)                           \
    P(lastMatch)                             \
    P(lastParen)                             \
    P(leftContext)                           \
    P(length)                                \
    P(link)                                  \
    P(LN10)                                  \
    P(LN2)                                   \
    P(load)                                  \
    P(locale)                                \
    P(localeCompare)                         \
    P(localeMatcher)                         \
    P(log)                                   \
    P(log10)                                 \
    P(LOG10E)                                \
    P(log1p)                                 \
    P(log2)                                  \
    P(LOG2E)                                 \
    P(map)                                   \
    P(Math)                                  \
    P(max)                                   \
    P(MAX_SAFE_INTEGER)                      \
    P(MAX_VALUE)                             \
    P(maxByteLength)                         \
    P(maximize)                              \
    P(maximumFractionDigits)                 \
    P(maximumSignificantDigits)              \
    P(message)                               \
    P(microsecond)                           \
    P(microseconds)                          \
    P(microsecondsDisplay)                   \
    P(millisecond)                           \
    P(milliseconds)                          \
    P(millisecondsDisplay)                   \
    P(min)                                   \
    P(MIN_SAFE_INTEGER)                      \
    P(MIN_VALUE)                             \
    P(minimalDays)                           \
    P(minimize)                              \
    P(minimumFractionDigits)                 \
    P(minimumIntegerDigits)                  \
    P(minimumSignificantDigits)              \
    P(minute)                                \
    P(minutes)                               \
    P(minutesDisplay)                        \
    P(month)                                 \
    P(monthCode)                             \
    P(months)                                \
    P(monthsDisplay)                         \
    P(monthsInYear)                          \
    P(move)                                  \
    P(multiline)                             \
    P(name)                                  \
    P(NaN)                                   \
    P(nanosecond)                            \
    P(nanoseconds)                           \
    P(nanosecondsDisplay)                    \
    P(negated)                               \
    P(NEGATIVE_INFINITY)                     \
    P(next)                                  \
    P(normalize)                             \
    P(notation)                              \
    P(notify)                                \
    P(Now)                                   \
    P(now)                                   \
    P(Number)                                \
    P(numberingSystem)                       \
    P(numeric)                               \
    P(observedAttributes)                    \
    P(of)                                    \
    P(offset)                                \
    P(offsetNanoseconds)                     \
    P(omitPadding)                           \
    P(opener)                                \
    P(overflow)                              \
    P(ownKeys)                               \
    P(padEnd)                                \
    P(padStart)                              \
    P(parse)                                 \
    P(parseFloat)                            \
    P(parseInt)                              \
    P(pause)                                 \
    P(PI)                                    \
    P(plainDateISO)                          \
    P(plainDateTimeISO)                      \
    P(plainTime)                             \
    P(plainTimeISO)                          \
    P(pluralCategories)                      \
    P(pop)                                   \
    P(POSITIVE_INFINITY)                     \
    P(pow)                                   \
    P(preventExtensions)                     \
    P(promise)                               \
    P(propertyIsEnumerable)                  \
    P(prototype)                             \
    P(Proxy)                                 \
    P(proxy)                                 \
    P(push)                                  \
    P(race)                                  \
    P(random)                                \
    P(raw)                                   \
    P(read)                                  \
    P(reason)                                \
    P(reduce)                                \
    P(reduceRight)                           \
    P(Reflect)                               \
    P(RegExp)                                \
    P(region)                                \
    P(reject)                                \
    P(relativeTo)                            \
    P(repeat)                                \
    P(resizable)                             \
    P(resize)                                \
    P(resolve)                               \
    P(resolvedOptions)                       \
    P(reverse)                               \
    P(revocable)                             \
    P(revoke)                                \
    P(rightContext)                          \
    P(round)                                 \
    P(roundingIncrement)                     \
    P(roundingMode)                          \
    P(roundingPriority)                      \
    P(rows)                                  \
    P(script)                                \
    P(seal)                                  \
    P(second)                                \
    P(seconds)                               \
    P(secondsDisplay)                        \
    P(segment)                               \
    P(select)                                \
    P(selectRange)                           \
    P(sensitivity)                           \
    P(set)                                   \
    P(setBigInt64)                           \
    P(setBigUint64)                          \
    P(setDate)                               \
    P(setFloat16)                            \
    P(setFloat32)                            \
    P(setFloat64)                            \
    P(setFromBase64)                         \
    P(setFromHex)                            \
    P(setFullYear)                           \
    P(setHours)                              \
    P(setInt8)                               \
    P(setInt16)                              \
    P(setInt32)                              \
    P(setMilliseconds)                       \
    P(setMinutes)                            \
    P(setMonth)                              \
    P(setPrototypeOf)                        \
    P(setSeconds)                            \
    P(setTime)                               \
    P(setUint8)                              \
    P(setUint16)                             \
    P(setUint32)                             \
    P(setUTCDate)                            \
    P(setUTCFullYear)                        \
    P(setUTCHours)                           \
    P(setUTCMilliseconds)                    \
    P(setUTCMinutes)                         \
    P(setUTCMonth)                           \
    P(setUTCSeconds)                         \
    P(setYear)                               \
    P(shift)                                 \
    P(sign)                                  \
    P(signDisplay)                           \
    P(sin)                                   \
    P(since)                                 \
    P(sinh)                                  \
    P(size)                                  \
    P(slice)                                 \
    P(small)                                 \
    P(smallestUnit)                          \
    P(some)                                  \
    P(sort)                                  \
    P(source)                                \
    P(splice)                                \
    P(sqrt)                                  \
    P(SQRT1_2)                               \
    P(SQRT2)                                 \
    P(stack)                                 \
    P(startOfDay)                            \
    P(startsWith)                            \
    P(status)                                \
    P(sticky)                                \
    P(store)                                 \
    P(strike)                                \
    P(String)                                \
    P(stringify)                             \
    P(style)                                 \
    P(sub)                                   \
    P(subarray)                              \
    P(substr)                                \
    P(substring)                             \
    P(subtract)                              \
    P(sumPrecise)                            \
    P(sup)                                   \
    P(supportedLocalesOf)                    \
    P(supportedValuesOf)                     \
    P(suppressed)                            \
    P(Symbol)                                \
    P(symmetricDifference)                   \
    P(table)                                 \
    P(take)                                  \
    P(tan)                                   \
    P(tanh)                                  \
    P(Temporal)                              \
    P(test)                                  \
    P(then)                                  \
    P(time)                                  \
    P(timeEnd)                               \
    P(timeLog)                               \
    P(timeStyle)                             \
    P(timeZone)                              \
    P(timeZoneId)                            \
    P(timeZoneName)                          \
    P(toArray)                               \
    P(toBase64)                              \
    P(toDateString)                          \
    P(toExponential)                         \
    P(toFixed)                               \
    P(toGMTString)                           \
    P(toHex)                                 \
    P(toInstant)                             \
    P(toISOString)                           \
    P(toJSON)                                \
    P(toLocaleDateString)                    \
    P(toLocaleLowerCase)                     \
    P(toLocaleString)                        \
    P(toLocaleTimeString)                    \
    P(toLocaleUpperCase)                     \
    P(toLowerCase)                           \
    P(toPlainDate)                           \
    P(toPlainDateTime)                       \
    P(toPlainMonthDay)                       \
    P(toPlainTime)                           \
    P(toPlainYearMonth)                      \
    P(toPrecision)                           \
    P(toReversed)                            \
    P(toSorted)                              \
    P(toSpliced)                             \
    P(toString)                              \
    P(total)                                 \
    P(toTemporalInstant)                     \
    P(toTimeString)                          \
    P(toUpperCase)                           \
    P(toUTCString)                           \
    P(toWellFormed)                          \
    P(toZonedDateTime)                       \
    P(toZonedDateTimeISO)                    \
    P(trace)                                 \
    P(trailingZeroDisplay)                   \
    P(transfer)                              \
    P(transferToFixedLength)                 \
    P(trim)                                  \
    P(trimEnd)                               \
    P(trimLeft)                              \
    P(trimRight)                             \
    P(trimStart)                             \
    P(trunc)                                 \
    P(type)                                  \
    P(undefined)                             \
    P(unescape)                              \
    P(unicode)                               \
    P(unicodeSets)                           \
    P(unit)                                  \
    P(unitDisplay)                           \
    P(unregister)                            \
    P(unshift)                               \
    P(until)                                 \
    P(usage)                                 \
    P(use)                                   \
    P(useGrouping)                           \
    P(UTC)                                   \
    P(Value)                                 \
    P(value)                                 \
    P(valueOf)                               \
    P(values)                                \
    P(wait)                                  \
    P(waitAsync)                             \
    P(warn)                                  \
    P(weekday)                               \
    P(weekend)                               \
    P(weekOfYear)                            \
    P(week)                                  \
    P(weeks)                                 \
    P(weeksDisplay)                          \
    P(with)                                  \
    P(withCalendar)                          \
    P(withPlainTime)                         \
    P(withResolvers)                         \
    P(withTimeZone)                          \
    P(writable)                              \
    P(written)                               \
    P(year)                                  \
    P(yearOfWeek)                            \
    P(years)                                 \
    P(yearsDisplay)                          \
    P(zonedDateTimeISO)

struct CommonPropertyNames {
    PropertyKey and_ { "and", PropertyKey::StringMayBeNumber::No };
    PropertyKey catch_ { "catch", PropertyKey::StringMayBeNumber::No };
    PropertyKey delete_ { "delete", PropertyKey::StringMayBeNumber::No };
    PropertyKey for_ { "for", PropertyKey::StringMayBeNumber::No };
    PropertyKey or_ { "or", PropertyKey::StringMayBeNumber::No };
    PropertyKey register_ { "register", PropertyKey::StringMayBeNumber::No };
    PropertyKey return_ { "return", PropertyKey::StringMayBeNumber::No };
    PropertyKey throw_ { "throw", PropertyKey::StringMayBeNumber::No };
    PropertyKey try_ { "try", PropertyKey::StringMayBeNumber::No };
    PropertyKey union_ { "union", PropertyKey::StringMayBeNumber::No };
    PropertyKey xor_ { "xor", PropertyKey::StringMayBeNumber::No };
    PropertyKey inputAlias { "$_", PropertyKey::StringMayBeNumber::No };
    PropertyKey lastMatchAlias { "$&", PropertyKey::StringMayBeNumber::No };
    PropertyKey lastParenAlias { "$+", PropertyKey::StringMayBeNumber::No };
    PropertyKey leftContextAlias { "$`", PropertyKey::StringMayBeNumber::No };
    PropertyKey rightContextAlias { "$'", PropertyKey::StringMayBeNumber::No };
#define __ENUMERATE(x) PropertyKey x { #x, PropertyKey::StringMayBeNumber::No };
    ENUMERATE_STANDARD_PROPERTY_NAMES(__ENUMERATE)
#undef __ENUMERATE
#define __JS_ENUMERATE(x, a, b, c, t) PropertyKey x { #x, PropertyKey::StringMayBeNumber::No };
    JS_ENUMERATE_BUILTIN_TYPES
#undef __JS_ENUMERATE
#define __JS_ENUMERATE(x, a, b, c) PropertyKey x { #x, PropertyKey::StringMayBeNumber::No };
    JS_ENUMERATE_INTL_OBJECTS
#undef __JS_ENUMERATE
#define __JS_ENUMERATE(x, a, b, c) PropertyKey x { #x, PropertyKey::StringMayBeNumber::No };
    JS_ENUMERATE_TEMPORAL_OBJECTS
#undef __JS_ENUMERATE
#define __JS_ENUMERATE(x, a) PropertyKey x { #x, PropertyKey::StringMayBeNumber::No };
    JS_ENUMERATE_WELL_KNOWN_SYMBOLS
#undef __JS_ENUMERATE
};

}
