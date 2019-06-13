//  Copyright © 2018 650 Industries. All rights reserved.

NS_ASSUME_NONNULL_BEGIN

@interface EXUpdatesDatabase : NSObject

- (void)openDatabase;
- (void)closeDatabase;

- (void)addUpdateWithId:(NSUUID *)updateId
             commitTime:(NSNumber *)commitTime
         binaryVersions:(NSString *)binaryVersions
               metadata:(NSDictionary * _Nullable)metadata;

- (void)addAssetWithUrl:(NSString *)url
                headers:(NSDictionary * _Nullable)headers
                   type:(NSString *)type
               metadata:(NSDictionary * _Nullable)metadata
           downloadTime:(NSDate *)downloadTime
           relativePath:(NSString *)relativePath
             hashAtomic:(NSString *)hashAtomic
            hashContent:(NSString *)hashContent
               hashType:(int)hashType
               updateId:(NSUUID *)updateId
          isLaunchAsset:(BOOL)isLaunchAsset;

- (NSArray <NSDictionary *>*)launchableUpdates;
- (NSURL * _Nullable)launchAssetUrlWithUpdateId:(NSUUID *)updateId;
- (NSArray <NSDictionary *>*)assetsWithUpdateId:(NSUUID *)updateId;

@end

NS_ASSUME_NONNULL_END
