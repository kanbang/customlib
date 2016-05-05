#import <Foundation/Foundation.h>

@interface Cattle : NSObject
{
	int legsCount;
}

-(void)saySomething;
-(void)setLegsCount:(int)count;
-(int)legsCount;

@end

