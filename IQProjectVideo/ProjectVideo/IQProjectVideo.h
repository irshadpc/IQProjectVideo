//
//  IQImagesToMovie.h
//  VideoCreatorDemo
//
//  Created by Iftekhar Mac Pro on 9/26/13.
//  Copyright (c) 2013 Iftekhar. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^ProgressBlock)(CGFloat progress);
typedef void(^CompletionBlock)(NSDictionary* fileInfo);

@interface IQProjectVideo : NSObject
{
    NSMutableArray  *_images;
    NSString        *_path;
    NSTimer         *_timer;
    NSTimer         *_stopTimer;
    ProgressBlock   _progressBlock;
    CompletionBlock _completionBlock;
}

//Start capturing video of screen. Automatically call stopVideoCapture after 'seconds' parameter.
-(void)startVideoCaptureOfDuration:(NSInteger)seconds savePath:(NSString*)path;

//Start capturing video of screen. You need to manually call stopVideoCapture to stop video capture.
-(void)startVideoCaptureWithSavePath:(NSString*)path;

//Stop video capture.
-(void)stopVideoCaptureWithProgress:(ProgressBlock)progressBlock completionHandler:(CompletionBlock)completionBlock;

-(void)cancel;


@end


extern NSString *const IQFilePathKey;
extern NSString *const IQFileSizeKey;
extern NSString *const IQFileCreateDateKey;