// give.c
// ����2000/6/14����bug

#include <ansi.h>

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int amount;
       	string info,name,id,filen,infoa,infob;
         object weapon,newob,oldob;
        int i,j, flag = 0,arg2;
        object ob;
        string mission, wname, wmin, file,mission2;
        string *wmission;
     me=this_player();   
	if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("��Ҫ��˭ʲô������\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("����û������ˡ�\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

  //if (!wizardp(me))
  //	return notify_fail("������ û�ж���ҿ��ţ�\n"); 

  if ((int)me->query("balance",1)<= 1000000)
  	return notify_fail("����װ��ת����Ҫ��һ�����ƽ������� �����ӦǮ�����������У�\n"); 
//	if( who->query("env/no_accept") )
//		return notify_fail("�˼����ڲ���Ҫʲô������\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("������û������������\n");
	if( obj->query_temp("is_rided_by") == me->query("id"))
		return notify_fail( obj->name() + "���������ţ����ܸ��ˡ�\n");

	if( !obj->query("systemmake") )
		return notify_fail("������԰󶨵�װ���ſ��������ָ�\n");

	if( obj->query("id")=="newbie armor" || obj->query("id")=="newbie sword")
		return notify_fail("�������粻��������\n");                



		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
	
			if( amount != obj->query_amount() ) 
			return notify_fail("���������ĸ�����!\n");
	
	
	}



	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
string target, item;
	object  *inv, obj2;
	int amount;
       	string info,name,id,filen,infoa,infob;
         object weapon,newob,oldob;
        int i,j, flag = 0,arg2;
        object ob;
        string mission, wname, wmin, file,mission2;
        string *wmission;
//       if( obj->query("no_drop") )
//		return notify_fail("�����������������ˡ�\n");
// Add by Java 
	if( userp(obj) )
		return notify_fail("��ֻ������ҡ�\n");

	if( !obj->query("systemmake") )
		return notify_fail("������԰󶨵�װ���ſ��������ָ�\n");

 seteuid(getuid());
 filen = "/p/residence/banding/"+me->query("id");
        if (!read_file(filen))  write_file(filen, "", 1);
        wmission = explode(read_file(filen), "\n");

//printf(base_name(obj));
	        for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wname, wmin)!=2 ) continue;
//printf(wmin);
//printf(base_name(obj));
if (base_name(obj)==wmin)
{
return notify_fail("����Ʒ�ѱ��󶨣��޷�������ʹ�á� \n");
      }
       
        }

// on June 3.1998



	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
		// check for dynamic_quests
        if(obj->query("dynamic_quest"))
        if(TASK_D->quest_reward(me,who,obj))
        return 1;
	if( !interactive(who) && !who->accept_object(me, obj) )
		return notify_fail("�Է�����������������\n");

me->add("balance",-1000000);

	if( !userp(who) && obj->value() ) {
		message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
		destruct(obj);
        me->save();
        if (userp(who)) who->save();
		return 1;
	} else if( obj->move(who) ) {
		printf("���%sһ%s%s��\n", who->name(), obj->query("unit"),
			obj->name());
		message("vision", sprintf("%s����һ%s%s��\n", me->name(),
			obj->query("unit"), obj->name()), who );
		message("vision", sprintf("%s��%sһ%s%s��\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
		me->save();
		if (userp(who)) who->save();
		return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
ָ���ʽ : bgive <��Ʒ����> to <ĳ��>
      �� : bgive <ĳ��> <��Ʒ����>
 
���ָ��������㽫ĳ��������԰󶨵���Ʒ�����ˣ���Ȼ��������Ҫӵ��������Ʒ��
 
HELP
    );
    return 1;
}
