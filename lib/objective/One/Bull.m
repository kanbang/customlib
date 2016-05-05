#import "Bull.h"

@implementation Bull

-(void)saySomething
{
	NSLog(@"Hello, I am a %@ Bull, I have %d legs",skinColor, legsCount);
}

-(void)setSkinColor:(NSString*)color
{
	skinColor = color;
}

-(NSString*)getSkinColor
{
	return skinColor;
}

@end
