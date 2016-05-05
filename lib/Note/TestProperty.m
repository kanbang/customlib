#import "TestProperty.h"

@interface TestProperty()
{
	int count;
}
@property int count;
@end
@implementation TestProperty

@synthesize str1;
@synthesize str2;
@synthesize count;
+(void)testString
{
	__strong NSString *s1 = [[NSString alloc] initWithString:@"xingkd---s1"];
	
	NSLog(@"s1============%@\n",s1);

	__weak NSString *s2 = s1;
	NSLog(@"s2==============%@\n", s2);
	NSLog(@"set ======s1=nil=========\n");
	s1 = nil;
	NSLog(@"s1============%@\n",s1);

	NSLog(@"s2==============%@\n", s2);

	TestProperty *tp = [[TestProperty alloc] init];
	tp.str1 = @"xingkongdao";
	NSLog(@"tp.str1===============%@\n", tp.str1);
	tp.str2 = tp.str1;

	NSLog(@"tp.str2===============%@\n", tp.str2);
	NSLog(@"=========set str2=nil==============\n");
	
	tp.str1 = nil;
	NSLog(@"tp.str1===============%@\n", tp.str1);
	NSLog(@"tp.str2===============%@\n", tp.str2);
	
}

@end

