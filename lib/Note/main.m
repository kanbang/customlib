
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

#import "TestNSClass.h"

int main(int argc, char* argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	[TestNSClass testNSData];
//	[TestNSClass testNSString];
//	[TestNSClass testNSArray];
//	[TestNSClass testProxy];
	
	[pool drain];
	return 0;
}
