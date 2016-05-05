#import "DoProxy.h"
#import "Cattle.h"
#import "Bull.h"

@implementation DoProxy

-(void)sayAllIVars
{
	cattle[0] = [Cattle new];
	
	bullClass = NSClassFromString(BULL_CLASS);

	cattle[1] = [bullClass new];
	cattle[2] = [bullClass new];

	say = @selector(saySomething);
	skin = NSSelectorFromString(SET_SKIN_COLOR);

}

-(void)SELFuncs
{
	[self doWithCattle:cattle[0] colorParam:@"browm"];

	[self doWithCattle:cattle[1] colorParam:@"red"];

	[self doWithCattle:cattle[2] colorParam:@"black"];

	[self doWithCattle: self colorParam:@"Ha-Ha"];

}

-(void)functionPointers
{
	setSkinColor_Func = (void(*) (id,SEL,NSString*))[cattle[1] methodForSelector:skin];

	say_Func = [cattle[1] methodForSelector:say];

	setSkinColor_Func(cattle[1],skin, @"verbose");

	NSLog(@"Running a sayFunctionPointer will be more efficiency");

	say_Func(cattle[1], say);

}


-(void)doWithCattle:(id)aCattle colorParam:(NSString*)color
{
	if(notFirstRun == NO)
	{
		NSString* myname = NSStringFromSelector(_cmd);
		NSLog(@"Running in the method of %@",myname);

		notFirstRun = YES;
	}

	NSString* cattleParamClassName = [aCattle className];
	if([cattleParamClassName isEqualToString:BULL_CLASS] || [cattleParamClassName isEqualToString:CATTLE_CLASS])
	{
		[aCattle setLegsCount:4];
		if([aCattle respondsToSelector:skin])
		{
			[aCattle performSelector:skin withObject:color];
		}
		else
		{
			NSLog(@"Hi, I am a %@ have not setSkinColor!",cattleParamClassName);
		}
		
		[aCattle performSelector:skin];
	}
	else
	{
		NSString* yourClassName = [aCattle className];
		NSLog(@"Hi, you area %@ ,but i like cattle or bull", yourClassName);
	}
}
@end

