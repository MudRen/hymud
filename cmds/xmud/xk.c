// follow.c
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
	int i;
	mapping inquirys;
	string *inqu;
	if( !arg ) return notify_fail("错误用法！\n");
	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("这里没有 " + arg + "。\n");
	if( !ob->is_character() )
		return notify_fail("什么？查..." + ob->name() + "？\n");
	if( ob==me )
		return notify_fail("查自己？\n");
        	if( mapp(inquirys= ob->query("inquiry")) ) {
		inqu = keys(inquirys);
		for(i=0; i<sizeof(inqu); i++)
			{
				write("$keask#"+inqu[i]+"\n");
			}
		}
	return 1;
}
int help (object me)
{
        write(@HELP
HELP
);
        return 1;
}
