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
			return notify_fail("�������ֻ���ɹǻҼ���Աʹ�á�\n");

	if( strlen(replace_color(arg,0)) > 26 )
		return notify_fail("�º�̫���ˣ�������һ����һ��ġ�����һ��ġ�\n");
		
		return wiz_set(me->query("id"),arg,"title",1)?1:notify_fail("����ʧ�ܡ�\n");
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
					tell_object(me,"���ܷ��ֲ�������("+str1+")��\n");
					return 0;
				}
	if(wiz_level(me)<wiz_level(ob))
	{
		tell_object(me,"���Ȩ�޲�����\n");
		return 0;
	}
	if((prop=="title"&&wizardp(me))||prop=="nickname")
		if(str2=="cancel")
		{
			ob->delete(prop);
			message_vision("$N��"+prop+"������ˡ�\n",ob);
			return 1;
		}
	str2=replace_color(str2,color_flag);
	message_vision("$N��"+prop+"���趨Ϊ:"+str2+"\n",ob);
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
ָ���ʽ : 
ָ���ʽ: title ��ʾ��Ŀǰ�Ľ׼���ͷ�Ρ�
title <�ִ�>	�趨title���� (�����ڹǻҼ���Ա)
�����ϣ��ʹ�� ANSI �Ŀ�����Ԫ�ı���ɫ�����������µĿ����ִ���
$BLK$ - ��ɫ		$NOR$ - �ָ�������ɫ
$RED$ - ��ɫ		$HIR$ - ����ɫ
$GRN$ - ��ɫ		$HIG$ - ����ɫ
$YEL$ - ����ɫ		$HIY$ - ��ɫ
$BLU$ - ����ɫ		$HIB$ - ��ɫ
$MAG$ - ǳ��ɫ		$HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ		$HIC$ - ����ɫ
$WHT$ - ǳ��ɫ		$HIW$ - ��ɫ
$BLINK$ - �ַ���˸
����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��

HELP
	);
	return 1;
}
