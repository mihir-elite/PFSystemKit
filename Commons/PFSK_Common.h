//
//  PFSK_Common.h
//  PFSystemKit
//
//  Created by Perceval FARAMAZ on 19/04/15.
//  Copyright (c) 2015 Perceval FARAMAZ. All rights reserved.
//

#import <Foundation/Foundation.h>
#if defined(__cplusplus)
#import <string>
#endif
#import "PFSKTypes.h"
#import "PFSystemCPUReport.h"
#import "PFSystemBatteryReport.h"
#import "PFSystemPlatformReport.h"
#import "PFSystemRAMStatistics.h"

@interface PFSK_Common : NSObject {
    NSError *error;
@protected
    PFSystemKitError errorCode;
    kern_return_t extErrorCode;
    PFSystemKitLockState writeLockState;
}

/*!
 @discussion Translates a PFSystemKitError to a human-readable string
 @param err Any member of the PFSystemKitError enum
 @returns A NSString holding the PFSystemKitError string value
 */
+(NSString*) errorToString:(PFSystemKitError)err;
inline NSString* errorToString(PFSystemKitError err);

/*!
 @discussion Explains a PFSystemKitError
 @param err Any member of the PFSystemKitError enum
 @returns A NSString holding the explanation
 */
+(NSString*) errorToExplanation:(PFSystemKitError)err;
inline NSString* errorToExplanation(PFSystemKitError err);

/*!
 @discussion Explains how to recover from a PFSystemKitError
 @param err Any member of the PFSystemKitError enum
 @returns A NSString holding the recovery details
 */
+(NSString*) errorToRecovery:(PFSystemKitError)err;
inline NSString* errorToRecovery(PFSystemKitError err);

/*!
 @discussion Translates a kern_return_t to a human-readable string
 @abstract Wraps mach_error_string()
 @param err Any int, that is a valid error code
 @returns A NSString holding the error string
 */
+(NSString*) iokitErrorToString:(kern_return_t)err;

/*!
 @discussion Matches a PFSystemKitPlatform to a displayable NSString
 @param platform Any member of the PFSystemKitPlatform enum
 @returns A NSString holding the platform string
 */
+(NSString*) platformToString:(PFSystemKitPlatform)platform;

/*!
 @discussion Matches a NSString to its PFSystemKitPlatform value
 @param string Any NSString, that could be a valid platform from Apple
 @returns A member of the PFSystemKitPlatform enum if found, PFSystemKitPlatformUnknown else
 */
+(PFSystemKitPlatform) stringToPlatform:(NSString*)str;

/*!
 @discussion Matches a PFSystemKitFamily to a displayable NSString
 @param family Any member of the PFSystemKitFamily enum
 @returns A NSString holding the Device Family string
 */
+(NSString*) familyToString:(PFSystemKitDeviceFamily)family;

/*!
 @discussion Matches a PFSystemKitEndianness to a displayable NSString
 @param endianness Any member of the PFSystemKitEndianness enum
 @returns A NSString holding either "Big Endian", "Little Endian", or "Unknown" if unknown
 */
+(NSString*) endiannessToString:(PFSystemKitEndianness) endianness;

/*!
 @discussion Matches a NSString to its PFSystemKitFamily value
 @param string Any NSString, that could be a valid Apple device family
 @returns A member of the PFSystemKitFamily enum if found, PFSystemKitFamilyUnknown else
 */
+(PFSystemKitDeviceFamily) stringToFamily:(NSString*)str;

/*!
 @discussion Translates a member of PFSystemKitCPUVendors to a displayable NSString
 @param vendor Any member of the PFSystemKitCPUVendors enum
 @returns A NSString holding either "GenuineIntel", "AuthenticAMD" (for hackintoshes, most likely), or "Unknown" if unknown
 */
+(NSString*) cpuVendorToString:(PFSystemKitCPUVendors) vendor;

/*!
 @discussion Translates a member of PFSystemKitCPUArches to a displayable NSString
 @param vendor Any member of the PFSystemKitCPUArches enum
 @returns A NSString holding either a CPU architecture (x86_64, ARM, i860, etc...), or "Unknown" if unknown
 */
+(NSString*) cpuArchToString:(PFSystemKitCPUArches) arch;
NSString* _cpuArchToString(PFSystemKitCPUArches arch);

#if defined(__cplusplus) //we're working with Objective-C++, so we can use std::strings and pass by reference
/*!
 @discussion Makes a SysCtl call with the given key, and assign the received string value to the passed std::string
 @param key A char array holding the requested key
 @param answerString A std::string that will be holding the SysCtl-retrieved string
 @returns A member of the PFSystemKitError enum (PFSKReturnSuccess in case of successful request)
 */
