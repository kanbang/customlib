#import "TestExtension.h"

@interface TestExtension(Private)

	int var;

@end

@implementation TestExtension

//@synthesize var;

-(void)setVar:(int)value
{
//	NSLog(@"the value of var is --%d\n",value);
	var = value;
	NSLog(@"the value============================");
}

-(int)getVar
{
	NSLog(@"getVar=====================circle====\n");
	return var;
}
-(void)output
{
	NSLog(@"testExtension--------output\n");
}

@end
