// nick.c
// by jackyboy @ cctx 98/12/12
#include <ansi.h>

inherit F_CLEAN_UP;
string replace_color(string,int);
int help(object);
int wiz_set(string,string,string,int);

int main(object me, string arg)
{
	string dest;
	
	if( !arg )
	{
	 printf(BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(me), me->short(1));
	 return 1;	
	}
	if(sscanf(arg,"%s",arg)==1)
	{
		if(!wizardp(me) && (int)me->query("hyvip")!=4 )
			return notify_fail("这个功能只能由骨灰级会员使用。\n");

	if( strlen(replace_color(arg,0)) > 26 )
		return notify_fail("绰号太长了，请你想一个短一点的、响亮一点的。\n");
		
		return wiz_set(me->query("id"),arg,"title",1)?1:notify_fail("命令失败。\n");
	}
	



	write("Ok.\n");
	return 1;
}
int wiz_set(string str1,string str2,string prop,int color_flag)
{
	object ob,me;
	me=this_player(1);
	if(str1=="me")
		ob=this_player(1);
	else
		if(!objectp(ob=present(str1,environment(me))))
			if(!objectp(ob=find_player(str1)))
				if(!objectp(ob=find_living(str1)))
				{
					tell_object(me,"不能发现操作对象("+str1+")！\n");
					return 0;
				}
	if(wiz_level(me)<wiz_level(ob))
	{
		tell_object(me,"你的权限不够！\n");
		return 0;
	}
	if((prop=="title"&&wizardp(me))||prop=="nickname")
		if(str2=="cancel")
		{
			ob->delete(prop);
			message_vision("$N的"+prop+"被清除了。\n",ob);
			return 1;
		}
	str2=replace_color(str2,color_flag);
	message_vision("$N的"+prop+"被设定为:"+str2+"\n",ob);
	ob->set(prop,str2);
	return 1;
}

string replace_color(string arg,int flag)
{
	arg = replace_string(arg, "$BLK$", flag?BLK:"");
	arg = replace_string(arg, "$RED$", flag?RED:"");
	arg = replace_string(arg, "$GRN$", flag?GRN:"");
	arg = replace_string(arg, "$YEL$", flag?YEL:"");
	arg = replace_string(arg, "$BLU$", flag?BLU:"");
	arg = replace_string(arg, "$MAG$", flag?MAG:"");
	arg = replace_string(arg, "$CYN$", flag?CYN:"");
	arg = replace_string(arg, "$WHT$", flag?WHT:"");
	arg = replace_string(arg, "$HIR$", flag?HIR:"");
	arg = replace_string(arg, "$HIG$", flag?HIG:"");
	arg = replace_string(arg, "$HIY$", flag?HIY:"");
	arg = replace_string(arg, "$HIB$", flag?HIB:"");
	arg = replace_string(arg, "$HIM$", flag?HIM:"");
	arg = replace_string(arg, "$HIC$", flag?HIC:"");
	arg = replace_string(arg, "$HIW$", flag?HIW:"");
	arg = replace_string(arg, "$NOR$", flag?NOR:"");
	arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
	if(flag) arg+=NOR;
	return arg;
}

int help(object me)
{
	write(@HELP
指令格式 : 
指令格式: title 显示你目前的阶级和头衔。
title <字串>	设定title属性 (适用于骨灰级会员)
如果你希望使用 ANSI 的控制字元改变颜色，可以用以下的控制字串：
$BLK$ - 黑色		$NOR$ - 恢复正常颜色
$RED$ - 红色		$HIR$ - 亮红色
$GRN$ - 绿色		$HIG$ - 亮绿色
$YEL$ - 土黄色		$HIY$ - 黄色
$BLU$ - 深蓝色		$HIB$ - 蓝色
$MAG$ - 浅紫色		$HIM$ - 粉红色
$CYN$ - 蓝绿色		$HIC$ - 天青色
$WHT$ - 浅灰色		$HIW$ - 白色
$BLINK$ - 字符闪烁
其中系统自动会在字串尾端加一个 $NOR$。

HELP
	);
	return 1;
}
