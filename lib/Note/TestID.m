#import "TestID.h"

@implementation MyObject

-(void)show
{
	NSLog(@"Object============show============\n");
}

@end

@implementation IDClass

-(id)getObj
{
	NSLog(@"IDClass ========getObj========\n");
	MyObject *obj = [[MyObject alloc] init];
	NSLog(@"IDClass==========create obj======\n");

	return obj;
}

@end

