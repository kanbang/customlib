// objc 机制
// Runtime RunLoop Block,内存管理
//
// note :
// NSString 必须定义成指针
// int i ; for(i = 0; i<10; i++) (对)  
//
// for(int i = 0; i<10; i++) (错)
//
//
//
// /////////////////////////////////////////
// need to know 
// 1. @selector
//
#import <Foundation/Foundation.h>
@interface Hello 
{
}
-(void) HelloWorld;
@end

@implementation Hello

-(void)HelloWorld
{
	NSLog(@"Hello World\n");
}

@end

@interface Dog : NSObject
{
	int m_age;
	NSString* m_name;
}

@property (nonatomic, retain)NSString* m_name;

// abcd 是随意写的，目的是为了区分第二个参数
-(void)setProperty:(NSString *)name abcd:(int)age;
-(void)setAge:(int)age;
-(int)getAge;
-(void)swap:(int *)p1 twoParam:(int*)p2;
//-(NSString*)m_name;
//-(void)setM_name:(NSString*)newM_name;

// static function
+(void)showMessage;
+(void)testNSString;

@end

@implementation Dog

@synthesize m_name;
//-(NSString*)m_name
//{
//	return m_name;
//}

//-(void)setM_name:(NSString*)newM_name
//{
//	m_name = newM_name;
//}


-(void)swap:(int *)p1 twoParam:(int *)p2
{
	NSLog(@"===========begin swap==============");
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
	NSLog(@"===========end swap==============");
}
-(void)setProperty:(NSString *)name abcd:(int)age
{
	NSLog(@"===========begin setProperty============");
	NSLog(name);
	NSLog(@"setProperty age = %i\n", age);

	m_age = age;
	self.m_name = name;
	NSLog(@"===========end setProperty============");
}
-(void)setAge:(int)age
{
	NSLog(@"setAge, age= %i" ,age);
	m_age = age;
}

-(int)getAge
{
	NSLog(@"m_age = %i\n", m_age);
	return m_age;
}

+(void)showMessage
{
	NSLog(@"showMessage  Hello World \n");
}

+(void)testNSString
{
	NSLog(@"==============begin testNSString===========\n");
	NSString *str0 = @"first===";
	NSString *str=@"xingkongdao";
    
	// %s is char* 
	NSString *str1 = [NSString stringWithFormat:@"my name is :%@, my age is :%i, my emai is :%s",@"xingkongdao",27,"xingkongdao@syberos.com"];
	NSLog(@"======================1");
	NSString *str2 = [NSString stringWithString:@"I am charactor"];
	NSString *str3 = [NSString stringWithUTF8String:"UTF8 charactor"];

	int i = 100;
	char* c = "zhengsihua";

	NSString *temp = @"I am a temperance charactor";
	NSString *str4 = [temp stringByAppendingFormat:@"Int : %d, Char :%s", i, c];

	//NSString *str5 = [temp stringByAppendindString:temp];

	NSLog(@"======================2");
	NSLog(@"str = %@\n",str);
	int length = [str length];
	NSLog(@"str.length = %i\n",length);
	int ii ;
	for(ii = 0; ii < length; ii++)
	{
		char c = [str characterAtIndex:ii];
		NSLog(@"str.at(%d) is %c\n",ii,c);
	}

	NSLog(@"str0 = %@\n",str0);
	NSLog(@"str1 = %@\n",str1);
	NSLog(@"str2 = %@\n",str2);
	NSLog(@"str3 = %@\n",str3);
	NSLog(@"str4 = %@\n",str4);
	//NSLog(@"str5 = %@\n",str5);

	NSString *one = @"xing";
	NSString *copyone = @"xing";
	NSString *two = @"zhen";

	if([one isEqualToString:copyone])
	{
		NSLog(@" one is equal to copyone");
	}

	if([one hasPrefix:@"xi"])
	{
		NSLog(@"one is begin with xi");
	}

	if([one hasSuffix:@"ng"])
	{
		NSLog(@"one is end with ng");
	}
	
	//str = xingkongdao
	
	NSString* to = [str substringToIndex:4];
	NSLog(@" to = %@", to);

	NSString* from = [str substringFromIndex: 4];
	NSLog(@" from = %@", from);

	NSRange rang = NSMakeRange(4,7);
	NSString *rangStr = [str substringWithRange:rang];
	NSLog(@"rand = %@", rangStr);
}
@end

//====================================protocol==============================================

@protocol Eat<NSObject> 
-(void) eat;
@end

@interface Human : NSObject<Eat>
-(void) eat;

@end

@implementation Human

-(void)eat
{
	NSLog(@"Human eat\n");
}

@end

int main(int argc,char* argv[])
{
	NSAutoreleasePool *pool = [ [NSAutoreleasePool alloc] init];
	//NSLog(@"Hello World\n");
    
	
	//Hello *hello = [Hello new];
	//[hello HelloWorld];
	Dog* dog =[[Dog alloc] init];
	
	int age = 20;
	[dog setAge:203];
	[dog setAge:age];
	[dog getAge];
    
	int a = 10;
	int b = 20;
	NSLog(@"change the value of a and b\n");
	NSLog(@" a = %i ---------- b = %i\n", a, b);
	[dog swap:&a twoParam:&b];
	NSLog(@" a = %i ---------- b = %i\n", a, b);

	NSLog(@"after getAge");
	[dog setProperty:@"tom" abcd:123];

	[Dog showMessage];
	[Dog testNSString];

	Human *human = [[Human alloc] init];
	[human eat];
//	NSLog([dog getAge]);
	[pool release];

	return 0;
	
}
