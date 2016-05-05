#import <Foundation/Foundation.h>

#define SET_SKIN_COLOR @"setSkinColor:"
#define BULL_CLASS @"Bull"
#define CATTLE_CLASS @"Cattle"

@interface DoProxy : NSObject
{
	BOOL notFirstRun;
	id cattle[3];
	SEL say;
	SEL skin;
	void(*setSkinColor_Func)(id, SEL, NSString*);
	IMP say_Func;
	Class bullClass;
}

-(void)doWithCattle:(id)aCattle colorParam:(NSString*)color;
-(void)sayAllIVars;
-(void)SELFuncs;
-(void)functionPointers;

@end
