#import "TestProtocol.h"
#import "ProtocolFromNet.h"

@implementation TestProtocol
-(void)eat
{
	NSLog(@"testProtocol------------eat\n");
}

-(void)write
{
	NSLog(@"testProtocol----------write\n");
}

@end

@implementation OneProtocol

-(void)eat
{
	NSLog(@"OneProtocol-------------------eat\n");
}

-(void)write
{
	NSLog(@"oneProtocol--------------write\n");
}

@end

@implementation TwoProtocol
-(void)write
{
	NSLog(@"Two----------------write\n");
}

-(void)eat
{
	NSLog(@"Two----------------eat\n");
}
@end

@implementation TestProtocolProxy

@synthesize delegate;

-(void) show:(BOOL) flag
{
	if(flag)
	{
		[[self delegate]write];
	}
	else
	{
		[[self delegate]eat];
	}
}

-(id)init
{
	NSLog(@"init------proxy-----\n");
	[super init];
	
	self.delegate=nil;
	NSLog(@"init------delegate-------self=%@---delegate=%@\n",self,self.delegate);
	
//	Student *stu = [[Student
	
	return self;
}

-(void)askChild
{
	NSLog(@"askChild------------------------\n");
	Student *std = [[Student alloc] init];
	self.delegate = std;

	[self.delegate setname];
}
@end