PFSystemKitError _sysctlStringForKey(char*__nonnull key, std::string& answerString);
#endif

/*!
 @discussion Makes a SysCtl call with the given key, and assign the received string value to the passed NSString
 @param key A char array holding the requested key
 @param answerString A NSString that will be holding the SysCtl-retrieved string
 @returns A member of the PFSystemKitError enum (PFSKReturnSuccess in case of successful request)
 */
PFSystemKitError _sysctlStringForKey(char*__nonnull key, NSString Ind2_NNAR answerString);

/*!
 @discussion Makes a SysCtl call with the given key, and assign the received string value to the passed char array
 @param key A char array holding the requested key
 @param answerString A char array that will be holding the SysCtl-retrieved string
 @returns A member of the PFSystemKitError enum (PFSKReturnSuccess in case of successful request)
 */
PFSystemKitError _sysctlStringForKeySynthesizing(char*__nonnull key, char*__nonnull answerString);

#if defined(__cplusplus)
/*!
 @discussion Makes a SysCtl call with the given key, and assign the received string value to the passed std::string
 @param key A char array holding the requested key
 @param answerString A std::string that will be holding the SysCtl-retrieved string
 @returns A member of the PFSystemKitError enum (PFSKReturnSuccess in case of successful request)
 */
BOOL _sysctlStringForKeySynthesizing(char*__nonnull key, std::string& answerString, NSError Ind2_NUAR error);
#endif

/*!
 @discussion Makes a SysCtl call with the given key, and assign the received string value to the passed NSString
 @param key A char array holding the requested key
 @param answerString A NSString that will be holding the SysCtl-retrieved string
 @returns A member of the PFSystemKitError enum (PFSKReturnSuccess in case of successful request)
 */
BOOL _sysctlStringForKeySynthesizing(char*__nonnull key, NSString Ind2_NNAR answerString, NSError Ind2_NUAR error);

/*!
 @discussion Makes a SysCtl call with the given key, and assign the received string value to the passed char array
 @param key A char array holding the requested key
 @param answerString A char array that will be holding the SysCtl-retrieved string
 @returns A member of the PFSystemKitError enum (PFSKReturnSuccess in case of successful request)
 */
BOOL _sysctlStringForKeySynthesizing(char*__nonnull key, char*__nonnull answerString, NSError Ind2_NUAR error);

#if defined(__cplusplus)
/*!
 @discussion Makes a SysCtl call with the given key, and assign the received value to the passed double
 @param key A char array holding the requested key
 @param answerDouble A double that will be holding the SysCtl-retrieved value
 @returns A member of the PFSystemKitError enum (PFSKReturnSuccess in case of successful request)
 */
PFSystemKitError _sysctlDoubleForKey(char*__nonnull key, double& answerDouble);
#endif

/*!
 @discussion Makes a SysCtl call with the given key, and assign the received value to the passed NSNumber instance
 @param key A char array holding the requested key
 @param answerDouble A NSNumber instance that will be holding the SysCtl-retrieved value
 @returns A member of the PFSystemKitError enum (PFSKReturnSuccess in case of successful request)
 */
PFSystemKitError _sysctlNumberForKey(char*__nonnull key, NSNumber Ind2_NNAR answerNumber);

#if defined(__cplusplus)
/*!
 @discussion Makes a SysCtl call with the given key, and assign the received value to the passed double
 @param key A char array holding the requested key
 @param answerDouble A double that will be holding the SysCtl-retrieved value
 @returns A member of the PFSystemKitError enum (PFSKReturnSuccess in case of successful request)
 */
BOOL _sysctlDoubleForKey(char*__nonnull key, double& answerDouble, NSError Ind2_NUAR error);
#endif

/*!
 @discussion Makes a SysCtl call with the given key, and assign the received value to the passed NSNumber instance
 @param key A char array holding the requested key
 @param answerDouble A NSNumber instance that will be holding the SysCtl-retrieved value
 @returns A member of the PFSystemKitError enum (PFSKReturnSuccess in case of successful request)
 */
BOOL _sysctlNumberForKey(char*__nonnull key, NSNumber Ind2_NNAR answerNumber, NSError Ind2_NUAR error);

+(NSArray*) userPreferredLanguages;

__attribute__((always_inline)) NSError*__nonnull synthesizeError(PFSystemKitError error);
__attribute__((always_inline)) NSError*__nonnull synthesizeErrorExt(PFSystemKitError error, kern_return_t extendedError);
@end

#import "PFSK_Common+Machine.h"
