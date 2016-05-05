#import <Foundation/Foundation.h>
#import "Cattle.h"
#import "Bull.h"
#import "DoProxy.h"

int main(int argc, char* argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc]init];

	int type = 1;
	if(type == 0)
	{
		
	NSLog(@"Running the type == 0");
	id cattle = [Cattle new];
	[cattle setLegsCount:4];
	[cattle saySomething];

	id redBull = [Bull new];
	[redBull setLegsCount:4];
	[redBull setSkinColor:@"red"];
	[redBull saySomething];

	Bull *blackBull = [Bull new];
	[blackBull setLegsCount:4];
	[blackBull setSkinColor:@"black"];
	[blackBull saySomething];

	}

	if(type == 1)
	{
		NSLog(@"Running the type == 1");
		DoProxy *doProxy = [DoProxy new];
		[doProxy setAllIVars];
		[doProxy SELFuncs];
		[doProxy functionPointers];
	}
	[pool drain];

	return 0;
}
