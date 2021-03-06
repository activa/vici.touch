//=============================================================================
// Vici Touch - Productivity Library for Objective C / iOS SDK 
//
// Copyright (c) 2009-2010 Philippe Leybaert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy 
// of this software and associated documentation files (the "Software"), to deal 
// in the Software without restriction, including without limitation the rights 
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
// copies of the Software, and to permit persons to whom the Software is 
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in 
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//=============================================================================

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VCCache.h"

@class VCLazyImageView;

@protocol VCLazyImageViewDelegate<NSObject>

- (void) lazyImageView:(VCLazyImageView *)lazyImageView imageLoaded:(UIImage *)image;

@end


@interface VCLazyImageView : UIView 
{
	NSMutableData *_receivedData;
	
	UIActivityIndicatorView *_spinnerView;
	UIImageView *_imageView;
	
	NSString *_backupImageName;
	
	NSURLConnection *_urlConnection;
	
	NSString *_url;
    
    BOOL _useCaching;
	
	id<VCLazyImageViewDelegate> _delegate;
}

@property (nonatomic,assign) id<VCLazyImageViewDelegate> delegate;
@property (readonly) UIImage *image;
@property (nonatomic,assign) BOOL useCaching;

- (void) setImageUrl:(NSString *)url backupImageName:(NSString *)backupImageName;

@end
