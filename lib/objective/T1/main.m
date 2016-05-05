#import <Foundation/Foundation.h>

@interface Hello : NSObject
{
	NSString *m_name;
}

@property (nonatomic, retain) NSString* m_name;

-(void)setM_name:(NSString*)name;
-(NSString*)m_name;
-(void)setName:(NSString*)name;

@end

@implementation Hello 

-(void)setName:(NSString*)name
{
	self.m_name = name;
}

-(void)setM_name:(NSString*)name
{
	m_name=name;
}

-(NSString*)m_name
{
	return m_name;
}

@end


int main(int argc, char* argv[])
{
	Hello *hello = [[Hello alloc]init];

	[hello setName:@"xingkongdao"];
	
	NSString* one = @"xingkongdao";
	NSString* one1 = one;

	one = @"zhengsihua";
//	NSString* one1 = [[NSString alloc] initWithString:one];

	NSLog(@"one = %@, one1 = %@\n", one, one1);

	return 0;
}


