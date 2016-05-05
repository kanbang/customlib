
#import <Foundation/Foundation.h>

// 每个协议默认都要遵守NSObject协议，因此，
// @protocol TestProtocolDelegate  等同于 @protocol TestProtocolDelegate<NSObject>
@protocol TestProtocolDelegate

@required
-(void) eat;
@optional
-(void) write;
@end

// TestProtocol 继承了TestProtocolDelegate，因此不需要在@interface 部分声明，
// 直接在m文件中定义就行
@interface TestProtocol : NSObject<TestProtocolDelegate>

//-(void)eat;
//-(void)write;

@end

@interface OneProtocol : NSObject<TestProtocolDelegate>
//-(void)eat;
//-(void)write;
@end

@interface TwoProtocol : NSObject<TestProtocolDelegate>
//-(void)eat; // 没有这个运行不了
//-(void)write;
@end

@interface TestProtocolProxy : NSObject
{
	id<TestProtocolDelegate> delegate;
}

@property(nonatomic, retain)id delegate;
-(void) show:(BOOL) flag;
-(id)init;
-(void) askChild;
@end
