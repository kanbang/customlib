#import "Cattle.h"

@implementation Cattle
-(void)saySomething
{
	NSLog(@"Hello, I am a Cattle, I have a %d legs", legsCount);
}

-(void)setLegsCount:(int)count
{
	legsCount = count;
}

-(int)legsCount
{
	return legsCount;
}

@end
