#import <Foundation/Foundation.h>
#import "TestProtocol.h"

/**
@protocol ProtocolCom

@required
-(void)eat;

@optional
-(void)write;

@end
*/

@protocol NetProtocolDelegate<TestProtocolDelegate>

@required
-(void)setname;

@optional
-(void)setage;

@end

@interface Student : NSObject<NetProtocolDelegate>

@end

