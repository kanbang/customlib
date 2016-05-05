#import "TestNSClass.h"
#import "TestProtocol.h"
#import "TestProtocolProxy-testCategory.h"
#import "TestExtension.h"
#import "TestID.h"
#import "TestProperty.h"

@implementation TestNSClass

+(void)testNSData
{
	NSData *data = [@"0123" dataUsingEncoding:NSUTF8StringEncoding];
	
	NSLog(@"testData============%@=========%@\n",data, [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding]);

	
}

+(void)testNSString
{
	NSLog(@"============================testNSString================================\n");
	NSString *str = @"123";
	NSLog(@"str + 1 = %d\n",[str integerValue] + 1);
	NSString *oneStr = [NSString stringWithFormat:@"%d",199];
	// NSString 不能改变,只能是定义的时候初始化，初始化以后不能改变
//	[oneStr appendString:str];
	
	NSMutableString *muteStr = [NSMutableString stringWithCString:"xingkd"];
	[muteStr appendString:str];

	NSLog(@"int to string ----%@\n", muteStr);
	NSLog(@"int to string ----%@\n", oneStr);
}
+(void)testNSArray
{
	NSLog(@"======================NSArray===================\n");
	NSArray *array = [NSArray  arrayWithObject:@"xingkongdoa"];// arrayWithObjects:@"first", @"second", nil];
	NSLog(@"test isMemberOfClass===%d\n",[ array isMemberOfClass:[NSArray class]]);
	NSLog(@"the count of array is %d\n", [array count]);
	NSLog(@"the index of 1 is %@\n", [array objectAtIndex: 0]);

	NSString *splitStr = @"xing:kong:dao:zheng:si:hua";
	NSArray *splite = [splitStr componentsSeparatedByString:@":"];
	NSLog(@"splite'count is %d\n", [splite count]);

	int i = 0;
	for(i = 0; i<[splite count]; i++)
	{
		NSLog(@"at the %d of splite is %@\n", i, [splite objectAtIndex: i]);
	}

	for(NSString* item in splite)
	{
		NSLog(@"item is %@\n", item);
	}

	NSString *one = @"one";
	NSString *two = @"two";
	// 数组的最后要以nil结尾。NSDictionary也是
	NSArray *oneArray = [NSArray arrayWithObjects:@"xing", nil];
	NSLog(@"oneArray arrayWithObjects: %@\n",oneArray);

	NSMutableArray *muteArray = [[NSMutableArray alloc] init];
	[muteArray addObject:@"Hello"];
	[muteArray addObject:array];
	[muteArray addObject:splite];

	NSLog(@"muteArray'count is %d\n",[muteArray count]);

	for(i = 0; i< [muteArray count]; i++)
	{
		NSLog(@"mutable item is %@\n", [muteArray objectAtIndex: i]);
		if([[muteArray objectAtIndex: i] isKindOfClass:[NSArray class]])
		{
			NSLog(@"the object is kind of NSArray\n");
			for(NSString*item in [muteArray objectAtIndex: i])
			{
				NSLog(@"output the item = %@\n",item);
			}

			NSLog(@"test isKindOfClass======%d\n", [ array isKindOfClass:[NSObject class]]);
			NSLog(@"test isMemberOfClass===%d\n",[[muteArray objectAtIndex: i] isMemberOfClass:[NSArray class]]);
		}
	}
}

+(void)testProxy
{
	//@autoreleasepool{
//	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
//	NSApplication *app = [NSApplication sharedApplication];
	NSLog(@"Hello World\n");
	
	TestProtocol *protocol = [[TestProtocol alloc] init];

//	[protocol eat];
//	[protocol write];

	TestProtocolProxy *proxy = [[TestProtocolProxy alloc] init];
	proxy.delegate = protocol;
	[proxy show:NO];

	OneProtocol *one = [[OneProtocol alloc] init];
	proxy.delegate = one;
	[proxy show:NO];
	
	TwoProtocol *two = [[TwoProtocol alloc] init];
	proxy.delegate= two;
	[proxy show:YES];
	
	[proxy askChild];
	[proxy category];

	TestExtension *ext = [[TestExtension alloc] init];

	[ext setVar: 4];
	
	NSLog(@"ext's value = %d\n", [ext getVar]);

	ext.var = 100;
	NSLog(@"ext's value = %d\n", [ext getVar]);

	MyObject *obj = [[MyObject alloc] init];
	[obj show];
	IDClass *tid = [[IDClass alloc] init];
	MyObject *myobj = [tid getObj];

	[myobj show];	
	NSLog(@"testApplication=========================\n");

	[TestProperty testString];
//	[app run];
	//}
//	[pool release];
}

@end

