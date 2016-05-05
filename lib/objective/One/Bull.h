#import <Foundation/Foundation.h>
#import "Cattle.h"

@interface Bull : Cattle
{
	NSString* skinColor;
}

-(void)saySomething;
-(void)setSkinColor:(NSString*)color;
-(NSString*)getSkinColor;

@end
