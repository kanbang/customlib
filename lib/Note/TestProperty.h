#import <Foundation/Foundation.h>

// 目前没有到达测试strong和weak的效果，后期要验证
@interface TestProperty : NSObject
{
	NSString* str1;
	NSString* str2;
}
@property(nonatomic,retain) NSString* str1;
@property(nonatomic,retain) NSString* str2;
// copy retain copy strong weak
+(void)testString;

@end
